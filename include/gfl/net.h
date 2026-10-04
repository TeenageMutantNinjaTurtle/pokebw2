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
    // The game's commands, a NetCommand table
    const void *commandTable;
    int commandNum;
    // Called when a machine disconnects
    void (*disconnectCallback)(void *work, int netId);
    // Called when a machine's negotiation is accepted
    void (*negotiationCallback)(void *work, int netId);
    // The data this machine shares with the others, and its size
    void *(*getInfo)(void *work);
    int (*getInfoSize)(void *work);
    void *unk18;
    void *unk1C;
    void *unk20;
    void (*unk24)(NetHandle *handle, int a1, void *work);
    void (*unk28)(NetHandle *handle, int a1, void *work);
    void (*unk2C)(void *work);
    void (*unk30)(void *work);
    u8 unk34[0xc];
    int (*unk40)(void *work);
    int (*unk44)(void *work);
    // The size of the heap for Wi-Fi
    u32 wifiHeapSize;
    u8 unk4C[8];
    HeapID parentHeapId;
    HeapID heapId;
    HeapID wifiHeapId;
    HeapID ircHeapId;
    // Where the wireless signal icon is
    u16 iconX;
    u16 iconY;
    u8 maxConnectNum;
    // The largest packet
    u8 maxSendSize;
    u8 unk62;
    u8 unk63;
    // Whether the parent relays every machine's data (MP mode)
    u8 bMPMode;
    // A GFL_NET_TYPE_*
    u8 bNetType;
    u8 unk66;
    // The high byte of the game's commands
    u8 gameCommandBase;
    u8 unk68[4];
    u16 unk6C;
    u16 unk6E;
} GFLNetInitData;

// The kinds of connection: Wi-Fi through DWC, and the others through the wireless or infrared devices
#define GFL_NET_TYPE_WIFI 1
#define GFL_NET_TYPE_WIFI_LOBBY 2
#define GFL_NET_TYPE_WIFI_GTS 6

// What the network device does, wireless or Wi-Fi; the code calls each through GFLNetSys
typedef BOOL (*GFLNetRecvFunc)(u16 netId, u8 *data, u16 size);
typedef BOOL (*GFLNetSendDoneFunc)(BOOL ok);

typedef struct {
    void (*unk00)(int a0, int a1);
    void (*init)(HeapID heapId, void *sys, int a2, void *work);
    void (*unk08)(int a0);
    // Runs the device each frame with the connected machines, returning a negative error or a status
    int (*update)(u16 connectBits);
    BOOL (*unk10)(int a0, int a1);
    BOOL (*unk14)(int a0);
    u8 unk18[0x10];
    int (*unk28)(int a0);
    int (*unk2C)(int a0);
    u8 unk30[8];
    BOOL (*unk38)(int a0);
    void (*setDisconnectCallback)(void (*callback)(int netId));
    int (*unk40)(int a0, BOOL (*callback)(void));
    BOOL (*unk44)(int a0, int a1);
    int (*unk48)(BOOL a0, const u8 *mac, int a2, int a3, void (*callback)(void));
    u8 unk4C[4];
    BOOL (*unk50)(int a0, int a1, int a2);
    BOOL (*unk54)(BOOL a0, int a1);
    BOOL (*unk58)(void);
    BOOL (*unk5C)(u8 *data);
    u8 *(*getRecvData)(int netId);
    BOOL (*send)(u8 *data, int size, int a2, GFLNetSendDoneFunc callback);
    void (*setRecvCallback)(GFLNetRecvFunc callback);
    BOOL (*unk6C)(void);
    BOOL (*isConnected)(void);
    BOOL (*unk74)(void);
    BOOL (*unk78)(void);
    int (*getConnectBits)(void);
    int (*getNetId)(void);
    int (*getSignalLevel)(void);
    BOOL (*isError)(void);
    void (*unk8C)(int a0);
    int (*unk90)(int a0);
    u8 unk94[8];
    void (*unk9C)(void);
    BOOL (*unkA0)(void);
    BOOL (*unkA4)(void);
    BOOL (*unkA8)(void);
    BOOL (*unkAC)(void);
    BOOL (*unkB0)(void);
    void (*unkB4)(void);
    void (*unkB8)(int a0);
    BOOL (*unkBC)(void);
    void (*unkC0)(int a0);
    void (*unkC4)(int a0);
} GFLNetDevTable;

// The network library's state, with a copy of the game's init data
typedef struct {
    GFLNetInitData aNetInit;
    NetHandle handles[GFL_NET_HANDLE_MAX];
    const GFLNetDevTable *pDevTable;
    u8 unk344[4];
    // Called when the network has ended
    void (*exitCallback)(void *work);
    void *devWork;
    u8 unk350[2];
    u8 unk352;
    u8 unk353;
} GFLNetSys;

// The network error, which func_020424ac records
typedef struct {
    int code;
    u32 unk4;
    u32 unk8;
    // Nonzero once an error is recorded, the line it was found on for net_system.c's
    int type;
} GFLNetErrorInfo;

GFLNetSys *func_02042e78(void);
GFLNetInitData *func_02042e84(void);
// The number of machines, and the size of each machine's data in a packet
int func_02042dc0(void);
int func_02042de8(void);
void func_020410dc(void);
BOOL func_02042be8(NetHandle *handle, int command, u16 size, const void *data);
BOOL func_02042c9c(NetHandle *handle, int dest, int command, int size, const void *data, int a5, int a6, int a7);
BOOL func_02042bd8(void);
void *func_02042d94(void);
void func_02042e18(void);
BOOL func_02043068(void);
// NitroSDK's OS_GetMacAddress
void func_0207c33c(u8 *mac);
void func_020430bc(void *data);
// Command handlers of the other parts of the library
void func_02043764(int netId, int size, void *data, void *work, NetHandle *handle);
void func_02043ca0(int netId, int size, void *data, void *work, NetHandle *handle);
void *func_02043c64(int netId, void *work, int size);
void func_02043d6c(int netId, int size, void *data, void *work, NetHandle *handle);
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
