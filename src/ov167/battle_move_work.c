#include "battle/btl_pokeparam.h"
#include "pml/waza.h"

struct BattleMoveCore {
    u16 id;
    union {
        struct {
            u8 pp;
            u8 maxPP;
        };
        u16 ppPair;
    };
    union {
        struct {
            u8 unk04;
            u8 flagsLow : 4;
            u8 flagsHigh : 4;
        };
        u16 flagsPair;
    };
};

struct BattleMoveWork {
    struct BattleMoveCore current;
    struct BattleMoveCore original;
    u8 originalActive;
};

// Function names from swan.
void MoveWork_UpdateNumber(BattleMoveWork *work, u16 move, u8 maxPP, BOOL updateCurrent) {
    if (updateCurrent) {
        MoveCore_UpdateNumber(&work->current, move, maxPP);
        if (work->originalActive != 0) {
            work->original.id = work->current.id;
            work->original.ppPair = work->current.ppPair;
            work->original.flagsPair = work->current.flagsPair;
        }
    } else {
        MoveCore_UpdateNumber(&work->original, move, maxPP);
        work->originalActive = 0;
    }
}

void MoveCore_UpdateNumber(BattleMoveCore *core, u16 move, u8 maxPP) {
    u8 pp;

    core->id = move;
    core->flagsLow = 0;
    core->flagsHigh = 0;
    if (move != 0) {
        pp = PML_MoveGetMaxPP(move, 0);
    } else {
        pp = 0;
    }
    core->maxPP = pp;
    if (maxPP != 0 && core->maxPP > maxPP) {
        core->maxPP = maxPP;
    }
    core->pp = core->maxPP;
}
