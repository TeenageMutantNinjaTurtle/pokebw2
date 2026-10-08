#include "heapcommoni.h"
#include "nnsys/fnd.h"
#include <stdlib.h>

// NitroSystem's expanded heaps (NNS_Fnd). Every block, free or used, has a 16-byte header, and the headers are kept
// in two lists. Blocks are cut from either end of a free block, and freed blocks merge with free neighbours.
// swan's names: NNS_FndCreateExpHeapEx InitHeapBaseSafe, NNS_FndAllocFromExpHeapEx AllocOnHeapBase,
// NNS_FndResizeForMBlockExpHeap ExpHeap_ResizeBlock, NNS_FndFreeToExpHeap FreeFromHeapBase,
// NNS_FndGetTotalFreeSizeForExpHeap HeapBase_GetFreeSize, NNS_FndGetSizeForMBlockExpHeap HeapBlock_GetSize; for the
// statics, GetRegionOfMBlock GetExistingExpHeapHeaderBounds, RemoveMBlock UnlinkExpHeapHeader, InsertMBlock
// AppendHeaderToExpHeapLL, InitMBlock SetupExpHeapHeader, InitExpHeap InitHeapBaseEXPH, AllocUsedBlockFromFreeBlock
// AllocExpHeapCore, AllocFromHead AllocExpHeapHead, AllocFromTail AllocExpHeapTail and RecycleRegion
// ExpHeap_MarkFreeBounds

#define EXPHEAP_SIGNATURE 0x45585048 // 'EXPH'
#define FREE_BLOCK_SIGNATURE 0x4652  // 'FR'
#define USED_BLOCK_SIGNATURE 0x5544  // 'UD'

#define HEADER_SIZE sizeof(NNSiFndExpHeapMBlockHead)
// What is left of a free block is kept only when it can hold a header and 4 bytes more
#define MIN_FREE_BLOCK (HEADER_SIZE + 4)
// The heap needs room for its heads, a block header and 4 bytes
#define MIN_HEAP_SIZE (sizeof(NNSiFndHeapHead) + sizeof(NNSiFndExpHeapHead) + HEADER_SIZE + 4)

// A used block's attribute: its group in bits 0 to 7, the bytes skipped before its header for alignment in bits 8 to
// 14, and in bit 15 whether it came from the end of the heap
#define BLOCK_GROUP_MASK 0xFF
#define BLOCK_PAD_SHIFT 8
#define BLOCK_PAD_MASK 0x7F
#define BLOCK_DIR_SHIFT 15

// The heap's feature: bit 0 is the allocation mode
#define FEATURE_MODE_MASK 1

static void GetRegionOfMBlock(NNSiMemRegion *region, NNSiFndExpHeapMBlockHead *block);
static NNSiFndExpHeapMBlockHead *RemoveMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block);
static NNSiFndExpHeapMBlockHead *InsertMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block,
                                              NNSiFndExpHeapMBlockHead *after);
static NNSiFndExpHeapMBlockHead *InitMBlock(const NNSiMemRegion *region, u16 signature);
static NNSiFndHeapHead *InitExpHeap(void *start, void *end, u16 optFlag);
static void *AllocUsedBlockFromFreeBlock(NNSiFndExpHeapHead *expHeap, NNSiFndExpHeapMBlockHead *source, void *data,
                                         u32 size, u16 direction);
static void *AllocFromHead(NNSiFndHeapHead *heap, u32 size, int alignment);
static void *AllocFromTail(NNSiFndHeapHead *heap, u32 size, int alignment);
static BOOL RecycleRegion(NNSiFndExpHeapHead *expHeap, const NNSiMemRegion *region);

// The expanded heap's own head, just after the common one
static inline NNSiFndExpHeapHead *ExpHeapOf(NNSiFndHeapHead *heap) {
    return (NNSiFndExpHeapHead *)(AddrOf(heap) + sizeof(NNSiFndHeapHead));
}

// The memory a header stands for
static inline void *DataOf(NNSiFndExpHeapMBlockHead *block) {
    return (void *)(AddrOf(block) + HEADER_SIZE);
}

// The header in front of memory handed out
static inline NNSiFndExpHeapMBlockHead *HeaderOf(const void *data) {
    return (NNSiFndExpHeapMBlockHead *)(AddrOf(data) - HEADER_SIZE);
}

// The first byte past a block
static inline void *EndOf(NNSiFndExpHeapMBlockHead *block) {
    return (void *)(AddrOf(DataOf(block)) + block->blockSize);
}

static inline u16 PaddingOf(const NNSiFndExpHeapMBlockHead *block) {
    return (u16)((block->attribute >> BLOCK_PAD_SHIFT) & BLOCK_PAD_MASK);
}

// The whole stretch a block covers: its header, its data and the padding before it
static void GetRegionOfMBlock(NNSiMemRegion *region, NNSiFndExpHeapMBlockHead *block) {
    region->start = (void *)(AddrOf(block) - PaddingOf(block));
    region->end = EndOf(block);
}

// Takes block out of list, and returns the block that was before it
static NNSiFndExpHeapMBlockHead *RemoveMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block) {
    NNSiFndExpHeapMBlockHead *prev = block->pMBHeadPrev;
    NNSiFndExpHeapMBlockHead *next = block->pMBHeadNext;

    if (prev != NULL) {
        prev->pMBHeadNext = next;
    } else {
        list->head = next;
    }
    if (next != NULL) {
        next->pMBHeadPrev = prev;
    } else {
        list->tail = prev;
    }
    return prev;
}

// Links block in after after, or at the front when after is NULL
static NNSiFndExpHeapMBlockHead *InsertMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block,
                                              NNSiFndExpHeapMBlockHead *after) {
    NNSiFndExpHeapMBlockHead *next;

    block->pMBHeadPrev = after;
    if (after != NULL) {
        next = after->pMBHeadNext;
        after->pMBHeadNext = block;
    } else {
        next = list->head;
        list->head = block;
    }
    block->pMBHeadNext = next;
    if (next != NULL) {
        next->pMBHeadPrev = block;
    } else {
        list->tail = block;
    }
    return block;
}

// Writes an unlinked header at the start of region, covering the rest of it
static NNSiFndExpHeapMBlockHead *InitMBlock(const NNSiMemRegion *region, u16 signature) {
    NNSiFndExpHeapMBlockHead *block = region->start;

    block->signature = signature;
    block->attribute = 0;
    block->blockSize = BytesBetween(DataOf(block), region->end);
    block->pMBHeadPrev = NULL;
    block->pMBHeadNext = NULL;
    return block;
}

static NNSiFndHeapHead *InitExpHeap(void *start, void *end, u16 optFlag) {
    NNSiFndHeapHead *heap = start;
    NNSiFndExpHeapHead *expHeap = ExpHeapOf(heap);
    NNSiFndExpHeapMBlockHead *whole;
    NNSiMemRegion all;

    NNSi_FndInitHeapHead(heap, EXPHEAP_SIGNATURE, (void *)(AddrOf(expHeap) + sizeof(NNSiFndExpHeapHead)), end, optFlag);
    expHeap->groupID = 0;
    expHeap->feature = 0;
    expHeap->feature &= ~FEATURE_MODE_MASK; // NNS_FND_EXPHEAP_FIRST_FIT
    all.start = heap->heapStart;
    all.end = heap->heapEnd;
    whole = InitMBlock(&all, FREE_BLOCK_SIGNATURE);
    expHeap->mbFreeList.head = whole;
    expHeap->mbFreeList.tail = whole;
    expHeap->mbUsedList.head = NULL;
    expHeap->mbUsedList.tail = NULL;
    return heap;
}

// Carves size bytes at data out of the free block source. What is left below and above stays free when it is big
// enough, and joins the new block otherwise
static void *AllocUsedBlockFromFreeBlock(NNSiFndExpHeapHead *expHeap, NNSiFndExpHeapMBlockHead *source, void *data,
                                         u32 size, u16 direction) {
    NNSiMemRegion below;
    NNSiMemRegion above;
    NNSiFndExpHeapMBlockHead *neighbour;
    NNSiFndExpHeapMBlockHead *used;
    NNSiMemRegion usedRegion;
    u32 padding;
    u32 group;

    GetRegionOfMBlock(&below, source);
    above.end = below.end;
    above.start = (void *)(AddrOf(data) + size);
    below.end = (void *)(AddrOf(data) - HEADER_SIZE);

    neighbour = RemoveMBlock(&expHeap->mbFreeList, source);

    if (BytesBetween(below.start, below.end) < MIN_FREE_BLOCK) {
        below.end = below.start;
    } else {
        neighbour = InsertMBlock(&expHeap->mbFreeList, InitMBlock(&below, FREE_BLOCK_SIGNATURE), neighbour);
    }
    if (BytesBetween(above.start, above.end) < MIN_FREE_BLOCK) {
        above.start = above.end;
    } else {
        InsertMBlock(&expHeap->mbFreeList, InitMBlock(&above, FREE_BLOCK_SIGNATURE), neighbour);
    }

    FillAllocMemory((NNSiFndHeapHead *)(AddrOf(expHeap) - sizeof(NNSiFndHeapHead)), below.end,
                    BytesBetween(below.end, above.start));

    usedRegion.start = (void *)(AddrOf(data) - HEADER_SIZE);
    usedRegion.end = above.start;
    used = InitMBlock(&usedRegion, USED_BLOCK_SIGNATURE);
    used->attribute &= ~(1 << BLOCK_DIR_SHIFT);
    used->attribute |= (direction & 1) << BLOCK_DIR_SHIFT;
    padding = (u16)BytesBetween(below.end, used) & BLOCK_PAD_MASK;
    used->attribute &= ~(BLOCK_PAD_MASK << BLOCK_PAD_SHIFT);
    used->attribute |= padding << BLOCK_PAD_SHIFT;
    group = expHeap->groupID & BLOCK_GROUP_MASK;
    used->attribute &= ~BLOCK_GROUP_MASK;
    used->attribute |= group;
    InsertMBlock(&expHeap->mbUsedList, used, expHeap->mbUsedList.tail);
    return data;
}

// Searches the free blocks from the start of the heap: the first that fits in first-fit mode, else the smallest
static void *AllocFromHead(NNSiFndHeapHead *heap, u32 size, int alignment) {
    NNSiFndExpHeapHead *expHeap = ExpHeapOf(heap);
    BOOL takeFirst = (u16)(expHeap->feature & FEATURE_MODE_MASK) == NNS_FND_EXPHEAP_FIRST_FIT;
    NNSiFndExpHeapMBlockHead *block;
    NNSiFndExpHeapMBlockHead *chosen = NULL;
    u32 chosenSize = 0xFFFFFFFF;
    void *chosenData = NULL;

    for (block = expHeap->mbFreeList.head; block != NULL; block = block->pMBHeadNext) {
        void *data = DataOf(block);
        void *aligned = (void *)((AddrOf(data) + (alignment - 1)) & ~(alignment - 1));
        u32 skipped = BytesBetween(data, aligned);

        if (block->blockSize >= size + skipped && chosenSize > block->blockSize) {
            chosenSize = block->blockSize;
            chosen = block;
            chosenData = aligned;
            if (takeFirst || chosenSize == size) {
                break;
            }
        }
    }
    if (chosen != NULL) {
        return AllocUsedBlockFromFreeBlock(expHeap, chosen, chosenData, size, NNS_FND_EXPHEAP_FROM_BOTTOM);
    }
    return NULL;
}

// The same from the end of the heap, placing the block as high in each free block as it goes
static void *AllocFromTail(NNSiFndHeapHead *heap, u32 size, int alignment) {
    NNSiFndExpHeapHead *expHeap = ExpHeapOf(heap);
    BOOL takeFirst = (u16)(expHeap->feature & FEATURE_MODE_MASK) == NNS_FND_EXPHEAP_FIRST_FIT;
    NNSiFndExpHeapMBlockHead *block;
    NNSiFndExpHeapMBlockHead *chosen = NULL;
    u32 chosenSize = 0xFFFFFFFF;
    void *chosenData = NULL;

    for (block = expHeap->mbFreeList.tail; block != NULL; block = block->pMBHeadPrev) {
        void *data = DataOf(block);
        void *top = (void *)(AddrOf(data) + block->blockSize);
        void *aligned = (void *)((AddrOf(top) - size) & ~(alignment - 1));

        if ((s32)(AddrOf(aligned) - AddrOf(data)) >= 0 && chosenSize > block->blockSize) {
            chosenSize = block->blockSize;
            chosen = block;
            chosenData = aligned;
            if (takeFirst || chosenSize == size) {
                break;
            }
        }
    }
    if (chosen != NULL) {
        return AllocUsedBlockFromFreeBlock(expHeap, chosen, chosenData, size, NNS_FND_EXPHEAP_FROM_TOP);
    }
    return NULL;
}

// Gives region back to the free list, joined with a free block just above or below it. Returns FALSE, keeping
// nothing, when the result can't even hold a header
static BOOL RecycleRegion(NNSiFndExpHeapHead *expHeap, const NNSiMemRegion *region) {
    NNSiFndExpHeapMBlockHead *lower = NULL;
    NNSiMemRegion joined = *region;
    NNSiFndExpHeapMBlockHead *block;

    for (block = expHeap->mbFreeList.head; block != NULL; block = block->pMBHeadNext) {
        if (AddrOf(block) < AddrOf(region->start)) {
            lower = block;
            continue;
        }
        if (block == region->end) {
            joined.end = EndOf(block);
            RemoveMBlock(&expHeap->mbFreeList, block);
        }
        break;
    }

    if (lower != NULL && EndOf(lower) == region->start) {
        joined.start = lower;
        lower = RemoveMBlock(&expHeap->mbFreeList, lower);
    }

    if (BytesBetween(joined.start, joined.end) < HEADER_SIZE) {
        return FALSE;
    }
    InsertMBlock(&expHeap->mbFreeList, InitMBlock(&joined, FREE_BLOCK_SIGNATURE), lower);
    return TRUE;
}

NNSFndHeapHandle NNS_FndCreateExpHeapEx(void *startAddress, u32 size, u16 optFlag) {
    void *end = (void *)((AddrOf(startAddress) + size) & ~3);

    startAddress = (void *)((AddrOf(startAddress) + 3) & ~3);
    if (AddrOf(startAddress) > AddrOf(end) || BytesBetween(startAddress, end) < MIN_HEAP_SIZE) {
        return NULL;
    }
    return InitExpHeap(startAddress, end, optFlag);
}

void NNS_FndDestroyExpHeap(NNSFndHeapHandle heap) {
    NNSi_FndFinalizeHeap(heap);
}

// A negative alignment takes the block from the end of the heap
void *NNS_FndAllocFromExpHeapEx(NNSFndHeapHandle heap, u32 size, int alignment) {
    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;
    if (alignment >= 0) {
        return AllocFromHead(heap, size, alignment);
    } else {
        return AllocFromTail(heap, size, -alignment);
    }
}

// Grows a used block into the free block right after it, or shrinks it, returning its new size. Returns 0 when it
// can't grow that far
u32 NNS_FndResizeForMBlockExpHeap(NNSFndHeapHandle heap, void *memBlock, u32 size) {
    NNSiFndExpHeapHead *expHeap = ExpHeapOf(heap);
    NNSiFndExpHeapMBlockHead *block = HeaderOf(memBlock);
    u32 oldSize;

    size = (size + 3) & ~3;
    oldSize = block->blockSize;
    if (size == oldSize) {
        return size;
    }

    if (size > oldSize) {
        void *end = (void *)(AddrOf(DataOf(block)) + oldSize);
        NNSiFndExpHeapMBlockHead *next;
        NNSiMemRegion rest;
        NNSiFndExpHeapMBlockHead *neighbour;
        void *grownFrom;

        for (next = expHeap->mbFreeList.head; next != NULL; next = next->pMBHeadNext) {
            if (next == end) {
                break;
            }
        }
        if (next == NULL || size > oldSize + HEADER_SIZE + next->blockSize) {
            return 0;
        }

        GetRegionOfMBlock(&rest, next);
        neighbour = RemoveMBlock(&expHeap->mbFreeList, next);
        grownFrom = rest.start;
        rest.start = (void *)(AddrOf(memBlock) + size);
        if (BytesBetween(rest.start, rest.end) < HEADER_SIZE) {
            rest.start = rest.end;
        }
        block->blockSize = BytesBetween(memBlock, rest.start);
        if (BytesBetween(rest.start, rest.end) >= HEADER_SIZE) {
            InsertMBlock(&expHeap->mbFreeList, InitMBlock(&rest, FREE_BLOCK_SIGNATURE), neighbour);
        }
        FillAllocMemory(heap, grownFrom, BytesBetween(grownFrom, rest.start));
    } else {
        NNSiMemRegion cut;

        cut.start = (void *)(AddrOf(memBlock) + size);
        cut.end = EndOf(block);
        block->blockSize = size;
        if (!RecycleRegion(expHeap, &cut)) {
            block->blockSize = oldSize;
        }
    }
    return block->blockSize;
}

void NNS_FndFreeToExpHeap(NNSFndHeapHandle heap, void *memBlock) {
    NNSiFndExpHeapHead *expHeap = ExpHeapOf(heap);
    NNSiFndExpHeapMBlockHead *block = HeaderOf(memBlock);
    NNSiMemRegion freed;

    GetRegionOfMBlock(&freed, block);
    RemoveMBlock(&expHeap->mbUsedList, block);
    RecycleRegion(expHeap, &freed);
}

u32 NNS_FndGetTotalFreeSizeForExpHeap(NNSFndHeapHandle heap) {
    u32 total = 0;
    NNSiFndExpHeapMBlockHead *block;

    for (block = ExpHeapOf(heap)->mbFreeList.head; block != NULL; block = block->pMBHeadNext) {
        total += block->blockSize;
    }
    return total;
}

// The biggest block that could be allocated with the alignment, taken from the free block that wastes the fewest
// bytes on alignment when several allow the same size
u32 HeapBase_GetHighestAllocatableSize(NNSFndHeapHandle heap, int alignment) {
    u32 best;
    u32 bestSkip;
    NNSiFndExpHeapMBlockHead *block;

    alignment = abs(alignment);
    best = 0;
    bestSkip = 0xFFFFFFFF;
    for (block = ExpHeapOf(heap)->mbFreeList.head; block != NULL; block = block->pMBHeadNext) {
        void *data = DataOf(block);
        u32 aligned = (AddrOf(data) + (alignment - 1)) & ~(alignment - 1);
        u32 end = AddrOf(data) + block->blockSize;

        if (aligned < end) {
            u32 room = end - aligned;
            u32 skip = aligned - AddrOf(data);

            if (best < room || (best == room && bestSkip > skip)) {
                best = room;
                bestSkip = skip;
            }
        }
    }
    return best;
}

// Returns the old mode
u16 NNS_FndSetExpHeapFitMode(NNSFndHeapHandle heap, u16 mode) {
    NNSiFndExpHeapHead *expHeap = ExpHeapOf(heap);
    u16 old = (u16)(expHeap->feature & FEATURE_MODE_MASK);

    expHeap->feature &= ~FEATURE_MODE_MASK;
    expHeap->feature |= mode & FEATURE_MODE_MASK;
    return old;
}

// Sets the group that blocks allocated from now on belong to, returning the old one
u16 NNS_FndSetExpHeapGroup(NNSFndHeapHandle heap, u16 groupID) {
    NNSiFndExpHeapHead *expHeap = ExpHeapOf(heap);
    u16 old = expHeap->groupID;

    expHeap->groupID = groupID;
    return old;
}

// Calls callback with every used block, oldest first
void HeapBase_DumpMemory(NNSFndHeapHandle heap, NNSFndHeapBlockCallback callback, u32 param) {
    NNSiFndExpHeapMBlockHead *block = ExpHeapOf(heap)->mbUsedList.head;

    while (block != NULL) {
        NNSiFndExpHeapMBlockHead *next = block->pMBHeadNext;

        callback(DataOf(block), heap, param);
        block = next;
    }
}

u32 NNS_FndGetSizeForMBlockExpHeap(const void *memBlock) {
    return HeaderOf(memBlock)->blockSize;
}

u16 NNS_FndGetExpHeapBlockGroup(const void *memBlock) {
    return (u16)(HeaderOf(memBlock)->attribute & BLOCK_GROUP_MASK);
}
