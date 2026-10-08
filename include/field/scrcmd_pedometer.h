#ifndef POKEBW2_FIELD_SCRCMD_PEDOMETER_H
#define POKEBW2_FIELD_SCRCMD_PEDOMETER_H

// Overlay 12's scrcmd_pedometer.c (a descriptive name): the script commands of the step counter. Names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL s02B8_PedometerStart(VM *vm, FieldScriptEnv *env);
BOOL s02B9_PedometerEnd(VM *vm, FieldScriptEnv *env);
BOOL s02BA_PedometerGet(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_PEDOMETER_H
