#ifndef POKEBW2_BATTLE_BTL_SERVER_FLOW_SUB_H
#define POKEBW2_BATTLE_BTL_SERVER_FLOW_SUB_H

// Overlay 167's btl_server_flow_sub.c, a guessed name: the helpers btl_server_flow.c calls for a move's targets,
// experience and effort values, the items trainers use from the bag, the battle's result and the sides' HP. Its line
// numbers restart after btl_server_flow.c's. Function names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0) where it has them

#include "types.h"
#include "battle/btl_handler.h"
#include "struct_decls.h"

u8 func_ov167_021ae32c(BtlServerFlow *flow, BattleMon *mon, u8 target, BtlFlowMoveParam *param, void *targets);
void AddExpAndEVs(BtlServerFlow *flow, BattleParty *party, BattleMon *defeated, BtlFlowExpEntry *entries);
u8 func_ov167_021af2ac(BtlServerFlow *flow, BattleMon *mon, u16 item, u8 param, u8 slot);
s32 func_ov167_021b0318(BtlMainModule *mainModule, BtlPokeCon *pokeCon);
u32 func_ov167_021b05b4(BtlServerFlow *flow);
void func_ov167_021b0814(u32 *table);
void func_ov167_021b0824(u32 *table, u8 monId, u32 value);
u32 func_ov167_021b082c(u32 *table, u8 monId);
u32 func_ov167_021b0834(u32 *table, u8 monId);

#endif // POKEBW2_BATTLE_BTL_SERVER_FLOW_SUB_H
