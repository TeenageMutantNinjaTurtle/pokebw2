#include "field/battle_facility.h"
#include "field/bsubway_scr.h"

u32 func_ov033_0217bca0(BSubwayScrWork *bsw, u16 index) {
    return func_ov012_02162b38(*(u16 *)((u8 *)bsw + 0x8c + 0x120 * index));
}
