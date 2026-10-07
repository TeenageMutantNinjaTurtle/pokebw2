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
u16 PMSInput_GetSentenceType(const PMSInputWork *wk);
// The word at a place of the sentence, or the word being written
u16 PMSInput_GetEditWord(const PMSInputWork *wk, u32 index);
// The sentence's text, with its words as commands
StrBuf *PMSInput_GetEditSourceString(const PMSInputWork *wk, HeapID heapId);
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
// The search's letters and results, through pmsi_search.c
void PMSInput_GetSearchInputStr(const PMSInputWork *wk, StrBuf *buf);
void PMSInput_ResetSearch(const PMSInputWork *wk);
u32 PMSInput_GetSearchResultCount(const PMSInputWork *wk);
u32 PMSInput_GetSearchInputLen(const PMSInputWork *wk);
void PMSInput_GetSearchResultStr(const PMSInputWork *wk, u32 index, StrBuf *buf);

#endif // POKEBW2_APP_PMS_INPUT_H
