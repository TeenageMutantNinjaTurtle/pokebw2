#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
typedef struct SpeedBoostWork {
    u32 flags;
    u32 count;
    u8 unk08[4];
    u8 active;
    u8 unk0d[2];
    u8 amount;
    u8 monId;
} SpeedBoostWork;

void HandlerSpeedBoost(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    SpeedBoostWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetAdditionalConditionFlag(mon, 0)) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 0xe, (void *)monId);
            work->flags |= flag << 22;
            work->count = 5;
            work->amount = 1;
            work->monId = monId;
            work->active = 1;
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddSpeedBoost(u32 *priority) {
    *priority = 1;
    return data_ov167_021d771c;
}
