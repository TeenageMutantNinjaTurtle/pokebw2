#include "battle/btl_setup.h"
#include "field/bsubway_scr.h"
#include "gfl/heap.h"
#include "gfl/std.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov033_0217b664(GameSystem *gsys, BSubwayScrWork *bsw) {
    if (bsw != NULL) {
        if (bsw->allocatedBuffer != NULL) {
            GFL_HeapFree(bsw->allocatedBuffer);
            bsw->allocatedBuffer = NULL;
        }
        if (bsw->btlSetup != NULL) {
            BtlSetup_Free(bsw->btlSetup);
            bsw->btlSetup = NULL;
        }
        sys_memset(bsw, 0, sizeof(BSubwayScrWork));
        GFL_HeapFree(bsw);
    }
    func_02017954(GSYS_GetGameData(gsys), 0);
}
