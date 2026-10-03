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

FieldPalaceSys *FieldPalaceSys_Create(HeapID heapId, u32 a1, u32 a2, u32 a3) {
    FieldPalaceSys *sys;

    sys = GFL_HeapAllocate(heapId, sizeof(FieldPalaceSys), TRUE, "field_palace_sys.c", 67);
    sys->unk00 = a1;
    sys->unk04 = a2;
    sys->luminanceTable = NULL;
    FieldPalaceSys_InitPostFX(sys, a3, heapId);
    return sys;
}

void FieldPalaceSys_Free(FieldPalaceSys *sys) {
    if (sys->luminanceTable != NULL) {
        GFL_HeapFree(sys->luminanceTable);
    }
    GFL_HeapFree(sys);
}

void *FieldPalaceSys_GetLuminanceTable(FieldPalaceSys *sys) {
    return sys->luminanceTable;
}

BOOL FieldPalaceSys_CheckEventFlag(GameData *gameData, u16 zoneId) {
    EventWork *eventWork;
    u32 index;

    eventWork = GameData_GetEventWork(gameData);
    if (GetZoneIsEntralinkAny(zoneId) == TRUE) {
        for (index = 0; index < 25; index++) {
            if (zoneId == *(const u16 *)((const u8 *)ENTRALINK_WORLD_ZONES + index * 4)) {
                if (EventWork_FlagGet(eventWork, *(const u16 *)((const u8 *)data_ov036_021d4706 + index * 4)) == TRUE) {
                    return TRUE;
                }
                return FALSE;
            }
        }
    }
    return TRUE;
}
