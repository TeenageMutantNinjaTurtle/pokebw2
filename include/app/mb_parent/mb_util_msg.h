#ifndef POKEBW2_APP_MB_PARENT_MB_UTIL_MSG_H
#define POKEBW2_APP_MB_PARENT_MB_UTIL_MSG_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The messages, windows and menus of the DS Download Play parent (mb_util_msg.c)

MBUtilMsg *func_ov181_0219fc0c(HeapID heapId, u8 msgBg, u8 menuBg, u16 fileId, u32 a4, u32 a5);
void func_ov181_0219fd28(MBUtilMsg *msg);
void func_ov181_0219fdc0(MBUtilMsg *msg);
void func_ov181_0219fe70(MBUtilMsg *msg, u32 window);
void func_ov181_0219ff4c(MBUtilMsg *msg, u32 msgId, s32 textSpeed);
void func_ov181_021a0028(MBUtilMsg *msg, u32 msgId);
void func_ov181_021a00e0(MBUtilMsg *msg);
void func_ov181_021a0120(MBUtilMsg *msg);
void func_ov181_021a0134(MBUtilMsg *msg);
void func_ov181_021a0148(MBUtilMsg *msg, u32 index, u32 number, u32 digits);
void func_ov181_021a0160(MBUtilMsg *msg, u32 index, u32 number, u32 digits);
void func_ov181_021a0178(MBUtilMsg *msg, u32 a1);
void func_ov181_021a0200(MBUtilMsg *msg);
int func_ov181_021a0210(MBUtilMsg *msg);
void func_ov181_021a022c(MBUtilMsg *msg, u32 a1);
void func_ov181_021a026c(MBUtilMsg *msg);
int func_ov181_021a0274(MBUtilMsg *msg);
void func_ov181_021a02a0(MBUtilMsg *msg, s32 textSpeed);
MsgData *func_ov181_021a0344(MBUtilMsg *msg);
WordSet *func_ov181_021a0348(MBUtilMsg *msg);
Font *func_ov181_021a034c(MBUtilMsg *msg);
BOOL func_ov181_021a0350(MBUtilMsg *msg);
BOOL func_ov181_021a035c(MBUtilMsg *msg);
void func_ov181_021a036c(MBUtilMsg *msg, u32 a1);
void func_ov181_021a0380(MBUtilMsg *msg, u32 a1);

#endif // POKEBW2_APP_MB_PARENT_MB_UTIL_MSG_H
