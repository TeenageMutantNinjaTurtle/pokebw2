#ifndef POKEBW2_FIELD_BSUBWAY_SCR_H
#define POKEBW2_FIELD_BSUBWAY_SCR_H

#include "types.h"
#include "app/ov306.h"
#include "battle/btl_setup.h"
#include "gfl/heap.h"
#include "gfl/proc.h"
#include "save/player_info.h"
#include "struct_decls.h"

// The Battle Subway's work while the player is on the subway, which func_0201794c returns. Overlay 33's
// bsubway_scr.c and overlay 12 keep it, and script plugin 1 (overlay 50) drives it

// What overlay 50 fills in for overlay 174's screen
typedef struct {
    GameData *gameData;
    u8 unk4[0x18];
    // 0xb, 0xc or 0xd once the screen is done
    u32 result;
    u8 unk20[8];
} BSubwayOv174Param;

// Overlay 174's screen
extern const GameProcFunctions data_ov174_0219f0fc;

// Overlay 273
void func_ov273_021e9818(BtlSetup *setup);

// A Pokémon of a Battle Subway Trainer, which genSubwayBtlInstitutePoke makes a party Pokémon of. The fields are
// the PokeParty fields func_ov033_0217bf04 copies into it
struct BSubwayPokemon {
    u16 species : 11;
    u16 form : 5;
    u16 item;
    u16 moves[4];
    u32 id;
    u32 personality;
    u32 ivs;
    u8 evs[6];
    // Two bits per move
    u8 ppUps;
    u8 region;
    u8 ability;
    u8 happiness;
    u16 nickname[13];
};

struct BSubwayTeamConfig {
    u32 unk0;
    u16 unk4[2];
    u32 unk8[2];
    u8 unk10[2];
};

// A Trainer met in the Battle Subway or the Trial House
struct BSubwayTrainer {
    u8 unk00[4];
    u16 trainerId;
    u8 unk06[0x2a];
    BSubwayPokemon pokemon[4];
};

struct BSubwayScrWork {
    // 0x12345678
    u32 magic;
    u32 heapId;
    u8 memberCount;
    u8 playMode;
    u8 unkA[2];
    u16 unkC_0 : 1;
    u16 unkC_1 : 2;
    u16 unkC_3 : 2;
    u16 unkC_5 : 3;
    u16 unkC_8 : 1;
    u16 unkC_9 : 1;
    u16 unkC_10 : 2;
    u16 unkC_12 : 1;
    u16 unkC_13 : 3;
    u16 unkE;
    u16 unk10;
    u8 unk12[6];
    u16 unk18;
    u8 unk1A[4];
    // The party slots and species and items of the members entered
    u8 memberSlots[4];
    u16 memberSpecies[4];
    u16 memberItems[4];
    u16 unk32[0x1d];
    GameData *gameData;
    BSubwayPlayData *unk70;
    BSubwayScoreData *unk74;
    void *unk78;
    // Each member's chosen party slot plus 1
    u8 memberChoices[6];
    u16 unk82;
    u16 unk84;
    u8 unk86[2];
    BSubwayTrainer trainers[2];
    BSubwayTrainer unk2C8[3];
    BSubwayTeamConfig teamConfigs[3];
    u8 unk664[0x4a];
    u8 unk6AE[0x46];
    u8 unk6F4[0x28];
    void *unk71C;
    u16 *resultVar;
    u8 unk724;
    u8 unk725[2];
    u8 unk727;
    u8 unk728[2];
    u16 unk72A;
    PlayerInfo partner;
    u8 unk74C[0x58];
    BSubwayOv174Param ov174Param;
    void *allocatedBuffer;
    BtlSetup *btlSetup;
    Ov306Param ov306Param;
    u16 unk7EC;
    u16 unk7EE;
};

// Overlay 12
void func_ov012_021618ac(BSubwayScrWork *bsw);
void func_ov012_021618b8(u8 a0);
BOOL func_ov012_021618c8(u8 a0);
void func_ov012_02161844(BSubwayScrWork *bsw);
void func_ov012_02161894(BSubwayScrWork *bsw);
void func_ov012_02161990(BSubwayScrWork *bsw, u16 a1, u16 a2);
BOOL func_ov012_02161a48(BSubwayScrWork *bsw);
void func_ov012_02161a88(BSubwayScrWork *bsw, u8 a1);
BOOL func_ov012_02161a94(BSubwayScrWork *bsw, u16 *var);
// Makes a party of count Pokémon at the level
void func_ov012_021621d4(PokeParty *party, const BSubwayPokemon *pkms, u32 level, int count, HeapID heapId);
// Makes a Pokémon from the file of the Battle Subway's Pokémon arc
void func_ov012_02162490(BSubwayPokemon *pkm, u32 arcId, u16 file, u32 a3, u32 a4, u32 a5, u8 a6, u32 a7, HeapID heapId);
void *func_ov012_021628c0(BSubwayTrainer *trainer, u32 arcId, u32 trainerId, u32 msgFile, HeapID heapId);
GameEvent *func_ov012_02165f70(BSubwayScrWork *bsw, GameSystem *gsys, u8 a2);
GameEvent *func_ov012_02166070(BSubwayScrWork *bsw, GameSystem *gsys, Field *field);
GameEvent *func_ov012_02166118(BSubwayScrWork *bsw, GameSystem *gsys, u16 a2, u16 a3, u32 a4);
GameEvent *func_ov012_02166294(GameSystem *gsys);
GameEvent *func_ov012_0216657c(GameSystem *gsys, u16 a1, u16 a2);
void func_ov012_0216763c(FieldActor *actor, BOOL a1);

// Overlay 33's bsubway_scr.c
extern const u8 data_ov033_0217c564[12];

void func_ov033_0217b468(GameSystem *gsys);
BSubwayScrWork *func_ov033_0217b478(GameSystem *gsys, u16 a1, u16 a2);
void func_ov033_0217b664(GameSystem *gsys, BSubwayScrWork *bsw);
void func_ov033_0217b6b4(BSubwayScrWork *bsw);
void func_ov033_0217b708(BSubwayScrWork *bsw);
void func_ov033_0217b790(BSubwayScrWork *bsw, GameSystem *gsys);
void func_ov033_0217b7e8(BSubwayScrWork *bsw);
u16 func_ov033_0217b86c(GameSystem *gsys);
void func_ov033_0217b8ac(GameSystem *gsys, BSubwayScrWork *bsw);
u16 func_ov033_0217b8ec(BSubwayScrWork *bsw);
void func_ov033_0217b9dc(BSubwayScrWork *bsw);
u16 func_ov033_0217ba94(BSubwayScrWork *bsw, GameSystem *gsys);
BOOL func_ov033_0217bb20(BSubwayScrWork *bsw);
void func_ov033_0217bb4c(BSubwayScrWork *bsw, GameSystem *gsys);
void func_ov033_0217bb98(BSubwayScrWork *bsw, GameSystem *gsys);
void func_ov033_0217bbac(BSubwayScrWork *bsw);
u32 func_ov033_0217bca0(BSubwayScrWork *bsw, u16 a1);
u16 func_ov033_0217bcb4(BSubwayScoreData *score, GameSystem *gsys, u32 a2);
void func_ov033_0217bd34(BSubwayScrWork *bsw);
PokeParty *func_ov033_0217bd60(BSubwayScrWork *bsw);
BOOL func_ov033_0217bdf4(const u16 *list, u16 value, u16 count);
u16 func_ov033_0217be1c(s32 value);
u16 func_ov033_0217bd84(BSubwayScrWork *bsw);
void func_ov033_0217bd8c(BSubwayScrWork *bsw);
void func_ov033_0217bd88(BSubwayScrWork *bsw, u32 score);
void func_ov033_0217be2c(BSubwayScrWork *bsw, SaveControl *save, u32 a2, u32 a3);
void func_ov033_0217c010(BSubwayScrWork *bsw, SaveControl *save, u32 value);
void func_ov033_0217bda0(BSubwayScrWork *bsw);
void func_ov033_0217bda8(BSubwayScrWork *bsw, u32 count, u32 extra);
u16 func_ov033_0217bdc0(u16 mode);
void func_ov033_0217be88(BSubwayScrWork *bsw, u8 a1);
void func_ov033_0217b9dc(BSubwayScrWork *bsw);
void func_ov033_0217bf04(BSubwayPokemon *dest, PartyPkm *pkm);
void *func_ov033_0217c110(BSubwayScrWork *bsw);
BtlSetup *func_ov033_0217c094(BSubwayScrWork *bsw, GameSystem *gsys);
BOOL func_ov033_0217c264(BSubwayScrWork *bsw, BSubwayTrainer *trainer, u16 trainerId, u32 count, const u16 *species,
                        const u16 *items, const BSubwayTeamConfig *config, HeapID heapId);
u16 func_ov033_0217c11c(BSubwayScrWork *bsw, u16 level, u8 index, u32 mode, u8 side);
u16 func_ov033_0217c288(u32 value);
void func_ov033_0217c2c4(BSubwayScrWork *bsw, BSubwayTrainer *trainer, u16 trainerId, u32 count,
                        const BSubwayTeamConfig *config, HeapID heapId);
// Function name from swan
u16 randFFFFFFFFdivFFFF(BSubwayScrWork *bsw);

extern const char data_ov033_0217c640[];
extern const u8 data_ov033_0217c570[60];
extern const u8 data_ov033_0217c5ac[10];

// The range of trainer IDs a train's trainers come from, by level
typedef struct {
    u16 min;
    u16 max;
} BSubwayTrainerRange;

extern const BSubwayTrainerRange data_ov033_0217c5bc[2];
extern const BSubwayTrainerRange data_ov033_0217c5c4[3];
extern const BSubwayTrainerRange data_ov033_0217c5d0[4];
extern const BSubwayTrainerRange data_ov033_0217c5e0[4];

#endif // POKEBW2_FIELD_BSUBWAY_SCR_H
