#include "types.h"
#include "field/festival.h"
#include "field/field.h"
#include "field/field_script.h"
#include "field/survey.h"
#include "gfl/arc.h"
#include "gfl/bmpwin.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/random.h"
#include "gfl/std.h"
#include "gfl/str.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"
#include "system/rtc.h"

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

void func_ov027_02170b24(ArcTool *arc, u8 index, void *dest) {
    GFL_ArcToolReadRange(arc, 0, index * 4, 4, dest);
    GFL_ArcToolReadRange(arc, 1, index * 40, 40, (u8 *)dest + 4);
}

void *func_ov027_02170b50(ArcTool *arc, HeapID heapId) {
    s32 i;
    u8 *data;
    data = GFL_HeapAllocate(heapId, 0x974, TRUE, "fest_mission_data.c", 0x91);
    for (i = 0; i < 0x37; i++) {
        func_ov027_02170b24(arc, i, data + 0x2c * i);
    }
    return data;
}

void *func_ov027_02170b8c(FestivalText *text, HeapID heapId) {
    return func_ov027_02170b50(text->archive, heapId);
}
