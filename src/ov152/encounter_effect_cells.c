#include "types.h"
#include "field/encounter_effect.h"
#include "field/field.h"

GameEvent *func_ov152_021f6200(GameSystem *gsys, Field *field) {
    VecFx32 pos = { 0, 0, FX32_CONST(264) };

    func_ov036_021c5ea0(Field_GetEncEff(field));
    return func_ov148_021f59e0(gsys, &pos, func_ov152_021f623c, func_ov150_021f5fac);
}

GameEvent *func_ov152_021f623c(GameSystem *gsys) {
    EncEffGridParam param;

    param.cellWidth = 4;
    param.cellHeight = 4;
    param.init = NULL;
    param.update = func_ov152_021f6264;
    param.cellUpdate = func_ov152_021f62a4;
    return func_ov150_021f5da0(gsys, &param, 0);
}

// Shows one cell at a time
void func_ov152_021f6264(EncEffGrid *grid) {
    s32 *work = grid->work;

    if (work[0] < grid->columns * grid->rows) {
        if (work[1] == 0) {
            grid->cells[work[0]].visible = TRUE;
            work[0]++;
            work[1] = 0;
        } else {
            work[1]--;
        }
    }
}

BOOL func_ov152_021f62a4(EncEffCell *cell) {
    if (cell->frame < 1) {
        cell->offset += FX32_ONE;
        if (cell->offset >= FX32_CONST(16)) {
            cell->offset -= FX32_CONST(16);
            cell->frame++;
        }
    } else if (cell->frame == 1) {
        cell->offset += FX32_ONE;
        if (cell->offset >= FX32_CONST(8)) {
            cell->offset = FX32_CONST(8);
            cell->frame++;
        }
    } else {
        cell->done = TRUE;
    }
    return cell->done;
}
