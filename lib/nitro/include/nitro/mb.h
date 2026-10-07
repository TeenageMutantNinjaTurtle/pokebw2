#ifndef POKEBW2_NITRO_MB_H
#define POKEBW2_NITRO_MB_H

#include "types.h"

// NitroSDK's DS Download Play library (libmb), which overlay 181 links for the parent

#define MB_USER_NAME_LENGTH 10
#define MB_DOWNLOAD_PARAMETER_SIZE 32
// A tgid that MB_Init makes up from the clock
#define MB_TGID_AUTO 0x10000

// A player, as the parent and the children show each other
typedef struct {
    u8 favoriteColor : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[MB_USER_NAME_LENGTH];
} MBUserInfo;

// A game that the parent offers for download
typedef struct {
    const char *romFilePathp;
    u16 *gameNamep;
    u16 *gameIntroductionp;
    const char *iconCharPathp;
    const char *iconPalettePathp;
    u32 ggid;
    u8 maxPlayerNum;
    u8 pad[3];
    u8 userParam[MB_DOWNLOAD_PARAMETER_SIZE];
} MBGameRegistry;

#endif // POKEBW2_NITRO_MB_H
