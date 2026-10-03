#include "field/field_actor.h"

void AdjusGridXZByDir(u32 direction, s16 *x, s16 *z, s16 amount) {
    switch (direction) {
    case 0:
        *z = (s16)(*z - amount);
        break;
    case 1:
        *z = (s16)(*z + amount);
        break;
    case 2:
        *x = (s16)(*x - amount);
        break;
    case 3:
        *x = (s16)(*x + amount);
        break;
    }
}
