#ifndef POKEBW2_BATTLE_BTL_CLIENT_H
#define POKEBW2_BATTLE_BTL_CLIENT_H

// Overlay 167's battle clients, each the player or an opponent

#include "types.h"
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

#endif // POKEBW2_BATTLE_BTL_CLIENT_H
