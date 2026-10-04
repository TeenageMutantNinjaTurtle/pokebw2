#ifndef POKEBW2_OV214_WORLDTRADE_LOCAL_H
#define POKEBW2_OV214_WORLDTRADE_LOCAL_H

#include "types.h"
#include "app/worldtrade.h"
#include "dpw/dpw_tr.h"
#include "gfl/bmpwin.h"
#include "gfl/clact.h"
#include "gfl/msg.h"
#include "gfl/proc.h"
#include "gfl/tcb.h"
#include "gfl/tcbl.h"
#include "struct_decls.h"
#include "system/app_keycursor.h"
#include "system/app_taskmenu.h"
#include "system/gf_font.h"
#include "system/printsys.h"
#include "system/time_icon.h"
#include "system/wordset.h"

// The Global Trade Station's work and the functions its files share. The header's name is a guess, as are the
// names of the sequences, screens, fields and functions, except task_res and task_work, which the overlay's asserts
// print. The ROM names eight of the files; worldtrade_title.c, worldtrade_mypoke.c, worldtrade_partner.c and
// worldtrade_upload.c are guessed names for the screens of the same names

// What the proc's main function does
enum {
    WT_SEQ_INIT,
    WT_SEQ_FADEIN,
    WT_SEQ_MAIN,
    WT_SEQ_FADEOUT,
    WT_SEQ_OUT,
    WT_SEQ_END,
};

// The screens, each with an init, main and end function
enum {
    WORLDTRADE_ENTER,
    WORLDTRADE_TITLE,
    WORLDTRADE_MYPOKE,
    WORLDTRADE_PARTNER,
    WORLDTRADE_SEARCH,
    WORLDTRADE_MYBOX,
    WORLDTRADE_DEPOSIT,
    WORLDTRADE_UPLOAD,
    WORLDTRADE_STATUS,
    WORLDTRADE_DEMO,
};

// The cell actor resources: the main screen's, the lower screen's, the player's and the main screen's second set
enum {
    WT_CLACT_RES_MAIN,
    WT_CLACT_RES_SUB,
    WT_CLACT_RES_HERO,
    WT_CLACT_RES_MAIN2,
    WT_CLACT_RES_SETS,
};

enum {
    WT_CLACT_RES_CHAR,
    WT_CLACT_RES_PLTT,
    WT_CLACT_RES_CELL,
    WT_CLACT_RES_KINDS,
};

// A window whose text worldtrade_adapter.c prints through the print queue
typedef struct {
    BmpWin *win;
    u8 pending;
    u32 active;
} WorldTradePrintEntry;

// worldtrade_adapter.c's text printing: the font, the print queue and the message stream
typedef struct {
    Font *font;
    TCBExManager *tcbManager;
    TrainerDataSave *config;
    PrintQueue *printQueue;
    PrintStream *stream;
    BmpWin *streamWin;
    WorldTradePrintEntry entries[24];
    KeyCursor *keyCursor;
} WorldTradePrint;

// An entry of the list that the select boxes take their texts from
typedef struct {
    StrBuf *str;
    u32 param;
} WorldTradeMenuListItem;

typedef struct WorldTradeWork WorldTradeWork;

typedef void (*WorldTradeVBlankFunc)(WorldTradeWork *wk);

struct WorldTradeWork {
    WorldTradeParam *param;
    u8 unk4[0xc];
    int subProcess;
    int subNextProcess;
    int unk18;
    int oldSubProcess;
    int subProcessMode;
    int unk24;
    int subprocessSeq;
    int subprocessNextSeq;
    u16 unk30;
    u16 unk32;
    u16 unk34;
    // Counts down the frames before the server may be checked again
    u16 serverWaitTime;
    u8 unk38[0x80];
    // Set while the status screen or the trade demo runs, which takes the cell actors
    int subprocFlag;
    u8 unkBC[0x4];
    u16 titleCursorPos;
    u16 unkC2;
    u16 boxTrayNo;
    u8 unkC6[0xa];
    // How many Pokémon a search found
    int searchResult;
    u8 unkD4[0xa82];
    Dpw_Tr_PokemonSearchData search;
    // The last search, which can't be made again
    Dpw_Tr_PokemonSearchData searchBackup;
    u8 unkB62[0x6];
    WordSet *wordSet;
    MsgData *msgManager;
    MsgData *monsNameManager;
    MsgData *lobbyMsgManager;
    MsgData *systemMsgManager;
    MsgData *countryNameManager;
    u8 unkB80[0x40];
    ClActUnit *clactUnit;
    u32 clactRes[WT_CLACT_RES_SETS][WT_CLACT_RES_KINDS];
    u8 unkBF4[0x14c];
    BmpWin *msgWin;
    u8 unkD44[0xa4];
    WorldTradeMenuListItem *menuList;
    u8 unkDEC[0xc];
    WaitIcon *timeWaitWork;
    u8 unkDFC[0x8];
    AppTaskMenuRes *task_res;
    AppTaskMenu *task_work;
    u8 unkE0C[0xc];
    u16 demoEnd;
    u16 subLcdTouchOK;
    u8 unkE1C[0x8c];
    // The Pokémon of the trade demo
    PartyPkm *demoPokemon;
    u8 unkEAC[0x4];
    u16 boxPokeNum;
    u16 boxSearchFlag;
    u8 unkEB4[0x8];
    // Called once at the next VBlank
    WorldTradeVBlankFunc vfunc;
    // Called at every VBlank
    WorldTradeVBlankFunc vfunc2;
    u8 unkEC4[0xc0];
    int countryCode;
    u8 unkF88[0x8];
    TCB *vblankTask;
    TCBManager *tcbManager;
    u8 unkF98[0x4];
    void *tcbBuffer;
    WorldTradePrint print;
    u8 unk10DC[0x20c];
    int unk12E8;
    u8 unk12EC[0x4];
    GameProcManager *procManager;
    BOOL procResult;
    u8 unk12F8[0x34];
};

// worldtrade.c
void WorldTrade_TouchWinYesNoMake(WorldTradeWork *wk, int y, int cgx, int palette, u8 passive);
void WorldTrade_TouchWinYesNoMakeEx(WorldTradeWork *wk, int y, int cgx, int palette, int frame, u8 passive);
void WorldTrade_TouchWinYesNoDel(WorldTradeWork *wk);
u32 WorldTrade_TouchSwMain(WorldTradeWork *wk);
void WorldTrade_SelBoxInit(WorldTradeWork *wk, u8 frame, int count, int y);
int WorldTrade_SelBoxMain(WorldTradeWork *wk);
void WorldTrade_SelBoxEnd(WorldTradeWork *wk);
void WorldTrade_SetNextSeq(WorldTradeWork *wk, int toSeq, int nextSeq);
void WorldTrade_ActPos(ClActor *act, int x, int y);
void WorldTrade_SubProcessChange(WorldTradeWork *wk, int subProcess, int mode);
void WorldTrade_SubProcessUpdate(WorldTradeWork *wk);
int WorldTrade_GetTalkSpeed(WorldTradeWork *wk);
void WorldTrade_BoxPokeNumGetStart(WorldTradeWork *wk);
void WorldTrade_TimeIconAdd(WorldTradeWork *wk);
void WorldTrade_TimeIconDel(WorldTradeWork *wk);
void WorldTrade_CLACT_PosChange(ClActor *act, int x, int y);
void WorldTrade_SetPassiveKeepBG2(BOOL main);
void WorldTrade_ClearPassive(void);
void WorldTrade_InitGraphics(WorldTradeWork *wk);
void WorldTrade_ExitGraphics(WorldTradeWork *wk);
void WorldTrade_ShowFatalError(WorldTradeWork *wk);

// worldtrade_box.c
int WorldTrade_Box_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Box_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Box_End(WorldTradeWork *wk, int seq);

// worldtrade_demo.c
int WorldTrade_Demo_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Demo_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Demo_End(WorldTradeWork *wk, int seq);

// worldtrade_deposit.c
int WorldTrade_Deposit_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Deposit_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Deposit_End(WorldTradeWork *wk, int seq);

// worldtrade_enter.c
int WorldTrade_Enter_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Enter_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Enter_End(WorldTradeWork *wk, int seq);

// worldtrade_mypoke.c
int WorldTrade_MyPoke_Init(WorldTradeWork *wk, int seq);
int WorldTrade_MyPoke_Main(WorldTradeWork *wk, int seq);
int WorldTrade_MyPoke_End(WorldTradeWork *wk, int seq);

// worldtrade_partner.c
int WorldTrade_Partner_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Partner_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Partner_End(WorldTradeWork *wk, int seq);

// worldtrade_search.c
int WorldTrade_Search_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Search_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Search_End(WorldTradeWork *wk, int seq);

// worldtrade_status.c
int WorldTrade_Status_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Status_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Status_End(WorldTradeWork *wk, int seq);

// worldtrade_sublcd.c
void func_ov214_021de510(WorldTradeWork *wk);
void func_ov214_021de98c(WorldTradeWork *wk, int count, int a2);
void func_ov214_021deb40(WorldTradeWork *wk);

// worldtrade_title.c
int WorldTrade_Title_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Title_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Title_End(WorldTradeWork *wk, int seq);

// worldtrade_upload.c
int WorldTrade_Upload_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Upload_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Upload_End(WorldTradeWork *wk, int seq);

// worldtrade_adapter.c
PartyPkm *func_ov214_021e1504(HeapID heapId);
void func_ov214_021e15d4(WorldTradePrint *print, TrainerDataSave *config);
void func_ov214_021e1640(WorldTradePrint *print);
void func_ov214_021e166c(WorldTradePrint *print);

#endif // POKEBW2_OV214_WORLDTRADE_LOCAL_H
