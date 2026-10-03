#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

// Function names from swan.
struct AirLockWeatherWork {
    u32 flags;
    u8 weather;
    u8 duration;
    u8 active;
    u8 reserved;
    BattleHandlerString string;
};

void HandlerAirLockMemberIn(void *context, void *flow, u32 monId) {
    AirLockWeatherWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 0x1d, (void *)monId);
        work->flags |= flag << 22;
        work->weather = 0;
        work->active = 1;
        BattleHandler_StrSetup(&work->string, 1, 0x5e);
        BattleHandler_PopWork((BattleHandler *)flow, work);
    }
}

BOOL HandlerAirLockChangeWeather(void *context, void *flow, u32 monId) {
    return BattleEventVar_RewriteValue(0x41, 1);
}

const BattleEventHandlerEntry *EventAddAirLock(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7994;
}
