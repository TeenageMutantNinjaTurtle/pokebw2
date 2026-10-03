#include "field/field_exp_obj_gimmick_ov104.h"
#include "save/save_control.h"
#include "save/trainer_card.h"
#include "system/game_data.h"

void func_ov104_021eed78(FieldExpObjGimmickOv104Work *work) {
    struct FieldExpObjGimmickOv104SaveData *data;

    data = func_ov104_021eed58(work->field);
    data->value = work->value;
    data->stateValue = func_ov104_021efcf0(work->state) >> 12;
    data->flag = work->flag;
    data->payload = work->payload;
}

void func_ov104_021eedb0(FieldExpObjGimmickOv104Work *work) {
    struct FieldExpObjGimmickOv104SaveData *data;

    data = func_ov104_021eed58(work->field);
    work->value = data->value;
    work->stateValue = data->stateValue;
    work->flag = data->flag;
}

void func_ov104_021eedcc(FieldExpObjGimmickOv104Work *work) {
    SaveControl *save;
    TrainerCardSave *card;

    save = GameData_GetSaveControl(work->gameData);
    card = (TrainerCardSave *)getTrainerGameInfoAddress(save);
    func_0200cb08(card, work->flag);
}
