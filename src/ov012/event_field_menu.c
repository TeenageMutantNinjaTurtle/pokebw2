#include "types.h"
#include "field/field.h"
#include "field/field_menu.h"
#include "field/subscreen.h"
#include "field/zone.h"
#include "gfl/input.h"
#include "gfl/std.h"
#include "system/game_event.h"

GameEvent *EventFieldMenu_Create(GameSystem *gsys, Field *field, u16 param) {
    FieldSubscreen *subscreen = Field_GetSubscreen(field);
    GameEvent *event = GameEvent_Create(gsys, NULL, EventFieldMenu_Callback, sizeof(FieldMenuWork));
    FieldMenuWork *work = GameEvent_GetData(event);
    u32 screenId;

    sys_memset(work, 0, sizeof(FieldMenuWork));
    work->gameSystem = gsys;
    work->event = event;
    work->field = field;
    work->code = param;
    work->unk14 = 0;
    work->gameSystem2 = gsys;
    work->field2 = field;
    work->event2 = event;
    work->callback34 = func_ov012_0215aa74;
    work->callback38 = func_ov012_0215aa90;
    work->callback3C = func_ov012_0215aa94;
    work->self = work;
    work->unk30 = -1;
    screenId = FieldSubscreen_GetScreenID(subscreen);
    switch (screenId) {
    case 4:
        work->screenId = 4;
        break;
    case 10:
        work->screenId = 10;
        break;
    default:
        work->screenId = FieldSubscreen_GetIDForChange(Field_GetSubscreen(work->field), 0);
        break;
    }
    work->prevScreenId = work->screenId;
    func_0203d564(TRUE);
    return event;
}

GameEvent *EventFieldMenu_CreateUnionRoom(GameSystem *gsys, Field *field, u16 param) {
    GameEvent *event = EventFieldMenu_Create(gsys, field, param);
    FieldMenuWork *work = GameEvent_GetData(event);
    u16 zoneId = Field_GetPlayerStateZoneID(field);

    if (IsZone150Or151(zoneId) == 1) {
        work->screenId = 5;
    } else {
        work->screenId = 2;
    }
    return event;
}
