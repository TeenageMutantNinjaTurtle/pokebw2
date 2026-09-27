#ifndef POKEBW2_FIELD_FIELD_H
#define POKEBW2_FIELD_FIELD_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

void BeginContinuePlaceNameDisp(PlaceName *placeName, u16 zoneId);
void BeginForcePlaceNameDisp(PlaceName *placeName, s32 zoneId);
void EncEff_StartEvent(EncEff *encEff, GameEvent *event, u32 effect);
void FieldG2D_Prepare3DSurface(Field *field);
void FieldG2D_SetLCDConfig(void);
void FieldLensFlare_Cancel(FieldLensFlare *lensFlare);
void FieldLensFlare_DecideForZoneTransit(FieldLensFlare *lensFlare, u16 zoneId, u16 prevZoneId, u32 fog);
void FieldLensFlare_RequestStart(FieldLensFlare *lensFlare);
FieldActor *FieldPlayer_GetActor(FieldPlayer *player);
void FieldSnd_FadeInImmediate(FieldSound *fieldSound, GameData *gameData);
void FieldSnd_SetZoneBGM(FieldSound *fieldSound, GameData *gameData, u16 zoneId, u8 season);
void FieldSubscreen_ChangeImm(FieldSubscreen *subscreen, u32 mode);
BOOL FieldTaskManager_IsIdle(FieldTaskManager *taskManager);
FieldActorSystem *Field_GetActorSystem(Field *field);
EncEff *Field_GetEncEff(Field *field);
EncountSystem *Field_GetEncountSystem(Field *field);
u16 Field_GetHeapID(Field *field);
FieldLensFlare *Field_GetLensFlare(Field *field);
PlaceName *Field_GetPlaceName(Field *field);
FieldPlayer *Field_GetPlayer(Field *field);
u16 Field_GetPlayerStateZoneID(Field *field);
u32 Field_GetResolvedControllerTypeID(Field *field);
FieldSubscreen *Field_GetSubscreen(Field *field);
FieldTaskManager *Field_GetTaskManager(Field *field);
void Field_SetSeasonBannerOverdrawFlag(Field *field, BOOL flag);
u32 GetZoneFogIndexAll(Field *field, u16 zoneId);
void ShutdownFollowWork(GameData *gameData);
BOOL func_ov011_02154e70(GameData *gameData, u32 a1);
void func_ov012_02153668(GameCommSys *comm);
void func_ov012_0215cd58(CityState *state);
void func_ov012_0215ee40(GameData *gameData, u16 zoneId);
void func_ov012_0215ee94(GameData *gameData, u16 zoneId);
void func_ov012_0215eeb8(GameData *gameData, u16 zoneId);
void func_ov012_0215eedc(GameData *gameData, u16 zoneId);
void func_ov012_0215ef00(GameData *gameData, u16 zoneId);
void func_ov012_0215ef24(GameData *gameData, u16 zoneId);
void func_ov012_02162f44(GameData *gameData);
void func_ov012_021683f4(GameSystem *gsys, u16 zoneId);
u32 func_ov012_02169fb0(void);
void func_ov028_02170ec8(GameSystem *gsys);
void func_ov036_0219ad24(FieldPlayer *player, RailPosition *pos);
void func_ov036_021a2398(EncountSystem *encount, u32 a1);

#endif // POKEBW2_FIELD_FIELD_H
