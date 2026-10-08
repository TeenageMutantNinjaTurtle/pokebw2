#include "heapcommoni.h"
#include "nnsys/fnd.h"

// NitroSystem's unit heaps (NNS_Fnd): blocks of one size, the free ones chained through their first word. swan calls
// none of them by name. The game never makes one, so only what the unit heap allocator in allocator.c reaches is
// left; creating a unit heap was dead-stripped

static NNSiFndUnitBlock *TakeFreeUnit(NNSiFndUnitFreeList *list);

// The unit heap's own head, just after the common one
static inline NNSiFndUnitHeap *UnitHeapOf(NNSiFndHeapHead *heap) {
    return (NNSiFndUnitHeap *)(AddrOf(heap) + sizeof(NNSiFndHeapHead));
}

// Unchains the first free block, or returns NULL when there is none
static NNSiFndUnitBlock *TakeFreeUnit(NNSiFndUnitFreeList *list) {
    NNSiFndUnitBlock *first = list->head;

    if (first != NULL) {
        list->head = first->next;
    }
    return first;
}

void *NNS_FndUnitHeapAlloc(NNSFndHeapHandle heap) {
    NNSiFndUnitHeap *unitHeap = UnitHeapOf(heap);
    NNSiFndUnitBlock *block = TakeFreeUnit(&unitHeap->freeList);

    if (block != NULL) {
        FillAllocMemory(heap, block, unitHeap->unitSize);
    }
    return block;
}

void NNS_FndUnitHeapFree(NNSFndHeapHandle heap, void *memBlock) {
    NNSiFndUnitHeap *unitHeap = UnitHeapOf(heap);
    NNSiFndUnitBlock *block = memBlock;

    block->next = unitHeap->freeList.head;
    unitHeap->freeList.head = block;
}
