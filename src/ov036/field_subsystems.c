#include "field/festival.h"
#include "field/field_async_proc.h"
#include "field/field_internal.h"

PlaceName *Field_GetPlaceName(Field *field) {
    return field->placeName;
}

void *Field_GetFesGimmick(Field *field) {
    return field->fesGimmick;
}

FieldAsyncProcManager *Field_GetAsyncProcMgr(Field *field) {
    return field->asyncProcManager;
}
