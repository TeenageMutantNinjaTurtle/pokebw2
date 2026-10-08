#ifndef POKEBW2_GFL_NET_IRC_WIRELESS_H
#define POKEBW2_GFL_NET_IRC_WIRELESS_H

#include "types.h"
#include "gfl/net.h"
#include "struct_decls.h"

// Connecting over infrared first and then wirelessly: the machines meet over infrared, swap MAC addresses, and then
// find each other's wireless beacons by them

// Starts it in place of a GFL_NET_TYPE 4 network, returning the init data to start the infrared network with
const GFLNetInitData *func_02042f74(const GFLNetInitData *pNetInit, void *work);
void func_02043028(void);
void func_02043048(void);
// Whether it is running
BOOL func_02043068(void);
void func_0204307c(void *a0);
void (*func_02043088(void (*a0)(void *work), void (*a1)(void *work, BOOL a1), void (*a2)(void *work)))(void *work);
// Adds a MAC address to the ones collected
void func_020430bc(const u8 *mac);
// A collected MAC address
void func_0204313c(u8 *mac, int index);
// Steps it each frame
void func_020431cc(void);
// The command handler for the MAC addresses another machine collected
void func_02043764(int netId, int size, const void *data, void *work, NetHandle *handle);
BOOL func_020437a0(void);
void func_020437dc(int netId);
u8 func_0204381c(void);
void func_02043834(int gameCommandBase);

#endif // POKEBW2_GFL_NET_IRC_WIRELESS_H
