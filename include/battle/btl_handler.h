#ifndef POKEBW2_BATTLE_BTL_HANDLER_H
#define POKEBW2_BATTLE_BTL_HANDLER_H

#include "types.h"
#include "struct_decls.h"

struct BattleHandler {
    u8 unk00[8];
    BtlPokeCon *pokeCon;
    u8 unk0c[0x49c];
    BattleMoveEffectState *moveEffect;
    u8 unk4ac[0x18cc];
    u32 actionState;
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
void scPut_SetContFlag(BattleHandler *handler, BattleMon *mon, u32 flag);
void scPut_ResetContFlag(BattleHandler *handler, BattleMon *mon, u32 flag);

BOOL BattleHandler_InterruptAction(BattleHandler *handler, BattleHandlerInterruptParam *param);
u8 BattleHandler_InterruptMove(BattleHandler *handler, BattleHandlerInterruptParam *param);
BOOL BattleHandler_SendLast(BattleHandler *handler, BattleHandlerInterruptParam *param);
void BattleHandler_SetString(BattleHandler *handler, BattleHandlerString *string);

BOOL BattleHandler_SetMoveEffectIndex(BattleHandler *handler, BattleHandlerMoveEffectParam *param);
BOOL BattleHandler_SetMoveEffectEnable(BattleHandler *handler);

#endif // POKEBW2_BATTLE_BTL_HANDLER_H
