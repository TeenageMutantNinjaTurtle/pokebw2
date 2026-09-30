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

// The gimmick's work, whichever of its two layouts the field has
ResortPeople *func_ov137_021eeeac(Field *field);
void *func_ov137_021eeebc(Field *field);
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
void func_ov137_021f1748(void *a0);
u16 func_ov137_021f1878(ResortPersonData *data, void *a1, void *a2, JoinAvenueInfo *info);

// resort_data_manager.c
void func_ov137_021f1950(ResortPersonData *data);
u32 func_ov137_021f1968(ResortPersonData *data, JoinAvenuePersonParam param, void *buffer);
void func_ov137_021f1974(ResortPersonData *data, JoinAvenuePersonParam param, u32 value);
JoinAvenuePerson *func_ov137_021f1980(ResortPersonData *data);
u32 func_ov137_021f1984(ResortPersonData *data);
u32 func_ov137_021f198c(ResortPersonData *data);
u32 func_ov137_021f1990(ResortPersonData *data, u32 a1, u32 a2);
u32 func_ov137_021f199c(ResortPersonData *data, ResortPersonData *other, u32 a2, u32 a3);
ResortPersonData *func_ov137_021f1b94(void *a0, u32 a1, u16 a2);
ResortPersonData *func_ov137_021f1ba8(void *a0, u32 a1, u32 a2);
// The data of a person, among what func_ov137_021f2014 returns
ResortPersonData *func_ov137_021f1b6c(void *a0, JoinAvenuePerson *person);

// resort_npc.c
void func_ov137_021f1d04(void *a0, u32 a1);
u16 func_ov137_021f1d60(void *a0, u32 a1, u32 a2);
u16 func_ov137_021f1f00(void *a0, u32 a1);

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
