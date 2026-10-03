#include "field/hidden_hollow.h"
#include "field/zone.h"

u32 func_ov036_021c898c(HiddenHollowWork *work, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6) {
    if (IsZoneJoinAvenue((u16)work->unk04)) {
        return func_ov036_021c89cc(work, a1, a2, a3, a4, a5, a6);
    }
    return a4;
}
