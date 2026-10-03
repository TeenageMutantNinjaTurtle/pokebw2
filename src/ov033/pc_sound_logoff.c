#include "field/field.h"
#include "field/field_prop.h"
#include "field/pc_sound.h"
#include "gfl/sound.h"

GameEventReturnCode pcLogOffSound(GameEvent *event, u32 *state, void *eventData) {
    struct PCSoundEventData *data = eventData;
    VecFx32 position;
    FieldPropAreaBounds bounds;
    FieldPropSystem *propSystem;
    FieldChunkPropHolder *prop;
    u32 currentState = *state;

    switch (currentState) {
    case 0:
        if (data->skipSound == 0) {
            GFL_SndSEPlay(0x55d);
        }
        FieldPlayer_GetWPos(Field_GetPlayer(data->field), &position);
        bounds.minZ = position.z - (1 << 16);
        bounds.maxZ = position.z + (1 << 16);
        bounds.minX = position.x - (1 << 16);
        bounds.maxX = position.x + (1 << 16);
        propSystem = FieldG3DMapper_GetBMSystem(Field_GetG3DMapper(data->field));
        prop = FieldPropSystem_FindProp(propSystem, 4, &bounds);
        if (prop != NULL) {
            data->pcProp = prop;
            FieldChunkPropHolder_CallAnmCmd(propSystem, prop, 2, 0);
        }
        (*state)++;
        break;
    case 1:
        if (data->skipSound == 0) {
            if (GFL_SndPlayerIsActive(GFL_SndSeqGetPlayerIndex(0x55d))) {
                break;
            }
            (*state)++;
        } else {
            *state = currentState + 1;
        }
        break;
    case 2:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
