#include "field/field_map.h"

u32 MapReplace_ResolvePatch(MapReplace *replace, u32 *oldValue, u32 *newValue) {
    const u8 *entry = replace->entry;
    const u8 *variables = replace->variables;
    u32 originalValue = *(const u16 *)(entry + 4);
    u32 index;
    u32 replacementValue;

    switch (entry[3]) {
    case 0:
        index = variables[0];
        break;
    case 1:
        index = variables[1];
        break;
    case 2:
        index = variables[2];
        break;
    default:
        index = (&variables[MapReplace_GetEventByCond(entry[3])])[3];
        break;
    }
    replacementValue = *(const u16 *)(entry + 4 + index * 2);
    *oldValue = originalValue;
    *newValue = replacementValue;
    if (originalValue == replacementValue) {
        return 0;
    }
    if (entry[2] == 1) {
        return 2;
    }
    if (entry[2] == 0) {
        return 1;
    }
    return 0;
}

int MapReplace_GetEventByCond(u8 condition) {
    u32 i;

    for (i = 0; i < 10; i++) {
        if (condition == EVENT_MAP_REPLACE_TABLE[i].condition) {
            return i;
        }
    }
    return -1;
}
