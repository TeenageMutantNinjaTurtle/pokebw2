#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
void HandlerBlaze(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 9);
}

const BattleEventHandlerEntry *EventAddBlaze(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7734;
}

void HandlerTorrent(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 10);
}

const BattleEventHandlerEntry *EventAddTorrent(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7694;
}

void HandlerOvergrow(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 11);
}

const BattleEventHandlerEntry *EventAddOvergrow(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76cc;
}

void HandlerSwarm(void *context, BtlServerFlow *flow, u32 monId) {
    CommonLowHPBoostAbility(flow, monId, 6);
}

const BattleEventHandlerEntry *EventAddSwarm(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76c4;
}

void CommonLowHPBoostAbility(BtlServerFlow *flow, u32 monId, u32 type) {
    BattleMon *mon;
    u32 threshold;
    u32 divisor;

    divisor = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        mon = GetBattleMon(flow, monId);
        threshold = DivideMaxHp(mon, divisor);
        if (GetBattleMonStat(mon, 0xd) <= threshold) {
            if (BattleEventVar_GetValue(0x16) == type) {
                BattleEventVar_MulValue(0x35, divisor << 11);
            }
        }
    }
}
