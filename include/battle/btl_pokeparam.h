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
PokeTypePair func_ov167_021ce530(u32 type);
BOOL PokeTypePair_IsMonotype(PokeTypePair pair);

void IncrementTurn(BattleCondition *condition, u32 amount);
void SetTurns(BattleCondition *condition, u32 turns);
BattleCondition SetConditionTurns(u32 turns);
BattleCondition AddTurnCondition(u32 turns, u16 param);
BattleCondition func_ov167_021ce1dc(u32 turns);
BattleCondition MakeConditionPermanent(void);
BattleCondition MakeConditionParamPermanent(u16 param);
u16 Condition_GetParam(BattleCondition condition);
void SetConditionFlag(BattleCondition *condition, u32 flag);
u32 func_ov167_021ce464(BattleCondition condition);

BOOL CanPokemonBattle(BattleMon *mon);
PartyPkm *GetSrcData(const void *param);
BOOL CheckCondition(BattleMon *mon, u32 condition);
void CopyBatonPassParams(BattleMon *target, BattleMon *source);
BOOL Condition_IsBadlyPoisoned(BattleConditionCont cont);
u8 Condition_GetMonID(BattleCondition condition);
u32 GetAdditionalConditionFlag(BattleMon *mon, u32 flag);
u32 GetTurnFlag(BattleMon *mon, u32 flag);
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
u8 func_ov167_021bbfb0(BattleMon *mon);
BOOL IsFainted(BattleMon *mon);
BOOL TransformCheck(BattleMon *mon);
void ChangeForm(BattleMon *mon, u8 form);
void ChangePokeType(BattleMon *mon, u16 type);
void ChangeAbility(BattleMon *mon, u16 ability);
BOOL func_ov167_021ad6e8(u16 ability);
void SetWeight(BattleMon *mon, u16 weight);
u16 GetBattleMonWeight(BattleMon *mon);
void HPAdd(BattleMon *mon, u16 amount);
void HPZero(BattleMon *mon);
u32 DivideMaxHp(BattleMon *mon, u32 divisor);
u32 DivideMaxHPZeroCheck(BattleMon *mon, u32 divisor);
BOOL IsMonFullHP(BattleMon *mon);
BOOL StatStageRecover(BattleMon *mon);
void StatStageReset(BattleMon *mon);
void func_ov167_021bb7c0(BattleMon *mon, u32 flag);
void func_ov167_021bb7e4(BattleMon *mon, u32 flag);
void func_ov167_021bb808(BattleMon *mon, u32 flag);
void func_ov167_021bbc40(BattleMon *mon, u32 flag);
BOOL IsSubstituteActive(BattleMon *mon);
void ResetSpActPriority(BattleMon *mon);
void ComboMove_ClearParam(BattleMon *mon);
BOOL IsIllusionEnabled(BattleMon *mon);
void IllusionBreak(BattleMon *mon);
BOOL IsSemiInvulnMove(BattleMon *mon);
BOOL TransformSet(BattleMon *mon, BattleMon *target);
void RemoveForceAll(BattleMon *mon);
void AbilityEvent_RemoveItem(BattleMon *mon);
void AbilityEvent_AddItem(BattleMon *mon);
void ClearConsumedItem(BattleMon *mon);
void ConsumeItem(BattleMon *mon, u16 item);
u16 MoveGetID(BattleMon *mon, u8 index);
u8 PokeTypePair_GetType1(PokeTypePair pair);
u8 PokeTypePair_GetType2(PokeTypePair pair);
void func_ov167_021ce54c(PokeTypePair pair, u8 *type1, u8 *type2);
BOOL func_ov167_021ce564(PokeTypePair pair, u32 type);
BOOL func_ov167_021ce588(PokeTypePair first, PokeTypePair second);
u8 CountUsedMoves(BattleMon *mon);
u8 GetMovePPUsed(BattleMon *mon, u8 index);
u16 func_ov167_021bb3a4(BattleMon *mon);
u16 GetConsumedItem(BattleMon *mon);
u16 GetConsecutiveMoveCount(BattleMon *mon);
u16 GetPreviousMoveUsed(BattleMon *mon);
u8 GetPrevTargetPos(BattleMon *mon);
void MoveWork_UpdateNumber(BattleMoveWork *work, u16 move, u8 maxPP, BOOL updateCurrent);
void MoveCore_UpdateNumber(BattleMoveCore *core, u16 move, u8 maxPP);
void func_ov167_021ba9cc(void *moveWork);
void ClearUsedMoveFlag(BattleMon *mon);
void ClearMoveStatusWork(BattleMon *mon, u32 flag);
void ClearCounter(BattleMon *mon);
void setupBySrcData(BattleMon *mon, void *src, u32 value, u32 flag);
void MoveWork_ClearSurface(BattleMon *mon);
void ClearFormChange(BattleMon *mon);
void ResetStatStages(u8 *stages);
s32 func_ov167_021bb550(BattleMon *mon, u32 stat);
BOOL Move_IsPPFull(BattleMon *mon, u8 index, BOOL current);
u16 Move_IncrementPP(BattleMon *mon, u8 index, u8 amount);
u16 Move_IncrementPP_Org(BattleMon *mon, u8 index, u8 amount);
void Move_UpdateID(BattleMon *mon, u8 index, u16 move, u8 maxPP, BOOL updateCurrent);
BOOL MoveIsUsable(BattleMon *mon, u16 move);
u32 func_ov167_021bb07c(BattleMon *mon, u32 stat);
void SetBaseStatus(BattleMon *mon, u32 stat, u16 value);
u32 RawBattleMonStat(BattleMon *mon, u32 stat);
u32 CritAtkDefLevel(BattleMon *mon, u32 stat);
void splitTypeCore(BattleMon *mon, u8 *type1, u8 *type2);
BOOL DoesMonHaveType(BattleMon *mon, u32 type);
void SetIllusionDisguise(BattleMon *mon, void *disguise);
s8 *func_ov167_021bb4b4(BattleMon *mon, u32 stat, s8 *min, s8 *max);
BOOL IsStatChangeValid(BattleMon *mon, u32 stat, s32 change);
BOOL AreStatsLowered(BattleMon *mon);
u32 func_ov167_021bb408(BattleMon *mon);
BattleCondition ZeroConditionTurns(void);
BOOL IsBasicStatus(u32 condition);
void SetMoveCondition(BattleMon *mon, u32 condition, BattleCondition value);
void CureCondition(BattleMon *mon);
void CureDependentCondition(BattleMon *mon, u32 condition);
void CureMoveCondition(BattleMon *mon, u32 condition);

#endif // POKEBW2_BATTLE_BTL_POKEPARAM_H
