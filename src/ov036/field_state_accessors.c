#include "field/encounter_effect.h"
#include "field/field_internal.h"
#include "field/field_state.h"
#include "field/skill_map_effect.h"
#include "system/game_data.h"
#include "system/game_system.h"
#include "system/rtc.h"

u32 Field_GetRenderMode(Field *field) {
    return field->renderMode;
}

void Field_SetRenderMode(Field *field, u32 mode) {
    field->renderMode = mode;
}

void *Field_Get3DCi(Field *field) {
    return field->g3dCi;
}

EncEff *Field_GetEncEff(Field *field) {
    return field->encEff;
}

void *Field_GetSkillMapEff(Field *field) {
    return field->skillMapEff;
}

void *Field_GetSceneArea(Field *field) {
    return field->sceneArea;
}

void Field_SetFadeFlag(Field *field, BOOL flag) {
    field->fadeFlag = flag;
}

BOOL Field_GetFadeFlag(Field *field) {
    return field->fadeFlag;
}

BOOL Field_IsEventRunning(Field *field) {
    return GSYS_GetEventRunningFlag(field->gameSystem);
}

u16 Field_GetDayPeriod(Field *field) {
    return GetRealTimeDayPeriod(GameData_GetSeason(field->gameData));
}

BOOL Field_GetSeasonBannerOverdrawFlag(Field *field) {
    return field->seasonBannerOverdrawFlag;
}

void Field_SetSeasonBannerOverdrawFlag(Field *field, BOOL flag) {
    field->seasonBannerOverdrawFlag = flag;
}

void Field_SetEffectRunningFlag(Field *field, BOOL flag) {
    field->effectRunningFlag = flag;
}

void *Field_GetNDemoDataHandle(Field *field) {
    return field->nDemoDataHandle;
}

void Field_SetCasteliaRush(Field *field, BOOL flag) {
    field->casteliaRush = flag;
}

BOOL Field_GetCasteliaRush(Field *field) {
    return field->casteliaRush;
}

FieldLensFlare *Field_GetLensFlare(Field *field) {
    return field->lensFlare;
}

void *Field_GetColorPostFX(Field *field) {
    return field->colorPostFX;
}

fx32 func_ov036_02181324(Field *field) {
    return field->actorYOffset;
}
