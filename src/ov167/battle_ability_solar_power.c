#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.
struct SolarPowerWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void HandlerSolarPowerWeather(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    SolarPowerWork *work;
    u16 amount;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x39) == 1) {
            mon = GetBattleMon(flow, monId);
            amount = DivideMaxHPZeroCheck(mon, 8);
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 7, (void *)monId);
            work->monId = monId;
            work->amount = amount;
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
        }
    }
}

void HandlerSolarPowerPower(void *context, BtlServerFlow *flow, u32 monId) {
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        if (GetWeather(flow) == 1) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 2) {
                BattleEventVar_MulValue(0x35, multiplier << 11);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddSolarPower(u32 *priority) {
    *priority = 2;
    return data_ov167_021d79b4;
}
