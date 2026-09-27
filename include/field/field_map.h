#ifndef POKEBW2_FIELD_FIELD_MAP_H
#define POKEBW2_FIELD_FIELD_MAP_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

AreaData *AreaData_Create(HeapID heapId, u16 areaId, u32 a2);
void AreaData_Free(AreaData *areaData);
BOOL AreaData_IsExterior(AreaData *areaData);
void EventData_LoadZone(EventData *eventData, u16 zoneId, u8 season);
void GimmickState_Reset(GimmickState *gimmick);
void GimmickState_SetID(GimmickState *gimmick, u16 gimmickId);
void MapMatrix_Load(MapMatrix *matrix, u16 matrixId, u16 zoneId, HeapID heapId);
void MapMatrix_Patch(MapMatrix *matrix, GameSystem *gsys, HeapID heapId);
void ResetWeather(GameSystem *gsys, s32 zoneId);
void UpdateWeatherToDefault(GameData *gameData, u16 zoneId);

#endif // POKEBW2_FIELD_FIELD_MAP_H
