#include "types.h"
#include "gfl/arc.h"
#include "gfl/heap.h"
#include "gfl/msg.h"

typedef struct {
    ArcTool *archive;
    MsgData *message;
} FestivalText;

extern const char data_ov027_021711e0[];

u32 GetTrainerCardTextMSGID(u32 type);
FestivalText *getTextFileForFestMissions(HeapID heapId);

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
