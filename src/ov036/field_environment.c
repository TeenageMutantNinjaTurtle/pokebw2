#include "field/field_environment.h"
#include "field/field_internal.h"
#include "field/field_map.h"

void *Field_GetLightSystem(Field *field) {
    return field->lightSystem;
}

FieldFog *Field_GetFog(Field *field) {
    return field->fog;
}

void *Field_GetFogCtrl(Field *field) {
    return field->fogCtrl;
}

void *Field_GetWeatherSystem(Field *field) {
    return field->weatherSystem;
}

u32 Field_GetWeatherForZone(Field *field, u16 zoneId) {
    return GetWeatherAll(field->gameSystem, zoneId);
}
