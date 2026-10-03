#ifndef POKEBW2_FIELD_EVENT_ABYSSAL_RUINS_H
#define POKEBW2_FIELD_EVENT_ABYSSAL_RUINS_H

// Function and data names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

extern const u16 ABYSSAL_RUINS_DULL_SOUND_SCRIPTS[];
extern const u16 data_ov033_0217c522[];

GameEvent *CheckAbyssalRuinsStepEvent(GameSystem *gsys, Field *field);

#endif // POKEBW2_FIELD_EVENT_ABYSSAL_RUINS_H
