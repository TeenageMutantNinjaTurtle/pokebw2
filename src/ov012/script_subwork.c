#include "field/field_script.h"
#include "gfl/heap.h"
#include "system/game_data.h"
#include "system/game_system.h"

ScriptSubwork *InitScriptSubwork(ScriptWork *work, HeapID heapId) {
    ScriptSubwork *subwork = GFL_HeapAllocate(heapId, sizeof(ScriptSubwork), TRUE, data_ov012_0216e1e4, 0x7b);

    subwork->work = work;
    subwork->gsys = ScriptWork_GetGameSystem(work);
    subwork->gameData = GSYS_GetGameData(subwork->gsys);
    subwork->mmSys = GameData_GetMMSys(subwork->gameData);
    subwork->actorMsgPosActual = 7;
    return subwork;
}

void func_ov012_021550e4(void *subwork) {
    GFL_HeapFree(subwork);
}