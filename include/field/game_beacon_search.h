#ifndef POKEBW2_FIELD_GAME_BEACON_SEARCH_H
#define POKEBW2_FIELD_GAME_BEACON_SEARCH_H

#include "types.h"
#include "struct_decls.h"

// Names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

// Overlay 12's game_beacon_search.c, the communication GAME_COMM_NO_BEACON_SEARCH (and GAME_COMM_NO_UNK5): it sends
// the game's beacons and receives others'. The beacon broadcasts below lie between its code and symbol_map.c's, so
// they are assumed to be in it

// Its GameCommSys callbacks (see game_comm.c)
void *func_ov012_0215f55c(int *seq, void *param);
BOOL func_ov012_0215f5b4(int *seq, void *param, void *work);
BOOL func_ov012_0215f610(int *seq, void *param, void *work);
BOOL func_ov012_0215f628(int *seq, void *param, void *work);
void func_ov012_0215f654(int *seq, void *param, void *work);

void GameBeacon_BroadcastFerrisWheel(void);
// Sends a beacon of type 0x39, if GameBeaconSys_CanSendType allows it
void func_ov012_02160574(void);

#endif // POKEBW2_FIELD_GAME_BEACON_SEARCH_H
