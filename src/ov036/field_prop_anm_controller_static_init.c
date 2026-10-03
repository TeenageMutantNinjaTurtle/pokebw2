#include "field/field_prop.h"

void FieldPropAnmController_Static_Init(FieldPropSystem *system, FieldPropResInstance *instance) {
    s32 i;
    u32 state;

    i = 0;
    state = 0;
    for (; i < 4; i++) {
        instance->animationState[i] = state;
    }
}
