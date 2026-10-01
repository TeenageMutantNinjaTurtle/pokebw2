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

// An actor of a zone's entities, from which actors are created. Names and layout from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)
struct ZoneNPC {
    u16 uid;
    u16 modelId;
    u16 moveCode;
    u16 evType;
    u16 spawnFlag;
    u16 scrId;
    u16 direction;
    u16 param0;
    u16 param1;
    u16 param2;
    u16 areaW;
    u16 areaH;
    BOOL isRail;
    union {
        struct {
            u16 x;
            u16 z;
            s32 y;
        } grid;
        struct {
            u16 railIndex;
            u16 frontPos;
            u16 sidePos;
        } rail;
    } pos;
};

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
u32 GetIndexOfObjID(u16 objCode);
// An object code's record in ARCID_MMODEL_TBL, from 4 bytes into the file, at the index GetIndexOfObjID returns
typedef struct {
    u8 unk0[9];
    u8 unk9;
    u8 unkA[6];
    u16 unk10;
    u8 unk12[10];
} ObjCodeRecord;

// Overlay 36's table that func_ov036_02194650 indexes, by a record's unk9
typedef struct {
    u16 unk0_0 : 14;
    u16 unk0_14 : 2;
} Ov036Unk021cf1c8Entry;

typedef struct {
    const Ov036Unk021cf1c8Entry *const *unk0;
    u32 unk4;
} Ov036Unk021cf1c8;

extern const Ov036Unk021cf1c8 data_ov036_021cf1c8[];
void FldAct_SetShadowGroup(FieldActor *actor, u32 group);
u32 GetActorFaceDir(FieldActor *actor);
void CheckSetActorFaceDir(FieldActor *actor, u16 dir);
void DisableActorMovement(FieldActor *actor);
void EnableActorMovement(FieldActor *actor);
u16 GetActorZoneID(FieldActor *actor);
BOOL IsActorFlag16(FieldActor *actor);
// Steps through the system's actors from *index, returning TRUE with the next one in *actor
BOOL NextActor(MMSys *mmSys, FieldActor **actor, u32 *index);
FieldActor *CreateNewActorByEntityNoWKOBJCODE(MMSys *mmSys, const ZoneNPC *npc, u16 zoneId);
// Sets a ZoneNPC's position on the grid
void func_ov012_021682c0(ZoneNPC *npc, u16 x, u16 z, s32 y);
// The actor's user parameters 0 to 2
u16 GetActorUserParam(FieldActor *actor, u32 index);
void SetActorUserParam(FieldActor *actor, u16 value, u32 index);
void SetActorSCRID(FieldActor *actor, u16 scriptId);
void SetActorWPosAll(FieldActor *actor, const VecFx32 *pos, u32 dir);
FieldActor *CreateNewActorByParam(MMSys *mmSys, s16 x, s16 z, u16 dir, u16 id, u16 objCode, u16 moveCode, u16 zoneId);
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
