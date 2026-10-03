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

FieldDispControl *FieldDispControl_Create(HeapID heapId) {
    FieldDispControl *control;

    control = GFL_HeapAllocate(heapId, sizeof(FieldDispControl), TRUE, "fld_vreq.c", 128);
    sys_memset(control->bgEnabled, 0xff, sizeof(control->bgEnabled));
    return control;
}

void FieldDispControl_Free(FieldDispControl *control) {
    GFL_HeapFree(control);
}

void FieldDispControl_Update(FieldDispControl *control) {
    void (*proc)(void *, u32);
    s32 i;

    proc = FIELD_DISP_CONTROL_PROCS[control->requestA];
    if (proc != NULL) {
        proc(&control->alphaA, 1);
        control->requestA = 0;
    }

    proc = FIELD_DISP_CONTROL_PROCS[control->requestB];
    if (proc != NULL) {
        proc(&control->alphaB, 0);
        control->requestB = 0;
    }

    for (i = 0; i < 8; i++) {
        if (control->bgEnabled[i] != 0xff) {
            GFL_BGSysSetBGEnabled(i, control->bgEnabled[i]);
            control->bgEnabled[i] = 0xff;
        }
    }

    if (control->brightnessRequest[0] != 0) {
        GFXRegSetMasterBrightness(REG_MASTER_BRIGHT_ADDR, control->brightnessValue[0]);
        control->brightnessRequest[0] = 0;
    }
    if (control->brightnessRequest[1] != 0) {
        GFXRegSetMasterBrightness(REG_DB_MASTER_BRIGHT_ADDR, control->brightnessValue[1]);
        control->brightnessRequest[1] = 0;
    }
}

void FieldDispControl_ReqSetBGEnabled(FieldDispControl *control, u32 bgId, BOOL enabled) {
    u8 *target = (u8 *)control + bgId;

    ((FieldDispControl *)target)->bgEnabled[0] = enabled;
}

void FieldDispControl_ReqSetAlphaA(FieldDispControl *control, u32 alpha, u32 beta, u32 planeMask, u32 complement) {
    control->requestA = 2;
    control->alphaA = alpha;
    control->betaA = beta;
    control->planeMaskA = planeMask;
    control->complementA = complement;
}

void FieldDispControl_ReqSetAllA(FieldDispControl *control, u32 alpha, u32 beta, u32 planeMask, u32 complement,
                                 u32 all) {
    control->requestA = 4;
    control->alphaA = alpha;
    control->betaA = beta;
    control->planeMaskA = planeMask;
    control->complementA = complement;
    control->allA = all;
}

void FieldDispControl_ReqAdjustAlphaA(FieldDispControl *control, u32 alpha, u32 complement) {
    control->requestA = 5;
    control->alphaA = alpha;
    control->betaA = complement;
}

void FieldDispControl_ReqSetAlphaB(FieldDispControl *control, u32 alpha, u32 beta, u32 planeMask, u32 complement) {
    control->requestB = 2;
    control->alphaB = alpha;
    control->betaB = beta;
    control->planeMaskB = planeMask;
    control->complementB = complement;
}

void FieldDispControlProc_ResetBrightness(void *params, u32 screen) {
    if (screen != 0) {
        *(vu16 *)REG_BLDCNT_ADDR = 0;
    } else {
        *(vu16 *)REG_DB_BLDCNT_ADDR = 0;
    }
}

void FieldDispControlProc_SetAlpha(const u32 *params, u32 screen) {
    if (screen != 0) {
        gfxRegSetAlphaBlend(REG_BLDCNT_ADDR, params[0], params[1], params[2], params[3]);
    } else {
        gfxRegSetAlphaBlend(REG_DB_BLDCNT_ADDR, params[0], params[1], params[2], params[3]);
    }
}

void FieldDispControlProc_SetBrightness(const u32 *params, u32 screen) {
    if (screen != 0) {
        gfxRegSetBrightnessBlend(REG_BLDCNT_ADDR, params[0], params[1]);
    } else {
        gfxRegSetBrightnessBlend(REG_DB_BLDCNT_ADDR, params[0], params[1]);
    }
}

void FieldDispControlProc_SetAll(const u32 *params, u32 screen) {
    if (screen != 0) {
        gfxRegSetBlend(REG_BLDCNT_ADDR, params[0], params[1], params[2], params[3], params[4]);
    } else {
        gfxRegSetBlend(REG_DB_BLDCNT_ADDR, params[0], params[1], params[2], params[3], params[4]);
    }
}

void FieldDispControlProc_AdjustAlpha(const u32 *params, u32 screen) {
    if (screen != 0) {
        *(vu16 *)REG_BLDALPHA_ADDR = params[0] | (params[1] << 8);
    } else {
        *(vu16 *)REG_DB_BLDALPHA_ADDR = params[0] | (params[1] << 8);
    }
}

void FieldDispControlProc_AdjustBrightness(const u32 *params, u32 screen) {
    if (screen != 0) {
        gfxRegAdjustBrightnessBlend(REG_BLDCNT_ADDR, params[0]);
    } else {
        gfxRegAdjustBrightnessBlend(REG_DB_BLDCNT_ADDR, params[0]);
    }
}
