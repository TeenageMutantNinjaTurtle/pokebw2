#ifndef POKEBW2_SYSTEM_PMS_H
#define POKEBW2_SYSTEM_PMS_H

// The phrases made of a sentence and words, and the parameter of overlay 185's phrase select, of ARM9 main

#include "types.h"
#include "gfl/heap.h"
#include "gfl/proc.h"
#include "struct_decls.h"

typedef struct {
    u16 sentenceType;
    u16 sentenceId;
    u16 words[2];
} PMSData;

// The phrase select's parameter, for one kind of phrase
void *func_02029968(u32 kind, u32 a1, u32 a2, u32 a3, SaveControl *save, HeapID heapId);
void func_02029a20(void *param);
// The phrase the select starts with
void func_02029a2c(void *param, const PMSData *sentence);
// Whether the player backed out
BOOL func_02029a40(void *param);
u16 func_02029a48(void *param);
void func_02029a4c(void *param, u16 *words);
void func_02029a58(void *param, PMSData *sentence);
// The phrase as a string
StrBuf *func_02029c80(const PMSData *sentence, HeapID heapId);

// The C-Gear's phrases, which the save keeps
void *getCGearDataBlkAddress(SaveControl *save);
void func_0200ef90(void *cgear, u32 index, PMSData *sentence);
void func_0200efa8(void *cgear, u32 index, const PMSData *sentence);
// The same block, through the C-Gear's own accessor
void *func_0200ef7c(SaveControl *save);
// Sets the greeting that the game's beacon sends
void func_0202d0fc(const PMSData *greeting);

// Overlay 185, the phrase select
extern const GameProcFunctions data_ov185_021a7298;

#endif // POKEBW2_SYSTEM_PMS_H
