#ifndef POKEBW2_SAVE_ENCOUNTER_H
#define POKEBW2_SAVE_ENCOUNTER_H

#include "types.h"
#include "struct_decls.h"

u32 EncountSave_GetRoamingPkmZoneClock(EncountSave *save);
void EncountSave_RerollSwarmLocation(SaveControl *save);
u16 func_0200dd38(EncountSave *save, u8 index);

#endif // POKEBW2_SAVE_ENCOUNTER_H
