#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerSetCounterParam {
    u32 unk00;
    u8 monIndex;
    u8 counter;
    u8 value;
};

// Function name from swan.
BOOL BattleHandler_SetCounter(BattleHandler *handler, BattleHandlerSetCounterParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    ServerControl_SetMonCounter(handler, mon, param->counter, param->value);
    return TRUE;
}
