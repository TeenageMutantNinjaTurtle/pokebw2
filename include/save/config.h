#ifndef POKEBW2_SAVE_CONFIG_H
#define POKEBW2_SAVE_CONFIG_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The options, which a save keeps at the start of the block that getTrainerDataBlkAddress returns
typedef struct Config Config;

Config *func_0200898c(HeapID heapId);
// Copies a config into the save's
void initConfig(const Config *config, TrainerDataSave *dest);
// The text speed option
u32 func_02008a14(const Config *config);
BOOL func_02008a68(const Config *config);
// Bit 8, which also sets the message language: the kana or kanji text of the Japanese version
void func_02008a8c(Config *config, u32 value);
void func_02008ab4(TrainerDataSave *config);
u32 func_02008ac8(TrainerDataSave *config);
// Bit 10: whether the C-Gear is on, which a continue sets from the answer to the start menu's question
u32 func_02008ae8(const Config *config);
void func_02008af0(Config *config, u32 value);

#endif // POKEBW2_SAVE_CONFIG_H
