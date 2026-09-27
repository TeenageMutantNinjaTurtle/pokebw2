#ifndef POKEBW2_BATTLE_BTL_SERVER_FLOW_H
#define POKEBW2_BATTLE_BTL_SERVER_FLOW_H

#include "types.h"
#include "constants/battle.h"
#include "struct_decls.h"

// The damage of a move, with the type effectiveness if withEffectiveness is set. damageRoll is USE_MIN_DAMAGE for the
// lowest random roll, or ROLL_FOR_DAMAGE for a random one
u32 AICalcDamage(BtlServerFlow *serverFlow, u8 attackerId, u8 defenderId, u16 move, BOOL withEffectiveness,
                 u32 damageRoll);
u16 GetTurnCounter(BtlServerFlow *serverFlow);
u32 CalcMoveEffectiveness(BtlServerFlow *serverFlow, u8 attackerId, u8 defenderId, u16 move);
u16 func_ov167_021abd08(BtlServerFlow *serverFlow, BattleMon *mon, BOOL a2);
u32 func_ov167_021abd10(BtlServerFlow *serverFlow, BattleMon *mon, BOOL a2);
u32 func_ov167_021abe10(BtlServerFlow *serverFlow, u8 pos, u32 sideEffect);
BOOL func_ov167_021abe34(BtlServerFlow *serverFlow, u8 pos, u32 a2);

#endif // POKEBW2_BATTLE_BTL_SERVER_FLOW_H
