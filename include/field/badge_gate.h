#ifndef POKEBW2_FIELD_BADGE_GATE_H
#define POKEBW2_FIELD_BADGE_GATE_H

#include "types.h"
#include "struct_decls.h"
#include "system/game_event.h"

// The badge gates on the way to Victory Road, in Victory Road's gimmick (overlay 103)

// Victory Road's gimmick callbacks
void func_ov103_021eec80(Field *field);
void func_ov103_021eefe0(Field *field);
void func_ov103_021ef010(Field *field);
// Plays the gate of badge (0 to 7) checking its badge
GameEvent *BadgeGate_CreateCheckEvent(GameSystem *gsys, u8 badge);
// Plays the last gate, after the eight badge gates, with the camera
GameEvent *BadgeGate_CreateLastGateEvent(GameSystem *gsys);

#endif // POKEBW2_FIELD_BADGE_GATE_H
