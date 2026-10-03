#ifndef POKEBW2_BATTLE_BTL_SETUP_H
#define POKEBW2_BATTLE_BTL_SETUP_H

#include "types.h"
#include "gfl/heap.h"
#include "save/config.h"
#include "struct_decls.h"

struct BtlSetup {
    u32 battleType;
    u32 battleStyle;
    u8 unk8[0x1b];
    u8 unk23;
    PokeParty *party;
    u8 unk28[0x4c];
    Config *config;
    BagSave *bag;
    u8 unk7c[8];
    GameRecords *records;
    u8 unk88[0x20];
    u32 unkA8;
    u8 unkAC;
    u8 unkAD;
    u8 unkAE[0x24];
    u8 unkD2;
    u8 unkD3[8];
    u8 unkDB;
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
void freeVSPlayerBlkClearPtr(BtlSetup *setup);
u32 GetNumMonsOnField(u32 battleType, u32 count);

#endif // POKEBW2_BATTLE_BTL_SETUP_H
