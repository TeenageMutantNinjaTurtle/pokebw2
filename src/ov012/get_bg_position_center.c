#include "field/zone.h"

void func_ov012_0215d4d0(const ZoneBGEntity *entity, VecFx32 *position) {
    func_ov012_0215d88c(entity, position);
    position->x += 0x8000;
    position->z += 0x8000;
}
