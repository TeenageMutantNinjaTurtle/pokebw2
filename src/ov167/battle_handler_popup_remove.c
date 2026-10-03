#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"

// Function name from swan.
BOOL BattleHandler_AbilityPopupRemove(BattleHandler *handler, BattleHandlerPopupParam *param) {
    BattleMon *mon = GetPokeParam(handler->pokeCon, param->monId);
    ServerDisplay_AbilityPopupRemove(handler, mon);
    return TRUE;
}
