#include "battle/btl_action.h"
#include "battle/btl_display.h"
#include "battle/btl_handler.h"
#include "battle/btl_item.h"
#include "battle/btl_main.h"
#include "battle/btl_pokeparam.h"
#include "battle/btl_server_flow.h"

struct BattleHandlerForceUseItemParam {
    u32 unk00 : 8;
    u32 monIndex2 : 5;
    u32 unk13 : 19;
    u8 monIndex;
    u8 unk05;
    u16 item;
};

// Function name from swan.
BOOL BattleHandler_ForceUseItem(BattleHandler *handler, BattleHandlerForceUseItemParam *param) {
    BattleMon *mon;
    void *temp;
    u32 reserve;
    u32 state;

    mon = GetPokeParam(handler->pokeCon, param->monIndex);
    if (!IsFainted(mon)) {
        temp = ItemEvent_TempAdd(mon, param->item);
        if (temp != NULL) {
            reserve = SCQUE_RESERVE_Pos(handler->display, 0x42);
            state = PushState((BtlActionState *)&handler->actionState, 0x3db8);
            ServerEvent_EquipTempItem(handler, mon, param->monIndex2);
            if (BattleHandler_Result(handler) == 2) {
                func_ov167_021b14ec(handler->display, reserve, 0x42, param->monIndex);
            }
            PopState((BtlActionState *)&handler->actionState, state, 0x3dbf);
            func_ov167_021c27c4(temp);
            return TRUE;
        }
    }
    return FALSE;
}
