#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropResInstance_Free(void *argument) {
    FieldPropResInstance *instance;
    G3DModel *model;
    void *animation;
    s32 count;
    s32 i;

    instance = argument;
    if (instance->actor != NULL) {
        count = GFL_G3DActorGetAnmCount(instance->actor);
        for (i = 0; i < count; i++) {
            animation = GFL_G3DActorGetAnm(instance->actor, i);
            if (animation != NULL) {
                GFL_G3DAnmFree(animation);
            }
        }
        model = GFL_G3DActorGetMdl(instance->actor);
        GFL_G3DActorFree(instance->actor);
        instance->actor = NULL;
        instance->resInfoRef = NULL;
        GFL_G3DMdlFree(model);
    }
}
