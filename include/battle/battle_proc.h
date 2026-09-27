#ifndef POKEBW2_BATTLE_BATTLE_PROC_H
#define POKEBW2_BATTLE_BATTLE_PROC_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Overlay 10 starts a battle, overlay 167 is the battle system and overlay 213 selects the party for a Wi-Fi battle
#define OVERLAY_BATTLE OVERLAY_ID(10)
#define OVERLAY_BATTLE_MAIN OVERLAY_ID(167)
#define OVERLAY_BATTLE_SELECT OVERLAY_ID(213)

typedef struct {
    PokeParty *party;
    PlayerInfo *info;
    u32 unk8;
    u32 unkC;
} BattlePlayer;

typedef struct {
    GameData *gameData;
    BtlSetup *setup;
    BattlePlayer *players;
    u32 rule;
    u32 unk10;
    u32 unk14;
} BattleParam;

typedef struct {
    Regulation *regulation;
    PokeParty *party;
    u16 *otherName;
    u8 otherGender;
    PokeParty *otherParty;
    GameData *gameData;
    u8 unk18;
    PokeParty *unk1C;
    PokeParty *party0;
    PokeParty *party1;
    u32 result;
} BattleSelectParam;

extern const GameProcFunctions data_ov010_0215039c;
extern const GameProcFunctions data_ov213_021bbb38;
// The battle's comm commands
extern const u8 data_ov167_021d7448[];

#endif // POKEBW2_BATTLE_BATTLE_PROC_H
