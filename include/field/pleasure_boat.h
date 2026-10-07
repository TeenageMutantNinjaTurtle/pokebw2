#ifndef POKEBW2_FIELD_PLEASURE_BOAT_H
#define POKEBW2_FIELD_PLEASURE_BOAT_H

#include "types.h"
#include "struct_decls.h"

// The Royal Unova's cruise (pleasure_boat.c, in overlay 36): its clock, and the people and Trainers aboard

enum {
    PLEASURE_BOAT_INFO_STARBOARD_PEOPLE,
    PLEASURE_BOAT_INFO_PORT_PEOPLE,
    PLEASURE_BOAT_INFO_UNK_2,
    PLEASURE_BOAT_INFO_UNK_3,
    PLEASURE_BOAT_INFO_TRAINERS,
    PLEASURE_BOAT_INFO_TRAINERS_DEFEATED,
};

// A room of the ship
typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC[2];
    u32 unk14;
    u32 unk18;
} PleasureBoatRoom;

struct PleasureBoat {
    u32 unk0;
    // The clock, which counts periods of 1350
    s16 clock;
    // The last period reached
    s32 period;
    u32 unkC;
    PleasureBoatRoom rooms[];
};

// Sets up a cruise, with overlay 89
PleasureBoat *PleasureBoat_Create(BOOL a0);
// Frees the cruise and clears the pointer
void PleasureBoat_Free(PleasureBoat **boat);
// Returns PLEASURE_BOAT_INFO_*
u32 PleasureBoat_GetInfo(PleasureBoat *boat, u32 info);
// Moves the clock on by steps * 30. The clock counts periods of 1350, and the cruise plays SEQ_SE_FLD_78 as one ends.
// If this reaches the end of the period, the clock stops just short of it when stopBefore is set, so that the period
// ends on the next update, and otherwise starts the next period
void PleasureBoat_AdvanceClock(PleasureBoat *boat, u32 steps, BOOL stopBefore);
void PleasureBoat_SetTrainerDefeated(PleasureBoat *boat, u32 trainer, BOOL defeated);
void PleasureBoat_StopClock(PleasureBoat *boat);
void func_ov036_021c20e0(PleasureBoat *boat);
u32 func_ov036_021c2220(PleasureBoat *boat, u32 room);
u32 func_ov036_021c222c(PleasureBoat *boat, u32 room);
u32 func_ov036_021c2238(PleasureBoat *boat, u32 room, u32 index);
BOOL func_ov036_021c2248(PleasureBoat *boat, u32 room);

// Overlay 12's event_royal_unova.c
BOOL func_ov012_02160a90(VM *vm, FieldScriptEnv *env);
BOOL s01A2_CallRoyalUnovaView(VM *vm, FieldScriptEnv *env);

#endif // POKEBW2_FIELD_PLEASURE_BOAT_H
