#ifndef POKEBW2_APP_COMM_TVT_CTVT_GAME_BALLOON_H
#define POKEBW2_APP_COMM_TVT_CTVT_GAME_BALLOON_H

#include "types.h"
#include "gfl/heap.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// The balloon game's 3D objects: each member's balloon, which grows with each pump and pops, and the puffs of air
// shot at it

// The balloon of the member with the net ID, which is also its models' scene. pos places the balloons of the others
CtvtGameBalloon *CtvtGameBalloon_Create(CtvtGame *game, u16 netId, u8 pos, BOOL active, HeapID heapId);
void CtvtGameBalloon_Delete(CtvtGameBalloon *balloon);
void CtvtGameBalloon_Update(CtvtGameBalloon *balloon);
void CtvtGameBalloon_Draw(CtvtGameBalloon *balloon);
// Pumps the balloon, and returns whether it popped
BOOL CtvtGameBalloon_Pump(CtvtGameBalloon *balloon);
BOOL CtvtGameBalloon_IsIdle(CtvtGameBalloon *balloon);
void CtvtGameBalloon_Wobble(CtvtGameBalloon *balloon);
BOOL CtvtGameBalloon_IsBusy(CtvtGameBalloon *balloon);

// A puff of air from the column x that rises until topY. vanishOnHit drops it as soon as it gets there
CtvtGameShot *CtvtGameShot_Create(CtvtGame *game, u16 scene, int x, u8 vanishOnHit, fx32 topY, HeapID heapId);
void CtvtGameShot_Delete(CtvtGameShot *shot);
void CtvtGameShot_Update(CtvtGameShot *shot);
void CtvtGameShot_Draw(CtvtGameShot *shot);

#endif // POKEBW2_APP_COMM_TVT_CTVT_GAME_BALLOON_H
