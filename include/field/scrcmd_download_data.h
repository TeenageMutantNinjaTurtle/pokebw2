#ifndef POKEBW2_FIELD_SCRCMD_DOWNLOAD_DATA_H
#define POKEBW2_FIELD_SCRCMD_DOWNLOAD_DATA_H

// Overlay 12's scrcmd_download_data.c (a descriptive name): script commands 0x2B2 to 0x2B7, which read the downloaded
// data the save keeps

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL func_ov012_0216a950(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216a994(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216a9d8(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216aa1c(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216aabc(VM *vm, FieldScriptEnv *env);
BOOL func_ov012_0216ab30(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_DOWNLOAD_DATA_H
