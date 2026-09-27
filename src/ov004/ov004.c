#include "types.h"

typedef struct {
    u32 unk0;
    void *unk4;
    u32 unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
    void *unk34;
    void *unk38;
    void *unk3C;
    u32 unk40;
    u32 unk44;
    void *unk48;
    void *unk4C;
    u32 unk50;
} Ov004Work;

typedef struct {
    u32 unk0;
    u32 unk4;
} Ov004Args;

extern void *GSYS_GetGameData(void *proc);
extern void *GameEvent_Create(void *proc, u32 a1, void *func, u32 size);
extern void *GSYS_GetGameCommSystem(void *proc);
extern BOOL GameCommSys_BootCheck(void *a0);
extern void func_0202bd80(void *a0);
extern void *GameEvent_GetData(void *a0);
extern void sys_memset(void *dest, u32 value, u32 size);
extern void *GameData_GetSaveControl(void *a0);
extern void *func_0200b488(void *a0);
extern void *getSaveAdventureDataBlk(void *a0);
extern void *SaveControl_GetPokePartySave(void *a0);
extern void *GameData_GetBoxSaveAccessor(void *a0);
extern void *GameData_GetPokedex(void *a0);
extern void *func_02017238(void *a0);
extern void *getUnityTower_SurveySaveBlkAddrress(void *a0);
extern void *func_02008dd0(void *a0);
extern void *getTrainerDataBlkAddress(void *a0);
extern void *getTrainerCardInfoBlkAddress(void *a0);
extern void *GameData_GetBag(void *a0);
extern void *PokeDex_IsNationalObtained(void *a0);
extern void *func_0200a3dc(void *a0);
extern void GameEvent_ChainNext(void *a0, void *a1);
extern void *CallFieldMapEntranceOutTransitionDefault(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 GFL_SndBGMGetID(void);
extern void GFL_SndBGMFadeOut(u32 a0);
extern void *CreateFieldCloseEvent(void *a0, u32 a1);
extern void GSYS_QueueProc(void *a0, u32 a1, void *a2, void *a3);
extern BOOL GSYS_GetProcMgrState(void *a0);
extern void GFL_SndBGMPlay(u32 a0, u32 a1);
extern void GFL_SndBGMFadeIn(u32 a0);
extern void *EventFieldOpen_CreateHeadless(void *a0);
extern void *CallFieldMapEntranceInTransition(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u8 data_ov036_021e1ab8[];
// Defined by the linker script, the address is the overlay ID
extern u32 OVERLAY_214_ID[];

void *func_ov004_0214f50c(void *proc, u32 a1, u32 unused);
BOOL func_ov004_0214f5d0(void *proc, int *state, Ov004Work *work);

void *func_ov004_0214f500(void *proc, Ov004Args *args) {
    return func_ov004_0214f50c(proc, args->unk0, args->unk4);
}

void *func_ov004_0214f50c(void *proc, u32 a1, u32 unused) {
    void *unk = GSYS_GetGameData(proc);
    void *result = GameEvent_Create(proc, 0, func_ov004_0214f5d0, sizeof(Ov004Work));
    Ov004Work *work;

    if (GameCommSys_BootCheck(GSYS_GetGameCommSystem(proc))) {
        func_0202bd80(GSYS_GetGameCommSystem(proc));
    }

    work = GameEvent_GetData(result);
    sys_memset(work, 0, sizeof(Ov004Work));
    work->unk4 = proc;
    work->unk8 = a1;
    work->unk48 = GameData_GetSaveControl(unk);
    work->unkC = func_0200b488(work->unk48);
    work->unk10 = getSaveAdventureDataBlk(work->unk48);
    work->unk14 = SaveControl_GetPokePartySave(work->unk48);
    work->unk18 = GameData_GetBoxSaveAccessor(unk);
    work->unk1C = GameData_GetPokedex(unk);
    work->unk20 = func_02017238(unk);
    work->unk24 = getUnityTower_SurveySaveBlkAddrress(work->unk48);
    work->unk28 = func_02008dd0(work->unk48);
    work->unk2C = getTrainerDataBlkAddress(work->unk48);
    work->unk30 = getTrainerCardInfoBlkAddress(work->unk48);
    work->unk34 = GameData_GetBag(unk);
    work->unk4C = proc;
    work->unk38 = PokeDex_IsNationalObtained(work->unk1C);
    work->unk3C = func_0200a3dc(work->unk20);
    work->unk40 = 0;
    work->unk44 = 0;
    return result;
}

BOOL func_ov004_0214f5d0(void *proc, int *state, Ov004Work *work) {
    switch (*state) {
    case 0:
        if (!GameCommSys_BootCheck(GSYS_GetGameCommSystem(work->unk4))) {
            *state = 1;
        }
        break;
    case 1:
        if (work->unk50) {
            GameEvent_ChainNext(proc, CallFieldMapEntranceOutTransitionDefault(work->unk4, work->unk8, 0, 0));
        }
        work->unk0 = GFL_SndBGMGetID();
        GFL_SndBGMFadeOut(6);
        *state = 2;
        break;
    case 2:
        GameEvent_ChainNext(proc, CreateFieldCloseEvent(work->unk4, work->unk8));
        *state = 3;
        break;
    case 3:
        GSYS_QueueProc(work->unk4, (u32)OVERLAY_214_ID, data_ov036_021e1ab8, &work->unkC);
        *state = 4;
        break;
    case 4:
        if (!GSYS_GetProcMgrState(work->unk4)) {
            GFL_SndBGMPlay(work->unk0, 0xffff);
            GFL_SndBGMFadeIn(60);
            GameEvent_ChainNext(proc, EventFieldOpen_CreateHeadless(work->unk4));
            *state = 5;
        }
        break;
    case 5:
        if (work->unk50) {
            GameEvent_ChainNext(proc, CallFieldMapEntranceInTransition(work->unk4, work->unk8, 0, 0, 1, 0, 0));
        }
        *state = 6;
        break;
    case 6:
        return TRUE;
    }
    return FALSE;
}
