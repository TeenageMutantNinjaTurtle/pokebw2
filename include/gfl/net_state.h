#ifndef POKEBW2_GFL_NET_STATE_H
#define POKEBW2_GFL_NET_STATE_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/net.h"

// The state of the connection: a function for each state that runs every frame, for the parent and the children
// of a wireless connection, Wi-Fi, and ending the connection. The line numbers each state change passes are the
// original's

// Starts the network, calling callback when it is ready
void func_0204129c(HeapID heapId, void (*callback)(void *work));
// Connects to the parent with a MAC address, or becomes the parent
void func_02041354(const u8 *mac, BOOL parent);
void func_020413f0(void);
// Runs the state, each frame. Returns TRUE when the network is not running
BOOL func_02041410(void);
void func_020414c0(HeapID unused);
void func_02041a30(int a0, void (*callback)(void *work), int a2);
void func_02041c00(int mode, int a1, const u8 *mac);
// Command handlers
void func_02041cd8(int netId, int size, void *data, void *work, NetHandle *handle);
void func_02041d0c(int netId, int size, void *data, void *work, NetHandle *handle);
void func_02041e20(int netId, int size, void *data, void *work, NetHandle *handle);
void func_020421f8(int netId, int size, void *data, void *work, NetHandle *handle);
// Ends the network, calling callback when it has
void func_02041da8(void (*callback)(void *work));
void func_02041de4(void);
void func_02041dfc(void);
BOOL func_02041fd0(int a0);
BOOL func_0204200c(void);
BOOL func_0204204c(void);
void func_0204208c(void);
// Where the Wi-Fi connection is: 0 connecting, 1 connected, 3 to 5 failed, 2 otherwise
int func_020420b4(void);
void func_020421ac(BOOL a0);
u8 func_02042210(void);
BOOL func_02042220(void);
BOOL func_0204223c(void);
void func_0204230c(void (*callback)(void *work));
void func_020423e0(void);
void func_02042410(u8 a0);
void func_02042424(int a0);
BOOL func_02042454(u8 a0);
void func_02042478(void);
u8 func_02042494(void);
// Records a network error: its code, and type nonzero to set the network error
void func_020424ac(int code, u32 a1, u32 a2, int type);
void func_020424e4(void);
GFLNetErrorInfo *func_02042540(void);
BOOL func_02042580(void);

#endif // POKEBW2_GFL_NET_STATE_H
