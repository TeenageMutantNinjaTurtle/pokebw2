#include "battle/btl_handler.h"

struct BattleMoveEffectState {
    u8 unk00[4];
    u8 index;
    u8 enabled : 1;
    u8 unk05 : 7;
};

struct BattleHandlerMoveEffectParam {
    u8 unk00[4];
    u8 index;
};

// Function names from swan.
BOOL BattleHandler_SetMoveEffectIndex(BattleHandler *handler, BattleHandlerMoveEffectParam *param) {
    handler->moveEffect->index = param->index;
    return TRUE;
}

BOOL BattleHandler_SetMoveEffectEnable(BattleHandler *handler) {
    if (!handler->moveEffect->enabled) {
        handler->moveEffect->enabled = 1;
    }
    return TRUE;
}
