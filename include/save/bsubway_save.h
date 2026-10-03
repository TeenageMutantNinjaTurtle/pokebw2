#ifndef POKEBW2_SAVE_BSUBWAY_SAVE_H
#define POKEBW2_SAVE_BSUBWAY_SAVE_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The Battle Subway's save blocks: 0x38 the current play, 0x39 the scores, which include the Battle Points, and 0x3a
#define SAVE_BLOCK_BSUBWAY_PLAY 0x38
#define SAVE_BLOCK_BSUBWAY_SCORE 0x39
#define SAVE_BLOCK_BSUBWAY_3A 0x3a

// Block 0x38. Value 0 is the play mode
u32 func_0200e11c(BSubwayPlayData *data, u32 id, void *buffer);
void func_0200e1ac(BSubwayPlayData *data, u32 id, const void *value);
void func_0200e0f4(BSubwayPlayData *data);
void func_0200e100(BSubwayPlayData *data, u32 value);
u32 func_0200e114(BSubwayPlayData *data);
void func_0200e280(BSubwayPlayData *data, u8 a1, u8 a2, u16 a3);
void func_0200e2ac(BSubwayPlayData *data);
void func_0200e2c0(BSubwayPlayData *data);
u16 func_0200e2ec(BSubwayPlayData *data);

// Block 0x39, which func_0201795c also returns. func_0200e318 adds Battle Points
void func_0200e318(BSubwayScoreData *score, u16 amount);
void func_0200e384(BSubwayScoreData *score, u32 mode, u32 value);
void func_0200e3a0(BSubwayScoreData *score, u32 mode, u32 value);
void func_0200e3f8(BSubwayScoreData *score, u32 mode);
void func_0200e52c(BSubwayScoreData *score, BSubwayPlayData *play);
u16 func_0200e35c(BSubwayScoreData *score, u16 a1);
u16 func_0200e370(BSubwayScoreData *score, u32 index);
void func_0200e3b4(BSubwayScoreData *score, u32 mode);
void func_0200e3c8(BSubwayScoreData *score, u32 mode);
u16 func_0200e3dc(BSubwayScoreData *score, u32 a1);
u16 func_0200e418(BSubwayScoreData *score, u32 mode);
u16 func_0200e438(BSubwayScoreData *score, u32 id, u32 op);

// Block 0x3a
u16 func_0200e6f4(void *data);
u16 func_0200e6fc(void *data);
u16 func_0200e72c(void *data);
u16 func_0200e7d8(void *data);
u16 func_0200e7e4(void *data);
// Allocates a copy of the block's list of 0x22-byte entries
void *func_0200e7f0(void *data, HeapID heapId);
u16 func_0200e82c(void *list);
u32 func_0200e84c(void *entry);

#endif // POKEBW2_SAVE_BSUBWAY_SAVE_H
