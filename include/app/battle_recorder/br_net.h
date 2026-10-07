#ifndef POKEBW2_APP_BATTLE_RECORDER_BR_NET_H
#define POKEBW2_APP_BATTLE_RECORDER_BR_NET_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The Battle Recorder's connection to the Global Link (br_net.c), used by its online modes

BrNet *func_ov271_021f6224(GameData *gameData, u32 a1, HeapID heapId);
void func_ov271_021f6300(BrNet *net);
void func_ov271_021f6348(BrNet *net);
// TRUE once the connection has failed
BOOL func_ov271_021f66f8(BrNet *net);

#endif // POKEBW2_APP_BATTLE_RECORDER_BR_NET_H
