#include "field/field_exp_obj_gimmick_ov104.h"
#include "save/trainer_card.h"
#include "system/game_data.h"

void func_ov104_021eeebc(FieldExpObjGimmickOv104Work *work) {
    SaveControl *save;
    TrainerCardSave *card;

    if (work->value == 0) {
        save = GameData_GetSaveControl_(work->gameData);
        card = getTrainerCardData_wrapper(save);
        work->flag = func_0200cb00(card);
        work->value = 1;
    }
}
