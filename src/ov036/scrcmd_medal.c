#include "types.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_internal.h"
#include "field/field_script.h"
#include "field/medal.h"
#include "gfl/heap.h"
#include "save/medal_box.h"
#include "system/game_data.h"
#include "system/vm.h"

FieldActor *GetMrMedalActorIndex(Field *field) {
    MMSys *actorSystem;
    u32 index;
    FieldActor *actor;

    index = 0;
    actorSystem = Field_GetActorSystem(field);
    if (NextActor(actorSystem, &actor, &index) == TRUE) {
        do {
            if (FldAct_GetSCRID(actor) == 0x298e) {
                return actor;
            }
        } while (NextActor(actorSystem, &actor, &index) == TRUE);
    }
    return NULL;
}

u32 GetMrMedalActorUID(GameData *gameData) {
    EventData *eventData;
    ZoneNPC *npcs;
    s32 count;
    s32 i;

    eventData = GameData_GetEventData(gameData);
    npcs = GetZoneNPCs(eventData);
    count = GetZoneNPCsCount(eventData);
    if (npcs == NULL || count == 0) {
        return -1;
    }
    for (i = 0; i < count; i++) {
        if (npcs[i].scrId == 0x298e) {
            return npcs[i].uid;
        }
    }
    return -1;
}

BOOL s02E1_MedalDiscoverInitial(VM *vm, FieldScriptEnv *env) {
    GameData *gameData;
    SaveControl *save;
    MedalBox *box;
    HeapID heapId;

    gameData = FieldScriptEnv_GetGameData(env);
    save = GameData_GetSaveControl(gameData);
    box = SaveControl_GetMedalBox(save);
    heapId = FieldScriptEnv_GetHeapID(env);
    DiscoverInitialMedals(box, heapId);
    return FALSE;
}
