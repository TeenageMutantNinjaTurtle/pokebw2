#include "field/field_actor.h"

void ExpandVecInGridDir(u16 direction, VecFx32 *position, fx32 amount) {
    switch (direction) {
    case 0:
        position->z -= amount;
        break;
    case 1:
        position->z += amount;
        break;
    case 2:
        position->x -= amount;
        break;
    case 3:
        position->x += amount;
        break;
    }
}
