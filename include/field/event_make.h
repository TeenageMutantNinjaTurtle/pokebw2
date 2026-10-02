#ifndef POKEBW2_FIELD_EVENT_MAKE_H
#define POKEBW2_FIELD_EVENT_MAKE_H

// eventMakeFunc name from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0).

#include "types.h"
#include "struct_decls.h"

struct EventMakeArgs {
    u32 first;
    u32 second;
    u32 third;
};

GameEvent *func_ov010_02150310(GameSystem *gsys, u32 first, u32 second, u32 third);
GameEvent *eventMakeFunc(GameSystem *gsys, const EventMakeArgs *args);

#endif // POKEBW2_FIELD_EVENT_MAKE_H
