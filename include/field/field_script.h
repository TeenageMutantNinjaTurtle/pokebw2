#ifndef POKEBW2_FIELD_FIELD_SCRIPT_H
#define POKEBW2_FIELD_FIELD_SCRIPT_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

// Fields accessed by the field script work helpers; the remaining storage is not yet identified.
struct ScriptWork {
    u8 unk00[4];
    u16 scriptId;
    u16 unk06;
    FieldActor *parentActor;
    HeapID heapId;
    u16 unk0E;
    GameSystem *gsys;
    GameEvent *event;
    u8 fieldWork[8];
    u8 unk20[0xc];
    WordSet *wordSet;
    StrBuf *mainStrBuf;
    StrBuf *altStrBuf;
    void *unk38;
    void *userHeap;
    u32 seBitMask;
    u8 trainerState[2][0x1c];
    u16 localWork[0x62];
    FieldActorAnmProc *actorAnmProc;
    void *stadiumTrainers;
    void *subwork;
};

// Runs a script from an event, and returns its work
ScriptWork *EventScriptCall_Start(GameEvent *event, u16 scriptId, void *a2, void *a3, HeapID heapId);
// Sets the script's parameters, which it reads from its work
void ScriptWork_SetParams(ScriptWork *work, u16 param0, u16 param1, u16 param2, u16 param3);
void FieldScript_CallOnZoneInit(GameSystem *gsys, u32 a1);
void FieldScript_CallPlayerInitSetup(GameSystem *gsys, u32 a1);
void resetRebattleTrainers(EventWork *eventWork);

// A field script command. env is the running script's environment
typedef BOOL (*FieldScriptCommand)(VM *vm, FieldScriptEnv *env);

BOOL s0000_VMNop(VM *vm, FieldScriptEnv *env);
BOOL s0001_VMNop2(VM *vm, FieldScriptEnv *env);
BOOL s0002_VMHalt(VM *vm, FieldScriptEnv *env);
BOOL swapToScrcmdEnvirDecPauseCtr(VM *vm, void *env);
BOOL s0003_VMSleep(VM *vm, FieldScriptEnv *env);
BOOL s0004_VMCall(VM *vm, FieldScriptEnv *env);
BOOL s0005_VMReturn(VM *vm, FieldScriptEnv *env);
BOOL s0006_DebugPrint(VM *vm, FieldScriptEnv *env);
BOOL s0007_DebugStack(VM *vm, FieldScriptEnv *env);
BOOL s0014_VMRegSet8(VM *vm, FieldScriptEnv *env);
BOOL s0015_VMRegSet32(VM *vm, FieldScriptEnv *env);
BOOL s0016_VMRegMov(VM *vm, FieldScriptEnv *env);
u8 VMCmp(u32 left, u32 right);
BOOL s0017_VMRegCmp8(VM *vm, FieldScriptEnv *env);
BOOL s0018_VMRegCmpConst8(VM *vm, FieldScriptEnv *env);
BOOL s0019_WorkCmpConst(VM *vm, FieldScriptEnv *env);
BOOL s001A_WorkCmpWork(VM *vm, FieldScriptEnv *env);
BOOL s0008_VMStackPushConst(VM *vm, FieldScriptEnv *env);
BOOL s0009_VMStackPush(VM *vm, FieldScriptEnv *env);
BOOL s000A_VMStackPop(VM *vm, FieldScriptEnv *env);
BOOL s000B_VMStackDiscard(VM *vm, FieldScriptEnv *env);
BOOL s000C_VMStackAdd(VM *vm, FieldScriptEnv *env);
BOOL s000D_VMStackSub(VM *vm, FieldScriptEnv *env);
BOOL s000E_VMStackMul(VM *vm, FieldScriptEnv *env);
BOOL s000F_VMStackDiv(VM *vm, FieldScriptEnv *env);
BOOL s0010_VMStackPushFlag(VM *vm, FieldScriptEnv *env);
BOOL s0011_VMStackCmp(VM *vm, FieldScriptEnv *env);
BOOL s0021_RTReserveScript(VM *vm, FieldScriptEnv *env);
BOOL s0022_FieldGetContinueFlag(VM *vm, FieldScriptEnv *env);
BOOL s0023_FlagSet(VM *vm, FieldScriptEnv *env);
BOOL s0024_FlagReset(VM *vm, FieldScriptEnv *env);
BOOL s0025_FlagGet(VM *vm, FieldScriptEnv *env);
BOOL s0026_WorkAdd(VM *vm, FieldScriptEnv *env);
BOOL s0027_WorkSub(VM *vm, FieldScriptEnv *env);
BOOL s002B_WorkMul(VM *vm, FieldScriptEnv *env);
BOOL s002C_WorkDiv(VM *vm, FieldScriptEnv *env);
BOOL s002D_WorkMod(VM *vm, FieldScriptEnv *env);
BOOL s0012_WorkAnd(VM *vm, FieldScriptEnv *env);
BOOL s0013_WorkOr(VM *vm, FieldScriptEnv *env);
BOOL s0028_WorkSetConst(VM *vm, FieldScriptEnv *env);
BOOL s0029_WorkGet(VM *vm, FieldScriptEnv *env);
BOOL s002A_WorkSet(VM *vm, FieldScriptEnv *env);
extern const u8 VM_CMP_LUT[][3];
BOOL s001D_RTEndGlobal(VM *vm, FieldScriptEnv *env);
BOOL s001E_VMJump(VM *vm, FieldScriptEnv *env);
BOOL s001F_VMJumpIf(VM *vm, FieldScriptEnv *env);
BOOL s0020_VMCallIf(VM *vm, FieldScriptEnv *env);

GameSystem *FieldScriptEnv_GetGameSystem(FieldScriptEnv *env);
GameData *FieldScriptEnv_GetGameData(FieldScriptEnv *env);
HeapID FieldScriptEnv_GetHeapID(FieldScriptEnv *env);
u16 GetScriptEnvZoneID(FieldScriptEnv *env);
ScriptWork *FieldScriptEnv_GetScriptWork(FieldScriptEnv *env);
FieldActorAnmProc *ScriptWork_GetActorAnmProc(ScriptWork *work);
void ScriptWork_SetActorAnmProc(ScriptWork *work, FieldActorAnmProc *proc);
void ScriptWork_SetStadiumTrainers(ScriptWork *work, void *trainers);
void *ScriptWork_GetStadiumTrainers(ScriptWork *work);
void *ScriptWork_GetTrainerState(ScriptWork *work, int index);
extern u32 g_ActiveFieldScriptSubEvents;
void FieldScriptSubEvent_ResetAll(void);
void FieldScriptSubEvent_Register(int id);
void FieldScriptSubEvent_Unregister(int id);
BOOL FieldScriptSubEvent_IsRegistered(int id);
BOOL FieldScriptSubEvent_IsRegisteredCore(int id);
// Reads a value from the script, or the value of the variable it names (IDs from 0x4000)
u16 ScriptReadAny(VM *vm, FieldScriptEnv *env);
// Reads a variable's ID from the script, and returns the variable
u16 *ScriptReadVar(VM *vm, FieldScriptEnv *env);
// Runs event before the script goes on
void ScriptWork_CallEvent(ScriptWork *work, GameEvent *event);
void ScriptWork_SetPostEvent(ScriptWork *work, GameEvent *event);
GameEvent *ScriptWork_GetEvent(ScriptWork *work);
FieldScriptSupervisor *ScriptWork_GetSupervisor(ScriptWork *work);
ScriptWork *EventScriptCall_GetWork(GameEvent *event);
void UpdateScriptFieldWk(void *fieldWork, GameSystem *gsys);
void *ScriptWork_GetFieldWork(ScriptWork *work);
void *ScriptWork_GetSubwork(ScriptWork *work);
u32 *ScriptWork_GetSEBitMask(ScriptWork *work);
u16 ScriptWork_GetSCRID(ScriptWork *work);
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
void *ScriptWork_GetUserHeap(ScriptWork *work);
void ScriptWork_FreeUserHeap(ScriptWork *work);
u16 *ScriptWork_GetLocalWork(ScriptWork *work, u16 id);
WordSet *ScriptWork_GetWordSet(ScriptWork *work);
MMSys *GetScrEnvMMdlSys(FieldScriptEnv *env);
// Adds an entry to the script's list menu
void AddItemToListMenu(FieldScriptEnv *env, u32 a1, u32 message, u32 value, StrBuf *a4, StrBuf *a5);

// Overlay 36: show a message, and have the script wait for it
BOOL func_ov036_021a8eb4(VM *vm, FieldScriptEnv *env, StrBuf *message, u32 a3, u16 a4, u32 a5);
BOOL loadMsgBox(VM *vm, FieldScriptEnv *env, StrBuf *message, u32 a3, u8 a4);

#endif // POKEBW2_FIELD_FIELD_SCRIPT_H
