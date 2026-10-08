#ifndef POKEBW2_APP_LIVEBATTLEMATCH_IRC_H
#define POKEBW2_APP_LIVEBATTLEMATCH_IRC_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// Overlay 261's livebattlematch_irc.c (named by its embedded string): the infrared link of the live competitions.
// Only the functions that overlay 263's party exchange calls are declared so far, and none has a name yet

typedef struct LiveBattleMatchIrc LiveBattleMatchIrc;

LiveBattleMatchIrc *func_ov261_0217a27c(GameData *gameData, HeapID heapId);
void func_ov261_0217a2c8(LiveBattleMatchIrc *irc);
// Called every frame; does nothing
void func_ov261_0217a2e4(LiveBattleMatchIrc *irc);
// Sends the team picked, and then is TRUE once it is sent
BOOL func_ov261_0217a4cc(LiveBattleMatchIrc *irc, PokeParty *party);
// Copies the other player's team into party, and then is TRUE, once it has arrived
BOOL func_ov261_0217a50c(LiveBattleMatchIrc *irc, PokeParty *party);

#endif // POKEBW2_APP_LIVEBATTLEMATCH_IRC_H
