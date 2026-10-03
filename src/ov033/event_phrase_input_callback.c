#include "app/name_entry.h"
#include "field/event_phrase_input.h"
#include "field/field_event.h"
#include "gfl/overlay.h"
#include "gfl/str.h"

GameEventReturnCode EventPhraseInput_Callback(GameEvent *event, u32 *state, void *eventData) {
    struct EventPhraseInputData *data = eventData;

    switch (*state) {
    case 0:
        GameEvent_ChainNext(event, EventFieldSubprocessTransition_Create(data->gsys, data->field, OVERLAY_ID(280),
                                                                         &NAME_ENTRY_PROC_FUNCTIONS, &data->nameMode));
        (*state)++;
        break;
    case 1:
        func_ov033_02177734(data, &data->nameMode);
        GFL_StrBufFree(data->input);
        return GAMEEVENT_DONE;
    }
    return GAMEEVENT_CONTINUE;
}
