#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

// Function names from swan.
struct IntimidateWork {
    u32 flags;
    u32 command;
    u8 unk08[4];
    s8 target;
    u8 unk0d;
    u8 active;
    u8 count;
    u8 mons[6];
};

const BattleEventHandlerEntry *EventAddIntimidate(u32 *priority) {
    *priority = 2;
    return data_ov167_021d7944;
}

void HandlerIntimidateMemberIn(void *context, void *flow, u32 monId) {
    u8 *mons;
    u32 side;
    u32 count;
    u32 i;
    struct IntimidateWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        side = func_ov167_021ab840(flow, monId);
        mons = func_ov167_021abc60(flow, 6);
        count = HandlerGetAlivePartyCount((BattleHandler *)flow, (u16)(side | 0x100), mons);
        if (count != 0) {
            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
            work = BattleHandler_PushWork((BattleHandler *)flow, 0xe, (void *)monId);
            work->command = 1;
            work->target = -1;
            work->active = 1;
            work->count = count;
            for (i = 0; i < count; i++) {
                work->mons[i] = mons[i];
            }
            BattleHandler_PopWork((BattleHandler *)flow, work);
            BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
        }
    }
}
