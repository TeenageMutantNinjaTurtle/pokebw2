#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerChangeHPParam {
    u32 unk00;
    u8 count;
    u8 suppress;
    u8 skipReaction;
    u8 monIds[9];
    u32 hpChanges[6];
};

// Function name from swan.
BOOL BattleHandler_ChangeHP(BattleHandler *handler, BattleHandlerChangeHPParam *param) {
    u32 result;
    u32 i;
    BattleMon *mon;

    result = FALSE;
    for (i = 0; i < param->count; i++) {
        if (func_ov167_021acad4((u8 *)handler + 0x1ab8, param->monIds[i])) {
            mon = GetPokeParam(handler->pokeCon, param->monIds[i]);
            if (!IsFainted(mon)) {
                ServerDisplay_SimpleHP(handler, mon, param->hpChanges[i], param->suppress == 0);
                if (param->skipReaction == 0) {
                    ServerControl_CheckItemReaction(handler, mon, 1);
                }
                result = TRUE;
            }
        }
    }
    return result;
}
