#ifndef POKEBW2_FIELD_SCRCMD_SP_POKE_GIMMICK_H
#define POKEBW2_FIELD_SCRCMD_SP_POKE_GIMMICK_H

// Overlay 12's scrcmd_sp_poke_gimmick.c (a guess after overlay 129's file): the script commands of the special Pokémon.
// s020D_PokePartyFindEx is swan's name (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL func_ov012_02165598(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216564c(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_021656a8(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_021656e0(VM *vm, FieldScriptEnv *env);
BOOL s020D_PokePartyFindEx(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_021658c8(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_02165950(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_SP_POKE_GIMMICK_H
