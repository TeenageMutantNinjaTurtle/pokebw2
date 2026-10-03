#include "field/field.h"
#include "field/field_money_window.h"
#include "gfl/bmpwin.h"
#include "gfl/heap.h"
#include "gfl/input.h"
#include "gfl/sound.h"

GameEventReturnCode func_ov033_02177b08(GameEvent *unused, u32 *state, void *data) {
    FieldMoneyWindowEvent *event;
    BmpWin *bitmapWindow;
    u16 remaining;

    event = data;
    switch (*state) {
    case 0:
        remaining = event->count - event->index;
        if (remaining > 7) {
            remaining = 7;
        }
        event->window = func_ov033_02177998(event->field, (u32)&event->entries[event->index], remaining);
        func_ov033_02177a60(event->window);
        event->window->unk10 = func_ov036_02189cb0(Field_GetMsgBGSys(event->field));
        (*state)++;
        break;
    case 1:
        if (func_ov036_02187c70(event->window->window) != TRUE) {
            break;
        }
        (*state)++;
        break;
    case 2:
        bitmapWindow = func_ov036_02187c9c(event->window->window);
        func_ov036_02189de8(event->window->unk10, BmpWin_GetBitmap(bitmapWindow), 15);
        BmpWin_FlushChar(bitmapWindow);
        if (!(GCTX_HIDGetPressedKeys() & 3)) {
            break;
        }
        GFL_SndSEPlay(0x547);
        (*state)++;
        break;
    case 3:
        func_ov036_02189cd8(event->window->unk10);
        func_ov033_02177a28(event->window);
        (*state)++;
        break;
    case 4:
        if (event->index + 7 >= event->count) {
            GFL_HeapFree(event->entries);
            return TRUE;
        }
        event->index += 7;
        *state = 0;
        break;
    }
    return FALSE;
}
