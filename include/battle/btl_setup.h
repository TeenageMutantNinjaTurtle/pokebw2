#ifndef POKEBW2_BATTLE_BTL_SETUP_H
#define POKEBW2_BATTLE_BTL_SETUP_H

#include "types.h"
#include "gfl/heap.h"
#include "save/config.h"
#include "struct_decls.h"

// The battle's surroundings, which GetFieldEffectData returns
struct BtlFieldSituation {
    u8 unk00[0xa];
    u16 zoneId;
    u8 unk0c[6];
    u16 unk12;
    u8 unk14[4];
    u8 unk18;
    u8 unk19;
    u8 unk1a;
    u8 unk1b;
};

struct BtlSetup {
    u32 battleType;
    u32 battleStyle;
    BtlFieldSituation fieldSituation;
    PokeParty *party;
    u8 unk28[0x4c];
    Config *config;
    BagSave *bag;
    u8 unk7c[8];
    GameRecords *records;
    u8 unk88[0x10];
    u8 unk98;
    u8 unk99[0xf];
    u32 unkA8;
    u8 unkAC;
    u8 unkAD;
    u8 unkAE;
    u8 unkAF;
    u32 unkB0;
    u8 unkB4[0x1e];
    u8 unkD2;
    u8 unkD3[8];
    u8 unkDB;
    u8 unkDC[0xb];
    // The party slots each client sends out
    u8 unkE7[4][6];
    u8 unkFF[0x39];
    u16 unk138;
    u16 unk13a;
};

BtlSetup *BtlSetup_Create(HeapID heapId);
u32 BtlSetup_CheckFlag(BtlSetup *setup, u32 flag);
void BtlSetup_Free(BtlSetup *setup);
PokeParty *BtlSetup_GetParty(BtlSetup *setup, u32 index);
void BtlSetup_SetNet1v1Double(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, HeapID heapId);
void BtlSetup_SetNet1v1Single(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, HeapID heapId);
void BtlSetup_SetNetRotation(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, HeapID heapId);
void BtlSetup_SetNetTriple(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, HeapID heapId);
void func_02017cfc(BtlSetup *setup, PokeParty *party, u32 a2);
void func_02017d30(BtlSetup *setup, Regulation *regulation, HeapID heapId);
void func_020186b0(BtlSetup *setup, u32 a1);
void func_0201f63c(Regulation *regulation, PokeParty *party);
void func_0200bb24(HeapID heapId);
void freeVSPlayerBlkClearPtr(void);
u32 GetNumMonsOnField(u32 battleType, u32 count);

#endif // POKEBW2_BATTLE_BTL_SETUP_H
