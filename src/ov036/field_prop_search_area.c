#include "field/field_prop.h"

void FieldPropSearchArea_Set(FieldPropAreaBounds *bounds, const VecFx32 *position) {
    bounds->minZ = position->z - (3 << 16);
    bounds->maxZ = position->z + (3 << 16);
    bounds->minX = position->x - (2 << 16);
    bounds->maxX = position->x + (2 << 16);
}
