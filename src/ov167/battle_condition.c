#include "types.h"
#include "battle/btl_ability.h"
#include "battle/btl_action.h"
#include "battle/btl_action_order.h"
#include "battle/btl_display.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_item.h"
#include "battle/btl_main.h"
#include "battle/btl_math.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "battle/btl_setup.h"
#include "battle/btlv.h"
#include "constants/pokemon.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "pml/waza.h"
#include "save/bag.h"
#include "save/config.h"

BOOL IsStatChangeValid(BattleMon *mon, u32 stat, s32 change);

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.

// Function names from swan.
// Function names from swan.
BattleCondition ZeroConditionTurns(void) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 0;
    return condition;
}

BOOL func_ov167_021ce168(BattleCondition condition) {
    if (condition.common.type == 0) {
        return TRUE;
    }
    return FALSE;
}

BattleCondition SetConditionTurns(u32 turns) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 2;
    condition.common.turns = turns;
    condition.timed.param = 0;
    return condition;
}

BattleCondition AddTurnCondition(u32 turns, u16 param) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 2;
    condition.common.turns = turns;
    condition.timed.param = param;
    return condition;
}

BattleCondition func_ov167_021ce1dc(u32 turns) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 3;
    condition.common.turns = turns;
    return condition;
}

BattleCondition MakeConditionPermanent(void) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 1;
    return condition;
}

BattleCondition MakeConditionParamPermanent(u16 param) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 1;
    condition.timed.param = param;
    return condition;
}

BattleCondition func_ov167_021ce238(u32 turns, u16 param) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 1;
    condition.common.turns = turns;
    condition.timed.param = param;
    return condition;
}

BattleCondition func_ov167_021ce268(u32 monId, u32 turns) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 4;
    condition.common.turns = turns;
    condition.mon.monId = monId;
    return condition;
}

BattleCondition func_ov167_021ce298(void) {
    BattleCondition condition;

    condition.raw = 0;
    condition.common.type = 1;
    condition.common.turns = 15;
    return condition;
}

BOOL Condition_IsBadlyPoisoned(BattleConditionCont cont) {
    u32 turns;
    u32 type;

    turns = cont.common.turns;
    type = cont.common.type;
    return type == 1 && turns == 15;
}

u8 Condition_GetMonID(BattleCondition condition) {
    u32 type;
    u32 mon1;
    u32 mon2;

    type = condition.common.type;
    mon1 = condition.common.turns;
    mon2 = condition.mon.monId;
    if (type == 3) {
        return mon1;
    }
    if (type == 4) {
        return mon2;
    }
    return 31;
}

void func_ov167_021ce308(BattleCondition *condition, u32 value) {
    if (condition->common.type == 3) {
        condition->common.turns = value;
        return;
    }
    if (condition->common.type == 4) {
        condition->mon.monId = value;
    }
}

u8 func_ov167_021ce33c(BattleCondition condition) {
    u32 type;
    u32 turns;

    type = condition.common.type;
    turns = condition.common.turns;
    if (type == 2) {
        return turns;
    }
    if (type == 4) {
        return turns;
    }
    return 0;
}

void func_ov167_021ce368(BattleCondition *condition, u16 value) {
    if (condition->common.type == 1) {
        condition->timed.param = value;
        return;
    }
    if (condition->common.type == 3) {
        condition->timed.param = value;
        return;
    }
    if (condition->common.type == 4) {
        condition->raw = (condition->raw & 0x80007fff) | (((u32)value << 16) >> 1);
        return;
    }
    if (condition->common.type == 2) {
        condition->timed.param = value;
    }
}

u16 Condition_GetParam(BattleCondition condition) {
    if (condition.common.type == 1) {
        return (u16)((condition.raw << 7) >> 16);
    }
    if (condition.common.type == 3) {
        return (u16)((condition.raw << 7) >> 16);
    }
    if (condition.common.type == 4) {
        return (u16)((condition.raw << 1) >> 16);
    }
    if (condition.common.type == 2) {
        return (u16)((condition.raw << 7) >> 16);
    }
    return 0;
}

void SetConditionFlag(BattleCondition *condition, u32 flag) {
    if (condition->common.type == 1) {
        condition->one.flag = flag;
        return;
    }
    if (condition->common.type == 3) {
        condition->one.flag = flag;
        return;
    }
    if (condition->common.type == 4) {
        condition->four.flag = flag;
        return;
    }
    if (condition->common.type == 2) {
        condition->one.flag = flag;
    }
}

u32 func_ov167_021ce464(BattleCondition condition) {
    if (condition.common.type == 1) {
        return condition.one.flag;
    }
    if (condition.common.type == 3) {
        return condition.one.flag;
    }
    if (condition.common.type == 4) {
        return condition.four.flag;
    }
    if (condition.common.type == 2) {
        return condition.one.flag;
    }
    return 0;
}

void IncrementTurn(BattleCondition *condition, u32 amount) {
    if (condition->common.type == 2 && condition->common.turns < 8) {
        condition->common.turns += amount;
    }
    if (condition->common.type == 4 && condition->common.turns < 8) {
        condition->common.turns += amount;
    }
}

void SetTurns(BattleCondition *condition, u32 turns) {
    if (condition->common.type == 2 && condition->common.turns < 8) {
        condition->common.turns = turns;
    }
    if (condition->common.type == 4 && condition->common.turns < 8) {
        condition->common.turns = turns;
    }
}
