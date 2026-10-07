#ifndef POKEBW2_FIELD_SCRCMD_MISC_H
#define POKEBW2_FIELD_SCRCMD_MISC_H

// Overlay 36's scrcmd_misc.c: script commands of Castelia City's crowds, the elevators and the item collectors.
// Names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL s0134_CasteliaRushInit(VM *vm, FieldScriptEnv *env);
BOOL func_ov036_021afcfc(VM *vm, FieldScriptEnv *env);
BOOL func_ov036_021afd9c(VM *vm, FieldScriptEnv *env);
BOOL s01C1_ElevatorSetTablePtr(VM *vm, FieldScriptEnv *env);
BOOL s01C2_ElevatorBuildListMenu(VM *vm, FieldScriptEnv *env);
BOOL s01C2_ElevatorChangeMap(VM *vm, FieldScriptEnv *env);
BOOL s01FC_ItemCollectorGetPrice(VM *vm, FieldScriptEnv *env);
BOOL s01FB_ItemCollectorCheckGroup(VM *vm, FieldScriptEnv *env);
BOOL s0236_WordSetLoadItemCollectorPrice(VM *vm, FieldScriptEnv *env);
BOOL s0237_ItemCollectorSell(VM *vm, FieldScriptEnv *env);
BOOL func_ov036_021b018c(VM *vm, FieldScriptEnv *env);
BOOL func_ov036_021b01e0(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_MISC_H
