#ifndef POKEBW2_NNSYS_FND_H
#define POKEBW2_NNSYS_FND_H

#include "types.h"

// NitroSystem's expanded heaps (NNS_Fnd), under swan's names: NNS_FndCreateExpHeapEx, NNS_FndDestroyExpHeap,
// NNS_FndAllocFromExpHeapEx, NNS_FndResizeForMBlockExpHeap, NNS_FndFreeToExpHeap, NNS_FndGetTotalFreeSizeForExpHeap,
// NNS_FndGetAllocatableSizeForExpHeapEx, NNS_FndVisitAllocatedForExpHeap, NNS_FndGetSizeForMBlockExpHeap and
// NNS_FndInitAllocatorForExpHeap. A negative alignment allocates from the end of the heap

typedef void *NNSFndHeapHandle;

// The start of a heap, which records where it ends
typedef struct {
    u8 unk0[0x18];
    void *heapStart;
    void *heapEnd;
} NNSiFndHeapHead;

typedef struct {
    u8 data[0x10];
} NNSFndAllocator;

typedef void (*NNSFndHeapVisitor)(void *block, NNSFndHeapHandle heap, u32 param);

// NitroSystem's doubly linked lists of objects that hold their link at an offset: NNS_FndInitList,
// NNS_FndAppendListObject, NNS_FndRemoveListObject and NNS_FndGetNextListObject (our names, from NitroSystem's)
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
void NNS_FndRemoveListObject(NNSFndList *list, void *object);
// The object after object, or the first when it is NULL
void *NNS_FndGetNextListObject(NNSFndList *list, void *object);

NNSFndHeapHandle InitHeapBaseSafe(void *start, u32 size, u16 flags);
void func_0205ef78(NNSFndHeapHandle heap);
void *AllocOnHeapBase(NNSFndHeapHandle heap, u32 size, int alignment);
u32 ExpHeap_ResizeBlock(NNSFndHeapHandle heap, void *block, u32 size);
void FreeFromHeapBase(NNSFndHeapHandle heap, void *block);
u32 HeapBase_GetFreeSize(NNSFndHeapHandle heap);
u32 HeapBase_GetHighestAllocatableSize(NNSFndHeapHandle heap, int alignment);
void HeapBase_DumpMemory(NNSFndHeapHandle heap, NNSFndHeapVisitor visitor, u32 param);
u32 HeapBlock_GetSize(const void *block);
void CreateExpHeapAllocator(NNSFndAllocator *allocator, NNSFndHeapHandle heap, int alignment);

#endif // POKEBW2_NNSYS_FND_H
