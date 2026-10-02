#include "field/field_lifecycle.h"
#include "field/field_internal.h"

void Field_RequestClose(Field *field) {
    field->routineState = 2;
    field->routineID = 4;
}

BOOL Field_CheckMapLoadFinished(Field *field) {
    return field->routineState == 1;
}
