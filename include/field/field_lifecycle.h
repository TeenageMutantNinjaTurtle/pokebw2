#ifndef POKEBW2_FIELD_FIELD_LIFECYCLE_H
#define POKEBW2_FIELD_FIELD_LIFECYCLE_H

// Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

void Field_RequestClose(Field *field);
BOOL Field_CheckMapLoadFinished(Field *field);

#endif // POKEBW2_FIELD_FIELD_LIFECYCLE_H
