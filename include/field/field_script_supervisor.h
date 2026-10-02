#ifndef POKEBW2_FIELD_FIELD_SCRIPT_SUPERVISOR_H
#define POKEBW2_FIELD_FIELD_SCRIPT_SUPERVISOR_H

#include "types.h"
#include "struct_decls.h"

// Layout and names reconstructed from the field script code and swan.
struct FieldScriptSupervisor {
    u16 scriptId;
    u8 vmCount;
    u8 padding;
    VM *vms[3];
    void (*postFunc)(GameEvent *event, void *arg);
    void *postArg;
    u32 unk18;
};

BOOL FieldScriptSupervisor_Update(FieldScriptSupervisor *supervisor);
int FieldScriptSupervisor_AddVM(FieldScriptSupervisor *supervisor, VM *vm);
VM *FieldScriptSupervisor_GetVM(FieldScriptSupervisor *supervisor, int index);
void FieldScript_FreeVM(VM *vm);
void FieldScriptTerminator_ReplaceEvent(GameEvent *event, void *arg);
void FieldScriptSupervisor_SetPostEvent(FieldScriptSupervisor *supervisor, GameEvent *event);
void FieldScriptSupervisor_CallPostFunc(FieldScriptSupervisor *supervisor, GameEvent *event);
BOOL FieldScriptSupervisor_HasPostFunc(FieldScriptSupervisor *supervisor);

#endif // POKEBW2_FIELD_FIELD_SCRIPT_SUPERVISOR_H
