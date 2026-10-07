#ifndef POKEBW2_APP_PMS_INPUT_H
#define POKEBW2_APP_PMS_INPUT_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/str.h"
#include "struct_decls.h"

// The phrase input, overlay 185's pms_input.c: the work that the view and the screens' parts read. The names are
// ours, guessed

// Where the input is, keys or touch
int *PMSInput_GetKeyModePtr(const PMSInputWork *wk);
u32 PMSInput_GetInputMode(const PMSInputWork *wk);
// Whether the categories are listed by initial instead of by group
u32 PMSInput_GetCategoryMode(const PMSInputWork *wk);
u32 PMSInput_GetEditAreaCursorPos(const PMSInputWork *wk);
u32 PMSInput_GetButtonCursorPos(const PMSInputWork *wk);
u32 PMSInput_GetCategoryCursorPos(const PMSInputWork *wk);
u32 func_ov185_021a300c(const PMSInputWork *wk);
u32 PMSInput_GetWordWinCursorPos(const PMSInputWork *wk);
int PMSInput_GetWordWinScrollVector(const PMSInputWork *wk);
BOOL PMSInput_GetWordWinUpArrowVisible(const PMSInputWork *wk);
BOOL PMSInput_GetWordWinDownArrowVisible(const PMSInputWork *wk);
BOOL PMSInput_HasStartSentence(const PMSInputWork *wk);
TCBManager *PMSInput_GetTCBManager(const PMSInputWork *wk);
void func_ov185_021a30c0(const PMSInputWork *wk);
BOOL func_ov185_021a30dc(const PMSInputWork *wk);

#endif // POKEBW2_APP_PMS_INPUT_H
