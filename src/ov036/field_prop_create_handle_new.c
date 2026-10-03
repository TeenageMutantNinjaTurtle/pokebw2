#include "field/field_prop.h"
#include "gfl/heap.h"

FieldPropHandle *FieldPropSystem_CreateHandleNew(FieldPropSystem *system, u32 propId, FieldPropTransform *transform) {
    FieldPropHandle *handle;
    u32 index;

    handle = GFL_HeapAllocate(system->heapId, sizeof(FieldPropHandle), FALSE, data_ov036_021d4b2c, 0x812);
    handle->system = system;
    handle->holder = NULL;
    handle->animation = 0xffff;
    handle->transform = *transform;
    index = FieldPropSystem_ConvResIDToIndex(system, propId);
    FieldPropResInstance_Init(system, &handle->instance, (u8 *)system->resInfoArray + 0x18 * index);
    FieldPropSystem_RegistHandle(system, handle);
    return handle;
}
