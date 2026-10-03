#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/arc.h"
#include "system/version.h"

GameEvent *func_ov104_021f02fc(GameSystem *gsys, Field *field, u32 id) {
    GameEvent *event;
    struct FieldExpObjGimmickOv104GateEventData *data;

    event = GameEvent_Create(gsys, 0, func_ov104_021f0160, sizeof(struct FieldExpObjGimmickOv104GateEventData));
    data = GameEvent_GetData(event);
    data->gameSystem = gsys;
    data->field = field;
    data->id = id;
    return event;
}

BOOL func_ov104_021f0324(struct FieldExpObjGimmickOv104ResEntry *entry, u32 arcId, u32 fileId) {
    GFL_ArcSysReadRange(entry, arcId, fileId, 0, 0x24);
    return TRUE;
}

BOOL func_ov104_021f0334(struct FieldExpObjGimmickOv104ResEntry *entry, u16 zone) {
    if (entry->zones[0] == 0x267 && entry->zones[1] == 0x267 && entry->zones[2] == 0x267 && entry->zones[3] == 0x267) {
        return TRUE;
    }
    if (entry->zones[0] == zone || entry->zones[1] == zone || entry->zones[2] == zone || entry->zones[3] == zone) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov104_021f037c(struct FieldExpObjGimmickOv104ResEntry *entry) {
    if (entry->unk00 == 0) {
        return TRUE;
    }
    if (entry->unk00 == getGameVersion()) {
        return TRUE;
    }
    return FALSE;
}