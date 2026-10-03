#include "field/field_prop.h"

FieldPropHandle *FieldPropSystem_CreateHandleAtPos(FieldPropSystem *system, u32 propId, const VecFx32 *position) {
    FieldChunkPropHolder *holder;

    holder = FieldPropSystem_FindPropAtPos(system, propId, position);
    if (holder == NULL) {
        return NULL;
    }
    return FieldPropSystem_CreateHandleFromExisting(system, holder);
}
