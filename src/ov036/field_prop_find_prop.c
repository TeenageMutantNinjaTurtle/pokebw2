#include "field/field_prop.h"
#include "gfl/heap.h"

FieldChunkPropHolder *FieldPropSystem_FindProp(FieldPropSystem *system, u32 propId, const FieldPropAreaBounds *bounds) {
    u32 count;
    FieldChunkPropHolder **holders;
    FieldChunkPropHolder *holder;

    holders = FieldPropSystem_FindPropsInArea(system, bounds, propId, &count);
    holder = holders[0];
    GFL_HeapFree(holders);
    return holder;
}

FieldChunkPropHolder *FieldPropSystem_FindPropAtPos(FieldPropSystem *system, u32 propId, const VecFx32 *position) {
    FieldPropAreaBounds bounds;

    FieldPropSearchArea_Set(&bounds, position);
    return FieldPropSystem_FindProp(system, propId, &bounds);
}
