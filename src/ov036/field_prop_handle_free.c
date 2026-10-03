#include "field/field_prop.h"
#include "gfl/heap.h"

void FieldPropHandle_Free(FieldPropHandle *handle) {
    if (handle != NULL) {
        FieldPropSystem_DeleteHandle(handle->system, handle);
        FieldPropResInstance_Free(&handle->instance);
        if (handle->holder != NULL) {
            FieldChunkPropHolder_SetVisible(handle->holder, TRUE);
        }
        GFL_HeapFree(handle);
    }
}
