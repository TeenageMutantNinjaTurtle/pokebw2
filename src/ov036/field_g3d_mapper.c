#include "types.h"
#include "field/field_map.h"
#include "gfl/g3d.h"

void FieldG3DMapper_FreeMapTextures(G3DMapper *mapper) {
    if (mapper->mapTextureResource != NULL) {
        GFL_G3DResFreeTexData(mapper->mapTextureResource);
        GFL_G3DResFree(mapper->mapTextureResource);
        mapper->mapTextureResource = NULL;
    }
}
