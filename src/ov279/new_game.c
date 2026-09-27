#include "types.h"

typedef struct GameData GameData;
typedef struct SaveControl SaveControl;
typedef struct BagSave BagSave;
typedef struct PlayerInfo PlayerInfo;
typedef struct DreamRadarSave DreamRadarSave;

extern BagSave *GameData_GetBag(GameData *gameData);
extern PlayerInfo *GetGameDataPlayerInfo(GameData *gameData);
extern SaveControl *GameData_GetSaveControl(GameData *gameData);
extern void BagSave_Init(BagSave *bag);
extern BOOL BagSave_AddItem(BagSave *bag, u32 item, u32 count, u32 heapId);
extern u32 getTrainerGender(PlayerInfo *player);
extern DreamRadarSave *GetDreamRadarSaveBlock(SaveControl *save);
extern void SetDreamRadarFlag(DreamRadarSave *save, u32 flag, u32 value);
extern u32 GFL_RandomLC(u32 max);

#define GENDER_MALE 0

#define ITEM_PAL_PAD 437
// The male and female Xtransceivers are separate items
#define ITEM_XTRANSCEIVER_MALE 621
#define ITEM_XTRANSCEIVER_FEMALE 626

// Overlay 279 is only loaded to set up the save data of a new game

void InitItemBag_(GameData *gameData, u32 heapId) {
    BagSave *bag = GameData_GetBag(gameData);
    PlayerInfo *player = GetGameDataPlayerInfo(gameData);

    BagSave_Init(bag);
    if (getTrainerGender(player) == GENDER_MALE) {
        BagSave_AddItem(bag, ITEM_XTRANSCEIVER_MALE, 1, heapId);
    } else {
        BagSave_AddItem(bag, ITEM_XTRANSCEIVER_FEMALE, 1, heapId);
    }
    BagSave_AddItem(bag, ITEM_PAL_PAD, 1, heapId);
}

void InitDreamRadarFlagSave_(GameData *gameData) {
    DreamRadarSave *save = GetDreamRadarSaveBlock(GameData_GetSaveControl(gameData));

    // Value 1 gets a random 32-bit number, the others are cleared
    SetDreamRadarFlag(save, 1, GFL_RandomLC(0));
    SetDreamRadarFlag(save, 0, 0);
    SetDreamRadarFlag(save, 2, 0);
}

void InitItemBag(GameData *gameData, u32 heapId) {
    InitItemBag_(gameData, heapId);
}

void InitDreamRadarFlagSave(GameData *gameData, u32 heapId) {
    InitDreamRadarFlagSave_(gameData);
}
