#ifndef POKEBW2_APP_POKELIST_H
#define POKEBW2_APP_POKELIST_H

#include "types.h"
#include "field/player_action.h"
#include "gfl/arc_util.h"
#include "gfl/clact.h"
#include "gfl/g3d.h"
#include "gfl/heap.h"
#include "gfl/particle.h"
#include "gfl/proc.h"
#include "struct_decls.h"
#include "system/printsys.h"

// Overlay 165's party list, which EventPokeList_Create runs, showing overlay 207's summary screen for a Pokémon
// when asked to. Its files: pokelist.c (the proc), plist_sys.c (the screen), plist_plate.c (a Pokémon's plate),
// plist_message.c, plist_menu.c, plist_item.c (using an item), plist_battle.c (the partners' teams and the timer of
// a link battle's team selection), plist_demo.c (form changes) and status_rcv.c (an item's effect on a Pokémon)

// A partner's team, shown beside the player's in a multi battle's selection
typedef struct {
    PokeParty *party;
    u16 *name;
    u8 gender;
} PokeListPartnerParam;

// 0xa8 bytes, which func_02034bd8 fills in
typedef struct {
    PokeParty *party;
    BagSave *bag;
    void *unk08;
    TrainerDataSave *trainerData;
    void *unk10;
    Regulation *regulation;
    void *unk18;
    PokeDexSave *pokedex;
    void *shortcut;
    TrainerCardSave *trainerCard;
    PlayerInfo *playerInfo;
    PlayerActionPossibilities action;
    u16 zoneId;
    // What the screen is for, func_02034bd8's a2
    u32 mode;
    u32 unk48;
    // The Pokémon whose summary to show, when result is 1
    u32 index;
    // 0 once the screen is done, and 1 to show a summary
    u32 result;
    u16 item;
    u16 move;
    // The move slot to teach the move to
    u8 moveSlot;
    // The party slots, from 1, of the Pokémon picked
    u8 picked[6];
    // Where to go on in the moves a Pokémon learns at its new level
    u32 learnIndex;
    u8 unk64[8];
    u16 unk6C;
    u8 unk6E;
    u8 season;
    // Seconds left to pick, counted down while timerEnabled is set
    u16 timeLeft;
    u8 unk72;
    u8 unk73;
    u32 partnerCount;
    PokeListPartnerParam partners[3];
    BOOL showPartners;
    BOOL timerEnabled;
    u8 battleMsg;
    // Whether key item 0x1e is registered to Y, and whether it is to be, once the screen is done
    u8 keyItemRegistered;
    u8 unkA6[2];
} PokeListParam;

#define POKELIST_PLATE_COUNT 6
#define POKELIST_CL_RES_COUNT 23

// The list's work, which every file of the overlay shares
struct PokeListWork {
    u16 heapId;
    TCB *vblankTask;
    BOOL touch;
    u8 state;
    // The state to go to once the wipe is done
    u8 nextState;
    u8 subState;
    u8 input;
    // Holds the glow of the selected plate
    BOOL glowPaused;
    BOOL showShortcutButtons;
    // The modes that the list rewrites at its start, and gives back at its end
    BOOL wasMode18;
    BOOL wasMode19;
    BOOL wasMode1A;
    BOOL playHealSe;
    BOOL unk28;
    BOOL wasMode1B;
    // 0 to 5 for the plates, then the buttons
    s32 cursorPos;
    // 9 when nothing is selected
    s32 selectPos;
    s32 selectPos2;
    PartyPkm *pkm;
    u32 menuItem;
    // The palettes that glow, as loaded, and as blended
    u16 baseColors[3][16];
    u16 colors[3][16];
    u8 flashTimer;
    u16 glowAngle;
    u8 unk108;
    u8 enteredCount;
    void *buttons[2];
    u16 unk114;
    u16 unk116;
    u8 waitTimer;
    BOOL decided;
    u16 prevHp;
    s8 hpStep;
    // Called once a plate's HP is done changing
    void (*hpDoneFunc)(PokeListWork *wk);
    // The stats before a level up
    u16 prevStats[6];
    BmpWin *statsWindow;
    MsgData *msgData;
    Font *font;
    Font *smallFont;
    PrintQueue *printQueue;
    BOOL msgWaitInput;
    // Called once a message is done
    void (*msgDoneFunc)(PokeListWork *wk);
    // Called with the item picked in the menu
    void (*menuFunc)(PokeListWork *wk, u32 item);
    PokeListMessage *message;
    PokeListMenu *menu;
    void *plateScreenFile;
    NNSG2dScreenData *plateScreen;
    PokeListPlate *plates[POKELIST_PLATE_COUNT];
    // Palettes, then characters, then cell animations
    u32 clResources[POKELIST_CL_RES_COUNT];
    ClActUnit *actorUnit;
    ClActor *cursor;
    ClActor *subCursor;
    ClActor *exitButton;
    ClActor *shortcutButton;
    ClActor *shortcutMark;
    ClActor *pressedButton;
    ClActUnit *partnerUnit;
    PokeListPartner *partners[3];
    BmpWin *timerWindows[2];
    BOOL timerWindowDirty[2];
    u8 shownBattleMsg;
    u8 shownTime;
    u16 timerBaseColors[16];
    u16 timerColors[16];
    u16 timerBlink;
    BOOL timeUp;
    void *taskMenuRes;
    G3DCamera *camera;
    void *particleHeaps[2];
    ParticleSystem *particles[2];
    // The form change shown
    u32 demo;
    u8 demoTimer;
    u8 demoLength;
    u8 demoStep;
    u8 demoForm;
    u16 demoSe;
    u32 voice;
    BOOL unk284;
    u32 unk288;
    PokeListParam *param;
};

extern GameProcFunctions POKELIST_PROC_FUNCTIONS;

void func_02034bd8(PokeListParam *param, GameData *gameData, u32 a2, PokeParty *party);
// Allocates the parameters and fills them in with func_02034bd8
PokeListParam *func_02034c54(GameData *gameData, u32 a1, PokeParty *party, HeapID heapId);
GameEvent *EventPokeList_Create(GameSystem *gsys, Field *field, PokeListParam *param, void *summaryParam);

// plist_sys.c
BOOL PokeList_Init(PokeListWork *wk);
BOOL PokeList_Exit(PokeListWork *wk);
BOOL PokeList_Main(PokeListWork *wk);

#endif // POKEBW2_APP_POKELIST_H
