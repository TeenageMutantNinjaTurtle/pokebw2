#ifndef POKEBW2_BATTLE_BTL_CLIENT_H
#define POKEBW2_BATTLE_BTL_CLIENT_H

// Overlay 167's battle clients, each the player or an opponent

#include "types.h"
#include "battle/btl_calc.h"
#include "gfl/heap.h"
#include "nitro/math.h"
#include "struct_decls.h"

void func_ov167_021b18c4(BtlClient *client);
void *func_ov167_021b18d4(BtlClient *client, u32 *size);
void func_ov167_021b190c(BtlClient *client, BtlvCore *viewCore);
void func_ov167_021b1934(BtlClient *client, u32 arg1);
void func_ov167_021b1960(BtlClient *client);
void func_ov167_021b19a4(BtlClient *client);
void func_ov167_021b19b0(BtlClient *client, u32 value);
BOOL func_ov167_021b1d64(BtlClient *client);
BOOL func_ov167_021b1d90(BtlClient *client);

void func_ov167_021b1670(void);
BtlClient *func_ov167_021b1674(BtlMainModule *mainModule, BtlPokeCon *pokeCon, u8 commMode, void *netHandle, u16 clientId,
                               u8 numCoverPos, u8 isAI, u32 arg7, u8 recPlay, MATHRandContext32 *rand, HeapID heapId);
void func_ov167_021b1890(BtlClient *client);
void func_ov167_021b18e8(BtlClient *client, void *data);
void func_ov167_021b1910(BtlClient *client, BtlServer *server);
BtlAdapter *func_ov167_021b1928(BtlClient *client);
BOOL func_ov167_021b192c(BtlClient *client);
void func_ov167_021b1d58(BtlClient *client, BtlClientIDList *list);

#endif // POKEBW2_BATTLE_BTL_CLIENT_H
