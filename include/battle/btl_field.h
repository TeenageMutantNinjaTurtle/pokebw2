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
void func_ov167_021d5a38(u8 monId);
u8 func_ov167_021d59e4(void);
void FieldStatusSetWeather(u8 weather, u8 duration);
BOOL FieldStatusAddEffect(u32 effect, BattleCondition value);
void FieldStatusAddDependPoke(u32 effect, u8 monId);
BOOL func_ov167_021d5a48(BtlPokeCon *pokeCon, BattleMon *mon, u16 move);
void func_ov167_021d5a60(void (*callback)(u32 effect, BtlServerFlow *flow), BtlServerFlow *flow);

// The field status the main module keeps, which the clients pass along
BOOL CheckFieldEffect(u32 fieldStatus, u32 effect);
BOOL CheckImprison(u32 fieldStatus, BtlPokeCon *pokeCon, BattleMon *mon, u16 move);
void FieldStatusaddEffectCore(u32 fieldStatus, u32 effect, BattleCondition value, u32 arg3);
u8 func_ov167_021d5ad4(u32 fieldStatus);
void func_ov167_021d5aec(u32 fieldStatus, u8 weather, u16 turns);
void func_ov167_021d5af4(u32 fieldStatus);
void func_ov167_021d5bc0(u32 fieldStatus, u32 effect);
void func_ov167_021d5c04(u32 fieldStatus, u32 effect, u8 monId);
void func_ov167_021d5c60(u32 fieldStatus, u8 monId);
void func_ov167_021d5da4(u32 fieldStatus, u32 arg1, u32 arg2);

#endif // POKEBW2_BATTLE_BTL_FIELD_H
