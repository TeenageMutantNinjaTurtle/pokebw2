#ifndef POKEBW2_BATTLE_BTL_ACTION_H
#define POKEBW2_BATTLE_BTL_ACTION_H

#include "types.h"
#include "struct_decls.h"

struct BtlActionState {
    union {
        u32 raw;
        struct {
            u32 useItemNo : 10;
            u32 unk10 : 18;
            u32 prevResult : 1;
            u32 result : 1;
            u32 used : 1;
            u32 unk31 : 1;
        };
    };
};

union BattleAction {
    u32 raw;
    struct {
        u32 action : 4;
        u32 target : 3;
        u32 move : 16;
        u32 unk23 : 3;
        u32 unk26 : 1;
        u32 unk27 : 5;
    } bits;
    // An item use
    struct {
        u32 action : 4;
        u32 target : 3;
        u32 item : 16;
        u32 param : 8;
        u32 unk31 : 1;
    } item;
    // A switch, to the party slot
    struct {
        u32 action : 4;
        u32 unk4 : 3;
        u32 slot : 3;
        u32 unk10 : 1;
        u32 unk11 : 21;
    } change;
};

u32 PushState(BtlActionState *state, u32 command);
void PopState(BtlActionState *state, u32 value, u32 command);
u16 GetUseItemNo(BtlActionState *state);
BOOL IsUsed(BtlActionState *state);
void SetResult(BtlActionState *state, BOOL result);
BOOL GetPrevResult(BtlActionState *state);
BOOL func_ov167_021b0918(BtlActionState *state);
void *func_ov167_021b0920(BtlActionState *state, u32 command, u32 monId);
void PopWork(BtlActionState *state, void *work);

void BattleAction_SetFightParam(BattleAction *action, u16 move, u8 target);
void BattleAction_ChangeFightTargetPos(BattleAction *action, u8 target);
void func_ov167_021bdb40(BattleAction *action);
BOOL func_ov167_021bdb54(const BattleAction *action);
u16 func_ov167_021bdb68(const BattleAction *action);
void func_ov167_021bdb80(BattleAction *action, u16 item, u8 target, u8 param);
void func_ov167_021bdbbc(BattleAction *action, u8 pos, u8 slot);
void func_ov167_021bdbec(BattleAction *action);
BOOL func_ov167_021bdc08(const BattleAction *action);
void func_ov167_021bdc24(BattleAction *action, u8 target);
void func_ov167_021bdc3c(BattleAction *action);
void func_ov167_021bdc4c(BattleAction *action);
void BattleAction_SetNull(BattleAction *action);
void BattleAction_SetSkip(BattleAction *action);
u32 BattleAction_GetAction(const BattleAction *action);
void func_ov167_021bdc84(BattleAction *action);
void func_ov167_021bdc98(BattleAction *action);

#endif // POKEBW2_BATTLE_BTL_ACTION_H
