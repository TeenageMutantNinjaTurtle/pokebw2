#ifndef POKEBW2_FIELD_EVENT_IRC_H
#define POKEBW2_FIELD_EVENT_IRC_H

#include "types.h"
#include "struct_decls.h"

// Function names from swan.
void setPartyLv50(PokeParty *party);
void battleBoxToLv50Party(BOOL useBattleBox, IRCPartyWork *work);
void TrimPartyTo3Members(PokeParty *party);

#endif // POKEBW2_FIELD_EVENT_IRC_H
