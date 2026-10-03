#include "field/field_prop.h"

BOOL FieldPropResInstance_IsAnmIdle(void *argument, u32 animation) {
    FieldPropResInstance *instance;
    u8 index;

    instance = argument;
    index = animation;
    if (index >= 4) {
        index = 0;
    }
    switch (instance->animationState[index]) {
    case 0:
        return TRUE;
    case 1:
        return FALSE;
    case 2:
        return TRUE;
    case 3:
    case 4:
        return FALSE;
    default:
        break;
    }
    return FALSE;
}
