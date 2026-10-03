#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
void HandlerMarvelScale(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;

    if (BattleEventVar_GetValue(4) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon)) {
            BattleEventVar_GetValue(0x12);
            if (BattleEventVar_GetValue(0x1a) == 1) {
                BattleEventVar_MulValue(0x35, 6 << 10);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddMarvelScale(u32 *priority) {
    *priority = 1;
    return data_ov167_021d772c;
}

void HandlerSkillLink(void *context, void *flow, u32 monId) {
    if (BattleEventVar_GetValue(3) == monId) {
        BattleEventVar_RewriteValue(0x51, 1);
    }
}

const BattleEventHandlerEntry *EventAddSkillLink(u32 *priority) {
    *priority = 1;
    return data_ov167_021d769c;
}
