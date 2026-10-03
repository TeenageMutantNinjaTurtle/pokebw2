#ifndef POKEBW2_BATTLE_BTL_ABILITY_H
#define POKEBW2_BATTLE_BTL_ABILITY_H

#include "struct_decls.h"
#include "types.h"

u32 numHandlersWithHandlerPri(u32 priority, u32 count);
u32 devideNumHandersAndPri(u32 *packed);
u16 calcAbilHandlerSubPriority(BattleMon *mon);
BOOL func_ov167_021abdf8(BattleMon *mon, u32 value);
BOOL AbilityEvent_RollEffectChance(BattleMon *mon, u32 chance);
void AbilityEvent_ItemRotationSleep(BattleMon *mon);
void AbilityEvent_ItemRotationWake(BattleMon *mon);

#endif // POKEBW2_BATTLE_BTL_ABILITY_H
