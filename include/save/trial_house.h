#ifndef POKEBW2_SAVE_TRIAL_HOUSE_H
#define POKEBW2_SAVE_TRIAL_HOUSE_H

#include "types.h"
#include "struct_decls.h"

// Save block 0x3f
// A Pokémon of a recorded team
typedef struct {
    u16 species;
    u8 form;
    u8 sex;
} TrialHousePokemon;

// The result of a challenge
typedef struct {
    u8 valid;
    u8 isDouble;
    u16 points;
    TrialHousePokemon pokemon[4];
} TrialHouseRecord;

struct TrialHouseSave {
    // The challenges against the Trainers of the game and of a downloaded challenge
    TrialHouseRecord records[2];
    u8 bits[16];
    // Copied from the downloaded challenge's save
    u8 unk38[0x22];
};

u32 func_0200ee20(void);
BOOL func_0200ee38(void *saveBuffer);
BOOL func_0200ee64(void *extraSave);
u32 func_0200ee7c(void *saveBuffer);
// The Trainer of a recorded battle, 0 to 4
BSubwayTrainer *func_0200ee90(void *save, u32 index);
void func_0200eea0(GameData *gameData, void *saveBuffer, u32 heapId);
TrialHouseSave *func_0200f1b8(SaveControl *save);
void func_0200ef1c(void *extraSave);

#endif // POKEBW2_SAVE_TRIAL_HOUSE_H
