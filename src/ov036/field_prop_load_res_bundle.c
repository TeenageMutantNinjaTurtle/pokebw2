#include "field/field_prop.h"
#include "gfl/arc.h"
#include "gfl/heap.h"

void FieldPropSystem_LoadResBundle(FieldPropSystem *system, u32 arcId, u32 fileId) {
    ArcTool *arc;
    u32 count;

    arc = GFL_ArcSysCreateFileHandle(arcId, HEAPID_TAIL(system->heapId));
    if (GFL_ArcToolGetDataMax(arc) <= fileId) {
        fileId = 0;
    }
    system->resBundle = GFL_ArcToolReadHeapNew(arc, fileId, system->heapId);
    count = (u32)system->resBundle->countFlags >> 1;
    system->resInfoCount = count;
    if (count > 0x200) {
        system->resInfoCount = 0x80;
    }
    GFL_ArcToolFree(arc);
}
