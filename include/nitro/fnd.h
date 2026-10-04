#ifndef POKEBW2_NITRO_FND_H
#define POKEBW2_NITRO_FND_H

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

#endif // POKEBW2_NITRO_FND_H
