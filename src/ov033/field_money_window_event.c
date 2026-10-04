#include "field/field.h"
#include "field/field_money_window.h"
#include "gfl/bmpwin.h"
#include "gfl/heap.h"
#include "gfl/key.h"
#include "gfl/sound.h"
#include "save/bag.h"
#include "save/save_control.h"
#include "system/game_data.h"
#include "system/game_event.h"
#include "system/game_system.h"

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

u32 *func_ov033_02177bd4(GameData *gameData, HeapID heapId, void *items, u32 *count) {
    u32 *result;
    BagSave *bag;
    u32 n;
    s32 i;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    result = GFL_HeapAllocate(heapId, 0x50, TRUE, data_ov033_0217c600, 0x14d);
    i = 0;
    n = 0;
    for (; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_CheckAvailItemSpace(bag, item, quantity, heapId) == TRUE) {
            ((u16 *)result)[n * 2] = item;
            ((u16 *)result)[n * 2 + 1] = quantity;
            n++;
        }
    }
    *count = n;
    return result;
}

void func_ov033_02177c48(GameData *gameData, HeapID heapId, void *items) {
    BagSave *bag;
    u32 i;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    for (i = 0; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_AddItem(bag, item, quantity, heapId) == TRUE) {
            func_02009a6c(items, i);
        }
    }
}

u32 func_ov033_02177c8c(GameData *gameData, HeapID heapId, void *items) {
    BagSave *bag;
    u32 i;
    u32 count;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    i = 0;
    count = 0;
    for (; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_CheckAvailItemSpace(bag, item, quantity, heapId) == FALSE) {
            count++;
        }
    }
    return count;
}

u16 func_ov033_02177cd4(GameData *gameData, HeapID heapId, void *items, u32 position) {
    BagSave *bag;
    s32 i;
    u32 count;
    u16 item;
    u16 quantity;

    bag = GameData_GetBag(gameData);
    i = 0;
    count = 0;
    for (; i < 20; i++) {
        item = func_02009a18(items, i);
        quantity = func_02009a38(items, i);
        if (item != 0 && BagSave_CheckAvailItemSpace(bag, item, quantity, heapId) == FALSE) {
            if (count == position) {
                return item;
            }
            count++;
        }
    }
    return 0;
}

GameEvent *func_ov033_02177d28(GameSystem *gameSystem) {
    GameData *gameData;
    DreamWorldSave *items;
    GameEvent *event;
    FieldMoneyWindowEvent *work;

    gameData = GSYS_GetGameData(gameSystem);
    items = getDreamWorldStuffAddress(GameData_GetSaveControl(gameData));
    event = GameEvent_Create(gameSystem, NULL, func_ov033_02177b08, sizeof(FieldMoneyWindowEvent));
    work = GameEvent_GetData(event);
    work->field = GSYS_GetField(gameSystem);
    work->index = 0;
    work->entries = func_ov033_02177bd4(gameData, Field_GetHeapID(work->field), items, &work->count);
    return event;
}