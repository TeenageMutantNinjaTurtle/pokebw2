#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerDampEnd(BattleEventItem *item, BtlServerFlow *flow, u32 monId) {
    if (BattleEventVar_GetValue(2) == monId) {
        BattleEventItem_DetachSkipCheckHandler(item);
    }
}
