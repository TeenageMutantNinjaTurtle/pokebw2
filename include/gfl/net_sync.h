#ifndef POKEBW2_GFL_NET_SYNC_H
#define POKEBW2_GFL_NET_SYNC_H

#include "types.h"
#include "struct_decls.h"

struct NetSyncWork {
    u8 pad0[0x72];
    u8 state;
    u8 error;
    u8 pad1[0x30];
    u8 received;
};

struct NetSyncPacket {
    u16 value;
    u8 kind;
    u8 pad;
};

struct NetSyncCommand {
    void (*callback)(u32 a0, u32 a1, const NetSyncPacket *packet, NetSyncWork *work);
    void *arg;
};

extern const NetSyncCommand data_ov164_021999e8;

void func_ov164_021998c0(NetSyncWork *work);
void func_ov164_021998c8(NetSyncWork *work);
void func_ov164_021998d4(NetSyncWork *work);
u32 func_ov164_02199944(NetSyncWork *work, u8 kind, u16 value);
void func_ov164_02199984(u32 a0, u32 a1, const NetSyncPacket *packet, NetSyncWork *work);
void func_ov164_021999a8(u32 ignored, u32 a1);
BOOL func_ov164_021999bc(NetSyncWork *work, u32 a1);

#endif // POKEBW2_GFL_NET_SYNC_H
