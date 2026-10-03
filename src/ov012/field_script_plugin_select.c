#include "field/field_script_plugin.h"
#include "system/game_data.h"

void SetScrPluginByZone(GameData *gameData, u16 zoneId) {
    u32 i;
    u32 j;

    for (i = 0; i < 17; i++) {
        if (i != 0) {
            for (j = 0; j < SCRIPT_PLUGIN_TABLE[i].zoneCount; j++) {
                if (zoneId == SCRIPT_PLUGIN_TABLE[i].zones[j]) {
                    SetScrPluginNo(gameData, i);
                    return;
                }
            }
        }
    }
}
