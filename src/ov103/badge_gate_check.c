#include "field/badge_gate.h"
#include "field/field_exp_obj.h"

GameEventReturnCode BadgeGate_CheckEvent(GameEvent *event, u32 *state, void *arg) {
    BadgeGateCheckEventData *data;
    BadgeGateAnimationEntry *entry0;
    BadgeGateAnimationEntry *entry1;
    BadgeGateAnimationEntry *entry2;
    FieldExpObjAnm *anm;
    fx32 frame;

    data = arg;
    entry0 = func_ov103_021ef1ac(data->gimmickWork, data->badge, 0);
    entry1 = func_ov103_021ef1ac(data->gimmickWork, data->badge, 1);
    entry2 = func_ov103_021ef1ac(data->gimmickWork, data->badge, 2);
    func_ov103_021ef188(data);
    data->state++;

    switch (*state) {
    case 0:
        FieldExpObj_SetActorHidden(entry1->expObj, entry1->scene, entry1->actor, TRUE);
        FieldExpObj_SetActorHidden(entry0->expObj, entry0->scene, entry0->actor, FALSE);
        func_ov103_021ef1dc(entry0, 0, FALSE);
        func_ov103_021ef1dc(entry0, 1, FALSE);
        (*state)++;
        break;
    case 1:
        anm = FieldExpObj_GetAnmInfo(entry0->expObj, entry0->scene, entry0->actor, 0);
        if (FieldExpObjAnm_IsPlaybackFinished(anm) == TRUE) {
            func_ov103_021ef1dc(entry0, 0, TRUE);
            (*state)++;
            return GAMEEVENT_CONTINUE_DIRECT;
        }
        break;
    case 2:
        FieldExpObj_SetActorHidden(entry0->expObj, entry0->scene, entry0->actor, TRUE);
        FieldExpObj_SetActorHidden(entry2->expObj, entry2->scene, entry2->actor, FALSE);
        frame = func_ov103_021ef200(data->gimmickWork);
        FieldExpObj_SetAnmFrame(entry2->expObj, entry2->scene, entry2->actor, 0, frame);
        func_ov103_021ef1dc(entry2, 0, FALSE);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
