#ifndef POKEBW2_FIELD_FIELD_H
#define POKEBW2_FIELD_FIELD_H

#include "types.h"
#include "gfl/bmpwin.h"
#include "gfl/heap.h"
#include "gfl/tcb.h"
#include "nitro/fx.h"
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
// GENDER_MALE or GENDER_FEMALE
u32 FieldPlayer_GetSex(FieldPlayer *player);
void FieldPlayer_GetWPos(FieldPlayer *player, VecFx32 *pos);
u32 FieldPlayer_GetFaceDir(FieldPlayer *player);
// The player's object code for a sex, in a form or an extra state
u16 FieldPlayer_GetObjCodeByForme(u32 sex, u32 forme);
u16 FieldPlayer_GetObjCodeByExState(u32 sex, u32 exState);
void *Field_GetMsgBGSys(Field *field);
BOOL Field_IsEventRunning(Field *field);
void FieldPlayer_GetGPos(FieldPlayer *player, s16 *x, s16 *y, s16 *z);
// A number below 6 that overlay 137 reads from the game data
u32 func_ov012_02169b78(GameData *gameData);
// The size of a message in the field's message BG, in tiles
void CalcMsgWindowDimensions(void *msgBGSys, StrBuf *strbuf, u8 *width, u8 *height);
// Shows a message as a balloon of an index in the field's message BG, and removes it
void func_ov036_02188dfc(void *msgBGSys, StrBuf *strbuf, u16 index, u8 x, u8 y, u8 width, u8 a6, u32 a7);
void func_ov036_02188e90(void *msgBGSys, u16 index);
// The money window of the field's message BG
void *FieldMsgBG_CreateMoneyWin(void *msgBGSys, MsgData *msgData, u16 a2, u16 a3, u16 a4, u16 a5);
// The font of the field's message BG
Font *func_ov036_0218799c(void *msgBGSys);
// Turns on or off the alpha blending of the field's message BG
void setAlphaBlend_wrapper(BOOL enable);
// The grid position in front of the player, facing dir
void GetPlayerGPosPlusDir(FieldPlayer *player, u16 dir, s16 *x, s16 *y, s16 *z);
// A message window on the field's message BG: create, update (0 for the first answer, 2 while waiting) and free
void *func_ov036_021880d4(void *msgBGSys, u32 a1);
void func_ov036_02187c1c(void *window);
BOOL func_ov036_02187c70(void *window);
void func_ov036_02187c7c(void *window);
// Prints a string in the window at a position
void func_ov036_02187c4c(void *window, u16 x, u16 y, StrBuf *strbuf);
BmpWin *func_ov036_02187c9c(void *window);
u32 func_ov036_02189cb0(void *msgBGSys);
void func_ov036_02189cd8(u32 value);
void func_ov036_02189de8(u32 value, GFLBitmap *bitmap, u32 number);
GameEvent *func_ov036_021bfa68(u16 a0, GameSystem *gsys, u32 a2, u16 a3);
// Check the party and the Battle Box against a regulation. func_ov036_021aebf0 returns the event that lets the player
// choose between them, or NULL when neither can enter
GameEvent *func_ov036_021aebf0(GameSystem *gsys, u32 a1, Regulation *regulation, u16 *result, HeapID heapId);
u32 func_ov036_021aece0(GameSystem *gsys, u32 a1, Regulation *regulation, HeapID heapId);
u32 func_ov036_0218816c(void *window);
void func_ov036_02187ea0(void *window);
void *func_ov036_021c3d9c(PlayerInfo *info, Field *field, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
u32 func_ov036_021c3f98(void *obj);
void func_ov036_021c3eb4(void *obj);
void func_ov036_021c65a8(void *obj, u16 a1);
void func_ov036_021c65e8(void *obj, u16 a1);
void FieldPlayer_SetWPos(FieldPlayer *player, const VecFx32 *pos);
void FieldPlayer_SetDirection(FieldPlayer *player, u32 dir);
void FieldFadeTCB_Start(GameSystem *gsys, Field *field, u32 a2, u32 a3, u32 a4);

// The work of the zone's gimmick, such as a gym's puzzle, which the gimmick's overlay allocates at the zone's start
void *Field_AllocGimmickWorkBlock(Field *field, u32 id, HeapID heapId, u32 size);
void *Field_GetGimmickWorkBlock(Field *field, u32 id);
// Whether the gimmick work was allocated with the password
BOOL Field_CheckGimmickWorkPassword(Field *field, u32 password);
void Field_DeleteGimmickWorkBlock(Field *field, u32 id);

// A list of areas of the map, which the list's entry index sets: a grid rectangle, a value and flags
void *func_ov036_02184590(G3DMapper *mapper);
void func_ov036_021ba624(u8 index, u32 x, u32 z, u32 width, u32 depth, u32 value, u32 flags, void *list);
void FieldSnd_FadeInImmediate(FieldSound *fieldSound, GameData *gameData);
void FieldSnd_PlayAmbience(FieldSound *fieldSound, u32 se);
void FieldSnd_SetZoneBGM(FieldSound *fieldSound, GameData *gameData, u16 zoneId, u8 season);
void FieldSubscreen_ChangeImm(FieldSubscreen *subscreen, u32 mode);
BOOL FieldTaskManager_IsIdle(FieldTaskManager *taskManager);
MMSys *Field_GetActorSystem(Field *field);
FieldCamera *Field_GetCameraSystem(Field *field);
NoGridMapper *Field_GetNoGridMapper(Field *field);
FieldExpObjSystem *Field_GetExpObjSystem(Field *field);
// Whether a fade that FieldFadeTCB_Start started is still running
BOOL Field_GetFadeFlag(Field *field);
FieldFog *Field_GetFog(Field *field);
G3DMapper *Field_GetG3DMapper(Field *field);
GameSystem *Field_GetGameSystem(Field *field);
TCBManager *Field_GetTCBMgr(Field *field);
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
