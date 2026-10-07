#ifndef POKEBW2_APP_PMSIV_EDIT_H
#define POKEBW2_APP_PMSIV_EDIT_H

#include "types.h"
#include "gfl/arc.h"
#include "gfl/touchpanel.h"
#include "struct_decls.h"

// The phrase input's edit area, the sentence being written on the upper part of the lower screen, of overlay 185's
// pmsiv_edit.c. The names are ours, guessed

PMSIVEdit *PMSIVEdit_Create(PMSInputView *vwk, const PMSInputWork *mwk, const PMSInputData *dwk);
void PMSIVEdit_Delete(PMSIVEdit *wk);
void PMSIVEdit_SetupGraphicDatas(PMSIVEdit *wk, ArcTool *arc);
void func_ov185_0219f7d4(PMSIVEdit *wk, BOOL a1);
BOOL func_ov185_0219f834(PMSIVEdit *wk);
void func_ov185_0219fb1c(PMSIVEdit *wk);
// The touch rectangle of a word of the sentence
void func_ov185_0219fc00(PMSIVEdit *wk, TouchRect *rect, u32 index);
u32 func_ov185_0219ffbc(PMSIVEdit *wk);
u16 func_ov185_0219ffc0(PMSIVEdit *wk, u32 index);
void func_ov185_0219ffcc(PMSIVEdit *wk);
void func_ov185_0219ffd8(PMSIVEdit *wk);
void func_ov185_0219ffe4(PMSIVEdit *wk, BOOL a1);
void func_ov185_021a0004(PMSIVEdit *wk);
void func_ov185_021a0008(PMSIVEdit *wk);
void PMSIVEdit_MoveCursor(PMSIVEdit *wk, u32 pos);

#endif // POKEBW2_APP_PMSIV_EDIT_H
