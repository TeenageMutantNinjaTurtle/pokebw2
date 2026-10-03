#include "types.h"
#include "field/field.h"
#include "field/field_map.h"
#include "field/gimmick_state.h"
#include "system/game_data.h"
#include "system/game_system.h"

void func_ov095_021eec80(Field *field) {
    GimmickState_GetUserData(GameData_GetGimmickState(GSYS_GetGameData(Field_GetGameSystem(field))), 4);
    Field_AllocGimmickWorkBlock(field, 1, Field_GetHeapID(field), 4);
}

void func_ov095_021eecac(Field *field) {
    Field_DeleteGimmickWorkBlock(field, 1);
}

void func_ov095_021eecb8(Field *field) {
}
