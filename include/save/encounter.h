#ifndef POKEBW2_SAVE_ENCOUNTER_H
#define POKEBW2_SAVE_ENCOUNTER_H

#include "types.h"
#include "struct_decls.h"

u32 EncountSave_GetRoamingPkmZoneClock(EncountSave *save);
void EncountSave_RerollSwarmLocation(SaveControl *save);
u16 func_0200dd38(EncountSave *save, u8 index);
// Marks the special Pokémon of the index caught
void SetNPokeCaught(EncountSave *save, u8 index);
void EncountSave_SetRepelSteps(EncountSave *save, u8 steps);
BOOL EncountSave_IsRepelDepleted(EncountSave *save);
// Sets the repel that was used last
void func_0200ddf0(EncountSave *save, u16 item);

#endif // POKEBW2_SAVE_ENCOUNTER_H
