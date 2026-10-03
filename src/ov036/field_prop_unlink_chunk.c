#include "field/field_prop.h"

void FieldPropSystem_UnlinkChunk(FieldPropSystem *system, void *chunk) {
    FieldPropSystem_ReleaseChunkPropHolders(system, chunk);
}
