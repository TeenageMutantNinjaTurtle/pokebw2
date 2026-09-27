#ifndef POKEBW2_BATTLE_BTL_SETUP_H
#define POKEBW2_BATTLE_BTL_SETUP_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct BtlSetup {
    u8 unk0[0x84];
    void *records;
};

BtlSetup *BtlSetup_Create(HeapID heapId);
void BtlSetup_Free(BtlSetup *setup);
void BtlSetup_SetNet1v1Double(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, HeapID heapId);
void BtlSetup_SetNet1v1Single(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, HeapID heapId);
void BtlSetup_SetNetRotation(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, HeapID heapId);
void BtlSetup_SetNetTriple(BtlSetup *setup, GameData *gameData, NetHandle *handle, u32 a3, HeapID heapId);
void *func_0200b50c(HeapID heapId);
void func_0200b608(void *a0, u32 a1, BOOL a2);
void func_02017cfc(BtlSetup *setup, PokeParty *party, u32 a2);
void func_02017d30(BtlSetup *setup, void *a1, HeapID heapId);
void func_020186b0(BtlSetup *setup, u32 a1);
void func_0201f63c(void *a0, PokeParty *party);

#endif // POKEBW2_BATTLE_BTL_SETUP_H
