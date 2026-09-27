#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd

Script_3:
    ActorsPauseAll
    VMStackPushFlag 295
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00AE
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 0
    TrainerCardGetSex 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0066
    ActorMsg 1024, 0, 8, 0, 0
    ActorMsgClose
    VMJump L_0074

L_0066:
    ActorMsg 1024, 1, 8, 0, 0
    ActorMsgClose

L_0074:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 537
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 2, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 295
    VMJump L_00C2

L_00AE:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_00C2:
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 255
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 12
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    VMStackPushFlag 2459
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01E9
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01AE
    ParentActorMsg 1024, 6, 0, 0
    VMJump L_01B8

L_01AE:
    ParentActorMsg 1024, 7, 0, 0

L_01B8:
    MsgWinCloseAll
    Cmd_0275 0, 24, 0
    SEPlay 1908
    SystemMsg 8, 0
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2459
    VMJump L_01FD

L_01E9:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose

L_01FD:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
