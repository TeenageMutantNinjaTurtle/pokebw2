#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPushFlag 2457
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_005C
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    Cmd_0275 0, 14, 0
    SEPlay 1908
    SystemMsg 1, 0
    SEWait
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2457
    VMJump L_0070

L_005C:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0070:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    VMStackPushFlag 282
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_014A

L_00C1:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    PokePartyFindBySpecies 6, 0x8020, 0x8021
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0102
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_014A

L_0102:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    MsgWinCloseAll
    VMCall L_0150
    ParentActorMsg 1024, 5, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 36
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 282

L_014A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0150:
    WorkSetConst 0x8022, 0
    PlayerGetDir 0x8022
    WorkCmpConst 0x8022, 0
    VMJumpIf 1, L_016D
    VMJump L_017B

L_016D:
    ActorCmdExec 2, Movement_031C
    VMJump L_01DE

L_017B:
    WorkCmpConst 0x8022, 3
    VMJumpIf 1, L_018E
    VMJump L_019C

L_018E:
    ActorCmdExec 2, Movement_0350
    VMJump L_01DE

L_019C:
    WorkCmpConst 0x8022, 2
    VMJumpIf 1, L_01AF
    VMJump L_01BD

L_01AF:
    ActorCmdExec 2, Movement_0384
    VMJump L_01DE

L_01BD:
    WorkCmpConst 0x8022, 1
    VMJumpIf 1, L_01D0
    VMJump L_01DE

L_01D0:
    ActorCmdExec 2, Movement_03B8
    VMJump L_01DE

L_01DE:
    ActorCmdWait
    WorkSetConst 0x8022, 0
    VMReturn

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4108
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02D0
    ParentActorMsg 1024, 7, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02BC
    ItemSub 30, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02A8
    MsgWinCloseAll
    SEPlay 2017
    SEWait
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    PlayerGetDir 0x8010
    VMStackPush 0x8010
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_027A
    ActorCmdExec 3, Movement_02F8
    VMJump L_0282

L_027A:
    ActorCmdExec 3, Movement_0308

L_0282:
    VMSleep 20
    ActorCmdExec 255, Movement_0314
    ActorCmdWait
    ActorDelete 3
    WorkSetConst 0x4108, 2
    FlagSet 859
    FlagReset 860
    VMJump L_02B6

L_02A8:
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02B6:
    VMJump L_02CA

L_02BC:
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02CA:
    VMJump L_02F1

L_02D0:
    VMStackPush 0x4108
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_02F1
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02F1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_02F8:
    Move 36, 4
    Move 16, 1
    Move 18, 10
    MoveEnd

Movement_0308:
    Move 38, 4
    Move 18, 10
    MoveEnd

Movement_0314:
    Move 2, 1
    MoveEnd

Movement_031C:
    Move 14, 1
    Move 13, 1
    Move 35, 1
    Move 13, 1
    Move 15, 1
    Move 32, 1
    Move 15, 1
    Move 12, 1
    Move 34, 1
    Move 12, 1
    Move 14, 1
    Move 33, 1
    MoveEnd

Movement_0350:
    Move 12, 1
    Move 14, 1
    Move 33, 1
    Move 14, 1
    Move 13, 1
    Move 35, 1
    Move 13, 1
    Move 15, 1
    Move 32, 1
    Move 15, 1
    Move 12, 1
    Move 34, 1
    MoveEnd

Movement_0384:
    Move 12, 1
    Move 15, 1
    Move 33, 1
    Move 15, 1
    Move 13, 1
    Move 34, 1
    Move 13, 1
    Move 14, 1
    Move 32, 1
    Move 14, 1
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_03B8:
    Move 14, 1
    Move 12, 1
    Move 35, 1
    Move 12, 1
    Move 15, 1
    Move 33, 1
    Move 15, 1
    Move 13, 1
    Move 34, 1
    Move 13, 1
    Move 14, 1
    Move 32, 1
    MoveEnd
