#include "types.h"
#include "gfl/heapsys.h"
#include "nitro/os.h"

// A heap of DTCM, an OS heap in the DTCM arena. The name is a guess, from GFL_HeapDTCMInit

#define DTCM_HEAP_MAX_SIZE 0x2f80

typedef struct {
    u32 unk0;
    int handle;
    u32 unk8;
} DTCMHeap;

static DTCMHeap sDTCMHeap;

BOOL GFL_HeapDTCMInitCore(u32 size) {
    void *start;
    void *lo;
    BOOL result;

    if (size > DTCM_HEAP_MAX_SIZE) {
        return FALSE;
    }
    start = GetUserMemRegionStart(OS_ARENA_DTCM);
    SetUserMemRegionEnd(OS_ARENA_DTCM, (void *)(HW_DTCM + 0x3000));
    result = TRUE;
    lo = mem_init_alloc_area(OS_ARENA_DTCM, start, (u8 *)start + size, 1);
    SetUserMemRegionStart(OS_ARENA_DTCM, lo);
    sDTCMHeap.handle = mem_bind_range(OS_ARENA_DTCM, lo, (u8 *)start + size);
    if (sDTCMHeap.handle == OS_HEAP_INVALID) {
        result = FALSE;
    }
    return result;
}

void *GFL_HeapDTCMAllocateCore(u32 size) {
    return malloc_device(OS_ARENA_DTCM, sDTCMHeap.handle, size);
}

BOOL freeBlkFromDTCM(void *ptr) {
    free_device(OS_ARENA_DTCM, sDTCMHeap.handle, ptr);
    return TRUE;
}
