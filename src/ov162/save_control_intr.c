#include "types.h"
#include "gfl/heap.h"
#include "gfl/ui.h"
#include "save/save_control.h"
#include "save/save_control_intr.h"

// Saving a new game in the background. A soft reset cancels it, and it does nothing if save data is already present

enum {
    STATE_IDLE,
    STATE_SAVING,
    STATE_PAUSED,
    STATE_DONE,
};

struct SaveControlIntr {
    SaveControl *save;
    u8 state;
    // The state to go back to after a pause
    u8 resumeState;
    u8 pauseRequested;
    u8 disabled;
    // The save control's flags, cleared while saving and put back afterwards
    u32 flag4;
    u32 flag5;
    u32 flag6;
    u32 flag7;
};

static void SaveControlIntr_OnSoftReset(void *work);

SaveControlIntr *SaveControlIntr_Create(HeapID heapId, SaveControl *save) {
    SaveControlIntr *intr = GFL_HeapAllocate(heapId, sizeof(SaveControlIntr), TRUE, "save_control_intr.c", 71);

    intr->save = save;
    if (SaveControl_IsDataAlreadyPresent(save) == TRUE) {
        intr->disabled = TRUE;
    } else {
        GCTX_HIDSetSoftResetCallback(SaveControlIntr_OnSoftReset, intr);
    }
    return intr;
}

void SaveControlIntr_Free(SaveControlIntr *intr) {
    GCTX_HIDSetSoftResetCallback(NULL, NULL);
    GFL_HeapFree(intr);
}

void SaveControlIntr_Start(SaveControlIntr *intr) {
    if (intr->disabled == TRUE) {
        return;
    }
    func_020073ac(intr->save);
    if (intr->disabled == FALSE) {
        func_02008e04(intr->save);
        intr->flag4 = func_0200748c(intr->save);
        intr->flag5 = func_02007494(intr->save);
        intr->flag6 = func_020074dc(intr->save);
        intr->flag7 = func_020074e4(intr->save);
        func_02007490(intr->save, 0);
        func_02007498(intr->save, 0);
        func_020074e0(intr->save, 0);
        func_020074e8(intr->save, 0);
    }
    intr->state = STATE_SAVING;
}

u32 SaveControlIntr_Update(SaveControlIntr *intr) {
    u32 result;

    if (intr->disabled == TRUE) {
        return 2;
    }
    switch (intr->state) {
    case STATE_SAVING:
        if (intr->pauseRequested == TRUE && getLockIDStatus_inline_stub() == 0) {
            intr->resumeState = intr->state;
            intr->state = STATE_PAUSED;
            return 0;
        }
        result = func_020073c4(intr->save);
        if (result - 2 <= 1) {
            intr->state = STATE_DONE;
            func_02007490(intr->save, intr->flag4);
            func_02007498(intr->save, intr->flag5);
            func_020074e0(intr->save, intr->flag6);
            func_020074e8(intr->save, intr->flag7);
        }
        return result;
    case STATE_PAUSED:
        if (intr->pauseRequested == FALSE) {
            intr->state = intr->resumeState;
        }
        return 0;
    case STATE_DONE:
        return 2;
    }
    return 0;
}

void SaveControlIntr_Pause(SaveControlIntr *intr) {
    if (intr->state != STATE_DONE) {
        intr->pauseRequested = TRUE;
    }
}

void SaveControlIntr_Resume(SaveControlIntr *intr) {
    if (intr->state != STATE_DONE) {
        intr->pauseRequested = FALSE;
    }
}

BOOL SaveControlIntr_IsPausedOrDone(SaveControlIntr *intr) {
    if (intr->disabled == TRUE || intr->state == STATE_DONE) {
        return TRUE;
    }
    if (intr->state == STATE_PAUSED) {
        return TRUE;
    }
    return FALSE;
}

void SaveControlIntr_Nop(SaveControlIntr *intr) {
}

BOOL SaveControlIntr_IsDone(SaveControlIntr *intr) {
    if (intr->disabled == TRUE) {
        return TRUE;
    }
    if (intr->state == STATE_DONE) {
        return TRUE;
    }
    return FALSE;
}

static void SaveControlIntr_OnSoftReset(void *work) {
    SaveControlIntr *intr = work;

    if (intr->disabled == FALSE && intr->state != STATE_DONE) {
        func_02007424(intr->save);
        intr->disabled = TRUE;
    }
}
