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
extern const BattleEventHandlerEntry data_ov167_021d77c4[];
extern const BattleEventHandlerEntry data_ov167_021d765c[];
extern const BattleEventHandlerEntry data_ov167_021d77cc[];
extern const BattleEventHandlerEntry data_ov167_021d76ec[];
extern const BattleEventHandlerEntry data_ov167_021d7a44[];
void HandlerSwiftSwim(void *context, void *flow, u32 monId);
const BattleEventHandlerEntry *EventAddSwiftSwim(u32 *priority);
void HandlerChlorophyll(void *context, void *flow, u32 monId);
const BattleEventHandlerEntry *EventAddChlorophyll(u32 *priority);
void HandlerQuickFeet(void *context, void *flow, u32 monId);
const BattleEventHandlerEntry *EventAddQuickFeet(u32 *priority);
void HandlerTangledFeet(void *context, void *flow, u32 monId);
const BattleEventHandlerEntry *EventAddTangledFeet(u32 *priority);
void HandlerHustleAccuracy(void *context, void *item, u32 monId);
void HandlerHustlePower(void *context, void *item, u32 monId);
const BattleEventHandlerEntry *EventAddHustle(u32 *priority);
extern const BattleEventHandlerEntry data_ov167_021d7624[];
extern const BattleEventHandlerEntry data_ov167_021d76d4[];
void HandlerStall(void *context, void *item, u32 monId);
const BattleEventHandlerEntry *EventAddStall(u32 *priority);
void HandlerCompoundEyes(void *context, void *item, u32 monId);
const BattleEventHandlerEntry *EventAddCompoundEyes(u32 *priority);
extern const BattleEventHandlerEntry data_ov167_021d7a64[];
extern const BattleEventHandlerEntry data_ov167_021d7a74[];
void HandlerSandVeil(void *context, void *flow, u32 monId);
void HandlerSandVeilWeather(void *context, void *flow, u32 monId, u32 value);
const BattleEventHandlerEntry *EventAddSandVeil(u32 *priority);
void HandlerSnowCloak(void *context, void *flow, u32 monId);
void HandlerSnowCloakWeather(void *context, void *flow, u32 monId, u32 value);
const BattleEventHandlerEntry *EventAddSnowCloak(u32 *priority);
void CommonWeatherGuard(void *context, void *flow, u32 monId, u32 value, u8 weather);
extern const BattleEventHandlerEntry data_ov167_021d77bc[];
extern const BattleEventHandlerEntry data_ov167_021d7844[];
void HandlerTintedLens(void *context, void *item, u32 monId);
const BattleEventHandlerEntry *EventAddTintedLens(u32 *priority);
void HandlerSolidRock(void *context, void *item, u32 monId);
const BattleEventHandlerEntry *EventAddSolidRock(u32 *priority);
extern const BattleEventHandlerEntry data_ov167_021d783c[];
void HandlerSniper(void *context, void *item, u32 monId);
const BattleEventHandlerEntry *EventAddSniper(u32 *priority);

#endif // POKEBW2_BATTLE_BTL_ABILITY_H
