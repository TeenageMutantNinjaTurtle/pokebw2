#include "types.h"
#include "battle/btl_ability.h"
#include "battle/btl_action.h"
#include "battle/btl_action_order.h"
#include "battle/btl_display.h"
#include "battle/btl_event.h"
#include "battle/btl_field.h"
#include "battle/btl_handler.h"
#include "battle/btl_item.h"
#include "battle/btl_main.h"
#include "battle/btl_math.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server.h"
#include "battle/btl_server_flow.h"
#include "battle/btl_setup.h"
#include "battle/btlv.h"
#include "constants/pokemon.h"
#include "gfl/std.h"
#include "pml/poke_party.h"
#include "pml/waza.h"
#include "save/bag.h"
#include "save/config.h"

// Function names from swan.
BOOL DoesSwitchModeNeedConfirming(BtlServer *server) {
    u32 i;
    BattleParty *party;

    if (IsSwitchMode(server->mainModule) && server->count != 0) {
        for (i = 0; i < server->count; i++) {
            if (func_ov167_0219c650(server->mainModule, server->posList[i]) == 0) {
                return FALSE;
            }
        }
        party = GetPartyData(server->pokeCon, GetPlayerClientID(server->mainModule));
        if (GetAlivePartyCount(party) < 2) {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

u8 GetNextEnemyForSwitchMode(BtlServer *server) {
    struct SwitchModeState *switchMode;
    BattleAction *action;
    u8 slot;

    switchMode = &server->switchMode;
    if (IsSwitchModeEnabled(switchMode)) {
        action = func_ov167_021d4b50(switchMode->actionManager, NULL);
        if (BattleAction_GetAction(action) == 3) {
            slot = action->change.slot;
            return GetMonID(GetClientMonData(server->pokeCon, 1, slot));
        }
    }
    return 31;
}
