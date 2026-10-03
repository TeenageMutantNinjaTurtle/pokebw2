#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/arc.h"

BOOL func_ov104_021f0150(void *dest, u32 arcId, u32 fileId) {
    GFL_ArcSysReadRange(dest, arcId, fileId, 0, 0x7c);
    return TRUE;
}
