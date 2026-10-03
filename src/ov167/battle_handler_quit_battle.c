#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_server_flow.h"

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
