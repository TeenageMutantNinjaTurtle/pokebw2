#ifndef POKEBW2_FIELD_WBT_H
#define POKEBW2_FIELD_WBT_H

#include "types.h"
#include "battle/regulation.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "nitro/math.h"
#include "struct_decls.h"

// The Pokémon World Tournament: overlay 55's wbt_system.c, wbt_tool.c, wbt_setup.c and wbt_party.c, and the script
// plugins 6 (the entrance, with overlay 56) and 7 (the stadium, with overlay 57) that share overlay 55

// A Trainer of the tournaments, from arc 247
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8_0 : 3;
    u8 unk8_3 : 5;
    u8 unk9[7];
} WbtTrainer;

typedef struct {
    u32 count;
    WbtTrainer trainers[];
} WbtTrainers;

// One of the eight Trainers of a tournament
typedef struct {
    u8 unk0_0 : 3; // 3 for the player
    u8 unk0_3 : 1;
    u8 unk0_4 : 3; // The Trainer's rank, which decides a match between ranks that differ
    u8 unk0_7 : 1;
    u8 type;
    u8 unk2;
    u8 unk3_0 : 6;
    u8 unk3_6 : 2;
    u16 objCode;
    u16 unk6_0 : 12;
    u16 unk6_12 : 4;
    StrBuf *name;
    StrBuf *unkC;
} WbtEntrant;

// The result of a match of the bracket: whether the first Trainer won, and how
typedef struct {
    u8 firstWon;
    u8 score;
} WbtMatch;

typedef struct {
    u8 type;
    u8 unk1;
    u16 unk2;
} WbtUnk18A;

// A tournament downloaded to the save
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u8 unk6;
    u8 unk7;
    u8 unk8[0x52];
    u8 unk5A[0x4c];
    u8 unkA6;
    u8 unkA7;
    u8 unkA8;
    u8 unkA9;
    u16 unkAA;
} WbtDownloadedTournament;

struct WbtSystem {
    HeapID heapId;
    u8 unk2[2];
    BOOL unk4;
    WbtTrainers *trainers;
    u32 tournament;
    // The battle style, which starts out as 4, out of range
    u32 style;
    u32 unk14;
    u32 round;
    // The Type Expert Tournament's type
    u8 type;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u64 seed;
    MATHRandContext32 rand;
    WbtEntrant entrants[8];
    WbtMatch matches[7];
    Regulation regulation;
    WbtUnk18A unk18A;
    u8 unk18E[0x10];
    u16 downloadedName[0x25];
    u8 unk1E8[0x174];
    WbtDownloadedTournament downloaded;
    u8 unk408[0xfa0];
    u8 unk13A8;
    u8 unk13A9[3];
    void *unk13AC;
    u8 castSlots[6];
    u8 unk13B6[6];
    PokeParty *partyBC;
    PokeParty *partyC0;
    PokeParty *partyC4;
    u8 unk13C8[4];
    void *unk13CC;
    u8 unk13D0[0xc];
    // One for each round. Tournaments 1 and 10 award their total as Battle Points
    u8 unk13DC[3];
    u8 unk13DF;
    // The script variable that plugin 6 passes with func_ov022_0216e6e8's event
    u16 *unk13E0;
    u32 unk13E4;
};

// A tournament's type, from overlay 36's table of tournaments 1 to 15
typedef struct {
    u16 name;
    // Which of the save's 29 counts the tournament's wins go to. The Type Expert Tournament, tournament 2, counts
    // each of the 17 types in 0 to 16 instead
    u8 record;
    u8 unk3;
    u8 kind;
    u8 unk5;
    // The Battle Points for winning, by battle style
    u8 battlePoints[4];
} WbtTournamentInfo;

extern const WbtTournamentInfo data_ov036_021d4920[15];

const WbtTournamentInfo *func_ov036_021c98a4(u32 tournament);

// Overlay 36's table that func_ov036_02194650 indexes
typedef struct {
    u16 unk0_0 : 14;
    u16 unk0_14 : 2;
} Ov036Unk021cf1c8Entry;

typedef struct {
    const Ov036Unk021cf1c8Entry *const *unk0;
    u32 unk4;
} Ov036Unk021cf1c8;

extern const Ov036Unk021cf1c8 data_ov036_021cf1c8[];
void LoadPWTTournamentTypeText(HeapID heapId, u32 tournament, StrBuf *strbuf);

// The overworld setup of the tournament's Trainers, which overlay 22 shows
typedef struct {
    StrBuf *name;
    u16 unk4;
    u8 unk6;
    u8 unk7;
    u8 rank;
    u8 type;
    u8 isPlayer;
    u8 padB;
} WbtSetupEntrant;

typedef struct {
    u32 unk0;
    u8 unk4;
    u8 pad5[3];
} WbtSetupMatch;

typedef struct {
    GameSystem *gsys;
    u32 unk4;
    WbtSetupEntrant entrants[8];
    WbtSetupMatch firstRound[4];
    WbtSetupMatch secondRound[2];
    StrBuf *tournamentName;
    StrBuf *unk9C;
    u32 unkA0;
} WbtSetup;

// wbt_system.c
WbtSystem *WbtSystem_Create(HeapID heapId, BOOL a1);
void WbtSystem_Free(WbtSystem *sys);
void func_ov055_021e5ca0(WbtSystem *sys, u32 tournament);
u32 func_ov055_021e5ca4(WbtSystem *sys);
void func_ov055_021e5ca8(WbtSystem *sys, u32 style);
u32 func_ov055_021e5cac(WbtSystem *sys);
void func_ov055_021e5cb0(WbtSystem *sys, u8 type);
u8 func_ov055_021e5cb4(WbtSystem *sys);
void func_ov055_021e5cb8(WbtSystem *sys, u32 value);
u32 func_ov055_021e5cbc(WbtSystem *sys);
void func_ov055_021e5cc0(WbtSystem *sys, u32 round);
u32 func_ov055_021e5cc4(WbtSystem *sys);
u64 func_ov055_021e5cc8(WbtSystem *sys);
void func_ov055_021e5cd0(WbtSystem *sys, u8 value);
u8 func_ov055_021e5cd4(WbtSystem *sys);
void func_ov055_021e5cd8(WbtSystem *sys, u16 *var);
u16 *func_ov055_021e5ce4(WbtSystem *sys);
void func_ov055_021e5cf0(WbtSystem *sys, u8 value);
void func_ov055_021e5cfc(WbtSystem *sys, void *value);
void *func_ov055_021e5d08(WbtSystem *sys);
void func_ov055_021e5d14(WbtSystem *sys, u32 value);
WbtEntrant *func_ov055_021e5d20(WbtSystem *sys, u32 index);
WbtEntrant *func_ov055_021e5d28(WbtSystem *sys);
void func_ov055_021e5d44(WbtSystem *sys, u32 tournament, StrBuf *strbuf);
PokeParty *func_ov055_021e5d68(WbtSystem *sys);
PokeParty *func_ov055_021e5d74(WbtSystem *sys);
// The number of Pokémon each Trainer enters with, by the battle style
u32 func_ov055_021e5d7c(WbtSystem *sys);
u32 func_ov055_021e5e10(WbtEntrant *entrant);
u8 func_ov055_021e5e18(WbtEntrant *entrant);
u32 func_ov055_021e5e20(WbtEntrant *entrant);
u8 func_ov055_021e5e28(WbtEntrant *entrant);
u32 func_ov055_021e5e2c(WbtEntrant *entrant);
u32 func_ov055_021e5e34(WbtEntrant *entrant);
void func_ov055_021e5e3c(const WbtEntrant *entrant, StrBuf *dest);
u32 func_ov055_021e5e4c(WbtEntrant *entrant);
void func_ov055_021e5e54(WbtSystem *sys, GameData *gameData);
u8 func_ov055_021e5f38(WbtSystem *sys);
Regulation *func_ov055_021e5f78(WbtSystem *sys);
WbtUnk18A *func_ov055_021e6024(WbtSystem *sys);
u32 func_ov055_021e607c(WbtSystem *sys);
void func_ov055_021e62b0(WbtSystem *sys, MATHRandContext32 *rand);

// wbt_tool.c
// Load a Trainer's name and Trainer class from message files 409 and 410
void func_ov055_021e6388(HeapID heapId, u32 message, StrBuf *strbuf);
void func_ov055_021e63b4(HeapID heapId, u32 message, StrBuf *strbuf);
WbtTrainers *func_ov055_021e63e0(HeapID heapId);
void func_ov055_021e6438(WbtTrainers *trainers);
void func_ov055_021e6440(WbtTrainers *trainers, u32 index, WbtTrainer *dest);
BOOL func_ov055_021e6458(WbtTrainers *trainers, u8 index);
u16 func_ov055_021e6468(WbtTrainers *trainers, u8 index);
int func_ov055_021e6470(WbtTrainers *trainers, u8 index);
// The battle styles: single, double, triple and rotation
void func_ov055_021e6488(int style, StrBuf *strbuf);
u8 func_ov055_021e64c0(int style);
u32 func_ov055_021e64d4(int style);
int func_ov055_021e64e8(int style);
// The type that most of the party's Pokémon have, or a random one of those that tie
u8 func_ov055_021e64f0(PokeParty *party, u64 seed);
// Whether the tournament is open, by the wins that the save counts
BOOL func_ov055_021e66dc(GameData *gameData, u32 tournament);
// Whether winning the tournament would open another
BOOL func_ov055_021e66fc(GameData *gameData, u32 won, u32 tournament);
// The save's count of the tournament, where type is the Type Expert Tournament's
u32 func_ov055_021e6750(u32 tournament, u32 type);
// The tournament whose wins a count of the save counts
u32 func_ov055_021e6760(int record);
u32 func_ov055_021e6794(u32 tournament);
BOOL func_ov055_021e67a0(u32 tournament, u32 value);
u16 func_ov055_021e67b8(u32 tournament);
// The Battle Points for winning the tournament in the battle style
u8 func_ov055_021e67cc(u32 tournament, int style);
u8 func_ov055_021e67e4(u32 index);

// What wbt_setup.c fills in for overlay 326's screens
typedef struct {
    u32 unk0;
    u16 *unk4;
    void *save;
    PlayerInfo *playerInfo;
    // Whether the tournament of each of the save's counts is open
    u8 open[29];
} WbtOv326Param;

typedef struct {
    GameSystem *gsys;
    u32 unk4;
    u32 unk8;
    u16 *unkC;
    u16 *unk10;
} WbtOv326Param2;

// wbt_setup.c
WbtSetup *func_ov055_021e67f4(HeapID heapId, GameSystem *gsys);
void func_ov055_021e6870(WbtSetup *setup);
void func_ov055_021e68a8(GameSystem *gsys, WbtSystem *sys, WbtSetup *setup);
WbtOv326Param *func_ov055_021e6a64(HeapID heapId, GameSystem *gsys, u16 *var);
void func_ov055_021e6ac0(WbtOv326Param *param);
WbtOv326Param2 *func_ov055_021e6ac8(HeapID heapId, GameSystem *gsys, u32 a2, u16 *var1, u16 *var2);
void func_ov055_021e6afc(WbtOv326Param2 *param);

// wbt_party.c
// What a party picked from the Battle Subway's Pokémon may not repeat: the species, unless unk0 is set, the held
// items and the Pokémon files, each a list of 12
typedef struct {
    u32 unk0;
    u16 speciesCount;
    u16 itemCount;
    u16 fileCount;
    u16 *species;
    u16 *items;
    // 0xffff for none
    u16 *files;
} WbtPartyFilter;

WbtPartyFilter *func_ov055_021e6b58(HeapID heapId, u32 tournament);
void func_ov055_021e6bdc(WbtPartyFilter *filter);
void func_ov055_021e6bfc(WbtPartyFilter *filter, u16 item);
void func_ov055_021e6c20(WbtPartyFilter *filter, u16 species);
void func_ov055_021e6c44(WbtPartyFilter *filter, u16 file);
// Picks count of the files at random, as the filter allows, and adds them to the filter
void func_ov055_021e6f34(u16 *dest, WbtPartyFilter *filter, HeapID heapId, u16 fileCount, const u16 *files,
                         u32 arcId, u8 count, MATHRandContext32 *rand);
void func_ov055_021e713c(WbtSystem *sys, u32 a1, PlayerInfo *playerInfo, u16 placeName);
void func_ov055_021e71ec(WbtSystem *sys);

#endif // POKEBW2_FIELD_WBT_H
