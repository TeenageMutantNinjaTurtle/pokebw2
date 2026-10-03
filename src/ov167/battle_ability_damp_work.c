#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

// Function names from swan.
void HandlerDamp(void *context, BtlServerFlow *flow, u32 monId, u32 *state) {
    u16 move;
    u32 key;

    move = BattleEventVar_GetValue(0x12);
    state[0] = 0;
    if (move == 0x99 || move == 0x78) {
        key = 0x22;
        if (BattleEventVar_GetValue(key) == 0) {
            state[0] = BattleEventVar_RewriteValue(key, 0x13);
            state[1] = move;
        }
    }
}

struct DampMessageWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerDampEffective(void *context, BtlServerFlow *flow, u32 monId, u32 *state) {
    u8 target;
    DampMessageWork *work;

    if (state[0]) {
        target = BattleEventVar_GetValue(2);
        work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
        work->flags |= 4 << 21;
        BattleHandler_StrSetup(&work->string, 2, 0x389);
        BattleHandler_AddArg(&work->string, target);
        BattleHandler_AddArg(&work->string, state[1]);
        BattleHandler_PopWork((BattleHandler *)flow, work);
        state[0] = 0;
    }
}
