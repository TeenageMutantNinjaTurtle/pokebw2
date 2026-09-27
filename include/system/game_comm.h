#ifndef POKEBW2_SYSTEM_GAME_COMM_H
#define POKEBW2_SYSTEM_GAME_COMM_H

#include "types.h"
#include "struct_decls.h"

void GameBeacon_SetZone(u16 zoneId, GameData *gameData);
u8 GameCommSys_BootCheck(GameCommSys *comm);
void GameCommSys_ExitReq(GameCommSys *comm);
void func_0202be00(GameCommSys *comm);
void func_0203021c(void);

#endif // POKEBW2_SYSTEM_GAME_COMM_H
