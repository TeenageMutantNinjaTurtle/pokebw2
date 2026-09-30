#ifndef POKEBW2_NITRO_GX_H
#define POKEBW2_NITRO_GX_H

#include "types.h"
#include "nitro/fx.h"
#include "nitro/hw.h"

// The parts of NitroSDK's graphics registers and inline functions that the game's code uses

typedef u16 GXRgb;

#define GX_RGB(r, g, b) ((GXRgb)((r) | ((g) << 5) | ((b) << 10)))

#define reg_GX_DISPCNT (*(vu32 *)0x04000000)
#define reg_G2_BG0CNT (*(vu16 *)0x04000008)
#define reg_G2_BLDCNT (*(vu16 *)0x04000050)
#define reg_G2_BLDALPHA (*(vu16 *)0x04000052)
#define reg_G3X_DISP3DCNT (*(vu16 *)0x04000060)
#define reg_GX_DISPCAPCNT (*(vu32 *)0x04000064)
#define reg_G3_MTX_MODE (*(vu32 *)0x04000440)
#define reg_G3_MTX_PUSH (*(vu32 *)0x04000444)
#define reg_G3_MTX_POP (*(vu32 *)0x04000448)
#define reg_G3_MTX_IDENTITY (*(vu32 *)0x04000454)
#define reg_G3_MTX_SCALE (*(vu32 *)0x0400046c)
#define reg_G3_MTX_TRANS (*(vu32 *)0x04000470)
#define reg_G3_NORMAL (*(vu32 *)0x04000484)
#define reg_G3_TEXCOORD (*(vu32 *)0x04000488)
#define reg_G3_VTX_16 (*(vu32 *)0x0400048c)
#define reg_G3_POLYGON_ATTR (*(vu32 *)0x040004a4)
#define reg_G3_TEXIMAGE_PARAM (*(vu32 *)0x040004a8)
#define reg_G3_TEXPLTT_BASE (*(vu32 *)0x040004ac)
#define reg_G3_DIF_AMB (*(vu32 *)0x040004c0)
#define reg_G3_SPE_EMI (*(vu32 *)0x040004c4)
#define reg_G3_BEGIN_VTXS (*(vu32 *)0x04000500)
#define reg_G3_END_VTXS (*(vu32 *)0x04000504)
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

// The planes that blending takes, which include the backdrop
#define GX_BLEND_PLANEMASK_BG0 0x01
#define GX_BLEND_PLANEMASK_BG1 0x02
#define GX_BLEND_PLANEMASK_BG2 0x04
#define GX_BLEND_PLANEMASK_BG3 0x08
#define GX_BLEND_PLANEMASK_OBJ 0x10
#define GX_BLEND_PLANEMASK_BD 0x20

#define GX_DISPMODE_GRAPHICS 1
// Shows VRAM D, where the display capture can write, instead of the main engine's output
#define GX_DISPMODE_VRAM_D 0xe
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
#define GX_VRAM_BG_32_FG (GX_VRAM_F | GX_VRAM_G)
#define GX_VRAM_BG_128_A GX_VRAM_A
#define GX_VRAM_BG_128_D GX_VRAM_D
#define GX_VRAM_BGEXTPLTT_NONE GX_VRAM_NONE
#define GX_VRAM_SUB_BG_32_H GX_VRAM_H
#define GX_VRAM_SUB_BG_128_C GX_VRAM_C
#define GX_VRAM_SUB_BGEXTPLTT_NONE GX_VRAM_NONE
#define GX_VRAM_OBJ_NONE GX_VRAM_NONE
#define GX_VRAM_OBJ_16_G GX_VRAM_G
#define GX_VRAM_OBJ_64_E GX_VRAM_E
#define GX_VRAM_OBJ_128_B GX_VRAM_B
#define GX_VRAM_OBJEXTPLTT_NONE GX_VRAM_NONE
#define GX_VRAM_SUB_OBJ_16_I GX_VRAM_I
#define GX_VRAM_SUB_OBJ_128_D GX_VRAM_D
#define GX_VRAM_TEX_NONE GX_VRAM_NONE
#define GX_VRAM_TEXPLTT_NONE GX_VRAM_NONE
#define GX_VRAM_SUB_OBJEXTPLTT_NONE GX_VRAM_NONE
#define GX_VRAM_TEX_01_AB (GX_VRAM_A | GX_VRAM_B)
#define GX_VRAM_TEX_01_BD (GX_VRAM_B | GX_VRAM_D)
#define GX_VRAM_TEX_01_CD (GX_VRAM_C | GX_VRAM_D)
#define GX_VRAM_TEX_012_ABC (GX_VRAM_A | GX_VRAM_B | GX_VRAM_C)
#define GX_VRAM_TEX_0123_ABCD (GX_VRAM_A | GX_VRAM_B | GX_VRAM_C | GX_VRAM_D)
#define GX_VRAM_TEXPLTT_0_G GX_VRAM_G
#define GX_VRAM_TEXPLTT_01_FG (GX_VRAM_F | GX_VRAM_G)
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

// The geometry engine's matrix stacks, primitives, polygon attributes and textures
#define GX_MTXMODE_PROJECTION 0
#define GX_MTXMODE_POSITION 1
#define GX_MTXMODE_POSITION_VECTOR 2
#define GX_MTXMODE_TEXTURE 3

#define GX_BEGIN_TRIANGLES 0
#define GX_BEGIN_QUADS 1

#define GX_POLYGONMODE_MODULATE 0

#define GX_CULL_ALL 0
#define GX_CULL_FRONT 1
#define GX_CULL_BACK 2
#define GX_CULL_NONE 3

#define GX_TEXFMT_PLTT4 2
#define GX_TEXFMT_PLTT16 3
#define GX_TEXGEN_TEXCOORD 1
#define GX_TEXSIZE_S128 4
#define GX_TEXSIZE_T128 4
#define GX_TEXREPEAT_ST 3
#define GX_TEXFLIP_NONE 0
#define GX_TEXPLTTCOLOR0_TRNS 1

#define REG_G3_POLYGON_ATTR_LE_SHIFT 0
#define REG_G3_POLYGON_ATTR_PM_SHIFT 4
#define REG_G3_POLYGON_ATTR_BK_SHIFT 6
#define REG_G3_POLYGON_ATTR_ALPHA_SHIFT 16
#define REG_G3_POLYGON_ATTR_ID_SHIFT 24

#define REG_G3_TEXIMAGE_PARAM_RS_SHIFT 16
#define REG_G3_TEXIMAGE_PARAM_FS_SHIFT 18
#define REG_G3_TEXIMAGE_PARAM_V_SIZE_SHIFT 20
#define REG_G3_TEXIMAGE_PARAM_T_SIZE_SHIFT 23
#define REG_G3_TEXIMAGE_PARAM_TEXFMT_SHIFT 26
#define REG_G3_TEXIMAGE_PARAM_TR_SHIFT 29
#define REG_G3_TEXIMAGE_PARAM_TGEN_SHIFT 30

#define REG_G3_DIF_AMB_AMBIENT_RED_SHIFT 16
#define REG_G3_DIF_AMB_C_SHIFT 15
#define REG_G3_SPE_EMI_EMISSION_RED_SHIFT 16
#define REG_G3_SPE_EMI_S_SHIFT 15

#define GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc)                                \
    ((u32)(((light) << REG_G3_POLYGON_ATTR_LE_SHIFT) | ((polyMode) << REG_G3_POLYGON_ATTR_PM_SHIFT) |                \
           ((cullMode) << REG_G3_POLYGON_ATTR_BK_SHIFT) | (misc) | ((polygonID) << REG_G3_POLYGON_ATTR_ID_SHIFT) |    \
           ((alpha) << REG_G3_POLYGON_ATTR_ALPHA_SHIFT)))

#define GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, s, t, repeat, flip, pltt0, addr)                                    \
    ((u32)(((addr) >> 3) | ((texFmt) << REG_G3_TEXIMAGE_PARAM_TEXFMT_SHIFT) |                                     \
           ((texGen) << REG_G3_TEXIMAGE_PARAM_TGEN_SHIFT) | ((s) << REG_G3_TEXIMAGE_PARAM_V_SIZE_SHIFT) |          \
           ((t) << REG_G3_TEXIMAGE_PARAM_T_SIZE_SHIFT) | ((repeat) << REG_G3_TEXIMAGE_PARAM_RS_SHIFT) |            \
           ((flip) << REG_G3_TEXIMAGE_PARAM_FS_SHIFT) | ((pltt0) << REG_G3_TEXIMAGE_PARAM_TR_SHIFT)))

#define GX_PACK_TEXPLTTBASE_PARAM(addr, texFmt) ((u32)((addr) >> (4 - ((texFmt) == GX_TEXFMT_PLTT4))))

#define GX_PACK_DIFFAMB_PARAM(diffuse, ambient, IsSetVtxColor)                                                     \
    ((u32)((diffuse) | ((ambient) << REG_G3_DIF_AMB_AMBIENT_RED_SHIFT) |                                          \
           (((IsSetVtxColor) != FALSE) << REG_G3_DIF_AMB_C_SHIFT)))

#define GX_PACK_SPECEMI_PARAM(specular, emission, IsShininess)                                                     \
    ((u32)((specular) | ((emission) << REG_G3_SPE_EMI_EMISSION_RED_SHIFT) |                                       \
           (((IsShininess) != FALSE) << REG_G3_SPE_EMI_S_SHIFT)))

// A normal's components, 10 bits each, and a texture coordinate's, fixed point with 4 fractional bits
#define GX_FX16_FX10(x) ((fx16)((x) >> 3))
#define GX_VECFX10(x, y, z) ((u32)(((x) & 0x3ff) | (((y) & 0x3ff) << 10) | (((z) & 0x3ff) << 20)))
#define GX_ST(s, t) ((u32)(u16)(fx16)((s) >> 8) | ((u32)(u16)(fx16)((t) >> 8) << 16))

#define REG_GX_POWCNT_DSEL_SHIFT 15

#define REG_GX_DISPCAPCNT_E_MASK 0x80000000
#define REG_GX_DISPCAPCNT_MOD_SHIFT 29
#define REG_GX_DISPCAPCNT_SRCB_SHIFT 25
#define REG_GX_DISPCAPCNT_SRCA_SHIFT 24
#define REG_GX_DISPCAPCNT_WSIZE_SHIFT 20
#define REG_GX_DISPCAPCNT_WB_SHIFT 16
#define REG_GX_DISPCAPCNT_EVB_SHIFT 8
#define REG_GX_DISPCAPCNT_EVA_SHIFT 0

// The display capture, which writes the main engine's output to VRAM, blended with an image in VRAM with AB
#define GX_CAPTURE_SIZE_256x192 3
#define GX_CAPTURE_MODE_AB 2
#define GX_CAPTURE_SRCA_2D3D 0
#define GX_CAPTURE_SRCB_VRAM_0x00000 0
#define GX_CAPTURE_DEST_VRAM_D_0x00000 3

// Which engine draws to the top screen
#define GX_DISP_SELECT_SUB_MAIN 0
#define GX_DISP_SELECT_MAIN_SUB 1

static inline void GX_SetDispSelect(int select) {
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~REG_GX_POWCNT_DSEL_MASK) | (select << REG_GX_POWCNT_DSEL_SHIFT));
}

// The fields go from the highest bit to the lowest, as NitroSDK's register field macros write them
static inline void GX_SetCapture(int sz, int mode, int a, int b, int dest, int eva, int evb) {
    reg_GX_DISPCAPCNT = REG_GX_DISPCAPCNT_E_MASK | (mode << REG_GX_DISPCAPCNT_MOD_SHIFT) |
                        (b << REG_GX_DISPCAPCNT_SRCB_SHIFT) | (a << REG_GX_DISPCAPCNT_SRCA_SHIFT) |
                        (sz << REG_GX_DISPCAPCNT_WSIZE_SHIFT) | (dest << REG_GX_DISPCAPCNT_WB_SHIFT) |
                        (evb << REG_GX_DISPCAPCNT_EVB_SHIFT) | (eva << REG_GX_DISPCAPCNT_EVA_SHIFT);
}

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

static inline void G3_MtxMode(int mode) {
    reg_G3_MTX_MODE = mode;
}

static inline void G3_PushMtx(void) {
    reg_G3_MTX_PUSH = 0;
}

static inline void G3_PopMtx(int num) {
    reg_G3_MTX_POP = num;
}

static inline void G3_Identity(void) {
    reg_G3_MTX_IDENTITY = 0;
}

static inline void G3_Translate(fx32 x, fx32 y, fx32 z) {
    reg_G3_MTX_TRANS = (u32)x;
    reg_G3_MTX_TRANS = (u32)y;
    reg_G3_MTX_TRANS = (u32)z;
}

static inline void G3_Scale(fx32 x, fx32 y, fx32 z) {
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}

static inline void G3_PolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    reg_G3_POLYGON_ATTR = GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc);
}

static inline void G3_TexImageParam(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr) {
    reg_G3_TEXIMAGE_PARAM = GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, s, t, repeat, flip, pltt0, addr);
}

static inline void G3_TexPlttBase(u32 addr, int texFmt) {
    reg_G3_TEXPLTT_BASE = GX_PACK_TEXPLTTBASE_PARAM(addr, texFmt);
}

static inline void G3_MaterialColorDiffAmb(GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor) {
    reg_G3_DIF_AMB = GX_PACK_DIFFAMB_PARAM(diffuse, ambient, IsSetVtxColor);
}

static inline void G3_MaterialColorSpecEmi(GXRgb specular, GXRgb emission, BOOL IsShininess) {
    reg_G3_SPE_EMI = GX_PACK_SPECEMI_PARAM(specular, emission, IsShininess);
}

static inline void G3_Begin(int primitive) {
    reg_G3_BEGIN_VTXS = (u32)primitive;
}

static inline void G3_End(void) {
    reg_G3_END_VTXS = 0;
}

static inline void G3_Normal(fx16 x, fx16 y, fx16 z) {
    reg_G3_NORMAL = GX_VECFX10(GX_FX16_FX10(x), GX_FX16_FX10(y), GX_FX16_FX10(z));
}

static inline void G3_TexCoord(fx32 s, fx32 t) {
    reg_G3_TEXCOORD = GX_ST(s, t);
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z) {
    reg_G3_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    reg_G3_VTX_16 = (u32)(u16)z;
}

#endif // POKEBW2_NITRO_GX_H
