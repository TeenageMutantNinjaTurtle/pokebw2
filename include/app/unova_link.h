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

// A list of windows to choose from, as func_ov332_021c0dd4 creates it
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

// A menu of choices, as func_ov332_021c0c1c creates it
typedef struct {
    MsgData *msgData;
    Font *font;
    PrintQueue *printQueue;
    u32 msgIds[4];
    u32 count;
    u16 unk20;
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u32 unk28;
    u16 unk2c;
    u16 unk2e;
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

// A straight move over a number of frames
typedef struct {
    s32 x;
    s32 y;
    s32 startX;
    s32 startY;
    s32 endX;
    s32 endY;
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
    void *text;
    void *oamSys;
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
    void *unk24;
    void *scrollList;
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
    void *unk264;
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
KeySystemMsgWin *func_ov332_021c054c(u8 bg, u8 x, u8 y, u8 width, u16 height, u16 palette, Font *font, HeapID heapId);
void func_ov332_021c0604(KeySystemMsgWin *win);
void func_ov332_021c0654(KeySystemMsgWin *win);
void func_ov332_021c073c(KeySystemMsgWin *win, MsgData *msgData, u32 msgId, u32 a3);
void func_ov332_021c0758(KeySystemMsgWin *win, StrBuf *str, u32 a2);
void func_ov332_021c0770(KeySystemMsgWin *win, u16 color);
void func_ov332_021c0774(KeySystemMsgWin *win, u32 a1, u32 a2, u32 a3);
u16 func_ov332_021c095c(KeySystemMsgWin *win);
void func_ov332_021c0988(KeySystemMsgWin *win, u16 frameChar, u8 framePalette);
void func_ov332_021c09a0(KeySystemMsgWin *win);
void func_ov332_021c0bd4(void *a0);
KeySystemMenu *func_ov332_021c0c1c(const KeySystemMenuSetup *setup, HeapID heapId);
void func_ov332_021c0d50(KeySystemMenu *menu);
void func_ov332_021c0d9c(KeySystemMenu *menu);
KeySystemList *func_ov332_021c0dd4(const KeySystemListSetup *setup, HeapID heapId);
void func_ov332_021c0ee8(KeySystemList *list);
void func_ov332_021c0f10(KeySystemList *list);
void func_ov332_021c10e0(KeySystemList *list);
BOOL func_ov332_021c1140(KeySystemList *list);
BOOL func_ov332_021c1168(KeySystemList *list);
u32 func_ov332_021c119c(KeySystemList *list);
BOOL func_ov332_021c11a0(KeySystemList *list);
KeySystemSeq *KeySystemSeq_Create(u32 depth, void *work, KeySystemSeqFunc func, HeapID heapId);
void KeySystemSeq_Free(KeySystemSeq *seq);
void KeySystemSeq_Run(KeySystemSeq *seq);
BOOL KeySystemSeq_IsEmpty(KeySystemSeq *seq);
void KeySystemSeq_Set(KeySystemSeq *seq, KeySystemSeqFunc func);
void KeySystemSeq_Push(KeySystemSeq *seq, KeySystemSeqFunc func);
// Ends the sequence
void KeySystemSeq_Reset(KeySystemSeq *seq);
void KeySystemSeq_Pop(KeySystemSeq *seq);
void KeySystemSeq_PopTo(KeySystemSeq *seq, KeySystemSeqFunc func);
KeySystemScene *KeySystemScene_Create(void *work, HeapID heapId);
void KeySystemScene_Free(KeySystemScene *scene);
void KeySystemScene_Update(KeySystemScene *scene);
void KeySystemScene_Start(KeySystemScene *scene, const KeySystemSceneFuncs *funcs, HeapID heapId);
void KeySystemScene_RequestEnd(KeySystemScene *scene);
BOOL KeySystemScene_IsIdle(KeySystemScene *scene);
void KeySystemScene_Abort(KeySystemScene *scene);
void func_ov332_021c1cd4(u32 type, u16 *dest, u16 t, u32 offset, const u16 *from, const u16 *to);

// key_system_net.c
KeySystemNet *func_ov332_021c1dd0(GameData **gameData, HeapID heapId);
void func_ov332_021c1e14(KeySystemNet *net);
void func_ov332_021c1e30(KeySystemNet *net);
void func_ov332_021c1e54(KeySystemNet *net, u32 a1);
u32 func_ov332_021c2044(KeySystemNet *net);
void func_ov332_021c2110(KeySystemNet *net);

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
