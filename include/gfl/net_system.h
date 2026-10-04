#ifndef POKEBW2_GFL_NET_SYSTEM_H
#define POKEBW2_GFL_NET_SYSTEM_H

#include "types.h"
#include "gfl/heap.h"

// The packets between the machines: queuing commands to send, writing them into packets with a CRC and a sequence
// number, and reading the commands in the packets that arrive

BOOL func_0203ec44(int size, HeapID heapId);
int func_0203ecac(int a0);
BOOL func_0203ecd0(int a0);
int func_0203ed68(int a0, int size, int a2, BOOL (*callback)(void));
BOOL func_0203ede0(int a0, int size);
BOOL func_0203ee50(int size);
void func_0203eea4(int a0);
int func_0203eec0(BOOL a0, const u8 *mac, int size, void (*callback)(void));
void func_0203ef38(void);
// Forgets what has arrived from a machine, as when it disconnects
void func_0203efd0(u32 netId);
// Sends and receives, each frame
BOOL func_0203efe8(void);
void func_0203f0f8(void);
BOOL func_0203fafc(int command, u8 *data, int size, u32 unused, int dest, int netId, BOOL noCopy);
int func_0203fbb8(void);
int func_0203fbcc(void);
// Whether a machine is connected
BOOL func_0203fe74(u16 netId);
// The number of machines connected
int func_0203ff6c(void);
BOOL func_0203ff8c(void);
// This machine's network ID
u16 func_0203ffc4(void);
// The connected machines but the parent, as bits
u32 func_0204001c(void);
BOOL func_0204003c(void);
BOOL func_02040078(void);
// Whether a command is waiting to be sent
BOOL func_020400b8(u16 command, int dest);
BOOL func_020400f0(void);
void func_02040104(u8 a0);
void func_02040118(BOOL a0);
// Sets and clears the network error
void func_02040158(void);
void func_0204016c(void);
void func_02040180(void);
BOOL func_02040198(void);
// A network ID, or GFL_NET_NETID_SERVER for one past the last machine
int func_020401d4(int netId);

#endif // POKEBW2_GFL_NET_SYSTEM_H
