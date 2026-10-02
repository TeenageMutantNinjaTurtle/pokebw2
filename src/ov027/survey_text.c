#include "types.h"
#include "gfl/heap.h"
#include "gfl/msg.h"

typedef struct {
    HeapID heapId;
    u8 unused[0x16];
    MsgData *message;
} SurveyTextWork;

void getSurveyText(SurveyTextWork *work);

void getSurveyText(SurveyTextWork *work) {
    work->message = GFL_MsgSysLoadData(FALSE, 3, 0x33, work->heapId);
}
