#ifndef POKEBW2_FIELD_ENCOUNTER_H
#define POKEBW2_FIELD_ENCOUNTER_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Names and layouts from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)
struct EncountSystem {
    Field *field;
    GameSystem *gsys;
    GameData *gameData;
    EncData *encData;
    void *effectEncountState;
};

struct EncountState {
    s16 x;
    s16 y;
    s16 z;
    // The encounter rate climbs by its config's increase each time the block counter, which grows by the step
    // increment, reaches its threshold
    u8 rateBlockCounter;
    u8 rateStepIncrement;
    u32 rateStepCounter;
    u32 terrain;
    u16 encountRate;
    u8 unk12[2];
    u32 unk14;
    u8 unk18[0x10];
};

// How the encounter rate of a kind of encounter climbs while the player walks
typedef struct {
    u8 increase;
    u8 threshold;
    u8 max;
    u8 steps;
} EncountRateConfig;

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
void func_ov012_021591f4(GameData *gameData);
u16 EncountSave_GetRoamingPkmZone(EncountSave *save, u8 slot);
u16 getSwarmLevelRangeFromData(GameData *gameData);
u32 func_ov012_02159218(EncountSave *save);
void func_ov012_0215921c(void);
void func_ov012_02159220(GameData *gameData);
u32 GetDefaultWeatherValue(void);
u32 func_ov012_0215922c(void);
void func_ov036_021a203c(EncountSystem *system, void *effectEncountState);
// The phenomena (shaking grass, dust clouds and rippling water) of effect_encount.c
void *EffectEncountState_Create(HeapID heapId);
void EffectEncountState_Free(void *state);
void PrepareFieldEncountSystem(EncountSystem *system, void *effectEncountState);
void func_ov036_021a202c(EncountSystem *system, void *effectEncountState);
// The wild encounters of field_encount.c
EncountSystem *EncSys_Create(Field *field);
void EncSys_Free(EncountSystem *system);
BOOL EncSys_IsActive(EncountSystem *system, u32 a1);
void EncSys_Update(EncountSystem *system, BOOL moved, BOOL turned);
GameEvent *EventWildBattleCall_CreateStatic(EncountSystem *system, u16 species, u8 level, u8 form, u16 flags);
u32 ConvFieldWeatherToBtl(Field *field);
void func_ov036_021a2364(EncountSystem *system);
// Sets the setup up for a battle against the trainer, here
// The style is 0 to 3 for single, double, triple and rotation; a double battle is against two trainers with a
// partner, and a single one with a second trainer
void BtlSetup_SetTrainerLocal(EncountSystem *encountSystem, BtlSetup *setup, u32 style, u32 partnerId, u32 trainerId,
                              u32 trainerId2, HeapID heapId);
// The battle's encounter effect and music, against the wild species or the trainer
void EventBattleCall_DecideEnvWild(u32 species, u32 form, u32 a2, BOOL a3, Field *field, u32 *encEffect, u16 *bgm);
void EventBattleCall_DecideEnvTrainer(u32 trainerId, Field *field, u32 *encEffect, u16 *bgm);

void EncountSystem_CancelPhenomenon(EncountSystem *encountSystem);
u32 EncountState_CheckSpecialEncountPos(EncountSystem *encounter, const u16 *gridPos);
// The setup of the wild battle on the fishing rod, or NULL for none; rare is for rippling water
BtlSetup *BtlSetup_CreateFishing(EncountSystem *encounter, BOOL rare);

#endif // POKEBW2_FIELD_ENCOUNTER_H
