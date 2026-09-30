#ifndef POKEBW2_SYSTEM_GAME_SYSTEM_H
#define POKEBW2_SYSTEM_GAME_SYSTEM_H

#include "types.h"
#include "gfl/proc.h"
#include "nitro/fx.h"
#include "struct_decls.h"

typedef enum {
    GAME_ENTRYPOINT_OPENING,
    GAME_ENTRYPOINT_FIELD_CONTINUE,
    GAME_ENTRYPOINT_DEBUG,
} GameEntryPoint;

struct GameSystemProcData {
    GameEntryPoint entryPoint;
    VecFx32 spawnPos;
    u16 zoneId;
    u16 unk12;
};

extern const GameProcFunctions GAMESYSTEM_PROC_FUNCTIONS;

GameSystemProcData *GameSystem_CreateProcData(GameEntryPoint entryPoint, u16 zoneId, const VecFx32 *spawnPos, s16 unk12);
Field *GSYS_GetField(GameSystem *gsys);
GameCommSys *GSYS_GetGameCommSystem(GameSystem *gsys);
GameData *GSYS_GetGameData(GameSystem *gsys);
LinkFestival *GSYS_GetLinkFestival(GameSystem *gsys);
BOOL GSYS_GetProcMgrState(GameSystem *gsys);
void GSYS_QueueProc(GameSystem *gsys, s32 overlayId, const GameProcFunctions *functions, void *param);
void GSYS_QueueProcAsEvent(GameEvent *event, s32 overlayId, const GameProcFunctions *functions, void *param);
BOOL GSYS_TryBootGameComm(GameSystem *gsys);
void GameSystemTimer_Start(void);
ISS *GameSystem_GetISS(GameSystem *gsys);
u32 getStatusOfFesMission(LinkFestival *festival);

// Run by the start menu before the game starts: loads overlay 338 to run a check, and adds an HBlank task if it fails
void func_0202d6a8(void);

#endif // POKEBW2_SYSTEM_GAME_SYSTEM_H
