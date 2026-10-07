#ifndef POKEBW2_SAVE_KEY_INFO_H
#define POKEBW2_SAVE_KEY_INFO_H

#include "types.h"
#include "struct_decls.h"

// Unlocks a key, and enables what it unlocks
void func_020104b0(KeyInfoSave *keyInfo, u32 key);
void func_020104e0(KeyInfoSave *keyInfo, u32 key);
// Whether what a key unlocks is enabled
BOOL keyEnabler(KeyInfoSave *keyInfo, u32 key);
void SetGameDifficulty(KeyInfoSave *keyInfo, u32 difficulty);
// Sets the city, and the chamber the mystery door leads to
void func_02010550(KeyInfoSave *keyInfo, u32 city);
void func_0201058c(KeyInfoSave *keyInfo, u32 chamber);
// The Memory Link's data in the save (KeySystemWork's memoryLink). Links a Black or White save
BOOL func_020108dc(void *memoryLink, void *wbData, SaveControl *save);
// TRUE when no save is linked yet, or when the save's player (ID, name, gender) is in one of the three slots
BOOL func_0201090c(void *memoryLink, void *wbData, SaveControl *save);
// Whether a memory is unlocked, and the event work that marks it seen
BOOL func_02010c54(void *memoryLink, u32 memory);
u32 func_02010c6c(u32 memory);
// Returns 1 if the key that switches the city is set
u32 KeyInfo_GetCityKey(KeyInfoSave *keyInfo);
// The difficulty that the keys set, GAME_DIFFICULTY_*
u32 GetGameDifficulty(KeyInfoSave *keyInfo);
// 1 or 2 if a key that opens a chamber is set
u32 func_020105a0(KeyInfoSave *keyInfo);
// Returns its argument, as the key information in data that ov331 reads
KeyInfoSave *func_0201046c(void *a0);
// The Memory Link's data, at 0x38 in the same data
void *func_02010470(void *a0);

#define GAME_DIFFICULTY_EASY 0
#define GAME_DIFFICULTY_NORMAL 1
#define GAME_DIFFICULTY_CHALLENGE 2

#endif // POKEBW2_SAVE_KEY_INFO_H
