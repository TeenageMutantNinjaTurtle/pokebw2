#ifndef POKEBW2_FIELD_BADGE_GATE_H
#define POKEBW2_FIELD_BADGE_GATE_H

#include "types.h"
#include "nitro/fx.h"
#include "struct_decls.h"
#include "system/game_event.h"

// The badge gates on the way to Victory Road, in Victory Road's gimmick (overlay 103)

struct BadgeGateCheckEventData {
    void *gimmickWork;
    u16 badge;
    u16 padding;
    u32 state;
    u8 unk0c[0x10];
};

struct BadgeGateLastEventData {
    void *gimmickWork;
    FieldCamera *camera;
    u8 unk08[0x10];
    u32 state;
    u8 unk1c[4];
    VecFx32 eyeOffset;
    VecFx32 targetOffset;
    Field *field;
};

// Plays the gate of badge (0 to 7) checking its badge
GameEvent *BadgeGate_CreateCheckEvent(GameSystem *gsys, u8 badge);
GameEventReturnCode BadgeGate_CheckEvent(GameEvent *event, u32 *state, void *data);
void func_ov103_021ef010(Field *field);
// Plays the last gate, after the eight badge gates, with the camera
GameEvent *BadgeGate_CreateLastGateEvent(GameSystem *gsys);
GameEventReturnCode BadgeGate_LastGateEvent(GameEvent *event, u32 *state, void *data);

#endif // POKEBW2_FIELD_BADGE_GATE_H
