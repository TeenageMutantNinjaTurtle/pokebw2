#include "field/zone.h"
#include "field/zone_data.h"

BOOL func_ov036_021813b8(u16 zoneId) {
    if (zoneId == 0x249) {
        return FALSE;
    }
    if (IsZone150Or151(zoneId) == TRUE) {
        return FALSE;
    }
    if (zoneId == 0xf1) {
        return FALSE;
    }
    if (zoneId == 0xf2) {
        return FALSE;
    }
    if (zoneId == 0xf3) {
        return FALSE;
    }
    if (zoneId == 0xf4) {
        return FALSE;
    }
    return TRUE;
}

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
