#ifndef POKEBW2_FIELD_SCRCMD_MAPCHANGE_H
#define POKEBW2_FIELD_SCRCMD_MAPCHANGE_H

// Overlay 36's scrcmd_mapchange.c: the script commands that change the map. Names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL s00C2_MapChangeWarp(VM *vm, FieldScriptEnv *env);
BOOL s00BE_MapChangeFake(VM *vm, FieldScriptEnv *env);
BOOL s00C1_MapChangeQuicksand(VM *vm, FieldScriptEnv *env);
BOOL s00BF_MapChangeWarpPad(VM *vm, FieldScriptEnv *env);
BOOL s00C3_MapChangeUnionRoom(VM *vm, FieldScriptEnv *env);
BOOL s00C4_MapChangeCore(VM *vm, FieldScriptEnv *env);
BOOL s00C0_MapChangeWarpRail(VM *vm, FieldScriptEnv *env);
BOOL s0247_MapChangeRail(VM *vm, FieldScriptEnv *env);
BOOL s028A_MapChangeFlyWarp(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_MAPCHANGE_H
