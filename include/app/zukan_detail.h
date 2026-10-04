#ifndef POKEBW2_APP_ZUKAN_DETAIL_H
#define POKEBW2_APP_ZUKAN_DETAIL_H

#include "types.h"
#include "gfl/heap.h"
#include "gfl/overlay.h"
#include "gfl/proc.h"
#include "struct_decls.h"
#include "system/printsys.h"

// The Pokédex's detail screens, overlay 298: a Pokémon's info, its habitat map, its cry and its forms, with the bars
// at the top and bottom of the screens to switch between them. Overlay 302, the Pokédex's list, runs it
#define OVERLAY_ZUKAN_DETAIL OVERLAY_ID(298)

// The pages
enum {
    ZUKAN_DETAIL_PAGE_NONE,
    ZUKAN_DETAIL_PAGE_INFO,
    ZUKAN_DETAIL_PAGE_MAP,
    ZUKAN_DETAIL_PAGE_VOICE,
    ZUKAN_DETAIL_PAGE_FORM,
};

// What the screen returns to the list
enum {
    // The player picked a place on the habitat map
    ZUKAN_DETAIL_RESULT_PLACE,
    ZUKAN_DETAIL_RESULT_RETURN,
    ZUKAN_DETAIL_RESULT_CLOSE,
};

typedef struct {
    GameData *gameData;
    // The ZUKAN_DETAIL_PAGE_* to start on
    int page;
    // The Pokémon that the screen pages through, and where in the list it is
    const u16 *list;
    u16 count;
    u16 index;
    // A ZUKAN_DETAIL_RESULT_*
    int result;
    u32 mode;
    u16 unk18;
    // With ZUKAN_DETAIL_RESULT_PLACE
    u16 place;
} ZukanDetailParam;

extern const GameProcFunctions ZUKAN_DETAIL_PROC_FUNCTIONS;

typedef struct ZukanDetailProcSys ZukanDetailProcSys;
typedef struct ZukanDetailCommon ZukanDetailCommon;
typedef struct ZukanDetailBlend ZukanDetailBlend;
typedef struct ZukanDetailPalFade ZukanDetailPalFade;
typedef struct ZukanDetailBackground ZukanDetailBackground;
typedef struct ZukanDetailGraphic ZukanDetailGraphic;
typedef struct ZukanDetailTouchbar ZukanDetailTouchbar;
typedef struct ZukanDetailHeadbar ZukanDetailHeadbar;

// zukan_detail_procsys.c: runs one of the pages

typedef BOOL (*ZukanDetailProcFunc)(ZukanDetailProcSys *sys, int *seq, void *param, void *work,
                                    ZukanDetailCommon *common);
typedef void (*ZukanDetailProcCommandFunc)(ZukanDetailProcSys *sys, int *seq, void *param, void *work,
                                           ZukanDetailCommon *common, int command);
typedef void (*ZukanDetailProcDrawFunc)(ZukanDetailProcSys *sys, int *seq, void *param, void *work,
                                        ZukanDetailCommon *common);

typedef struct {
    ZukanDetailProcFunc init;
    ZukanDetailProcFunc main;
    ZukanDetailProcFunc exit;
    // Called every frame with the touch bar's command
    ZukanDetailProcCommandFunc command;
    ZukanDetailProcDrawFunc draw;
} ZukanDetailProcFuncs;

struct ZukanDetailProcSys {
    const ZukanDetailProcFuncs *funcs;
    int seq;
    int subSeq;
    void *param;
    void *work;
};

ZukanDetailProcSys *ZukanDetailProcSys_Create(const ZukanDetailProcFuncs *funcs, void *param, HeapID heapId);
void ZukanDetailProcSys_Free(ZukanDetailProcSys *sys);
// Returns TRUE once the page has exited
BOOL ZukanDetailProcSys_Main(ZukanDetailProcSys *sys, ZukanDetailCommon *common);
void ZukanDetailProcSys_Command(ZukanDetailProcSys *sys, ZukanDetailCommon *common, int command);
void ZukanDetailProcSys_Draw(ZukanDetailProcSys *sys, ZukanDetailCommon *common);
void *ZukanDetailProcSys_AllocWork(ZukanDetailProcSys *sys, u32 size, HeapID heapId);
void ZukanDetailProcSys_FreeWork(ZukanDetailProcSys *sys);

// zukan_detail_common.c: what the pages share

struct ZukanDetailCommon {
    GameData *gameData;
    ZukanDetailGraphic *graphic;
    Font *font;
    PrintQueue *printQueue;
    ZukanDetailTouchbar *touchbar;
    ZukanDetailHeadbar *headbar;
    // The Pokémon that the screen pages through, and where in the list it is
    const u16 *list;
    u16 count;
    u16 *index;
};

ZukanDetailCommon *ZukanDetailCommon_Create(HeapID heapId, GameData *gameData, ZukanDetailGraphic *graphic, Font *font,
                                            PrintQueue *printQueue, ZukanDetailTouchbar *touchbar,
                                            ZukanDetailHeadbar *headbar, const u16 *list, u16 count, u16 *index);
void ZukanDetailCommon_Free(ZukanDetailCommon *common);
GameData *ZukanDetailCommon_GetGameData(ZukanDetailCommon *common);
ZukanDetailGraphic *ZukanDetailCommon_GetGraphic(ZukanDetailCommon *common);
Font *ZukanDetailCommon_GetFont(ZukanDetailCommon *common);
PrintQueue *ZukanDetailCommon_GetPrintQueue(ZukanDetailCommon *common);
ZukanDetailTouchbar *ZukanDetailCommon_GetTouchbar(ZukanDetailCommon *common);
ZukanDetailHeadbar *ZukanDetailCommon_GetHeadbar(ZukanDetailCommon *common);
u16 ZukanDetailCommon_GetCount(ZukanDetailCommon *common);
u16 ZukanDetailCommon_GetSpecies(ZukanDetailCommon *common);
void ZukanDetailCommon_GoNext(ZukanDetailCommon *common);
void ZukanDetailCommon_GoPrev(ZukanDetailCommon *common);

// A screen's blending, which fades layers in or out by 2 of 16 every frame
struct ZukanDetailBlend {
    u32 plane1;
    u32 plane2;
    int ev;
    int step;
    int wait;
};

ZukanDetailBlend *ZukanDetailBlend_Create(HeapID heapId);
void ZukanDetailBlend_Free(ZukanDetailBlend *blend);
void ZukanDetailBlend_Update(ZukanDetailBlend *main, ZukanDetailBlend *sub);
BOOL ZukanDetailBlend_IsActive(ZukanDetailBlend *blend);
void ZukanDetailBlend_StartIn(ZukanDetailBlend *blend);
void ZukanDetailBlend_StartOut(ZukanDetailBlend *blend);
// screen is 0 for the main screen and 1 for the sub screen
void ZukanDetailBlend_SetIn(u32 screen, ZukanDetailBlend *blend);
void ZukanDetailBlend_SetOut(u32 screen, ZukanDetailBlend *blend);
void ZukanDetailBlend_InitPlanes(ZukanDetailBlend *blend);

// Fades the palettes of the screens to black and back
enum {
    PALFADE_MAIN_BG = 1 << 0,
    PALFADE_SUB_BG = 1 << 1,
    PALFADE_MAIN_OBJ = 1 << 2,
    PALFADE_SUB_OBJ = 1 << 3,
};

enum {
    PALFADE_SHOWN,
    PALFADE_HIDDEN,
    PALFADE_FADING_IN,
    PALFADE_FADING_OUT,
};

struct ZukanDetailPalFade {
    TCBManager *tcbMgr;
    void *tcbBuffer;
    void *palette;
    // The PALFADE_* palettes that it fades
    u16 buffers;
    int state;
};

ZukanDetailPalFade *ZukanDetailPalFade_CreateEx(HeapID heapId, u16 buffers);
ZukanDetailPalFade *ZukanDetailPalFade_Create(HeapID heapId);
void ZukanDetailPalFade_Free(ZukanDetailPalFade *fade);
void ZukanDetailPalFade_Update(ZukanDetailPalFade *fade);
void ZukanDetailPalFade_VBlank(ZukanDetailPalFade *fade);
BOOL ZukanDetailPalFade_IsFading(ZukanDetailPalFade *fade);
void ZukanDetailPalFade_StartIn(ZukanDetailPalFade *fade);
void ZukanDetailPalFade_StartOut(ZukanDetailPalFade *fade);
void ZukanDetailPalFade_SetHidden(ZukanDetailPalFade *fade);
void ZukanDetailPalFade_LoadPalette(ZukanDetailPalFade *fade, u32 arcId, u32 fileId, HeapID heapId, u32 buffer,
                                    u32 size, u16 offset, u16 srcOffset);
void ZukanDetailPalFade_ReadPalettes(ZukanDetailPalFade *fade);

// A page's scrolling background
struct ZukanDetailBackground {
    u32 chars;
    u8 bg;
    u8 wait;
};

ZukanDetailBackground *ZukanDetailBackground_Create(HeapID heapId, u32 page, u8 bg, u8 bottomPalette, u8 topPalette);
void ZukanDetailBackground_Free(ZukanDetailBackground *background);
void ZukanDetailBackground_Update(ZukanDetailBackground *background);
u32 ZukanDetail_LoadBG(BOOL loaded, HeapID heapId, u8 bg, u32 palettes, u8 palette, u8 srcPalette, u32 arcId, u32 nclr,
                       u32 ncgr, u32 nscr, u32 chars);
void ZukanDetail_FreeBG(u32 bg, u32 chars);

// zukan_detail_graphic.c: the screens' BGs, OBJs and 3D

ZukanDetailGraphic *ZukanDetailGraphic_Create(u32 unk0, HeapID heapId, BOOL unk2);
void ZukanDetailGraphic_Free(ZukanDetailGraphic *graphic);
void ZukanDetailGraphic_Update(ZukanDetailGraphic *graphic);
void ZukanDetailGraphic_Begin3D(ZukanDetailGraphic *graphic);
void ZukanDetailGraphic_End3D(ZukanDetailGraphic *graphic);

// zukan_detail_touchbar.c: the bar at the bottom of the touch screen

// The commands of the bar's buttons
enum {
    ZUKAN_DETAIL_CMD_NONE,
    ZUKAN_DETAIL_CMD_RETURN,
    ZUKAN_DETAIL_CMD_CLOSE,
    ZUKAN_DETAIL_CMD_INFO = 6,
    ZUKAN_DETAIL_CMD_MAP,
    ZUKAN_DETAIL_CMD_VOICE,
    ZUKAN_DETAIL_CMD_FORM,
    ZUKAN_DETAIL_CMD_MAP_PLACE = 0x22,
};

ZukanDetailTouchbar *ZukanDetailTouchbar_Create(HeapID heapId, u32 unk1, u32 mode);
void ZukanDetailTouchbar_Free(ZukanDetailTouchbar *touchbar);
void ZukanDetailTouchbar_Update(ZukanDetailTouchbar *touchbar);
int ZukanDetailTouchbar_GetTrigger(ZukanDetailTouchbar *touchbar);
int ZukanDetailTouchbar_GetCommand(ZukanDetailTouchbar *touchbar);

// zukan_detail_headbar.c: the bar at the top of the screen

ZukanDetailHeadbar *ZukanDetailHeadbar_Create(HeapID heapId, Font *font);
void ZukanDetailHeadbar_Free(ZukanDetailHeadbar *headbar);
void ZukanDetailHeadbar_Update(ZukanDetailHeadbar *headbar);

// zukan_detail_info.c: the Pokémon's info

typedef struct {
    HeapID heapId;
} ZukanDetailInfoParam;

extern const ZukanDetailProcFuncs ZUKAN_DETAIL_INFO_PROC_FUNCS;

void ZukanDetailInfo_InitParam(ZukanDetailInfoParam *param, HeapID heapId);

// zukan_detail_map.c: where the Pokémon lives

typedef struct {
    HeapID heapId;
    // The place picked on the map
    u16 place;
} ZukanDetailMapParam;

extern const ZukanDetailProcFuncs ZUKAN_DETAIL_MAP_PROC_FUNCS;

void ZukanDetailMap_InitParam(ZukanDetailMapParam *param, HeapID heapId);

// zukan_detail_voice.c: the Pokémon's cry

typedef struct {
    HeapID heapId;
} ZukanDetailVoiceParam;

extern const ZukanDetailProcFuncs ZUKAN_DETAIL_VOICE_PROC_FUNCS;

void ZukanDetailVoice_InitParam(ZukanDetailVoiceParam *param, HeapID heapId);

// zukan_detail_form.c: the Pokémon's forms

typedef struct {
    HeapID heapId;
} ZukanDetailFormParam;

extern const ZukanDetailProcFuncs ZUKAN_DETAIL_FORM_PROC_FUNCS;

void ZukanDetailForm_InitParam(ZukanDetailFormParam *param, HeapID heapId);

#endif // POKEBW2_APP_ZUKAN_DETAIL_H
