#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerCheckHeldItemParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05[3];
    u32 reaction;
};

// Function name from swan.
BOOL BattleHandler_CheckHeldItem(BattleHandler *handler, BattleHandlerCheckHeldItemParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    ServerControl_CheckItemReaction(handler, mon, param->reaction);
    return TRUE;
}
