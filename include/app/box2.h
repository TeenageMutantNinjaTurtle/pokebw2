#ifndef POKEBW2_APP_BOX2_H
#define POKEBW2_APP_BOX2_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// The PC Box
#define OVERLAY_BOX2 OVERLAY_ID(255)

#define BOX2_MODE_DREAM_WORLD 5

typedef struct {
    GameData *gameData;
    BoxSaveAccessor *boxes;
    PokeParty *party;
    BagSave *bag;
    PlayerInfo *playerInfo;
    u32 unk14;
    TrainerDataSave *trainerData;
    u32 unk1C;
    // Flags by species, which Box2Main_IsSpeciesFlagged reads
    u8 *unk20;
    u32 mode;
    u16 unk28;
    // Where the chosen Pokemon is, 0xff for both if none was chosen
    u8 tray;
    u8 position;
} Box2Param;

extern const GameProcFunctions BOX2_PROC_FUNCTIONS;

#endif // POKEBW2_APP_BOX2_H
