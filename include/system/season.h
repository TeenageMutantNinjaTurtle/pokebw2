#ifndef POKEBW2_SYSTEM_SEASON_H
#define POKEBW2_SYSTEM_SEASON_H

#include "types.h"
#include "struct_decls.h"

#define SEASON_SPRING 0
#define SEASON_SUMMER 1
#define SEASON_AUTUMN 2
#define SEASON_WINTER 3

u8 Season_GetNext(u8 season);
u8 Season_GetPrevious(u8 season);
u32 Season_GetRealTime(void);
void Season_Set(GameData *gameData, u16 season);

#endif // POKEBW2_SYSTEM_SEASON_H
