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

#endif // POKEBW2_APP_MUSICAL_STA_ACTING_H
