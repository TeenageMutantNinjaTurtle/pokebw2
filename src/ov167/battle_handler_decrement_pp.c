#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerDecrementPPParam {
    u32 unk00;
    u8 amount;
    u8 monIndex;
    u8 moveIndex;
    u8 unk07 : 1;
    u8 allowFainted : 1;
    u8 unk09 : 6;
    u8 string[0x28];
};

// Function name from swan.
BOOL BattleHandler_DecrementPP(BattleHandler *handler, BattleHandlerDecrementPPParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon) || param->allowFainted) {
        if (ServerControl_DecrementPP(handler, mon, param->moveIndex, param->amount)) {
            BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
            if (ServerEvent_DecrementPP(handler, mon, param->moveIndex)) {
                ServerControl_UseHeldItem(handler, mon);
            }
        }
        return TRUE;
    }
    return FALSE;
}
