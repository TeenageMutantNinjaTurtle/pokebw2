#include "types.h"
#include "field/fest_mission_data.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/msg.h"

FestivalText *getTextFileForFestMissions(HeapID heapId) {
    FestivalText *text = GFL_HeapAllocate(heapId, sizeof(FestivalText), TRUE, "fest_mission_data.c", 0x46);
    text->archive = GFL_ArcSysCreateFileHandle(0x121, heapId);
    text->message = GFL_MsgSysLoadData(FALSE, 2, 0x24, heapId);
    return text;
}

void func_ov027_02170b00(FestivalText *text) {
    GFL_MsgDataFree(text->message);
    GFL_ArcToolFree(text->archive);
    GFL_HeapFree(text);
}

void *func_ov027_02170b18(ArcTool *arc, HeapID heapId) {
    return GFL_ArcToolReadHeapNew(arc, 0, heapId);
}

void func_ov027_02170b24(ArcTool *arc, u8 index, FestMissionData *dest) {
    GFL_ArcToolReadRange(arc, 0, index * sizeof(dest->unk00), sizeof(dest->unk00), &dest->unk00);
    GFL_ArcToolReadRange(arc, 1, index * sizeof(dest->unk04), sizeof(dest->unk04), dest->unk04);
}

FestMissionData *func_ov027_02170b50(ArcTool *arc, HeapID heapId) {
    s32 i;
    FestMissionData *missions;

    missions = GFL_HeapAllocate(heapId, sizeof(FestMissionData) * FEST_MISSION_COUNT, TRUE, "fest_mission_data.c", 0x91);
    for (i = 0; i < FEST_MISSION_COUNT; i++) {
        func_ov027_02170b24(arc, i, &missions[i]);
    }
    return missions;
}

FestMissionData *func_ov027_02170b8c(FestivalText *text, HeapID heapId) {
    return func_ov027_02170b50(text->archive, heapId);
}
