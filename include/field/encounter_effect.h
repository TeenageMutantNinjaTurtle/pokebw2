#ifndef POKEBW2_FIELD_ENCOUNTER_EFFECT_H
#define POKEBW2_FIELD_ENCOUNTER_EFFECT_H

#include "types.h"
#include "nitro/fx.h"
#include "system/game_event.h"
#include "struct_decls.h"

// Overlay 150 runs the encounter effects that split the screen into a grid of cells, which overlays 151 to 153 set
// up. Overlay 148 runs the event around such an effect

// A cell of the screen, 0x40 bytes
struct EncEffCell {
    fx32 x;
    fx32 y;
    u32 unk08;
    u8 unk0C[0xc];
    u32 unk18;
    s32 offset;
    u32 unk20;
    u8 unk24[0xc];
    s32 frame;
    BOOL visible;
    BOOL done;
    // Called for each visible cell, until it returns TRUE
    BOOL (*update)(EncEffCell *cell);
};

struct EncEffGrid {
    EncEffCell cells[192];
    // For the grid's update function
    s32 work[2];
    u16 columns;
    u16 rows;
    u8 unk300C[0x64];
    void (*update)(EncEffGrid *grid);
    u32 unk3074;
    u32 unk3078;
};

struct EncEffGridParam {
    // The size of a cell, in tiles
    u32 cellWidth;
    u32 cellHeight;
    void (*init)(EncEffGrid *grid);
    void (*update)(EncEffGrid *grid);
    BOOL (*cellUpdate)(EncEffCell *cell);
};

void func_ov036_021c5ea0(EncEff *effect);
void *EncEff_AllocWorkArea(EncEff *effect, u32 id, u32 size);
void *EncEff_GetWorkArea(EncEff *effect);
void *Field_Get3DCi(Field *field);
void EncEff_CallRenderFunc(EncEff *effect);
GameEvent *EventFieldEffect_CreatePokeSprite(GameSystem *gsys, void *g3DCi, u8 partySlot);
// The event of an effect: init makes the effect's event, and render draws it
GameEvent *func_ov148_021f59e0(GameSystem *gsys, const VecFx32 *pos, GameEvent *(*init)(GameSystem *gsys),
                               void (*render)(EncEffGrid *grid));
GameEvent *func_ov150_021f5da0(GameSystem *gsys, const EncEffGridParam *param, u32 mode);
void func_ov150_021f5fac(EncEffGrid *grid);

GameEvent *func_ov152_021f6200(GameSystem *gsys, Field *field);
GameEvent *func_ov152_021f623c(GameSystem *gsys);
void func_ov152_021f6264(EncEffGrid *grid);
BOOL func_ov152_021f62a4(EncEffCell *cell);

GameEvent *func_ov153_021f6200(GameSystem *gsys, Field *field);
GameEvent *func_ov153_021f623c(GameSystem *gsys);
void func_ov153_021f6268(EncEffGrid *grid);
BOOL func_ov153_021f62c4(EncEffCell *cell);

#endif // POKEBW2_FIELD_ENCOUNTER_EFFECT_H
