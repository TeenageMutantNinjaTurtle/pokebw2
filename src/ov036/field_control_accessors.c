#include "field/field_controller.h"
#include "field/field_internal.h"
#include "field/field_player.h"

void *Field_GetController(Field *field) {
    return field->controller;
}

void Field_SetController(Field *field, void *controller) {
    field->controller = controller;
}

FieldPlayer *Field_GetPlayer(Field *field) {
    return field->player;
}

BOOL Field_HasPlayer(Field *field) {
    return field->player != NULL;
}
