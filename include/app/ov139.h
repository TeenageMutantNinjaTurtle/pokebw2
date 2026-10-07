#ifndef POKEBW2_APP_OV139_H
#define POKEBW2_APP_OV139_H

#include "types.h"
#include "gfl/arc.h"
#include "gfl/clact.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/overlay.h"
#include "gfl/str.h"
#include "gfl/touchpanel.h"
#include "system/printsys.h"

// Overlay 139's parts of the lower screen that applications share: OBJ resources and their actors, the bar of icons at
// the bottom, a scrolling list, and the menu of two choices with which the evolution demo asks about learning a move.
// None of these functions has a name yet

#define OVERLAY_139 OVERLAY_ID(139)

// The OBJ resources of a set of files, and where to load them from
typedef struct {
    u32 chars;
    u32 palette;
    u32 cellAnims;
    u32 vramType;
} Ov139ObjRes;

typedef struct {
    u32 vramType;
    // Bit 0 loads the whole palette, bit 1 means the characters are compressed
    u32 flags;
    u32 arcId;
    u32 paletteFile;
    u32 charFile;
    u32 cellFile;
    u32 animFile;
    u8 paletteOffset;
    u8 paletteStart;
    u8 paletteCount;
} Ov139ObjResSetup;

void func_ov139_021999c8(Ov139ObjRes *res, const Ov139ObjResSetup *setup, ClActUnit *unit, HeapID heapId);
void func_ov139_02199a44(Ov139ObjRes *res);
// Creates an actor of the resources at (x, y), playing an animation
ClActor *func_ov139_02199a5c(Ov139ObjRes *res, ClActUnit *unit, u8 x, u8 y, u8 anim, HeapID heapId);

// The bar of icons at the bottom of the lower screen, such as the return button
typedef struct Ov139TouchBar Ov139TouchBar;

// An icon of the bar: one of the bar's own, or from OV139_TOUCHBAR_ICON_CUSTOM on, one drawn from the caller's
// resources and animations. Pressing the key does what touching it does
#define OV139_TOUCHBAR_ICON_CUSTOM 7

typedef struct {
    u32 icon;
    ClActorPos pos;
    u16 charRes;
    u16 plttRes;
    u16 cellRes;
    u16 anims[3];
    u32 unk14;
    u32 key;
    u32 se;
} Ov139TouchBarItem;

typedef struct {
    Ov139TouchBarItem *items;
    u32 count;
    ClActUnit *unit;
    u32 bg;
    u32 bgPalette;
    u32 objPalette;
    u32 vramType;
    BOOL unk1C;
} Ov139TouchBarSetup;

Ov139TouchBar *func_ov139_02199aa0(const Ov139TouchBarSetup *setup, HeapID heapId);
void func_ov139_02199b5c(Ov139TouchBar *bar);
void func_ov139_02199b90(Ov139TouchBar *bar);
// Whether the touched icon's animation has ended, or -1 when none was touched
u32 func_ov139_02199c08(Ov139TouchBar *bar);
// Whether the return icon was touched
BOOL func_ov139_02199c30(Ov139TouchBar *bar);
// Whether the icons can be touched
void func_ov139_02199c90(Ov139TouchBar *bar, BOOL active);
void func_ov139_02199ce0(Ov139TouchBar *bar, u32 a1);
void func_ov139_02199d08(Ov139TouchBar *bar, u32 icon, BOOL a2);
void func_ov139_02199d18(Ov139TouchBar *bar, u32 icon, BOOL a2);
void func_ov139_02199d48(Ov139TouchBar *bar, u32 icon, BOOL a2);
void func_ov139_02199d74(Ov139TouchBar *bar, u32 a1);

// A list of items that scrolls, with a scroll bar and arrows
typedef struct Ov139List Ov139List;

// What func_ov139_0219b2e0 returns besides the position of the item chosen
#define OV139_LIST_NONE (-1)

// A rectangle of the list's rows and buttons
typedef struct {
    TouchRect rect;
    u32 unk4;
} Ov139ListTouch;

// What the list calls to print an item into its row's window at y, when the cursor moves to an item, and when the
// items scroll by delta pixels
typedef struct {
    void (*print)(void *work, u32 index, PrintWindow *window, s16 y);
    void (*select)(void *work, u32 index);
    void (*scroll)(void *work, s16 delta);
} Ov139ListCallbacks;

typedef struct {
    u8 unk0[20];
    u16 count;
    u16 unk16;
    u8 cursorPos;
    u8 unk19;
    u16 scroll;
    const Ov139ListTouch *touch;
    const Ov139ListCallbacks *callbacks;
    void *work;
} Ov139ListSetup;

Ov139List *func_ov139_0219af1c(const Ov139ListSetup *setup, HeapID heapId);
void func_ov139_0219b138(Ov139List *list);
// Adds an item
void func_ov139_0219b1b4(Ov139List *list, u32 type, u32 value);
// Loads the screen of the list's frame, and its palette
void func_ov139_0219b1e0(Ov139List *list, ArcTool *arc, u32 fileId, BOOL compressed, u32 index);
void func_ov139_0219b21c(Ov139List *list, ArcTool *arc, u32 fileId, BOOL compressed, u32 a4, u16 a5, u8 a6);
void func_ov139_0219b27c(Ov139List *list, ArcTool *arc, u32 fileId, u32 palette, u32 count);
// Whether the list is still drawing its items
BOOL func_ov139_0219b294(Ov139List *list);
u32 func_ov139_0219b2e0(Ov139List *list);
// Where the scroll bar goes, from its y
int func_ov139_0219c324(Ov139List *list, int y);
PrintQueue *func_ov139_0219cc18(Ov139List *list);
// An item's value
u32 func_ov139_0219cc1c(Ov139List *list, u32 index);
// The item under the cursor, the cursor's row, and the first row shown
int func_ov139_0219cc28(Ov139List *list);
s16 func_ov139_0219cc34(Ov139List *list);
s16 func_ov139_0219cc3c(Ov139List *list);
// Whether the list can scroll down
BOOL func_ov139_0219cc44(Ov139List *list);
void func_ov139_0219cc58(Ov139List *list, int pos);
void func_ov139_0219cc90(Ov139List *list);
void func_ov139_0219ccb0(Ov139List *list, u32 a1);
void func_ov139_0219ccc8(Ov139List *list, u32 a1);
void func_ov139_0219ccd0(Ov139List *list, int a1);
u32 func_ov139_0219cd0c(Ov139List *list);

// A search of message files for the strings that start with a prefix
typedef struct Ov139Search Ov139Search;

// A string found: its message file and its line
typedef struct {
    u32 file;
    u32 line;
} Ov139SearchResult;

Ov139Search *func_ov139_0219a438(MsgData **files, u32 count, HeapID heapId);
void func_ov139_0219a490(Ov139Search *search);
// Fills results with the strings of a file that start with prefix, up to max, and returns how many it found
u32 func_ov139_0219a4a4(Ov139Search *search, u32 file, u32 a2, StrBuf *prefix, Ov139SearchResult *results, u32 max);

typedef struct TwoChoiceMenu TwoChoiceMenu;

// What func_ov139_0219ae78 returns
#define TWO_CHOICE_MENU_SECOND 0
#define TWO_CHOICE_MENU_FIRST 1
#define TWO_CHOICE_MENU_NONE 2

// Prints a string into a window through the queue, aligned at x by the alignment
void func_ov139_0219a2a4(PrintWindow *window, PrintQueue *queue, u16 x, u16 y, const StrBuf *strbuf, Font *font,
                         u16 color, u32 align);
TwoChoiceMenu *func_ov139_0219a584(HeapID heapId, u32 a1, u32 a2, u32 a3, u32 a4, ClActUnit *unit, Font *font,
                                   PrintQueue *queue, u32 a8);
void func_ov139_0219a864(TwoChoiceMenu *menu);
// Opens the menu with the two choices
void func_ov139_0219a8bc(TwoChoiceMenu *menu, StrBuf *first, StrBuf *second);
void func_ov139_0219aaa4(TwoChoiceMenu *menu);
void func_ov139_0219ab40(TwoChoiceMenu *menu);
u32 func_ov139_0219ae78(TwoChoiceMenu *menu);

#endif // POKEBW2_APP_OV139_H
