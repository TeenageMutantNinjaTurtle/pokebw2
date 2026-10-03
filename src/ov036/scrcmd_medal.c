#include "types.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/sound.h"
#include "constants/species.h"
#include "field/day_care.h"
#include "field/encounter_effect.h"
#include "field/festival.h"
#include "field/field.h"
#include "field/field_3d_ci.h"
#include "field/field_actor.h"
#include "field/field_async_proc.h"
#include "field/field_controller.h"
#include "field/field_display_control.h"
#include "field/field_effects.h"
#include "field/field_environment.h"
#include "field/field_exp_obj.h"
#include "field/field_internal.h"
#include "field/field_lens_flare.h"
#include "field/field_lifecycle.h"
#include "field/field_map.h"
#include "field/field_palace.h"
#include "field/field_player.h"
#include "field/field_pokemon_form.h"
#include "field/field_prop.h"
#include "field/field_render.h"
#include "field/field_script.h"
#include "field/field_state.h"
#include "field/field_visuals.h"
#include "field/hidden_hollow.h"
#include "field/medal.h"
#include "field/skill_map_effect.h"
#include "field/unity_tower.h"
#include "field/zone.h"
#include "field/zone_data.h"
#include "gfl/arc.h"
#include "gfl/g3d.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "gfl/sound.h"
#include "gfl/std.h"
#include "nitro/fx.h"
#include "nitro/hw.h"
#include "pml/poke_party.h"
#include "save/event_work.h"
#include "save/medal_box.h"
#include "save/records.h"
#include "save/save_control.h"
#include "system/aeabi.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/rtc.h"
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
            return *(u16 *)((u8 *)npcs + i * sizeof(ZoneNPC));
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
