#ifndef POKEBW2_BATTLE_BTL_HANDLER_H
#define POKEBW2_BATTLE_BTL_HANDLER_H

#include "types.h"
#include "battle/btl_pokeparam.h"
#include "struct_decls.h"

struct BattleHandler {
    BtlServerFlow *serverFlow;
    BtlMainModule *mainModule;
    BtlPokeCon *pokeCon;
    void *display;
    u8 unk10[4];
    u32 unk14;
    u8 unk18[0x490];
    BattleMoveEffectState *moveEffect;
    u8 unk4ac[0x2fd];
    u8 unk7a9[0x15cf];
    u32 actionState;
};

struct BattleHandlerPopupParam {
    u32 unk00 : 8;
    u32 monId : 5;
    u32 unk13 : 19;
};

struct BattleHandlerString {
    u16 message;
    union {
        u16 flags;
        struct {
            u16 enabled : 8;
            u16 count : 7;
            u16 hasSound : 1;
        };
    };
    u32 args[8];
    u32 soundEffect;
};

struct BattleMoveEffectState {
    u8 unk00[4];
    u8 index;
    u8 enabled : 1;
    u8 unk05 : 7;
};

struct BattleHandlerAbilityChangeParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 ability;
    u8 targetIndex;
    u8 force;
    u8 unk08[4];
    BattleHandlerString string;
};

struct BattleHandlerAddFieldEffectParam {
    u32 unk00;
    u32 effect;
    BattleCondition value;
    u8 duration;
    u8 unk0d[3];
    u8 string[0x28];
};

struct BattleHandlerBatonPassParam {
    u32 unk00;
    u8 sourceMonIndex;
    u8 targetMonIndex;
};

struct BattleHandlerChangeFormParam {
    u32 unk00 : 23;
    u32 showAbility : 1;
    u32 unk18 : 8;
    u8 monIndex;
    u8 form;
    u8 unk06[2];
    u8 string[0x28];
};

struct BattleHandlerChangeHPParam {
    u32 unk00;
    u8 count;
    u8 suppress;
    u8 skipReaction;
    u8 monIds[9];
    u32 hpChanges[6];
};

struct BattleHandlerChangeTypeParam {
    u32 unk00;
    u16 type;
    u8 monIndex;
    u8 suppressMessage;
};

struct BattleHandlerChangeWeatherParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 weather;
    u8 duration;
    u8 notifyAirLock;
    u8 unk07;
    BattleHandlerString string;
};

struct BattleHandlerCheckHeldItemParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    u32 reaction;
};

struct BattleHandlerConsumeItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
    u32 skipDisplay;
    u8 string[0x28];
};

struct BattleHandlerCureConditionParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u32 condition;
    u8 monIds[12];
    u8 count;
    u8 useString;
    u8 unk16[2];
    BattleHandlerString string;
};

struct BattleHandlerDamageParam {
    u32 unk00 : 8;
    u32 sourceIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 amount;
    u8 targetIndex;
    u8 checkSemi : 1;
    u8 showViewEffect : 1;
    u8 unkFlags : 6;
    u16 effect;
    u8 effectArg1;
    u8 effectArg2;
    BattleHandlerString string;
};

struct BattleHandlerDecrementPPParam {
    u32 unk00;
    u8 amount;
    u8 monIndex;
    u8 moveIndex;
    u8 unk07 : 1;
    u8 allowFainted : 1;
    u8 unk09 : 6;
    u8 string[0x28];
};

struct BattleHandlerDrainParam {
    u32 unk00;
    u16 amount;
    u8 monIndex;
    u8 sourceIndex;
    BattleHandlerString string;
};

struct BattleHandlerFaintParam {
    u32 unk00;
    u8 monIndex;
    u8 force;
    u8 unk06[2];
    BattleHandlerString string;
};

struct BattleHandlerFlagParam {
    u32 unk00;
    u32 flag;
    u8 monIndex;
};

struct BattleHandlerFlinchParam {
    u32 unk00;
    u8 monIndex;
    u8 flag;
};

struct BattleHandlerForceUseItemParam {
    u32 unk00 : 8;
    u32 monIndex2 : 5;
    u32 unk13 : 19;
    u8 monIndex;
    u8 unk05;
    u16 item;
};

struct BattleHandlerGravityCheckParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
};

struct BattleHandlerHideTurnParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    u32 flag;
    u8 string[0x28];
};

struct BattleHandlerIllusionBreakParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    BattleHandlerString string;
};

struct BattleHandlerInterruptParam {
    u32 unk00;
    union {
        u8 monId;
        u16 moveId;
    };
    u16 unk06;
    u8 string[0x28];
};

struct BattleHandlerMessageParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 string[0x28];
};

struct BattleHandlerMoveEffectParam {
    u8 unk00[4];
    u8 index;
};

struct BattleHandlerQuitBattleParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
};

struct BattleHandlerRecoverStatStageParam {
    u32 unk00;
    u8 monIndex;
};

struct BattleHandlerRemoveFieldEffectParam {
    u32 unk00;
    u32 effect;
};

struct BattleHandlerResetStatStageParam {
    u32 unk00;
    u8 count;
    u8 monIndices[6];
};

struct BattleHandlerReviveParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05;
    u16 amount;
    u8 string[0x28];
};

struct BattleHandlerSetCounterParam {
    u32 unk00;
    u8 monIndex;
    u8 counter;
    u8 value;
};

struct BattleHandlerSetItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 item;
    u8 targetIndex;
    u8 clearConsumed;
    u8 clearOtherConsumed;
    u8 otherIndex;
    u8 unk0a[2];
    BattleHandlerString string;
};

struct BattleHandlerSetWeightParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05;
    u16 weight;
    u8 string[0x28];
};

struct BattleHandlerStatChangeParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u32 stat;
    u32 value;
    s8 change;
    u8 flag;
    u8 unk0e;
    u8 count;
    u8 monIds[8];
    BattleHandlerString string;
};

struct BattleHandlerSwapItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 otherIndex;
    u8 unk05[3];
    BattleHandlerString firstString;
    BattleHandlerString secondString;
    BattleHandlerString thirdString;
};

struct BattleHandlerSwapPokeParam {
    u32 unk00;
    u8 firstMonIndex;
    u8 secondMonIndex;
    u8 unk06[2];
    BattleHandlerString string;
};

struct BattleHandlerSwitchParam {
    u32 unk00;
    u8 firstString[0x28];
    u8 secondString[0x28];
    u8 monIndex;
    u8 flag;
};

struct BattleHandlerTransformParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 targetIndex;
    u8 unk05[3];
    BattleHandlerString string;
};

struct BattleHandlerUseHeldItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
    u32 checkFullHp : 1;
    u32 allowFainted : 1;
    u32 unk22 : 30;
};

void BattleHandler_StrClear(BattleHandlerString *string);
BOOL BattleHandler_StrIsEnabled(BattleHandlerString *string);
void BattleHandler_StrSetup(BattleHandlerString *string, u32 enabled, u16 message);
void BattleHandler_AddArg(BattleHandlerString *string, u32 arg);
void BattleHandler_AddSoundEffect(BattleHandlerString *string, u32 soundEffect);

void *BattleHandler_PushWork(BattleHandler *handler, u32 command, void *data);
void BattleHandler_PushRun(BattleHandler *handler, u32 command, void *data);
void BattleHandler_PopWork(BattleHandler *handler, void *work);
u32 BattleHandler_Result(BattleHandler *handler);
void BattleHandler_Execute(BattleHandler *handler);

BOOL BattleHandler_SetTurnFlag(BattleHandler *handler, BattleHandlerFlagParam *param);
BOOL BattleHandler_ResetTurnFlag(BattleHandler *handler, BattleHandlerFlagParam *param);
BOOL BattleHandler_SetContinueFlag(BattleHandler *handler, BattleHandlerFlagParam *param);
BOOL BattleHandler_ResetContinueFlag(BattleHandler *handler, BattleHandlerFlagParam *param);
BOOL BattleHandler_InterruptAction(BattleHandler *handler, BattleHandlerInterruptParam *param);
u8 BattleHandler_InterruptMove(BattleHandler *handler, BattleHandlerInterruptParam *param);
BOOL BattleHandler_SendLast(BattleHandler *handler, BattleHandlerInterruptParam *param);
BOOL BattleHandler_SetString(BattleHandler *handler, BattleHandlerString *string);
BOOL BattleHandler_AbilityPopupRemove(BattleHandler *handler, BattleHandlerPopupParam *param);
BOOL BattleHandler_HideTurnCancel(BattleHandler *handler, BattleHandlerHideTurnParam *param);
BOOL BattleHandler_RemoveMessageWindow(BattleHandler *handler);
BOOL BattleHandler_ChangeForm(BattleHandler *handler, BattleHandlerChangeFormParam *param);
u8 BattleHandler_Flinch(BattleHandler *handler, BattleHandlerFlinchParam *param);
BOOL BattleHandler_SetWeight(BattleHandler *handler, BattleHandlerSetWeightParam *param);
BOOL BattleHandler_Revive(BattleHandler *handler, BattleHandlerReviveParam *param);
BOOL BattleHandler_SetCounter(BattleHandler *handler, BattleHandlerSetCounterParam *param);
BOOL BattleHandler_CheckHeldItem(BattleHandler *handler, BattleHandlerCheckHeldItemParam *param);
BOOL BattleHandler_UseHeldItem(BattleHandler *handler, BattleHandlerUseHeldItemParam *param);
BOOL BattleHandler_ConsumeItem(BattleHandler *handler, BattleHandlerConsumeItemParam *param);
BOOL BattleHandler_QuitBattle(BattleHandler *handler, BattleHandlerQuitBattleParam *param);
BOOL BattleHandler_Switch(BattleHandler *handler, BattleHandlerSwitchParam *param);
BOOL BattleHandler_AddFieldEffect(BattleHandler *handler, BattleHandlerAddFieldEffectParam *param);
BOOL BattleHandler_RemoveFieldEffect(BattleHandler *handler, BattleHandlerRemoveFieldEffectParam *param);
u8 BattleHandler_RecoverStatStage(BattleHandler *handler, BattleHandlerRecoverStatStageParam *param);
BOOL BattleHandler_ResetStatStage(BattleHandler *handler, BattleHandlerResetStatStageParam *param);
BOOL BattleHandler_Message(BattleHandler *handler, BattleHandlerMessageParam *param);
BOOL BattleHandler_DecrementPP(BattleHandler *handler, BattleHandlerDecrementPPParam *param);
BOOL BattleHandler_ForceUseItem(BattleHandler *handler, BattleHandlerForceUseItemParam *param);
BOOL BattleHandler_BatonPass(BattleHandler *handler, BattleHandlerBatonPassParam *param);
BOOL BattleHandler_IllusionBreak(BattleHandler *handler, BattleHandlerIllusionBreakParam *param);
BOOL BattleHandler_SwapPoke(BattleHandler *handler, BattleHandlerSwapPokeParam *param);
u8 BattleHandler_ChangeWeather(BattleHandler *handler, BattleHandlerChangeWeatherParam *param);
BOOL BattleHandler_GravityCheck(BattleHandler *handler, BattleHandlerGravityCheckParam *param);
BOOL BattleHandler_Transform(BattleHandler *handler, BattleHandlerTransformParam *param);
BOOL BattleHandler_SetItem(BattleHandler *handler, BattleHandlerSetItemParam *param);
BOOL BattleHandler_SwapItem(BattleHandler *handler, BattleHandlerSwapItemParam *param);
BOOL BattleHandler_Drain(BattleHandler *handler, BattleHandlerDrainParam *param);
u8 func_ov167_021ac988(void *state, u8 monIndex);
BOOL BattleHandler_Damage(BattleHandler *handler, BattleHandlerDamageParam *param);
BOOL BattleHandler_ChangeHP(BattleHandler *handler, BattleHandlerChangeHPParam *param);
BOOL BattleHandler_Faint(BattleHandler *handler, BattleHandlerFaintParam *param);
u8 func_ov167_021aca54(void *state, u8 monIndex);
u8 func_ov167_021acad4(void *state, u8 monIndex);
u8 func_ov167_021ad15c(void *state, u8 monIndex);
BOOL BattleHandler_ChangeType(BattleHandler *handler, BattleHandlerChangeTypeParam *param);
BOOL BattleHandler_AbilityChange(BattleHandler *handler, BattleHandlerAbilityChangeParam *param);
u8 func_ov167_021ad1f4(void *state, u8 monIndex);
BOOL func_ov167_021ad204(u16 species);
u32 HandlerGetAlivePartyCount(BattleHandler *handler, u16 code, u8 *monIds);
u32 func_ov167_021ab840(void *flow, u32 monId);
u8 *func_ov167_021abc60(void *flow, u32 value);
u8 func_ov167_021add78(void *state, u8 monIndex);
u8 func_ov167_021ae0fc(void *state, u8 monIndex);

BOOL BattleHandler_SetMoveEffectIndex(BattleHandler *handler, BattleHandlerMoveEffectParam *param);
BOOL BattleHandler_SetMoveEffectEnable(BattleHandler *handler);

#endif // POKEBW2_BATTLE_BTL_HANDLER_H
