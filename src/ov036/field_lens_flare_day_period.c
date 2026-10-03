#include "field/field_lens_flare.h"

u8 FieldLensFlare_GetSubIndexForDayPeriod(u32 period) {
    switch (period) {
    case 0:
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
    case 4:
        return 2;
    default:
        return 0;
    }
}
