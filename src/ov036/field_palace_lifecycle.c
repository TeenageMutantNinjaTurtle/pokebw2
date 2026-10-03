#include "field/field_palace.h"
#include "gfl/heap.h"

void FieldPalaceSys_Free(FieldPalaceSys *sys) {
    if (sys->luminanceTable != NULL) {
        GFL_HeapFree(sys->luminanceTable);
    }
    GFL_HeapFree(sys);
}

void *FieldPalaceSys_GetLuminanceTable(FieldPalaceSys *sys) {
    return sys->luminanceTable;
}
