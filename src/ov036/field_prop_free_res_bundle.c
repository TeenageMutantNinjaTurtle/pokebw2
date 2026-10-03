#include "field/field_prop.h"
#include "gfl/heap.h"

void FieldPropSystem_FreeResBundle(FieldPropSystem *system) {
    GFL_HeapFree(system->resBundle);
    system->resInfoCount = 0;
}
