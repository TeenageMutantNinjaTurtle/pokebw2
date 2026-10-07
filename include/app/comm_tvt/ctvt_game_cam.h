#ifndef POKEBW2_APP_COMM_TVT_CTVT_GAME_CAM_H
#define POKEBW2_APP_COMM_TVT_CTVT_GAME_CAM_H

#include "types.h"
#include "app/comm_tvt/ctvt_game.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The minigames' camera: the screen that takes this machine's pictures before a game, and the pictures that go on
// its face or balloon. Only what ctvt_game.c uses is known until ctvt_game_cam.c is decompiled

struct CtvtGameCam {
    u8 unk0[8];
    // This machine's pictures
    void *pictures[3];
};

// Starts taking the pictures
CtvtGameCamTask *func_ov257_021a8090(CtvtGameCam *cam, HeapID heapId);
// 0 while the pictures are taken, 1 when they are and 2 on an error
int func_ov257_021a81d4(CtvtGameCamTask *task);
void func_ov257_021a8228(CtvtGameCamTask *task);
// type is the game's, CTVT_GAME_TYPE_*, and members the others in the call
CtvtGameCam *func_ov257_021a82cc(HeapID heapId, BOOL cameraEnabled, int type, u8 unk3dc, CtvtGameMember *members,
                                 CameraSystem *cameraSystem);
void func_ov257_021a83ac(CtvtGameCam *cam);

#endif // POKEBW2_APP_COMM_TVT_CTVT_GAME_CAM_H
