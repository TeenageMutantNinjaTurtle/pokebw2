#ifndef POKEBW2_APP_GAME_START_H
#define POKEBW2_APP_GAME_START_H

#include "types.h"
#include "gfl/proc.h"

// Starting the game from the start menu and the screens around it (ov162): a new game, which runs the intro and the
// name entries, or a continue, which loads the save. Both continues start the game system with bit 10 of the config
// set or cleared

void GameStart_NewGame(void);
void GameStart_ContinueFlagOff(void);
void GameStart_ContinueFlagOn(void);

extern const GameProcFunctions NEW_GAME_PROC_FUNCTIONS;
extern const GameProcFunctions CONTINUE_PROC_FUNCTIONS;
extern const GameProcFunctions DEBUG_GAME_START_PROC_FUNCTIONS;

#endif // POKEBW2_APP_GAME_START_H
