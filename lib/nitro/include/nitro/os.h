#ifndef POKEBW2_NITRO_OS_H
#define POKEBW2_NITRO_OS_H

#include "types.h"
#include "nitro/hw.h"

// The tick count of the system timer, which swan names clock
u64 clock(void);
// The system clock, and NitroSDK's OS_TicksToSeconds: the system timer ticks every 64 cycles of it
#define OS_SYSTEM_CLOCK 33514000
#define OS_TicksToSeconds(tick) (((tick) * 64) / OS_SYSTEM_CLOCK)
#define OS_TicksToMilliSeconds(tick) (((tick) * 64) / (OS_SYSTEM_CLOCK / 1000))
#define OS_TicksToMicroSeconds(tick) (((tick) * 64 * 1000) / (OS_SYSTEM_CLOCK / 1000))
// Restarts the game, which swan names sys_reset
void sys_reset(u32 parameter);
// Stops the game after a fatal error, calling the registered handler first
void sys_exit(void);
// Stops the CPU until an interrupt, which swan names cp15_halt. NitroSDK's OS_Halt
void cp15_halt(void);
// Writes a range of the data cache back to memory, before DMA reads it. NitroSDK's DC_FlushRange
void cp15_flushDC(const void *addr, u32 size);
// Discards a range of the data cache, after DMA writes it. NitroSDK's DC_InvalidateRange
void cp15_invalidateDC(void *addr, u32 size);

// The start of DTCM, where the linker places the DTCM module
extern u32 SDK_AUTOLOAD_DTCM_START[];
#define HW_DTCM ((u32)SDK_AUTOLOAD_DTCM_START)
// The interrupt flags that OS_WaitIrq checks, at the end of DTCM
#define HW_INTR_CHECK_BUF (HW_DTCM + 0x3ff8)

#define OS_IE_V_BLANK 0x1
// The DSi's new DMA channel 1
#define OS_IE_NDMA1 0x20000000

static inline u32 OS_GetVBlankCount(void) {
    return *(vu32 *)HW_VBLANK_COUNT_BUF;
}

// Waits for one of the interrupts, after clearing their flags if clear is set. NitroSDK's OS_WaitIrq, under swan's
// name
void CPU_WaitIntrBit(BOOL clear, u32 interrupts);

static inline void OS_SetIrqCheckFlag(u32 interrupts) {
    *(vu32 *)HW_INTR_CHECK_BUF |= interrupts;
}

// Memory arenas and OS heaps, under swan's names: OS_GetArenaLo, OS_GetArenaHi, OS_SetArenaLo, OS_SetArenaHi,
// OS_AllocFromArenaLo, OS_InitAlloc, OS_CreateHeap, OS_AllocFromHeap and OS_FreeToHeap
#define OS_ARENA_MAIN 0
#define OS_ARENA_DTCM 4
#define OS_HEAP_INVALID (-1)

void *GetUserMemRegionStart(int arena);
void *GetUserMemRegionEnd(int arena);
void SetUserMemRegionStart(int arena, void *start);
void SetUserMemRegionEnd(int arena, void *end);
void *mem_alloc_direct(int arena, u32 size, u32 alignment);
void *mem_init_alloc_area(int arena, void *start, void *end, int maxHeaps);
int mem_bind_range(int arena, void *start, void *end);
void *malloc_device(int arena, int heap, u32 size);
void free_device(int arena, int heap, void *ptr);

// NitroSDK's OS_GetLockID and OS_ReleaseLockID, under swan's names
#define OS_LOCK_ID_ERROR (-3)

s32 cart_key_create(void);
void cart_key_release(u16 lockId);
// NitroSDK's OS_LockCard and OS_UnlockCard
s32 func_0207a178(u16 lockId);
s32 func_0207a1a0(u16 lockId);

// NitroSDK's OS_DisableInterrupts and OS_RestoreInterrupts, under swan's names
u32 CPU_IRQDisable(void);
u32 CPU_SetIRQMask(u32 mask);
// NitroSDK's OS_EnableIrqMask, under swan's name
u32 CPU_EnableInterrupts(u32 mask);
// NitroSDK's OS_Sleep: waits for some milliseconds, letting other threads run
void func_0207aa04(u32 msec);
// Waits for one of the interrupts, clearing their flags first if clear is TRUE
void CPU_WaitIntrBit(BOOL clear, u32 interrupts);
void exit(int status);

// Fills 32 bytes with values that differ from run to run
void OS_GetLowEntropyData(u32 buffer[8]);
// NitroSDK's STD_CompareString
int STD_CompareString(const char *a, const char *b);
// NitroSDK's STD_GetStringLength
int NNS_STD_StrLen(const char *str);
// NitroSDK's STD_CopyLString: copies at most size - 1 characters and a NUL, returning the length of src
int func_0207f7cc(char *dst, const char *src, int size);
// NitroSDK's STD_TSPrintf
int func_020800e8(char *dst, const char *fmt, ...);
// TwlSDK's OS_SpinWaitSysCycles: busy-waits for some cycles of the system clock
void func_0207c160(u32 cycles);

// NitroSDK's OS_WaitIrq and OS_IsRunOnTwl, under swan's names
void irq_waitFor(BOOL clear, u32 interrupts);
BOOL hw_isDSi(void);
// The DSi's parental controls, of its settings. The fields' meanings are not known
typedef struct {
    u32 unk0_0 : 1;
    u32 unk0_1 : 4;
    u32 unk0_5 : 1;
    u32 unk0_6 : 26;
} TWLParentalControl;

// The DSi's parental controls, NULL on a DS
TWLParentalControl *func_0207c4b4(void);
// TwlSDK's OS_IsAvailableWireless, TRUE on a DS, and OS_IsAgreeEULA, FALSE on a DS
BOOL func_0207c438(void);
BOOL func_0207c45c(void);
// NitroSDK's OS_WaitVBlankIntr
void OS_WaitVBlankIntr(void);

// The buttons the ARM7 reads, X, Y and the lid among them, in shared memory. NitroSDK's PAD_DetectFold
#define HW_BUTTON_XY_BUF 0x02ffffa8
#define PAD_DETECT_FOLD_MASK 0x8000
#define PAD_DETECT_FOLD_SHIFT 15

static inline BOOL PAD_DetectFold(void) {
    return (*(vu16 *)HW_BUTTON_XY_BUF & PAD_DETECT_FOLD_MASK) >> PAD_DETECT_FOLD_SHIFT;
}

// The DS's owner settings
#define OS_OWNERINFO_NICKNAME_MAX 10
#define OS_OWNERINFO_COMMENT_MAX 26

typedef struct {
    u8 month;
    u8 day;
} OSBirthday;

typedef struct {
    u8 language;
    u8 favoriteColor;
    OSBirthday birthday;
    u16 nickName[OS_OWNERINFO_NICKNAME_MAX + 1];
    u16 nickNameLength;
    u16 comment[OS_OWNERINFO_COMMENT_MAX + 1];
    u16 commentLength;
} OSOwnerInfo;

// TwlSDK's owner settings, which add the country
typedef struct {
    u8 language;
    u8 favoriteColor;
    OSBirthday birthday;
    u16 nickName[OS_OWNERINFO_NICKNAME_MAX + 1];
    u16 nickNameLength;
    u16 comment[OS_OWNERINFO_COMMENT_MAX + 1];
    u16 commentLength;
    u8 country;
} OSOwnerInfoEx;

void OS_GetOwnerInfo(OSOwnerInfo *info);

int OS_SNPrintf(char *dst, u32 len, const char *format, ...);

#endif // POKEBW2_NITRO_OS_H
