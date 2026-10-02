#include "field/field_effects.h"
#include "field/field_internal.h"

void *Field_GetEffectBlAct(Field *field) {
    return field->effectBlAct;
}

void *Field_GetWildEffectBlAct(Field *field) {
    return field->wildEffectBlAct;
}
