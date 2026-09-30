#ifndef POKEBW2_FIELD_FIELD_SCRIPT_H
#define POKEBW2_FIELD_FIELD_SCRIPT_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Runs a script from an event, and returns its work
ScriptWork *EventScriptCall_Start(GameEvent *event, u16 scriptId, void *a2, void *a3, HeapID heapId);
// Sets the script's parameters, which it reads from its work
void ScriptWork_SetParams(ScriptWork *work, u16 param0, u16 param1, u16 param2, u16 param3);
void FieldScript_CallOnZoneInit(GameSystem *gsys, u32 a1);
void FieldScript_CallPlayerInitSetup(GameSystem *gsys, u32 a1);
void resetRebattleTrainers(EventWork *eventWork);

// A field script command. env is the running script's environment
typedef BOOL (*FieldScriptCommand)(VM *vm, FieldScriptEnv *env);

GameSystem *FieldScriptEnv_GetGameSystem(FieldScriptEnv *env);
ScriptWork *FieldScriptEnv_GetScriptWork(FieldScriptEnv *env);
// Reads a value from the script, or the value of the variable it names (IDs from 0x4000)
u16 ScriptReadAny(VM *vm, FieldScriptEnv *env);
// Reads a variable's ID from the script, and returns the variable
u16 *ScriptReadVar(VM *vm, FieldScriptEnv *env);
// Runs event before the script goes on
void ScriptWork_CallEvent(ScriptWork *work, GameEvent *event);

#endif // POKEBW2_FIELD_FIELD_SCRIPT_H
