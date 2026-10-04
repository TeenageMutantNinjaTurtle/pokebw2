#ifndef POKEBW2_APP_BOX2_MAIN_H
#define POKEBW2_APP_BOX2_MAIN_H

#include "types.h"
#include "app/box2.h"
#include "gfl/arc.h"
#include "gfl/clact.h"
#include "gfl/msg.h"
#include "gfl/str.h"
#include "gfl/tcb.h"
#include "system/printsys.h"
#include "system/wordset.h"
#include "struct_decls.h"

// The PC box's work and the functions of box2_main.c, which the sequences in box2_seq.c call. Names are ours

// The number of boxes once all are open
#define BOX2_TRAY_MAX 24
// The trays and positions of the party and of the box list, after the boxes' own
#define BOX2_GET_NONE 0xff

// The Pokémon search's criteria, which the boxes' icons are filtered by
typedef struct {
    u16 species;
    // 1 when the Pokémon must hold an item, 2 when it must hold none
    u8 item;
    u8 marks;
    u8 unk4;
    u8 ability;
    u8 unk6;
    u8 active;
} Box2SearchParam;

struct Box2SysWork {
    Box2Param *param;
    GameProcManager *procManager;
    BOOL procMgrResult;
    void *subProcWork;
    u16 subRet;
    u8 subProcType;
    u8 unk13;
    u8 tray;
    u8 trayMax;
    u8 pos;
    // The tray of the held Pokémon, or BOX2_GET_NONE
    u8 getTray;
    u8 unk18;
    u8 trayScroll;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u32 curRcvPos;
    int nextSeq;
    Box2AppWork *app;
    Box2SearchParam search;
};

// A text object on OAM
typedef struct {
    void *oam;
    GFLBitmap *bitmap;
} Box2FontOam;

// What runs once per frame until it returns FALSE
typedef BOOL (*Box2VFunc)(Box2SysWork *syswk);

typedef struct {
    Box2VFunc func;
    Box2VFunc freq;
    void *work;
    u16 seq;
    u16 cnt;
} Box2IrqWork;

// An item of the yes/no menu
typedef struct {
    StrBuf *str;
    u16 color;
    u32 type;
} Box2TaskMenuItem;

// A button's press animation, on an actor or on the BG
typedef struct {
    u8 mode : 1;
    u8 id : 7;
    u8 pal1 : 4;
    u8 pal2 : 4;
    u8 seq;
    u8 cnt;
    u8 px;
    u8 py;
    u8 sx;
    u8 sy;
} Box2ButtonAnm;

typedef struct {
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    u16 anmMax;
    u16 anmCnt;
    u8 anm;
    u8 prevAnm;
    u8 startPos;
    u8 endPos;
} Box2RangeSelect;

struct Box2AppWork {
    void *bmpOam;
    Box2FontOam fontOam[10];
    u32 keyRepeatWait;
    u32 keyRepeatStart;
    TCB *vtask;
    Box2IrqWork vfunk;
    int vfuncNextSeq;
    void *palFade;
    void *cursorMove;
    void *bgWinFrame;
    Font *font;
    Font *smallFont;
    MsgData *msgData;
    WordSet *wordSet;
    StrBuf *expandBuf;
    PrintQueue *printQueue;
    u32 unk98;
    PrintWindow windows[28];
    u8 flushChar[4];
    u32 cursorChars;
    BOOL nationalDex;
    u16 *regionalDex;
    Box2TaskMenuItem yesNoItems[2];
    void *yesNoRes;
    void *yesNoMenu;
    u16 ynID;
    Box2ButtonAnm bawk;
    ArcTool *pokeIconArc;
    u8 pokeIconChar[30][0x200];
    u8 pokeIconPal[30];
    u8 pokeIconId[66];
    BOOL pokeIconExist[30];
    u8 trayIconChar[BOX2_TRAY_MAX][0x400];
    ClActUnit *clunit;
    ClActor *actors[145];
    u32 chrRes[129];
    u8 unkA2E0[0x204];
    u32 palRes[11];
    u32 cellRes[13];
    u16 pokegraSwap;
    u16 unkA546;
    u32 oldCurPos;
    u16 getItem;
    u16 getItemInitPos;
    u8 unkA550;
    u8 unkA551;
    u8 unkA552;
    u8 unkA553;
    u32 unkA554;
    s8 wallPx;
    u8 wallArea;
    u8 unkA55A;
    u8 wallpaperPos;
    u8 unkA55C;
    u8 unkA55D;
    u8 unkA55E;
    u8 unkA55F;
    u32 tpx;
    u32 tpy;
    int wipeSeq;
    int wait;
    void *unkA570;
    int subSeq;
    int msgNextSeq;
    u8 rangeFlags[30];
    u8 rangeWidth;
    u8 rangeHeight;
    Box2RangeSelect rangeSelect;
    BOOL unkA5B4;
    BOOL unkA5B8;
};

void Box2Main_InitSettings(Box2SysWork *syswk);

#endif // POKEBW2_APP_BOX2_MAIN_H
