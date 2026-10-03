#ifndef POKEBW2_FIELD_EVENT_BATTLE_LOSE_H
#define POKEBW2_FIELD_EVENT_BATTLE_LOSE_H

#include "types.h"
#include "struct_decls.h"
#include "system/game_event.h"

struct BattleLoseData {
    GameSystem *gsys;
    BOOL returnNonLeague;
    PlayerInfo *playerInfo;
};

GameEvent *EventBattleLose_Create(GameSystem *gsys);
GameEventReturnCode EventBattleLose_Callback(GameEvent *event, u32 *state, void *data);

#endif // POKEBW2_FIELD_EVENT_BATTLE_LOSE_H
