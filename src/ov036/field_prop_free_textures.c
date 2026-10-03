#include "field/field_prop.h"
#include "gfl/g3d.h"

void FieldPropSystem_FreeTextures(FieldPropSystem *system) {
    if (system->textureResource != NULL) {
        GFL_G3DResFreeTexData(system->textureResource);
        GFL_G3DResFree(system->textureResource);
        system->textureResource = NULL;
    }
}
