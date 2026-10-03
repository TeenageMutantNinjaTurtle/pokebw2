#include "field/zone.h"

void SetupWarpParamByWarp(ZoneWarp *warp, ZoneSpawnInfo *spawn, u32 direction) {
    SetupZoneSpawnInfoWarp(spawn, warp->unk0, warp->destId, direction);
}
