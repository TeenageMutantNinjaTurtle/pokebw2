#ifndef POKEBW2_FIELD_FIELD_DAYCARE_H
#define POKEBW2_FIELD_FIELD_DAYCARE_H

#include "types.h"
#include "struct_decls.h"

DayCareSave *Field_GetDayCare(Field *field);
BOOL DayCare_CheckSpawnFlag(DayCareSave *dayCare);
void DayCare_Breed(DayCareSave *dayCare, PokeParty *party);
void DayCare_CheckResetSeed(DayCareSave *dayCare);
GameEvent *EventDayCarePokeSelect_Create(GameSystem *gsys, Field *field, u16 *result);
void DayCare_AddPkm(DayCareSave *dayCare, PokeParty *party, u32 slot);
void DayCare_RemovePkm(DayCareSave *dayCare, u32 slot, PokeParty *party);
u32 DayCare_GetPkmCount(DayCareSave *dayCare);
u32 DayCare_CalcEggSpawnChance(DayCareSave *dayCare);
PartyPkm *DayCare_GetPkm(DayCareSave *dayCare, u32 slot);
u32 DayCare_CalcNewLevel(DayCareSave *dayCare, u32 slot);
u32 DayCare_CalcLevelGain(DayCareSave *dayCare, u32 slot);
u32 DayCare_CalcWithdrawCost(DayCareSave *dayCare, u32 slot);
u32 getNameGenderStatus(PartyPkm *pkm);

#endif // POKEBW2_FIELD_FIELD_DAYCARE_H
