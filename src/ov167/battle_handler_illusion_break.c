#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"

struct BattleHandlerIllusionBreakParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    BattleHandlerString string;
};

// Function name from swan.
BOOL BattleHandler_IllusionBreak(BattleHandler *handler, BattleHandlerIllusionBreakParam *param) {
    BattleMon *mon;

    if (func_ov167_021ae0fc((u8 *)handler + 0x1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (IsIllusionEnabled(mon)) {
            IllusionBreak(mon);
            func_ov167_021b1434(handler->display, 0x4b, param->monIndex);
            BattleHandler_SetString(handler, &param->string);
            return TRUE;
        }
    }
    return FALSE;
}
