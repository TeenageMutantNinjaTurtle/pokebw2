#ifndef POKEBW2_SAVE_KEY_INFO_H
#define POKEBW2_SAVE_KEY_INFO_H

#include "types.h"
#include "struct_decls.h"

// Returns 1 if the key that switches the city is set

u32 KeyInfo_GetCityKey(KeyInfoSave *keyInfo);
// The difficulty that the keys set, GAME_DIFFICULTY_*
u32 GetGameDifficulty(KeyInfoSave *keyInfo);
// 1 or 2 if a key that opens a chamber is set
u32 func_020105a0(KeyInfoSave *keyInfo);
// Returns its argument, as the key information in data that ov331 reads
KeyInfoSave *func_0201046c(void *a0);

#define GAME_DIFFICULTY_EASY 0
#define GAME_DIFFICULTY_NORMAL 1
#define GAME_DIFFICULTY_CHALLENGE 2

#endif // POKEBW2_SAVE_KEY_INFO_H
