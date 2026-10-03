#include "field/field_display_control.h"
#include "gfl/std.h"

FieldDispControl *FieldDispControl_Create(HeapID heapId) {
    FieldDispControl *control;

    control = GFL_HeapAllocate(heapId, sizeof(FieldDispControl), TRUE, data_ov036_021d56f0, 128);
    sys_memset(control->bgEnabled, 0xff, sizeof(control->bgEnabled));
    return control;
}

void FieldDispControl_Free(FieldDispControl *control) {
    GFL_HeapFree(control);
}
