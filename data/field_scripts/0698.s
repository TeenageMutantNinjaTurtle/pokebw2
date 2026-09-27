#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0047
    ActorSetGPos 2, 3, 0, 8, 3

L_0047:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_00C4

L_00B0:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose

L_00C4:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 7
    VMStackCmp 1
    VMJumpIf 255, L_0101
    ActorCmdExec 2, Movement_0154
    VMSleep 40
    ActorCmdExec 255, Movement_0184
    ActorCmdWait
    VMJump L_012A

L_0101:
    VMStackPush 0x8022
    VMStackPushConst 9
    VMStackCmp 1
    VMJumpIf 255, L_012A
    ActorCmdExec 2, Movement_0160
    VMSleep 40
    ActorCmdExec 255, Movement_017C
    ActorCmdWait

L_012A:
    ActorMsg 1024, 3, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_018C
    VMSleep 8
    ActorCmdExec 2, Movement_016C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0154:
    Move 75, 1
    Move 32, 1
    MoveEnd

Movement_0160:
    Move 75, 1
    Move 33, 1
    MoveEnd

Movement_016C:
    Move 35, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_017C:
    Move 32, 1
    MoveEnd

Movement_0184:
    Move 33, 1
    MoveEnd

Movement_018C:
    Move 15, 1
    MoveEnd
