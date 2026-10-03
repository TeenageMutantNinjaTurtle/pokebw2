#include "field/field_script_plugin.h"
#include "gfl/overlay.h"
#include "system/game_data.h"

void LoadScrPluginOverlays(GameData *gameData) {
    u32 pluginNo = GetScrPluginNo(gameData);

    if (pluginNo != 0) {
        if (SCRIPT_PLUGIN_TABLE[pluginNo].overlay0 != -1) {
            GFL_OvlLoad(SCRIPT_PLUGIN_TABLE[pluginNo].overlay0);
        }
        if (SCRIPT_PLUGIN_TABLE[pluginNo].overlay1 != -1) {
            GFL_OvlLoad(SCRIPT_PLUGIN_TABLE[pluginNo].overlay1);
        }
    }
}

void UnloadScrPluginOverlays(GameData *gameData) {
    u32 pluginNo = GetScrPluginNo(gameData);

    if (pluginNo != 0) {
        if (SCRIPT_PLUGIN_TABLE[pluginNo].overlay1 != -1) {
            GFL_OvlUnload(SCRIPT_PLUGIN_TABLE[pluginNo].overlay1);
        }
        if (SCRIPT_PLUGIN_TABLE[pluginNo].overlay0 != -1) {
            GFL_OvlUnload(SCRIPT_PLUGIN_TABLE[pluginNo].overlay0);
        }
        SetScrPluginNo(gameData, 0);
    }
}
