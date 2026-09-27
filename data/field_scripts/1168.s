#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_3:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    CallPlaceNameDisp
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 612, 0
    ScreamMsg 0, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    WorkSetConst 0x8020, 0
    WorkOr 0x8020, 2
    WorkOr 0x8020, 128
    CallWildBattleEx 612, 60, 0, 0x8020
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_007E
    FlagSet 946
    ActorDelete 1
    CallWildBattleEnd
    VMJump L_0080

L_007E:
    CallWildLose

L_0080:
    WildBattleGetResult 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0097
    VMJump L_00A1

L_0097:
    FlagSet 420
    VMJump L_00D1

L_00A1:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_00C1
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_00C1
    VMJump L_00D1

L_00C1:
    SystemMsg 1, 2
    LastKeyWait
    InfoMsgClose
    VMJump L_00D1

L_00D1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 2, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_012A
    ActorMsg 1024, 3, 0, 2, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    RTReserveScript 11
    MapChangeCore 111, 14, 0, 19, 1
    VMJump L_013A

L_012A:
    ActorMsg 1024, 4, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_013A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
