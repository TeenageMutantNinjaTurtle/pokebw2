#ifndef POKEBW2_FIELD_FIELDMAP_CTRL_HYBRID_H
#define POKEBW2_FIELD_FIELDMAP_CTRL_HYBRID_H

// The controller of maps with both grid and rail movement, overlay 36's fieldmap_ctrl_hybrid.c. Function names from
// swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0)

#include "types.h"
#include "struct_decls.h"

typedef struct {
    // The controller type in use, grid or rail
    u32 activeType;
    FieldPlayer *player;
    u32 unk08;
} FieldmapCtrlHybrid;

u32 FieldmapCtrlHybrid_GetActiveTypeID(FieldmapCtrlHybrid *controller);

#endif // POKEBW2_FIELD_FIELDMAP_CTRL_HYBRID_H
