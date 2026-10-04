#ifndef POKEBW2_FIELD_GAME_BEACON_SET_H
#define POKEBW2_FIELD_GAME_BEACON_SET_H

// Overlay 12's game_beacon_set.c (a descriptive name): the field's messages to nearby players, which it puts in the
// beacon that ARM9 main's g_GameBeaconSys broadcasts. Each message has a public function, which checks that the
// message may be sent, and a function that fills the beacon in

#include "types.h"
#include "struct_decls.h"

// The info of the beacon the game broadcasts, of ARM9 main
typedef struct {
    u8 unk0[3];
    u8 passPower : 7;
    u8 unk3_7 : 1;
    u8 unk4[0x2c];
    // What the message is
    u16 type;
    u16 value;
    union {
        u16 value16;
        u32 value32;
        u8 value8;
        struct {
            u8 a;
            u8 b;
        } pair;
        struct {
            u16 value;
            u8 extra;
        } withExtra;
        u16 name[9];
        struct {
            u16 name[9];
            u16 value;
        } named;
        struct {
            u16 name[9];
            u8 value;
        } namedByte;
    } data;
} GameBeaconInfo;

typedef struct {
    u32 unk0;
    u32 unk4;
    GameBeaconInfo info;
} GameBeaconSys;

extern GameBeaconSys *g_GameBeaconSys;

// ARM9 main's beacon functions, which belong with g_GameBeaconSys
// Whether the player is busy with something else, such as a Pokémon Musical
BOOL func_0202d014(void);
// Whether a message of the type may be sent
BOOL func_0202cfe8(u16 type);
// Whether a message of the type, about value, is a record to send instead
BOOL func_0202cfac(u32 type, u16 value);
void func_0202ce84(GameBeaconInfo *info);
void func_0202ce90(GameBeaconInfo *info);
void func_0202ce9c(GameBeaconInfo *info, u16 type, u32 value);
void func_0202cea8(GameBeaconInfo *info, u16 type, const StrBuf *name, u32 value);
void func_0202d074(const StrBuf *name, u16 *dest);
// Send the message, each in its own way
void func_0202d4c8(GameBeaconInfo *info);
void func_0202d4e0(GameBeaconInfo *info);
void func_0202d4fc(GameBeaconInfo *info);
void func_0202d518(GameBeaconInfo *info);
void func_0202d534(GameBeaconInfo *info);
void func_0202d550(GameBeaconInfo *info);
BOOL func_02026ccc(u16 value);

void func_ov012_0215f958(u16 value);
void func_ov012_0215f994(u16 value);
void func_ov012_0215fa90(u16 itemId);
void func_ov012_0215faf0(u16 itemId);
void func_ov012_0215fb50(u16 itemId);
void func_ov012_0215fbb0(u16 itemId);
void func_ov012_0215fc10(u16 itemId);
void func_ov012_0215fc70(u16 itemId);
void func_ov012_0215fcd0(u32 passPower);
void func_ov012_0215fd50(u16 value);
void func_ov012_0215fdbc(void);
void func_ov012_0215fdec(u32 value);
void func_ov012_0215fe3c(void);
void func_ov012_0215fe6c(u16 value);
void func_ov012_0215febc(u16 value, const StrBuf *name);
void func_ov012_0215ff20(u16 value, const StrBuf *name);
void func_ov012_0215ff84(u16 value, const StrBuf *name);
void func_ov012_0215ffe8(const StrBuf *name);
void func_ov012_0216002c(u16 value);
void func_ov012_02160080(void);
void func_ov012_021600d0(u16 species);
void func_ov012_02160124(void);
void func_ov012_02160174(void);
void func_ov012_021601a4(u32 value);
void func_ov012_021601dc(void);
void func_ov012_02160210(void);
void func_ov012_02160240(u8 value);
void func_ov012_021602cc(void);
// That the player is in a musical with the Pokémon of that name
void func_ov012_021602fc(const StrBuf *name);
void func_ov012_02160340(u32 passPower);
void func_ov012_02160390(GameData *gameData, u16 value);
void func_ov012_0216045c(u8 value);
void func_ov012_02160488(u8 value);
void func_ov012_021604c4(u8 value);
void func_ov012_021604f4(u8 value, u8 kind);
void func_ov012_0216052c(u8 value, u8 extra);
void func_ov012_021605a4(u8 extra, u16 value);
void func_ov012_021605d4(u8 extra, u16 value);
void func_ov012_02160618(void);
void func_ov012_0216063c(u8 type, u16 value);

#endif // POKEBW2_FIELD_GAME_BEACON_SET_H
