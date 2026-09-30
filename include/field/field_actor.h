#ifndef POKEBW2_FIELD_FIELD_ACTOR_H
#define POKEBW2_FIELD_FIELD_ACTOR_H

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// The directions that actors face and move in
#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3

// A position on the grid of 16-unit tiles. The game copies it as 8 bytes, with a field after z
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 unk6;
} GridPos;

GameEvent *CallEventPrepareResidentActorsForZoneChange(GameSystem *gsys, Field *field);
void DisableAllActorsMovement(MMSys *mmSys);
void EnableAllActorsMovement(MMSys *mmSys);
// Whether the actor has finished its movement commands
BOOL IsAllActorAcmdFinished(FieldActor *actor);
void FldActSys_ClearCache(MMSys *mmSys);
void FldActSys_DeleteAllActors(MMSys *mmSys);
VecFx32 *GetMModelWPosPtr(FieldActor *actor);
s32 GetZoneNPCInfoCacheIdx(u16 zoneId);
ZoneNPC *GetZoneNPCs(EventData *eventData);
u32 GetZoneNPCsCount(EventData *eventData);
void LoadMModelSystemInfoCache(MMSys *mmSys, s32 index);
void SetActorFlag(FieldActor *actor, u32 flag);
void SetActorHidden(FieldActor *actor, BOOL hidden);
void FldAct_GetGPos(FieldActor *actor, GridPos *pos);
u16 GetActorUID(FieldActor *actor);
u16 FldAct_GetObjCode(FieldActor *actor);
void FldAct_SetShadowGroup(FieldActor *actor, u32 group);
u32 GetActorFaceDir(FieldActor *actor);
void CopyActorWPos(FieldActor *actor, VecFx32 *dest);
void SetActorWPosValue(FieldActor *actor, const VecFx32 *pos);
// The actor with an ID, or NULL
FieldActor *FindFieldActor(MMSys *mmSys, u16 id);
// Moves grid coordinates or a position by a distance in a direction
void AdjusGridXZByDir(u32 dir, s16 *x, s16 *z, s16 distance);
void ExpandVecInGridDir(u16 dir, VecFx32 *pos, fx32 distance);
// Sets x and z to the center of a tile, leaving y
void ConvGXZToVector(u32 x, u32 z, VecFx32 *pos);
void SpawnAllZoneNPCs(MMSys *mmSys, ZoneNPC *npcs, s32 zoneId, u32 count, EventWork *eventWork);

#endif // POKEBW2_FIELD_FIELD_ACTOR_H
