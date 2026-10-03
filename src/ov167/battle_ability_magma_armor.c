#include "battle/btl_ability.h"

// Function names from swan.
void HandlerMagmaArmorStatus(void *context, void *flow, u32 monId, u32 *result) {
    *result = HandlerCommonGuardStatus(flow, monId, 3);
}

void HandlerMagmaArmorCureStatus(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatus(flow, monId, 3);
}

void HandlerMagmaArmorActionEnd(void *context, void *flow, u32 monId) {
    CommonAbilityCureStatusCore(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddMagmaArmor(u32 *priority) {
    *priority = 5;
    return data_ov167_021d7cd0;
}
