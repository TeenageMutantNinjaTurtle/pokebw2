#include "battle/btl_action.h"
#include "battle/btl_handler.h"

// Function names from swan.
void *BattleHandler_PushWork(BattleHandler *handler, u32 command, void *data) {
    return func_ov167_021b0920((BtlActionState *)&handler->actionState, command, data);
}

void BattleHandler_PushRun(BattleHandler *handler, u32 command, void *data) {
    void *work;

    work = BattleHandler_PushWork(handler, command, data);
    BattleHandler_PopWork(handler, work);
}

void BattleHandler_PopWork(BattleHandler *handler, void *work) {
    BattleHandler_Execute(handler);
    PopWork((BtlActionState *)&handler->actionState, work);
}

u32 BattleHandler_Result(BattleHandler *handler) {
    BtlActionState *state;

    state = (BtlActionState *)&handler->actionState;
    if (IsUsed(state)) {
        if (func_ov167_021b0918(state)) {
            return 2;
        }
        return 1;
    }
    return 0;
}
