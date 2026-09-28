#ifndef POKEBW2_GFL_CLACT_H
#define POKEBW2_GFL_CLACT_H

#include "types.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"

// Cell actors, the OAM sprites of the 2D engines

// Holds cell actors, 0xe4 bytes each
typedef struct ClActUnit ClActUnit;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC;
    // For ClActVRAMManager_Init
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
} ClActSysSetup;

void ClActSys_Create(const ClActSysSetup *setup, const BGSysVRAMConfig *vramConfig, HeapID heapId);
void func_0204b758(void);
void func_0204b794(void);
void func_0204b7c8(void);
ClActUnit *func_0204bf1c(u16 count, u8 a1, HeapID heapId);
void func_0204bf98(ClActUnit *unit);
void func_0204c028(ClActUnit *unit);

#endif // POKEBW2_GFL_CLACT_H
