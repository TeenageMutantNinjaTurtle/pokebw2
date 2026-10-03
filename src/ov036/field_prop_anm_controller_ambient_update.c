#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropAnmController_Ambient_Update(void *controller, void *instance) {
    s32 i;

    for (i = 0; i < 4; i++) {
        GFL_G3DActorStepAnmFrameLoop(*(G3DActor **)instance, i, FX32_ONE);
    }
}
