#ifndef POKEBW2_FIELD_FIELD_MOVE_SCRIPTS_H
#define POKEBW2_FIELD_FIELD_MOVE_SCRIPTS_H

#include "field/field_script.h"

BOOL ScriptNative_SurfTCBWait(VM *vm, void *env);
BOOL s00C5_CallSurf(VM *vm, FieldScriptEnv *env);
BOOL ScriptNative_WaterfallTCBWait(VM *vm, void *env);
BOOL s00C6_CallWaterfall(VM *vm, FieldScriptEnv *env);
BOOL s00C7_CallCut(VM *vm, FieldScriptEnv *env);
BOOL s00C8_CallDiving(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_FIELD_MOVE_SCRIPTS_H
