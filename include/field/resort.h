#ifndef POKEBW2_FIELD_RESORT_H
#define POKEBW2_FIELD_RESORT_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "save/join_avenue.h"
#include "struct_decls.h"

// The Join Avenue's gimmick, overlay 137, whose files are resort_field.c, resort_people.c, resort_data_manager.c,
// resort_npc.c and resort_sys.c. Script plugin 8 (overlays 58 to 60) drives it. The objects are named after the file
// they come from: the system of resort_sys.c, and the people of resort_people.c, each with its data, which reads and
// writes its fields through a table of functions

typedef struct ResortSys ResortSys;
typedef struct ResortPeople ResortPeople;
typedef struct ResortPerson ResortPerson;
typedef struct ResortPersonData ResortPersonData;
typedef struct ResortNPC ResortNPC;
typedef struct ResortSlots ResortSlots;

// What the gimmick's system is created with
typedef struct {
    JoinAvenueOccupants *occupants;
    JoinAvenuePersonList *list;
    // A second list, or NULL
    JoinAvenuePersonList *list2;
    // The twelve entries of func_02037f04
    void *entries;
    JoinAvenueInfo *info;
} ResortSysSetup;

// A walk through the data of a list of kinds, for func_ov137_021f1ae0 and func_ov137_021f1b0c
typedef struct {
    u16 kindIndex;
    u16 pos;
} ResortDataIter;

// What the avenue's NPCs are created with
typedef struct {
    MMSys *mmSys;
    u32 unk4;
    // The index of the avenue's zone, for func_0203950c
    u32 zone;
    JoinAvenueInfo *info;
    // The NPCs' table, of func_020395ac
    void *table;
} ResortNPCSetup;

// The gimmick's work, whichever of its two layouts the field has
ResortPeople *func_ov137_021eeeac(Field *field);
ResortNPC *func_ov137_021eeebc(Field *field);
ResortSys *func_ov137_021eeec8(Field *field);
void func_ov137_021eeed4(Field *field, ResortPerson *person);
void func_ov137_021eeee8(Field *field, u32 a1);
u32 func_ov137_021eeefc(Field *field, u32 a1);
void func_ov137_021eef10(Field *field, u32 a1);
void func_ov137_021eef24(Field *field);
void func_ov137_021eef3c(Field *field);
void func_ov137_021eef4c(Field *field);
void func_ov137_021eef68(Field *field, u32 a1);
ResortPeople *func_ov137_021f0e74(Field *field);
ResortSys *func_ov137_021f0e80(Field *field);
void *func_ov137_021f0e8c(Field *field);

// resort_people.c
JoinAvenuePerson *func_ov137_021f0f58(ResortPerson *person);
void func_ov137_021f0f84(ResortPerson *person, u32 value);
void *func_ov137_021f0fa8(ResortPerson *person);
void func_ov137_021f0fb8(ResortPerson *person);
void func_ov137_021f1020(ResortPerson *person, u16 *a1, u16 *a2, u16 *a3);
void func_ov137_021f10dc(ResortPerson *person, JoinAvenuePersonParam param, u32 value);
u32 func_ov137_021f10e8(ResortPerson *person, JoinAvenuePersonParam param, void *buffer);
u32 func_ov137_021f10f4(ResortPerson *person, u32 which);
ResortPersonData *func_ov137_021f1110(ResortPerson *person);
u32 func_ov137_021f134c(ResortPeople *people);
ResortPerson *func_ov137_021f14a8(ResortPeople *people, void *a1);
void func_ov137_021f152c(ResortPeople *people);
void func_ov137_021f1554(ResortPeople *people, ResortPerson *person);
void func_ov137_021f15ac(ResortPeople *people, ResortPerson *person);
ResortPerson *func_ov137_021f15cc(ResortPeople *people, FieldActor *actor);
ResortPerson *func_ov137_021f1600(ResortPeople *people, JoinAvenuePerson *person);
ResortPerson *func_ov137_021f1634(ResortPeople *people, u32 index);
ResortPerson *func_ov137_021f163c(ResortPeople *people, ResortPersonData *data);

// resort_data_manager.c. The data of the avenue's people and records, 40 of them, for kinds 0 to 4: the eight
// occupants, the four records, the eight of each list and the twelve entries. Each calls the functions of its type
ResortSlots *func_ov137_021f1710(ResortPersonData **datas, HeapID heapId);
void func_ov137_021f1740(ResortSlots *slots);
// Places each data that is not empty in the slot of its params 0 and 1, the slot and the row (1 or 2)
void func_ov137_021f1748(ResortSlots *slots);
u16 func_ov137_021f17ec(u32 kind);
u32 func_ov137_021f17fc(u32 kind);
// Whether a slot of a row is empty, the data in it, and the first empty one (0xffff if none)
BOOL func_ov137_021f1808(ResortSlots *slots, u32 row, u32 pos);
ResortPersonData *func_ov137_021f1824(ResortSlots *slots, u32 row, u32 pos);
u16 func_ov137_021f184c(ResortSlots *slots, u32 row);
u16 func_ov137_021f1878(ResortPersonData *data, void *a1, void *a2, JoinAvenueInfo *info);
ResortPersonData *func_ov137_021f18f0(HeapID heapId, void *person, u32 kind, u16 index);
void func_ov137_021f1920(ResortPersonData *data);
void func_ov137_021f1950(ResortPersonData *data);
BOOL func_ov137_021f195c(ResortPersonData *data);
u32 func_ov137_021f1968(ResortPersonData *data, JoinAvenuePersonParam param, void *buffer);
void func_ov137_021f1974(ResortPersonData *data, JoinAvenuePersonParam param, u32 value);
JoinAvenuePerson *func_ov137_021f1980(ResortPersonData *data);
u32 func_ov137_021f1984(ResortPersonData *data);
u32 func_ov137_021f1988(ResortPersonData *data);
u32 func_ov137_021f198c(ResortPersonData *data);
u32 func_ov137_021f1990(ResortPersonData *data, u32 a1, u32 a2);
u32 func_ov137_021f199c(ResortPersonData *data, ResortPersonData *other, u32 a2, u32 a3);
ResortPersonData **func_ov137_021f19c4(const ResortSysSetup *setup, HeapID heapId);
void func_ov137_021f1ac0(ResortPersonData **datas);
ResortDataIter func_ov137_021f1ae0(ResortPersonData **datas, const u32 *kinds, u32 count);
// The next data of the kinds, or NULL
ResortPersonData *func_ov137_021f1b0c(ResortPersonData **datas, ResortDataIter *iter, const u32 *kinds, u32 count);
// The data of a person, among what func_ov137_021f2014 returns
ResortPersonData *func_ov137_021f1b6c(ResortPersonData **datas, JoinAvenuePerson *person);
ResortPersonData *func_ov137_021f1b94(ResortPersonData **datas, u32 kind, u16 index);
// The same for the scripts' numbering of the kinds: 0 the occupants, 1 the entries, 2 the people of both lists and 3
// the records
ResortPersonData *func_ov137_021f1ba8(ResortPersonData **datas, u32 which, u16 index);
// The first empty data of a kind, or NULL
ResortPersonData *func_ov137_021f1bd0(ResortPersonData **datas, u32 kind);

// resort_npc.c
ResortNPC *func_ov137_021f1c24(const ResortNPCSetup *setup, HeapID heapId);
void func_ov137_021f1c74(ResortNPC *npc);
// Stops the NPCs' movement while an event is running
void func_ov137_021f1c88(ResortNPC *npc, Field *field);
// The actor of an NPC, or NULL
FieldActor *func_ov137_021f1cc8(ResortNPC *npc, u32 index);
// The number of NPCs created
u32 func_ov137_021f1d00(ResortNPC *npc);
void func_ov137_021f1d04(ResortNPC *npc, BOOL visible);
// A column of an NPC's row of texts
u16 func_ov137_021f1d60(ResortNPC *npc, u32 row, u32 column);
u16 func_ov137_021f1f00(ResortNPC *npc, u32 row);

// resort_sys.c
void *func_ov137_021f1ff8(ResortSys *sys);
void *func_ov137_021f2000(ResortSys *sys);
void *func_ov137_021f2008(ResortSys *sys);
void *func_ov137_021f200c(ResortSys *sys);
void *func_ov137_021f2014(ResortSys *sys);
void *func_ov137_021f2018(ResortSys *sys);
JoinAvenueOccupants *func_ov137_021f201c(ResortSys *sys);
JoinAvenueInfo *func_ov137_021f202c(ResortSys *sys);
u32 *func_ov137_021f2030(ResortSys *sys);
u16 func_ov137_021f2040(u32 a0, ResortSys *sys, ResortPersonData *data, GameData *gameData, WordSet *wordSet,
                        HeapID heapId);
u16 func_ov137_021f2fd0(ResortPersonData *data, JoinAvenuePerson *person, ResortSys *sys, u16 *a3, u16 *a4,
                        u16 *a5);
u16 func_ov137_021f312c(ResortSys *sys, GameData *gameData, u32 a2, u16 *a3);
u16 func_ov137_021f3238(JoinAvenuePerson *person, ResortSys *sys, u32 a2, u16 *a3);
u32 func_ov137_021f3344(ResortSys *sys);
u32 func_ov137_021f3354(ResortSys *sys);
void func_ov137_021f33b8(u32 a0, u32 a1, u32 a2, u32 a3, ResortSys *sys, ResortPerson *person, WordSet *wordSet,
                         GameData *gameData, HeapID heapId);
void *func_ov137_021f3e7c(void *msgBGSys, HeapID heapId);
void func_ov137_021f3e98(void *a0, JoinAvenueOccupants *occupants, void *msgBGSys, WordSet *wordSet,
                         GameData *gameData, s16 a5, HeapID heapId);
u32 func_ov137_021f420c(ResortSys *sys, GameData *gameData);
u32 func_ov137_021f4294(ResortSys *sys, GameData *gameData, u32 a2);
u16 func_ov137_021f44ac(void *a0, ResortPersonData *data, u32 a2);
void func_ov137_021f44f8(ResortPeople *people, void *a1, Field *field, ResortPerson *person, u32 a4);
ResortSys *func_ov137_021f4670(Field *field);
// The person of the script's actor
ResortPerson *func_ov137_021f4690(FieldScriptEnv *env, ResortPeople *people);
StrBuf *func_ov137_021f4930(void *shops, ResortPersonData *data, u16 a2, HeapID heapId);
u16 func_ov137_021f46a8(ResortSys *sys, ResortPersonData *data, u32 a2);
void func_ov137_021f4dbc(ResortSys *sys, PlayerInfo *playerInfo, u32 a2, u32 a3, HeapID heapId);
void func_ov137_021f4ecc(ResortSys *sys, ResortPersonData *a1, ResortPersonData *data);
BOOL func_ov137_021f4fa4(ResortSys *sys, ResortPersonData *a1, ResortPersonData *data, u32 *a3);
u32 func_ov137_021f50f4(ResortSys *sys, ResortPersonData *a1);
u32 func_ov137_021f51a4(ResortSys *sys, ResortPersonData *a1);
void func_ov137_021f5200(ResortSys *sys, ResortPersonData *a1, u32 a2);
u16 func_ov137_021f522c(ResortSys *sys, GameData *gameData, u32 a2);
// Whether all eight of the avenue's people are there
BOOL func_ov137_021f5294(ResortSys *sys);

#endif // POKEBW2_FIELD_RESORT_H
