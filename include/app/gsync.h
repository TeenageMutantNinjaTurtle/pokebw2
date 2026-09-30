#ifndef POKEBW2_APP_GSYNC_H
#define POKEBW2_APP_GSYNC_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"

// Game Sync and the Dream World account, which take the event's work as their parameter
#define OVERLAY_GSYNC OVERLAY_ID(199)

// Results of the Game Sync procs
#define GSYNC_RESULT_ACCOUNT 1
#define GSYNC_RESULT_CONNECT 2
#define GSYNC_RESULT_WIFI_SETTINGS 3
#define GSYNC_RESULT_NO_POKEMON 4
#define GSYNC_RESULT_SELECT_POKEMON 5
#define GSYNC_RESULT_RETRY_LOGIN 7

extern const GameProcFunctions GSYNC_PROC_FUNCTIONS;
// The start menu's Game Sync settings, in the main program
extern const GameProcFunctions GAME_SYNC_SETTINGS_PROC_FUNCTIONS;
extern const GameProcFunctions PDWACC_PROC_FUNCTIONS;

#endif // POKEBW2_APP_GSYNC_H
