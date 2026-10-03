#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

// Function names from swan.
struct NaturalCureWork {
    u32 flags;
    u32 status;
    u8 monId;
    u8 reserved09[0xb];
    u8 active;
    u8 showPopup;
};

void HandlerNaturalCure(void *context, BtlServerFlow *flow, u32 monId) {
    NaturalCureWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        work = BattleHandler_PushWork((BattleHandler *)flow, 0xb, (void *)monId);
        work->status = 0x24;
        work->active = 1;
        work->monId = monId;
        work->showPopup = 1;
        BattleHandler_PopWork((BattleHandler *)flow, work);
    }
}

const BattleEventHandlerEntry *EventAddNaturalCure(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7874;
}
