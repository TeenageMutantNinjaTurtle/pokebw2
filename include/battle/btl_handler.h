#ifndef POKEBW2_BATTLE_BTL_HANDLER_H
#define POKEBW2_BATTLE_BTL_HANDLER_H

#include "types.h"
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
u32 HandlerGetAlivePartyCount(BattleHandler *handler, u16 code, u8 *monIds);
u8 func_ov167_021add78(void *state, u8 monIndex);
u8 func_ov167_021ae0fc(void *state, u8 monIndex);

BOOL BattleHandler_SetMoveEffectIndex(BattleHandler *handler, BattleHandlerMoveEffectParam *param);
BOOL BattleHandler_SetMoveEffectEnable(BattleHandler *handler);

#endif // POKEBW2_BATTLE_BTL_HANDLER_H
