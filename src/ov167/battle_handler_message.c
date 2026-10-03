#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"

struct BattleHandlerMessageParam {
    u32 unk00 : 8;
    u32 monIndex : 5;
    u32 unk13 : 10;
    u32 popup : 1;
    u32 unk24 : 8;
    u8 string[0x28];
};

// Function name from swan.
BOOL BattleHandler_Message(BattleHandler *handler, BattleHandlerMessageParam *param) {
    BattleMon *mon;

    mon = NULL;
    if (param->monIndex != 0x1f) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
    }
    if (param->popup && mon != NULL) {
        ServerDisplay_AbilityPopupAdd(handler, mon);
    }
    BattleHandler_SetString(handler, (BattleHandlerString *)param->string);
    if (param->popup && mon != NULL) {
        ServerDisplay_AbilityPopupRemove(handler, mon);
    }
    return TRUE;
}
