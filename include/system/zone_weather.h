#ifndef POKEBW2_SYSTEM_ZONE_WEATHER_H
#define POKEBW2_SYSTEM_ZONE_WEATHER_H

#include "types.h"
#include "struct_decls.h"

// zone_weather.c: which weather a zone has. The ROM doesn't name the file; the name is a guess. Names from swan
// (https://github.com/ds-pokemon-hacking/swan, GPL-3.0), except WEATHER_NONE

// No weather chosen, so the next rule decides
#define WEATHER_NONE 0xffff

// A zone's weather: a forced one, the Entralink's by the connected game, the Route 7 event's, the player's birthday's
// on Routes 14 and 15, the date's if the season is the real one, else the zone's own
u8 GetWeatherAll(GameSystem *gsys, u32 zoneId);
// Sets the current weather to the zone's
void ResetWeather(GameSystem *gsys, u32 zoneId);
// Sets the current weather to a forced one, or back to the zone's own from weathers 6 and 7
void UpdateWeatherToDefault(GameData *gameData, u32 zoneId);

#endif // POKEBW2_SYSTEM_ZONE_WEATHER_H
