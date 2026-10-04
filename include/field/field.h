#ifndef POKEBW2_FIELD_FIELD_H
#define POKEBW2_FIELD_FIELD_H

#include "types.h"
#include "gfl/g3d.h"
#include "gfl/bmp_menu.h"
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
u32 Field_GetRenderMode(Field *field);
void Field_SetRenderMode(Field *field, u32 mode);
void *Field_GetSceneArea(Field *field);
void Field_SetFadeFlag(Field *field, BOOL flag);
u16 Field_GetDayPeriod(Field *field);
BOOL Field_GetSeasonBannerOverdrawFlag(Field *field);
void Field_SetEffectRunningFlag(Field *field, BOOL flag);
void *Field_GetNDemoDataHandle(Field *field);
void Field_SetCasteliaRush(Field *field, BOOL flag);
BOOL Field_GetCasteliaRush(Field *field);
void *Field_GetColorPostFX(Field *field);
void Field_SetPlayerPosPtr(Field *field, VecFx32 *position);
// Recolors a texture resource with the field's color post-FX
void FieldColorPostFX_Apply(void *postFx, void *texture);
fx32 func_ov036_02181324(Field *field);
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
// A talk window on the field's message BG, printing messages of a message data or strings: create, free, print,
// whether printing has ended, clear, and the window
MsgData *func_ov036_021879a0(void *msgBGSys, u32 fileId);
void func_ov036_021879b8(MsgData *msgData);
void *func_ov036_0218845c(void *msgBGSys);
void func_ov036_02188338(void *window);
void func_ov036_0218836c(void *window, u32 a1, u32 a2, u32 messageId);
void func_ov036_021883b0(void *window, u32 a1, u32 a2, StrBuf *strbuf);
BOOL func_ov036_021883e8(void *window);
void func_ov036_02188474(void *window);
BmpWin *func_ov036_02188494(void *window);
// A list menu window on the field's message BG. ListMenuRequest_Set completes the request with the number of
// options, the position and the size, which CalcListMenuWidth and CalcListMenuHeight give in tiles
typedef struct {
    u16 count;
    u16 unk02;
    u8 unk04;
    u8 unk05;
    u16 unk06;
    u16 unk08;
    u16 unk0A_0 : 3;
    u16 unk0A_3 : 4;
    u16 unk0A_7 : 9;
    u32 unk0C;
    u16 unk10;
    // The height of a row, in pixels
    u16 rowHeight;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u32 unk1C;
} ListMenuRequest;

typedef struct ListMenuUI ListMenuUI;

ListMenuOption *InitListMenuOptionHeap(u32 count, HeapID heapId);
void AppendListMenuOption(ListMenuOption *options, StrBuf *text, u32 value, HeapID heapId);
u32 ListMenuCore_GetOptionCount(ListMenuOption *options);
u32 CalcListMenuWidth(void *msgBGSys, ListMenuOption *options, u32 a2, u32 a3);
u32 CalcListMenuHeight(u32 rows, u32 rowHeight, u32 a2, BOOL scrolls);
void ListMenuRequest_Set(ListMenuRequest *request, u16 count, u16 x, u16 y, u16 width, u16 height);
ListMenuUI *ListMenuUI_Create(void *msgBGSys, ListMenuRequest *request, ListMenuOption *options,
                              BmpMenuListCursorCallback callback, void *work, u16 a5, u16 cursor, u32 flags);
// BMPMENULIST_NULL until an option is chosen or the menu is cancelled
s32 ListMenuUI_Update(ListMenuUI *menu);
// A window that describes the list menu's options: clear and print
void func_ov036_02188660(void *window);
void func_ov036_02188680(void *window, u32 x, u32 y, StrBuf *strbuf);
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
void *func_ov036_021ba5d0(u32 count, u8 heapId);
void func_ov036_021ba624(u8 index, u32 x, u32 z, u32 width, u32 depth, u32 value, u32 flags, void *list);
void func_ov036_021ba670(void *list);
u32 func_ov036_021ba684(void *list);
BOOL func_ov036_021ba688(s32 x, s32 z, void *list, u8 index);
u32 func_ov036_021ba6a4(u8 index, void *list);
u32 func_ov036_021ba6b0(u8 index, void *list);
// The mapper's WFBC work
void *func_ov036_0218adac(HeapID heapId);
void func_ov036_0218add0(void *wfbc);
void func_ov036_0218ade0(void *wfbc, CityState *city, BOOL isOther, HeapID heapId);
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
FieldG3DMapper *Field_GetG3DMapper(Field *field);
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

// One of N's Pokémon, which createNPkm makes
typedef struct {
    u16 unk0;
    u16 species;
    u8 level;
    u8 unk5;
    u8 unk6;
    u8 unk7;
} NPokeSpec;

void createNPkm(PartyPkm *pkm, const NPokeSpec *spec);

void Field_RequestClose(Field *field);
BOOL Field_CheckMapLoadFinished(Field *field);
void FieldRenderPhase2_FieldEffect(Field *field);
void FieldRenderPhase2_EncountEffect(Field *field);
void *FieldG2D_GetDispControl(Field *field);
void *Field_GetFieldEffects(Field *field);
void *Field_GetG3DObjSys(Field *field);
u32 GetZoneFogIndex(u16 zoneId);
u32 ZoneData_GetObjectProjectionMatrixType(u16 zoneId);
u32 GetObjectProjectionMatrixOffset(u16 zoneId);
BOOL func_ov036_021813b8(u16 zoneId);
BOOL IsZoneTwoPassLoad(u16 zoneId);
BOOL func_ov036_0218141c(u16 zoneId);
u32 GetZoneMapType(u16 zoneId);
u32 GetZoneMapType2(u16 zoneId);
void SetupLoadZoneMapTypeData(u16 zoneId, AreaData *area, FieldG3DMapperConfig *config, MapMatrix *matrix);
const FieldmapCtrlVTable *GetZoneFieldmapCtrlVTable(u16 zoneId);
u32 GetFieldmapZoneHeapSize(u16 zoneId);
PlaceName *FieldPlaceName_Create(GameSystem *gsys, HeapID heapId, void *msgBGSys);
void FieldPlaceName_Free(PlaceName *placeName);
void func_ov036_021b4ff8(PlaceName *placeName);
void func_ov036_021b5064(PlaceName *placeName);
void Field_InitGimmick(Field *field);
void Field_TerminateGimmick(Field *field);
void Field_UpdateGimmick(Field *field);
void *CreateFieldMsgBGSystem(HeapID heapId, G3DCamera *camera);
void func_ov036_021877ac(void *msgBGSys);
void func_ov036_021878d0(void *msgBGSys);
void func_ov036_0218796c(void *msgBGSys);
void func_ov036_02187760(void *msgBGSys);
void func_ov036_0218776c(void *msgBGSys);
// Overlay 34, which the Union Room and the Entralink load
void *func_ov034_0217b768(HeapID heapId);
void func_ov034_0217b794(void *work);
void func_ov034_0217b7bc(void *work);
void func_ov034_0217b7d0(void *work);
// Overlay 28
void func_ov028_02170f28(GameCommSys *comm, Field *field);
BOOL FieldmapProc_Init(GameProc *proc, int *seq, void *param, void *work);
BOOL FieldmapProc_Update(GameProc *proc, int *seq, void *param, void *work);
BOOL FieldmapProc_End(GameProc *proc, int *seq, void *param, void *work);
Field *Field_Create(GameSystem *gsys, HeapID heapId);
void Field_Free(Field *field);
void Field_RenderStart(Field *field);
BOOL Field_CallRoutines(GameSystem *gsys, Field *field);
void FieldG2D_Init(Field *field);
void func_ov036_02180630(Field *field);
void Field_FreeGraphicsSystems(Field *field);
void FieldG3D_InitCallback(void);
void FieldG3D_Init(Field *field);
void FieldG3D_Update(Field *field);
void FieldG3D_RenderPhase1(Field *field);
void FieldG3D_RenderPhase2(Field *field);
void FieldG3D_Free(Field *field);
void FldActSys_AsyncMatLoadTCBFunc(TCB *tcb, void *data);
void FldActSys_VRAMUploadFunc(u32 type, u32 dest, const void *src, u32 size);
void Field_LoadEdgeColorTable(AreaData *area, u16 zoneId);
void Field_LoadActorMatColorPreset(Field *field);
void Field_InitActorSystem(Field *field);
void Field_SuspendActorSystem(Field *field);
BOOL Field_CheckDoRealTimeLoad(Field *field);
BOOL Field_UpdateZoneStatePos(Field *field);
BOOL Field_ShouldSwapZone(Field *field);
void Field_SwapZoneByMatrix(Field *field);
void Field_HotswapSpawnActors(Field *field, GameData *gameData, MMSys *actorSystem, EventData *eventData, u32 zoneId);
void Field_SwapZoneBGM(Field *field, u32 zoneId);
void Field_SwapWeather(Field *field, u32 zoneId);
void Field_CheckGiveDiamondDustMedal(Field *field);
void Field_SwapFog(Field *field, u32 zoneId);
void Field_UpdatePlayerStateZoneID(GameData *gameData, u32 zoneId);
void Field_SwapCameraBoundaries(Field *field, u32 zoneId);
void Field_ResetController(Field *field);
void FieldCameraBoundary_ChangeZone(Field *field, u32 zoneId, HeapID heapId);
void Field_LoadWFBC(GameData *gameData, Field *field, u32 zoneId);
void Field_LoadJoinAvenue(GameData *gameData, Field *field, u32 zoneId);
void Field_LoadSceneArea(Field *field, u32 zoneId);
u32 func_ov036_02180f80(GameCommSys *comm);
BOOL func_ov036_02180fc0(GameCommSys *comm);

void FieldRenderPhase1_Fieldmap(Field *field);
void FieldRenderPhase2_Fieldmap(Field *field);
fx32 func_ov036_0218132c(Field *field);
void FieldColorPostFX_Set(void *postFx, void *luminanceTable, BOOL flashback);

#endif // POKEBW2_FIELD_FIELD_H
