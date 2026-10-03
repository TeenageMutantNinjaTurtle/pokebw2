#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.

void HandlerIceBody(void *context, BtlServerFlow *flow, u32 monId) {
    CommonWeatherRecoveryAbility(flow, monId, 3);
}

const BattleEventHandlerEntry *EventAddIceBody(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7644;
}

void HandlerRainDish(void *context, BtlServerFlow *flow, u32 monId) {
    CommonWeatherRecoveryAbility(flow, monId, 2);
}

const BattleEventHandlerEntry *EventAddRainDish(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76f4;
}

struct WeatherRecoveryWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void CommonWeatherRecoveryAbility(BtlServerFlow *flow, u32 monId, u32 weather) {
    BattleMon *mon;
    WeatherRecoveryWork *work;

    if (BattleEventVar_GetValue(0x39) == weather) {
        if (BattleEventVar_GetValue(2) == monId) {
            mon = GetBattleMon(flow, monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 5, (void *)monId);
            work->flags |= 2 << 22;
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 0x10);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleEventVar_RewriteValue(0x41, 1);
        }
    }
}
