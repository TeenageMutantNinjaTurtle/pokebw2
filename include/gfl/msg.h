#ifndef POKEBW2_GFL_MSG_H
#define POKEBW2_GFL_MSG_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

// Loads a file of a message archive. With preload set, all its text is read at once
MsgData *GFL_MsgSysLoadData(BOOL preload, u32 arcId, u32 fileId, HeapID heapId);
void GFL_MsgDataFree(MsgData *msgData);
// The language that messages are read in, which is the kana or kanji choice in the Japanese version
u8 GFL_MsgDataGetDefaultLangID(void);
void GFL_MsgDataSetDefaultLangID(u8 langId);
void GFL_MsgDataLoadStrbuf(MsgData *msgData, u32 messageId, StrBuf *strbuf);
StrBuf *GFL_MsgDataLoadStrbufNew(MsgData *msgData, u32 messageId);

Font *GFL_FontCreate(u32 arcId, u32 fileId, u32 a2, u32 a3, HeapID heapId);
void GFL_FontFree(Font *font);
// The width in pixels of a string's widest line
s32 GFL_FontGetBlockWidth(const StrBuf *strbuf, Font *font, u32 spacing);

void GFL_TextRndUpdateColorIndexLUT(u8 a0, u8 a1, u8 a2);
// Both call GFL_TextRndUpdateColorIndexLUT(1, 2, 0)
void func_020232d0(void);
void func_020232d8(void);

#endif // POKEBW2_GFL_MSG_H
