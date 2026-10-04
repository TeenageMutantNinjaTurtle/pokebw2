#include "types.h"
#include "battle/btl_action.h"

// Function names from swan.
void BattleAction_SetFightParam(BattleAction *action, u16 move, u8 target) {
    action->raw = 0;
    action->bits.action = 1;
    action->bits.target = target;
    action->bits.move = move;
}

void BattleAction_ChangeFightTargetPos(BattleAction *action, u8 target) {
    if (action->bits.action == 1 && target != 6) {
        action->bits.target = target;
    }
}

void func_ov167_021bdb40(BattleAction *action) {
    if (action->bits.action == 1) {
        action->bits.unk26 = 1;
    }
}

BOOL func_ov167_021bdb54(const BattleAction *action) {
    if (action->bits.action == 1) {
        return action->bits.unk26;
    }
    return FALSE;
}

u16 func_ov167_021bdb68(const BattleAction *action) {
    if (action->bits.action == 1) {
        return action->bits.move;
    }
    return 0;
}

void func_ov167_021bdb80(BattleAction *action, u16 item, u8 target, u8 param) {
    action->raw = 0;
    action->item.action = 2;
    action->item.item = item;
    action->item.target = target;
    action->item.param = param;
}

void func_ov167_021bdbbc(BattleAction *action, u8 pos, u8 slot) {
    action->raw = 0;
    action->change.action = 3;
    action->change.unk4 = pos;
    action->change.slot = slot;
    action->change.unk10 = 0;
}

void func_ov167_021bdbec(BattleAction *action) {
    action->raw = 0;
    action->change.action = 3;
    action->change.slot = 0;
    action->change.unk10 = 1;
}

BOOL func_ov167_021bdc08(const BattleAction *action) {
    if (action->change.action == 3 && action->change.unk10 == 1) {
        return TRUE;
    }
    return FALSE;
}

void func_ov167_021bdc24(BattleAction *action, u8 target) {
    action->raw = 0;
    action->bits.action = 6;
    action->bits.target = target;
}

void func_ov167_021bdc3c(BattleAction *action) {
    action->bits.action = 4;
}

void func_ov167_021bdc4c(BattleAction *action) {
    action->bits.action = 5;
}

// Function name from swan.
void BattleAction_SetNull(BattleAction *action) {
    action->bits.action = 0;
    action->raw &= 0xf;
}

void BattleAction_SetSkip(BattleAction *action) {
    action->bits.action = 7;
}

u32 BattleAction_GetAction(const BattleAction *action) {
    return action->bits.action;
}

void func_ov167_021bdc84(BattleAction *action) {
    action->bits.action = 8;
    action->raw &= 0xf;
}

void func_ov167_021bdc98(BattleAction *action) {
    action->bits.action = 9;
    action->raw &= 0xf;
}
