#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    VMStackPushFlag 455
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_005B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_02C7

L_005B:
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 449
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_008A
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    FlagSet 449
    VMJump L_0096

L_008A:
    ParentActorMsg 1024, 2, 0, 0
    MsgWaitAdvance

L_0096:
    ItemGetTMCount 0x8020
    WordSetNumber 0, 0x8020, 2
    ParentActorMsg 1024, 4, 0, 0
    MsgWaitAdvance
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMStackPushFlag 450
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00E0
    VMCall L_02CD
    FlagSet 450
    VMJump L_02C7

L_00E0:
    VMStackPush 0x8020
    VMStackPushConst 20
    VMStackCmp 4
    VMStackPushFlag 451
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0113
    VMCall L_02CD
    FlagSet 451
    VMJump L_02C7

L_0113:
    VMStackPush 0x8020
    VMStackPushConst 35
    VMStackCmp 4
    VMStackPushFlag 452
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0146
    VMCall L_02CD
    FlagSet 452
    VMJump L_02C7

L_0146:
    VMStackPush 0x8020
    VMStackPushConst 50
    VMStackCmp 4
    VMStackPushFlag 453
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0179
    VMCall L_02CD
    FlagSet 453
    VMJump L_02C7

L_0179:
    VMStackPush 0x8020
    VMStackPushConst 70
    VMStackCmp 4
    VMStackPushFlag 454
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01AC
    VMCall L_02CD
    FlagSet 454
    VMJump L_02C7

L_01AC:
    VMStackPush 0x8020
    VMStackPushConst 95
    VMStackCmp 1
    VMJumpIf 255, L_0208
    WordSetItemName 0, 45
    ParentActorMsg 1024, 5, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 45
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 455
    VMJump L_02C7

L_0208:
    WorkSetConst 0x8021, 0
    Random 0x8021, 5
    WorkCmpConst 0x8021, 0
    VMJumpIf 1, L_0227
    VMJump L_0237

L_0227:
    ParentActorMsg 1024, 8, 0, 0
    VMJump L_02C3

L_0237:
    WorkCmpConst 0x8021, 1
    VMJumpIf 1, L_024A
    VMJump L_025A

L_024A:
    ParentActorMsg 1024, 9, 0, 0
    VMJump L_02C3

L_025A:
    WorkCmpConst 0x8021, 2
    VMJumpIf 1, L_026D
    VMJump L_027D

L_026D:
    ParentActorMsg 1024, 10, 0, 0
    VMJump L_02C3

L_027D:
    WorkCmpConst 0x8021, 3
    VMJumpIf 1, L_0290
    VMJump L_02A0

L_0290:
    ParentActorMsg 1024, 11, 0, 0
    VMJump L_02C3

L_02A0:
    WorkCmpConst 0x8021, 4
    VMJumpIf 1, L_02B3
    VMJump L_02C3

L_02B3:
    ParentActorMsg 1024, 12, 0, 0
    VMJump L_02C3

L_02C3:
    LastKeyWait
    MsgWinCloseAll

L_02C7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_02CD:
    WordSetItemName 0, 45
    ParentActorMsg 1024, 5, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 45
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn
    .balign 4, 0
