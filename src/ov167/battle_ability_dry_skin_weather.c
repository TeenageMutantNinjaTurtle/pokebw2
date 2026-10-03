#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
struct DrySkinWeatherWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void HandlerDrySkinWeather(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    DrySkinWeatherWork *work;
    u8 weather;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        weather = BattleEventVar_GetValue(0x39);
        if (weather == 1) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 7, (void *)monId);
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
        } else if (weather == 2) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 5, (void *)monId);
            work->flags |= 2 << 22;
            work->monId = monId;
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}
