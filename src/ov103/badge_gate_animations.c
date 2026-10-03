#include "field/badge_gate.h"
#include "field/field_exp_obj.h"

typedef FieldExpObjAnm *(*BadgeGateAnmInfoGetter)(FieldExpObjSystem *, u16, u16, u32);

void func_ov103_021ef1dc(void *data, u32 anim, u32 paused) {
    BadgeGateAnimationEntry *entry;
    FieldExpObjAnm *anm;

    entry = data;
    // This caller passes the full animation index; the shared declaration narrows it for other callers.
    anm = ((BadgeGateAnmInfoGetter)FieldExpObj_GetAnmInfo)(entry->expObj, entry->scene, entry->actor, anim);
    FieldExpObjAnm_SetPaused(anm, paused);
}

u32 func_ov103_021ef200(void *work) {
    s32 i;
    BadgeGateAnimationEntry *entry;
    FieldExpObjAnm *anm;

    for (i = 0; i < 8; i++) {
        entry = func_ov103_021ef1ac(work, i, 2);
        anm = FieldExpObj_GetAnmInfo(entry->expObj, entry->scene, entry->actor, 0);
        if (!func_ov036_021b84ec(anm)) {
            return func_ov036_021b8520(entry->expObj, entry->scene, entry->actor, 0);
        }
    }
    return 0;
}
