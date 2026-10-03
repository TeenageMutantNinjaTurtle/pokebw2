#include "field/zone.h"

void GetRailWarpOutPos(ZoneWarp *warp, u32 direction, RailPosition *position) {
    ZoneWarpRailPosition *rail = (ZoneWarpRailPosition *)&warp->gridPos;
    u32 warpDirection = ZoneWarp_GetDirection(warp);
    s16 side;
    u16 param;

    position->componentId = rail->componentId;
    position->componentIsLine = 1;
    position->railDirection = ConvDirToRailDir(warpDirection);
    side = *(volatile s16 *)&rail->posSide;
    param = rail->param;
    position->posSide = side;
    position->posFront = rail->posFront;
    if (rail->sideSpan > 1) {
        position->posSide += (s16)CalcWarpTransferAddend(direction, warpDirection, 1, param, rail->sideSpan);
    } else if (rail->frontSpan > 1) {
        position->posFront += CalcWarpTransferAddend(direction, warpDirection, 1, param, rail->frontSpan);
    }
}

BOOL CheckWarpPositionMatchRail(const ZoneWarp *warp, const RailPosition *position) {
    const ZoneWarpRailPosition *rail;

    if (warp->isRail == 0) {
        return FALSE;
    }
    rail = (const ZoneWarpRailPosition *)&warp->gridPos;
    if (rail->componentId == position->componentId && rail->posFront <= position->posFront &&
        rail->posFront + rail->frontSpan > position->posFront && rail->posSide <= position->posSide &&
        rail->posSide + rail->sideSpan > position->posSide) {
        return TRUE;
    }
    return FALSE;
}

void func_ov012_0215d88c(const ZoneBGEntity *entity, VecFx32 *position) {
    const s32 *coords;
    s32 x;
    s32 y;
    s32 z;

    coords = &entity->pos.grid.x;
    z = coords[1] << 16;
    x = coords[0] << 16;
    y = coords[2] << 12;
    position->x = x;
    position->y = y;
    position->z = z;
}

BOOL CheckBGPositionMatchGrid(const ZoneBGEntity *entity, const VecFx32 *position) {
    const s32 *coords;
    s32 zRaw;
    s32 x;
    s32 y;
    s32 z;

    if (entity->isRail == 1) {
        return FALSE;
    }
    zRaw = position->z;
    coords = &entity->pos.grid.x;
    z = (zRaw >> 4) / 4096;
    x = (position->x >> 4) / 4096;
    y = position->y >> 12;
    if (coords[0] == x && coords[1] == z && coords[2] - 2 <= y && coords[2] + 2 > y) {
        return TRUE;
    }
    return FALSE;
}

void func_ov012_0215d8fc(const ZoneBGEntity *entity, RailPosition *position) {
    u32 direction;
    const u16 *values;

    values = (const u16 *)&entity->pos.rail;
    switch (entity->direction) {
    case 0:
        direction = 1;
        break;
    case 1:
        direction = 2;
        break;
    case 2:
        direction = 3;
        break;
    case 3:
        direction = 0;
        break;
    default:
        direction = 0;
        break;
    }
    position->componentId = values[0];
    position->componentIsLine = 1;
    position->railDirection = ConvDirToRailDir(direction);
    position->posSide = ((const s16 *)values)[2];
    position->posFront = values[1];
}

BOOL CheckBGPositionMatchRail(const ZoneBGEntity *entity, const RailPosition *position) {
    const u16 *values;

    if (entity->isRail == 0) {
        return FALSE;
    }
    values = (const u16 *)&entity->pos.rail;
    if (values[0] == position->componentId && values[1] == position->posFront && (s16)values[2] == position->posSide) {
        return TRUE;
    }
    return FALSE;
}

void GetTriggerCenterPos_(const ZoneTrigger *trigger, VecFx32 *position) {
    const u16 *values;
    fx32 y;
    fx32 x;
    fx32 z;

    values = &trigger->pos.grid.x;
    z = (values[1] << 16) + FX_Div(values[3] << 16, 2 << 12);
    y = ((const s16 *)values)[4] << 12;
    x = (values[0] << 16) + FX_Div(values[2] << 16, 2 << 12);
    position->z = z;
    position->x = x;
    position->y = y;
}

BOOL CheckTriggerPositionMatchXYZ(const ZoneTrigger *trigger, const VecFx32 *position) {
    const u16 *values;
    s32 x;
    s32 y;
    s32 z;

    if (trigger->isRail == 1) {
        return FALSE;
    }
    values = &trigger->pos.grid.x;
    x = (position->x >> 4) / 4096;
    z = (position->z >> 4) / 4096;
    y = position->y >> 12;
    if (values[0] <= x && values[0] + values[2] > x && values[1] <= z && values[1] + values[3] > z &&
        ((const s16 *)values)[4] - 2 <= y && ((const s16 *)values)[4] + 2 > y) {
        return TRUE;
    }
    return FALSE;
}

BOOL CheckTriggerPositionMatchXZ(const ZoneTrigger *trigger, const VecFx32 *position) {
    s32 x;
    s32 z;
    const u16 *values;

    if (trigger->isRail == 1) {
        return FALSE;
    }
    values = &trigger->pos.grid.x;
    x = (position->x >> 4) / 4096;
    z = (position->z >> 4) / 4096;
    if (values[0] <= x && values[0] + values[2] > x && values[1] <= z && values[1] + values[3] > z) {
        return TRUE;
    }
    return FALSE;
}

BOOL CheckTriggerPositionMatchRail(const ZoneTrigger *trigger, const RailPosition *position) {
    const u16 *values;

    if (trigger->isRail == 0) {
        return FALSE;
    }
    values = &trigger->pos.rail.componentId;
    if (values[0] == position->componentId && values[1] <= position->posFront &&
        values[1] + values[3] > position->posFront && ((const s16 *)values)[2] <= position->posSide &&
        ((const s16 *)values)[2] + values[4] > position->posSide) {
        return TRUE;
    }
    return FALSE;
}
