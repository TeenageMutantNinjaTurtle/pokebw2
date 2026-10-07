#ifndef POKEBW2_APP_BOX2_SEQ_H
#define POKEBW2_APP_BOX2_SEQ_H

#include "types.h"
#include "app/box2_main.h"
#include "struct_decls.h"

// The PC box's sequences, in box2_seq.c. Names are ours

enum {
    BOX2SEQ_INIT = 0,
    BOX2SEQ_RELEASE,
    BOX2SEQ_WIPE,
    BOX2SEQ_PALETTE_FADE,
    BOX2SEQ_WAIT,
    BOX2SEQ_VFUNC,
    BOX2SEQ_TRGWAIT,
    BOX2SEQ_YESNO,
    BOX2SEQ_BUTTON_ANM,
    BOX2SEQ_SUBPROC_CALL,
    BOX2SEQ_SUBPROC_MAIN,
    BOX2SEQ_START,
    BOX2SEQ_START_WAIT,
    BOX2SEQ_END = 117,
};

// Runs the current sequence; FALSE once the box is done
BOOL Box2Seq_Main(Box2SysWork *syswk, u32 *seq);
int func_ov255_021cbe68(Box2SysWork *syswk, int nextSeq);
int func_ov255_021cbec8(Box2SysWork *syswk, Box2VFunc func, int nextSeq);
void func_ov255_021cdb90(Box2SysWork *syswk);
void func_ov255_021cdc74(Box2SysWork *syswk, s16 item);

#endif // POKEBW2_APP_BOX2_SEQ_H
