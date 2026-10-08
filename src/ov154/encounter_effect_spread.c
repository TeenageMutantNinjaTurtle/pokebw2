#include "types.h"
#include "field/encounter_effect_spread.h"
#include "field/field.h"

GameEvent *func_ov154_021f6200(GameSystem *gsys, Field *field) {
    VecFx32 pos = { 0, 0, FX32_CONST(264) };

    func_ov036_021c5ea0(Field_GetEncEff(field));
    return EncEffCapture_CreateFlashEvent(gsys, &pos, func_ov154_021f623c, EncEffGrid_Draw);
}

GameEvent *func_ov154_021f623c(GameSystem *gsys) {
    EncEffGridParam param;

    param.cellWidth = 2;
    param.cellHeight = 2;
    param.init = func_ov154_021f626c;
    param.update = func_ov154_021f62b0;
    param.cellUpdate = func_ov154_021f6314;
    return EncEffGrid_CreateEvent(gsys, &param, 1);
}

// Starts the waves at three cells
void func_ov154_021f626c(EncEffGrid *grid) {
    EncEffSpread *spread = (EncEffSpread *)grid->unk300C;

    spread->nextCount = 0;
    spread->waveCount = 0;
    spread->next[0] = 51;
    spread->nextCount++;
    spread->next[1] = 149;
    spread->nextCount++;
    spread->next[2] = 91;
    spread->nextCount++;
}

// Shows the next wave every other frame
void func_ov154_021f62b0(EncEffGrid *grid) {
    s32 *work = grid->work;
    EncEffSpread *spread = (EncEffSpread *)grid->unk300C;
    int i;

    if (work[0] < grid->columns * grid->rows) {
        if (work[1] == 0) {
            for (i = 0; i < spread->waveCount; i++) {
                func_ov154_021f63bc(grid, spread->wave[i]);
            }
            func_ov154_021f6420(grid);
            work[1] = 1;
        } else {
            work[1]--;
        }
    }
}

// Flies off to the right, faster each frame, while turning half a turn
BOOL func_ov154_021f6314(EncEffCell *cell) {
    if (cell->pos.x < FX32_CONST(256)) {
        cell->pos.z = FX32_ONE;
        cell->pos.x += cell->speed;
        cell->speed += FX32_ONE;
        if (cell->offset < FX32_CONST(8)) {
            cell->offset += FX32_CONST(0.125);
        } else {
            cell->offset = FX32_CONST(8);
        }
    } else {
        cell->done = TRUE;
    }
    return cell->done;
}

// Whether a cell is already in the next wave
BOOL func_ov154_021f634c(int cell, EncEffSpread *spread) {
    int i;

    for (i = 0; i < spread->nextCount; i++) {
        if (cell == spread->next[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

// Adds a cell to the next wave, unless it is shown or already there
void func_ov154_021f637c(EncEffGrid *grid, int column, int row) {
    EncEffSpread *spread = (EncEffSpread *)grid->unk300C;
    int cell = column + row * grid->columns;

    if (!grid->cells[cell].visible && !func_ov154_021f634c(cell, spread)) {
        spread->next[spread->nextCount] = cell;
        spread->nextCount++;
    }
}

// Adds the cells above, right of, below and left of a cell to the next wave
void func_ov154_021f63bc(EncEffGrid *grid, int cell) {
    int column = cell % grid->columns;
    int row = cell / grid->columns;

    if (row - 1 >= 0) {
        func_ov154_021f637c(grid, column, row - 1);
    }
    if (column + 1 < grid->columns) {
        func_ov154_021f637c(grid, column + 1, row);
    }
    if (row + 1 < grid->rows) {
        func_ov154_021f637c(grid, column, row + 1);
    }
    if (column - 1 >= 0) {
        func_ov154_021f637c(grid, column - 1, row);
    }
}

// Shows the next wave's cells and makes it the last wave
void func_ov154_021f6420(EncEffGrid *grid) {
    int i;
    s32 *work = grid->work;
    EncEffSpread *spread = (EncEffSpread *)grid->unk300C;

    for (i = 0; i < spread->nextCount; i++) {
        EncEffCell *cell = &grid->cells[spread->next[i]];

        if (!cell->visible) {
            cell->visible = TRUE;
            work[0]++;
            cell->speed = FX32_ONE;
            spread->wave[i] = spread->next[i];
        }
    }
    spread->waveCount = spread->nextCount;
    spread->nextCount = 0;
}
