#include "battle/btl_action.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct SwitchModeState {
    void *actionManager;
    u8 unk04[7];
    u8 enabled;
};

struct BtlServerFlow {
    u8 unk00[0xc];
    BtlMainModule *mainModule;
    BtlPokeCon *pokeCon;
    u8 unk14[0xc];
    struct SwitchModeState switchMode;
    u8 unk2c[0xc88];
    u8 posList[6];
    u8 count;
};

struct SwitchBattleAction {
    u32 action : 4;
    u32 unk4 : 3;
    u32 slot : 3;
    u32 unk10 : 22;
};

// Function names from swan.
BOOL DoesSwitchModeNeedConfirming(BtlServerFlow *flow) {
    u32 i;
    BattleParty *party;

    if (IsSwitchMode(flow->mainModule) && flow->count != 0) {
        for (i = 0; i < flow->count; i++) {
            if (func_ov167_0219c650(flow->mainModule, flow->posList[i]) == 0) {
                return FALSE;
            }
        }
        party = GetPartyData(flow->pokeCon, GetPlayerClientID(flow->mainModule));
        if (GetAlivePartyCount(party) < 2) {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

u8 GetNextEnemyForSwitchMode(BtlServerFlow *flow) {
    struct SwitchModeState *switchMode;
    struct SwitchBattleAction *action;
    u8 slot;

    switchMode = &flow->switchMode;
    if (IsSwitchModeEnabled(switchMode)) {
        action = func_ov167_021d4b50(switchMode->actionManager, NULL);
        if (BattleAction_GetAction(action) == 3) {
            slot = action->slot;
            return GetMonID(GetClientMonData(flow->pokeCon, 1, slot));
        }
    }
    return 31;
}
