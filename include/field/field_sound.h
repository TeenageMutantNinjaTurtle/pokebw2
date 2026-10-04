#ifndef POKEBW2_FIELD_FIELD_SOUND_H
#define POKEBW2_FIELD_FIELD_SOUND_H

#include "types.h"
#include "struct_decls.h"

u32 FieldSnd_BGMGetStackIndex(FieldSound *fieldSound);
void FieldSnd_ChangeZoneBGM(FieldSound *fieldSound, GameData *gameData, u16 zoneId);

#endif // POKEBW2_FIELD_FIELD_SOUND_H
