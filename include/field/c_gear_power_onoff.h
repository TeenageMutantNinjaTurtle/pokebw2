#ifndef POKEBW2_FIELD_C_GEAR_POWER_ONOFF_H
#define POKEBW2_FIELD_C_GEAR_POWER_ONOFF_H

#include "types.h"
#include "gfl/heap.h"
#include "struct_decls.h"

// The touch screen that asks whether to turn the C-Gear on or off, or says that wireless communication is disabled,
// overlay 88, named after the ROM's "c_gear_power_onoff.c". Overlay 36's field subscreen table calls these. The names
// are ours

typedef struct CGearPowerOnOff CGearPowerOnOff;

CGearPowerOnOff *CGearPowerOnOff_Create(FieldSubscreen *subscreen, GameSystem *gsys, HeapID heapId);
void CGearPowerOnOff_Free(CGearPowerOnOff *work);
// active is unused
void CGearPowerOnOff_Update(CGearPowerOnOff *work, BOOL active);

#endif // POKEBW2_FIELD_C_GEAR_POWER_ONOFF_H
