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
    void *lightSystem;
    FieldFog *fog;
    void *fogCtrl;
    void *weatherSystem;
    FieldSubscreen *subscreen;
    void *msgBGSys;
    u8 unk2c[0x4];
    PlaceName *placeName;
    u8 unk34[0x4];
    void *fesGimmick;
    FieldExpObjSystem *expObjSystem;
    MMSys *actorSystem;
    NoGridMapper *noGridMapper;
    u8 unk48[0x8];
    G3DMapper *g3DMapper;
    u8 unk54[0x40];
    FieldPlayer *player;
    u8 unk98[0x4];
    void *fieldEffects;
    u8 unka0[0x24];
    void *effectBlAct;
    void *wildEffectBlAct;
    FieldAsyncProcManager *asyncProcManager;
    u8 unkd0[0x18];
    u16 playerStateZoneId;
    u8 unkea[0x2e];
    u32 *controllerTypeID;
    void *controller;
    TCBManager *tcbManager;
    u8 unk124[0x1c];
    void *g3DObjSystem;
    FieldTaskManager *taskManager;
};

#endif // POKEBW2_FIELD_FIELD_INTERNAL_H
