#ifndef POKEBW2_BATTLE_BTLV_H
#define POKEBW2_BATTLE_BTLV_H

#include "types.h"
#include "gfl/clact.h"
#include "gfl/graphics.h"
#include "gfl/heap.h"
#include "struct_decls.h"

struct BtlvStringParam {
    u16 message;
    u8 mode;
    u8 type : 4;
    u8 count : 4;
    u32 args[9];
};

// The battle's display: the BG, 2D and 3D systems, and the battle view and AI overlays
extern const BGSysLCDConfig data_ov167_021da8d4;
extern const ClActSysSetup data_ov167_021da8e4;
extern const BGSysVRAMConfig data_ov167_021da900;

void func_ov167_021ce604(HeapID heapId);
void func_ov167_021ce638(void);
void func_ov167_021ce668(HeapID heapId);
void func_ov167_021ce678(HeapID heapId);
void func_ov167_021ce748(void);

void Btlv_StringParam_Setup(BtlvStringParam *param, u32 type, u16 message);
void Btlv_StringParam_AddArg(BtlvStringParam *param, u32 arg);

// The battle view, in overlay 168

void func_ov168_021df138(void);
u32 func_ov168_021e04ec(u8 pos);

BtlvCore *BtlvCore_Create(BtlMainModule *mainModule, BtlClient *client, BtlPokeCon *pokeCon, u32 arg3, HeapID heapId);
void func_ov167_021ce668(HeapID heapId);
void func_ov167_021ce870(BtlvCore *viewCore);
void *func_ov167_021d5e1c(HeapID heapId);
void func_ov167_021d5e68(void *data);

void func_ov167_021ce10c(void);
void func_ov167_021ce138(void);
void func_ov167_021ce8c8(BtlvCore *viewCore);
void func_ov167_021d4630(void *data, void *src, u32 size);
BOOL func_ov167_021d4880(void *data, u8 clientId);
void func_ov167_021d4a1c(u8 arg0);
void func_ov167_021d4a40(void);
u32 func_ov167_021d5a84(HeapID heapId);
void func_ov167_021d5aac(u32 arg0);

#endif // POKEBW2_BATTLE_BTLV_H
