#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerBatonPassParam {
    u32 unk00;
    u8 sourceMonIndex;
    u8 targetMonIndex;
};

// Function name from swan.
BOOL BattleHandler_BatonPass(BattleHandler *handler, BattleHandlerBatonPassParam *param) {
    BattleMon *source;
    BattleMon *target;
    u8 substitute;

    source = GetPokeParam(handler->pokeCon, param->sourceMonIndex);
    target = GetPokeParam(handler->pokeCon, param->targetMonIndex);
    if (CheckCondition(source, 16)) {
        ServerEvent_GastroAcidConfirmed(handler, target);
    }
    CopyBatonPassParams(target, source);
    func_ov167_021b1434(handler->display, 0x26, param->sourceMonIndex, param->targetMonIndex);
    if (IsSubstituteActive(target)) {
        substitute = func_ov167_021add78((u8 *)handler + 0x1ab8, param->targetMonIndex);
        func_ov167_021b1434(handler->display, 0x51, substitute);
    }
    return TRUE;
}
