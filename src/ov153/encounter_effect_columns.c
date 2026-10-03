#include "types.h"
#include "field/encounter_effect.h"
#include "field/field.h"

GameEvent *func_ov153_021f6200(GameSystem *gsys, Field *field) {
    VecFx32 pos = { 0, 0, FX32_CONST(264) };

    func_ov036_021c5ea0(Field_GetEncEff(field));
    return func_ov148_021f59e0(gsys, &pos, func_ov153_021f623c, func_ov150_021f5fac);
}

GameEvent *func_ov153_021f623c(GameSystem *gsys) {
    EncEffGridParam param;

    param.cellWidth = 2;
    param.cellHeight = 2;
    param.init = NULL;
    param.update = func_ov153_021f6268;
    param.cellUpdate = func_ov153_021f62c4;
    return func_ov150_021f5da0(gsys, &param, 1);
}

// Shows one column at a time
void func_ov153_021f6268(EncEffGrid *grid) {
    s32 *work = grid->work;
    int row;

    if (work[0] < grid->columns) {
        if (work[1] == 0) {
            for (row = 0; row < grid->rows; row++) {
                grid->cells[work[0] + row * grid->columns].visible = TRUE;
            }
            work[0]++;
            work[1] = 1;
        } else {
            work[1]--;
        }
    }
}

BOOL func_ov153_021f62c4(EncEffCell *cell) {
    if (cell->frame < 64) {
        cell->offset += FX32_CONST(0.125);
        cell->frame++;
    } else {
        cell->done = TRUE;
    }
    return cell->done;
}
