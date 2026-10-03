#ifndef POKEBW2_FIELD_FIELD_CONTROLLER_H
#define POKEBW2_FIELD_FIELD_CONTROLLER_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

void *Field_GetController(Field *field);
void Field_SetController(Field *field, void *controller);
u32 Field_GetControllerTypeID(Field *field);

#endif // POKEBW2_FIELD_FIELD_CONTROLLER_H
