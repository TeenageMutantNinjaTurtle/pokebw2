#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"

// Function names from swan.
struct LevitateImmunityWork {
    u32 flags;
    BattleHandlerString string;
};

void HandlerLevitateAddImmunity(void *context, BtlServerFlow *flow, u32 monId, u32 *active) {
    LevitateImmunityWork *work;

    if (BattleEventVar_GetValue(2) == monId) {
        if (*active) {
            work = BattleHandler_PushWork((BattleHandler *)flow, 4, (void *)monId);
            work->flags |= 4 << 21;
            BattleHandler_StrSetup(&work->string, 2, 0xd2);
            BattleHandler_AddArg(&work->string, monId);
            BattleHandler_PopWork((BattleHandler *)flow, work);
            *active = 0;
        }
    }
}
