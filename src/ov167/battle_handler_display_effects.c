#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"

// Function names from swan.

// Function name from swan.
BOOL BattleHandler_RemoveMessageWindow(BattleHandler *handler) {
    func_ov167_021b1434(handler->display, 0x56, 0);
    return TRUE;
}

struct BattleHandlerChangeFormParam {
    u32 unk00 : 23;
    u32 showAbility : 1;
    u32 unk18 : 8;
    u8 monIndex;
    u8 form;
    u8 unk06[2];
    u8 string[0x28];
};

// Function name from swan.
BOOL BattleHandler_ChangeForm(BattleHandler *handler, BattleHandlerChangeFormParam *param) {
    BattleMon *mon;
    u8 currentForm;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) && !TransformCheck(mon)) {
        currentForm = GetBattleMonStat(mon, 0x13);
        if (currentForm != param->form) {
            if (param->showAbility) {
                ServerDisplay_AbilityPopupAdd(handler, mon);
            }
            ChangeForm(mon, param->form);
            func_ov167_021b1434(handler->display, 0x4f, param->monIndex, param->form);
            BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
            if (param->showAbility) {
                ServerDisplay_AbilityPopupRemove(handler, mon);
            }
            return TRUE;
        }
    }
    return FALSE;
}

struct BattleMoveEffectState {
    u8 unk00[4];
    u8 index;
    u8 enabled : 1;
    u8 unk05 : 7;
};

struct BattleHandlerMoveEffectParam {
    u8 unk00[4];
    u8 index;
};

BOOL BattleHandler_SetMoveEffectIndex(BattleHandler *handler, BattleHandlerMoveEffectParam *param) {
    handler->moveEffect->index = param->index;
    return TRUE;
}

BOOL BattleHandler_SetMoveEffectEnable(BattleHandler *handler) {
    if (!handler->moveEffect->enabled) {
        handler->moveEffect->enabled = 1;
    }
    return TRUE;
}
