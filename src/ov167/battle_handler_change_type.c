#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"

struct BattleHandlerChangeTypeParam {
    u32 unk00;
    u16 type;
    u8 monIndex;
    u8 suppressMessage;
};

// Function name from swan.
BOOL BattleHandler_ChangeType(BattleHandler *handler, BattleHandlerChangeTypeParam *param) {
    BattleMon *mon;

    if (func_ov167_021ad1f4((u8 *)handler + 0x1ab8, param->monIndex)) {
        mon = GetPokeParam(handler->pokeCon, param->monIndex);
        if (!IsFainted(mon) && !func_ov167_021ad204(GetBattleMonSpecies(mon))) {
            func_ov167_021b1434(handler->display, 0x16, param->monIndex, param->type);
            ChangePokeType(mon, param->type);
            if (!param->suppressMessage && PokeTypePair_IsMonotype(param->type)) {
                func_ov167_021b15d0(handler->display, 0x5b, 0x380, param->monIndex, PokeTypePair_GetType1(param->type),
                                    0xffff0000);
            }
            return TRUE;
        }
    }
    return FALSE;
}
