#include "battle/btl_ability.h"

// Function names from swan.
void HandlerOwnTempoStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 6);
}

void HandlerOwnTempoAddStatusFailed(void *context, void *flow, u32 monId, void *result) {
    CommonAddStatusFailed(context, flow, monId, result, 0x165);
}

void HandlerOwnTempoCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 6);
}

void HandlerOwnTempoActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 6);
}

const BattleEventHandlerEntry *EventAddOwnTempo(u32 *priority) {
    *priority = 4;
    return data_ov167_021d7c38;
}
