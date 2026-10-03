#include "battle/btl_ability.h"

// Function names from swan.
void HandlerImmunity(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 5);
}

void HandlerImmunityCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 5);
}

void HandlerImmunityActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 5);
}

const BattleEventHandlerEntry *EventAddImmunity(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7cf8;
}

void HandlerWaterVeil(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 4);
}

void HandlerWaterVeilCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 4);
}

void HandlerWaterVeilActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 4);
}

const BattleEventHandlerEntry *EventAddWaterVeil(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7d20;
}
