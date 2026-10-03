#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
struct ForecastFormWork {
    u32 flags;
    u8 monId;
    u8 form;
    u8 reserved06[2];
    BattleHandlerString string;
};

void HandlerForecastAbilityOff(void *context, BtlServerFlow *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        CommonForecastOff(context, flow, monId);
    }
}

void CommonForecastOff(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    ForecastFormWork *work;
    mon = GetBattleMon(flow, monId);
    if (GetBattleMonSpecies(mon) == 0x15f) {
        if (GetBattleMonStat(mon, 0x13) != 0) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 0x39, (void *)monId);
            work->monId = monId;
            work->form = 0;
            BattleHandler_StrSetup(&work->string, 2, 0xde);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

void CommonForecastFormChange(BtlServerFlow *flow, u32 monId, u32 weather) {
    BattleMon *mon;
    ForecastFormWork *work;
    u8 currentForm;
    u32 newForm;
    mon = GetBattleMon(flow, monId);
    if (GetBattleMonSpecies(mon) == 0x15f) {
        currentForm = GetBattleMonStat(mon, 0x13);
        switch (weather) {
        case 0:
            newForm = 0;
            break;
        case 1:
            newForm = 1;
            break;
        case 2:
            newForm = 2;
            break;
        case 3:
            newForm = 3;
            break;
        default:
            newForm = 0;
            break;
        }
        if (newForm != currentForm) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 0x39, (void *)monId);
            work->flags |= 2 << 22;
            work->monId = monId;
            work->form = newForm;
            BattleHandler_StrSetup(&work->string, 2, 0xde);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddForecast(u32 *priority) {
    *priority = 9;
    return data_ov167_021d7e58;
}
