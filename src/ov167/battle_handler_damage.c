#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerDamageParam {
    u32 unk00 : 8;
    u32 sourceIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u16 amount;
    u8 targetIndex;
    u8 checkSemi : 1;
    u8 showViewEffect : 1;
    u8 unkFlags : 6;
    u16 effect;
    u8 effectArg1;
    u8 effectArg2;
    BattleHandlerString string;
};

// Function name from swan.
BOOL BattleHandler_Damage(BattleHandler *handler, BattleHandlerDamageParam *param) {
    BattleMon *mon;
    BattleMon *source;

    if (func_ov167_021aca54((u8 *)handler + 0x1ab8, param->targetIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->targetIndex);
        source = NULL;
        if (param->sourceIndex != 0x1f) {
            source = GetPokeParam(handler->pokeCon, param->sourceIndex);
        }
        if (!IsFainted(mon)) {
            if (!param->checkSemi || !IsSemiInvulnMove(mon)) {
                if (ServerControl_CheckSimpleDamageEnabled(handler, mon, param->amount)) {
                    if (param->popup) {
                        ServerDisplay_AbilityPopupAdd(handler, source);
                    }
                    if (param->showViewEffect) {
                        ServerControl_ViewEffect(handler, param->effect, param->effectArg1, param->effectArg2, 0, 0);
                    }
                    ServerControl_SimpleDamageCore(handler, mon, param->amount, &param->string);
                    if (param->popup) {
                        ServerDisplay_AbilityPopupRemove(handler, source);
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}
