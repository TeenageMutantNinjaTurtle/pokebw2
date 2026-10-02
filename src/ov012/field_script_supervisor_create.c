#include "field/field_script_supervisor.h"

FieldScriptSupervisor *FieldScriptSupervisor_Create(HeapID heapId) {
    FieldScriptSupervisor *supervisor;

    supervisor = GFL_HeapAllocate(heapId, sizeof(FieldScriptSupervisor), TRUE, data_ov012_0216e190, 0xf1);
    supervisor->heapId = heapId;
    return supervisor;
}

void FieldScriptSupervisor_Free(FieldScriptSupervisor *supervisor) {
    GFL_HeapFree(supervisor);
}
