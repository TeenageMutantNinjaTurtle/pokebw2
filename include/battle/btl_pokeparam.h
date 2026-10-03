#ifndef POKEBW2_BATTLE_BTL_POKEPARAM_H
#define POKEBW2_BATTLE_BTL_POKEPARAM_H

#include "types.h"
#include "constants/battle.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// How long a condition lasts, passed by value
typedef struct {
    u32 raw;
} BattleConditionCont;

// Two types, the first in bits 8 to 15 and the second in bits 0 to 7
typedef s32 PokeTypePair;

BOOL CanPokemonBattle(BattleMon *mon);
PartyPkm *GetSrcData(const void *param);
BOOL CheckCondition(BattleMon *mon, u32 condition);
BOOL Condition_IsBadlyPoisoned(BattleConditionCont cont);
u32 GetAdditionalConditionFlag(BattleMon *mon, u32 flag);
u32 GetBattleMonHeldItem(BattleMon *mon);
u8 GetBattleMonMoveCount(BattleMon *mon);
u16 GetBattleMonSpecies(BattleMon *mon);
u32 GetBattleMonStat(BattleMon *mon, u32 value);
u32 GetBattleMonStatus(BattleMon *mon);
BattleConditionCont GetConditionContinuationParam(BattleMon *mon, u32 condition);
u8 GetConditionCount(BattleMon *mon, u32 condition);
u16 GetConsecutiveMoveCount(BattleMon *mon);
fx32 GetHPRatio(BattleMon *mon);
u8 GetMonID(BattleMon *mon);
u8 GetMovePP(BattleMon *mon, u8 index);
PokeTypePair GetPokeType(BattleMon *mon);
u16 GetPreviousMoveID(BattleMon *mon);
BOOL IsFainted(BattleMon *mon);
BOOL IsSubstituteActive(BattleMon *mon);
u16 MoveGetID(BattleMon *mon, u8 index);
u8 PokeTypePair_GetType1(PokeTypePair pair);
u8 PokeTypePair_GetType2(PokeTypePair pair);
u8 CountUsedMoves(BattleMon *mon);
u8 GetMovePPUsed(BattleMon *mon, u8 index);
u16 func_ov167_021bb3a4(BattleMon *mon);
u16 GetConsumedItem(BattleMon *mon);

#endif // POKEBW2_BATTLE_BTL_POKEPARAM_H
