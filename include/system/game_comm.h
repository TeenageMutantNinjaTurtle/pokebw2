#ifndef POKEBW2_SYSTEM_GAME_COMM_H
#define POKEBW2_SYSTEM_GAME_COMM_H

#include "types.h"
#include "struct_decls.h"

void GameBeacon_SetZone(u16 zoneId, GameData *gameData);
void GameBeacon_BroadcastFerrisWheel(void);
u8 GameCommSys_BootCheck(GameCommSys *comm);
// The running communication's work
void *func_0202bdf4(GameCommSys *comm);
void GameCommSys_ExitReq(GameCommSys *comm);
void func_0202be00(GameCommSys *comm);
void func_0203021c(void);
// Sends a beacon of type 0x39, if func_0202cfe8 allows it
void func_ov012_02160574(void);

// Sets the medal count that the game's beacon sends
void func_0202d17c(u8 count);
void func_0202d1ac(u16 species, BOOL a1, BOOL a2);
void func_0202d2c8(const StrBuf *name);
void func_0202bd08(GameCommSys *comm, Field *field);
void func_0202bd30(GameCommSys *comm, Field *field);
u8 func_0202bdfc(GameCommSys *comm);

#endif // POKEBW2_SYSTEM_GAME_COMM_H
