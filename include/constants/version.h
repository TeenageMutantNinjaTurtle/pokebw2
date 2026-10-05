#ifndef POKEBW2_CONSTANTS_VERSION_H
#define POKEBW2_CONSTANTS_VERSION_H

// The game versions, which getGameVersion returns
#define VERSION_WHITE 20
#define VERSION_BLACK 21
#define VERSION_WHITE2 22
#define VERSION_BLACK2 23

// This game's version
#ifdef BLACK2
#define GAME_VERSION VERSION_BLACK2
#else
#define GAME_VERSION VERSION_WHITE2
#endif

#endif // POKEBW2_CONSTANTS_VERSION_H
