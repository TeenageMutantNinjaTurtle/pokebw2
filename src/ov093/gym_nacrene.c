#include "types.h"
#include "field/field.h"
#include "field/field_map.h"
#include "field/gym_nacrene.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov093_021eec80(Field *field) {
    Field_AllocGimmickWorkBlock(field, 1, Field_GetHeapID(field), 4);
    Field_GetGimmickWorkBlock(field, 1);
    GimmickState_GetUserData(GameData_GetGimmickState(GSYS_GetGameData(Field_GetGameSystem(field))), 3);
}

void func_ov093_021eecb4(Field *field) {
    Field_DeleteGimmickWorkBlock(field, 1);
}

void func_ov093_021eecc0(Field *field) {
}
