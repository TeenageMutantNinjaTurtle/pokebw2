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

// The parameter's save data and its unlocks
PokeDexSave *PMSInputParam_GetPokeDex(const void *param);
PMSWordSave *PMSInputParam_GetWordSave(const void *param);
// Whether event flag 0x960 is set, which unlocks the moves
BOOL func_02029a74(const void *param);
// Whether the input offers the hidden words
BOOL func_02029a84(const void *param);

// The words' texts, one message bank for each kind of word
PMSWordMan *PMSWordMan_Create(u32 heapId);
void PMSWordMan_Delete(PMSWordMan *man);
void PMSWordMan_CopyStr(PMSWordMan *man, u16 word, StrBuf *buf);
// The word of an entry of a message bank
u16 PMSWord_GetWordNumByGmmId(u32 gmmId, u32 index);
// Whether the player has learned one of the greetings
BOOL PMSWordSave_GetGreetingFlag(const PMSWordSave *save, u32 id);

// Overlay 185, the phrase select
extern const GameProcFunctions data_ov185_021a7298;

#endif // POKEBW2_SYSTEM_PMS_H
