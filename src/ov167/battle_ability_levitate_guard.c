#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerLevitate(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    u32 key;

    if (BattleEventVar_GetValue(2) == monId) {
        key = 0x51;
        if (BattleEventVar_GetValue(key) == 0) {
            *result = BattleEventVar_RewriteValue(key, 1);
        }
    }
}
