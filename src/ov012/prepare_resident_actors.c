#include "field/field_actor.h"
#include "system/game_event.h"
#include "system/game_system.h"

struct PrepareResidentActorsWork {
    GameSystem *gameSystem;
    Field *field;
    GameData *gameData;
    u32 unkC;
};

GameEvent *CallEventPrepareResidentActorsForZoneChange(GameSystem *gsys, Field *field) {
    GameEvent *event = GameEvent_Create(gsys, NULL, func_ov012_0215c59c, sizeof(PrepareResidentActorsWork));
    PrepareResidentActorsWork *work = GameEvent_GetData(event);
    work->gameSystem = gsys;
    work->field = field;
    work->gameData = GSYS_GetGameData(gsys);
    return event;
}
