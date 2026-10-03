#include "field/event_data.h"
#include "field/zone.h"
#include "save/event_work.h"

void *GetZoneProxiesAndCount(EventData *data, u32 *restrict count) {
    *count = data->entityCount;
    return data->entityPtr;
}

s32 CheckProxyEntityEvent(EventData *data, EventWork *eventWork, const void *position, u16 direction) {
    ZoneBGEntity *entity;
    u16 alternateDirection;
    u16 count;
    u16 i;
    u16 flag;

    entity = data->entityPtr;
    if (entity != NULL) {
        i = 0;
        if ((count = data->entityCount) > i) {
            alternateDirection = direction + 0xfffe;
            do {
                if (((u16 *)entity)[1] >= 3) {
                    goto next;
                }
                if (entity->isRail == 0) {
                    if (!CheckBGPositionMatchGrid(entity, position)) {
                        goto next;
                    }
                } else if (!CheckBGPositionMatchRail(entity, position)) {
                    goto next;
                }
                if (((u16 *)entity)[1] == 2) {
                    flag = GetHiddenItemEventFlagNoBySCRID(((u16 *)entity)[0]);
                    if (EventWork_FlagGet(eventWork, flag)) {
                        goto next;
                    }
                    return ((u16 *)entity)[0];
                }
                switch (entity->direction) {
                case 0:
                    if (direction == 0) return ((u16 *)entity)[0];
                    break;
                case 1:
                    if (direction == 3) return ((u16 *)entity)[0];
                    break;
                case 2:
                    if (direction == 2) return ((u16 *)entity)[0];
                    break;
                case 3:
                    if (direction == 1) return ((u16 *)entity)[0];
                    break;
                case 4:
                    return ((u16 *)entity)[0];
                case 5:
                    if (alternateDirection <= 1) return ((u16 *)entity)[0];
                    break;
                case 6:
                    if (direction <= 1) return ((u16 *)entity)[0];
                    break;
                }
            next:
                i++;
                entity++;
            } while (i < count);
        }
    }
    return 0xffff;
}

s32 CheckProxyEntityEventGrid(EventData *data, EventWork *eventWork, const VecFx32 *position, u16 direction) {
    return CheckProxyEntityEvent(data, eventWork, position, direction);
}

s32 CheckProxyEntityEventRail(EventData *data, EventWork *eventWork, const RailPosition *position, u16 direction) {
    return CheckProxyEntityEvent(data, eventWork, position, direction);
}
