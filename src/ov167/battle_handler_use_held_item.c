#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerUseHeldItemParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 19;
    u32 checkFullHp : 1;
    u32 allowFainted : 1;
    u32 unk22 : 30;
};

// Function name from swan.
BOOL BattleHandler_UseHeldItem(BattleHandler *handler, BattleHandlerUseHeldItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) || param->allowFainted) {
        if (param->checkFullHp && IsMonFullHP(mon)) {
            return FALSE;
        }
        if (ServerControl_UseHeldItem(handler, mon)) {
            return TRUE;
        }
    }
    return FALSE;
}
