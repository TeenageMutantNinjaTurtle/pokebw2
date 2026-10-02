#include "field/field_internal.h"
#include "field/field_visuals.h"

FieldSubscreen *Field_GetSubscreen(Field *field) {
    return field->subscreen;
}

void *Field_GetFieldEffects(Field *field) {
    return field->fieldEffects;
}

void *Field_GetG3DObjSys(Field *field) {
    return field->g3DObjSystem;
}
