#ifndef POKEBW2_SAVE_JOIN_AVENUE_H
#define POKEBW2_SAVE_JOIN_AVENUE_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

JoinAvenuePersonList *JoinAvenuePersonList_Create(HeapID heapId, u32 count);
void JoinAvenuePersonList_Free(JoinAvenuePersonList *list);
JoinAvenuePerson *JoinAvenuePersonList_Get(JoinAvenuePersonList *list, u32 index);
u32 JoinAvenuePersonList_GetCount(JoinAvenuePersonList *list);
BOOL JoinAvenuePerson_IsEmpty(JoinAvenuePerson *person);
void JoinAvenuePerson_SetParam(JoinAvenuePerson *person, u32 param, u32 value);
JoinAvenueInfo *JoinAvenue_GetInfo(JoinAvenueSave *joinAvenue);
u32 JoinAvenue_GetParam(JoinAvenueInfo *info, u32 param, u32 a2);
JoinAvenuePersonList *JoinAvenue_GetPersonList(JoinAvenueSave *joinAvenue);
void func_02038bc8(u32 a0);

#endif // POKEBW2_SAVE_JOIN_AVENUE_H
