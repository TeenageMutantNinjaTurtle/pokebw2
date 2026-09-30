#ifndef POKEBW2_NITRO_GX_H
#define POKEBW2_NITRO_GX_H

#include "types.h"

// The parts of NitroSDK's graphics registers and inline functions that the game's code uses

typedef u16 GXRgb;

#define GX_RGB(r, g, b) ((GXRgb)((r) | ((g) << 5) | ((b) << 10)))

#define reg_GX_DISPCNT (*(vu32 *)0x04000000)
#define reg_G2_BG0CNT (*(vu16 *)0x04000008)
#define reg_G2_BLDCNT (*(vu16 *)0x04000050)
#define reg_G2_BLDALPHA (*(vu16 *)0x04000052)
#define reg_G3X_DISP3DCNT (*(vu16 *)0x04000060)
#define reg_G3_VIEWPORT (*(vu32 *)0x04000580)
#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)
#define reg_G2S_DB_BLDCNT (*(vu16 *)0x04001050)

#define REG_GX_DISPCNT_W0_SHIFT 13
#define REG_GX_DISPCNT_W0_MASK 0x00002000
#define REG_GX_DISPCNT_W1_MASK 0x00004000
#define REG_GX_DISPCNT_OW_MASK 0x00008000

#define REG_G2_BG0CNT_PRIORITY_SHIFT 0
#define REG_G2_BG0CNT_PRIORITY_MASK 0x0003

#define REG_G3X_DISP3DCNT_THS_SHIFT 1
#define REG_G3X_DISP3DCNT_THS_MASK 0x0002
#define REG_G3X_DISP3DCNT_ATE_MASK 0x0004
#define REG_G3X_DISP3DCNT_ABE_MASK 0x0008
#define REG_G3X_DISP3DCNT_AAE_MASK 0x0010
#define REG_G3X_DISP3DCNT_EME_MASK 0x0020
#define REG_G3X_DISP3DCNT_RO_MASK 0x1000
#define REG_G3X_DISP3DCNT_GO_MASK 0x2000

#define GX_WNDMASK_NONE 0x00

#define GX_OAM_MODE_NORMAL 0
#define GX_OAM_MODE_XLU 1

#define GX_PLANEMASK_BG0 0x01
#define GX_PLANEMASK_BG1 0x02
#define GX_PLANEMASK_BG2 0x04
#define GX_PLANEMASK_BG3 0x08
#define GX_PLANEMASK_OBJ 0x10

#define GX_DISPMODE_GRAPHICS 1
#define GX_BGMODE_0 0
#define GX_BG0_AS_2D 0
#define GX_BG0_AS_3D 1

#define GX_SHADING_TOON 0
#define GX_SHADING_HIGHLIGHT 1

#define GX_SORTMODE_AUTO 0
#define GX_SORTMODE_MANUAL 1
#define GX_BUFFERMODE_Z 0
#define GX_BUFFERMODE_W 1

// VRAM banks, as masks
#define GX_VRAM_NONE 0x000
#define GX_VRAM_A 0x001
#define GX_VRAM_B 0x002
#define GX_VRAM_C 0x004
#define GX_VRAM_D 0x008
#define GX_VRAM_E 0x010
#define GX_VRAM_F 0x020
#define GX_VRAM_G 0x040
#define GX_VRAM_H 0x080
#define GX_VRAM_I 0x100

#define GX_VRAM_BG_NONE GX_VRAM_NONE
#define GX_VRAM_BG_16_F GX_VRAM_F
#define GX_VRAM_BG_128_A GX_VRAM_A
#define GX_VRAM_BG_128_D GX_VRAM_D
#define GX_VRAM_BGEXTPLTT_NONE GX_VRAM_NONE
#define GX_VRAM_SUB_BG_32_H GX_VRAM_H
#define GX_VRAM_SUB_BGEXTPLTT_NONE GX_VRAM_NONE
#define GX_VRAM_OBJ_16_G GX_VRAM_G
#define GX_VRAM_OBJ_64_E GX_VRAM_E
#define GX_VRAM_OBJ_128_B GX_VRAM_B
#define GX_VRAM_OBJEXTPLTT_NONE GX_VRAM_NONE
#define GX_VRAM_SUB_OBJ_16_I GX_VRAM_I
#define GX_VRAM_SUB_OBJEXTPLTT_NONE GX_VRAM_NONE
#define GX_VRAM_TEX_01_CD (GX_VRAM_C | GX_VRAM_D)
#define GX_VRAM_TEX_012_ABC (GX_VRAM_A | GX_VRAM_B | GX_VRAM_C)
#define GX_VRAM_TEX_0123_ABCD (GX_VRAM_A | GX_VRAM_B | GX_VRAM_C | GX_VRAM_D)
#define GX_VRAM_TEXPLTT_0_G GX_VRAM_G
#define GX_VRAM_TEXPLTT_0123_E GX_VRAM_E

#define GX_OBJVRAMMODE_CHAR_1D_32K 0x00000010
#define GX_OBJVRAMMODE_CHAR_1D_64K 0x00100010
#define GX_OBJVRAMMODE_CHAR_1D_128K 0x00200010

#define GX_BG_COLORMODE_16 0
#define GX_BG_COLORMODE_256 1

// The screen base in units of 0x800 bytes, and the character base in units of 0x4000
#define GX_BG_SCRBASE(offset) ((offset) / 0x800)
#define GX_BG_CHARBASE(offset) ((offset) / 0x4000)

#define GX_BG_EXTPLTT_01 0
#define GX_BG_EXTPLTT_23 1

#define GX_BG_AREAOVER_XLU 0
#define GX_BG_AREAOVER_REPEAT 1

#define GX_PACK_VIEWPORT_PARAM(x1, y1, x2, y2) \
    ((u32)(x1) | ((u32)(y1) << 8) | ((u32)(x2) << 16) | ((u32)(y2) << 24))

static inline void GX_SetVisibleWnd(int window) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_W0_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_OW_MASK)) |
                     (window << REG_GX_DISPCNT_W0_SHIFT);
}

static inline void GXS_SetVisibleWnd(int window) {
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GX_DISPCNT_W0_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_OW_MASK)) |
        (window << REG_GX_DISPCNT_W0_SHIFT);
}

static inline void G2_BlendNone(void) {
    reg_G2_BLDCNT = 0;
}

static inline void G2S_BlendNone(void) {
    reg_G2S_DB_BLDCNT = 0;
}

static inline void G2_SetBG0Priority(int priority) {
    reg_G2_BG0CNT =
        (u16)((reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | (priority << REG_G2_BG0CNT_PRIORITY_SHIFT));
}

static inline void G3X_SetShading(int shading) {
    reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_THS_MASK | REG_G3X_DISP3DCNT_RO_MASK |
                                                     REG_G3X_DISP3DCNT_GO_MASK)) |
                              (shading << REG_G3X_DISP3DCNT_THS_SHIFT));
}

static inline void G3X_AntiAlias(BOOL enable) {
    if (enable) {
        reg_G3X_DISP3DCNT =
            (u16)((reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK)) |
                  REG_G3X_DISP3DCNT_AAE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= ~(REG_G3X_DISP3DCNT_AAE_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}

static inline void G3X_AlphaTest(BOOL enable, int ref) {
    if (enable) {
        reg_G3X_DISP3DCNT =
            (u16)((reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK)) |
                  REG_G3X_DISP3DCNT_ATE_MASK);
        *(vu8 *)0x04000340 = (u8)ref;
    } else {
        reg_G3X_DISP3DCNT &= ~(REG_G3X_DISP3DCNT_ATE_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}

static inline void G3X_AlphaBlend(BOOL enable) {
    if (enable) {
        reg_G3X_DISP3DCNT =
            (u16)((reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK)) |
                  REG_G3X_DISP3DCNT_ABE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= ~(REG_G3X_DISP3DCNT_ABE_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}

static inline void G3X_EdgeMarking(BOOL enable) {
    if (enable) {
        reg_G3X_DISP3DCNT =
            (u16)((reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK)) |
                  REG_G3X_DISP3DCNT_EME_MASK);
    } else {
        reg_G3X_DISP3DCNT &= ~(REG_G3X_DISP3DCNT_EME_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}

static inline void G3_ViewPort(int x1, int y1, int x2, int y2) {
    reg_G3_VIEWPORT = GX_PACK_VIEWPORT_PARAM(x1, y1, x2, y2);
}

#endif // POKEBW2_NITRO_GX_H
