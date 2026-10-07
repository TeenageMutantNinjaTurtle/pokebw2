#ifndef POKEBW2_APP_UNOVA_LINK_H
#define POKEBW2_APP_UNOVA_LINK_H

#include "types.h"
#include "gfl/clact.h"
#include "gfl/heap.h"
#include "gfl/msg.h"
#include "gfl/proc.h"
#include "gfl/str.h"
#include "nitro/fx.h"
#include "save/player_info.h"
#include "struct_decls.h"
#include "system/gf_font.h"
#include "system/printsys.h"
#include "system/wordset.h"

// Unova Link, overlay 332: the Key System, which exchanges keys with another Black 2 or White 2, Memory Link, which
// reads a Black or White save, and the Nintendo 3DS Link with Pokémon Dream Radar. None of these names is swan's.
// The ROM names every file but key_system_flow.c, whose name is a guess from the functions around it, and
// data_convert_flow.c's first two functions, which only follow from the file order

typedef struct {
    // UNOVA_LINK_MODE_*
    u32 mode;
    GameData *gameData;
    // 1 in Black 2 and 0 in White 2
    u32 unk08;
} UnovaLinkParam;

// Started by the game clear event, or from the start menu without a parameter
#define UNOVA_LINK_MODE_GAME_CLEAR 0
#define UNOVA_LINK_MODE_START_MENU 1

extern const GameProcFunctions UNOVA_LINK_PROC_FUNCTIONS;

typedef struct KeySystemWork KeySystemWork;
typedef struct KeySystemSeq KeySystemSeq;
typedef struct KeySystemScene KeySystemScene;
typedef struct KeySystemGraphic KeySystemGraphic;
typedef struct KeySystemMsgWin KeySystemMsgWin;
typedef struct KeySystemMenu KeySystemMenu;
typedef struct KeySystemList KeySystemList;
typedef struct KeySystemNet KeySystemNet;
typedef struct KeySystemMsgWinGroup KeySystemMsgWinGroup;
typedef struct KeySystemOamText KeySystemOamText;
typedef struct KeySystemScrollList KeySystemScrollList;
typedef struct KeySystemParticle KeySystemParticle;

// A step of the sequence, called each frame with its own state
typedef void (*KeySystemSeqFunc)(KeySystemSeq *seq, int *state, void *work);

// A scene: a screen that is set up, runs until main returns TRUE, and is torn down
typedef struct {
    void (*init)(void *work, HeapID heapId);
    BOOL (*main)(void *work);
    void (*exit)(void *work);
    void (*free)(void *work);
} KeySystemSceneFuncs;

// The palettes the BG fades between
#define KEY_SYSTEM_BG_PALETTE_COUNT 5

// The BG's palette fades, from one of its palettes to another
enum {
    KEY_SYSTEM_BG_FADE_NONE,
    KEY_SYSTEM_BG_FADE_0_TO_1,
    KEY_SYSTEM_BG_FADE_0_TO_2,
    KEY_SYSTEM_BG_FADE_1_TO_0,
    KEY_SYSTEM_BG_FADE_2_TO_0,
    KEY_SYSTEM_BG_FADE_3_TO_0,
    KEY_SYSTEM_BG_FADE_0_TO_3,
    KEY_SYSTEM_BG_FADE_4_TO_3,
    KEY_SYSTEM_BG_FADE_3_TO_4,
    KEY_SYSTEM_BG_FADE_0,
};

// The scrolling BG and its palette fades
typedef struct KeySystemBG KeySystemBG;

#define KEY_SYSTEM_ACTOR_COUNT 25

// The cell actors and their resources
typedef struct {
    // The palette, characters and cell animations
    u32 resources[3];
    ClActor *actors[KEY_SYSTEM_ACTOR_COUNT];
    ClActUnit *unit;
} KeySystemClAct;

#define KEY_SYSTEM_TAG_COUNT 5

// A value kept under a three-letter tag, such as the cursor of a menu
typedef struct {
    u32 value;
    char tag[4];
} KeySystemTag;

// A list of windows to choose from, as KeySystemList_Create creates it
typedef struct {
    u32 msgId;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} KeySystemListItem;

#define KEY_SYSTEM_LIST_MAX 4

typedef struct {
    u32 bg;
    u32 unk04;
    u32 frameChar;
    u32 palette;
    MsgData *msgData;
    Font *font;
    u32 count;
    u32 cursor;
    KeySystemListItem items[KEY_SYSTEM_LIST_MAX];
    // Called with the index of an item, when it is chosen
    int (*select)(int index, void *arg);
    void *arg;
} KeySystemListSetup;

// A menu of choices, as KeySystemMenu_Create creates it
typedef struct {
    MsgData *msgData;
    Font *font;
    PrintQueue *printQueue;
    u32 msgIds[4];
    u32 count;
    u16 bg;
    u16 palette;
    u16 framePalette;
    u16 frameChar;
    // Whether B cancels
    BOOL cancelable;
    // What B chooses, and where the cursor starts
    u16 cancelValue;
    u16 cursor;
} KeySystemMenuSetup;

#define KEY_SYSTEM_KEY_COUNT 5

// The keys of a game, which two games exchange
typedef struct {
    BOOL unlocked[KEY_SYSTEM_KEY_COUNT];
    BOOL enabled[KEY_SYSTEM_KEY_COUNT];
    u32 version;
} KeySystemKeyState;

// Whether a game has a save, and its player
typedef struct {
    BOOL hasSave;
    PlayerInfo player;
} KeySystemSaveInfo;

// The list of keys to choose from
typedef struct KeySystemKeySelect {
    GameData *gameData;
    KeySystemList **list;
    KeySystemClAct *clact;
    KeyInfoSave *keyInfo;
    void (*setup)(struct KeySystemKeySelect *keySelect, KeySystemListSetup *setup);
    int (*select)(int index, struct KeySystemKeySelect *keySelect);
    int result;
    int index;
} KeySystemKeySelect;

// A position in pixels
typedef struct {
    s32 x;
    s32 y;
} KeySystemPos;

// A straight move over a number of frames
typedef struct {
    KeySystemPos pos;
    KeySystemPos start;
    KeySystemPos end;
    fx32 stepX;
    fx32 stepY;
    int frame;
    int frames;
} KeySystemTween;

// A move in 3D that speeds up
typedef struct {
    VecFx32 pos;
    VecFx32 start;
    VecFx32 end;
    VecFx32 dir;
    fx32 speed;
    fx32 accel;
    int frame;
    int frames;
} KeySystemAccelMove;

// The animation of a key being unlocked
typedef struct KeySystemKeyAnim {
    KeySystemMsgWin *msgWin;
    KeySystemClAct *clact;
    ClActor *keyActor;
    ClActor *actor10;
    ClActor *actor12;
    ClActor *actor9;
    KeySystemOamText *text;
    BmpOamSys *oamSys;
    int state;
    int timer;
    u16 msgId;
    StrBuf *str;
    u32 key;
    BOOL active;
    MsgData *msgData;
    Font *font;
    KeySystemTween tween;
    KeySystemAccelMove move;
    u32 frame;
    BOOL (*func)(struct KeySystemKeyAnim *anim);
} KeySystemKeyAnim;

struct KeySystemWork {
    KeySystemScene *scene;
    KeySystemSeq *seq;
    KeySystemGraphic *graphic;
    UnovaLinkParam *param;
    // The message window on the upper screen
    KeySystemMsgWin *msgWin;
    // The window on the lower screen
    KeySystemMsgWin *infoWin;
    // The title of the upper screen
    KeySystemMsgWin *titleWin;
    KeySystemList *list;
    KeySystemMenu *menu;
    KeySystemMsgWinGroup *msgWinGroup;
    KeySystemScrollList *scrollList;
    Font *font;
    PrintQueue *printQueue;
    MsgData *msgData;
    WordSet *wordSet;
    KeySystemBG *bg;
    KeySystemClAct clact;
    KeySystemTag tags[KEY_SYSTEM_TAG_COUNT];
    // key_system_flow.c's
    KeySystemKeySelect keySelect;
    // ov331's work, with the other save
    void *ov331Work;
    KeyInfoSave *keyInfo;
    void *unk104;
    // data_convert_flow.c's
    void *wbData;
    KeySystemNet *net;
    // key_system_flow.c's: the keys and saves of this game and of the other
    KeySystemKeyState keys;
    KeySystemKeyState partnerKeys;
    KeySystemSaveInfo saveInfo;
    KeySystemSaveInfo partnerSaveInfo;
    KeySystemKeyAnim keyAnim;
    // cygnus_flow.c's
    void *cygnusActors;
    KeySystemParticle *particle;
    void *cygnusWork;
    void *cygnusGraphic;
    // The handle of the sounds that Unova Link loads ahead
    u32 preloadedSeqs;
    // The last choice of a list or menu, or the result of an exchange
    u32 choice;
    u32 timer;
    StrBuf *strBuf;
    // Whether B can't cancel the exchange
    BOOL noCancel;
    BOOL unk284;
    // data_convert_flow.c's
    BOOL loggedIn;
    BOOL transferResult;
    StrBuf *enteredCode;
    StrBuf *msgStrs[2];
    void *subProcParam;
    void *wbSave;
    u8 loginBuffer[0x174];
};

// key_system_main.c
void KeySystem_SeqFadeIn(KeySystemSeq *seq, int *state, void *work);
void KeySystem_SeqFadeOut(KeySystemSeq *seq, int *state, void *work);
// The same as KeySystem_SeqFadeIn, and unused
void KeySystem_SeqFadeInUnused(KeySystemSeq *seq, int *state, void *work);
// Fades both screens out to white
void KeySystem_SeqFadeOutWhite(KeySystemSeq *seq, int *state, void *work);
void KeySystem_SeqEndScene(KeySystemSeq *seq, int *state, void *work);
// Says that wireless communications are off
void KeySystem_SeqWirelessOff(KeySystemSeq *seq, int *state, void *work);
void KeySystemBG_StartFade(KeySystemBG *bg, u32 fade, u16 duration);
void KeySystemBG_LoadScreen(KeySystemBG *bg, u8 bgId, u32 screen);
ClActor *KeySystemClAct_Create(KeySystemClAct *clact, u32 id, HeapID heapId);
void KeySystemClAct_Delete(KeySystemClAct *clact, u32 id);
ClActor *KeySystemClAct_GetActor(KeySystemClAct *clact, u32 id);
u32 KeySystemClAct_GetResource(KeySystemClAct *clact, u32 id);
ClActUnit *KeySystemClAct_GetUnit(KeySystemClAct *clact);
void KeySystemTags_Set(KeySystemTag *tags, const char *tag, u32 value);
void KeySystemTags_Remove(KeySystemTag *tags, const char *tag);
BOOL KeySystemTags_Has(KeySystemTag *tags, const char *tag);
u32 KeySystemTags_Get(KeySystemTag *tags, const char *tag);
void KeySystem_Setup(KeySystemWork *wk, HeapID heapId);
void KeySystem_Teardown(KeySystemWork *wk, BOOL keepSounds);
void KeySystem_CreateMsgWin(KeySystemWork *wk, HeapID heapId);
void KeySystem_FreeMsgWin(KeySystemWork *wk);
void KeySystem_CreateMsgWinOn(KeySystemWork *wk, u8 bg, HeapID heapId);
void KeySystem_FreeMsgWinOn(KeySystemWork *wk, u32 bg);
void KeySystem_FreeTitleWin(KeySystemWork *wk);
void KeySystem_CreateTitleWin(KeySystemWork *wk, u8 width, HeapID heapId);
void KeySystem_CreateInfoWin(KeySystemWork *wk, HeapID heapId);
void KeySystem_FreeInfoWin(KeySystemWork *wk);
void KeySystem_CreateYesNoMenu(KeySystemWork *wk, HeapID heapId);
void KeySystem_FreeMenu(KeySystemWork *wk);
void KeySystem_SeqTop(KeySystemSeq *seq, int *state, void *work);

// key_system_graphic.c
// What KeySystemGraphic_Set3D does
#define KEY_SYSTEM_GRAPHIC_3D_ON 0
#define KEY_SYSTEM_GRAPHIC_3D_OFF 1

KeySystemGraphic *KeySystemGraphic_Create(u32 layout, HeapID heapId);
void KeySystemGraphic_Free(KeySystemGraphic *graphic);
void KeySystemGraphic_Update(KeySystemGraphic *graphic);
void KeySystemGraphic_Begin3D(KeySystemGraphic *graphic);
void KeySystemGraphic_End3D(KeySystemGraphic *graphic);
ClActUnit *KeySystemGraphic_GetClActUnit(KeySystemGraphic *graphic);
void KeySystemGraphic_Set3D(KeySystemGraphic *graphic, u32 mode);

// key_system_util.c
// How a KeySystemMsgWin prints: all at once through the print queue, or a character at a time, with the cursor and at
// the text speed, at the fast speed or without the cursor
enum {
    KEY_SYSTEM_MSG_PRINT,
    KEY_SYSTEM_MSG_STREAM,
    KEY_SYSTEM_MSG_PRINT_WAIT_ICON,
    KEY_SYSTEM_MSG_STREAM_FAST,
    KEY_SYSTEM_MSG_STREAM_NO_CURSOR,
    KEY_SYSTEM_MSG_IDLE,
};

// Where KeySystemMsgWin_SetPos puts the text in its window
enum {
    KEY_SYSTEM_ALIGN_TOP_LEFT,
    KEY_SYSTEM_ALIGN_CENTER,
    KEY_SYSTEM_ALIGN_CENTER_Y,
    KEY_SYSTEM_ALIGN_RIGHT,
};

// A window of KeySystemMsgWinGroup_Create
typedef struct {
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u32 msgId;
} KeySystemMsgWinTemplate;

#define KEY_SYSTEM_SCROLL_LIST_MAX 12

// A list that scrolls through ov139's list, with an actor for each item
typedef struct {
    MsgData *msgData;
    Font *font;
    ClActor *arrowDown;
    ClActor *arrowUp;
    u32 msgIds[KEY_SYSTEM_SCROLL_LIST_MAX];
    u32 values[KEY_SYSTEM_SCROLL_LIST_MAX];
    ClActor *icons[KEY_SYSTEM_SCROLL_LIST_MAX];
    u32 count;
    u16 bg;
    u16 palette;
    u16 unkA8;
    u16 unkAA;
    u16 unkAC;
} KeySystemScrollListSetup;

KeySystemMsgWin *KeySystemMsgWin_Create(u16 bg, u16 x, u16 y, u16 width, u16 height, u16 palette, Font *font,
                                        HeapID heapId);
void KeySystemMsgWin_Free(KeySystemMsgWin *win);
void KeySystemMsgWin_Update(KeySystemMsgWin *win);
// Prints a message or a string, KEY_SYSTEM_MSG_*
void KeySystemMsgWin_PrintMsg(KeySystemMsgWin *win, MsgData *msgData, u32 msgId, u32 mode);
void KeySystemMsgWin_PrintStr(KeySystemMsgWin *win, const StrBuf *str, u32 mode);
void KeySystemMsgWin_SetColor(KeySystemMsgWin *win, u16 color);
void KeySystemMsgWin_SetPos(KeySystemMsgWin *win, s32 x, s32 y, u32 align);
BOOL KeySystemMsgWin_IsDone(KeySystemMsgWin *win);
void KeySystemMsgWin_StopWaitIcon(KeySystemMsgWin *win);
void KeySystemMsgWin_DrawFrame(KeySystemMsgWin *win, u16 frameChar, u8 framePalette);
void KeySystemMsgWin_Clear(KeySystemMsgWin *win);
void KeySystemMsgWin_ClearFrame(KeySystemMsgWin *win);
void KeySystemMsgWin_CreateCursor(KeySystemMsgWin *win);
KeySystemMsgWinGroup *KeySystemMsgWinGroup_Create(const KeySystemMsgWinTemplate *templates, u32 count, u16 bg,
                                                  u16 palette, Font *font, MsgData *msgData, HeapID heapId);
void KeySystemMsgWinGroup_Free(KeySystemMsgWinGroup *group);
void KeySystemMsgWinGroup_Update(KeySystemMsgWinGroup *group);
BOOL KeySystemMsgWinGroup_IsDone(KeySystemMsgWinGroup *group);
KeySystemMenu *KeySystemMenu_Create(const KeySystemMenuSetup *setup, HeapID heapId);
KeySystemMenu *KeySystemMenu_CreateAt(const KeySystemMenuSetup *setup, u8 x, u8 y, u8 width, u8 height, HeapID heapId);
void KeySystemMenu_Free(KeySystemMenu *menu);
// Returns the chosen item, the cancel value or BMPMENULIST_NULL
s32 KeySystemMenu_Update(KeySystemMenu *menu);
BOOL KeySystemMenu_UpdatePrint(KeySystemMenu *menu);
KeySystemList *KeySystemList_Create(const KeySystemListSetup *setup, HeapID heapId);
void KeySystemList_Free(KeySystemList *list);
void KeySystemList_Update(KeySystemList *list);
void KeySystemList_Draw(KeySystemList *list);
BOOL KeySystemList_IsPrinted(KeySystemList *list);
void KeySystemList_Reset(KeySystemList *list);
BOOL KeySystemList_IsDecided(KeySystemList *list);
u32 KeySystemList_GetCursor(KeySystemList *list);
BOOL KeySystemList_IsChanged(KeySystemList *list);
const KeySystemListSetup *KeySystemList_GetSetup(KeySystemList *list);
KeySystemSeq *KeySystemSeq_Create(u32 depth, void *work, KeySystemSeqFunc func, HeapID heapId);
void KeySystemSeq_Free(KeySystemSeq *seq);
void KeySystemSeq_Run(KeySystemSeq *seq);
BOOL KeySystemSeq_IsEmpty(KeySystemSeq *seq);
void KeySystemSeq_Set(KeySystemSeq *seq, KeySystemSeqFunc func);
void KeySystemSeq_Push(KeySystemSeq *seq, KeySystemSeqFunc func);
// Ends the sequence
void KeySystemSeq_Reset(KeySystemSeq *seq);
void KeySystemSeq_Pop(KeySystemSeq *seq);
BOOL KeySystemSeq_IsCurrent(KeySystemSeq *seq, KeySystemSeqFunc func);
void KeySystemSeq_AddState(KeySystemSeq *seq, int add);
void KeySystemSeq_PopTo(KeySystemSeq *seq, KeySystemSeqFunc func);
KeySystemScene *KeySystemScene_Create(void *work, HeapID heapId);
void KeySystemScene_Free(KeySystemScene *scene);
void KeySystemScene_Update(KeySystemScene *scene);
void KeySystemScene_Start(KeySystemScene *scene, const KeySystemSceneFuncs *funcs, HeapID heapId);
void KeySystemScene_RequestEnd(KeySystemScene *scene);
BOOL KeySystemScene_IsIdle(KeySystemScene *scene);
void KeySystemScene_Abort(KeySystemScene *scene);
KeySystemOamText *KeySystemOamText_Create(const ClActorSetup *setup, u16 width, u16 height, u32 palette,
                                          u8 paletteOffset, u32 surface, BmpOamSys *oamSys, HeapID heapId);
void KeySystemOamText_Free(KeySystemOamText *text);
void KeySystemOamText_Print(KeySystemOamText *text, MsgData *msgData, u32 msgId, Font *font);
void KeySystemOamText_SetColor(KeySystemOamText *text, u16 color);
void KeySystemOamText_Update(KeySystemOamText *text);
BOOL KeySystemOamText_IsDone(KeySystemOamText *text);
BmpOamActor *KeySystemOamText_GetActor(KeySystemOamText *text);
void KeySystemTween_Init(KeySystemTween *tween, const KeySystemPos *start, const KeySystemPos *end, int frames);
// Returns TRUE once the move is done
BOOL KeySystemTween_Update(KeySystemTween *tween);
void KeySystemTween_GetPos(const KeySystemTween *tween, ClActorPos *pos);
void KeySystemAccelMove_Init(KeySystemAccelMove *move, const KeySystemPos *start, const KeySystemPos *end, fx32 speed,
                             int frames);
BOOL KeySystemAccelMove_Update(KeySystemAccelMove *move);
void KeySystemAccelMove_GetPos(const KeySystemAccelMove *move, ClActorPos *pos);
KeySystemScrollList *KeySystemScrollList_Create(const KeySystemScrollListSetup *setup, HeapID heapId);
void KeySystemScrollList_Free(KeySystemScrollList *list);
// Returns the value of the chosen item, or SCROLL_LIST_NONE
u32 KeySystemScrollList_Update(KeySystemScrollList *list);
BOOL KeySystemScrollList_Start(KeySystemScrollList *list);
void KeySystemScrollList_GetPos(KeySystemScrollList *list, u32 *cursor, u32 *top);
KeySystemParticle *KeySystemParticle_Create(HeapID heapId);
void KeySystemParticle_Free(KeySystemParticle *particle);
void KeySystemParticle_Load(KeySystemParticle *particle, u32 arcId, u32 fileId, HeapID heapId);
void KeySystemParticle_Emit(KeySystemParticle *particle, int resourceId);
// Blends two palettes by the cosine of angle and uploads the result
void KeySystem_BlendPalette(u32 type, u16 *dest, u16 angle, u32 palette, const u16 *from, const u16 *to);
// Loads a message, formatted with the word set
StrBuf *KeySystem_LoadFormattedStr(WordSet *wordSet, MsgData *msgData, u32 msgId, HeapID heapId);

// key_system_net.c
// The connection a KeySystemNet runs
enum {
    KEY_SYSTEM_NET_MODE_NONE,
    KEY_SYSTEM_NET_MODE_WIRELESS,
    KEY_SYSTEM_NET_MODE_OV181,
    KEY_SYSTEM_NET_MODE_WIFI,
    KEY_SYSTEM_NET_MODE_COUNT,
};

// What KeySystemNet_Request starts
enum {
    KEY_SYSTEM_NET_REQUEST_CONNECT,
    KEY_SYSTEM_NET_REQUEST_DISCONNECT,
    KEY_SYSTEM_NET_REQUEST_CANCEL,
    KEY_SYSTEM_NET_REQUEST_SEND,
    KEY_SYSTEM_NET_REQUEST_SYNC,
    KEY_SYSTEM_NET_REQUEST_OV181_START,
    KEY_SYSTEM_NET_REQUEST_OV181_END,
    KEY_SYSTEM_NET_REQUEST_WIFI_POST,
    KEY_SYSTEM_NET_REQUEST_WIFI_GET,
    KEY_SYSTEM_NET_REQUEST_COUNT,
};

// What KeySystemNet_GetState returns: the step that runs
enum {
    KEY_SYSTEM_NET_STATE_IDLE,
    KEY_SYSTEM_NET_STATE_CONNECTING,
    KEY_SYSTEM_NET_STATE_DISCONNECTING,
    KEY_SYSTEM_NET_STATE_CONNECTED,
    KEY_SYSTEM_NET_STATE_SENDING,
    KEY_SYSTEM_NET_STATE_SYNCING,
    KEY_SYSTEM_NET_STATE_CANCELING,
    KEY_SYSTEM_NET_STATE_OV181,
    KEY_SYSTEM_NET_STATE_OV181_END,
    KEY_SYSTEM_NET_STATE_WIFI_POST,
    KEY_SYSTEM_NET_STATE_WIFI_GET,
    KEY_SYSTEM_NET_STATE_COUNT,
};

// What KeySystemNet_CheckError returns
#define KEY_SYSTEM_NET_ERROR_NONE 0
#define KEY_SYSTEM_NET_ERROR 2

// The parameters and results of a request
typedef union {
    struct {
        const void *data;
        u32 size;
    } send;
    // Called when the wireless connection ends
    struct {
        void *arg;
        void (*func)(void *arg);
    } callback;
    struct {
        u32 a;
        u32 b;
        u32 result;
    } ov181;
    struct {
        BOOL done;
        u32 a;
        u32 b;
    } ov181End;
    struct {
        const void *data;
        u32 result;
        u32 a;
        u32 b;
    } wifi;
    struct {
        u32 value;
        u32 result;
    } wifiGet;
    u8 raw[0x100];
} KeySystemNetRequest;

KeySystemNet *KeySystemNet_Create(GameData **gameData, HeapID heapId);
void KeySystemNet_Free(KeySystemNet *net);
void KeySystemNet_Update(KeySystemNet *net);
void KeySystemNet_SetMode(KeySystemNet *net, u32 mode);
void KeySystemNet_Request(KeySystemNet *net, u32 request, const KeySystemNetRequest *params);
u32 KeySystemNet_GetState(KeySystemNet *net);
BOOL KeySystemNet_GetReceived(KeySystemNet *net, void *dest, u32 size);
u32 KeySystemNet_CheckError(KeySystemNet *net);
// Ends the connection after an error
void KeySystemNet_Reset(KeySystemNet *net);
void KeySystemNet_SetBuffer(KeySystemNet *net, void *buffer);
void KeySystemNet_SetNoErrorCheck(KeySystemNet *net, BOOL noErrorCheck);
void KeySystemNet_SetErrorCallback(KeySystemNet *net, void (*callback)(void *work), void *work);
// The request's parameters and results
KeySystemNetRequest *KeySystemNet_GetRequest(KeySystemNet *net);

// key_system_flow.c (a guessed name)
void func_ov332_021c2b18(KeySystemWork *wk, HeapID heapId);
void func_ov332_021c2b5c(KeySystemWork *wk);
void func_ov332_021c2b80(KeySystemSeq *seq, int *state, void *work);
void func_ov332_021c2cd4(KeySystemSeq *seq, int *state, void *work);

// data_convert_flow.c
void func_ov332_021c53dc(KeySystemWork *wk, HeapID heapId);
void func_ov332_021c53e0(KeySystemSeq *seq, int *state, void *work);

// cygnus_flow.c
void func_ov332_021c7028(KeySystemWork *wk, HeapID heapId);
void func_ov332_021c704c(KeySystemWork *wk);
void func_ov332_021c7064(KeySystemSeq *seq, int *state, void *work);

#endif // POKEBW2_APP_UNOVA_LINK_H
