#ifndef POKEBW2_APP_PMSIV_CATEGORY_H
#define POKEBW2_APP_PMSIV_CATEGORY_H

#include "types.h"
#include "gfl/arc.h"
#include "struct_decls.h"

// The phrase input's categories, the buttons of the word groups or of the initials, of overlay 185's
// pmsiv_category.c. The names are ours, guessed

PMSIVCategory *PMSIVCategory_Create(PMSInputView *vwk, const PMSInputWork *mwk, const PMSInputData *dwk);
void PMSIVCategory_Delete(PMSIVCategory *wk);
void PMSIVCategory_SetupGraphicDatas(PMSIVCategory *wk, ArcTool *arc);
void PMSIVCategory_VisibleCursor(PMSIVCategory *wk, BOOL visible);
void PMSIVCategory_MoveCursor(PMSIVCategory *wk, u32 pos);
void func_ov185_0219f04c(PMSIVCategory *wk);
BOOL func_ov185_0219f064(PMSIVCategory *wk);
void func_ov185_0219f080(PMSIVCategory *wk);
BOOL func_ov185_0219f098(PMSIVCategory *wk);
void func_ov185_0219f0e4(PMSIVCategory *wk);
void func_ov185_0219f0f4(PMSIVCategory *wk);
BOOL func_ov185_0219f10c(PMSIVCategory *wk);
void func_ov185_0219f118(PMSIVCategory *wk);
BOOL func_ov185_0219f134(PMSIVCategory *wk);
void func_ov185_0219f150(PMSIVCategory *wk);
BOOL func_ov185_0219f18c(PMSIVCategory *wk);
void func_ov185_0219f198(PMSIVCategory *wk);
void func_ov185_0219f1b8(PMSIVCategory *wk);
BOOL func_ov185_0219f234(PMSIVCategory *wk);
void func_ov185_0219f238(PMSIVCategory *wk);
void func_ov185_0219f2a0(PMSIVCategory *wk, BOOL a1);
BOOL func_ov185_0219f3ec(PMSIVCategory *wk, BOOL a1);
void func_ov185_0219f464(PMSIVCategory *wk, u32 pos);
BOOL func_ov185_0219f4f0(PMSIVCategory *wk);

#endif // POKEBW2_APP_PMSIV_CATEGORY_H
