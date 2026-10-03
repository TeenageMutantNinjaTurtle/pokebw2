#ifndef POKEBW2_SAVE_TRIAL_HOUSE_H
#define POKEBW2_SAVE_TRIAL_HOUSE_H

#include "types.h"
#include "struct_decls.h"

u32 func_0200ee20(void);
BOOL func_0200ee38(void *saveBuffer);
BOOL func_0200ee64(void *extraSave);
u32 func_0200ee7c(void *saveBuffer);
void *func_0200ee90(void *save, u32 mode);
void func_0200eea0(GameData *gameData, void *saveBuffer, u32 heapId);
void *func_0200f1b8(SaveControl *save);
void func_0200ef1c(void *extraSave);

#endif // POKEBW2_SAVE_TRIAL_HOUSE_H
