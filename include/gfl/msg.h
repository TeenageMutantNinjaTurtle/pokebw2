#ifndef POKEBW2_GFL_MSG_H
#define POKEBW2_GFL_MSG_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Loads a file of a message archive. With preload set, all its text is read at once
MsgData *GFL_MsgSysLoadData(BOOL preload, u32 arcId, u32 fileId, HeapID heapId);
void GFL_MsgDataFree(MsgData *msgData);

Font *GFL_FontCreate(u32 arcId, u32 fileId, u32 a2, u32 a3, HeapID heapId);
void GFL_FontFree(Font *font);

// Both call GFL_TextRndUpdateColorIndexLUT(1, 2, 0)
void func_020232d0(void);
void func_020232d8(void);

#endif // POKEBW2_GFL_MSG_H
