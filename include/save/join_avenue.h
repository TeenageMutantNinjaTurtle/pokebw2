#ifndef POKEBW2_SAVE_JOIN_AVENUE_H
#define POKEBW2_SAVE_JOIN_AVENUE_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// A field of a person, which joinAveTextHandler reads and JoinAvenuePerson_SetParam writes, as overlay 137's people
// do through their data
typedef enum {
    JOIN_AVE_PARAM_NAME = 4,
    JOIN_AVE_PARAM_COUNTRY = 8,
    JOIN_AVE_PARAM_AREA = 9,
    JOIN_AVE_PARAM_JOB = 12,
    JOIN_AVE_PARAM_HOBBY = 13,
} JoinAvenuePersonParam;

JoinAvenuePersonList *JoinAvenuePersonList_Create(HeapID heapId, u32 count);
void JoinAvenuePersonList_Free(JoinAvenuePersonList *list);
JoinAvenuePerson *JoinAvenuePersonList_Get(JoinAvenuePersonList *list, u32 index);
u32 JoinAvenuePersonList_GetCount(JoinAvenuePersonList *list);
BOOL JoinAvenuePerson_IsEmpty(JoinAvenuePerson *person);
void JoinAvenuePerson_SetParam(JoinAvenuePerson *person, JoinAvenuePersonParam param, u32 value);
JoinAvenueInfo *JoinAvenue_GetInfo(JoinAvenueSave *joinAvenue);
u32 JoinAvenue_GetParam(JoinAvenueInfo *info, u32 param, u32 a2);
JoinAvenuePersonList *JoinAvenue_GetPersonList(JoinAvenueSave *joinAvenue);
void func_02038bc8(u32 a0);
// Sets a field of the info
void func_02039064(JoinAvenueInfo *info, u32 param, u32 value);

// A person's fields. joinAveTextHandler reads one, into the buffer for a name
u32 joinAveTextHandler(JoinAvenuePerson *person, JoinAvenuePersonParam param, void *buffer);
BOOL func_02036e4c(JoinAvenuePerson *person, u32 bit);
void *func_02038470(JoinAvenuePerson *person);
u32 func_02038a20(JoinAvenuePerson *person, PlayerInfo *playerInfo);
// The flags at 0xac of a person
u32 func_020363e0(void *flags, u32 which);
void func_0203640c(void *flags, u32 which, u32 value);
BOOL func_02036434(void *flags, u32 bit);
void func_02036448(void *flags, u32 bit, BOOL set);

// The avenue's people: 8 of 0xc4 bytes, then 4 of 0x58 bytes, and the player's own entry at 0x780
JoinAvenueOccupants *getAddressOfBeginningOfOccupants(JoinAvenueSave *joinAvenue);
JoinAvenuePerson *func_02038860(JoinAvenueOccupants *occupants, u32 index);
// The number of the eight people who are there
u32 func_02038868(JoinAvenueOccupants *occupants);
void *func_0203888c(JoinAvenueOccupants *occupants, u32 index);
// The number of the four records that are not empty
u32 func_0203889c(JoinAvenueOccupants *occupants);
u32 func_020388c0(JoinAvenueOccupants *occupants);
void func_02038a0c(JoinAvenueOccupants *occupants, u32 value);
JoinAvenuePerson *func_02038a18(JoinAvenueOccupants *occupants);
// The 0x58-byte records
BOOL func_020384e0(void *record);
// A field of a record, which reads into the buffer for a name, as joinAveTextHandler does for a person
u32 func_020385a8(void *record, u32 param, void *buffer);
void func_02038680(void *record, u32 param, u32 value);

// The shops' data: tables of u16 rows
u16 func_020394b0(u16 a0, u16 a1, u16 a2, u16 a3, JoinAvenueInfo *info, void *shops);
u32 func_02039518(u16 zoneId);
u16 func_020395f8(void *table, u32 row, u32 column);
u32 func_0203968c(void *table, u32 a1);
const u16 *func_02039798(void *shops, JoinAvenuePerson *person);
const u16 *func_020397b4(void *shops, u32 id);
u16 func_020397cc(const u16 *row, u32 index);
const u16 *func_020397d4(void *shops, const u16 *row, u16 index);
// The number of the row's items
u32 func_020397f8(void *shops, const u16 *row);
u16 func_0203981c(const u16 *row, u32 index);
void func_02039898(u32 *a0, SaveControl *save);
u32 join_ave_raffle_shop(void *table, u32 row, u32 a2);

#endif // POKEBW2_SAVE_JOIN_AVENUE_H
