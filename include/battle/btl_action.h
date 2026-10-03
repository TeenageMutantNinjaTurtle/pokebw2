#ifndef POKEBW2_BATTLE_BTL_ACTION_H
#define POKEBW2_BATTLE_BTL_ACTION_H

#include "types.h"
#include "struct_decls.h"

union BattleAction {
    u32 raw;
    struct {
        u32 action : 4;
        u32 target : 3;
        u32 move : 16;
        u32 unused : 9;
    } bits;
};

u32 PushState(BtlActionState *state, u32 command);
void PopState(BtlActionState *state, u32 value, u32 command);
u16 GetUseItemNo(BtlActionState *state);
BOOL IsUsed(BtlActionState *state);
void SetResult(BtlActionState *state, BOOL result);
BOOL GetPrevResult(BtlActionState *state);
BOOL func_ov167_021b0918(BtlActionState *state);
void *func_ov167_021b0920(BtlActionState *state, u32 command, void *data);
void PopWork(BtlActionState *state, void *work);

u32 BattleAction_GetAction(const void *action);
void BattleAction_SetFightParam(BattleAction *action, u16 move, u8 target);
void BattleAction_ChangeFightTargetPos(BattleAction *action, u8 target);
void BattleAction_SetNull(BattleAction *action);
void *func_ov167_021d4b50(void *actionManager, void *out);

#endif // POKEBW2_BATTLE_BTL_ACTION_H
