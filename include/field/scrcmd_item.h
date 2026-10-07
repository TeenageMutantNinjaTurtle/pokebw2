#ifndef POKEBW2_FIELD_SCRCMD_ITEM_H
#define POKEBW2_FIELD_SCRCMD_ITEM_H

// Overlay 36's scrcmd_item.c: the script commands of items. Names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL s00B5_ItemAdd(VM *vm, FieldScriptEnv *env);
BOOL s00B6_ItemSub(VM *vm, FieldScriptEnv *env);
BOOL s00B7_ItemCheckSpace(VM *vm, FieldScriptEnv *env);
BOOL s00B8_ItemCheckAmount(VM *vm, FieldScriptEnv *env);
BOOL s00B9_ItemGetCount(VM *vm, FieldScriptEnv *env);
BOOL s00BA_ItemIsTMHM(VM *vm, FieldScriptEnv *env);
BOOL s00BB_ItemGetPocket(VM *vm, FieldScriptEnv *env);
BOOL s00BD_ItemGetClass(VM *vm, FieldScriptEnv *env);
BOOL s02D4_ItemGetTMCount(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_ITEM_H
