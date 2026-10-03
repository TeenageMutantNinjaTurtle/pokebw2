#include "field/field_script_plugin.h"
#include "system/game_data.h"

const FieldScriptCommand *GetCurrentScrPluginTable(GameData *gameData) {
    u32 pluginNo = GetScrPluginNo(gameData);

    if (pluginNo == 0) {
        return NULL;
    }
    return SCRIPT_PLUGIN_TABLE[pluginNo].commands;
}

u32 GetCurrentScrPluginCmdCount(GameData *gameData) {
    u32 count;

    if (GetScrPluginNo(gameData) == 0 || GetCurrentScrPluginTable(gameData) == NULL) {
        return 0;
    }
    count = 0;
    while ((u32)GetCurrentScrPluginTable(gameData)[count] != (u32)-1) {
        count++;
    }
    return count;
}
