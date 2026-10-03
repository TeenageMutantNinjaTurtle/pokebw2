#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"

struct BattleHandlerSetWeightParam {
    u32 unk00;
    u8 monIndex;
    u8 unk05;
    u16 weight;
    u8 string[0x28];
};

// Function name from swan.
BOOL BattleHandler_SetWeight(BattleHandler *handler, BattleHandlerSetWeightParam *param) {
    BattleMon *mon;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    SetWeight(mon, param->weight);
    func_ov167_021b1434(handler->display, 0x14, param->monIndex, param->weight);
    BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
    return TRUE;
}
