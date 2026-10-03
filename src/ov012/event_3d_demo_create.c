#include "field/event_3d_demo.h"
#include "gfl/std.h"
#include "system/game_comm.h"
#include "system/game_event.h"
#include "system/game_system.h"

GameEvent *Event3DDemo_Create(GameSystem *gsys, GameEvent *parent, u32 demoId, u32 param, u32 realTime) {
    GameEvent *event = GameEvent_Create(gsys, parent, Event3DDemo_Callback, sizeof(Event3DDemoWork));
    Event3DDemoWork *work = GameEvent_GetData(event);
    sys_memset(work, 0, sizeof(Event3DDemoWork));
    work->gameSystem = gsys;
    work->gameCommSys = GSYS_GetGameCommSystem(gsys);
    work->demoId = demoId;
    if (realTime) {
        SetupPlaySequenceEventRealTime(work->sequence, gsys, demoId, param);
    } else {
        SetupPlaySequenceEventGameTime(work->sequence, gsys, demoId, param);
    }
    if (demoId == 3) {
        GameBeacon_BroadcastFerrisWheel();
    }
    return event;
}
