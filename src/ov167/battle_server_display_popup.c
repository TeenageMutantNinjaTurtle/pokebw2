#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"

// Function names from swan.
void ServerDisplay_AbilityPopupAdd(BattleHandler *handler, BattleMon *mon) {
    func_ov167_021b1434(handler->display, 0x57, GetMonID(mon));
}

void ServerDisplay_AbilityPopupRemove(BattleHandler *handler, BattleMon *mon) {
    func_ov167_021b1434(handler->display, 0x58, GetMonID(mon));
}
