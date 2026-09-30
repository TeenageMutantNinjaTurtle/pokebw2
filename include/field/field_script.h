#ifndef POKEBW2_FIELD_FIELD_SCRIPT_H
#define POKEBW2_FIELD_FIELD_SCRIPT_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
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
GameData *FieldScriptEnv_GetGameData(FieldScriptEnv *env);
HeapID FieldScriptEnv_GetHeapID(FieldScriptEnv *env);
u16 GetScriptEnvZoneID(FieldScriptEnv *env);
ScriptWork *FieldScriptEnv_GetScriptWork(FieldScriptEnv *env);
// Reads a value from the script, or the value of the variable it names (IDs from 0x4000)
u16 ScriptReadAny(VM *vm, FieldScriptEnv *env);
// Reads a variable's ID from the script, and returns the variable
u16 *ScriptReadVar(VM *vm, FieldScriptEnv *env);
// Runs event before the script goes on
void ScriptWork_CallEvent(ScriptWork *work, GameEvent *event);
void *ScriptWork_GetFieldWork(ScriptWork *work);
// A variable of the script (IDs from 0x8000) or saved event work (from 0x4000)
u16 *ScriptWork_GetWkAddr(ScriptWork *work, GameData *gameData, u16 id);
// Waits a number of frames: UpdateWaitCounter returns TRUE once they have passed
void FieldScriptEnv_SetWaitCounter(FieldScriptEnv *env, u16 frames);
BOOL FieldScriptEnv_UpdateWaitCounter(FieldScriptEnv *env);
GameSystem *ScriptWork_GetGameSystem(ScriptWork *work);
StrBuf *ScriptWork_GetMainStrBuf(ScriptWork *work);
StrBuf *ScriptWork_GetAltStrBuf(ScriptWork *work);
FieldActor *ScriptWork_GetParentActor(ScriptWork *work);
void ScriptWork_SetParentActor(ScriptWork *work, FieldActor *actor);
// A pointer that a command can keep its own work in while the script waits
void **ScriptWork_GetUserHeapPtr(ScriptWork *work);
WordSet *ScriptWork_GetWordSet(ScriptWork *work);
MMSys *GetScrEnvMMdlSys(FieldScriptEnv *env);
// Adds an entry to the script's list menu
void AddItemToListMenu(FieldScriptEnv *env, u32 a1, u32 message, u32 value, StrBuf *a4, StrBuf *a5);

// Overlay 36: show a message, and have the script wait for it
BOOL func_ov036_021a8eb4(VM *vm, FieldScriptEnv *env, StrBuf *message, u32 a3, u16 a4, u32 a5);
BOOL loadMsgBox(VM *vm, FieldScriptEnv *env, StrBuf *message, u32 a3, u8 a4);

#endif // POKEBW2_FIELD_FIELD_SCRIPT_H
