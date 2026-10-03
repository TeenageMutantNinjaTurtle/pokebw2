#include "field/zone.h"

u32 ConvDirToTriggerDir(u32 dir) {
    switch (dir) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 4;
    default:
        return 0;
    }
}
