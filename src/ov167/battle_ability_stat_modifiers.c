#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_math.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.

const BattleEventHandlerEntry *EventAddThickFat(u32 *priority) {
    *priority = 1;
    return data_ov167_021d763c;
}

void HandlerThickFat(void *context, void *item, u32 monId) {
    u8 type;

    if (BattleEventVar_GetValue(4) == monId) {
        type = BattleEventVar_GetValue(0x16);
        if (type == 14 || type == 9) {
            BattleEventVar_MulValue(0x35, 2 << 10);
        }
    }
}

const BattleEventHandlerEntry *EventAddHugePower(u32 *priority) {
    *priority = 1;
    return data_ov167_021d784c;
}

void HandlerHugePower(void *context, void *item, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, 2 << 12);
        }
    }
}

void HandlerSwiftSwim(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 2) {
            BattleEventVar_MulValue(0x35, multiplier << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddSwiftSwim(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77c4;
}

void HandlerChlorophyll(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetWeather(flow) == 1) {
            BattleEventVar_MulValue(0x35, multiplier << 12);
        }
    }
}

const BattleEventHandlerEntry *EventAddChlorophyll(u32 *priority) {
    *priority = 1;
    return data_ov167_021d765c;
}

void HandlerQuickFeet(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetBattleMonStatus(GetBattleMon(flow, monId)) != 0) {
            BattleEventVar_MulValue(0x35, 6 << 10);
            BattleEventVar_RewriteValue(0x51, 0);
        }
    }
}

const BattleEventHandlerEntry *EventAddQuickFeet(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77cc;
}

void HandlerTangledFeet(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        if (CheckCondition(GetBattleMon(flow, monId), 6)) {
            BattleEventVar_MulValue(0x35, multiplier << 9);
        }
    }
}

const BattleEventHandlerEntry *EventAddTangledFeet(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76ec;
}

void HandlerHustleAccuracy(void *context, void *item, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetCategory(move) == 1) {
            BattleEventVar_MulValue(0x35, 0xccd);
        }
    }
}

void HandlerHustlePower(void *context, void *item, u32 monId) {
    u32 multiplier;
    u32 value;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
            value = BattleEventVar_GetValue(0x33);
            value = fixed_round(value, multiplier << 11);
            BattleEventVar_RewriteValue(0x33, value);
        }
    }
}

const BattleEventHandlerEntry *EventAddHustle(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7a44;
}

void HandlerStall(void *context, void *item, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x11, 0);
    }
}

const BattleEventHandlerEntry *EventAddStall(u32 *priority) {
    *priority = numHandlersWithHandlerPri(7, 1);
    return data_ov167_021d7624;
}
