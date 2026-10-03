#ifndef POKEBW2_FIELD_EVENT_GAME_CLEAR_H
#define POKEBW2_FIELD_EVENT_GAME_CLEAR_H

#include "types.h"
#include "struct_decls.h"
#include "system/game_event.h"

struct GameClearWork {
    GameSystem *gameSystem;
    GameData *gameData;
    u32 unk08;
    u8 unk0C[4];
    PlayerInfo *unk10;
    GameSystem *unk14;
    void *unk18;
    PokeParty *party;
    PlayerInfo *playerInfo;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    PlayerInfo *unk30;
    u32 unk34;
    u32 unk38;
    GameData *unk3C;
    u32 unk40;
    u32 current;
    u32 states[31];
    u32 unkC4;
};

GameEventReturnCode EventGameClear_Callback(GameEvent *event, u32 *state, void *data);
GameEvent *EventGameClear_Create(GameSystem *gsys, void *param);
void SetGameClearGameData(GameClearWork *work);
void func_ov012_0215a50c(GameClearWork *work);
void SetGameClearStatusSequence(GameClearWork *work);
void EventGameClear_GiveMonotypeMedals(GameClearWork *work);
u32 EventGameClear_Get3DDemoID(void);
void EventGameClear_NextState(GameClearWork *work, u32 *state);
void func_ov012_0215a670(GameClearWork *work);

#endif // POKEBW2_FIELD_EVENT_GAME_CLEAR_H
