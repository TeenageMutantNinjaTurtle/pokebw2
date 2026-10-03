#include "field/field_display_control.h"
#include "gfl/graphics.h"
#include "nitro/hw.h"

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
