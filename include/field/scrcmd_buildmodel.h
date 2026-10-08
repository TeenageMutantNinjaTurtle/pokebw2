#ifndef POKEBW2_FIELD_SCRCMD_BUILDMODEL_H
#define POKEBW2_FIELD_SCRCMD_BUILDMODEL_H

// Overlay 36's scrcmd_buildmodel.c: the script commands of build models. Names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL s0125_BMPlayHOFMachineSeq(VM *vm, FieldScriptEnv *env);
BOOL s012F_PokecenPlayHealingSequence(VM *vm, FieldScriptEnv *env);
BOOL s0130_PokecenPCOpen(VM *vm, FieldScriptEnv *env);
BOOL s0131_PokecenPCIdle(VM *vm, FieldScriptEnv *env);
BOOL s0132_PokecenPCClose(VM *vm, FieldScriptEnv *env);
BOOL s012B_BMAnmPlayInv(VM *vm, FieldScriptEnv *env);
BOOL s012E_BMAnmPlayLoop(VM *vm, FieldScriptEnv *env);
BOOL s012D_BMSetVisible(VM *vm, FieldScriptEnv *env);
BOOL s0126_BMChangeMdlID(VM *vm, FieldScriptEnv *env);
BOOL s0127_BMCreateHandleByGPos(VM *vm, FieldScriptEnv *env);
BOOL s0128_BMReleaseHandle(VM *vm, FieldScriptEnv *env);
BOOL s0129_BMHndAudioVisualAnmPlay(VM *vm, FieldScriptEnv *env);
BOOL s0124_BMHndAnmPlay(VM *vm, FieldScriptEnv *env);
BOOL s012C_BMHndAnmPause(VM *vm, FieldScriptEnv *env);
BOOL s012A_BMHndAnmWait(VM *vm, FieldScriptEnv *env);

// The handle that s012A_BMHndAnmWait waits on, among the common symbols at the end of the .bss
extern u16 g_ScrBMAnmWaitHandleID;

#endif // POKEBW2_FIELD_SCRCMD_BUILDMODEL_H
