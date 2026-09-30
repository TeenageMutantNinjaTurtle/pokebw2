#ifndef POKEBW2_FIELD_SCRCMD_RESORT_H
#define POKEBW2_FIELD_SCRCMD_RESORT_H

#include "types.h"
#include "struct_decls.h"

// The commands of the Join Avenue's script plugin (plugin 8), which RESORT_SCRIPT_COMMANDS lists. Overlay 59's
// scrcmd_resort.c and scrcmd_medalinfo.c have them, and while the shops are open, overlay 60 takes overlay 59's place
// and runs its own command from the first entry's address

BOOL func_ov059_021e58c0(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e591c(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e5950(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e5eb0(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e5f38(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6014(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e60a4(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e619c(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e61d8(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e62a8(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6318(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e63d4(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e64a0(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e65fc(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6630(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e66d8(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6778(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e67f8(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6868(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e689c(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6934(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6b68(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6bd4(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6c10(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6c48(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6d50(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6f14(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e6fc8(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e742c(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e74cc(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e7608(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e7710(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e7748(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e778c(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e77c4(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e79a4(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e7a28(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e7ad8(VM *vm, FieldScriptEnv *env);
BOOL func_ov059_021e7c70(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_RESORT_H
