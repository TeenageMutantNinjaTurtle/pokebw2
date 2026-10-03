#include "battle/btl_ability.h"
#include "battle/btl_event.h"

// Function names from swan.
void HandlerDrySkinDamageRecover(void *context, BtlServerFlow *flow, u32 monId) {
    if (BattleEventVar_GetValue(4) == monId) {
        if (BattleEventVar_GetValue(0x16) == 9) {
            BattleEventVar_MulValue(0x31, 5 << 10);
        }
    }
}
