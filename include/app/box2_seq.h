#ifndef POKEBW2_APP_BOX2_SEQ_H
#define POKEBW2_APP_BOX2_SEQ_H

#include "types.h"
#include "struct_decls.h"

// The PC box's sequences, in box2_seq.c. Names are ours

enum {
    BOX2SEQ_INIT = 0,
    BOX2SEQ_START = 11,
    BOX2SEQ_END = 117,
};

// Runs the current sequence; FALSE once the box is done
BOOL Box2Seq_Main(Box2SysWork *syswk, u32 *seq);

#endif // POKEBW2_APP_BOX2_SEQ_H
