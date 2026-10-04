#ifndef POKEBW2_FIELD_ZONE_CHANGE_H
#define POKEBW2_FIELD_ZONE_CHANGE_H

// Overlay 12's zone_change.c, what the game resets when the player enters a zone

#include "types.h"
#include "struct_decls.h"

void func_ov012_0215ee10(GameData *gameData, Field *field);
void func_ov012_0215ee40(GameData *gameData, u16 zoneId);
void func_ov012_0215ee94(GameData *gameData, u16 zoneId);
void func_ov012_0215eeb8(GameData *gameData, u16 zoneId);
void func_ov012_0215eedc(GameData *gameData, u16 zoneId);
void func_ov012_0215ef00(GameData *gameData, u16 zoneId);
void func_ov012_0215ef24(GameData *gameData, u16 zoneId);
void func_ov012_0215ef28(GameData *gameData, u16 zoneId);
// Resets the strength boulders of zone 0x1e5
void func_ov012_0215ef2c(MMSys *system);

#endif // POKEBW2_FIELD_ZONE_CHANGE_H
