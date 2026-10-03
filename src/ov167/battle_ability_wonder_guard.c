#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.
struct WonderGuardMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerWonderGuard(void *context, BtlServerFlow *flow, u32 monId) {
    WonderGuardMessageWork *work;
    u16 move;
    u32 run;

    if (BattleEventVar_GetValue(4) == monId) {
        run = 3;
        if (BattleEventVar_GetValue(run) != monId) {
            GetBattleMon(flow, monId);
            move = BattleEventVar_GetValue(0x12);
            if (PML_MoveIsDamaging(move)) {
                if (move != 0xa5) {
                    if ((s32)BattleEventVar_GetValue(0x38) <= 3) {
                        if (BattleEventVar_RewriteValue(0x40, 1)) {
                            BattleHandler_PushRun((BattleHandler *)flow, 2, (void *)monId);
                            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
                            BattleHandler_StrSetup(&work->string, 2, 0xd2);
                            BattleHandler_AddArg(&work->string, monId);
                            BattleHandler_PopWork((BattleHandler *)flow, work);
                            BattleHandler_PushRun((BattleHandler *)flow, run, (void *)monId);
                        }
                    }
                }
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddWonderGuard(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76e4;
}
