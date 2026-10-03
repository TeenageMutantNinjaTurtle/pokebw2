#include "field/event_data.h"
#include "field/zone.h"

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
