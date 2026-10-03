#include "field/field_exp_obj_gimmick_ov104.h"
#include "gfl/str.h"
#include "system/game_data.h"

void func_ov104_021ef868(FieldExpObjGimmickOv104Work *work) {
    s32 count;
    FieldExpObjGimmickOv104MessageArg arg;
    u32 species[6];
    WordSet *wordSet;
    const u32 *data;
    u32 message;
    s32 i;

    wordSet = GFL_WordSetSystemCreateDefault(func_ov104_021efcf4(work->state));
    func_ov104_021ef084(work, species, &count);
    switch (count) {
    case 1:
        message = 0xcd;
        break;
    case 2:
        message = 0xce;
        break;
    case 3:
        message = 0xcf;
        break;
    case 4:
        message = 0xd0;
        break;
    case 5:
        message = 0xd1;
        break;
    case 6:
        message = 0xd2;
        break;
    }
    for (i = 0; i < count; i++) {
        WordSet_LoadSpeciesName(wordSet, i, (u16)species[i]);
    }
    copyVarForText(wordSet, 6, GetGameDataPlayerInfo(work->gameData));
    data = &data_ov104_021f0620;
    arg.kind = ((const u16 *)data)[5];
    arg.unk04 = data[8];
    arg.unk08 = data[15];
    arg.unk0c = 2;
    arg.unk10 = 0x2b;
    arg.unk14 = message;
    arg.wordSet = wordSet;
    func_ov104_021ef28c(work, (u32)&arg, 9, 0);
    GFL_WordSetSystemFree(wordSet);
}
