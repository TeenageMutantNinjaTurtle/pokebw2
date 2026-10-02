#ifndef POKEBW2_FIELD_FIELD_ENVIRONMENT_H
#define POKEBW2_FIELD_FIELD_ENVIRONMENT_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

void *Field_GetLightSystem(Field *field);
void *Field_GetFogCtrl(Field *field);
void *Field_GetWeatherSystem(Field *field);
u8 Field_GetWeatherForZone(Field *field, u16 zoneId);

#endif // POKEBW2_FIELD_FIELD_ENVIRONMENT_H
