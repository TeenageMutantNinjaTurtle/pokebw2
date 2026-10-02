#include "types.h"
#include "field/field_map.h"
#include "field/gimmick_state.h"
#include "system/game_data.h"
#include "system/game_system.h"

struct GimmickStateA {
    u8 mode;
    u8 step;
    u16 padding;
    u32 values[5];
};

struct GimmickStateB {
    u8 padding[0x14];
    u16 first;
    u16 second;
};

void func_ov090_021eec80(GameSystem *gsys, u16 value) {
    u16 *state = GimmickState_GetUserData(GameData_GetGimmickState(GSYS_GetGameData(gsys)), 2);
    *state = value;
}

void func_ov090_021eec98(GameSystem *gsys) {
    GimmickStateA *state = GimmickState_GetUserData(GameData_GetGimmickState(GSYS_GetGameData(gsys)), 10);
    int i;

    state->step = 0;
    state->mode = 2;
    for (i = 0; i < 5; i++) {
        state->values[i] = 0;
    }
}

void func_ov090_021eecc0(GameSystem *gsys, BOOL first, BOOL second) {
    GimmickStateB *state = GimmickState_GetUserData(GameData_GetGimmickState(GSYS_GetGameData(gsys)), 0x30);

    if (first) {
        state->first = 1;
    }
    if (second) {
        state->second = 1;
    }
}
