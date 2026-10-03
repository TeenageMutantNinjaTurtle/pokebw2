#include "types.h"
#include "field/field_script.h"
#include "gfl/std.h"

void FieldScriptSubEvent_ResetAll(void) {
    sys_memset32(0, &g_ActiveFieldScriptSubEvents, sizeof(g_ActiveFieldScriptSubEvents));
}

void FieldScriptSubEvent_Register(int id) {
    if (id < 14 && !FieldScriptSubEvent_IsRegisteredCore(id)) {
        g_ActiveFieldScriptSubEvents |= 1 << id;
    }
}

void FieldScriptSubEvent_Unregister(int id) {
    if (id < 14 && FieldScriptSubEvent_IsRegisteredCore(id)) {
        g_ActiveFieldScriptSubEvents &= -1 ^ (1 << id);
    }
}

BOOL FieldScriptSubEvent_IsRegistered(int id) {
    return FieldScriptSubEvent_IsRegisteredCore(id);
}

BOOL FieldScriptSubEvent_IsRegisteredCore(int id) {
    if (id >= 14) {
        return FALSE;
    }
    if (((s32)g_ActiveFieldScriptSubEvents >> id) & 1) {
        return TRUE;
    }
    return FALSE;
}
