#ifndef POKEBW2_FIELD_ENCOUNTER_H
#define POKEBW2_FIELD_ENCOUNTER_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct EncountSystem {
    u8 unk00[0x10];
    u32 unk10;
};

struct EncountState {
    u8 unk00[6];
    u8 unk06;
    u8 unk07;
    u32 unk08;
    u32 terrain;
    u16 unk10;
    u8 unk12[2];
    u32 unk14;
    u8 unk18[0x10];
};

extern const char data_ov012_0216e240[];
extern const u16 ROAMING_POKEMON_ZONES[17];

void EncData_Load(void *encData, ArcTool *arc, u16 zoneId, u8 season);
EncountState *EncountState_Create(HeapID heapId);
void EncountState_Free(EncountState *state);
void EncountState_SetTerrain(EncountState *state, u32 terrain);
void func_ov012_0215917c(GameData *gameData, Field *field);
void func_ov012_021591b4(GameData *gameData);
void func_ov012_021591f4(void);
u16 EncountSave_GetRoamingPkmZone(EncountSave *save);
u16 getSwarmLevelRangeFromData(GameData *gameData);
u32 func_ov012_02159218(void);
void func_ov012_0215921c(void);
void func_ov012_02159220(GameData *gameData);
u32 GetDefaultWeatherValue(void);
u32 func_ov012_0215922c(void);
void func_ov036_021a203c(EncountSystem *system, u32 value);

void EncountSystem_CancelPhenomenon(EncountSystem *encountSystem);

#endif // POKEBW2_FIELD_ENCOUNTER_H
