#include "types.h"

typedef struct {
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 frame;
} ElScoreboard;

typedef struct {
    u16 unk0;
    u16 unk2;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
} G3DTextDrawResource;

typedef struct {
    u32 palette;
    u32 vramOffset;
} ElScoreboardPaletteTarget;

extern void *GFL_HeapAllocate(u16 heapId, u32 size, BOOL clear, const char *file, u32 line);
extern void GFL_HeapFree(void *ptr);
extern u32 func_ov012_02169fb0(void);
extern BOOL G3DTextDraw_CreateResource(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5, u16 a6, u32 a7, u16 heapId,
                                       G3DTextDrawResource *resource);
extern void gfxUploadAsync(u32 type, u32 dest, const void *src, u32 size);

// Declared in reverse, as the compiler emits them in reverse order
static const u16 sPalette3[4] = { 0x0000, 0x18c6, 0x0d73, 0x021f };
static const u16 sPalette2[4] = { 0x0000, 0x2108, 0x0d73, 0x021f };
static const u16 sPalette1[4] = { 0x0000, 0x18c6, 0x0df3, 0x031f };
static const u16 sPalette0[4] = { 0x0000, 0x2108, 0x0df3, 0x031f };

static const u16 *sPalettes[4] = { sPalette3, sPalette2, sPalette1, sPalette0 };

void func_ov035_0217ee2c(ElScoreboardPaletteTarget *target, int frame);

ElScoreboard *func_ov035_0217ed70(void *a0, u32 a1, u32 a2, u32 a3, u16 a4, u16 a5, u16 heapId) {
    G3DTextDrawResource resource;
    ElScoreboard *board = GFL_HeapAllocate(heapId, sizeof(ElScoreboard), TRUE, "el_scoreboard.c", 412);

    board->unk0 = 0;
    board->unk4 = func_ov012_02169fb0() - 1;
    board->unk6 = func_ov012_02169fb0() - 1;
    board->unk10 = -1;
    board->unk14 = -1;
    if (G3DTextDraw_CreateResource(a0, a1, 0, a2, a3, a4, a5, 0xc40, heapId, &resource)) {
        board->unk8 = resource.unk4;
        board->unkC = resource.unk8;
        board->unk10 = resource.unkC;
        board->unk4 = resource.unk0;
        board->unk6 = resource.unk2;
        board->unk14 = resource.unk10;
        board->frame = 0;
    }
    return board;
}

void func_ov035_0217ee00(ElScoreboard *board) {
    GFL_HeapFree(board);
}

void func_ov035_0217ee08(ElScoreboard *board) {
    ElScoreboardPaletteTarget target;

    board->frame++;
    if (board->unk14 != -1) {
        target.palette = board->unkC;
        target.vramOffset = board->unk14;
        func_ov035_0217ee2c(&target, board->frame);
    }
}

void func_ov035_0217ee2c(ElScoreboardPaletteTarget *target, int frame) {
    gfxUploadAsync(1, target->vramOffset + (u16)target->palette * 8, sPalettes[(frame & 0x1f) / 8], 8);
}
