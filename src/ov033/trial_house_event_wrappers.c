#include "field/trial_house.h"

u32 func_ov033_0217aed0(TrialHouseWork *work) {
    return func_ov012_02162b38(*(u16 *)((u8 *)work + 4));
}

GameEvent *func_ov033_0217aedc(GameSystem *gsys, TrialHouseWork *work, u32 actorId, u32 messageId) {
    return func_ov012_02161e6c(gsys, work, actorId, (u16)messageId);
}
