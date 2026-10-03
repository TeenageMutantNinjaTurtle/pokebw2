#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_pokeparam.h"

// Function names from swan.
void scPut_SetContFlag(BattleHandler *handler, BattleMon *mon, u32 flag) {
    func_ov167_021bb7e4(mon, flag);
    func_ov167_021b1434(handler->display, 0x19, GetMonID(mon), flag);
}

void scPut_ResetContFlag(BattleHandler *handler, BattleMon *mon, u32 flag) {
    func_ov167_021bb808(mon, flag);
    func_ov167_021b1434(handler->display, 0x1a, GetMonID(mon), flag);
}

void ServerDisplay_SetTurnFlag(BattleHandler *handler, BattleMon *mon, u32 flag) {
    func_ov167_021bb7c0(mon, flag);
    func_ov167_021b1434(handler->display, 0x1b, GetMonID(mon), flag);
}
