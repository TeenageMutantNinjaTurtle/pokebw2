#ifndef POKEBW2_FIELD_FIELD_INTERNAL_H
#define POKEBW2_FIELD_FIELD_INTERNAL_H

#include "field/field.h"

// The fields used by the accessors; the rest of Field's layout is not yet known.
struct Field {
    u16 heapId;
    u16 unk2;
    GameSystem *gameSystem;
    GameData *gameData;
    AreaData *areaData;
    FieldCamera *cameraSystem;
    void *lightSystem;
    FieldFog *fog;
    void *fogCtrl;
    void *weatherSystem;
    FieldSubscreen *subscreen;
    void *msgBGSys;
    void *moneyWin;
    PlaceName *placeName;
    u8 unk34[0x4];
    void *fesGimmick;
    FieldExpObjSystem *expObjSystem;
    MMSys *actorSystem;
    NoGridMapper *noGridMapper;
    void *sceneArea;
    u8 unk4c[0x4];
    G3DMapper *g3DMapper;
    u8 unk54[0x40];
    FieldPlayer *player;
    u8 unk98[0x4];
    void *fieldEffects;
    u8 unka0[0x8];
    u8 colorPostFX[0x8];
    void *skillMapEff;
    u8 unkb4[0x10];
    void *effectBlAct;
    void *wildEffectBlAct;
    FieldAsyncProcManager *asyncProcManager;
    u32 routineState;
    u32 routineID;
    u8 unkd8[0x10];
    u16 playerStateZoneId;
    u8 unkea[0x16];
    VecFx32 *playerPosPtr;
    u8 unk104[0xc];
    fx32 actorYOffset;
    u8 unk114[0x4];
    u32 *controllerTypeID;
    void *controller;
    TCBManager *tcbManager;
    u8 unk124[0x10];
    void *g3dCi;
    DayCareSave *dayCare;
    u32 renderMode;
    void *g3DObjSystem;
    FieldTaskManager *taskManager;
    BOOL fadeFlag;
    EncEff *encEff;
    BOOL effectRunningFlag;
    BOOL seasonBannerOverdrawFlag;
    u8 nDemoDataHandle[0x8];
    BOOL casteliaRush;
    FieldLensFlare *lensFlare;
};

#endif // POKEBW2_FIELD_FIELD_INTERNAL_H
