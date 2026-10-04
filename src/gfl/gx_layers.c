#include "types.h"
#include "gfl/graphics.h"
#include "gfl/gx_layers.h"
#include "gfl/std.h"
#include "nitro/gx.h"
#include "nitro/hw.h"

// The planes shown on each engine, GX_PLANEMASK_*, kept so that one can be shown or hidden without the others
static struct {
    u32 sub;
    u32 main;
} sEnabledPlanes;

void GFL_BGSysInitVRAM(u32 banks) {
    gfxSetLCDCBanks(GX_VRAM_LCDC_ALL & (banks ^ 0xffff));
    sys_memset32_fast(0, (void *)HW_LCDC_VRAM, HW_LCDC_VRAM_SIZE);
    gfxDisableLCDCBanks();
    sys_memset32_fast(0xc0, (void *)HW_OAM, HW_OAM_SIZE);
    sys_memset32_fast(0, (void *)HW_BG_PLTT, HW_PLTT_SIZE);
    sys_memset32_fast(0xc0, (void *)HW_DB_OAM, HW_OAM_SIZE);
    sys_memset32_fast(0, (void *)HW_DB_BG_PLTT, HW_PLTT_SIZE);
}

void GFL_BGSysSetVRAMBanks(const BGSysVRAMConfig *config) {
    gfxAcquireBGBanksA();
    gfxAcquireBGExtPltBanksA();
    gfxAcquireBGBanksB();
    gfxAcquireBGExtPltBanksB();
    gfxAcquireObjBanksA();
    gfxAcquireObjExtPltBanksA();
    gfxAcquireObjBanksB();
    gfxAcquireObjExtPltBanksB();
    gfxAcquireTextureBanks();
    gfxAcquirePaletteBanks();
    gfxSetBGBanksA(config->bgMain);
    gfxSetBGExtPltBanksA(config->bgExtPaletteMain);
    gfxSetBGBanksB(config->bgSub);
    gfxSetBGExtPltBanksB(config->bgExtPaletteSub);
    gfxSetObjBanksA(config->objMain);
    gfxSetObjExtPltBanksA(config->objExtPaletteMain);
    gfxSetObjBanksB(config->objSub);
    gfxSetObjExtPltBanksB(config->objExtPaletteSub);
    gfxSetTextureBanks(config->texture);
    gfxSetPaletteBanks(config->texturePalette);
    GX_SetOBJVRamModeChar(config->objMappingMain);
    GXS_SetOBJVRamModeChar(config->objMappingSub);
}

void GFL_BGSysDisableBGsA(void) {
    sEnabledPlanes.main &= GX_PLANEMASK_OBJ;
}

void GFL_BGSysDisableOBJA(void) {
    sEnabledPlanes.main &= GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3;
}

void GFL_BGSysDisableAllA(void) {
    GFL_BGSysDisableBGsA();
    GFL_BGSysDisableOBJA();
}

void GFL_BGSysSetBGEnabledA(u32 planes, BOOL enabled) {
    if (enabled == TRUE) {
        if (sEnabledPlanes.main & planes) {
            return;
        }
    } else {
        if (!(sEnabledPlanes.main & planes)) {
            return;
        }
    }
    sEnabledPlanes.main ^= planes;
    GX_SetVisiblePlane(sEnabledPlanes.main);
}

void GFL_BGSysSetEnabledBGsA(u32 enabled) {
    sEnabledPlanes.main = enabled;
    GX_SetVisiblePlane(sEnabledPlanes.main);
}

void GFL_BGSysDisableBGsB(void) {
    sEnabledPlanes.sub &= GX_PLANEMASK_OBJ;
}

void GFL_BGSysDisableOBJB(void) {
    sEnabledPlanes.sub &= GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3;
}

void GFL_BGSysDisableAllB(void) {
    GFL_BGSysDisableBGsB();
    GFL_BGSysDisableOBJB();
}

void GFL_BGSysSetBGEnabledB(u32 planes, BOOL enabled) {
    if (enabled == TRUE) {
        if (sEnabledPlanes.sub & planes) {
            return;
        }
    } else {
        if (!(sEnabledPlanes.sub & planes)) {
            return;
        }
    }
    sEnabledPlanes.sub ^= planes;
    GXS_SetVisiblePlane(sEnabledPlanes.sub);
}

void GFL_BGSysSetEnabledBGsB(u32 enabled) {
    sEnabledPlanes.sub = enabled;
    GXS_SetVisiblePlane(sEnabledPlanes.sub);
}

void GFL_BGSysEnableEngines(void) {
    gfxEngineEnableA();
    GXS_DispOn();
}

void GFL_BGSysSetDisplayLayout(u32 layout) {
    GX_SetDispSelect(layout);
}

u32 GFL_BGSysGetEnabledBGsA(void) {
    return sEnabledPlanes.main;
}

u32 GFL_BGSysGetEnabledBGsB(void) {
    return sEnabledPlanes.sub;
}
