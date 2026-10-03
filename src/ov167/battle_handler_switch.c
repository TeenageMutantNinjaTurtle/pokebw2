#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerSwitchParam {
    u32 unk00;
    u8 firstString[0x28];
    u8 secondString[0x28];
    u8 monIndex;
    u8 flag;
};

// Function name from swan.
BOOL BattleHandler_Switch(BattleHandler *handler, BattleHandlerSwitchParam *param) {
    BattleMon *mon;
    u8 pos;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!ServerControl_CheckMatchup(handler) && !func_ov167_021abeb4(handler, param->monIndex) && handler->unk14 == 0) {
        BattleHandler_SetString(handler, (BattleHandlerString *)param->firstString);
        if (ServerControl_SwitchOut(handler, mon, param->flag)) {
            pos = MonIDToBattlePos(handler->mainModule, handler->pokeCon, param->monIndex);
            RequestChangePokemon(handler->serverFlow, pos);
            BattleHandler_SetString(handler, (BattleHandlerString *)param->secondString);
            handler->unk14 = 1;
            return TRUE;
        }
    }
    return FALSE;
}
