#include "types.h"
#include "field/fieldmap_ctrl_hybrid.h"

u32 FieldmapCtrlHybrid_GetActiveTypeID(FieldmapCtrlHybrid *controller) {
    return controller->activeType;
}
