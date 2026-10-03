#ifndef POKEBW2_FIELD_DAY_CARE_H
#define POKEBW2_FIELD_DAY_CARE_H

#include "types.h"
#include "struct_decls.h"

DayCareSave *Field_GetDayCare(Field *field);
BOOL DayCare_CheckSpawnFlag(DayCareSave *dayCare);
void DayCare_Breed(DayCareSave *dayCare, PokeParty *party);
void DayCare_CheckResetSeed(DayCareSave *dayCare);
u32 DayCare_GetPkmCount(DayCareSave *dayCare);
u32 DayCare_CalcEggSpawnChance(DayCareSave *dayCare);
PartyPkm *DayCare_GetPkm(DayCareSave *dayCare, u32 slot);
u32 DayCare_CalcNewLevel(DayCareSave *dayCare, u32 slot);
u32 DayCare_CalcLevelGain(DayCareSave *dayCare, u32 slot);
u32 DayCare_CalcWithdrawCost(DayCareSave *dayCare, u32 slot);
u32 getNameGenderStatus(PartyPkm *pkm);

#endif // POKEBW2_FIELD_DAY_CARE_H
