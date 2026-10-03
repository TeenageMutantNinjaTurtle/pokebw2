#include "field/field_map.h"

u32 GetChunkCoordOfWorld(s32 coordinate) {
    return ((coordinate / 0x1000) / 16) / 32;
}
