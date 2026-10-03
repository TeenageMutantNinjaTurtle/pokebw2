#include "field/zone.h"

u16 GetInverseDirection(u32 direction) {
    return INV_DIR_TABLE[direction];
}
