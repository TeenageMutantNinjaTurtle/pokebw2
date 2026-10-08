#ifndef POKEBW2_DSPROT_DSPROT_INTERNAL_H
#define POKEBW2_DSPROT_DSPROT_INTERNAL_H

#include "types.h"
#include "dsprot/dsprot.h"

// The parts of DS Protect that call each other. Its code refers to functions by their address plus 0x2200, and to
// lengths by DSProt_Work's address plus 0x2200 plus the length, so that no plain address of its code is in the ROM.
// Each DSProt_Call* function is a hand-written stub that verifies itself, then has DSProt_Dispatch decrypt the
// function it stands for, run it and encrypt it again.

// dsprot_run.c
asm void DSProt_Crash(void);
void DSProt_ClearMemory(void *dest, u32 size);
asm void *DSProt_CallCrash(void *arg0, void *arg1);
void *DSProt_RunChecks(DSProtCallback callback, void *arg0, void *arg1);
asm void DSProt_DecryptRun(void);

// dsprot_stub_check.c
u32 DSProt_CheckEmulatorStub(void);
u32 DSProt_CheckFlashcartStub(void);
asm u32 DSProt_CallCheckEmulatorStub(void);
asm u32 DSProt_CallCheckFlashcartStub(void);
asm void DSProt_DecryptStubCheck(void);

// dsprot_decrypt.c
extern u8 DSProt_Work[];
void DSProt_Decrypt(u32 *list);
asm void DSProt_Dispatch(void);

// dsprot_detect.c
u32 DSProt_CheckEmulator(void);
u32 DSProt_CheckFlashcart(void);
asm u32 DSProt_CallCheckFlashcart(void);
asm u32 DSProt_CallCheckEmulator(void);

#endif // POKEBW2_DSPROT_DSPROT_INTERNAL_H
