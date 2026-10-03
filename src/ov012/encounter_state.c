#include "field/encounter.h"
#include "field/field.h"
#include "field/field_player.h"
#include "gfl/heap.h"
#include "save/encounter.h"
#include "system/game_data.h"

EncountState *EncountState_Create(HeapID heapId) {
    EncountState *state = GFL_HeapAllocate(heapId, sizeof(EncountState), TRUE, data_ov012_0216e240, 0x2d);
    EncountState_SetTerrain(state, 0xff);
    return state;
}

void EncountState_Free(EncountState *state) {
    GFL_HeapFree(state);
}

void func_ov012_0215917c(GameData *gameData, Field *field) {
    EncountSystem *system = Field_GetEncountSystem(field);
    FieldPlayer *player;
    EncountState *state;
    u32 terrain;

    player = Field_GetPlayer(field);
    func_ov036_021a203c(system, system->unk10);
    state = GameData_GetEncountState(gameData);
    terrain = FieldPlayer_GetTileTypeUnder(player);
    EncountState_SetTerrain(state, terrain);
}

void func_ov012_021591b4(GameData *gameData) {
    EncountState *state = GameData_GetEncountState(gameData);
    state->unk14 = 0;
}

void GameData_InitEncountTerrain(GameData *gameData, Field *field) {
    FieldPlayer *player = Field_GetPlayer(field);
    EncountState *state = GameData_GetEncountState(gameData);
    u32 terrain = FieldPlayer_GetTileTypeUnder(player);
    EncountState_SetTerrain(state, terrain);
}

void EncountState_SetTerrain(EncountState *state, u32 terrain) {
    state->terrain = terrain;
    state->unk08 = 0;
    state->unk10 = 1;
    state->unk06 = 0;
    state->unk07 = 0;
}

void func_ov012_021591f4(void) {
}

u16 EncountSave_GetRoamingPkmZone(EncountSave *save) {
    u32 clock = EncountSave_GetRoamingPkmZoneClock(save);
    if (clock > 16) {
        return 319;
    }
    return ROAMING_POKEMON_ZONES[clock];
}

u32 func_ov012_02159218(void) {
    return 0;
}

void func_ov012_0215921c(void) {
}

void func_ov012_02159220(void) {
}

u32 GetDefaultWeatherValue(void) {
    return 0xffff;
}

u32 func_ov012_0215922c(void) {
    return 0;
}
