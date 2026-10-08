#include "heapcommoni.h"
#include "nnsys/fnd.h"

// NitroSystem's frame heaps (NNS_Fnd). Allocating moves one pointer up from the bottom or another down from the top;
// nothing is freed on its own, only everything from one end, or everything since a recorded state. swan calls none
// of them by name. Their two allocators would share expheap.c's static names, so here they say which heap they serve

#define FRMHEAP_SIGNATURE 0x46524D48 // 'FRMH'

// The heap needs room for its heads
#define MIN_HEAP_SIZE (sizeof(NNSiFndHeapHead) + sizeof(NNSiFndFrameHeap))

static NNSiFndHeapHead *InitFrameHeap(void *start, void *end, u16 optFlag);
static void *AllocFromHeadForFrmHeap(NNSiFndFrameHeap *frmHeap, u32 size, int alignment);
static void *AllocFromTailForFrmHeap(NNSiFndFrameHeap *frmHeap, u32 size, int alignment);
static void FrameHeapReleaseLow(NNSiFndHeapHead *heap);
static void FrameHeapReleaseHigh(NNSiFndHeapHead *heap);

// The frame heap's own head, just after the common one
static inline NNSiFndFrameHeap *FrmHeapOf(NNSiFndHeapHead *heap) {
    return (NNSiFndFrameHeap *)(AddrOf(heap) + sizeof(NNSiFndHeapHead));
}

static inline NNSiFndHeapHead *HeapOf(NNSiFndFrameHeap *frmHeap) {
    return (NNSiFndHeapHead *)(AddrOf(frmHeap) - sizeof(NNSiFndHeapHead));
}

static NNSiFndHeapHead *InitFrameHeap(void *start, void *end, u16 optFlag) {
    NNSiFndHeapHead *heap = start;
    NNSiFndFrameHeap *frmHeap = FrmHeapOf(heap);

    NNSi_FndInitHeapHead(heap, FRMHEAP_SIGNATURE, (void *)(AddrOf(frmHeap) + sizeof(NNSiFndFrameHeap)), end, optFlag);
    frmHeap->low = heap->heapStart;
    frmHeap->high = heap->heapEnd;
    frmHeap->lastMark = NULL;
    return heap;
}

static void *AllocFromHeadForFrmHeap(NNSiFndFrameHeap *frmHeap, u32 size, int alignment) {
    void *block = (void *)((AddrOf(frmHeap->low) + (alignment - 1)) & ~(alignment - 1));
    void *newHead = (void *)(AddrOf(block) + size);

    if (AddrOf(newHead) > AddrOf(frmHeap->high)) {
        return NULL;
    }
    FillAllocMemory(HeapOf(frmHeap), frmHeap->low, BytesBetween(frmHeap->low, newHead));
    frmHeap->low = newHead;
    return block;
}

static void *AllocFromTailForFrmHeap(NNSiFndFrameHeap *frmHeap, u32 size, int alignment) {
    void *block = (void *)((AddrOf(frmHeap->high) - size) & ~(alignment - 1));

    if (AddrOf(block) < AddrOf(frmHeap->low)) {
        return NULL;
    }
    FillAllocMemory(HeapOf(frmHeap), block, BytesBetween(block, frmHeap->high));
    frmHeap->high = block;
    return block;
}

// Frees everything taken from the bottom, and forgets the recorded states, which lived there
static void FrameHeapReleaseLow(NNSiFndHeapHead *heap) {
    NNSiFndFrameHeap *frmHeap = FrmHeapOf(heap);

    frmHeap->low = heap->heapStart;
    frmHeap->lastMark = NULL;
}

// Frees everything taken from the top, in the recorded states as well
static void FrameHeapReleaseHigh(NNSiFndHeapHead *heap) {
    NNSiFndFrameHeap *frmHeap = FrmHeapOf(heap);
    NNSiFndFrameHeapMark *state;

    for (state = frmHeap->lastMark; state != NULL; state = state->prev) {
        state->high = heap->heapEnd;
    }
    frmHeap->high = heap->heapEnd;
}

NNSFndHeapHandle NNS_FndCreateFrmHeapEx(void *startAddress, u32 size, u16 optFlag) {
    void *end = (void *)((AddrOf(startAddress) + size) & ~3);

    startAddress = (void *)((AddrOf(startAddress) + 3) & ~3);
    if (AddrOf(startAddress) > AddrOf(end) || BytesBetween(startAddress, end) < MIN_HEAP_SIZE) {
        return NULL;
    }
    return InitFrameHeap(startAddress, end, optFlag);
}

void NNS_FndDestroyFrmHeap(NNSFndHeapHandle heap) {
    NNSi_FndFinalizeHeap(heap);
}

// A negative alignment takes the block from the top
void *NNS_FndAllocFromFrmHeapEx(NNSFndHeapHandle heap, u32 size, int alignment) {
    NNSiFndFrameHeap *frmHeap = FrmHeapOf(heap);

    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;
    if (alignment >= 0) {
        return AllocFromHeadForFrmHeap(frmHeap, size, alignment);
    } else {
        return AllocFromTailForFrmHeap(frmHeap, size, -alignment);
    }
}

// mode is a set of NNS_FND_FRMHEAP_RELEASE_* ends to free
void NNS_FndFreeToFrmHeap(NNSFndHeapHandle heap, int mode) {
    if (mode & NNS_FND_FRMHEAP_RELEASE_LOW) {
        FrameHeapReleaseLow(heap);
    }
    if (mode & NNS_FND_FRMHEAP_RELEASE_HIGH) {
        FrameHeapReleaseHigh(heap);
    }
}

// Saves both pointers under tag, in a record taken from the bottom of the heap. Returns FALSE when there's no
// room for it
BOOL NNS_FndRecordStateForFrmHeap(NNSFndHeapHandle heap, u32 tag) {
    NNSiFndFrameHeap *frmHeap = FrmHeapOf(heap);
    void *headBefore = frmHeap->low;
    NNSiFndFrameHeapMark *record = AllocFromHeadForFrmHeap(frmHeap, sizeof(NNSiFndFrameHeapMark), 4);

    if (record == NULL) {
        return FALSE;
    }
    record->tag = tag;
    record->low = headBefore;
    record->high = frmHeap->high;
    record->prev = frmHeap->lastMark;
    frmHeap->lastMark = record;
    return TRUE;
}

// Goes back to the state saved under tag, or to the latest one when tag is 0. Returns FALSE when there's no
// such state
BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tag) {
    NNSiFndFrameHeap *frmHeap = FrmHeapOf(heap);
    NNSiFndFrameHeapMark *record = frmHeap->lastMark;

    if (tag != 0) {
        for (; record != NULL; record = record->prev) {
            if (record->tag == tag) {
                break;
            }
        }
    }
    if (record == NULL) {
        return FALSE;
    }
    frmHeap->low = record->low;
    frmHeap->high = record->high;
    frmHeap->lastMark = record->prev;
    return TRUE;
}
