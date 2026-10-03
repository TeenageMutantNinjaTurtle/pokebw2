#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

// Function names from swan.

struct BattleHandlerQuitBattleParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
};

// Function name from swan.
BOOL BattleHandler_QuitBattle(BattleHandler *handler, BattleHandlerQuitBattleParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (ServerControl_EscapeSub(handler, mon, TRUE)) {
        handler->unk14 = 5;
        return TRUE;
    }
    return FALSE;
}

struct BattleHandlerSwitchParam {
    u32 unk00;
    u8 firstString[0x28];
    u8 secondString[0x28];
    u8 monIndex;
    u8 flag;
};

// Function name from swan.
BOOL BattleHandler_Switch(BattleHandler *handler, BattleHandlerSwitchParam *param) {
    BattleMon *mon;
    u8 pos;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!ServerControl_CheckMatchup(handler) && !func_ov167_021abeb4(handler, param->monIndex) && handler->unk14 == 0) {
        BattleHandler_SetString(handler, (BattleHandlerString *)param->firstString);
        if (ServerControl_SwitchOut(handler, mon, param->flag)) {
            pos = MonIDToBattlePos(handler->mainModule, handler->pokeCon, param->monIndex);
            RequestChangePokemon(handler->serverFlow, pos);
            BattleHandler_SetString(handler, (BattleHandlerString *)param->secondString);
            handler->unk14 = 1;
            return TRUE;
        }
    }
    return FALSE;
}

struct BattleHandlerBatonPassParam {
    u32 unk00;
    u8 sourceMonIndex;
    u8 targetMonIndex;
};

// Function name from swan.
BOOL BattleHandler_BatonPass(BattleHandler *handler, BattleHandlerBatonPassParam *param) {
    BattleMon *source;
    BattleMon *target;
    u8 substitute;

    source = GetPokeParam(handler->pokeCon, param->sourceMonIndex);
    target = GetPokeParam(handler->pokeCon, param->targetMonIndex);
    if (CheckCondition(source, 16)) {
        ServerEvent_GastroAcidConfirmed(handler, target);
    }
    CopyBatonPassParams(target, source);
    func_ov167_021b1434(handler->display, 0x26, param->sourceMonIndex, param->targetMonIndex);
    if (IsSubstituteActive(target)) {
        substitute = func_ov167_021add78((u8 *)handler + 0x1ab8, param->targetMonIndex);
        func_ov167_021b1434(handler->display, 0x51, substitute);
    }
    return TRUE;
}
