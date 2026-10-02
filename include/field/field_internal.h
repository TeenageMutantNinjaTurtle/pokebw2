#ifndef POKEBW2_FIELD_FIELD_INTERNAL_H
#define POKEBW2_FIELD_FIELD_INTERNAL_H

#include "field/field.h"

// The fields used by the accessors; the rest of Field's layout is not yet known.
struct Field {
    u16 heapId;
    u16 unk2;
    GameSystem *gameSystem;
    u8 unk8[0x8];
    FieldCamera *cameraSystem;
    u8 unk14[0x14];
    void *msgBGSys;
    u8 unk2c[0x10];
    FieldExpObjSystem *expObjSystem;
    MMSys *actorSystem;
    NoGridMapper *noGridMapper;
    u8 unk48[0x8];
    G3DMapper *g3DMapper;
    u8 unk54[0x94];
    u16 playerStateZoneId;
    u8 unkea[0x36];
    TCBManager *tcbManager;
    u8 unk124[0x20];
    FieldTaskManager *taskManager;
};

#endif // POKEBW2_FIELD_FIELD_INTERNAL_H
