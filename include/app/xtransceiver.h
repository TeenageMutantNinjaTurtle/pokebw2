#ifndef POKEBW2_APP_XTRANSCEIVER_H
#define POKEBW2_APP_XTRANSCEIVER_H

#include "types.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"

// Overlay 259: the Xtransceiver, the video calls. None of its functions has a name yet

#define OVERLAY_XTRANSCEIVER OVERLAY_ID(259)

extern const GameProcFunctions XTRANSCEIVER_PROC_FUNCTIONS;

#endif // POKEBW2_APP_XTRANSCEIVER_H
