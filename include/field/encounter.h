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

// Names and layouts from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)
typedef struct {
    u16 species : 11;
    u16 form : 5;
    u8 minLevel;
    u8 maxLevel;
} WildEncSlot;

// A zone's wild encounters for a season, 0xe8 bytes of archive 0x7f
struct EncData {
    u8 userData[7];
    u8 flags : 7;
    u8 fishingEnable : 1;
    WildEncSlot slots[56];
};

extern const char data_ov012_0216e240[];
extern const u16 ROAMING_POKEMON_ZONES[17];
// The places in the Abyssal Ruins where Flash and Strength can be used
extern const HiddenArea ABYSSAL_RUINS_FLASH_ROCK_RADIUS;
extern const HiddenArea ABYSSAL_RUINS_STRENGTH_ROCK_RADIUS;

BOOL EncData_Load(EncData *encData, ArcTool *arc, u16 zoneId, u8 season);
EncountState *EncountState_Create(HeapID heapId);
void EncountState_Free(EncountState *state);
void EncountState_SetTerrain(EncountState *state, u32 terrain);
void func_ov012_0215917c(GameData *gameData, Field *field);
void func_ov012_021591b4(GameData *gameData);
void func_ov012_021591f4(void);
u16 EncountSave_GetRoamingPkmZone(EncountSave *save, u8 slot);
u16 getSwarmLevelRangeFromData(GameData *gameData);
u32 func_ov012_02159218(EncountSave *save);
void func_ov012_0215921c(void);
void func_ov012_02159220(GameData *gameData);
u32 GetDefaultWeatherValue(void);
u32 func_ov012_0215922c(void);
void func_ov036_021a203c(EncountSystem *system, u32 value);

void EncountSystem_CancelPhenomenon(EncountSystem *encountSystem);
u32 EncountState_CheckSpecialEncountPos(EncountSystem *encounter, const u16 *gridPos);
BtlSetup *BtlSetup_CreateFishing(EncountSystem *encounter);
EncountSystem *EncSys_Create(Field *field);
void EncSys_Free(EncountSystem *system);

#endif // POKEBW2_FIELD_ENCOUNTER_H
