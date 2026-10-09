#ifndef POKEBW2_SAVE_TRAINER_DATA_SAVEDATA_H
#define POKEBW2_SAVE_TRAINER_DATA_SAVEDATA_H

#include "types.h"
#include "save/config.h"
#include "save/player_info.h"
#include "save/playtime.h"
#include "struct_decls.h"

#define TRAINER_DATA_MARKER_COUNT 22
#define TRAINER_DATA_MARKER_SET 0xc21e

// The save block of the options, the player's info and the play time (trainer_data_savedata.c, a guessed name)
struct TrainerDataSave {
    Config config;
    PlayerInfo playerInfo;
    PlayTime playTime;
    u8 unk2C;
    u8 unk2D[3];
    // Each is TRAINER_DATA_MARKER_SET once something has happened
    u16 markers[TRAINER_DATA_MARKER_COUNT];
    u32 unk5C[21];
};

u32 getSizeofTrainerData(void);
void func_02008da4(TrainerDataSave *data);
PlayerInfo *SaveControl_GetPlayerInfo(SaveControl *save);
TrainerDataSave *getTrainerDataBlkAddress(SaveControl *save);
// The play time: hours and minutes
PlayTime *func_02008de8(SaveControl *save);
u8 func_02008df4(SaveControl *save);
void func_02008e04(SaveControl *save);
void func_02008e14(SaveControl *save);
BOOL func_02008e24(SaveControl *save, u32 index);
void func_02008e48(SaveControl *save, u32 index);
void func_02008e60(SaveControl *save, u32 index);
u32 *func_02008e74(SaveControl *save, u32 index);
// Copy the player's info from the player state, and back
void func_02008e88(SaveControl *save, PlayerState *state);
void func_02008ea8(SaveControl *save, PlayerState *state);

#endif // POKEBW2_SAVE_TRAINER_DATA_SAVEDATA_H
