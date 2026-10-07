#ifndef POKEBW2_APP_MUSICAL_STA_ACTING_H
#define POKEBW2_APP_MUSICAL_STA_ACTING_H

// Overlay 209's sta_acting.c: the musical's stage, which plays the program's script with the Pokémon, the
// background, the objects, the lights, the effects and the audience. Declared for its callers before the file is
// decompiled

#include "types.h"
#include "struct_decls.h"

StaActPokeSys *StaActing_GetPokeSys(StaActing *stage);
StaActPoke *StaActing_GetPoke(StaActing *stage, u8 pos);
// How far the stage has scrolled, in pixels
u16 StaActing_GetScrollOffset(StaActing *stage);
// The position of the Pokémon the spotlight follows, or 4 for none
u8 StaActing_GetLightUpPoke(StaActing *stage);
StaActEffectSys *StaActing_GetEffectSys(StaActing *stage);
// How many times the props' effects run this frame
u32 StaActing_GetUpdateCount(StaActing *stage);
StaActLightSys *StaActing_GetLightSys(StaActing *stage);
StaActLight *StaActing_GetLight(StaActing *stage, u8 index);
// A state of the stage, during which (when not 0) the audience follows the Pokémon
u16 func_ov209_021c032c(StaActing *stage);

#endif // POKEBW2_APP_MUSICAL_STA_ACTING_H
