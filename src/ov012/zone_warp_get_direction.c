#include "field/zone.h"

u32 ZoneWarp_GetDirection(const ZoneWarp *warp) {
    switch (warp->unk4) {
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    default:
        return 1;
    }
}
