#include "battle/btl_ability.h"
#include "battle/btl_handler.h"

// Function names from swan.
struct RunAwayMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerRunAwayMessage(void *context, BtlServerFlow *flow, u32 monId) {
    RunAwayMessageWork *work;
    u32 flags;

    if (CommonCheckRunMessage(context)) {
        flags = 4;
        work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
        work->flags |= flags << 21;
        BattleHandler_StrSetup(&work->string, 1, 0x48);
        BattleHandler_AddSoundEffect(&work->string, 0x56a);
        BattleHandler_PopWork((BattleHandler *)flow, work);
    }
}

const BattleEventHandlerEntry *EventAddRunAway(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7934;
}
