#ifndef POKEBW2_FIELD_SCRCMD_TRAINER_H
#define POKEBW2_FIELD_SCRCMD_TRAINER_H

// Overlay 36's scrcmd_trainer.c: the script commands of Trainers, their sighting, battles and music. Names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"
#include "system/vm.h"

BOOL s0080_TrainerEyeEventInit(VM *vm, FieldScriptEnv *env);
BOOL s0081_TrainerEyeEventStart(VM *vm, FieldScriptEnv *env);
BOOL s0083_TrainerGetBattleType(VM *vm, FieldScriptEnv *env);
BOOL s007F_TrainerEyeGetTrainerID(VM *vm, FieldScriptEnv *env);
BOOL s0082_TrainerGetActorID(VM *vm, FieldScriptEnv *env);
BOOL s0084_ActorGetTrainerID(VM *vm, FieldScriptEnv *env);
BOOL s0085_CallTrainerBattle(VM *vm, FieldScriptEnv *env);
BOOL s0085_CallTrainerMultiBattle(VM *vm, FieldScriptEnv *env);
BOOL s0088_TrainerGetMessageTypes(VM *vm, FieldScriptEnv *env);
BOOL s008A_TrainerGetBattleType(VM *vm, FieldScriptEnv *env);
BOOL s008B_TrainerBGMPlayPush(VM *vm, FieldScriptEnv *env);
BOOL s008F_TrainerClassBGMPlayPush(VM *vm, FieldScriptEnv *env);
BOOL s0090_TrainerBGMPlay(VM *vm, FieldScriptEnv *env);
BOOL s008E_CallTrainerBattleEnd(VM *vm, FieldScriptEnv *env);
BOOL s0092_TrainerGetFieldAction(VM *vm, FieldScriptEnv *env);
BOOL s0093_TrainerGetPrizeItem(VM *vm, FieldScriptEnv *env);
BOOL s0094_CallTradedPokemonBattle(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_SCRCMD_TRAINER_H
