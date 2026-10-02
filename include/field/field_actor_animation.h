#ifndef POKEBW2_FIELD_FIELD_ACTOR_ANIMATION_H
#define POKEBW2_FIELD_FIELD_ACTOR_ANIMATION_H

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"
#include "system/game_event.h"

// Function names from swan.
FieldActorAnmProc *FieldActorAnmProc_Create(Field *field, u16 actorId, const VecFx32 *pos, HeapID heapId);
void FieldActorAnmProc_Free(FieldActorAnmProc *proc);
void FieldActorAnmProc_Play(FieldActorAnmProc *proc, u16 animation);
BOOL FieldActorAnmProc_IsPlaying(FieldActorAnmProc *proc);
BOOL s0157_ActorAnimationInit(VM *vm, FieldScriptEnv *env);
BOOL s0158_ActorAnimationFree(VM *vm, FieldScriptEnv *env);
BOOL s0159_ActorAnimationPlay(VM *vm, FieldScriptEnv *env);
GameEventReturnCode EventActorAnmProcWait_Callback(GameEvent *event, u32 *state, void *data);
BOOL s015A_ActorAnimationWait(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_FIELD_ACTOR_ANIMATION_H
