#include "field/event_data.h"
#include "field/zone.h"

void func_ov012_0215d4d0(const ZoneBGEntity *entity, VecFx32 *position) {
    func_ov012_0215d88c(entity, position);
    position->x += 0x8000;
    position->z += 0x8000;
}

void func_ov012_0215d4ec(const ZoneBGEntity *entity, RailPosition *position) {
    func_ov012_0215d8fc(entity, position);
}

void GetTriggerCenterPos(const ZoneTrigger *trigger, VecFx32 *position) {
    GetTriggerCenterPos_(trigger, position);
}

void SetBGEntityLocation(EventData *data, u32 index, s32 x, s32 z, u16 y) {
    ZoneBGEntity *entities;
    ZoneBGEntity *entity;
    s32 *coords;

    if (data->entityCount >= index && data->entityPtr != NULL) {
        entities = data->entityPtr;
        entity = &entities[index];
        if (entity->isRail == 0) {
            coords = &entity->pos.grid.x;
            coords[0] = x;
            coords[1] = y;
            coords[2] = z << 4;
        }
    }
}
