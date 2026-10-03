#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "pml/waza.h"

// Function names from swan.
struct SoundproofMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerSoundproof(void *context, BtlServerFlow *flow, u32 monId) {
    SoundproofMessageWork *work;
    u32 command;
    u16 move;

    command = 4;
    if (BattleEventVar_GetValue(4) == monId) {
        move = BattleEventVar_GetValue(0x12);
        if (getMoveFlag(move, 8)) {
            if (BattleEventVar_RewriteValue(0x40, 1)) {
                BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
                work = BattleHandler_PushWork((BattleHandler *)flow, command, (void *)monId);
                BattleHandler_StrSetup(&work->string, 2, 0xd2);
                BattleHandler_AddArg(&work->string, monId);
                BattleHandler_PopWork((BattleHandler *)flow, work);
                BattleHandler_PushRun((BattleHandler *)flow, 3, (void *)monId);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddSoundproof(u32 *priority) {
    *priority = 1;
    return data_ov167_021d780c;
}
