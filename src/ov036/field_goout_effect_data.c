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

#define RESOURCE_AT(symbol) (*(const u16 *)((const u8 *)(symbol) + effectSet * 12))

FieldLensFlareData *FieldLensFlareData_Create(HeapID heapId) {
    FieldLensFlareData *data;

    data = GFL_HeapAllocate(heapId, sizeof(FieldLensFlareData), TRUE, "field_goout_effect_data.c", 57);
    data->entries = GFL_ArcSysReadHeapNewLZGetLen(0xf1, 0, 0, heapId, &data->byteCount);
    return data;
}

void FieldLensFlareData_Free(FieldLensFlareData *data) {
    GFL_HeapFree(data->entries);
    GFL_HeapFree(data);
}

u16 FieldLensFlare_GetEffectSetID(FieldLensFlareData *data, u32 entryIndex, u32 effectIndex, u32 subIndex) {
    FieldLensFlareEntry *entry;

    entry = FieldLensFlareData_GetEntry(data, entryIndex);
    return entry->effectSetIds[effectIndex][subIndex];
}

u32 FieldLensFlareData_BytesToEntryCount(FieldLensFlareData *data) {
    return __aeabi_uidivmod(data->byteCount, sizeof(FieldLensFlareEntry));
}

u16 FieldLensFlareData_GetLensFlareID(FieldLensFlareData *data, u32 effectSet, u32 index) {
    return data_ov036_021d4768[effectSet][index];
}

u8 FieldLensFlareData_GetEffectSetSize(FieldLensFlareData *data, u32 effectSet) {
    int index;

    for (index = 0; index < 4; index++) {
        if (FieldLensFlareData_GetLensFlareID(data, effectSet, index) == 8) {
            break;
        }
    }
    return index;
}

u16 FieldLensFlareData_GetResDatID(FieldLensFlareData *data, u32 effectSet, u32 index) {
    switch (index) {
    case 0:
        return RESOURCE_AT(LENS_FLARE_RESOURCE_IDS);
    case 1:
        return RESOURCE_AT(data_ov036_021d47ba);
    case 2:
        return RESOURCE_AT(data_ov036_021d47bc);
    case 3:
        return RESOURCE_AT(data_ov036_021d47be);
    case 4:
        return RESOURCE_AT(data_ov036_021d47c0);
    default:
        return 0;
    }
}

FieldLensFlareEntry *FieldLensFlareData_GetEntry(FieldLensFlareData *data, u32 index) {
    return &data->entries[index];
}

u32 FieldLensFlareData_GetIdxForZoneTransit(FieldLensFlareData *data, u16 zoneId, u16 transitId) {
    u32 index;
    FieldLensFlareEntry *entry;

    index = 0;
    while (index < FieldLensFlareData_BytesToEntryCount(data)) {
        entry = FieldLensFlareData_GetEntry(data, index);
        if (entry->zoneId == zoneId && entry->transitId == transitId) {
            break;
        }
        index++;
    }
    return index;
}
