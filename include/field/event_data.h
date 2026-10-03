#ifndef POKEBW2_FIELD_EVENT_DATA_H
#define POKEBW2_FIELD_EVENT_DATA_H

// Names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct EventDataFlags {
    u8 low : 7;
    u8 high : 1;
};

struct EventData {
    u8 unk0[4];
    ArcTool *entityArc;
    ArcTool *encArc;
    ArcTool *otherArc;
    u16 zoneId;
    u8 unk12[0x22];
    u32 encLoaded;
    u8 encData[7];
    EventDataFlags encDataFlags;
    u8 encDataTail[0xe0];
    void *initScript;
    u8 rest[0x984];
};

extern const char data_ov012_0216e298[];

EventData *EventData_Create(HeapID heapId);
void EventData_Free(EventData *data);
void EventData_Clear(EventData *data);
void EventData_Reset(EventData *data);
void EventData_LoadZone(EventData *data, u16 zoneId, u8 season);
void EventData_LoadEntities(EventData *data, u16 zoneId, u8 season);
void LoadZoneEntities(EventData *data, u16 zoneId, u8 season);
void EventData_LoadEncData(EventData *data, u16 zoneId, u8 season);
void *GetZoneInitScrPointer(EventData *data);
u32 IsEncountDataLoaded(EventData *data);

#endif // POKEBW2_FIELD_EVENT_DATA_H
