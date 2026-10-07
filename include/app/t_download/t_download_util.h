#ifndef POKEBW2_APP_T_DOWNLOAD_T_DOWNLOAD_UTIL_H
#define POKEBW2_APP_T_DOWNLOAD_T_DOWNLOAD_UTIL_H

#include "types.h"
#include "struct_decls.h"

// t_download_util.c: the BGs, windows, messages, menus and cell actors of the downloaded tournaments' screens. The name
// is ours

void func_ov326_021a0a84(TDownloadWork *wk);
void func_ov326_021a0a88(TDownloadWork *wk);
void func_ov326_021a0ac8(TDownloadWork *wk);
void func_ov326_021a0b84(TDownloadWork *wk, int mode);
void func_ov326_021a0d2c(TDownloadWork *wk, int window);
void func_ov326_021a0d4c(TDownloadWork *wk, int mode);
void func_ov326_021a0da4(TDownloadWork *wk, int mode);
void func_ov326_021a1104(TDownloadWork *wk, int kind, int index, BOOL visible);
BOOL func_ov326_021a1134(TDownloadWork *wk, int kind, int index);
void func_ov326_021a1188(TDownloadWork *wk, int type);
void func_ov326_021a1274(TDownloadWork *wk);
int func_ov326_021a128c(TDownloadWork *wk);
BOOL func_ov326_021a1338(TDownloadWork *wk);
void func_ov326_021a1370(TDownloadWork *wk, BOOL clear);
void func_ov326_021a1388(TDownloadWork *wk, int window, u32 msgId, BOOL stream);
void func_ov326_021a14d4(TDownloadWork *wk, int button, int a2);
void func_ov326_021a1508(TDownloadWork *wk);
void func_ov326_021a1544(TDownloadWork *wk, int type, int index);
void func_ov326_021a16e8(TDownloadWork *wk, int mode);
int func_ov326_021a17c8(TDownloadWork *wk);
int func_ov326_021a17e4(TDownloadWork *wk, int result);
void func_ov326_021a1898(TDownloadWork *wk);
void func_ov326_021a1a10(TDownloadWork *wk, int type, int pos);
void func_ov326_021a1a78(TDownloadWork *wk, BOOL active);
void func_ov326_021a1b00(TDownloadWork *wk);
void func_ov326_021a1c0c(TDownloadWork *wk, BOOL start);
void func_ov326_021a1c34(TDownloadWork *wk, int tab);
void func_ov326_021a1c78(TDownloadWork *wk, int tab);
void func_ov326_021a1cb4(TDownloadWork *wk);
void func_ov326_021a1cf8(TDownloadWork *wk, int type, int index, int tab);
void func_ov326_021a1f34(TDownloadWork *wk, int type, int index);
int func_ov326_021a1fec(TDownloadWork *wk, int tab);
void func_ov326_021a2028(TDownloadWork *wk, int tab, int page, BOOL a3);
void func_ov326_021a20b4(TDownloadWork *wk, int mode, int tab);
int func_ov326_021a2114(TDownloadWork *wk, BOOL held, int mode);
void func_ov326_021a2138(TDownloadWork *wk, BOOL show);
void func_ov326_021a215c(TDownloadWork *wk, BOOL show);
void func_ov326_021a2194(TDownloadWork *wk, BOOL show);
void func_ov326_021a21d0(TDownloadWork *wk, int type, int slot);
void func_ov326_021a2298(TDownloadWork *wk, BOOL keys, BOOL touch, BOOL hide);
void func_ov326_021a2350(TDownloadWork *wk, int type, int min, int max, int pos);
BOOL func_ov326_021a23d4(TDownloadWork *wk, int button);
void func_ov326_021a2470(TDownloadWork *wk, int type, int slot);

#endif // POKEBW2_APP_T_DOWNLOAD_T_DOWNLOAD_UTIL_H
