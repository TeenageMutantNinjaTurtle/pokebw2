#ifndef POKEBW2_SAVE_TRIAL_HOUSE_H
#define POKEBW2_SAVE_TRIAL_HOUSE_H

#include "types.h"
#include "struct_decls.h"

// Save block 0x3f
struct TrialHouseSave {
    u8 flag0;
    u8 pad1[0x13];
    u8 flag14;
    u8 pad15[0x13];
    u8 bits[16];
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
