#include "field/field.h"
#include "field/field_menu.h"
#include "field/subscreen.h"

BOOL func_ov012_0215aa74(FieldMenuWork *work, FieldMenuWork *context) {
    FieldSubscreen *subscreen = Field_GetSubscreen(context->field);

    if (work->prevScreenId == 0) {
        func_ov036_0219886c(subscreen, context->unk10);
    }
    return TRUE;
}

BOOL func_ov012_0215aa90(void) {
    return TRUE;
}
