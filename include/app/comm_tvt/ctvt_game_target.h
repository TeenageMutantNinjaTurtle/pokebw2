#ifndef POKEBW2_APP_COMM_TVT_CTVT_GAME_TARGET_H
#define POKEBW2_APP_COMM_TVT_CTVT_GAME_TARGET_H

#include "types.h"
#include "gfl/g3d.h"
#include "gfl/tcb.h"
#include "nitro/fx.h"
#include "struct_decls.h"

// A face that floats up in the target game. Its scene is its member's, whose actors are the face as it is, as its
// member hit it and as another hit it; scene 4 holds the effects of the hits
struct CtvtGameTarget {
    BOOL active;
    TCB *tcb;
    CtvtGame *game;
    G3DManager *g3d;
    u16 scene;
    SRTMatrix srt;
    // 0 until it is hit, then 1 by its member, 2 by another
    int actor;
    // 1 to 3, the nearest
    int depth;
    s8 alpha;
    fx32 hitFrame;
    BOOL hitAnimating;
    fx32 grow;
    // What the hit scored: 0 or 1 by its member, before and after the hurry, 2 or 3 by another
    u32 hitKind;
    VecFx32 velocity;
    // The last frame of the host that it moved for
    u16 frame;
    s8 fadeFrames;
    u8 hitPending;
};

void CtvtGameTarget_Init(CtvtGameTarget *target);
void CtvtGameTarget_Delete(CtvtGameTarget *target);
// Moves the target for each of the host's frames since the last update, and deletes it once it has left the screen
void CtvtGameTarget_Update(CtvtGameTarget *target);
void CtvtGameTarget_Draw(CtvtGameTarget *target);

#endif // POKEBW2_APP_COMM_TVT_CTVT_GAME_TARGET_H
