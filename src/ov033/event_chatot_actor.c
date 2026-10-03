#include "field/event_chatot.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "system/game_system.h"

void func_ov033_02178fcc(void *work, u32 *state) {
    *state = 1;
}

void func_ov033_02178fd4(ChatotEventWork *work) {
    DisableAllActorsMovement(Field_GetActorSystem(GSYS_GetField(work->gsys)));
}

void func_ov033_02178fe8(ChatotEventWork *work) {
    EnableAllActorsMovement(Field_GetActorSystem(GSYS_GetField(work->gsys)));
}
