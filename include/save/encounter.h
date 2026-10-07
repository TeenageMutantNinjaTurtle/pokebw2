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
// Sets the repel that was used last
void func_0200ddf0(EncountSave *save, u16 item);
BOOL IsNPokeAlreadyCaught(EncountSave *save, u8 index);
int GetAlreadyCaughtNPokeCount(EncountSave *save);
// Whether the repel has run out
BOOL EncountSave_IsRepelDepleted(EncountSave *save);
// The Repel that was used last
u16 EncountSave_GetUsedRepelItemID(EncountSave *save);
// The swarm's location, an index of overlay 36's swarm table
u8 EncountSave_GetSwarmLocation(EncountSave *save);
// The roaming Pokémon of the slot, whether it roams, and its parameters
BOOL EncountSave_GetRoamingPkmStatus(EncountSave *save, u8 slot);
void *EncountSave_GetRoamingPkm(EncountSave *save, u8 slot);
u32 EncountSave_GetRoamingPkmParam(void *roamingPkm, u32 param);

#endif // POKEBW2_SAVE_ENCOUNTER_H
