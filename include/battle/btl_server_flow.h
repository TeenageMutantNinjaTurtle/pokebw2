#ifndef POKEBW2_BATTLE_BTL_SERVER_FLOW_H
#define POKEBW2_BATTLE_BTL_SERVER_FLOW_H

#include "types.h"
#include "struct_decls.h"

// Type effectiveness, which multiplies the power by 0, 1/4, 1/2, 1, 2 or 4
#define TYPE_EFFECTIVENESS_IMMUNE 0
#define TYPE_EFFECTIVENESS_QUARTER 1
#define TYPE_EFFECTIVENESS_HALF 2
#define TYPE_EFFECTIVENESS_NORMAL 3
#define TYPE_EFFECTIVENESS_DOUBLE 4
#define TYPE_EFFECTIVENESS_QUADRUPLE 5

u32 AICalcDamage(BtlServerFlow *serverFlow, u8 attackerId, u8 defenderId, u16 move, BOOL a4, u32 a5);
u16 GetTurnCounter(BtlServerFlow *serverFlow);
u32 CalcMoveEffectiveness(BtlServerFlow *serverFlow, u8 attackerId, u8 defenderId, u16 move);
u16 func_ov167_021abd08(BtlServerFlow *serverFlow, BattleMon *mon, BOOL a2);
u32 func_ov167_021abd10(BtlServerFlow *serverFlow, BattleMon *mon, BOOL a2);
u32 func_ov167_021abe10(BtlServerFlow *serverFlow, u8 pos, u32 sideEffect);
BOOL func_ov167_021abe34(BtlServerFlow *serverFlow, u8 pos, u32 a2);

#endif // POKEBW2_BATTLE_BTL_SERVER_FLOW_H
