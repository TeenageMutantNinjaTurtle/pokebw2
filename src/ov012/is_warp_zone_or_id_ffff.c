#include "field/zone.h"

BOOL IsWarpZoneOrWarpID0xFFFF(const ZoneWarp *warp) {
    return warp->unk0 == 0xffff || warp->destId == 0xffff;
}
