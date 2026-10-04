#ifndef POKEBW2_GFL_NET_H
#define POKEBW2_GFL_NET_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/net_handle.h"
#include "struct_decls.h"

// The unnamed functions below are from the network library. Some appear to synchronize with the other player or
// toggle error checks, but that is not confirmed.

// How the game set up the network: what net.c keeps from GFL_NetInit
typedef struct {
    u8 unk0[8];
    // Called when a machine disconnects
    void (*disconnectCallback)(void *work, int netId);
    // Called when a machine's negotiation is accepted
    void (*negotiationCallback)(void *work, int netId);
    // The data this machine shares with the others, and its size
    void *(*getInfo)(void *work);
    int (*getInfoSize)(void *work);
    u8 unk18[0x3e];
    HeapID heapId;
    u8 unk58[0xc];
    // Whether the parent relays every machine's data (MP mode)
    u8 bMPMode;
    // The kind of connection: 1 and 2 are infrared, 3 and 4 Wi-Fi
    u8 type;
    u8 unk66;
    u8 unk67;
    u8 unk68[6];
    u16 unk6E;
} GFLNetInitData;

// What the network device does, wireless or Wi-Fi; the code calls each through GFLNetSys
typedef BOOL (*GFLNetRecvFunc)(u16 netId, u8 *data, u16 size);
typedef BOOL (*GFLNetSendDoneFunc)(BOOL ok);

typedef struct {
    u8 unk0[4];
    void (*init)(HeapID heapId, void *sys, int a2, void *work);
    void (*unk08)(int a0);
    void (*setConnectBits)(u16 bits);
    u8 unk10[0x2c];
    void (*setDisconnectCallback)(void (*callback)(int netId));
    int (*unk40)(int a0, int a1);
    BOOL (*unk44)(int a0, int a1);
    int (*unk48)(BOOL a0, int a1, int a2, int a3, int a4);
    u8 unk4C[0xc];
    BOOL (*unk58)(void);
    BOOL (*unk5C)(u8 *data);
    u8 *(*getRecvData)(int netId);
    BOOL (*send)(u8 *data, int size, int a2, GFLNetSendDoneFunc callback);
    void (*setRecvCallback)(GFLNetRecvFunc callback);
    BOOL (*unk6C)(void);
    BOOL (*isConnected)(void);
    u8 unk74[8];
    int (*getConnectBits)(void);
    int (*getNetId)(void);
    int (*getSignalLevel)(void);
    BOOL (*isError)(void);
    u8 unk8C[4];
    int (*unk90)(int a0);
    u8 unk94[8];
    void (*unk9C)(void);
    BOOL (*unkA0)(void);
    BOOL (*unkA4)(void);
    u8 unkA8[4];
    BOOL (*unkAC)(void);
    BOOL (*unkB0)(void);
    u8 unkB4[8];
    BOOL (*unkBC)(void);
    void (*unkC0)(int a0);
} GFLNetDevTable;

typedef struct {
    u8 unk0[0x64];
    u8 unk64;
    u8 unk65[7];
    u16 unk6C;
    u8 unk6E[2];
    NetHandle handles[GFL_NET_HANDLE_MAX];
    const GFLNetDevTable *devTable;
    u8 unk344[8];
    void *devWork;
    u8 unk350[2];
    u8 unk352;
} GFLNetSys;

// A network error to report, which func_020424ac records with the line it came from
typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    BOOL reported;
} GFLNetErrorInfo;

GFLNetSys *func_02042e78(void);
GFLNetInitData *func_02042e84(void);
// The number of machines, and the size of each machine's data in a packet
int func_02042dc0(void);
int func_02042de8(void);
GFLNetErrorInfo *func_02042540(void);
void func_020424ac(u32 a0, u32 a1, u32 a2, int line);
BOOL func_02042494(void);
void func_020410dc(void);
BOOL func_02042be8(NetHandle *handle, int command, u16 size, const void *data);
BOOL func_02042c9c(NetHandle *handle, int dest, int command, int size, const void *data, int a5, int a6, int a7);
BOOL func_02042bd8(void);
void *func_02042d94(void);
// NitroSDK's OS_GetMacAddress
void func_0207c33c(u8 *mac);
void func_020430bc(void *data);
void func_02040d78(int netId, int sender, int command, int size, void *data, NetHandle *handle);
BOOL func_02040dc0(int command);
BOOL func_02040dd4(int command);
void *func_02040de8(int command, int netId, int size);
BOOL func_02040c94(int netId);

BOOL GFL_NetErrCheck(void);
void GFL_NetErrMarkShown(void);
void GFL_NetErrShow(u32 a0);
void func_02011de0(void);
// Calls into the functions that show the wireless strength icons
void func_02042ba8(u32 a0, HeapID heapId);
void func_02012154(void);
u32 func_02042bc4(void);
int func_02042a78(void);
void func_02040c20(u32 a0, const void *commands, u32 count, void *work);
void func_02040c64(u32 a0);
void func_020421ac(u32 a0);
BOOL func_02042788(void);
BOOL func_ov036_02180f80(GameCommSys *comm);
BOOL func_0202bde0(GameCommSys *comm);
BOOL func_020427a4(void);
void func_02042860(u32 a0);
// Steps the network while the game waits for it, as before a soft reset
void func_020428e0(void);
u32 func_02042a6c(NetHandle *handle);
u32 func_02042c18(NetHandle *handle, u32 destination, u32 command, u32 size, const void *data, u32 count, u32 a6,
                  u32 a7);
BOOL func_02042ab8(void);
void func_02042e94(BOOL a0);
void func_02042e9c(BOOL a0);

#endif // POKEBW2_GFL_NET_H
