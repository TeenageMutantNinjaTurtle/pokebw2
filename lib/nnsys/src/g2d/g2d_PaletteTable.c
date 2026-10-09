#include "nnsys/g2d.h"

// NitroSystem's palette swap table, which the renderer draws each OAM's palette through. The file name is a guess
// from NitroSystem's g2d_PaletteTable.h: the ROM has no string for it, and the renderer is the only caller

u16 NNS_G2dGetPaletteTableValue(const NNSG2dPaletteSwapTable *tbl, u16 beforeIdx) {
    return tbl->paletteIndex[beforeIdx];
}
