#include "field/field.h"
#include "field/field_prop.h"
#include "field/pc_sound.h"
#include "gfl/sound.h"

GameEventReturnCode pcEntrySound(GameEvent *event, u32 *state, void *eventData) {
    struct PCSoundEventData *data = eventData;
    VecFx32 position;
    FieldPropAreaBounds bounds;
    FieldPropSystem *propSystem;
    FieldChunkPropHolder *prop;

    switch (*state) {
    case 0:
        GFL_SndSEPlay(0x55b);
        FieldPlayer_GetWPos(Field_GetPlayer(data->field), &position);
        bounds.minZ = position.z - (1 << 16);
        bounds.maxZ = position.z + (1 << 16);
        bounds.minX = position.x - (1 << 16);
        bounds.maxX = position.x + (1 << 16);
        propSystem = FieldG3DMapper_GetBMSystem(Field_GetG3DMapper(data->field));
        prop = FieldPropSystem_FindProp(propSystem, 4, &bounds);
        if (prop != NULL) {
            data->pcProp = prop;
            FieldChunkPropHolder_CallAnmCmd(propSystem, prop, 0, 0);
        }
        (*state)++;
        break;
    case 1:
        if (GFL_SndPlayerIsActive(GFL_SndSeqGetPlayerIndex(0x55b))) {
            break;
        }
        (*state)++;
        break;
    case 2:
        GFL_SndSEPlay(0x55c);
        if (data->pcProp != NULL) {
            FieldChunkPropHolder_CallAnmCmd(FieldG3DMapper_GetBMSystem(Field_GetG3DMapper(data->field)), data->pcProp,
                                            1, 2);
        }
        (*state)++;
        break;
    case 3:
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
