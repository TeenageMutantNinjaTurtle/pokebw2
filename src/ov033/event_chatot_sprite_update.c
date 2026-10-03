#include "field/event_chatot.h"

u32 func_ov033_021790c4(ChatotEventWork *work) {
    ClActorPos position;

    if (work->animFrame == 0) {
        work->animOffset = -4;
    }
    if (work->animOffset == -4) {
        work->animOffset = 3;
        work->animFrame++;
        if (work->animFrame == 3) {
            return 0;
        }
    }
    func_0204c178(work->sprite, &position, 0);
    position.y -= work->animOffset;
    func_0204c140(work->sprite, &position, 0);
    work->animOffset--;
    return 1;
}
