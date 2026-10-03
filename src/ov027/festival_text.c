#include "types.h"
#include "field/festival.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/msg.h"

u32 GetTrainerCardTextMSGID(u32 type) {
    switch (type) {
    case 0:
        return 0x179;
    case 1:
        return 0x17a;
    case 2:
        return 0x17b;
    case 3:
        return 0x17c;
    case 4:
        return 0x17d;
    case 5:
        return 0x17e;
    }
    return 0;
}

FestivalText *getTextFileForFestMissions(HeapID heapId) {
    FestivalText *text = GFL_HeapAllocate(heapId, sizeof(FestivalText), TRUE, data_ov027_021711e0, 0x46);
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
    data = GFL_HeapAllocate(heapId, 0x974, TRUE, data_ov027_021711e0, 0x91);
    for (i = 0; i < 0x37; i++) {
        func_ov027_02170b24(arc, i, data + 0x2c * i);
    }
    return data;
}

void *func_ov027_02170b8c(FestivalText *text, HeapID heapId) {
    return func_ov027_02170b50(text->archive, heapId);
}
