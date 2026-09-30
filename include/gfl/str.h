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

WordSet *GFL_WordSetSystemCreateDefault(HeapID heapId);
void GFL_WordSetSystemFree(WordSet *wordSet);
void GFL_WordSetFormatStrbuf(WordSet *wordSet, StrBuf *dest, const StrBuf *src);
void GFL_WordSetLoadStr(WordSet *wordSet, u32 index, const u16 *str);
// Puts the player's name in a word set
void copyVarForText(WordSet *wordSet, u32 index, PlayerInfo *playerInfo);

#endif // POKEBW2_GFL_STR_H
