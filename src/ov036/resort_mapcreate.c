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

HiddenHollowWork *func_ov036_021c8954(HeapID heapId) {
    HiddenHollowWork *work;

    work = GFL_HeapAllocate(heapId, sizeof(HiddenHollowWork), TRUE, "resort_mapcreate.c", 73);
    work->heapId = heapId;
    work->unk04 = 0xffff;
    return work;
}

void func_ov036_021c897c(HiddenHollowWork *work) {
    GFL_HeapFree(work);
}

void func_ov036_021c8984(HiddenHollowWork *work, u32 a1, u32 a2, u32 a3) {
    work->unk04 = a1;
    work->unk08 = a2;
    work->unk0c = a3;
}

u32 func_ov036_021c898c(HiddenHollowWork *work, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6) {
    if (IsZoneJoinAvenue((u16)work->unk04)) {
        return func_ov036_021c89cc(work, a1, a2, a3, a4, a5, a6);
    }
    return a4;
}
