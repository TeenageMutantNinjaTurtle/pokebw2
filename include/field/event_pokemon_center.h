#ifndef POKEBW2_FIELD_EVENT_POKEMON_CENTER_H
#define POKEBW2_FIELD_EVENT_POKEMON_CENTER_H

#include "types.h"
#include "struct_decls.h"

// Partial layout for the healing machine's animation state.
struct EventPokeCenHealData {
    u8 unk00[0x14];
    u8 ballCount;
    u8 animationCount;
    u8 unk16[2];
    FieldChunkPropHolder *propHolder;
    FieldPropHandle *ballHandles[6];
    void *centerProp;
};

void EventPokeCenHeal_StartAnimations(EventPokeCenHealData *work);
void EventPokeCenHeal_PauseAnimation(EventPokeCenHealData *work);
BOOL EventPokeCenHeal_IsAnimationDone(EventPokeCenHealData *work);

#endif // POKEBW2_FIELD_EVENT_POKEMON_CENTER_H
