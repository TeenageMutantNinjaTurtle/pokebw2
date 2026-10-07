#ifndef POKEBW2_SAVE_WBT_SAVE_H
#define POKEBW2_SAVE_WBT_SAVE_H

#include "types.h"
#include "struct_decls.h"

// The Pokémon World Tournament's save data, from func_020179f8. It counts to 9999 for each of 29 tournaments

void *func_0200fea0(SaveControl *save);
u16 func_0200feac(void *save, u32 tournament);
void func_0200feb4(void *save, u32 tournament);
u16 func_0200ff34(void *save, u8 index);

#endif // POKEBW2_SAVE_WBT_SAVE_H
