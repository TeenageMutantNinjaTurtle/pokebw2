#ifndef POKEBW2_FIELD_EVENT_BATTLE_H
#define POKEBW2_FIELD_EVENT_BATTLE_H

// Overlay 12's event_battle.c: the events that run battles from the field. Function names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

GameEvent *CreateTrialHouseBattleEvent(GameSystem *gsys, Field *field, BtlSetup *setup);
GameEvent *func_ov012_0216881c(GameSystem *gsys, Field *field, BtlSetup *setup);

#endif // POKEBW2_FIELD_EVENT_BATTLE_H
