#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
struct ShedSkinWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved[0xb];
    u8 active;
};

void HandlerShedSkin(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    ShedSkinWork *work;
    u32 flag;

    flag = 2;
    if (BattleEventVar_GetValue(2) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon)) {
            if (AbilityEvent_RollEffectChance((BattleMon *)flow, 0x21)) {
                work = BattleHandler_PushWork((BattleHandler *)flow, 0xb, (void *)monId);
                work->flags |= flag << 22;
                work->flags |= flag << 24;
                work->status = 0x24;
                work->monId = monId;
                work->active = 1;
                BattleHandler_PopWork((BattleHandler *)flow, work);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddShedSkin(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78fc;
}
