#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.
void HandlerGuts(void *context, BtlServerFlow *flow, u32 monId) {
    BattleMon *mon;
    u32 multiplier;

    multiplier = 3;
    if (BattleEventVar_GetValue(3) == monId) {
        mon = GetBattleMon(flow, monId);
        if (GetBattleMonStatus(mon) != 0) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 1) {
                BattleEventVar_MulValue(0x35, multiplier << 11);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddGuts(u32 *priority) {
    *priority = 1;
    return data_ov167_021d76bc;
}
