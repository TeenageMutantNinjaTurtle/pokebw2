#ifndef POKEBW2_FIELD_EVENT_WILD_BATTLE_H
#define POKEBW2_FIELD_EVENT_WILD_BATTLE_H

#include "types.h"
#include "struct_decls.h"

GameEvent *EventWildBattleCall_CreateRandom(EncountSystem *encountSystem, u32 mode);
GameEvent *func_ov011_021686b8(GameSystem *gsys, Field *field, BtlSetup *setup, u32 arg3, u32 arg4);

#endif // POKEBW2_FIELD_EVENT_WILD_BATTLE_H
