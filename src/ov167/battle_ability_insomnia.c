#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerInsomniaStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 2);
    if (!*result) {
        *result = HandlerCommonGuardStatus(flow, monId, 0xe);
    }
}

void HandlerInsomniaWake(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 2);
}

void HandlerInsomniaActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 2);
}

void HandlerInsomniaYawnCheck(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventVar_RewriteValue(0x41, 1);
    }
}

const BattleEventHandlerEntry *EventAddInsomnia(u32 *priority) {
    *priority = 6;
    return data_ov167_021d7dc0;
}
