#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0051
    ParentActorMsg 1024, 1, 0, 0
    VMJump L_005B

L_0051:
    ParentActorMsg 1024, 2, 0, 0

L_005B:
    ParentActorMsg 1024, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 620
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 4, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 8
    VMStackCmp 1
    VMJumpIf 255, L_00CE
    ActorWalkRoute 7, 9, 15, 1, 8, 0
    VMSleep 16
    ActorCmdExec 255, Movement_0170
    ActorCmdWait
    VMJump L_00EA

L_00CE:
    ActorWalkRoute 7, 8, 14, 1, 8, 1
    VMSleep 8
    ActorCmdExec 255, Movement_0170
    ActorCmdWait

L_00EA:
    ActorDelete 7
    VMSleep 2
    VMStackPush 0x8021
    VMStackPushConst 8
    VMStackCmp 1
    VMJumpIf 255, L_0119
    ActorNew 9, 15, 1, 251, 196, 0
    VMJump L_0127

L_0119:
    ActorNew 8, 14, 1, 251, 196, 0

L_0127:
    VMSleep 6
    ActorCmdExec 255, Movement_0190
    PVPlay 571, 0
    ActorMsg 1024, 5, 251, 0, 0
    PVWait
    MsgWaitAdvance
    ActorMsgClose
    ActorCmdWait
    ActorCmdExec 251, Movement_0188
    ActorCmdWait
    ActorDelete 251
    FlagSet 967
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 32, 1
    MoveEnd

Movement_0170:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_0188:
    Move 17, 4
    MoveEnd

Movement_0190:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
