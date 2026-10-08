#ifndef POKEBW2_FIELD_SCRCMD_MUSICAL_H
#define POKEBW2_FIELD_SCRCMD_MUSICAL_H

// Overlay 12's scrcmd_musical.c: the script commands of the musical. Names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL func_ov012_021580c4(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_021581e4(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_02158280(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_02158550(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_021585e0(VM *vm, FieldScriptEnv *env);
BOOL s005D_WordSetMusicalInfo(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_02158858(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0215887c(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_021588d4(VM *vm, FieldScriptEnv *env);
BOOL s02EE_MusicalIsPropOwned(VM *vm, FieldScriptEnv *env);
BOOL s02EF_MusicalGetOwnedPropCount(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_02158ff4(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_MUSICAL_H
