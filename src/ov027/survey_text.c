#include "types.h"
#include "field/survey.h"
#include "gfl/heap.h"
#include "gfl/msg.h"

void getSurveyText(SurveyTextWork *work) {
    work->message = GFL_MsgSysLoadData(FALSE, 3, 0x33, work->heapId);
}
