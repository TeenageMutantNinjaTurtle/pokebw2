#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "pml/waza.h"

// Function names from swan.
void HandlerTechnician(void *context, void *flow, u32 monId) {
    u32 multiplier;

    multiplier = 0x30;
    if (BattleEventVar_GetValue(3) == monId) {
        if (BattleEventVar_GetValue(0x30) <= 0x3c) {
            BattleEventVar_MulValue(0x31, multiplier << 7);
        }
    }
}

const BattleEventHandlerEntry *EventAddTechnician(u32 *priority) {
    *priority = 1;
    return data_ov167_021d768c;
}

void HandlerIronFist(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (getMoveFlag(BattleEventVar_GetValue(0x12), 7)) {
            BattleEventVar_MulValue(0x31, 0x1333);
        }
    }
}

const BattleEventHandlerEntry *EventAddIronFist(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77dc;
}

void HandlerReckless(void *context, void *flow, u32 monId) {
    u16 move;

    if (BattleEventVar_GetValue(3) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (PML_MoveGetParam(move, 0x1e) || move == 0x1a || move == 0x88) {
            BattleEventVar_MulValue(0x31, 0x1333);
        }
    }
}

const BattleEventHandlerEntry *EventAddReckless(u32 *priority) {
    *priority = 1;
    return data_ov167_021d77a4;
}
