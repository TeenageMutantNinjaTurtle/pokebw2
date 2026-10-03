#include "field/zone.h"

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
