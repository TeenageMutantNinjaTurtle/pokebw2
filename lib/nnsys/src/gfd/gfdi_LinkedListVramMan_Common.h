#ifndef POKEBW2_NNSYS_GFDI_LINKEDLISTVRAMMAN_COMMON_H
#define POKEBW2_NNSYS_GFDI_LINKEDLISTVRAMMAN_COMMON_H

#include "types.h"

// The free-list allocator that the linked-list texture and palette VRAM managers share. A manager keeps its free
// spans of VRAM as blocks in a list, takes new blocks from a pool in the work memory it is given, and gives them back
// there. The function names are the SDK's, from pokediamond's disassembly; the types and fields are named here

// A free span of VRAM, linked both ways
typedef struct GfdVramBlock {
    u32 start;
    u32 size;
    struct GfdVramBlock *prev;
    struct GfdVramBlock *next;
} GfdVramBlock;

typedef struct {
    GfdVramBlock *head;
} GfdVramFreeList;

void NNSi_GfdInitLnkVramMan(GfdVramFreeList *list);
// Links the blocks of the array into a list, the pool, and returns its head
GfdVramBlock *NNSi_GfdInitLnkVramBlockPool(GfdVramBlock *blocks, u32 count);
BOOL NNSi_GfdAddNewFreeBlock(GfdVramFreeList *list, GfdVramBlock **pool, u32 start, u32 size);
BOOL NNSi_GfdAllocLnkVram(GfdVramFreeList *list, GfdVramBlock **pool, u32 *outAddr, u32 size);
BOOL NNSi_GfdAllocLnkVramAligned(GfdVramFreeList *list, GfdVramBlock **pool, u32 *outAddr, u32 size, u32 align);
// Joins the free blocks that touch
void NNSi_GfdMergeAllFreeBlocks(GfdVramFreeList *list, GfdVramBlock **pool);
BOOL NNSi_GfdFreeLnkVram(GfdVramFreeList *list, GfdVramBlock **pool, u32 addr, u32 size);

#endif // POKEBW2_NNSYS_GFDI_LINKEDLISTVRAMMAN_COMMON_H
