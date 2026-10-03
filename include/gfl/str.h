#ifndef POKEBW2_GFL_STR_H
#define POKEBW2_GFL_STR_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Strings, and the word sets that fill the placeholders in messages

// String buffers (strbuf.c): up to size characters, of which length are used, followed by the terminator. It grew out of
// Gen 4's Strbuf in pokeplatinum's string_gf.c

// Sets the character that ends strings, 0xffff unless changed
void GFL_StrBufSetTerminator(u16 terminator);
BOOL GFL_StrBufIsValid(const StrBuf *strbuf);
// A buffer for size characters, the terminator included
StrBuf *GFL_StrBufCreate(u32 size, HeapID heapId);
void GFL_StrBufFree(StrBuf *strbuf);
void GFL_StrBufClear(StrBuf *strbuf);
// Copies a string to a buffer that is large enough for it, or leaves the buffer as it was
void GFL_StrBufCopy(StrBuf *dest, const StrBuf *src);
StrBuf *GFL_StrBufClone(const StrBuf *strbuf, HeapID heapId);
// Returns TRUE if the strings are the same
BOOL GFL_StrBufCmp(const StrBuf *a, const StrBuf *b);
u16 GFL_StrBufGetCharCount(const StrBuf *strbuf);
// Cuts the string to length characters
void GFL_StrBufInsertTerminator(StrBuf *strbuf, u32 length);
// Sets a buffer to a terminated string, or as much of it as fits
void GFL_StrBufLoadString(StrBuf *strbuf, const u16 *src);
// Sets a string buffer to a string of up to length characters
void GFL_StrBufLoadFixedString(StrBuf *strbuf, const u16 *str, u32 length);
// Sets a buffer to length characters, the terminator included
void GFL_StrBufCopyString(StrBuf *strbuf, const u16 *src, u32 length);
// Copies the string out, at most size characters
void GFL_StrBufStoreString(const StrBuf *strbuf, u16 *dest, u32 size);
const u16 *GFL_StrBufGetStringPtr(const StrBuf *strbuf);
u16 GFL_StrBufGetTerminator(void);
// Appends a string, if it fits whole, or a character
void GFL_StrBufConcat(StrBuf *dest, const StrBuf *src);
void GFL_StrBufAppend(StrBuf *strbuf, u16 c);

// Returns TRUE if the strings are the same, taking accented letters as their plain ones
BOOL GFL_StrBufCmpIgnoreAccents(const StrBuf *a, const StrBuf *b);
// Copies src, expanding it if it is compressed, as Trainer names in message file 409 are
void GFL_StrBufUncompress(StrBuf *dest, const StrBuf *src);
void textCopy(const u16 *src, StrBuf *dest);
StrBuf *copyTrainerNameToNewStrbuf(const u16 *name, HeapID heapId);

WordSet *GFL_WordSetSystemCreateDefault(HeapID heapId);
// A word set of count words of up to length characters
WordSet *GFL_WordSetSystemCreate(u32 count, u32 length, HeapID heapId);
void GFL_WordSetSystemFree(WordSet *wordSet);
void GFL_WordSetClearAll(WordSet *wordSet);
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
void loadPokemonTextNameToStrbuf(WordSet *wordSet, u32 index, PartyPkm *pkm);
void loadPokemonSpeciesTextNameToStrbuf(WordSet *wordSet, u32 index, PartyPkm *pkm);
void loadMoveNameToStrbuf(WordSet *wordSet, u32 index, u32 move);
void loadItemNameToStrbuf(WordSet *wordSet, u32 index, u32 item);
void loadPassPowerToStrbuf(WordSet *wordSet, u32 index, u32 passPower);
void func_02024868(WordSet *wordSet, u32 index, u32 value, u32 arg3);
// An item's name: the plural when plural is set, else the one in message file 481 when a4 is set
void loadItemText(WordSet *wordSet, u32 index, u32 item, BOOL plural, BOOL a4);
void loadBagPocketNameToStrbuf(WordSet *wordSet, u32 index, u32 pocket);
// Puts the player's name in a word set
void copyVarForText(WordSet *wordSet, u32 index, PlayerInfo *playerInfo);
// Puts a place name, from the place names' message file, in a word set
void loadLocationNameToStrbuf(WordSet *wordSet, u32 index, u32 placeNameId);
void loadMonthToStrbuf(WordSet *wordSet, u32 index, u32 month);
void func_0202437c(WordSet *wordSet, u32 index, const StrBuf *strbuf, u32 a3, u32 a4, u32 a5);

// How WordSetNumber pads a number to its digits
#define NUM_PAD_NONE 0
#define NUM_PAD_ZERO 2

void WordSetNumber(WordSet *wordSet, u32 index, s32 number, u32 digits, u32 pad, u32 a5);

#endif // POKEBW2_GFL_STR_H
