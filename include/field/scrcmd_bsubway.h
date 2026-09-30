#ifndef POKEBW2_FIELD_SCRCMD_BSUBWAY_H
#define POKEBW2_FIELD_SCRCMD_BSUBWAY_H

#include "types.h"
#include "struct_decls.h"

// The commands of the Battle Subway's script plugin (plugin 1), which BSUBWAY_SCRIPT_COMMANDS lists

BOOL func_ov050_021e5838(VM *vm, FieldScriptEnv *env);
BOOL func_ov050_021e5800(VM *vm, FieldScriptEnv *env);
BOOL func_ov050_021e5854(VM *vm, FieldScriptEnv *env);
// Runs one of the subway's operations, by the ID that follows the command, with two arguments and a variable for
// its result
BOOL BSubwayCmd_Tool(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_BSUBWAY_H
