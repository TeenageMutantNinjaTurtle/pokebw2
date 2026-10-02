#include "field/field_internal.h"

G3DMapper *Field_GetG3DMapper(Field *field) {
    return field->g3DMapper;
}

u16 Field_GetPlayerStateZoneID(Field *field) {
    return field->playerStateZoneId;
}
