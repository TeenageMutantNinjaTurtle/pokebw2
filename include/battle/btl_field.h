#ifndef POKEBW2_BATTLE_BTL_FIELD_H
#define POKEBW2_BATTLE_BTL_FIELD_H

#include "types.h"
#include "struct_decls.h"

// The weather and field effects of the battle in progress
u32 GetFieldWeather(void);
u32 IsFieldEffectActive(u32 fieldEffect);
BOOL FieldStatusRemoveEffect(u32 effect);
u32 GetWeather(BtlServerFlow *serverFlow);
u32 func_ov167_021d59c0(void);
void FieldStatusSetWeather(u8 weather, u8 duration);
BOOL FieldStatusAddEffect(u32 effect, BattleCondition value);
void FieldStatusAddDependPoke(u32 effect, u8 monId);
BOOL func_ov167_021d5a48(BtlPokeCon *pokeCon, BattleMon *mon, u16 move);

#endif // POKEBW2_BATTLE_BTL_FIELD_H
