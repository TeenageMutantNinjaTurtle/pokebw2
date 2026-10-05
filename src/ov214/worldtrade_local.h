#ifndef POKEBW2_OV214_WORLDTRADE_LOCAL_H
#define POKEBW2_OV214_WORLDTRADE_LOCAL_H

#include "types.h"
#include "app/worldtrade.h"
#include "dpw/dpw_tr.h"
#include "gfl/bmp_menu.h"
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

// A Pokémon icon of the box screen, whose characters and palette worldtrade_box.c uploads at the next VBlank
typedef struct {
    u32 charOffset;
    u32 palette;
    ClActor *icon;
    u8 chars[0x200];
} WorldTradePokeBuf;

// The boxes and the party have 30 slots a page
#define BOX_POKE_NUM 30
// How many Pokémon a search returns
#define SEARCH_POKE_MAX 7

// Which table of levels a wanted level is from
#define LEVEL_PRINT_TBL_DEPOSIT 0
#define LEVEL_PRINT_TBL_SEARCH 1

typedef struct {
    int boxNo;
    int pos;
} WorldTradeEvoPokeInfo;

// The deposit and search screens' work
typedef struct {
    ListMenuOption *pokename;
    u16 headwordPos;
    u16 headwordListPos;
    u16 namePos;
    u16 nameListPos;
    int sexPos;
    int levelPos;
    // Whether each species is of the regional Pokédex
    u8 *sinouTable;
    // The species in the order of their names
    u16 *nameSortTable;
    int nameSortNum;
    // The gender ratio of the Pokémon chosen
    int sexSelection;
    int cursorSide;
    int leftCursorPos;
    int rightCursorPos;
} WorldTradeDepositWork;

// The cursor of each list of the name input, kept between the deposit and search screens
typedef struct {
    u16 headList;
    u16 headPos;
    u16 nameList[10];
    u16 namePos[10];
} WorldTradeSelectListPos;

typedef struct WorldTradeInputWork WorldTradeInputWork;

// What worldtrade_input.c's input asks for; the modes from INPUT_MODE_HEADWORD_1 on are its own steps
enum {
    INPUT_MODE_POKEMON_NAME,
    INPUT_MODE_SEX,
    INPUT_MODE_LEVEL,
    INPUT_MODE_NATION,
    INPUT_MODE_HEADWORD_1,
    INPUT_MODE_HEADWORD_2,
    INPUT_MODE_NATION_HEAD1,
    INPUT_MODE_NATION_HEAD2,
};

// The screen that uses the input
enum {
    INPUT_SITUATION_DEPOSIT,
    INPUT_SITUATION_SEARCH,
};

// worldtrade_adapter.c's numbers, printed with a font of digits
typedef struct WorldTradeNumFont WorldTradeNumFont;

// What worldtrade_input.c's input draws with
typedef struct {
    BmpWin **menuWin;
    BmpWin **backWin;
    ClActor *cursorAct;
    ClActor *arrowAct[2];
    // Only for the search screen
    ClActor *searchCursorAct;
    MsgData *msgManager;
    MsgData *monsNameManager;
    MsgData *countryNameManager;
    PokeDexSave *zukan;
    u8 *sinouTable;
    TrainerDataSave *config;
} WorldTradeInputHeader;

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
    // The server's or the library's error, which the error screens show
    int connectErrorNo;
    u8 unk3C[0x7c];
    // Set while the status screen or the trade demo runs, which takes the cell actors
    int subprocFlag;
    // The cursor of the list being shown, to play a sound when it moves
    u16 listpos;
    u16 unkBE;
    u16 titleCursorPos;
    u16 unkC2;
    u16 boxTrayNo;
    u16 boxCursorPos;
    // How many boxes the player has
    u32 boxCount;
    // The Pokémon chosen to deposit or offer
    BoxPkm *depositPkm;
    // How many Pokémon a search found
    int searchResult;
    // Which of them was chosen
    int touchTrainerPos;
    // The trade partner, made up for the trade demo
    PlayerInfo *partnerStatus;
    // Where the traded Pokémon goes, for its evolution: a box and slot, or 0xff and a party slot
    WorldTradeEvoPokeInfo evoPokeInfo;
    Dpw_Tr_Data uploadPokemonData;
    Dpw_Tr_Data downloadPokemonData[SEARCH_POKE_MAX];
    Dpw_Tr_Data exchangePokemonData;
    Dpw_Tr_PokemonDataSimple post;
    Dpw_Tr_PokemonSearchData want;
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
    StrBuf *boxTrayNameString;
    // "Quit"
    StrBuf *endString;
    StrBuf *talkString;
    StrBuf *titleString;
    StrBuf *infoString[10];
    u8 unkBB8[0x8];
    ClActUnit *clactUnit;
    u32 clactRes[WT_CLACT_RES_SETS][WT_CLACT_RES_KINDS];
    ClActor *cursorAct;
    ClActor *subCursorAct;
    // The finger that points at the Quit button
    ClActor *fingerAct;
    ClActor *pokeIconAct[BOX_POKE_NUM];
    ClActor *itemIconAct[BOX_POKE_NUM];
    ClActor *cballAct[6];
    // The Pokémon's picture on the main screen
    ClActor *pokemonAct;
    ClActor *subAct[8];
    // The arrows by the box name
    ClActor *boxArrowAct[2];
    ClActor *unkD34;
    // The icon that says to look at the lower screen
    ClActor *promptDsAct;
    int unkD3C;
    BmpWin *msgWin;
    u8 unkD44[0x8];
    BmpWin *subWin;
    BmpWin *menuWin[16];
    BmpWin *infoWin[16];
    BmpWin *talkWin;
    // "Back"
    BmpWin *backWin;
    u8 unkDD8[0x8];
    // Explains the screen on the lower screen
    BmpWin *explainWin;
    // worldtrade_input.c's input of a search or of the wanted Pokémon
    WorldTradeInputWork *inputWork;
    ListMenuOption *menuList;
    u8 unkDEC[0x8];
    BmpMenuList *bmpListWork;
    WaitIcon *timeWaitWork;
    int wait;
    // The deposit and search screens' work
    WorldTradeDepositWork *dw;
    AppTaskMenuRes *task_res;
    AppTaskMenu *task_work;
    u8 unkE0C[0xc];
    u16 demoEnd;
    u16 subLcdTouchOK;
    u8 unkE1C[0x88];
    // A copy of the Pokémon the player trades away, which an evolution by trade checks
    PartyPkm *sentPokemon;
    // The Pokémon of the trade demo
    PartyPkm *demoPokemon;
    // The box page's Pokémon, as the server describes them
    Dpw_Tr_PokemonDataSimple *boxWork;
    u16 boxPokeNum;
    u16 boxSearchFlag;
    u32 subOutFlag;
    WorldTradePokeBuf *boxIcon;
    // Called once at the next VBlank
    WorldTradeVBlankFunc vfunc;
    // Called at every VBlank
    WorldTradeVBlankFunc vfunc2;
    // The first y of each person on the lower screen
    s16 subActY[10][2];
    WorldTradeSelectListPos selectListPos;
    // The player's profile on the server, and the server's answer
    Dpw_Common_Profile dcProfile;
    Dpw_Common_ProfileResult dcProfileResult;
    int countryCode;
    // The steps and frames of a server error's message
    s16 localSeq;
    s16 localWait;
    // Frames spent waiting for the server
    s32 timeoutCount;
    TCB *vblankTask;
    TCBManager *tcbManager;
    u8 unkF98[0x4];
    void *tcbBuffer;
    WorldTradePrint print;
    // The parameter of the proc that a screen runs, the trade demo or the evolution demo
    void *subProcParam;
    u8 unk10E0[0x8c];
    // The Wi-Fi login proc's work
    u8 wifiLoginBuffer[0x178];
    int unk12E4;
    int unk12E8;
    // The step of the login, which the Wi-Fi login proc calls back for
    int loginSeq;
    GameProcManager *procManager;
    BOOL procResult;
    // Set when the traded Pokémon may evolve
    int checkEvolution;
    u8 unk12FC[0x30];
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
BOOL WorldTrade_GetPPorPPP(int tray);
BoxPkm *WorldTrade_GetPokePtr(PokeParty *party, BoxSaveAccessor *box, int tray, int pos);
int WorldTrade_GetBoxPokeNum(PokeParty *party, BoxSaveAccessor *box, int tray);
BOOL WorldTrade_PokemonMailCheck(PartyPkm *pkm);

// worldtrade_demo.c
int WorldTrade_Demo_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Demo_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Demo_End(WorldTradeWork *wk, int seq);
PlayerInfo *WorldTrade_MakePartnerStatus(Dpw_Tr_Data *dtd);

// worldtrade_deposit.c
int WorldTrade_Deposit_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Deposit_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Deposit_End(WorldTradeWork *wk, int seq);
BOOL WorldTrade_SexSelectionCheck(Dpw_Tr_PokemonSearchData *dtps, int sexSelection);
void WorldTrade_PokeNamePrint(BmpWin *win, MsgData *nameManager, int monsno, int flag, int y, u16 color,
                              WorldTradePrint *print);
void WorldTrade_PokeNamePrintNoPut(BmpWin *win, MsgData *nameManager, int monsno, int y, u16 color,
                                   WorldTradePrint *print);
void WorldTrade_CountryPrint(BmpWin *win, MsgData *nameManager, MsgData *msgManager, int countryCode, int flag, int y,
                             u16 color, WorldTradePrint *print);
void WorldTrade_SexPrint(BmpWin *win, MsgData *msgManager, int sex, int flag, int y, int printFlag, u16 color,
                         WorldTradePrint *print);
void WorldTrade_SexPrintNoPut(BmpWin *win, MsgData *msgManager, int sex, int flag, int x, int y, u16 color,
                              WorldTradePrint *print);
void WorldTrade_WantLevelPrint(BmpWin *win, MsgData *msgManager, int level, int flag, int y, u16 color, int tblSelect,
                               WorldTradePrint *print);
void WorldTrade_WantLevelPrint_XY(BmpWin *win, MsgData *msgManager, int level, int flag, int x, int y, u16 color,
                                  int tblSelect, WorldTradePrint *print);
void WorldTrade_PokeWantPrint(MsgData *msgManager, MsgData *monsNameManager, WordSet *wordSet, BmpWin **win, int monsno,
                              int sex, int level, WorldTradePrint *print);
void WorldTrade_MyPokeWantPrint(MsgData *msgManager, MsgData *monsNameManager, WordSet *wordSet, BmpWin **win,
                                int monsno, int sex, int level, WorldTradePrint *print);
void WorldTrade_PokeInfoPrint(MsgData *msgManager, WordSet *wordSet, BmpWin **win, BoxPkm *pkm,
                              Dpw_Tr_PokemonDataSimple *post, WorldTradePrint *print);
u16 *WorldTrade_ZukanSortDataGet(int heapId, int idx, int *num);
void WorldTrade_HeadwordRangeGet(int select, int *start, int *end);
u8 *WorldTrade_SinouZukanDataGet(int heapId);
void WorldTrade_PostPokemonBaseDataMake(Dpw_Tr_Data *dtd, WorldTradeWork *wk);
BmpMenuList *WorldTrade_PokeNameListMake(WorldTradeWork *wk, ListMenuOption **menulist, BmpWin *win,
                                         MsgData *msgManager, MsgData *monsNameManager, WorldTradeDepositWork *dw,
                                         PokeDexSave *zukan);
int WorldTrade_LevelListAdd(ListMenuOption **menulist, MsgData *msgManager, int tblSelect);
void WorldTrade_LevelMinMaxSet(Dpw_Tr_PokemonSearchData *dtps, int index, int tblSelect);
int WorldTrade_LevelTermGet(int min, int max, int tblSelect);
void WorldTrade_CountryCodeSet(WorldTradeWork *wk, int countryCode);
int WorldTrade_NationSortListNumGet(int start, int *number);
int WorldTrade_NationSortListMake(ListMenuOption **menulist, MsgData *countryNameManager, int start);
void WorldTrade_SelectListPosInit(WorldTradeSelectListPos *slp);
void WorldTrade_SelectNameListBackup(WorldTradeSelectListPos *slp, int head, int list, int pos);
// The number of countries in the list
extern const u32 WorldTrade_CountryListNum;
extern const u32 WorldTrade_SexStringTable[];

// worldtrade_enter.c
int WorldTrade_Enter_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Enter_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Enter_End(WorldTradeWork *wk, int seq);
void Enter_MessagePrint(WorldTradeWork *wk, MsgData *msgManager, int msgNo, int wait, u16 dat);
void Enter_MessagePrintNoStream(WorldTradeWork *wk, MsgData *msgManager, int msgNo, int wait, u16 dat);
// Print a string at x, or centered for flag 1 or right-aligned for flag 2
void WorldTrade_SysPrint(BmpWin *win, StrBuf *str, int x, int y, int flag, u16 color, WorldTradePrint *print);
void WorldTrade_TouchPrint(BmpWin *win, StrBuf *str, int x, int y, int flag, u16 color, WorldTradePrint *print);
void WorldTrade_ExplainPrint(BmpWin *win, MsgData *msgManager, int no, WorldTradePrint *print);
void WorldTrade_WifiIconAdd(WorldTradeWork *wk);

// worldtrade_input.c
WorldTradeInputWork *WorldTrade_Input_Init(WorldTradeInputHeader *header, int frame, int situation);
void WorldTrade_Input_Start(WorldTradeInputWork *wk, int type);
void WorldTrade_Input_Exit(WorldTradeInputWork *wk);
// The value chosen, or -1 while the input runs or -2 when it was cancelled
u32 WorldTrade_Input_Main(WorldTradeInputWork *wk);

// worldtrade_mypoke.c
int WorldTrade_MyPoke_Init(WorldTradeWork *wk, int seq);
int WorldTrade_MyPoke_Main(WorldTradeWork *wk, int seq);
int WorldTrade_MyPoke_End(WorldTradeWork *wk, int seq);
// Prints a Pokémon's nickname, gender, species, level and item into seven windows
void WorldTrade_MyPokeInfoPrint(MsgData *msgManager, MsgData *monsNameManager, WordSet *wordSet, BmpWin **win,
                                BoxPkm *pkm, Dpw_Tr_PokemonDataSimple *post, WorldTradePrint *print);
// Prints the Pokémon's owner and its original trainer
void WorldTrade_PokeInfoPrint2(MsgData *msgManager, BmpWin **win, u16 *name, PartyPkm *pkm, BmpWin **oyaWin,
                               WorldTradePrint *print);
// Uploads the Pokémon's front sprite to the main screen's OBJ characters
void WorldTrade_TransPokeGraphic(PartyPkm *pkm);

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
void func_ov214_021debb0(WorldTradeWork *wk);
void func_ov214_021debe0(WorldTradeWork *wk);

// worldtrade_title.c
int WorldTrade_Title_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Title_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Title_End(WorldTradeWork *wk, int seq);
void func_ov214_021dee54(WorldTradeWork *wk, int a1, int a2);
void func_ov214_021def50(WorldTradeWork *wk);
void func_ov214_021df920(WorldTradeWork *wk);
void func_ov214_021df9a0(WorldTradeWork *wk);
void func_ov214_021dfa18(WorldTradeWork *wk, int explain);

// worldtrade_upload.c
int WorldTrade_Upload_Init(WorldTradeWork *wk, int seq);
int WorldTrade_Upload_Main(WorldTradeWork *wk, int seq);
int WorldTrade_Upload_End(WorldTradeWork *wk, int seq);

// worldtrade_adapter.c
void func_ov214_021e14e0(WordSet *wordSet, u32 index, BoxPkm *pkm);
PartyPkm *func_ov214_021e1504(HeapID heapId);
void func_ov214_021e1528(PartyPkm *src, PartyPkm *dest);
// Clears a window from the screen, now or at the next VBlank
void func_ov214_021e1540(BmpWin *win, int mode);
StrBuf *func_ov214_021e156c(WordSet *wordSet, MsgData *msgData, u32 msgNo, HeapID heapId);
// The width of a string in the print's font
int func_ov214_021e15c0(WorldTradePrint *print, u8 font, StrBuf *str, int spacing);
void func_ov214_021e159c(BoxPkm *pkm, PartyPkm *dest);
void func_ov214_021e15d4(WorldTradePrint *print, TrainerDataSave *config);
void func_ov214_021e1640(WorldTradePrint *print);
void func_ov214_021e166c(WorldTradePrint *print);
BOOL func_ov214_021e173c(WorldTradePrint *print);
void func_ov214_021e1754(BmpWin *win, int x, StrBuf *str, int y, int a4, WorldTradePrint *print);
// The same through the message stream, at the player's text speed
void func_ov214_021e1774(BmpWin *win, int a1, StrBuf *str, int x, int y, WorldTradePrint *print);
void func_ov214_021e17c4(BmpWin *win, int a1, StrBuf *str, int x, int y, int a5, u16 color, WorldTradePrint *print);
void func_ov214_021e1840(WorldTradePrint *print);
WorldTradeNumFont *func_ov214_021e1874(u32 a0, u32 a1, u32 a2, HeapID heapId);
void func_ov214_021e18d8(WorldTradeNumFont *numFont);
void func_ov214_021e18fc(WorldTradeNumFont *numFont);
// Prints a number of digits at x and y of a window
void func_ov214_021e1954(WorldTradeNumFont *numFont, int num, int digits, int dispType, BmpWin *win, int x, int y);
// Prints the slash between two numbers
void func_ov214_021e1a28(WorldTradeNumFont *numFont, int a1, BmpWin *win, int x, int y);

#endif // POKEBW2_OV214_WORLDTRADE_LOCAL_H
