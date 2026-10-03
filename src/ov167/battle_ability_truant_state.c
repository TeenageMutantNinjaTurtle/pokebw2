#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.
void HandlerTruant(void *context, BtlServerFlow *flow, u32 monId, u32 *state) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (state[0] != 0) {
            state[1] = BattleEventVar_RewriteValue(0x22, 0x13);
            state[0] = 0;
        } else {
            state[0] = 1;
        }
    }
}

void HandlerTruantGet(void *context, BtlServerFlow *flow, u32 monId, u32 *result) {
    if (BattleEventVar_GetValue(2) == monId) {
        if (GetTurnFlag(GetBattleMon(flow, monId), 0)) {
            *result = 1;
        }
    }
}
