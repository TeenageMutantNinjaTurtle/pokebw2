#ifndef POKEBW2_APP_T_DOWNLOAD_T_DOWNLOAD_SAVE_H
#define POKEBW2_APP_T_DOWNLOAD_T_DOWNLOAD_SAVE_H

#include "types.h"
#include "struct_decls.h"

// t_download_save.c: the tournaments kept in the save's extra blocks and those received, and saving one, named after
// the ROM's "t_download_save.c"

int func_ov326_021a24ac(TDownloadWork *wk);
void func_ov326_021a2580(TDownloadWork *wk);
int func_ov326_021a25a4(TDownloadWork *wk);
void func_ov326_021a2734(TDownloadWork *wk, int src, int dest);
BOOL func_ov326_021a27c0(TDownloadWork *wk);
void func_ov326_021a2828(TDownloadWork *wk);
void func_ov326_021a2850(TDownloadWork *wk);
void func_ov326_021a2864(TDownloadWork *wk);
int func_ov326_021a287c(TDownloadWork *wk);
BOOL func_ov326_021a2888(TDownloadWork *wk, int index);
int func_ov326_021a2a44(TDownloadWork *wk, int start);
int func_ov326_021a2a98(TDownloadWork *wk, BOOL down, int pos);

#endif // POKEBW2_APP_T_DOWNLOAD_T_DOWNLOAD_SAVE_H
