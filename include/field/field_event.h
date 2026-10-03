#ifndef POKEBW2_FIELD_FIELD_EVENT_H
#define POKEBW2_FIELD_FIELD_EVENT_H

#include "types.h"
#include "field/zone.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Moves the player to another zone with a transition, such as through a door
struct WarpSequence {
    GameEvent *parent;
    GameSystem *gsys;
    GameData *gameData;
    Field *field;
    u32 unk10;
    u32 transitionType;
    u16 zoneId;
    ZoneSpawnInfo spawn;
    u32 outTransition;
    u32 inTransition;
    BOOL seasonChanged;
    u8 startSeason;
    u8 endSeason;
    u32 unk48;
    u32 unk4C;
};

GameEvent *CallFieldMapEntranceInTransition(GameSystem *gsys, Field *field, u32 type, u32 a3, u32 a4, u8 startSeason,
                                            u8 endSeason);
GameEvent *CallFieldMapEntranceOutTransition(GameSystem *gsys, Field *field, u32 type, u32 a3, u32 a4);
GameEvent *CallFieldMapEntranceOutTransitionDefault(GameSystem *gsys, Field *field, u32 type, u32 a3);
GameEvent *CreateFieldCloseEvent(GameSystem *gsys, Field *field);
GameEvent *EventBGMChange_Create(GameSystem *gsys, u32 bgm, u32 a2, u32 a3);
GameEvent *EventBGMPlay_Create(GameSystem *gsys, u32 bgm);
GameEvent *EventBGMFadeWait_Create(GameSystem *gsys);
GameEvent *EventBGMPop_CreateEx(GameSystem *gsys, u32 a1, u32 a2);
GameEvent *EventBGMPlayPushEx_Create(GameSystem *gsys, u32 bgm, u32 a2, u32 a3);
GameEvent *EventDig_Create(GameEvent *event, GameSystem *gsys, Field *field, BOOL seasonChanged);
BOOL EventEntralinkWarpIn_CheckAllowed(GameSystem *gsys);
GameEvent *EventEscapeRope_Create(GameEvent *event, GameSystem *gsys, Field *field, BOOL seasonChanged);
GameEvent *EventFieldCloseKeepSound_Create(GameSystem *gsys, Field *field);
GameEvent *EventFieldOpen_Create(GameSystem *gsys);
GameEvent *EventFieldOpen_CreateHeadless(GameSystem *gsys);
GameEvent *EventFieldOpenRestoreLCD_Create(GameSystem *gsys);
// Runs the proc as a field subprocess, then calls callback with work if there is a callback, and frees work
GameEvent *EventFieldSubprocessCall_CreateWithCallback(GameSystem *gsys, Field *field, s32 overlayId,
                                                       const GameProcFunctions *functions, void *param,
                                                       void (*callback)(void *work), void *work);
GameEvent *EventFieldSubprocessTransition_Create(GameSystem *gsys, Field *field, s32 overlayId,
                                                 const GameProcFunctions *functions, void *param);
GameEvent *EventPlayerSpinDown_Create(GameEvent *event, GameSystem *gsys, Field *field);
GameEvent *EventQuicksandArrive_Create(GameEvent *event, GameSystem *gsys, Field *field);
GameEvent *EventQuicksandDrawIn_Create(GameEvent *event, GameSystem *gsys, Field *field, VecFx32 *pos);
GameEvent *EventTeleportEffect_Create(GameEvent *event, GameSystem *gsys, Field *field, BOOL a3);
GameEvent *EventWaitFieldSound_Create(GameSystem *gsys);
void func_ov036_021b50c8(PlaceName *placeName, s32 zoneId);
void func_ov036_021b5168(PlaceName *placeName);
GameEvent *func_ov036_021b8850(GameSystem *gsys, Field *field, u32 a2, u32 a3, u32 a4);
GameEvent *func_ov036_021b95ac(GameEvent *event, GameSystem *gsys, Field *field, BOOL seasonChanged, u16 prevSeason,
                               u16 season);
GameEvent *func_ov036_021b95e0(GameEvent *event, GameSystem *gsys, Field *field, BOOL seasonChanged, u16 prevSeason,
                               u16 season);
GameEvent *func_ov036_021b9614(GameEvent *event, GameSystem *gsys, Field *field);
GameEvent *func_ov036_021b9664(GameEvent *event, GameSystem *gsys, Field *field);
GameEvent *func_ov036_021b9df8(GameEvent *event, GameSystem *gsys, Field *field);
GameEvent *EventWarpSequence_CreateIn(WarpSequence *warp);
GameEvent *EventWarpSequence_CreateOut(WarpSequence *warp);
GameEvent *func_ov033_021773e4(GameSystem *gsys, void *args);
GameEvent *func_ov156_021f59e0(GameSystem *gsys, void *args);

#endif // POKEBW2_FIELD_FIELD_EVENT_H
