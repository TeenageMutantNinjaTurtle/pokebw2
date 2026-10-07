#ifndef POKEBW2_APP_PMSIV_MENU_H
#define POKEBW2_APP_PMSIV_MENU_H

#include "types.h"
#include "struct_decls.h"

// The phrase input's menu and buttons on the lower screen, of overlay 185's pmsiv_menu.c. The names are ours, guessed

PMSIVMenu *PMSIVMenu_Create(PMSInputView *vwk, const PMSInputWork *mwk, const PMSInputData *dwk);
void PMSIVMenu_Delete(PMSIVMenu *wk);
// Runs every frame
void PMSIVMenu_Main(PMSIVMenu *wk);
void func_ov185_021a0430(PMSIVMenu *wk);
void func_ov185_021a0538(PMSIVMenu *wk);
void func_ov185_021a0568(PMSIVMenu *wk);
void func_ov185_021a0588(PMSIVMenu *wk);
void func_ov185_021a0624(PMSIVMenu *wk);
void func_ov185_021a0660(PMSIVMenu *wk);
void func_ov185_021a07c4(PMSIVMenu *wk, u32 a1);
void func_ov185_021a07f8(PMSIVMenu *wk, u32 a1);
BOOL func_ov185_021a0818(PMSIVMenu *wk, u32 a1);
void func_ov185_021a0850(PMSIVMenu *wk, u32 a1);
void func_ov185_021a085c(PMSIVMenu *wk, u8 pos, BOOL a2);
void func_ov185_021a089c(PMSIVMenu *wk, u8 pos, BOOL a2);
BOOL func_ov185_021a08d0(PMSIVMenu *wk, u8 pos);
void func_ov185_021a08e0(PMSIVMenu *wk);
BOOL func_ov185_021a0908(PMSIVMenu *wk);

#endif // POKEBW2_APP_PMSIV_MENU_H
