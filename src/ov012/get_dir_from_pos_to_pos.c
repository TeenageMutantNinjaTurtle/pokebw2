#include "field/zone.h"

u16 GetDirFromPosToPos(s32 x1, s32 z1, s32 x2, s32 z2) {
    s32 direction;

    if (x1 > x2) {
        return 2;
    }
    if (x1 < x2) {
        return 3;
    }
    direction = 1;
    if (z1 > z2) {
        direction = 0;
    }
    return direction;
}
