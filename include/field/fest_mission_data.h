#ifndef POKEBW2_FIELD_FEST_MISSION_DATA_H
#define POKEBW2_FIELD_FEST_MISSION_DATA_H

#include "types.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "struct_decls.h"

// The Funfest missions' data and text, overlay 27's fest_mission_data.c

struct FestivalText {
    ArcTool *archive;
    MsgData *message;
};

// A mission, from files 0 and 1 of the missions' archive
typedef struct {
    u32 unk00;
    u8 unk04[40];
} FestMissionData;

#define FEST_MISSION_COUNT 55

FestivalText *getTextFileForFestMissions(HeapID heapId);
void func_ov027_02170b00(FestivalText *text);
void *func_ov027_02170b18(ArcTool *arc, HeapID heapId);
void func_ov027_02170b24(ArcTool *arc, u8 index, FestMissionData *dest);
// All the missions
FestMissionData *func_ov027_02170b50(ArcTool *arc, HeapID heapId);
FestMissionData *func_ov027_02170b8c(FestivalText *text, HeapID heapId);

#endif // POKEBW2_FIELD_FEST_MISSION_DATA_H
