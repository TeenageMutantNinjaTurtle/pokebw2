#include "field/zone_data.h"

BOOL IsZoneTwoPassLoad(u16 zoneId) {
    if (zoneId == 0x6c)
        return TRUE;
    if (zoneId == 0x249)
        return TRUE;
    if (zoneId == 0x8f)
        return TRUE;
    return FALSE;
}

BOOL func_ov036_0218141c(u16 zoneId) {
    if (zoneId == 0x1de) {
        goto match;
    }
    if (zoneId != 0x1df) {
        goto noMatch;
    }
match:
    return TRUE;
noMatch:
    return FALSE;
}
