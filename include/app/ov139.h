#ifndef POKEBW2_APP_OV139_H
#define POKEBW2_APP_OV139_H

#include "types.h"
#include "gfl/clact.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/overlay.h"
#include "gfl/str.h"
#include "system/printsys.h"

// Overlay 139's menu of two choices on the lower screen, with which the evolution demo asks about learning a move.
// None of these functions has a name yet

#define OVERLAY_139 OVERLAY_ID(139)

typedef struct TwoChoiceMenu TwoChoiceMenu;

// What func_ov139_0219ae78 returns
#define TWO_CHOICE_MENU_SECOND 0
#define TWO_CHOICE_MENU_FIRST 1
#define TWO_CHOICE_MENU_NONE 2

TwoChoiceMenu *func_ov139_0219a584(HeapID heapId, u32 a1, u32 a2, u32 a3, u32 a4, ClActUnit *unit, Font *font,
                                   PrintQueue *queue, u32 a8);
void func_ov139_0219a864(TwoChoiceMenu *menu);
// Opens the menu with the two choices
void func_ov139_0219a8bc(TwoChoiceMenu *menu, StrBuf *first, StrBuf *second);
void func_ov139_0219aaa4(TwoChoiceMenu *menu);
void func_ov139_0219ab40(TwoChoiceMenu *menu);
u32 func_ov139_0219ae78(TwoChoiceMenu *menu);

// A sprite that loads its own characters, palette and cells from an archive. The names are descriptive
typedef struct {
    u32 charRes;
    u32 plttRes;
    u32 cellRes;
    u32 vramType;
    ClActor *actor;
} ResSprite;

typedef struct {
    u32 vramType;
    u32 flags;
    u32 arcId;
    u32 plttFile;
    u32 charFile;
    u32 cellFile;
    u32 animFile;
    // Where the palette goes, and which and how many of the file's palettes
    u8 plttOffset;
    u8 plttSrcOffset;
    u8 plttCount;
} ResSpriteParam;

void func_ov139_021999c8(ResSprite *sprite, const ResSpriteParam *param, ClActUnit *unit, HeapID heapId);
void func_ov139_02199a44(ResSprite *sprite);
ClActor *func_ov139_02199a5c(ResSprite *sprite, ClActUnit *unit, u8 x, u8 y, u8 a4, HeapID heapId);

// The bar of buttons along the bottom of the lower screen (touchbar.c)
typedef struct TouchBar TouchBar;

// A button of the bar: one of the bar's own icons, or from TOUCHBAR_ICON_CUSTOM on, one drawn from the caller's
// resources and animations. Pressing the key does what touching it does
#define TOUCHBAR_ICON_CUSTOM 7

typedef struct {
    u32 icon;
    s16 x;
    s16 y;
    u16 charRes;
    u16 plttRes;
    u16 cellRes;
    u16 anims[3];
    u32 unk14;
    u32 key;
    u32 se;
} TouchBarItem;

typedef struct {
    TouchBarItem *items;
    u32 count;
    ClActUnit *unit;
    // The BG frame of the bar, a sub screen frame from 4 on, and the palettes it loads into
    u32 bgFrame;
    u32 bgPltt;
    u32 objPltt;
    u32 mapping;
    BOOL unk1C;
} TouchBarSetup;

TouchBar *func_ov139_02199aa0(const TouchBarSetup *setup, HeapID heapId);
void func_ov139_02199b5c(TouchBar *bar);
void func_ov139_02199b90(TouchBar *bar);
// The button that was touched
u32 func_ov139_02199c08(TouchBar *bar);
// The button held down
u32 func_ov139_02199c30(TouchBar *bar);
void func_ov139_02199ce0(TouchBar *bar, u32 a1);
void func_ov139_02199d08(TouchBar *bar, u32 button, BOOL a2);
void func_ov139_02199d18(TouchBar *bar, u32 button, BOOL a2);
void func_ov139_02199d74(TouchBar *bar, u32 a1);

#endif // POKEBW2_APP_OV139_H
