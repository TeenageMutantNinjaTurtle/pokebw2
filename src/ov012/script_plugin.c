#include "types.h"
#include "field/field_script.h"
#include "field/field_script_plugin.h"
#include "gfl/overlay.h"
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
