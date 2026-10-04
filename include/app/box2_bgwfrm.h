#ifndef POKEBW2_APP_BOX2_BGWFRM_H
#define POKEBW2_APP_BOX2_BGWFRM_H

#include "types.h"
#include "struct_decls.h"

// The PC box's sliding frames, over bgwinfrm.c. The ROM doesn't name this file; box2_bgwfrm.c is a guess. None of
// these functions has a name yet

BOOL func_ov255_021d387c(BGWinFrame *frames);
void func_ov255_021d3a38(BGWinFrame *frames);
void func_ov255_021d3b10(BGWinFrame *frames);

#endif // POKEBW2_APP_BOX2_BGWFRM_H
