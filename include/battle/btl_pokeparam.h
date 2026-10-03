#ifndef POKEBW2_BATTLE_BTL_POKEPARAM_H
#define POKEBW2_BATTLE_BTL_POKEPARAM_H

#include "types.h"
#include "constants/battle.h"
#include "nitro/fx.h"
#include "struct_decls.h"

struct BattleCondition {
    union {
        u32 raw;
        struct {
            u32 type : 3;
            u32 turns : 6;
            u32 unk09 : 23;
        } common;
        struct {
            u32 type : 3;
            u32 turns : 6;
            u32 param : 16;
            u32 unk25 : 7;
        } timed;
        struct {
            u32 unk00 : 9;
            u32 monId : 6;
            u32 unk15 : 17;
        } mon;
        struct {
            u32 unk00 : 25;
            u32 flag : 1;
            u32 unk26 : 6;
        } one;
        struct {
            u32 unk00 : 31;
            u32 flag : 1;
        } four;
    };
};

// The condition word returned by GetConditionContinuationParam.
typedef BattleCondition BattleConditionCont;

// Two types, the first in bits 8 to 15 and the second in bits 0 to 7
typedef s32 PokeTypePair;

PokeTypePair PokeTypePair_Make(u32 type1, u32 type2);
BOOL PokeTypePair_IsMonotype(PokeTypePair pair);

void IncrementTurn(BattleCondition *condition, u32 amount);
void SetTurns(BattleCondition *condition, u32 turns);
BattleCondition SetConditionTurns(u32 turns);
BattleCondition AddTurnCondition(u32 turns, u16 param);
BattleCondition MakeConditionPermanent(void);
BattleCondition MakeConditionParamPermanent(u16 param);
u16 Condition_GetParam(BattleCondition condition);
void SetConditionFlag(BattleCondition *condition, u32 flag);

BOOL CanPokemonBattle(BattleMon *mon);
PartyPkm *GetSrcData(const void *param);
BOOL CheckCondition(BattleMon *mon, u32 condition);
BOOL Condition_IsBadlyPoisoned(BattleConditionCont cont);
u8 Condition_GetMonID(BattleCondition condition);
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
BOOL TransformCheck(BattleMon *mon);
void ChangeForm(BattleMon *mon, u8 form);
void func_ov167_021bb7c0(BattleMon *mon, u32 flag);
void func_ov167_021bb7e4(BattleMon *mon, u32 flag);
void func_ov167_021bb808(BattleMon *mon, u32 flag);
void func_ov167_021bbc40(BattleMon *mon, u32 flag);
BOOL IsSubstituteActive(BattleMon *mon);
u16 MoveGetID(BattleMon *mon, u8 index);
u8 PokeTypePair_GetType1(PokeTypePair pair);
u8 PokeTypePair_GetType2(PokeTypePair pair);
u8 CountUsedMoves(BattleMon *mon);
u8 GetMovePPUsed(BattleMon *mon, u8 index);
u16 func_ov167_021bb3a4(BattleMon *mon);
u16 GetConsumedItem(BattleMon *mon);

#endif // POKEBW2_BATTLE_BTL_POKEPARAM_H
