#include "gfdi_LinkedListVramMan_Common.h"

// NitroSystem's linked-list VRAM allocator, shared by the texture and palette managers. pokediamond's link map has the
// file as gfdi_linkedlist (cut at 15 characters); the rest of the name is a guess

// A free span being grown by the blocks that touch it, from lo up to hi
typedef struct {
    u32 lo;
    u32 hi;
} GfdVramSpan;

static BOOL AbsorbTouchingBlocks(GfdVramFreeList *list, GfdVramBlock **pool, GfdVramSpan *span);

static inline void PushBlock(GfdVramBlock **head, GfdVramBlock *block) {
    if (*head != NULL) {
        (*head)->prev = block;
    }
    block->next = *head;
    block->prev = NULL;
    *head = block;
}

static inline void UnlinkBlock(GfdVramBlock **head, GfdVramBlock *block) {
    GfdVramBlock *before = block->prev;
    GfdVramBlock *after = block->next;

    if (before != NULL) {
        before->next = after;
    } else {
        *head = after;
    }
    if (after != NULL) {
        after->prev = before;
    }
}

static inline GfdVramBlock *TakePoolBlock(GfdVramBlock **pool) {
    GfdVramBlock *block = *pool;

    if (block != NULL) {
        *pool = block->next;
    }
    return block;
}

static inline void SetBlock(GfdVramBlock *block, u32 start, u32 size) {
    block->start = start;
    block->size = size;
    block->prev = NULL;
    block->next = NULL;
}

// Moves the free blocks that touch the span into it, and their blocks back to the pool, and returns whether there
// were any
static BOOL AbsorbTouchingBlocks(GfdVramFreeList *list, GfdVramBlock **pool, GfdVramSpan *span) {
    GfdVramBlock *block = list->head;
    GfdVramBlock *next;
    BOOL absorbed = FALSE;

    while (block != NULL) {
        next = block->next;

        if (block->start == span->hi) {
            span->hi = block->start + block->size;
            UnlinkBlock(&list->head, block);
            PushBlock(pool, block);
            absorbed |= TRUE;
        }
        if (span->lo == block->start + block->size) {
            span->lo = block->start;
            UnlinkBlock(&list->head, block);
            PushBlock(pool, block);
            absorbed |= TRUE;
        }

        block = next;
    }
    return absorbed;
}

void NNSi_GfdInitLnkVramMan(GfdVramFreeList *list) {
    list->head = NULL;
}

GfdVramBlock *NNSi_GfdInitLnkVramBlockPool(GfdVramBlock *blocks, u32 count) {
    u32 i;

    for (i = 0; i < count - 1; i++) {
        blocks[i].next = &blocks[i + 1];
        blocks[i + 1].prev = &blocks[i];
    }
    blocks[0].prev = NULL;
    (blocks + count - 1)->next = NULL;
    return blocks;
}

BOOL NNSi_GfdAddNewFreeBlock(GfdVramFreeList *list, GfdVramBlock **pool, u32 start, u32 size) {
    GfdVramBlock *block = TakePoolBlock(pool);

    if (block != NULL) {
        SetBlock(block, start, size);
        PushBlock(&list->head, block);
        return TRUE;
    }
    return FALSE;
}

BOOL NNSi_GfdAllocLnkVram(GfdVramFreeList *list, GfdVramBlock **pool, u32 *outAddr, u32 size) {
    return NNSi_GfdAllocLnkVramAligned(list, pool, outAddr, size, 0);
}

BOOL NNSi_GfdAllocLnkVramAligned(GfdVramFreeList *list, GfdVramBlock **pool, u32 *outAddr, u32 size, u32 align) {
    GfdVramBlock *block = list->head;
    GfdVramBlock *chosen = NULL;
    u32 addr;
    u32 taken;
    u32 skipped;

    // The first free block that holds the size once its start is aligned
    while (block != NULL) {
        if (align > 1) {
            addr = (block->start + (align - 1)) & ~(align - 1);
            skipped = addr - block->start;
            taken = size + skipped;
        } else {
            addr = block->start;
            skipped = 0;
            taken = size;
        }

        if (block->size >= taken) {
            chosen = block;
            break;
        }
        block = block->next;
    }

    if (chosen != NULL) {
        // What aligning skips stays free, as a block of its own
        if (skipped > 0) {
            GfdVramBlock *gap = TakePoolBlock(pool);

            if (gap == NULL) {
                goto fail;
            }
            SetBlock(gap, chosen->start, skipped);
            PushBlock(&list->head, gap);
        }

        chosen->size -= taken;
        chosen->start += taken;
        if (chosen->size == 0) {
            UnlinkBlock(&list->head, chosen);
            PushBlock(pool, chosen);
        }
        *outAddr = addr;
        return TRUE;
    }

fail:
    *outAddr = 0;
    return FALSE;
}

void NNSi_GfdMergeAllFreeBlocks(GfdVramFreeList *list, GfdVramBlock **pool) {
    GfdVramBlock *block = list->head;

    while (block != NULL) {
        GfdVramSpan span;

        span.lo = block->start;
        span.hi = block->start + block->size;
        if (AbsorbTouchingBlocks(list, pool, &span)) {
            // The list changed, so start over
            block->start = span.lo;
            block->size = span.hi - span.lo;
            block = list->head;
        } else {
            block = block->next;
        }
    }
}

BOOL NNSi_GfdFreeLnkVram(GfdVramFreeList *list, GfdVramBlock **pool, u32 addr, u32 size) {
    GfdVramSpan span;
    GfdVramBlock *block;

    span.lo = addr;
    span.hi = addr + size;
    AbsorbTouchingBlocks(list, pool, &span);

    block = TakePoolBlock(pool);
    if (block == NULL) {
        return FALSE;
    }
    block->start = span.lo;
    block->size = span.hi - span.lo;
    block->prev = NULL;
    block->next = NULL;
    PushBlock(&list->head, block);
    return TRUE;
}
