#include "types.h"
#include "gfl/backup_card.h"
#include "gfl/std.h"
#include "nitro/card.h"
#include "nitro/os.h"

static void setCardWrittenVerified(void *arg);
static void func_0203c1c0(u16 lockId, BOOL noResponse, BackupWriteErrorCallback callback);

// Whether the last write has ended
static BOOL sWriteDone = TRUE;

static BOOL sLocked;

BOOL identifyGameCardBackup(void) {
    s32 lock_id = cart_key_create();
    CARDBackupType type;

    GFL_ASSERT(lock_id != OS_LOCK_ID_ERROR);
    func_0206ef4c(lock_id);
    type = CARD_BACKUP_TYPE_FLASH_4MBITS_EX;
    if (!func_0206f854(type)) {
        type = 0;
    }
    func_0206ef58(lock_id);
    cart_key_release(lock_id);
    return type != 0 ? TRUE : FALSE;
}

BOOL func_0203bfd4(u32 dest, const void *src, u32 size, BackupWriteErrorCallback callback) {
    BOOL result;
    u16 lockId = func_0203c07c(dest, src, size, callback);

    while (!finishBackupGetResult(lockId, &result, callback)) {
    }
    return result;
}

BOOL readFlashWaitSuccess(u32 src, void *dest, u32 size, BackupReadErrorCallback callback) {
    s32 lock_id = cart_key_create();
    BOOL result;

    GFL_ASSERT(lock_id != OS_LOCK_ID_ERROR);
    func_0206ef4c(lock_id);
    CARD_ReadBackupAsync(src, dest, size, NULL, NULL);
    result = func_0206f888();
    func_0206ef58(lock_id);
    cart_key_release(lock_id);
    if (!result && callback != NULL) {
        callback();
    }
    return result;
}

static void setCardWrittenVerified(void *arg) {
    sWriteDone = TRUE;
}

u16 func_0203c07c(u32 dest, const void *src, u32 size, BackupWriteErrorCallback callback) {
    u32 header;
    s32 lock_id = cart_key_create();

    GFL_ASSERT(lock_id != OS_LOCK_ID_ERROR);
    func_0206ef4c(lock_id);
    sLocked = TRUE;
    if (!CARD_ReadBackup(0, &header, sizeof(header))) {
        func_0203c1c0(lock_id, TRUE, callback);
    }
    sWriteDone = FALSE;
    CARD_WriteAndVerifyBackupAsync(dest, src, size, setCardWrittenVerified, NULL);
    return lock_id;
}

BOOL finishBackupGetResult(u16 lockId, BOOL *result, BackupWriteErrorCallback callback) {
    if (sWriteDone == TRUE) {
        func_0206ef58(lockId);
        cart_key_release(lockId);
        sLocked = FALSE;
        switch (func_0206eecc()) {
        case CARD_RESULT_SUCCESS:
            *result = TRUE;
            break;
        default:
        case CARD_RESULT_FAILURE:
        case CARD_RESULT_INVALID_PARAM:
        case CARD_RESULT_UNSUPPORTED:
        case CARD_RESULT_TIMEOUT:
        case CARD_RESULT_ERROR:
        case CARD_RESULT_CANCELED:
            *result = FALSE;
            if (callback != NULL) {
                callback(FALSE);
            }
            break;
        case CARD_RESULT_NO_RESPONSE:
            *result = FALSE;
            if (callback != NULL) {
                callback(TRUE);
            }
            break;
        }
        return TRUE;
    }
    return FALSE;
}

void cancelCardProcess(u16 lockId) {
    if (!func_0206f890()) {
        func_0206f898();
        func_0206f888();
    }
    if (sLocked == TRUE) {
        func_0206ef58(lockId);
        cart_key_release(lockId);
        sLocked = FALSE;
    }
}

static void func_0203c1c0(u16 lockId, BOOL noResponse, BackupWriteErrorCallback callback) {
    func_0206ef58(lockId);
    cart_key_release(lockId);
    sLocked = FALSE;
    if (callback != NULL) {
        callback(noResponse);
    }
}

BOOL getLockIDStatus(void) {
    return sLocked;
}
