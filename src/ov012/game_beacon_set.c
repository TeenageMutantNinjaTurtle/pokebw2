#include "types.h"
#include "app/name_entry.h"
#include "field/game_beacon_set.h"
#include "gfl/str.h"
#include "save/high_link.h"
#include "save/save_control.h"
#include "system/game_comm.h"
#include "system/game_data.h"
#include "system/str_tool.h"

static void func_ov012_0215f9b0(u16 value);
static void func_ov012_0215f9d8(GameBeaconInfo *info, u16 value);
static void func_ov012_0215f9e8(u16 value);
static void func_ov012_0215fa10(GameBeaconInfo *info, u16 value);
static void func_ov012_0215fa20(u16 value);
static void func_ov012_0215fa48(GameBeaconInfo *info, u16 value);
static void func_ov012_0215fa58(u16 value);
static void func_ov012_0215fa80(GameBeaconInfo *info, u16 value);
static void func_ov012_0215fae0(GameBeaconInfo *info, u16 itemId);
static void func_ov012_0215fb40(GameBeaconInfo *info, u16 itemId);
static void func_ov012_0215fba0(GameBeaconInfo *info, u16 itemId);
static void func_ov012_0215fc00(GameBeaconInfo *info, u16 itemId);
static void func_ov012_0215fc60(GameBeaconInfo *info, u16 itemId);
static void func_ov012_0215fcc0(GameBeaconInfo *info, u16 itemId);
static void func_ov012_0215fd30(GameBeaconInfo *info, u32 passPower);
static void func_ov012_0215fdac(GameBeaconInfo *info, u16 value);
static void func_ov012_0215fde0(GameBeaconInfo *info);
static void func_ov012_0215fe2c(GameBeaconInfo *info, u32 value);
static void func_ov012_0215fe60(GameBeaconInfo *info);
static void func_ov012_0215feb0(GameBeaconInfo *info);
static void func_ov012_0215ff04(GameBeaconInfo *info, const StrBuf *name);
static void func_ov012_0215ff68(GameBeaconInfo *info, const StrBuf *name);
static void func_ov012_0215ffcc(GameBeaconInfo *info, const StrBuf *name);
static void func_ov012_02160010(GameBeaconInfo *info, const StrBuf *name);
static void func_ov012_02160070(GameBeaconInfo *info, u16 value);
static void func_ov012_021600c4(GameBeaconInfo *info);
static void func_ov012_02160114(GameBeaconInfo *info, u16 species);
static void func_ov012_02160168(GameBeaconInfo *info);
static void func_ov012_02160198(GameBeaconInfo *info);
static void func_ov012_021601cc(GameBeaconInfo *info, u32 value);
static void func_ov012_02160200(GameBeaconInfo *info);
static void func_ov012_02160234(GameBeaconInfo *info);
static void func_ov012_02160268(GameBeaconInfo *info, u8 value);
static void func_ov012_021602c0(GameBeaconInfo *info);
static void func_ov012_021602f0(GameBeaconInfo *info);
static void func_ov012_02160324(GameBeaconInfo *info, const StrBuf *name);
static void func_ov012_02160380(GameBeaconInfo *info, u32 passPower);
static void func_ov012_021603bc(GameBeaconInfo *info, GameData *gameData, u16 value);
static void func_ov012_02160438(GameBeaconInfo *info, const StrBuf *name, u8 value);
static void func_ov012_021604b4(GameBeaconInfo *info, u8 value, u16 type);
static void func_ov012_0216055c(GameBeaconInfo *info, u8 value, u8 extra, u32 type);
static void func_ov012_02160598(GameBeaconInfo *info);
static void func_ov012_02160604(GameBeaconInfo *info, u8 extra, u16 value, u16 type);

static const u8 data_ov012_0216d718[5] = {10, 30, 50, 100, 200};

void func_ov012_0215f958(u16 value) {
    if (func_0202d014()) {
        func_ov012_0215fa20(value);
    } else if (func_0202cfac(4, value)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x3e, value);
    } else {
        func_ov012_0215f9b0(value);
    }
}

void func_ov012_0215f994(u16 value) {
    if (func_0202d014()) {
        func_ov012_0215fa58(value);
    } else {
        func_ov012_0215f9e8(value);
    }
}

static void func_ov012_0215f9b0(u16 value) {
    if (func_0202cfe8(2)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215f9d8(&g_GameBeaconSys->info, value);
    }
}

static void func_ov012_0215f9d8(GameBeaconInfo *info, u16 value) {
    info->type = 2;
    info->value = value;
    func_0202d4c8(info);
}

static void func_ov012_0215f9e8(u16 value) {
    if (func_0202cfe8(3)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215fa10(&g_GameBeaconSys->info, value);
    }
}

static void func_ov012_0215fa10(GameBeaconInfo *info, u16 value) {
    info->type = 3;
    info->value = value;
    func_0202d550(info);
}

static void func_ov012_0215fa20(u16 value) {
    if (func_0202cfe8(4)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215fa48(&g_GameBeaconSys->info, value);
    }
}

static void func_ov012_0215fa48(GameBeaconInfo *info, u16 value) {
    info->type = 4;
    info->value = value;
    func_0202d4e0(info);
}

static void func_ov012_0215fa58(u16 value) {
    if (func_0202cfe8(5)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215fa80(&g_GameBeaconSys->info, value);
    }
}

static void func_ov012_0215fa80(GameBeaconInfo *info, u16 value) {
    info->type = 5;
    info->value = value;
    func_0202d550(info);
}

void func_ov012_0215fa90(u16 itemId) {
    if (itemId < 0x32e) {
        if (func_0202cfac(8, itemId)) {
            func_0202ce9c(&g_GameBeaconSys->info, 0x42, itemId);
        } else if (func_0202cfe8(6)) {
            func_0202ce90(&g_GameBeaconSys->info);
            func_ov012_0215fae0(&g_GameBeaconSys->info, itemId);
        }
    }
}

static void func_ov012_0215fae0(GameBeaconInfo *info, u16 itemId) {
    info->type = 6;
    info->data.value16 = itemId;
    func_0202d4fc(info);
}

void func_ov012_0215faf0(u16 itemId) {
    if (itemId < 0x32e) {
        if (func_0202cfac(9, itemId)) {
            func_0202ce9c(&g_GameBeaconSys->info, 0x43, itemId);
        } else if (func_0202cfe8(7)) {
            func_0202ce90(&g_GameBeaconSys->info);
            func_ov012_0215fb40(&g_GameBeaconSys->info, itemId);
        }
    }
}

static void func_ov012_0215fb40(GameBeaconInfo *info, u16 itemId) {
    info->type = 7;
    info->data.value16 = itemId;
    func_0202d550(info);
}

void func_ov012_0215fb50(u16 itemId) {
    if (itemId < 0x32e) {
        if (func_0202cfac(8, itemId)) {
            func_0202ce9c(&g_GameBeaconSys->info, 0x42, itemId);
        } else if (func_0202cfe8(8)) {
            func_0202ce90(&g_GameBeaconSys->info);
            func_ov012_0215fba0(&g_GameBeaconSys->info, itemId);
        }
    }
}

static void func_ov012_0215fba0(GameBeaconInfo *info, u16 itemId) {
    info->type = 8;
    info->data.value16 = itemId;
    func_0202d518(info);
}

void func_ov012_0215fbb0(u16 itemId) {
    if (itemId < 0x32e) {
        if (func_0202cfac(9, itemId)) {
            func_0202ce9c(&g_GameBeaconSys->info, 0x43, itemId);
        } else if (func_0202cfe8(9)) {
            func_0202ce90(&g_GameBeaconSys->info);
            func_ov012_0215fc00(&g_GameBeaconSys->info, itemId);
        }
    }
}

static void func_ov012_0215fc00(GameBeaconInfo *info, u16 itemId) {
    info->type = 9;
    info->data.value16 = itemId;
    func_0202d550(info);
}

void func_ov012_0215fc10(u16 itemId) {
    if (itemId < 0x32e) {
        if (func_0202cfac(8, itemId)) {
            func_0202ce9c(&g_GameBeaconSys->info, 0x42, itemId);
        } else if (func_0202cfe8(10)) {
            func_0202ce90(&g_GameBeaconSys->info);
            func_ov012_0215fc60(&g_GameBeaconSys->info, itemId);
        }
    }
}

static void func_ov012_0215fc60(GameBeaconInfo *info, u16 itemId) {
    info->type = 10;
    info->data.value16 = itemId;
    func_0202d534(info);
}

void func_ov012_0215fc70(u16 itemId) {
    if (itemId < 0x32e) {
        if (func_0202cfac(9, itemId)) {
            func_0202ce9c(&g_GameBeaconSys->info, 0x43, itemId);
        } else if (func_0202cfe8(11)) {
            func_0202ce90(&g_GameBeaconSys->info);
            func_ov012_0215fcc0(&g_GameBeaconSys->info, itemId);
        }
    }
}

static void func_ov012_0215fcc0(GameBeaconInfo *info, u16 itemId) {
    info->type = 11;
    info->data.value16 = itemId;
    func_0202d550(info);
}

void func_ov012_0215fcd0(u32 passPower) {
    if (func_0202cfac(15, passPower)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x49, passPower);
    } else if (func_0202cfe8(0x12)) {
        if (PassPower_IsBW1Compatible(passPower)) {
            func_0202ce84(&g_GameBeaconSys->info);
        } else {
            func_0202ce90(&g_GameBeaconSys->info);
        }
        func_ov012_0215fd30(&g_GameBeaconSys->info, passPower);
    }
}

static void func_ov012_0215fd30(GameBeaconInfo *info, u32 passPower) {
    info->type = 0x12;
    info->passPower = passPower;
    func_0202d550(info);
}

void func_ov012_0215fd50(u16 value) {
    if (func_0202cfac(12, value)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x46, value);
    } else if (func_0202cfe8(0x13)) {
        if (func_02026ccc(value)) {
            func_0202ce90(&g_GameBeaconSys->info);
        } else {
            func_0202ce84(&g_GameBeaconSys->info);
        }
        func_ov012_0215fdac(&g_GameBeaconSys->info, value);
    }
}

static void func_ov012_0215fdac(GameBeaconInfo *info, u16 value) {
    info->type = 0x13;
    info->data.value16 = value;
    func_0202d550(info);
}

void func_ov012_0215fdbc(void) {
    if (func_0202cfe8(0x15)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215fde0(&g_GameBeaconSys->info);
    }
}

static void func_ov012_0215fde0(GameBeaconInfo *info) {
    info->type = 0x15;
    func_0202d550(info);
}

void func_ov012_0215fdec(u32 value) {
    u32 i;

    if (func_0202cfe8(0x16)) {
        for (i = 0; i < NELEMS(data_ov012_0216d718); i++) {
            if (value == data_ov012_0216d718[i]) {
                func_0202ce84(&g_GameBeaconSys->info);
                func_ov012_0215fe2c(&g_GameBeaconSys->info, value);
                return;
            }
        }
    }
}

static void func_ov012_0215fe2c(GameBeaconInfo *info, u32 value) {
    info->type = 0x16;
    info->data.value32 = value;
    func_0202d550(info);
}

void func_ov012_0215fe3c(void) {
    if (func_0202cfe8(0x17)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215fe60(&g_GameBeaconSys->info);
    }
}

static void func_ov012_0215fe60(GameBeaconInfo *info) {
    info->type = 0x17;
    func_0202d550(info);
}

void func_ov012_0215fe6c(u16 value) {
    if (func_0202cfac(7, value)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x41, value);
    } else if (func_0202cfe8(0x1e)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215feb0(&g_GameBeaconSys->info);
    }
}

static void func_ov012_0215feb0(GameBeaconInfo *info) {
    info->type = 0x1e;
    func_0202d550(info);
}

void func_ov012_0215febc(u16 value, const StrBuf *name) {
    if (func_0202cfac(0x2b, value)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x65, value);
    } else if (func_0202cfe8(0x1f)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215ff04(&g_GameBeaconSys->info, name);
    }
}

static void func_ov012_0215ff04(GameBeaconInfo *info, const StrBuf *name) {
    info->type = 0x1f;
    func_0202d074(name, info->data.name);
    func_0202d550(info);
}

void func_ov012_0215ff20(u16 value, const StrBuf *name) {
    if (func_0202cfac(0x2c, value)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x66, value);
    } else if (func_0202cfe8(0x20)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215ff68(&g_GameBeaconSys->info, name);
    }
}

static void func_ov012_0215ff68(GameBeaconInfo *info, const StrBuf *name) {
    info->type = 0x20;
    func_0202d074(name, info->data.name);
    func_0202d550(info);
}

void func_ov012_0215ff84(u16 value, const StrBuf *name) {
    if (func_0202cfac(0x2a, value)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x64, value);
    } else if (func_0202cfe8(0x21)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_0215ffcc(&g_GameBeaconSys->info, name);
    }
}

static void func_ov012_0215ffcc(GameBeaconInfo *info, const StrBuf *name) {
    info->type = 0x21;
    func_0202d074(name, info->data.name);
    func_0202d550(info);
}

void func_ov012_0215ffe8(const StrBuf *name) {
    if (func_0202cfe8(0x22)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160010(&g_GameBeaconSys->info, name);
    }
}

static void func_ov012_02160010(GameBeaconInfo *info, const StrBuf *name) {
    info->type = 0x22;
    func_0202d074(name, info->data.name);
    func_0202d550(info);
}

void func_ov012_0216002c(u16 value) {
    if (func_0202cfac(13, value)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x47, value);
    } else if (func_0202cfe8(0x24)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160070(&g_GameBeaconSys->info, value);
    }
}

static void func_ov012_02160070(GameBeaconInfo *info, u16 value) {
    info->type = 0x24;
    info->data.value16 = value;
    func_0202d550(info);
}

void func_ov012_02160080(void) {
    if (func_0202cfac(0x12, 0)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x4c, 0);
    } else if (func_0202cfe8(0x25)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_021600c4(&g_GameBeaconSys->info);
    }
}

static void func_ov012_021600c4(GameBeaconInfo *info) {
    info->type = 0x25;
    func_0202d550(info);
}

void func_ov012_021600d0(u16 species) {
    if (func_0202cfac(0x1b, species)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x55, species);
    } else if (func_0202cfe8(0x26)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160114(&g_GameBeaconSys->info, species);
    }
}

static void func_ov012_02160114(GameBeaconInfo *info, u16 species) {
    info->type = 0x26;
    info->value = species;
    func_0202d550(info);
}

void func_ov012_02160124(void) {
    if (func_0202cfac(14, 0)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x48, 0);
    } else if (func_0202cfe8(0x27)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160168(&g_GameBeaconSys->info);
    }
}

static void func_ov012_02160168(GameBeaconInfo *info) {
    info->type = 0x27;
    func_0202d550(info);
}

void func_ov012_02160174(void) {
    if (func_0202cfe8(0x28)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160198(&g_GameBeaconSys->info);
    }
}

static void func_ov012_02160198(GameBeaconInfo *info) {
    info->type = 0x28;
    func_0202d550(info);
}

void func_ov012_021601a4(u32 value) {
    if (func_0202cfe8(0x29)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_021601cc(&g_GameBeaconSys->info, value);
    }
}

static void func_ov012_021601cc(GameBeaconInfo *info, u32 value) {
    info->type = 0x29;
    info->data.value32 = value;
    func_0202d550(info);
}

void func_ov012_021601dc(void) {
    if (func_0202cfe8(0x2a)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160200(&g_GameBeaconSys->info);
    }
}

static void func_ov012_02160200(GameBeaconInfo *info) {
    info->type = 0x2a;
    info->data.value32 = 0;
    func_0202d550(info);
}

void func_ov012_02160210(void) {
    if (func_0202cfe8(0x2b)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160234(&g_GameBeaconSys->info);
    }
}

static void func_ov012_02160234(GameBeaconInfo *info) {
    info->type = 0x2b;
    func_0202d550(info);
}

void func_ov012_02160240(u8 value) {
    if (func_0202cfe8(0x2c)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160268(&g_GameBeaconSys->info, value);
    }
}

static void func_ov012_02160268(GameBeaconInfo *info, u8 value) {
    info->type = 0x2c;
    info->data.value8 = value;
    func_0202d550(info);
}

void GameBeacon_BroadcastFerrisWheel(void) {
    if (func_0202cfac(16, 0)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x4a, 0);
    } else if (func_0202cfe8(0x2d)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_021602c0(&g_GameBeaconSys->info);
    }
}

static void func_ov012_021602c0(GameBeaconInfo *info) {
    info->type = 0x2d;
    func_0202d550(info);
}

void func_ov012_021602cc(void) {
    if (func_0202cfe8(0x2e)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_021602f0(&g_GameBeaconSys->info);
    }
}

static void func_ov012_021602f0(GameBeaconInfo *info) {
    info->type = 0x2e;
    func_0202d550(info);
}

void func_ov012_021602fc(const StrBuf *name) {
    if (func_0202cfe8(0x2f)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160324(&g_GameBeaconSys->info, name);
    }
}

static void func_ov012_02160324(GameBeaconInfo *info, const StrBuf *name) {
    info->type = 0x2f;
    func_0202d074(name, info->data.name);
    func_0202d550(info);
}

void func_ov012_02160340(u32 passPower) {
    if (func_0202cfe8(0x30)) {
        if (PassPower_IsBW1Compatible(passPower)) {
            func_0202ce84(&g_GameBeaconSys->info);
        } else {
            func_0202ce90(&g_GameBeaconSys->info);
        }
        func_ov012_02160380(&g_GameBeaconSys->info, passPower);
    }
}

static void func_ov012_02160380(GameBeaconInfo *info, u32 passPower) {
    info->type = 0x30;
    info->data.value16 = passPower;
    func_0202d550(info);
}

void func_ov012_02160390(GameData *gameData, u16 value) {
    if (func_0202cfe8(0x18)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_021603bc(&g_GameBeaconSys->info, gameData, value);
    }
}

static void func_ov012_021603bc(GameBeaconInfo *info, GameData *gameData, u16 value) {
    wcharsncpy(func_0200c954(getTrainerGameInfoAddress(GameData_GetSaveControl(gameData))), info->data.named.name, 9);
    info->type = 0x18;
    info->data.named.value = value;
    func_0202d550(info);
}

void func_ov012_021603ec(StrBuf *name, u8 value) {
    if (func_0202cfac(0x2d, 0)) {
        func_0202cea8(&g_GameBeaconSys->info, 0x67, name, value);
    } else if (func_0202cfe8(0x31)) {
        func_0202ce84(&g_GameBeaconSys->info);
        func_ov012_02160438(&g_GameBeaconSys->info, name, value);
    }
}

static void func_ov012_02160438(GameBeaconInfo *info, const StrBuf *name, u8 value) {
    GFL_StrBufStoreString(name, info->data.namedByte.name, 9);
    info->data.namedByte.value = value;
    info->type = 0x31;
    func_0202d550(info);
}

void func_ov012_0216045c(u8 value) {
    if (func_0202cfe8(0x33)) {
        func_0202ce90(&g_GameBeaconSys->info);
        func_ov012_021604b4(&g_GameBeaconSys->info, value, 0x33);
    }
}

void func_ov012_02160488(u8 value) {
    if (func_0202cfe8(0x34)) {
        func_0202ce90(&g_GameBeaconSys->info);
        func_ov012_021604b4(&g_GameBeaconSys->info, value, 0x34);
    }
}

static void func_ov012_021604b4(GameBeaconInfo *info, u8 value, u16 type) {
    info->type = type;
    info->data.value8 = value;
    func_0202d550(info);
}

void func_ov012_021604c4(u8 value) {
    if (func_0202cfe8(0x35)) {
        func_0202ce90(&g_GameBeaconSys->info);
        func_ov012_0216055c(&g_GameBeaconSys->info, value, 0, 0x35);
    }
}

void func_ov012_021604f4(u8 value, u8 kind) {
    u32 type = 0x38;

    if (kind != 3) {
        type = 0x36;
    }
    if (func_0202cfe8(type)) {
        func_0202ce90(&g_GameBeaconSys->info);
        func_ov012_0216055c(&g_GameBeaconSys->info, value, kind, type);
    }
}

void func_ov012_0216052c(u8 value, u8 extra) {
    if (func_0202cfe8(0x37)) {
        func_0202ce90(&g_GameBeaconSys->info);
        func_ov012_0216055c(&g_GameBeaconSys->info, value, extra, 0x37);
    }
}

static void func_ov012_0216055c(GameBeaconInfo *info, u8 value, u8 extra, u32 type) {
    info->type = type;
    info->data.pair.a = value;
    info->data.pair.b = extra;
    func_0202d550(info);
}

void func_ov012_02160574(void) {
    if (func_0202cfe8(0x39)) {
        func_0202ce90(&g_GameBeaconSys->info);
        func_ov012_02160598(&g_GameBeaconSys->info);
    }
}

static void func_ov012_02160598(GameBeaconInfo *info) {
    info->type = 0x39;
    func_0202d550(info);
}

void func_ov012_021605a4(u8 extra, u16 value) {
    if (func_0202cfe8(0x3a)) {
        func_0202ce90(&g_GameBeaconSys->info);
        func_ov012_02160604(&g_GameBeaconSys->info, extra, value, 0x3a);
    }
}

void func_ov012_021605d4(u8 extra, u16 value) {
    if (func_0202cfe8(0x3b)) {
        func_0202ce90(&g_GameBeaconSys->info);
        func_ov012_02160604(&g_GameBeaconSys->info, extra, value, 0x3b);
    }
}

static void func_ov012_02160604(GameBeaconInfo *info, u8 extra, u16 value, u16 type) {
    info->type = type;
    info->data.withExtra.value = value;
    info->data.withExtra.extra = extra;
    func_0202d550(info);
}

void func_ov012_02160618(void) {
    if (func_0202cfac(10, 0)) {
        func_0202ce9c(&g_GameBeaconSys->info, 0x44, 0);
    }
}

void func_ov012_0216063c(u8 type, u16 value) {
    if (type >= 4 && func_0202cfac(type, value)) {
        func_0202ce9c(&g_GameBeaconSys->info, type + 0x3a, value);
    }
}
