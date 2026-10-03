#include "field/badge_gate.h"
#include "field/field.h"
#include "field/field_exp_obj.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov103_021eec80(Field *field) {
    HeapID heapId;
    GameData *gameData;
    BadgeGateWork *work;

    heapId = Field_GetHeapID(field);
    gameData = GSYS_GetGameData(Field_GetGameSystem(field));
    GameData_GetGimmickState(gameData);
    work = Field_AllocGimmickWorkBlock(field, 0, heapId, sizeof(BadgeGateWork));
    work->unk00 = 0x15;
    work->field = field;
    work->expObj = Field_GetExpObjSystem(field);
    work->eventWork = GameData_GetEventWork(gameData);
    work->last = 0;
    LoadFieldExpandObjData(work->expObj, &data_ov103_021ef814, 0);
    LoadFieldExpandObjData(work->expObj, &data_ov103_021ef824, 1);
    LoadFieldExpandObjData(work->expObj, &data_ov103_021ef844, 2);
    func_ov103_021eecfc(work);
}
