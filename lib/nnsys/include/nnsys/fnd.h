#ifndef POKEBW2_NNSYS_FND_H
#define POKEBW2_NNSYS_FND_H

#include "types.h"

// NitroSystem's foundation (NNS_Fnd): linked lists, the expanded, frame and unit heaps and the allocators over them.
// Names are NitroSystem's where pret's decompilations use them, then swan's, then ours; the sources' header comments
// list swan's names that differ

// Lists (list.c), which link any struct through an NNSFndLink at offset in it

typedef struct {
    void *prevObject;
    void *nextObject;
} NNSFndLink;

typedef struct {
    void *headObject;
    void *tailObject;
    u16 numObjects;
    u16 offset;
} NNSFndList;

void NNS_FndInitList(NNSFndList *list, u16 offset);
void NNS_FndAppendListObject(NNSFndList *list, void *object);
void NNS_FndPrependListObject(NNSFndList *list, void *object);
// Inserts object before target, or last when target is NULL
void NNS_FndInsertListObject(NNSFndList *list, void *target, void *object);
void NNS_FndRemoveListObject(NNSFndList *list, void *object);
// The first object when object is NULL
void *NNS_FndGetNextListObject(NNSFndList *list, void *object);
// The last object when object is NULL
void *NNS_FndGetPrevListObject(NNSFndList *list, void *object);

// What every heap starts with (heapcommon.c). A heap is linked into the child list of the heap its memory came from

// Clear allocated memory to 0
#define NNS_FND_HEAP_CLEAR_ON_ALLOC (1 << 0)

typedef struct NNSiFndHeapHead {
    u32 signature;
    NNSFndLink link;
    NNSFndList childList;
    void *heapStart;
    void *heapEnd;
    u32 attribute; // The options (NNS_FND_HEAP_CLEAR_ON_ALLOC) in the low byte
} NNSiFndHeapHead;

typedef NNSiFndHeapHead *NNSFndHeapHandle;

// Expanded heaps (expheap.c): blocks of any size, allocated from either end. A negative alignment allocates from the
// end of the heap

// Allocate from the first free block big enough, or from the smallest
#define NNS_FND_EXPHEAP_FIRST_FIT 0
#define NNS_FND_EXPHEAP_BEST_FIT 1

#define NNS_FND_EXPHEAP_FROM_BOTTOM 0
#define NNS_FND_EXPHEAP_FROM_TOP 1

typedef struct NNSiFndExpHeapMBlockHead NNSiFndExpHeapMBlockHead;

// The header before every block, free ('FR') or used ('UD')
struct NNSiFndExpHeapMBlockHead {
    u16 signature;
    u16 attribute; // A used block's group in the low byte, its alignment padding in bits 8 to 14, its end in bit 15
    u32 blockSize;
    NNSiFndExpHeapMBlockHead *pMBHeadPrev;
    NNSiFndExpHeapMBlockHead *pMBHeadNext;
};

typedef struct {
    NNSiFndExpHeapMBlockHead *head;
    NNSiFndExpHeapMBlockHead *tail;
} NNSiFndExpMBlockList;

// Follows the NNSiFndHeapHead of an expanded heap
typedef struct {
    NNSiFndExpMBlockList mbFreeList;
    NNSiFndExpMBlockList mbUsedList;
    u16 groupID;
    u16 feature; // The fit mode (NNS_FND_EXPHEAP_FIRST_FIT or _BEST_FIT) in bit 0
} NNSiFndExpHeapHead;

typedef void (*NNSFndHeapBlockCallback)(void *memBlock, NNSFndHeapHandle heap, u32 param);

NNSFndHeapHandle NNS_FndCreateExpHeapEx(void *startAddress, u32 size, u16 optFlag);
void NNS_FndDestroyExpHeap(NNSFndHeapHandle heap);
void *NNS_FndAllocFromExpHeapEx(NNSFndHeapHandle heap, u32 size, int alignment);
u32 NNS_FndResizeForMBlockExpHeap(NNSFndHeapHandle heap, void *memBlock, u32 size);
void NNS_FndFreeToExpHeap(NNSFndHeapHandle heap, void *memBlock);
u32 NNS_FndGetTotalFreeSizeForExpHeap(NNSFndHeapHandle heap);
u32 HeapBase_GetHighestAllocatableSize(NNSFndHeapHandle heap, int alignment);
u16 NNS_FndSetExpHeapFitMode(NNSFndHeapHandle heap, u16 mode);
u16 NNS_FndSetExpHeapGroup(NNSFndHeapHandle heap, u16 groupID);
void HeapBase_DumpMemory(NNSFndHeapHandle heap, NNSFndHeapBlockCallback callback, u32 param);
u32 NNS_FndGetSizeForMBlockExpHeap(const void *memBlock);
u16 NNS_FndGetExpHeapBlockGroup(const void *memBlock);

// Frame heaps (frameheap.c): allocation moves a pointer from either end, and memory is freed only all at once

#define NNS_FND_FRMHEAP_RELEASE_LOW (1 << 0)
#define NNS_FND_FRMHEAP_RELEASE_HIGH (1 << 1)
#define NNS_FND_FRMHEAP_RELEASE_BOTH (NNS_FND_FRMHEAP_RELEASE_LOW | NNS_FND_FRMHEAP_RELEASE_HIGH)

typedef struct NNSiFndFrameHeapMark NNSiFndFrameHeapMark;

// Where both ends were, recorded under a tag in memory allocated from the heap
struct NNSiFndFrameHeapMark {
    u32 tag;
    void *low;
    void *high;
    NNSiFndFrameHeapMark *prev;
};

// Follows the NNSiFndHeapHead of a frame heap
typedef struct {
    void *low;
    void *high;
    NNSiFndFrameHeapMark *lastMark;
} NNSiFndFrameHeap;

NNSFndHeapHandle NNS_FndCreateFrmHeapEx(void *startAddress, u32 size, u16 optFlag);
void NNS_FndDestroyFrmHeap(NNSFndHeapHandle heap);
void *NNS_FndAllocFromFrmHeapEx(NNSFndHeapHandle heap, u32 size, int alignment);
void NNS_FndFreeToFrmHeap(NNSFndHeapHandle heap, int mode);
BOOL NNS_FndRecordStateForFrmHeap(NNSFndHeapHandle heap, u32 tag);
BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tag);

// Unit heaps (unitheap.c): blocks of one size, kept in a free list

typedef struct NNSiFndUnitBlock NNSiFndUnitBlock;

struct NNSiFndUnitBlock {
    NNSiFndUnitBlock *next;
};

typedef struct {
    NNSiFndUnitBlock *head;
} NNSiFndUnitFreeList;

// Follows the NNSiFndHeapHead of a unit heap
typedef struct {
    NNSiFndUnitFreeList freeList;
    u32 unitSize;
} NNSiFndUnitHeap;

void *NNS_FndUnitHeapAlloc(NNSFndHeapHandle heap);
void NNS_FndUnitHeapFree(NNSFndHeapHandle heap, void *memBlock);

static inline u32 NNS_FndGetUnitHeapUnitSize(NNSFndHeapHandle heap) {
    return ((NNSiFndUnitHeap *)((u32)heap + sizeof(NNSiFndHeapHead)))->unitSize;
}

// Allocators (allocator.c): a heap and its parameters behind one pair of functions

typedef struct NNSFndAllocator NNSFndAllocator;

typedef void *(*NNSFndFuncAllocatorAlloc)(NNSFndAllocator *allocator, u32 size);
typedef void (*NNSFndFuncAllocatorFree)(NNSFndAllocator *allocator, void *memBlock);

typedef struct {
    NNSFndFuncAllocatorAlloc pfAlloc;
    NNSFndFuncAllocatorFree pfFree;
} NNSFndAllocatorFunc;

struct NNSFndAllocator {
    const NNSFndAllocatorFunc *pFunc;
    void *pHeap;
    u32 heapParam1; // The alignment, or for a NitroSDK heap its arena
    u32 heapParam2;
};

void *NNS_FndAllocFromAllocator(NNSFndAllocator *allocator, u32 size);
void NNS_FndFreeToAllocator(NNSFndAllocator *allocator, void *memBlock);
void NNS_FndInitAllocatorForExpHeap(NNSFndAllocator *allocator, NNSFndHeapHandle heap, int alignment);

#endif // POKEBW2_NNSYS_FND_H
