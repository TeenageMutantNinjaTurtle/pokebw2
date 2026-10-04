#ifndef POKEBW2_FIELD_FIELD_ACTOR_H
#define POKEBW2_FIELD_FIELD_ACTOR_H

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"
#include "system/game_event.h"

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
// Field names from swan's ZoneNPCPositionGrid and ZoneNPCPositionRail.
struct ZoneNPCGridPosition {
    u16 x;
    u16 z;
    s32 y;
};

struct ZoneNPCRailPosition {
    u16 railIndex;
    u16 frontPos;
    u16 sidePos;
};

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
        ZoneNPCGridPosition grid;
        ZoneNPCRailPosition rail;
    } pos;
};

// An actor's move code and its functions, called with the actor: unkC before the code is changed
typedef struct {
    u32 code;
    void (*unk4)(FieldActor *actor);
    void (*unk8)(FieldActor *actor);
    void (*unkC)(FieldActor *actor);
    void (*unk10)(FieldActor *actor);
} FieldActorMoveCode;

GameEvent *CallEventPrepareResidentActorsForZoneChange(GameSystem *gsys, Field *field);
GameEventReturnCode func_ov012_0215c59c(GameEvent *event, u32 *state, void *data);
void DisableAllActorsMovement(MMSys *mmSys);
FieldActor *FindPlayerFieldActor(MMSys *mmSys);
void EnableAllActorsMovement(MMSys *mmSys);
// Whether the actor has finished its movement commands
BOOL IsAllActorAcmdFinished(FieldActor *actor);
void FldActSys_ClearCache(MMSys *mmSys);
void FldActSys_DeleteAllActors(MMSys *mmSys);
VecFx32 *GetMModelWPosPtr(FieldActor *actor);
s32 GetZoneNPCInfoCacheIdx(u16 zoneId);
ZoneNPC *GetZoneNPCs(EventData *eventData);
u32 GetZoneNPCsCount(EventData *eventData);
void SetZoneNPCLocation(EventData *eventData, u32 npcId, u16 direction, u16 x, s32 y, u16 z);
void SetZoneNPCMdlID(EventData *eventData, u16 npcId, u16 objCode);
void SetZoneNPCSCRID(EventData *eventData, u16 npcId, u16 scriptId);
void GetNPCMdlInfoForOBJCODE(MMSys *actorSystem, u16 objCode, void *modelInfo);
void LoadMModelSystemInfoCache(MMSys *mmSys, s32 index);
void SetActorFlag(FieldActor *actor, u32 flag);
void SetActorMovementFlag(FieldActor *actor, u32 flag);
void ClearActorMovementFlag(FieldActor *actor, u32 flag);
void FldAct_InvokeUpdateCallback(FieldActor *actor);
void ChangeActorDirection(FieldActor *actor, u32 dir);
void SetActorHidden(FieldActor *actor, BOOL hidden);
void FldAct_GetGPos(FieldActor *actor, GridPos *pos);
u16 GetActorUID(FieldActor *actor);
u16 FldAct_GetSCRID(FieldActor *actor);
u16 FldAct_GetObjCode(FieldActor *actor);
// Makes the actor the one an entry describes
void FldAct_Transplant(FieldActor *actor, const ZoneNPC *npc);
u16 GetActorMotionDir(FieldActor *actor);
BOOL func_ov012_0216773c(FieldActor *actor);
void func_ov036_0219634c(FieldActor *actor, u16 *a1, u16 *a2);
void func_ov036_021963a4(FieldActor *actor, u16 a1, u16 a2);
// The field object code of a Pokémon walking in the field, in the main module
u16 GetPokemonFieldOBJCODE(void *pokemonData, u16 species, u16 sex, u16 form);
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
u16 GetActorFaceDir(FieldActor *actor);
void CheckSetActorFaceDir(FieldActor *actor, u16 dir);
void DisableActorMovement(FieldActor *actor);
void EnableActorMovement(FieldActor *actor);
void DeleteActor(FieldActor *actor);
// The actor's current movement command
u16 FldAct_GetAcmd(FieldActor *actor);
void FldAct_UpdateBlInfoForNewObjCode(FieldActor *actor, u16 objCode);
void SetActorGPosX(FieldActor *actor, s16 x);
void SetActorGPosZ(FieldActor *actor, s16 z);
// Whether the actor has flag 4, and setting or clearing flag 0x80 (set when the value is not TRUE)
BOOL func_ov012_02167520(FieldActor *actor);
void func_ov012_02167580(FieldActor *actor, BOOL value);
// Ends the actor's movement command
void func_ov012_02166f2c(FieldActor *actor);
s16 GetGPosX(FieldActor *actor);
s16 GetGPosZ(FieldActor *actor);
void SetActorGPos(FieldActor *actor, s16 x, s16 y, s16 z, u16 dir);
void SetActorMotionDir(FieldActor *actor, u16 dir);
void ChangeActorMoveCodeSeq(FieldActor *actor, u16 moveCode);
MMSys *GetActorMModelSystem(FieldActor *actor);
G3DMapper *GetMMSysG3DMapper(MMSys *system);
BOOL GetTerrainAtPosByActor(FieldActor *actor, const VecFx32 *position, FieldTerrain *terrain);
Field *GetMMSysField(MMSys *mmSys);
// The movement command of a direction in the row of a table that has the command
u16 GetAcmdForDir(u32 dir, u32 acmd);
// The collision flags of the tile next to the actor in a direction
u32 ActorRouteCollCheckOneTileInDir(FieldActor *actor, u16 dir);
// Starts a movement command
void func_ov012_02166eb0(FieldActor *actor, u16 acmd);
void FldAct_SetAcmd(FieldActor *actor, u16 acmd);
BOOL func_ov012_02166ef8(FieldActor *actor);
// Whether the actor's movement command has finished
BOOL func_ov036_0218f01c(FieldActor *actor);
// Set movement flag 0x10, clear it, and clear flag 0x40
void func_ov012_021674b0(FieldActor *actor);
void func_ov012_021674bc(FieldActor *actor);
void func_ov012_021674e8(FieldActor *actor);
// Gives the actor a move code of its own functions
void func_ov012_021682e8(FieldActor *actor, const FieldActorMoveCode *moveCode);
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
FieldActor *FindActorByMoveCode(MMSys *mmSys, u16 code);
// Moves grid coordinates or a position by a distance in a direction
void AdjusGridXZByDir(u32 dir, s16 *x, s16 *z, s16 distance);
void ExpandVecInGridDir(u16 dir, VecFx32 *pos, fx32 distance);
void func_ov012_021670f4(FieldActor *actor, u32 value);
void func_ov012_02167564(FieldActor *actor, u32 value);
// Sets x and z to the center of a tile, leaving y
void ConvGXZToVector(u32 x, u32 z, VecFx32 *pos);
void SpawnAllZoneNPCs(MMSys *mmSys, ZoneNPC *npcs, s32 zoneId, u32 count, EventWork *eventWork);

BOOL func_ov012_02166ecc(FieldActor *actor);

#endif // POKEBW2_FIELD_FIELD_ACTOR_H
