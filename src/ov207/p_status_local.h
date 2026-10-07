#ifndef POKEBW2_OV207_P_STATUS_LOCAL_H
#define POKEBW2_OV207_P_STATUS_LOCAL_H

#include "types.h"
#include "app/p_status.h"
#include "gfl/bmpwin.h"
#include "gfl/clact.h"
#include "gfl/g3d.h"
#include "gfl/msg.h"
#include "gfl/tcb.h"
#include "struct_decls.h"
#include "system/gf_font.h"
#include "system/mcss.h"
#include "system/printsys.h"
#include "system/wordset.h"

// The summary screen's work and the functions its files share. The ROM names p_status.c and the pages' files
// (p_sta_sub.c, p_sta_info.c, p_sta_ribbon.c, p_sta_skill.c and p_sta_oam.c); p_sta_sys.c, the screen's core, and
// ribbon.c, the ribbon table, are guessed names. So are the names of the fields and functions

// The palettes, characters and cell animations in PStatusWork's clResources
#define PSTA_RES_PLTT(i) (i)
#define PSTA_RES_CHAR(i) (12 + (i))
#define PSTA_RES_CELL(i) (25 + (i))
#define PSTA_RES_COUNT 38

#define PSTA_TYPE_COUNT 17

// PStatusWork.shownPage before the first page is drawn
#define PSTA_PAGE_NONE 4

// Which way PStatus_FindPokemon looks
enum {
    PSTA_DIR_UP,
    PSTA_DIR_DOWN,
};

// The buttons of the bottom screen
enum {
    PSTA_BUTTON_INFO,
    PSTA_BUTTON_SKILL,
    PSTA_BUTTON_RIBBON,
    // Registers the page to the shortcut menu
    PSTA_BUTTON_SHORTCUT,
    PSTA_BUTTON_UP,
    PSTA_BUTTON_DOWN,
    PSTA_BUTTON_CLOSE,
    PSTA_BUTTON_BACK,
    PSTA_BUTTON_COUNT,
};

// What the proc's main function does
enum {
    PSTA_SEQ_FADE_IN,
    PSTA_SEQ_WAIT_FADE_IN,
    PSTA_SEQ_EXIT,
    PSTA_SEQ_WAIT_FADE_OUT,
    PSTA_SEQ_MAIN,
};

// The mosaic that hides a change of page or Pokémon
enum {
    PSTA_MOSAIC_NONE,
    PSTA_MOSAIC_IN,
    PSTA_MOSAIC_REDRAW,
    PSTA_MOSAIC_OUT,
};

// A screen file and its data
typedef struct {
    NNSG2dScreenData *screen;
    void *file;
} PStaScreen;

struct PStatusWork {
    HeapID heapId;
    TCB *vblankTcb;
    PStatusParam *param;
    BOOL isRedrawing;
    BOOL playCry;
    BOOL canForgetHm;
    u16 partyIndex;
    // The Pokémon on screen, 0xff for none
    u8 shownPartyIndex;
    u8 bgScrollFrames;
    u8 isTouch;
    u32 lastVBlankCount;
    s32 touchHit;
    u32 touchX;
    u32 touchY;
    u32 prevTouchX;
    u32 prevTouchY;
    BOOL isEgg;
    u32 happiness;
    BOOL hasRibbon;
    BOOL isInputEnabled;
    BOOL upPressed;
    BOOL downPressed;
    int seq;
    int exitResult;
    int page;
    int shownPage;
    BOOL shortcutRegistered[3];
    u32 unk6C;
    G3DCamera *camera;
    u32 unk74;
    MCSSSystem *mcssSys;
    MsgData *msgData;
    Font *font;
    PrintQueue *printQueue;
    PStaSubWork *sub;
    PStaInfoWork *info;
    PStaSkillWork *skill;
    PStaRibbonWork *ribbon;
    u32 clResources[PSTA_RES_COUNT];
    u32 typeIconChars[PSTA_TYPE_COUNT];
    ClActUnit *actorUnit;
    ClActor *buttons[PSTA_BUTTON_COUNT];
    ClActor *typeIcons[2];
    ClActor *pressedButton;
    u16 plttAnimPhase;
    // Copied from OBJ palette RAM at the start, though only the animated colors 4 to 7 are used
    u16 cursorPltt[8];
    u16 tabPlttSrc[2][16];
    u16 tabPltt[16];
    u16 buttonPltt[16];
    u16 buttonPlttSrc[16];
    // A party copy of the boxed Pokémon shown
    PartyPkm *boxPartyPkm;
    int mosaicState;
    u8 mosaicLevel;
};

// p_sta_sys.c
BOOL PStatus_Init(PStatusWork *wk);
BOOL PStatus_Exit(PStatusWork *wk);
int PStatus_Main(PStatusWork *wk);
void PStatus_EnableInput(PStatusWork *wk, BOOL enable);
BoxPkm *PStatus_GetBoxPkm(PStatusWork *wk);
PartyPkm *PStatus_GetPartyPkm(PStatusWork *wk);
void PStatus_SetDecrypted(PStatusWork *wk, BOOL decrypt);
void PStatus_Print(PStatusWork *wk, GFLBitmap *bitmap, u32 msgId, u16 x, u16 y, u16 color);
void PStatus_PrintToWindow(PStatusWork *wk, BmpWin *window, u32 msgId, u16 x, u16 y, u16 color);
void PStatus_PrintCentered(PStatusWork *wk, GFLBitmap *bitmap, u32 msgId, u16 x, u16 y, u16 color);
void PStatus_PrintFormatted(PStatusWork *wk, GFLBitmap *bitmap, WordSet *wordSet, u32 msgId, u16 x, u16 y, u16 color);
void PStatus_PrintFormattedToWindow(PStatusWork *wk, BmpWin *window, WordSet *wordSet, u32 msgId, u16 x, u16 y,
                                    u16 color);
void PStatus_PrintFormattedRight(PStatusWork *wk, GFLBitmap *bitmap, WordSet *wordSet, u32 msgId, u16 x, u16 y,
                                 u16 color);
void PStatus_PrintFormattedRightToWindow(PStatusWork *wk, BmpWin *window, WordSet *wordSet, u32 msgId, u16 x, u16 y,
                                         u16 color);

// p_sta_sub.c
PStaSubWork *func_ov207_021b5364(PStatusWork *wk);
void func_ov207_021b5394(PStatusWork *wk, PStaSubWork *sub);
void func_ov207_021b53a0(PStatusWork *wk, PStaSubWork *sub);
void func_ov207_021b5580(PStatusWork *wk, PStaSubWork *sub, ArcTool *arc);
void func_ov207_021b559c(PStatusWork *wk, PStaSubWork *sub);
void func_ov207_021b55a4(PStatusWork *wk, PStaSubWork *sub);
void func_ov207_021b56e0(PStatusWork *wk, PStaSubWork *sub);
void func_ov207_021b5710(PStatusWork *wk, PStaSubWork *sub);
void func_ov207_021b57cc(PStatusWork *wk, PStaSubWork *sub);
void func_ov207_021b5a70(PStatusWork *wk, PStaSubWork *sub);
void func_ov207_021b5a98(PStatusWork *wk, PStaSubWork *sub);

// p_sta_info.c
PStaInfoWork *func_ov207_021b6924(PStatusWork *wk);
void func_ov207_021b6958(PStatusWork *wk, PStaInfoWork *info);
void func_ov207_021b696c(PStatusWork *wk, PStaInfoWork *info);
void func_ov207_021b6970(PStatusWork *wk, PStaInfoWork *info, ArcTool *arc);
void func_ov207_021b6a18(PStatusWork *wk, PStaInfoWork *info);
void func_ov207_021b6a60(PStatusWork *wk, PStaInfoWork *info);
void func_ov207_021b6ad4(PStatusWork *wk, PStaInfoWork *info);
void func_ov207_021b6cac(PStatusWork *wk, PStaInfoWork *info);
void func_ov207_021b6cd4(PStatusWork *wk, PStaInfoWork *info);

// p_sta_ribbon.c
PStaRibbonWork *func_ov207_021b7644(PStatusWork *wk);
void func_ov207_021b767c(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b7690(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b76e4(PStatusWork *wk, PStaRibbonWork *ribbon, ArcTool *arc);
void func_ov207_021b7764(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b7798(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b785c(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b7db0(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b7e0c(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b7efc(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b7f20(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b7f7c(PStatusWork *wk, PStaRibbonWork *ribbon);
void func_ov207_021b804c(PStatusWork *wk, PStaRibbonWork *ribbon);

// p_sta_skill.c
PStaSkillWork *func_ov207_021b8510(PStatusWork *wk);
void func_ov207_021b8594(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b85a0(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b87e0(PStatusWork *wk, PStaSkillWork *skill, ArcTool *arc);
void func_ov207_021b8864(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b88ac(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b8a34(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b8a9c(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b8b30(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b8ba4(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b8bf4(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b9510(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b9610(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b96b8(PStatusWork *wk, PStaSkillWork *skill);
void func_ov207_021b9728(PStatusWork *wk, PStaSkillWork *skill);

// ribbon.c
u32 func_ov207_021bad9c(u32 ribbon, u32 field);

#endif // POKEBW2_OV207_P_STATUS_LOCAL_H
