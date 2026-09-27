#ifndef POKEBW2_GFL_HEAP_H
#define POKEBW2_GFL_HEAP_H

// Names, layouts and constants from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"

typedef u16 HeapID;

enum {
    HEAPID_SYSTEM = 0x0,
    HEAPID_USER = 0x1,
    HEAPID_GAMESYSTEM = 0x3,
    HEAPID_GAMEEVENT = 0x4,
    HEAPID_TRIAL_HOUSE = 0x5,
    HEAPID_SAVEDATA = 0x7,
    HEAPID_NET = 0x8,
    HEAPID_DEVICE_ALLOC = 0x9,
    HEAPID_STARTMENU = 0xb,
    HEAPID_DLP = 0xc,
    HEAPID_FIELDMAP = 0x15,
    HEAPID_TITLE = 0x16,
    HEAPID_POKELIST = 0x17,
    HEAPID_NAMEIN = 0x1e,
    HEAPID_IRC_BATTLE_MENU = 0x1f,
    HEAPID_TRAINER_CARD = 0x26,
    HEAPID_MUSICAL_EVENT = 0x2c,
    HEAPID_MUSICAL_DRESSUP = 0x2d,
    HEAPID_MUSICAL = 0x2e,
    HEAPID_DEBUG_GENDER_SELECT = 0x39,
    HEAPID_MICTEST = 0x49,
    HEAPID_FIELD_PARTICLE = 0x50,
    HEAPID_BATTLE_RETURN = 0x52,
    HEAPID_GAMESYNC = 0x67,
    HEAPID_DEMO3D = 0x6c,
    HEAPID_INTRO = 0x6f,
    HEAPID_FIELD_MENU = 0x70,
    HEAPID_BATTLE_LOAD = 0x76,
    HEAPID_CDEMO = 0x7f,
    HEAPID_SAVEDATA_DELETE = 0x81,
    HEAPID_FIELD_CLACT = 0x89,
    HEAPID_FIELD_WEATHER = 0x92,
    HEAPID_FIELD_PLACE_NAME = 0x93,
    HEAPID_FIELD_SCENEAREA = 0x96,
};

// Allocates from the end of the heap instead of the start
#define HEAPID_TAIL_BIT 0x8000
#define HEAPID_TAIL(heapId) ((heapId) | HEAPID_TAIL_BIT)

void *GFL_HeapAllocate(HeapID heapId, u32 size, BOOL clear, const char *file, u16 line);
void GFL_HeapFree(void *ptr);

#endif // POKEBW2_GFL_HEAP_H
