#ifndef POKEBW2_APP_MYSTERY_MYSTERY_NET_H
#define POKEBW2_APP_MYSTERY_MYSTERY_NET_H

// Mystery Gift's receiving of gifts, by wireless, infrared or Wi-Fi (ov197, mystery_net.c). Our names; swan has none
// for this overlay

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// What MysteryNet_GetRecvData gives
enum {
    MYSTERY_NET_RECV_NONE,
    MYSTERY_NET_RECV_OK,
    MYSTERY_NET_RECV_ERROR,
};

// What MysteryNet_GetError gives
enum {
    MYSTERY_NET_ERROR_NONE,
    MYSTERY_NET_ERROR_FATAL,
    MYSTERY_NET_ERROR_DISCONNECT,
};

MysteryNet *MysteryNet_Create(SaveControl *save, HeapID heapId);
void MysteryNet_Delete(MysteryNet *net);
void MysteryNet_Main(MysteryNet *net);
void MysteryNet_ChangeState(MysteryNet *net, u32 state);
u32 MysteryNet_GetState(MysteryNet *net);
u32 MysteryNet_GetBeaconFlags(MysteryNet *net);
u32 MysteryNet_GetRecvData(MysteryNet *net, void *buffer, u32 size);
u32 MysteryNet_GetError(MysteryNet *net);
void MysteryNet_ClearError(MysteryNet *net);

#endif // POKEBW2_APP_MYSTERY_MYSTERY_NET_H
