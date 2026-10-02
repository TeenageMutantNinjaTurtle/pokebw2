#include "types.h"
#include "field/event_make.h"

GameEvent *eventMakeFunc(GameSystem *gsys, const EventMakeArgs *args) {
    return func_ov010_02150310(gsys, args->first, args->second, args->third);
}
