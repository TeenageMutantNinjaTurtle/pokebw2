#ifndef POKEBW2_BATTLE_BTL_DISPLAY_H
#define POKEBW2_BATTLE_BTL_DISPLAY_H

#include "types.h"
#include "struct_decls.h"

void func_ov167_021b1434(void *display, u32 event, u8 monId, ...);
void ServerDisplay_AbilityPopupAdd(BattleHandler *handler, BattleMon *mon);
void ServerDisplay_AbilityPopupRemove(BattleHandler *handler, BattleMon *mon);
void scPut_SetContFlag(BattleHandler *handler, BattleMon *mon, u32 flag);
void scPut_ResetContFlag(BattleHandler *handler, BattleMon *mon, u32 flag);
void ServerDisplay_SetTurnFlag(BattleHandler *handler, BattleMon *mon, u32 flag);

#endif // POKEBW2_BATTLE_BTL_DISPLAY_H
