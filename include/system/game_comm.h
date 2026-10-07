#ifndef POKEBW2_SYSTEM_GAME_COMM_H
#define POKEBW2_SYSTEM_GAME_COMM_H

#include "types.h"
#include "struct_decls.h"

void GameBeacon_SetZone(u16 zoneId, GameData *gameData);
void GameBeacon_BroadcastFerrisWheel(void);
u8 GameCommSys_BootCheck(GameCommSys *comm);
// The running communication's work
void *func_0202bdf4(GameCommSys *comm);
// The game data the communication was started with
GameData *getBasePlayerBlk(GameCommSys *comm);
void GameCommSys_ExitReq(GameCommSys *comm);
void func_0202be00(GameCommSys *comm);
BOOL func_0202be08(GameCommSys *comm);
BOOL func_0202be3c(GameCommSys *comm);
// Fills in, and reads, the game's part of a communication beacon
void func_0202c190(void *data);
void func_0202c1dc(void);
void func_0202c6c4(const void *data);
void func_0203021c(void);
// Sends a beacon of type 0x39, if func_0202cfe8 allows it
void func_ov012_02160574(void);

// Returns the game beacon system's flag at 0xc2f, and clears it. The Research Radar shows its new result icon when it
// was set
BOOL func_0202d080(void);
// Sets the medal count that the game's beacon sends
void func_0202d17c(u8 count);
// Sets the value of func_02008bf4 that the game's beacon sends
void func_0202d114(u32 value);
void func_0202d1ac(u16 species, BOOL a1, BOOL a2);
void func_0202d2c8(const StrBuf *name);
void func_0202bd08(GameCommSys *comm, Field *field);
void func_0202bd30(GameCommSys *comm, Field *field);
u8 func_0202bdfc(GameCommSys *comm);

#endif // POKEBW2_SYSTEM_GAME_COMM_H
