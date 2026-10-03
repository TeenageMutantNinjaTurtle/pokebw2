#ifndef POKEBW2_GFL_MSG_H
#define POKEBW2_GFL_MSG_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

// Message files (msgdata.c): a block of messages for each language, encrypted with a key from each message's ID.

// Loads a file of a message archive. With preload set, all its text is read at once, and otherwise each message is
// read from the archive when it is loaded
MsgData *GFL_MsgSysLoadData(BOOL preload, u32 arcId, u32 fileId, HeapID heapId);
// The same over a whole message file already in memory, which stays the caller's
MsgData *GFL_MsgDataCreateFromHandle(void *file, HeapID heapId);
void GFL_MsgDataFree(MsgData *msgData);
// Loads a message to a buffer, or to a new one, which is cleared if there is no such message
void GFL_MsgDataLoadStrbuf(MsgData *msgData, u32 messageId, StrBuf *strbuf);
StrBuf *GFL_MsgDataLoadStrbufNew(MsgData *msgData, u32 messageId);
u32 GFL_MsgDataGetLineCount(MsgData *msgData);
// Loads up to size characters of a message, and the terminator after them
void GFL_MsgDataLoadRawStr(MsgData *msgData, u32 messageId, u16 *dest, u32 size);
// The language that messages are read in, which is the kana or kanji choice in the Japanese version
void GFL_MsgDataSetDefaultLangID(u8 langId);
u8 GFL_MsgDataGetDefaultLangID(void);

Font *GFL_FontCreate(u32 arcId, u32 fileId, u32 a2, u32 a3, HeapID heapId);
void GFL_FontFree(Font *font);
// The width in pixels of a string's widest line
s32 GFL_FontGetBlockWidth(const StrBuf *strbuf, Font *font, u32 spacing);

void GFL_TextRndUpdateColorIndexLUT(u8 a0, u8 a1, u8 a2);
// Both call GFL_TextRndUpdateColorIndexLUT(1, 2, 0)
void func_020232d0(void);
void func_020232d8(void);

#endif // POKEBW2_GFL_MSG_H
