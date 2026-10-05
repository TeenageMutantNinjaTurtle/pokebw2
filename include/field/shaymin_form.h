#ifndef POKEBW2_FIELD_SHAYMIN_FORM_H
#define POKEBW2_FIELD_SHAYMIN_FORM_H

// Overlay 12's shaymin_form.c (a descriptive name): the forms that change with time

#include "types.h"
#include "nitro/rtc.h"
#include "struct_decls.h"

// Changes the forms of the party's Pokémon that the minutes passed and the time change
void func_ov012_02164384(GameData *gameData, PokeParty *party, s32 minutes, const RTCTime *time, u8 season);

#endif // POKEBW2_FIELD_SHAYMIN_FORM_H
