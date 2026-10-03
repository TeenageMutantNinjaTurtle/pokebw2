#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerFlinchParam {
    u32 unk00;
    u8 monIndex;
    u8 flag;
};

// Function name from swan.
u8 BattleHandler_Flinch(BattleHandler *handler, BattleHandlerFlinchParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (ServerControl_FlinchCore(handler, mon, param->flag)) {
        return TRUE;
    }
    return FALSE;
}
