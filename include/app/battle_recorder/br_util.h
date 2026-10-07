#ifndef POKEBW2_APP_BATTLE_RECORDER_BR_UTIL_H
#define POKEBW2_APP_BATTLE_RECORDER_BR_UTIL_H

#include "types.h"
#include "app/battle_recorder/br_res.h"
#include "gfl/heap.h"
#include "struct_decls.h"
#include "system/printsys.h"

// The Battle Recorder's utilities (br_util.c): sequences, message windows, lists and the ball effect

// A position on the touch screen
typedef struct {
    s32 x;
    s32 y;
} BrPoint;

// A step of a sequence, which runs every frame until it sets the next one
typedef void (*BrSeqFunc)(BrSeq *p_seqwk, u32 *p_seq, void *p_wk_adrs);

BrSeq *func_ov271_021f44ec(void *p_wk_adrs, BrSeqFunc seq_function, HeapID heapId);
void func_ov271_021f4528(BrSeq *p_wk);
void func_ov271_021f4530(BrSeq *p_wk);
void func_ov271_021f4550(BrSeq *p_wk, BrSeqFunc seq_function);

// The message window of the main screen's info text
BrMsgWin *func_ov271_021f3f40(BrRes *res, PrintQueue *que, HeapID heapId);
void func_ov271_021f3f70(BrMsgWin *p_wk, BrRes *res);
void func_ov271_021f3f84(BrMsgWin *p_wk, BrRes *res, u32 msgID);
void func_ov271_021f3fd0(BrMsgWin *p_wk);

void func_ov271_021f4678(BrBallEffect *p_wk, u32 type, const BrPoint *cp_pos);

#endif // POKEBW2_APP_BATTLE_RECORDER_BR_UTIL_H
