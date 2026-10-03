#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
struct AngerPointWork {
    u32 flags;
    u32 stage;
    u8 reserved08[4];
    u8 amount;
    u8 active;
    u8 showPopup;
    u8 showMessage;
    u8 monId;
    u8 reserved11[7];
    BattleHandlerString string;
};

void HandlerAngerPoint(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    AngerPointWork *work;
    s32 amount;

    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x46) == 0) {
            if (BattleEventVar_GetValue(0x45) != 0) {
                mon = GetBattleMon(flow, monId);
                if (func_ov167_021bb550(mon, 1) > 0) {
                    work = BattleHandler_PushWork((BattleHandler *)flow, 0xe, (void *)monId);
                    work->stage = 1;
                    amount = func_ov167_021bb550(mon, 1);
                    work->amount = amount;
                    work->showPopup = 1;
                    work->showMessage = 1;
                    work->monId = monId;
                    work->active = 1;
                    work->flags |= 1 << 23;
                    BattleHandler_StrSetup(&work->string, 2, 0x1e1);
                    BattleHandler_AddArg(&work->string, monId);
                    BattleHandler_PopWork((BattleHandler *)flow, work);
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddAngerPoint(u32 *priority) {
    *priority = 1;
    return data_ov167_021d78dc;
}
