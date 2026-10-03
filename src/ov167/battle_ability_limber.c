#include "battle/btl_ability.h"

// Function names from swan.
void HandlerLimberStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 1);
}

void HandlerLimberCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 1);
}

void HandlerLimberActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 1);
}

const BattleEventHandlerEntry *EventAddLimber(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7c80;
}
