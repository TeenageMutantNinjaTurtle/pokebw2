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
// A field of the info, which reads into the buffer for the avenue's name
u32 JoinAvenue_GetParam(JoinAvenueInfo *info, u32 param, void *buffer);
JoinAvenuePersonList *JoinAvenue_GetPersonList(JoinAvenueSave *joinAvenue);
void func_02038bc8(u32 a0);
// Sets a field of the info
void func_02039064(JoinAvenueInfo *info, u32 param, u32 value);

// A person's fields. joinAveTextHandler reads one, into the buffer for a name
u32 joinAveTextHandler(JoinAvenuePerson *person, JoinAvenuePersonParam param, void *buffer);
// Allocates a person, frees one and clears one
JoinAvenuePerson *func_02036d94(HeapID heapId);
void func_02036db8(JoinAvenuePerson *person);
void func_02036e14(JoinAvenuePerson *person);
u32 func_020378f8(JoinAvenuePerson *person, u32 a1, u32 a2);
// The 0x60-byte entries, twelve from 4 bytes into the Join Avenue's save at 0x628, with the same functions as a
// person's
void *func_02010054(JoinAvenueSave *joinAvenue);
void *func_02037f04(void *entries, u32 index);
// The number of entries
u32 func_02037ed4(void *entries);
// Stores a person list in a global structure, if there is one; NULL clears it
void func_0202d608(JoinAvenuePersonList *list);
// Called with an entry by overlay 137, which counts a result of 2 and stops at 0
u32 func_02010078(JoinAvenueSave *joinAvenue, GameData *gameData, void *entry, u32 a3);
void *func_02037a40(HeapID heapId);
void func_02037a68(void *entry);
void func_02037ab4(void *entry, PlayerInfo *info, u16 species, u32 a3);
void func_02037a70(void *entry);
BOOL func_02037a90(void *entry);
u32 func_02037b38(void *entry, u32 param, void *buffer);
void func_02037c70(void *entry, u32 param, u32 value);
u32 func_02037e34(void *entry, u32 a1, u32 a2);
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
// The 0x58-byte records: allocated, freed and cleared as a person is
void *func_020384a4(HeapID heapId);
void func_020384cc(void *record);
void func_020384d4(void *record);
BOOL func_020384e0(void *record);
// A field of a record, which reads into the buffer for a name, as joinAveTextHandler does for a person
u32 func_020385a8(void *record, u32 param, void *buffer);
void func_02038680(void *record, u32 param, u32 value);
u32 func_020387f4(void *record, u32 a1, u32 a2);

// The shops' data: tables of u16 rows
u16 func_020394b0(u16 a0, u16 a1, u16 a2, u16 a3, JoinAvenueInfo *info, void *shops);
u32 func_02039518(u16 zoneId);
// The avenue has three zones: the zone of an index, and the index of a zone (0 if it is none of them)
u16 func_0203950c(u32 index);
// Tables of u16 rows of a number of columns, read from a file of archive 244 (resort_binary.c)
void *func_020395ac(u32 fileId, u32 columns, HeapID heapId);
void func_020395e4(void *table);
u16 func_020395f8(void *table, u32 row, u32 column);
// The number of rows
u32 func_02039608(void *table);
// A row of the table found from a1 to a3, of which column 0 matches a1, and the row's column 3
const u16 *func_02039628(void *table, u32 a1, u32 a2, u16 a3);
u16 func_02039624(const u16 *row);
// Positions on the grid and directions, from two tables of {u16 x, u16 z, u32 dir}
void func_02039538(u16 index, u16 *x, u16 *z, u16 *dir);
void func_02039578(u16 index, u16 *x, u16 *z, u16 *dir);
// The offset of a shop's entity
void func_02039560(u16 index, u16 *x, u16 *y);
u32 func_0203941c(u32 value, u32 a1, u32 a2);
u32 func_020393e4(JoinAvenueInfo *info, u32 a1, u32 a2);
u32 func_0203968c(void *table, u32 a1);
// The shops' tables, from files 1 and 2 of archive 244, and their free
void *func_020396e8(HeapID heapId);
void func_02039720(void *shops);
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
