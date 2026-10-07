#ifndef POKEBW2_BATTLE_HANDLER_COMMON_H
#define POKEBW2_BATTLE_HANDLER_COMMON_H

// Overlay 167's handler_common.c, named descriptively: the helpers that the ability, item and move event handlers
// share. Function names from swan (https://github.com/ds-pokemon-hacking/swan, GPL-3.0) where it has them

#include "types.h"
#include "struct_decls.h"

BOOL func_ov167_021cde38(u32 monId);
BOOL IsMonLastInTurnOrder(BtlServerFlow *flow, u8 monId);
BOOL GiratinaArceusGenesectItemCheck(u16 species, u16 item);
BOOL func_ov167_021cdedc(BtlServerFlow *flow, u8 monId);
BOOL func_ov167_021cdf08(BtlServerFlow *flow, u8 monId);
BOOL func_ov167_021cdf28(BtlServerFlow *flow, u8 monId, u8 otherId);
void CommonMagicCoatCheckMoveEffect(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work);
void CommonMagicCoatWait(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work);
void func_ov167_021ce044(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work);
void MultiplyBasePower(u32 factor);
void CommonRunCalcSkip(BattleEventItem *item, BtlServerFlow *flow, u8 monId, s32 *work);
BOOL CommonCheckRunMessage(BattleEventItem *item, BtlServerFlow *flow, u8 monId);

#endif // POKEBW2_BATTLE_HANDLER_COMMON_H
