#ifndef POKEBW2_FIELD_EVENT_GAME_CLEAR_H
#define POKEBW2_FIELD_EVENT_GAME_CLEAR_H

#include "types.h"
#include "struct_decls.h"

struct GameClearWork {
    u32 unk00;
    GameData *gameData;
    u32 unk08;
    u8 unk0C[0x10];
    PokeParty *party;
    PlayerInfo *playerInfo;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    PlayerInfo *unk30;
    u32 unk34;
    u8 unk38[0x0C];
    void *current;
    void *states[1];
};

void SetGameClearGameData(GameClearWork *work);
void func_ov012_0215a50c(GameClearWork *work);
u32 EventGameClear_Get3DDemoID(void);
void EventGameClear_NextState(GameClearWork *work, u32 *state);
void func_ov012_0215a670(GameClearWork *work);

#endif // POKEBW2_FIELD_EVENT_GAME_CLEAR_H
