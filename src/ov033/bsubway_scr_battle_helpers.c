#include "field/battle_facility.h"
#include "field/bsubway_scr.h"

void *func_ov033_0217c264(BSubwayScrWork *bsw, void *param, u16 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7) {
    return func_ov012_02162864(param, a2, a3, a4, a5, a6, a7);
}

u16 func_ov033_0217c288(u32 value) {
    if (value < 100) {
        return 3;
    }
    if (value < 120) {
        return 6;
    }
    if (value < 140) {
        return 9;
    }
    if (value < 160) {
        return 12;
    }
    if (value < 180) {
        return 15;
    }
    if (value < 200) {
        return 18;
    }
    if (value < 220) {
        return 21;
    }
    return 31;
}
