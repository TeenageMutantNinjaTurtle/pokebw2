#ifndef POKEBW2_APP_PMSIV_WORDWIN_H
#define POKEBW2_APP_PMSIV_WORDWIN_H

#include "types.h"
#include "gfl/clact.h"
#include "struct_decls.h"

// The phrase input's word window, the list of a category's words, of overlay 185's pmsiv_wordwin.c. The names are
// ours, guessed

PMSIVWordWin *PMSIVWordWin_Create(PMSInputView *vwk, const PMSInputWork *mwk, const PMSInputData *dwk);
void PMSIVWordWin_Delete(PMSIVWordWin *wk);
void PMSIVWordWin_SetupGraphicDatas(PMSIVWordWin *wk);
void func_ov185_021a32d0(PMSIVWordWin *wk);
void func_ov185_021a3320(PMSIVWordWin *wk, BOOL a1);
void func_ov185_021a3380(PMSIVWordWin *wk);
BOOL func_ov185_021a3438(PMSIVWordWin *wk);
void func_ov185_021a345c(PMSIVWordWin *wk);
BOOL func_ov185_021a3480(PMSIVWordWin *wk);
void func_ov185_021a3500(PMSIVWordWin *wk, BOOL a1);
void PMSIVWordWin_MoveCursor(PMSIVWordWin *wk, u32 pos);
void func_ov185_021a3584(PMSIVWordWin *wk, int vector);
BOOL func_ov185_021a3640(PMSIVWordWin *wk);
BOOL func_ov185_021a3674(PMSIVWordWin *wk, ClActorPos *pos);
void func_ov185_021a3690(PMSIVWordWin *wk, BOOL up, BOOL down);
void func_ov185_021a3704(PMSIVWordWin *wk, s16 y);
u32 func_ov185_021a3740(PMSIVWordWin *wk, u32 count);
void func_ov185_021a398c(PMSIVWordWin *wk, u32 pos);
BOOL func_ov185_021a39dc(PMSIVWordWin *wk);

#endif // POKEBW2_APP_PMSIV_WORDWIN_H
