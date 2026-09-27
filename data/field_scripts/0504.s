#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    Cmd_017A 36
    FinishAllEvents
    ActorsUnpauseAll
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
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0087
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_009B

L_0087:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose

L_009B:
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
    PlayerGetGPos 0x8021, 0x8022
    ActorCmdExec 1, Movement_0374
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 8
    VMStackCmp 1
    VMJumpIf 255, L_00FE
    ActorCmdExec 1, Movement_0354
    VMSleep 8
    ActorCmdExec 255, Movement_034C
    ActorCmdWait
    VMJump L_0127

L_00FE:
    VMStackPush 0x8021
    VMStackPushConst 10
    VMStackCmp 1
    VMJumpIf 255, L_0127
    ActorCmdExec 1, Movement_034C
    VMSleep 8
    ActorCmdExec 255, Movement_0354
    ActorCmdWait

L_0127:
    ActorMsg 1024, 4, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_036C
    VMSleep 8
    ActorCmdExec 1, Movement_035C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 217
    WorkSet 0x8001, 1
    WorkSet 0x8002, 442
    WorkSet 0x8003, 5
    WorkSet 0x8004, 6
    WorkSet 0x8005, 6
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40e2
    VMStackPushConst 6
    VMStackCmp 5
    VMJumpIf 255, L_032C
    ParentActorMsg 1024, 7, 0, 0
    VMStackPush 0x40e2
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_023B
    ParentActorMsg 1024, 12, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 50
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40e2, 6
    VMJump L_0326

L_023B:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0

L_0247:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0311
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 312
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0295
    ActorMsg 1024, 8, 4, 0, 0
    WorkAdd 0x8023, 1
    VMJump L_0305

L_0295:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 313
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02D0
    ActorMsg 1024, 9, 4, 0, 0
    WorkAdd 0x8023, 1
    VMJump L_0305

L_02D0:
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPushFlag 314
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0305
    ActorMsg 1024, 10, 4, 0, 0
    WorkAdd 0x8023, 1

L_0305:
    WorkAdd 0x8024, 1
    VMJump L_0247

L_0311:
    WordSetNumber 0, 0x8023, 1
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0326:
    VMJump L_033A

L_032C:
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_033A:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_034C:
    Move 35, 1
    MoveEnd

Movement_0354:
    Move 34, 1
    MoveEnd

Movement_035C:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd

Movement_036C:
    Move 12, 1
    MoveEnd

Movement_0374:
    Move 75, 1
    MoveEnd
