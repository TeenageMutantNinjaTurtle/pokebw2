#include "p_status_local.h"

// The ribbons as the summary screen shows them: each one's Pokémon field, icon and palette, name and description, and
// the category that numbers it. The file's name is a guess, after Gen 4's ribbon.c

typedef struct {
    u32 param;
    u16 icon;
    u16 palette;
    u16 name;
    u16 description;
    u8 category;
} RibbonData;

static const RibbonData sRibbons[RIBBON_COUNT] = {
    { 0x61, 26, 0, 0, 0x50, 0 },  { 0x19, 27, 0, 1, 0x51, 0 },  { 0x4d, 18, 0, 2, 0x52, 1 },
    { 0x4e, 19, 0, 3, 0x53, 1 },  { 0x4f, 20, 0, 4, 0x54, 1 },  { 0x50, 21, 0, 5, 0x55, 1 },
    { 0x51, 18, 1, 6, 0x56, 1 },  { 0x52, 19, 1, 7, 0x57, 1 },  { 0x53, 20, 1, 8, 0x58, 1 },
    { 0x54, 21, 1, 9, 0x59, 1 },  { 0x55, 18, 2, 10, 0x5a, 1 }, { 0x56, 19, 2, 11, 0x5b, 1 },
    { 0x57, 20, 2, 12, 0x5c, 1 }, { 0x58, 21, 2, 13, 0x5d, 1 }, { 0x59, 18, 3, 14, 0x5e, 1 },
    { 0x5a, 19, 3, 15, 0x5f, 1 }, { 0x5b, 20, 3, 16, 0x60, 1 }, { 0x5c, 21, 3, 17, 0x61, 1 },
    { 0x5d, 18, 4, 18, 0x62, 1 }, { 0x5e, 19, 4, 19, 0x63, 1 }, { 0x5f, 20, 4, 20, 0x64, 1 },
    { 0x60, 21, 4, 21, 0x65, 1 }, { 0x78, 22, 0, 22, 0x66, 1 }, { 0x79, 23, 0, 23, 0x67, 1 },
    { 0x7a, 24, 0, 24, 0x68, 1 }, { 0x7b, 25, 0, 25, 0x69, 1 }, { 0x7c, 22, 1, 26, 0x6a, 1 },
    { 0x7d, 23, 1, 27, 0x6b, 1 }, { 0x7e, 24, 1, 28, 0x6c, 1 }, { 0x7f, 25, 1, 29, 0x6d, 1 },
    { 0x80, 22, 2, 30, 0x6e, 1 }, { 0x81, 23, 2, 31, 0x6f, 1 }, { 0x82, 24, 2, 32, 0x70, 1 },
    { 0x83, 25, 2, 33, 0x71, 1 }, { 0x84, 22, 3, 34, 0x72, 1 }, { 0x85, 23, 3, 35, 0x73, 1 },
    { 0x86, 24, 3, 36, 0x74, 1 }, { 0x87, 25, 3, 37, 0x75, 1 }, { 0x88, 22, 4, 38, 0x76, 1 },
    { 0x89, 23, 4, 39, 0x77, 1 }, { 0x8a, 24, 4, 40, 0x78, 1 }, { 0x8b, 25, 4, 41, 0x79, 1 },
    { 0x62, 56, 0, 42, 0x7a, 2 }, { 0x63, 57, 0, 43, 0x7b, 2 }, { 0x1a, 58, 0, 44, 0x7c, 2 },
    { 0x1b, 59, 0, 45, 0x7d, 2 }, { 0x1c, 60, 0, 46, 0x7e, 2 }, { 0x1d, 61, 0, 47, 0x7f, 2 },
    { 0x1e, 62, 0, 48, 0x80, 2 }, { 0x1f, 63, 0, 49, 0x81, 2 }, { 0x64, 28, 1, 50, 0x82, 3 },
    { 0x65, 29, 2, 51, 0x83, 3 }, { 0x20, 30, 2, 52, 0x84, 3 }, { 0x21, 31, 0, 53, 0x85, 3 },
    { 0x22, 32, 1, 54, 0x86, 3 }, { 0x23, 33, 2, 55, 0x87, 3 }, { 0x24, 34, 3, 56, 0x88, 3 },
    { 0x25, 35, 0, 57, 0x89, 3 }, { 0x26, 36, 2, 58, 0x8a, 3 }, { 0x27, 37, 1, 59, 0x8b, 3 },
    { 0x28, 38, 3, 60, 0x8c, 3 }, { 0x29, 39, 0, 61, 0x8d, 3 }, { 0x2a, 40, 0, 62, 0x8e, 3 },
    { 0x2b, 41, 1, 63, 0x8f, 3 }, { 0x2d, 42, 0, 64, 0x90, 3 }, { 0x69, 43, 3, 65, 0x91, 4 },
    { 0x6a, 43, 4, 66, 0x92, 4 }, { 0x6b, 44, 0, 67, 0x93, 4 }, { 0x6c, 44, 1, 68, 0x94, 4 },
    { 0x33, 45, 1, 69, 0x95, 4 }, { 0x34, 46, 0, 70, 0x96, 4 }, { 0x2c, 47, 3, 71, 0x97, 4 },
    { 0x2f, 48, 2, 72, 0x98, 4 }, { 0x30, 49, 2, 73, 0x99, 4 }, { 0x31, 50, 1, 74, 0x9a, 4 },
    { 0x32, 51, 0, 75, 0x9b, 4 }, { 0x66, 52, 3, 76, 0x9c, 4 }, { 0x67, 53, 3, 77, 0x9d, 4 },
    { 0x68, 54, 1, 78, 0x9e, 4 }, { 0x2e, 55, 1, 79, 0x9f, 4 },
};

u32 Ribbon_GetData(u32 ribbon, u32 field) {
    switch (field) {
    case RIBBON_DATA_PARAM:
        return sRibbons[ribbon].param;
    case RIBBON_DATA_ICON:
        return sRibbons[ribbon].icon;
    case RIBBON_DATA_PALETTE:
        return sRibbons[ribbon].palette;
    case RIBBON_DATA_NAME:
        return sRibbons[ribbon].name;
    case RIBBON_DATA_DESCRIPTION:
        return sRibbons[ribbon].description;
    case RIBBON_DATA_CATEGORY:
        return sRibbons[ribbon].category;
    }
    return 0;
}

u32 Ribbon_GetDescription(u32 ribbon) {
    return sRibbons[ribbon].description;
}
