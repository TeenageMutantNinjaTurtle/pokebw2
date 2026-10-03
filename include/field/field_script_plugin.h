#ifndef POKEBW2_FIELD_FIELD_SCRIPT_PLUGIN_H
#define POKEBW2_FIELD_FIELD_SCRIPT_PLUGIN_H

#include "types.h"
#include "field/field_script.h"
#include "struct_decls.h"

struct ScriptPluginEntry {
    const FieldScriptCommand *commands;
    const u16 *zones;
    u32 zoneCount;
    s32 overlay0;
    s32 overlay1;
};

extern const ScriptPluginEntry SCRIPT_PLUGIN_TABLE[];

void SetScrPluginByZone(GameData *gameData, u16 zoneId);
void LoadScrPluginOverlays(GameData *gameData);
void UnloadScrPluginOverlays(GameData *gameData);
const FieldScriptCommand *GetCurrentScrPluginTable(GameData *gameData);
u32 GetCurrentScrPluginCmdCount(GameData *gameData);

#endif // POKEBW2_FIELD_FIELD_SCRIPT_PLUGIN_H
