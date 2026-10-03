#ifndef POKEBW2_FIELD_PC_SOUND_H
#define POKEBW2_FIELD_PC_SOUND_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "system/game_event.h"

struct PCSoundEventData {
    GameSystem *gameSystem;
    Field *field;
    FieldChunkPropHolder *volatile pcProp;
    u32 unkC;
    u32 skipSound;
};

GameEventReturnCode pcEntrySound(GameEvent *event, u32 *state, void *data);
GameEvent *CreatePCSoundCallEvent(GameEvent *parent, GameSystem *gsys, Field *field);
GameEventReturnCode pcLogOffSound(GameEvent *event, u32 *state, void *data);

#endif // POKEBW2_FIELD_PC_SOUND_H
