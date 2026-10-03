#include "field/bsubway_scr.h"
#include "save/bsubway_save.h"

u16 func_ov033_0217bcb4(BSubwayScoreData *score, GameSystem *gsys, u32 op) {
    u8 value;
    u32 limit;

    value = func_0200e4a0(score);
    switch (op) {
    case 0:
        return value;
    case 3:
        func_0200e438(score, 0, 2);
        if (value == 10) {
            return 0;
        }
        func_0200e488(score);
        return 1;
    case 4:
        limit = func_0200e4a4(score, 3);
        if (value == 1) {
            return 0;
        }
        if (limit >= data_ov033_0217c564[value - 1]) {
            func_0200e494(score);
            func_0200e4a4(score, 2);
            func_0200e438(score, 0, 2);
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}
