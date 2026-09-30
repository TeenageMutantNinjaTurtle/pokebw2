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
// Copies the string out, at most size characters
void GFL_StrBufStoreString(const StrBuf *strbuf, u16 *dest, u32 size);
void GFL_StrBufLoadString(StrBuf *strbuf, const u16 *src);

WordSet *GFL_WordSetSystemCreateDefault(HeapID heapId);
void GFL_WordSetSystemFree(WordSet *wordSet);
void GFL_WordSetFormatStrbuf(WordSet *wordSet, StrBuf *dest, const StrBuf *src);
void GFL_WordSetLoadStr(WordSet *wordSet, u32 index, const u16 *str);
// Puts a Pokémon's species name in a word set
void setPartyPokemonSpeciesNameToStrbuf(WordSet *wordSet, u32 index, PartyPkm *pkm);
void loadPokemonNicknameToStrbuf(WordSet *wordSet, u32 index, PartyPkm *pkm);
void loadMoveNameToStrbuf(WordSet *wordSet, u32 index, u32 move);
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
