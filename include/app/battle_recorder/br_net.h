#ifndef POKEBW2_APP_BATTLE_RECORDER_BR_NET_H
#define POKEBW2_APP_BATTLE_RECORDER_BR_NET_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The Battle Recorder's connection to the Global Link (br_net.c), used by its online modes

BrNet *func_ov271_021f6224(GameData *gameData, u32 a1, HeapID heapId);
void func_ov271_021f6300(BrNet *net);
void func_ov271_021f6348(BrNet *net);

// The data of a request to the Global Link. The musical photo upload, request 0, sends the photo in data
typedef struct {
    void *data;
    u32 unk4;
} BrNetRequestParam;

// Starts a request, 0 to 8
void BrNet_StartRequest(BrNet *net, u32 type, const BrNetRequestParam *param);
// TRUE once the request has finished
BOOL BrNet_IsRequestEnd(BrNet *net);
// TRUE if the request's result has a message, which it gives in msgID
BOOL BrNet_GetResultMsg(BrNet *net, u32 *msgID);
// 2 once the connection has had an error, which ends the Battle Recorder's screens
u32 BrNet_CheckError(BrNet *net);
// TRUE once the connection has failed
BOOL func_ov271_021f66f8(BrNet *net);

#endif // POKEBW2_APP_BATTLE_RECORDER_BR_NET_H
