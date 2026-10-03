#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
struct PoisonHealWork {
    u32 flags;
    u16 amount;
    u8 monId;
};

void HandlerPoisonHeal(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    PoisonHealWork *work;
    u32 flag;

    if (BattleEventVar_GetValue(2) == monId) {
        if (BattleEventVar_GetValue(0x1d) == 5) {
            mon = GetBattleMon(flow, monId);
            BattleEventVar_RewriteValue(0x32, 0);
            work = BattleHandler_PushWork((BattleHandler *)flow, 5, (void *)monId);
            work->amount = DivideMaxHPZeroCheck(mon, 8);
            work->monId = monId;
            flag = 8;
            work->flags |= flag << 20;
            BattleHandler_PopWork((BattleHandler *)flow, work);
        }
    }
}

const BattleEventHandlerEntry *EventAddPoisonHeal(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78f4;
}
