#include "field/event_fishing.h"
#include "field/field.h"
#include "field/field_actor.h"
#include "field/field_visuals.h"
#include "gfl/input.h"

u32 func_ov033_021795a4(FishingEventWork *work, u32 value) {
    u32 elapsed;

    elapsed = work->elapsed++;
    if (elapsed < value) {
        return 0;
    }
    work->elapsed = 0;
    return 1;
}

u32 func_ov033_021795bc(FishingEventWork *work, u32 value) {
    u32 elapsed;

    elapsed = work->elapsed++;
    if (elapsed < value) {
        if (GCTX_HIDGetPressedKeys() & PAD_BUTTON_A) {
            work->elapsed = 0;
            return 1;
        }
    } else {
        work->elapsed = 0;
        return 2;
    }
    return 0;
}

void func_ov033_021795e8(FishingEventWork *work) {
    void *effects;

    effects = Field_GetFieldEffects(work->field);
    func_ov012_021670f4(work->actor, 2);
    work->effect2C = func_ov036_021b3f14(effects, work->actor, 0, 1);
    func_ov036_021a5968(work->effect30, 1);
}

void func_ov033_02179614(FishingEventWork *work) {
    if (work->effect2C != NULL) {
        func_ov036_021a3a70(work->effect2C);
        work->effect2C = NULL;
    }
}

void func_ov033_02179628(FishingEventWork *work) {
    void *effects;
    u32 sameHeight;

    effects = Field_GetFieldEffects(work->field);
    sameHeight = 1;
    if (work->fishingPos.y != work->playerPos.y) {
        sameHeight = 0;
    }
    work->effect30 = func_ov036_021a58e0(effects, &work->fishingPos, work->faceDirection, sameHeight);
}

void func_ov033_02179650(FishingEventWork *work) {
    if (work->effect30 != NULL) {
        func_ov036_021a3a70(work->effect30);
        work->effect30 = NULL;
    }
}
