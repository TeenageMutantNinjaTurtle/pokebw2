#include "gfdi_LinkedListVramMan_Common.h"
#include "nnsys/gfd.h"

// NitroSystem's gfd_LinkedListPlttVramMan.c: the linked-list palette VRAM manager, which frees what it allocated

typedef struct {
    GfdVramFreeList list;
    GfdVramBlock *pool;
    u32 size;
    GfdVramBlock *work;
    u32 workSize;
} GfdLnkPlttVramManager;

static GfdLnkPlttVramManager plttMgr_;

u32 NNS_GfdGetLnkPlttVramManagerWorkSize(u32 numMemBlk) {
    return numMemBlk * sizeof(GfdVramBlock);
}

void NNS_GfdInitLnkPlttVramManager(u32 szByte, void *pManagementWork, u32 szByteManagementWork, BOOL useAsDefault) {
    plttMgr_.size = szByte;
    plttMgr_.work = pManagementWork;
    plttMgr_.workSize = szByteManagementWork;
    NNS_GfdResetLnkPlttVramState();

    if (useAsDefault) {
        NNS_GfdDefaultFuncAllocPlttVram = NNS_GfdAllocLnkPlttVram;
        NNS_GfdDefaultFuncFreePlttVram = NNS_GfdFreeLnkPlttVram;
    }
}

NNSGfdPlttKey NNS_GfdAllocLnkPlttVram(u32 szByte, BOOL is4pltt, u32 opt) {
    u32 addr;
    BOOL ok;

    szByte = GfdPlttAllocSize(szByte);
    if (szByte >= GFD_PLTT_ALLOC_LIMIT) {
        return NNS_GFD_ALLOC_ERROR_PLTTKEY;
    }

    if (is4pltt) {
        ok = NNSi_GfdAllocLnkVramAligned(&plttMgr_.list, &plttMgr_.pool, &addr, szByte, 8);
        if (addr + szByte > GFD_PLTT4_LIMIT) {
            NNSi_GfdFreeLnkVram(&plttMgr_.list, &plttMgr_.pool, addr, szByte);
            return NNS_GFD_ALLOC_ERROR_PLTTKEY;
        }
    } else {
        ok = NNSi_GfdAllocLnkVramAligned(&plttMgr_.list, &plttMgr_.pool, &addr, szByte, 16);
    }

    if (ok) {
        return GfdMakePlttKey(addr, szByte);
    }
    return NNS_GFD_ALLOC_ERROR_PLTTKEY;
}

// Returns 0 when freed and 1 when the manager had no block left to free it with
int NNS_GfdFreeLnkPlttVram(NNSGfdPlttKey key) {
    const u32 addr = NNS_GfdGetPlttKeyAddr(key);
    const u32 size = NNS_GfdGetPlttKeySize(key);
    const BOOL ok = NNSi_GfdFreeLnkVram(&plttMgr_.list, &plttMgr_.pool, addr, size);

    if (ok) {
        return 0;
    }
    return 1;
}

void NNS_GfdResetLnkPlttVramState(void) {
    plttMgr_.pool = NNSi_GfdInitLnkVramBlockPool(plttMgr_.work, plttMgr_.workSize / sizeof(GfdVramBlock));
    NNSi_GfdInitLnkVramMan(&plttMgr_.list);
    NNSi_GfdAddNewFreeBlock(&plttMgr_.list, &plttMgr_.pool, 0, plttMgr_.size);
    NNSi_GfdMergeAllFreeBlocks(&plttMgr_.list, &plttMgr_.pool);
}
