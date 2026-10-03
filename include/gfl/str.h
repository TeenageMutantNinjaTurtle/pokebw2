#ifndef POKEBW2_GFL_STR_H
#define POKEBW2_GFL_STR_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Strings, and the word sets that fill the placeholders in messages

typedef struct StrBuf StrBuf;
typedef struct WordSet WordSet;

StrBuf *GFL_StrBufCreate(u32 size, HeapID heapId);
void GFL_StrBufFree(StrBuf *strbuf);
void GFL_StrBufCopy(StrBuf *dest, const StrBuf *src);
StrBuf *GFL_StrBufClone(const StrBuf *strbuf, HeapID heapId);
// Sets a string buffer to a string of up to length characters
void GFL_StrBufLoadFixedString(StrBuf *strbuf, const u16 *str, u32 length);
// Returns TRUE if the strings are the same, taking accented letters as their plain ones
BOOL GFL_StrBufCmpIgnoreAccents(const StrBuf *a, const StrBuf *b);
// Copies the string out, at most size characters
void GFL_StrBufStoreString(const StrBuf *strbuf, u16 *dest, u32 size);
void GFL_StrBufLoadString(StrBuf *strbuf, const u16 *src);
void GFL_StrBufClear(StrBuf *strbuf);
// Copies src, expanding it if it is compressed, as Trainer names in message file 409 are
void GFL_StrBufUncompress(StrBuf *dest, const StrBuf *src);
void textCopy(const u16 *src, StrBuf *dest);
StrBuf *copyTrainerNameToNewStrbuf(const u16 *name, HeapID heapId);

WordSet *GFL_WordSetSystemCreateDefault(HeapID heapId);
// A word set of count words of up to length characters
WordSet *GFL_WordSetSystemCreate(u32 count, u32 length, HeapID heapId);
void GFL_WordSetSystemFree(WordSet *wordSet);
void GFL_WordSetFormatStrbuf(WordSet *wordSet, StrBuf *dest, const StrBuf *src);
void GFL_WordSetLoadStr(WordSet *wordSet, u32 index, const u16 *str);
void WordSet_LoadSpeciesName(WordSet *wordSet, u32 index, u32 species);
void loadCountryToStrbuf(WordSet *wordSet, u32 index, u32 country);
void loadCountryAreaToStrbuf(WordSet *wordSet, u32 index, u32 country, u32 area);
void loadJobAnswerToStrbuf(WordSet *wordSet, u32 index, u8 job);
void loadHobbyNameToStrbuf(WordSet *wordSet, u32 index, u32 hobby);
// Puts a Pokémon's species name in a word set
void setPartyPokemonSpeciesNameToStrbuf(WordSet *wordSet, u32 index, PartyPkm *pkm);
void loadPokemonNicknameToStrbuf(WordSet *wordSet, u32 index, PartyPkm *pkm);
void loadMoveNameToStrbuf(WordSet *wordSet, u32 index, u32 move);
void loadItemNameToStrbuf(WordSet *wordSet, u32 index, u32 item);
// An item's name: the plural when plural is set, else the one in message file 481 when a4 is set
void loadItemText(WordSet *wordSet, u32 index, u32 item, BOOL plural, BOOL a4);
void loadBagPocketNameToStrbuf(WordSet *wordSet, u32 index, u32 pocket);
// Puts the player's name in a word set
void copyVarForText(WordSet *wordSet, u32 index, PlayerInfo *playerInfo);
// Puts a place name, from the place names' message file, in a word set
void loadLocationNameToStrbuf(WordSet *wordSet, u32 index, u32 placeNameId);
void func_0202437c(WordSet *wordSet, u32 index, const StrBuf *strbuf, u32 a3, u32 a4, u32 a5);

// How WordSetNumber pads a number to its digits
#define NUM_PAD_NONE 0
#define NUM_PAD_ZERO 2

void WordSetNumber(WordSet *wordSet, u32 index, s32 number, u32 digits, u32 pad, u32 a5);

#endif // POKEBW2_GFL_STR_H
