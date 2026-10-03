#include "types.h"
#include "field/field.h"
#include "field/field_exp_obj.h"
#include "field/gimmick_league_lift.h"
#include "gfl/g3d.h"
#include "nitro/fx.h"

typedef struct {
    u16 heapId;
} GimmickWork;

void func_ov106_021eecd4(Field *field);
void func_ov106_021eed04(Field *field);
BOOL func_ov106_021eed18(Field *field);
void func_ov106_021eed48(Field *field);
void func_ov106_021eed78(Field *field);
BOOL func_ov106_021eedc8(Field *field);
void func_ov106_021eedfc(GimmickWork *work, Field *field);
void func_ov106_021eee50(GimmickWork *work, Field *field);
void func_ov106_021eee54(GimmickWork *work, Field *field);

static const G3DSceneAnimationSetup sAnimations01[] = { { 1, 0 } };
static const G3DSceneAnimationSetup sAnimations03[] = { { 3, 0 }, { 4, 0 } };

static const G3DSceneActorSetup sActors[2] = {
    { 0, 0, 0, 0, sAnimations01, NELEMS(sAnimations01) },
    { 2, 0, 2, 0, sAnimations03, NELEMS(sAnimations03) },
};

static const G3DSceneResourceSetup sResources[] = {
    { 0x9b, 1, 0 }, { 0x9b, 8, 0 }, { 0x9b, 3, 0 }, { 0x9b, 14, 0 }, { 0x9b, 23, 0 },
};

static const G3DSceneSetup sSceneSetup = { sResources, NELEMS(sResources), sActors, NELEMS(sActors) };

// Where each actor is
static const VecFx32 sActorPositions[2] = {
    { FX32_CONST(480), FX32_CONST(2), FX32_CONST(1296) },
    { FX32_CONST(480), FX32_CONST(2), FX32_CONST(1296) },
};

void func_ov106_021eec80(Field *field) {
    u16 heapId;
    GimmickWork *work;

    heapId = Field_GetHeapID(field);
    work = Field_AllocGimmickWorkBlock(field, 1, heapId, sizeof(GimmickWork));
    work->heapId = heapId;
    func_ov106_021eedfc(work, field);
    func_ov106_021eee50(work, field);
}

void func_ov106_021eecac(Field *field) {
    GimmickWork *work;

    work = Field_GetGimmickWorkBlock(field, 1);
    func_ov106_021eee54(work, field);
    Field_DeleteGimmickWorkBlock(field, 1);
}

void func_ov106_021eecc8(Field *field) {
    FieldExpObj_StepAllAnimations(Field_GetExpObjSystem(field));
}

void func_ov106_021eecd4(Field *field) {
    FieldExpObjSystem *system;
    FieldExpObjAnm *anm;

    system = Field_GetExpObjSystem(field);
    FieldExpObj_SetAnm(system, 0, 0, 0, TRUE);
    anm = FieldExpObj_GetAnmInfo(system, 0, 0, 0);
    FieldExpObjAnm_SetLooped(anm, FALSE);
}

void func_ov106_021eed04(Field *field) {
    FieldExpObj_SetAnm(Field_GetExpObjSystem(field), 0, 0, 0, FALSE);
}

BOOL func_ov106_021eed18(Field *field) {
    s32 i;
    FieldExpObjSystem *system;
    FieldExpObjAnm *anm;

    system = Field_GetExpObjSystem(field);
    for (i = 0; i < 1; i++) {
        anm = FieldExpObj_GetAnmInfo(system, 0, 0, i);
        if (!FieldExpObjAnm_IsPlaybackFinished(anm)) {
            return FALSE;
        }
    }
    return TRUE;
}

void func_ov106_021eed48(Field *field) {
    s32 i;
    FieldExpObjSystem *system;

    system = Field_GetExpObjSystem(field);
    FieldExpObj_SetActorHidden(system, 0, 1, TRUE);
    for (i = 0; i < 2; i++) {
        FieldExpObj_SetAnm(system, 0, 1, i, FALSE);
    }
}

void func_ov106_021eed78(Field *field) {
    s32 i;
    s32 j;
    FieldExpObjSystem *system;
    FieldExpObjAnm *anm;

    system = Field_GetExpObjSystem(field);
    FieldExpObj_SetActorHidden(system, 0, 1, FALSE);
    for (i = 0; i < 2; i++) {
        FieldExpObj_SetAnm(system, 0, 1, i, TRUE);
    }
    for (j = 0; j < 2; j++) {
        anm = FieldExpObj_GetAnmInfo(system, 0, 1, j);
        FieldExpObjAnm_SetLooped(anm, FALSE);
    }
}

BOOL func_ov106_021eedc8(Field *field) {
    s32 i;
    FieldExpObjSystem *system;
    FieldExpObjAnm *anm;

    system = Field_GetExpObjSystem(field);
    for (i = 0; i < 2; i++) {
        anm = FieldExpObj_GetAnmInfo(system, 0, 1, i);
        if (!FieldExpObjAnm_IsPlaybackFinished(anm)) {
            return FALSE;
        }
    }
    return TRUE;
}

void func_ov106_021eedfc(GimmickWork *work, Field *field) {
    FieldExpObjSystem *system;
    SRTMatrix *matrix;
    s32 i;

    system = Field_GetExpObjSystem(field);
    LoadFieldExpandObjData(system, &sSceneSetup, 0);
    for (i = 0; i < 2; i++) {
        matrix = FieldExpObj_GetActorMatrixPtr(system, 0, i);
        matrix->translation.x = sActorPositions[i].x;
        matrix->translation.y = sActorPositions[i].y;
        matrix->translation.z = sActorPositions[i].z;
    }
    func_ov106_021eed04(field);
    func_ov106_021eed48(field);
}

void func_ov106_021eee50(GimmickWork *work, Field *field) {
}

void func_ov106_021eee54(GimmickWork *work, Field *field) {
}