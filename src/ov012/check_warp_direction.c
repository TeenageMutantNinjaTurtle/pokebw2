#include "field/zone.h"

BOOL CheckWarpDirectionMatch(const ZoneWarp *warp, u16 direction) {
    if ((direction == 0 && warp->unk4 == 2) || (direction == 1 && warp->unk4 == 1) ||
        (direction == 2 && warp->unk4 == 4) || (direction == 3 && warp->unk4 == 3)) {
        return TRUE;
    }
    return FALSE;
}
