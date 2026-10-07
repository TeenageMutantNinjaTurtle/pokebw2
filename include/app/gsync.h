#ifndef POKEBW2_APP_GSYNC_H
#define POKEBW2_APP_GSYNC_H

#include "types.h"
#include "app/box2.h"
#include "app/wifi_login.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"

// Game Sync and the Dream World account, overlay 199. Game Sync's event (field/event_gsync.h) runs the menu,
// then Game Sync itself, and the start menu's Game Sync settings run the account screens
#define OVERLAY_GSYNC OVERLAY_ID(199)

// Results of the Game Sync procs
#define GSYNC_RESULT_NONE 0
#define GSYNC_RESULT_ACCOUNT 1
#define GSYNC_RESULT_CONNECT 2
#define GSYNC_RESULT_WIFI_SETTINGS 3
#define GSYNC_RESULT_NO_POKEMON 4
#define GSYNC_RESULT_SELECT_POKEMON 5
#define GSYNC_RESULT_RETRY_LOGIN 7

// Game Sync's event work, which its procs also take as their parameter
typedef struct {
    GameSystem *gsys;
    GameData *gameData;
    SaveControl *save;
    u8 unkC[0x44];
    u32 unk50;
    u8 loginBuffer[0x174];
    u32 gsyncResult;
    BOOL bgmPushed;
    u16 boxTray;
    u16 boxPosition;
    u32 bgm;
    u8 unk1D8[0x80];
    WifiLoginParam login;
    WifiLogoutParam logout;
    Box2Param box;
    // Whether the menu comes back from the Wi-Fi settings, which it fades in from white
    BOOL fromWifiSettings;
} EventGameSync;

// The Game Sync menu (gsync_menu.c): Game Sync, the Wi-Fi settings or back
extern const GameProcFunctions GSYNC_MENU_PROC_FUNCTIONS;
// The start menu's Game Sync settings, in the main program
extern const GameProcFunctions GAME_SYNC_SETTINGS_PROC_FUNCTIONS;
// Game Sync itself (gsync_state.c)
extern const GameProcFunctions GSYNC_PROC_FUNCTIONS;
// The Dream World account screens (pdwacc_state.c), which the Game Sync settings start
extern const GameProcFunctions PDWACC_PROC_FUNCTIONS;

#endif // POKEBW2_APP_GSYNC_H
