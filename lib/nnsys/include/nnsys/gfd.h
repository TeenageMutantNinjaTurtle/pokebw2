#ifndef POKEBW2_NNSYS_GFD_H
#define POKEBW2_NNSYS_GFD_H

#include "types.h"

// NitroSystem's VRAM managers (NNS_Gfd) for textures and palettes. A key packs where an allocation is and its size, 0
// when it failed

// Where a transfer goes: the BG palettes or the OBJ characters of the main or sub engine
#define NNS_GFD_DST_2D_BG_PLTT_MAIN 0xf
#define NNS_GFD_DST_2D_OBJ_CHAR_MAIN 0x13
#define NNS_GFD_DST_2D_BG_PLTT_SUB 0x1f
#define NNS_GFD_DST_2D_OBJ_CHAR_SUB 0x23

typedef u32 NNSGfdTexKey;
typedef u32 NNSGfdPlttKey;

// Where in VRAM a key's allocation is
#define NNS_GFD_KEY_ADDR_SHIFT 3

static inline u32 NNS_GfdGetTexKeyAddr(NNSGfdTexKey key) {
    return (u32)((key & 0xffff) << NNS_GFD_KEY_ADDR_SHIFT);
}

static inline u32 NNS_GfdGetPlttKeyAddr(NNSGfdPlttKey key) {
    return (u32)((key & 0xffff) << NNS_GFD_KEY_ADDR_SHIFT);
}

typedef NNSGfdTexKey (*NNSGfdFuncAllocTexVram)(u32 szByte, BOOL is4x4comp, u32 opt);
typedef int (*NNSGfdFuncFreeTexVram)(NNSGfdTexKey key);
typedef NNSGfdPlttKey (*NNSGfdFuncAllocPlttVram)(u32 szByte, BOOL is4pltt, u32 opt);
typedef int (*NNSGfdFuncFreePlttVram)(NNSGfdPlttKey key);

// The managers that NNS_GfdAllocTexVram and the others use, which a manager's init sets when it is the default:
// NNS_GfdDefaultFuncAllocTexVram and the rest, under swan's names
extern NNSGfdFuncAllocTexVram g_TexVRAMAllocFunc;
extern NNSGfdFuncFreeTexVram g_TexVRAMFreeFunc;
extern NNSGfdFuncAllocPlttVram g_PltVRAMAllocFunc;
extern NNSGfdFuncFreePlttVram g_PltVRAMFreeFunc;

static inline NNSGfdTexKey NNS_GfdAllocTexVram(u32 szByte, BOOL is4x4comp, u32 opt) {
    return (*g_TexVRAMAllocFunc)(szByte, is4x4comp, opt);
}

static inline int NNS_GfdFreeTexVram(NNSGfdTexKey key) {
    return (*g_TexVRAMFreeFunc)(key);
}

static inline NNSGfdPlttKey NNS_GfdAllocPlttVram(u32 szByte, BOOL is4pltt, u32 opt) {
    return (*g_PltVRAMAllocFunc)(szByte, is4pltt, opt);
}

static inline int NNS_GfdFreePlttVram(NNSGfdPlttKey key) {
    return (*g_PltVRAMFreeFunc)(key);
}

// Where each region of a frame manager is allocated up to, to go back to later
typedef struct {
    u32 address[10];
} NNSGfdFrmTexVramState;

typedef struct {
    u32 address[2];
} NNSGfdFrmPlttVramState;

void NNS_GfdGetFrmTexVramState(NNSGfdFrmTexVramState *state);
void NNS_GfdSetFrmTexVramState(const NNSGfdFrmTexVramState *state);
void NNS_GfdGetFrmPlttVramState(NNSGfdFrmPlttVramState *state);
void NNS_GfdSetFrmPlttVramState(const NNSGfdFrmPlttVramState *state);
NNSGfdTexKey NNS_GfdAllocFrmTexVram(u32 szByte, BOOL is4x4comp, u32 opt);
// Allocates from the low end of palette VRAM when bAllocFromLo is set
NNSGfdPlttKey NNS_GfdAllocFrmPlttVram(u32 szByte, BOOL is4pltt, BOOL bAllocFromLo);
int NNS_GfdFreeLnkTexVram(NNSGfdTexKey key);
int NNS_GfdFreeLnkPlttVram(NNSGfdPlttKey key);

// The frame managers, which free only from the top, and the linked-list ones, which need work memory
void NNS_GfdInitFrmTexVramManager(u16 numSlot, BOOL useAsDefault);
u32 NNS_GfdGetLnkTexVramManagerWorkSize(u32 numMemBlk);
void NNS_GfdInitLnkTexVramManager(u32 szByte, u32 szByteFor4x4, void *pManagementWork, u32 szByteManagementWork,
                                  BOOL useAsDefault);
u32 NNS_GfdGetLnkPlttVramManagerWorkSize(u32 numMemBlk);
void NNS_GfdInitLnkPlttVramManager(u32 szByte, void *pManagementWork, u32 szByteManagementWork, BOOL useAsDefault);

#endif // POKEBW2_NNSYS_GFD_H
