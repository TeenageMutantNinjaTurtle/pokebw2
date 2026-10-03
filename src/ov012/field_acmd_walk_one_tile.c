#include "field/field_acmd.h"
#include "field/field_actor.h"

FieldAcmdTCB *FieldAcmdTCB_CreateWalkOneTile(FieldActor *actor, u32 direction) {
    const u32 *queue;
    switch (direction) {
    case 0: queue = ACMD_QUEUE_WALK_N_8F; break;
    case 1: queue = ACMD_QUEUE_WALK_S_8F; break;
    case 2: queue = ACMD_QUEUE_WALK_W_8F; break;
    case 3: queue = ACMD_QUEUE_WALK_E_8F; break;
    }
    func_ov012_02166f2c(actor);
    return FieldAcmdTCB_Create(actor, queue);
}
