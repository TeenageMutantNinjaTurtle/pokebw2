#ifndef POKEBW2_SAVE_BATTLE_REC_H
#define POKEBW2_SAVE_BATTLE_REC_H

#include "types.h"
#include "battle/btl_setup.h"
#include "gfl/heap.h"
#include "nitro/math.h"
#include "save/gds_profile.h"
#include "save/player_info.h"
#include "struct_decls.h"
#include "system/pms_data.h"

// battle_rec.c: the battle video that is loaded, which the battle recorder plays and the extra save data keeps

// A Pokémon as a recording keeps it: the fields of its blocks that the battle uses, unencrypted
typedef struct {
    u32 pid;
    u16 partyDecrypted : 1;
    u16 boxDecrypted : 1;
    u16 badEgg : 1;
    u16 nature : 8;
    u16 nPoke : 1;
    u16 species;
    u16 item;
    u32 id;
    u32 exp;
    u8 friendship;
    u8 ability;
    u8 hpEV;
    u8 atkEV;
    u8 defEV;
    u8 speEV;
    u8 spaEV;
    u8 spdEV;
    u16 moves[4];
    u8 pp[4];
    u8 ppUps[4];
    u32 hpIV : 5;
    u32 atkIV : 5;
    u32 defIV : 5;
    u32 speIV : 5;
    u32 spaIV : 5;
    u32 spdIV : 5;
    u32 isEgg : 1;
    u32 isNicknamed : 1;
    u8 fatefulEncounter : 1;
    u8 gender : 2;
    u8 form : 5;
    u16 nickname[11];
    u16 otName[8];
    u8 ball;
    u8 language;
    u32 statusCond;
    u8 level;
    u8 pokestarFame;
    u16 nowHP;
    u16 maxHP;
    u16 atk;
    u16 def;
    u16 spe;
    u16 spa;
    u16 spd;
} BattleRecPkm;

// A party as a recording keeps it
typedef struct {
    u16 capacity;
    u16 count;
    BattleRecPkm pkm[6];
} BattleRecParty;

// A BtlSetupTrainer as a recording keeps it, with the name as characters
typedef struct {
    u32 aiFlags;
    u16 trainerId;
    u16 trainerClass;
    u16 items[4];
    u16 name[16];
    PMSData unk30;
    PMSData unk38;
} BattleRecTrainer;

enum {
    BATTLE_REC_CLIENT_NONE,
    BATTLE_REC_CLIENT_PLAYER,
    BATTLE_REC_CLIENT_TRAINER,
};

// A client of the battle: a player, whose info the setup has, or a trainer, BATTLE_REC_CLIENT_*
typedef struct {
    u16 type;
    u16 unk2;
    union {
        PlayerInfo player;
        BattleRecTrainer trainer;
    } info;
} BattleRecClient;

// The setup's parameters, which both forms keep at their start
typedef struct {
    MATHRandContext32 rand;
    BtlFieldEnv env;
    u8 config[4];
    u16 bgm;
    u16 unk2E;
    u16 unk30;
    u8 battleType : 5;
    u8 unk32_5 : 3;
    u8 battleStyle : 4;
    u8 unk33_4 : 3;
    u8 unk33_7 : 1;
} BattleRecSetup;

// The body of a battle video, after its profile and header
typedef struct {
    BattleRecSetup setup;
    u32 dataSize;
    u8 data[0xc00];
    BattleRecParty parties[4];
    BattleRecClient clients[4];
} BattleRecBody;

// The battle video that is loaded, data_02140f64 (battle_rec.c).
typedef struct {
    u8 profile[0x80];
    u8 header[0x44];
    BattleRecBody body;
} BattleRecVideo;

extern BattleRecVideo *data_02140f64;

// Loads the saved video of a slot (0 is the player's own, 1 to 3 the downloaded ones). result is 1 if it loaded
void func_0200bc9c(SaveControl *save, HeapID heapId, u32 *result, u32 slot);
// The profile of the player who recorded the loaded video. The name is swan's
GdsProfile *getVSPlayerAllocation(void);
// The header of the loaded video
BattleRecHeader *func_0200c0c0(void);
// A value from the header, such as the video's number
u64 func_0200c124(BattleRecHeader *header, u32 id, u32 index);

#endif // POKEBW2_SAVE_BATTLE_REC_H
