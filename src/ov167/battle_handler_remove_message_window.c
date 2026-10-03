#include "battle/btl_display.h"
#include "battle/btl_handler.h"

// Function name from swan.
BOOL BattleHandler_RemoveMessageWindow(BattleHandler *handler) {
    func_ov167_021b1434(handler->display, 0x56, 0);
    return TRUE;
}
