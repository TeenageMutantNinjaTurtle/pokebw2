#include "battle/btl_ability.h"
#include "battle/btl_event.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"
#include "pml/waza.h"

// Function names from swan.
void HandlerPlusMinus(void *context, void *flow, u32 monId, void *list) {
    if (BattleEventVar_GetValue(3) == monId) {
        if (func_ov167_021be5c4(flow, monId, list, 0x39) || func_ov167_021be5c4(flow, monId, list, 0x3a)) {
            if (PML_MoveGetCategory(BattleEventVar_GetValue(0x12)) == 2) {
                BattleEventVar_MulValue(0x35, 6 << 10);
            }
        }
    }
}

const BattleEventHandlerEntry *EventAddPlusMinus(u32 *priority) {
    *priority = 1;
    return data_ov167_021d7724;
}

BOOL func_ov167_021be5c4(void *flow, u32 monId, void *list, u32 ability) {
    volatile u32 count;
    u32 clientCount;
    u16 packed;
    u8 i;
    u8 *mons;

    mons = list;
    clientCount = func_ov167_021abb50(flow);
    if (clientCount != 6) {
        packed = (7 << 8) | clientCount;
        count = HandlerGetAlivePartyCount((BattleHandler *)flow, packed, mons);
        for (i = 0; i < count; i++) {
            if (monId != mons[i]) {
                if (GetBattleMonStat(GetBattleMon(flow, mons[i]), 0x11) == ability) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}
