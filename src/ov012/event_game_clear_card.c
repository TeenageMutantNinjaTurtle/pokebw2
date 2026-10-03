#include "field/event_game_clear.h"
#include "save/save_control.h"
#include "save/trainer_card.h"

void func_ov012_0215a670(GameClearWork *work) {
    func_0200cb08(getTrainerCardDataBlkAddress(work->gameData), 0x5a0);
}
