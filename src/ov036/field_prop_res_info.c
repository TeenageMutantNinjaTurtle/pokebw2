#include "field/field_prop.h"

u32 FieldPropResAnmHeader_GetAnmCount(const FieldPropResAnmHeader *header) {
    u32 i = 0;
    u32 count = 0;

    for (; i < 4; i++) {
        if (header->animationIds[i] != 0xffffffff) {
            count++;
        }
    }
    return count;
}

FieldPropResAnmHeader *FieldPropResInfo_GetAnmHeader(FieldPropResInfo *resInfo) {
    return &resInfo->animationHeader;
}

u8 FieldPropResInfo_GetTypeConv(const FieldPropResInfo *resInfo) {
    const u8 lut[16] = { 0, 1, 1, 1, 2, 0, 3, 4, 5, 6, 7, 8, 9, 1, 1, 1 };
    u16 type = resInfo->type;

    if (type >= 16) {
        return 0;
    }
    return lut[type];
}
