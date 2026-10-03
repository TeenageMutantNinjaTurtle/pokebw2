#ifndef POKEBW2_FIELD_DAY_CARE_H
#define POKEBW2_FIELD_DAY_CARE_H

#include "types.h"
#include "struct_decls.h"

DayCareSave *Field_GetDayCare(Field *field);
BOOL DayCare_CheckSpawnFlag(DayCareSave *dayCare);
void DayCare_Breed(DayCareSave *dayCare, PokeParty *party);
void DayCare_CheckResetSeed(DayCareSave *dayCare);

#endif // POKEBW2_FIELD_DAY_CARE_H
