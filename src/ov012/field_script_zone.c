#include "field/field_script_supervisor.h"
#include "field/player_state.h"
#include "system/game_system.h"

u16 FieldScript_GetZoneIDFromGSys(GameSystem *gsys) {
    return PlayerState_GetZoneID(GSYS_GetPlayerState(gsys));
}
