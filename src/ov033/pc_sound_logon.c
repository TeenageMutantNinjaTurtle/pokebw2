#include "field/field.h"
#include "field/field_prop.h"
#include "field/pc_sound.h"

GameEventReturnCode func_ov033_021799e8(GameEvent *event, u32 *state, void *eventData) {
    struct PCSoundEventData *data;
    VecFx32 position;
    FieldPropAreaBounds bounds;
    FieldPropSystem *propSystem;
    FieldChunkPropHolder *prop;

    data = eventData;
    switch (*state) {
    case 0:
        FieldPlayer_GetWPos(Field_GetPlayer(data->field), &position);
        bounds.minZ = position.z - (1 << 16);
        bounds.maxZ = position.z + (1 << 16);
        bounds.minX = position.x - (1 << 16);
        bounds.maxX = position.x + (1 << 16);
        propSystem = FieldG3DMapper_GetBMSystem(Field_GetG3DMapper(data->field));
        prop = FieldPropSystem_FindProp(propSystem, 4, &bounds);
        if (prop != NULL) {
            data->pcProp = prop;
            FieldChunkPropHolder_CallAnmCmd(propSystem, prop, 1, 2);
        }
        (*state)++;
        break;
    case 1:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}

GameEvent *func_ov033_02179a58(GameEvent *parent, GameSystem *gsys, Field *field) {
    GameEvent *event;
    struct PCSoundEventData *data;

    event = GameEvent_Create(gsys, parent, func_ov033_021799e8, sizeof(struct PCSoundEventData));
    data = GameEvent_GetData(event);
    data->gameSystem = gsys;
    data->field = field;
    data->pcProp = NULL;
    return event;
}
