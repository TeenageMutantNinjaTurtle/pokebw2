#include "constants/sound.h"
#include "field/field_internal.h"
#include "field/field_player.h"
#include "gfl/sound.h"
#include "save/records.h"
#include "system/game_data.h"

BOOL Field_ToggleCycling(Field *field) {
    BOOL changed = FALSE;
    u32 exState = FieldPlayer_GetExState(field->player);

    if (exState == 1) {
        FieldPlayer_SetSpecialSeq(field->player, 1);
        changed = TRUE;
    } else if (exState == 0) {
        changed = TRUE;
        GFL_SndSEPlay(SEQ_SE_BICYCLE);
        FieldPlayer_SetSpecialSeq(field->player, 2);
        RecordAddOne(GameData_GetRecords(field->gameData), 3);
    }

    if (changed == TRUE) {
        func_ov036_0219a580(field->player);
    }
    return changed;
}
