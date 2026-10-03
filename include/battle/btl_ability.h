#ifndef POKEBW2_BATTLE_BTL_ABILITY_H
#define POKEBW2_BATTLE_BTL_ABILITY_H

#include "struct_decls.h"
#include "types.h"
#include "battle/btl_event.h"

u32 numHandlersWithHandlerPri(u32 priority, u32 count);
u32 devideNumHandersAndPri(u32 *packed);
u16 calcAbilHandlerSubPriority(BattleMon *mon);
BOOL func_ov167_021abdf8(BattleMon *mon, u32 value);
BOOL AbilityEvent_RollEffectChance(BattleMon *mon, u32 chance);
void AbilityEvent_ItemRotationSleep(BattleMon *mon);
void AbilityEvent_ItemRotationWake(BattleMon *mon);
extern const BattleEventHandlerEntry data_ov167_021d7794[];
extern const BattleEventHandlerEntry data_ov167_021d763c[];
extern const BattleEventHandlerEntry data_ov167_021d784c[];
const BattleEventHandlerEntry *EventAddInnerFocus(u32 *priority);
void HandlerInnerFocus(void *context, void *item, u32 monId);
const BattleEventHandlerEntry *EventAddThickFat(u32 *priority);
void HandlerThickFat(void *context, void *item, u32 monId);
const BattleEventHandlerEntry *EventAddHugePower(u32 *priority);
void HandlerHugePower(void *context, void *item, u32 monId);

#endif // POKEBW2_BATTLE_BTL_ABILITY_H
