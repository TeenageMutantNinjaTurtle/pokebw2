#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    ActorCmdExec 0, Movement_0384
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 18
    VMStackCmp 1
    VMJumpIf 255, L_0061
    WorkSub 0x8022, 1
    ActorWalkRoute 0, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    VMJump L_0081

L_0061:
    WorkSub 0x8022, 1
    ActorWalkRoute 0, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 0, Movement_0350
    ActorCmdWait

L_0081:
    WordSetPlayerName 0
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0368
    ActorCmdWait
    VMSleep 8
    ActorCmdExec 0, Movement_0350
    ActorCmdWait
    ActorMsg 1024, 1, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4115, 3
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SystemMsg 2, 2
    LastKeyWait
    InfoMsgClose
    FlagReset 916
    ActorCmdExec 0, Movement_0348
    ActorCmdExec 255, Movement_0358
    ActorCmdWait
    ActorWalkRoute 255, 18, 17, 1, 8, 0
    ActorCmdWait
    ActorWalkRoute 0, 17, 19, 1, 8, 0
    ActorCmdWait
    VMSleep 16
    ActorAdd 2
    ActorMoveLinear 2, 18, 0, 15, 32
    ActorSetGPos 2, 18, 0, 15, 1
    PVPlay 480, 0
    InfoMsg 3, 2
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    ActorMsg 1024, 4, 0, 0, 0
    MsgWinCloseAll
    VMSleep 16
    ActorAdd 3
    ActorMoveLinear 3, 16, 0, 17, 32
    ActorSetGPos 3, 16, 0, 17, 1
    PVPlay 481, 0
    InfoMsg 5, 2
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0340
    VMSleep 3
    ActorCmdExec 0, Movement_0340
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    VMSleep 16
    ActorAdd 1
    ActorMoveLinear 1, 20, 0, 17, 32
    ActorSetGPos 1, 20, 0, 17, 1
    PVPlay 482, 0
    InfoMsg 7, 2
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0338
    VMSleep 3
    ActorCmdExec 0, Movement_0338
    ActorCmdWait
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0348
    VMSleep 3
    ActorCmdExec 0, Movement_0348
    ActorCmdWait
    VMSleep 32
    ActorCmdExec 2, Movement_03A8
    ActorCmdWait
    ActorMoveLinear 2, 19, 0, 20, 16
    ActorCmdExec 2, Movement_0398
    ActorCmdWait
    ActorMoveLinear 2, 18, 0, 24, 10
    ActorDelete 2
    SystemMsg 9, 2
    InfoMsgClose
    VMSleep 8
    ActorCmdExec 3, Movement_03A0
    ActorCmdWait
    ActorMoveLinear 3, 15, 0, 20, 12
    ActorCmdExec 3, Movement_0398
    ActorCmdWait
    ActorMoveLinear 3, 18, 0, 24, 12
    ActorDelete 3
    SystemMsg 10, 2
    InfoMsgClose
    VMSleep 8
    ActorCmdExec 1, Movement_03A8
    ActorCmdWait
    ActorMoveLinear 1, 21, 0, 20, 10
    ActorCmdExec 1, Movement_0398
    ActorCmdWait
    ActorMoveLinear 1, 18, 0, 24, 12
    ActorDelete 1
    SystemMsg 11, 2
    InfoMsgClose
    VMSleep 16
    ActorCmdExec 255, Movement_0350
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 12, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 0, 18, 27, 1, 8, 1
    ActorCmdWait
    ActorDelete 0
    WorkSetConst 0x4115, 4
    WorkSetConst 0x4116, 1
    WorkSetConst 0x4117, 1
    WorkSetConst 0x4118, 1
    FlagSet 916
    FlagSet 917
    Cmd_0262 0, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0338:
    Move 35, 1
    MoveEnd

Movement_0340:
    Move 34, 1
    MoveEnd

Movement_0348:
    Move 32, 1
    MoveEnd

Movement_0350:
    Move 33, 1
    MoveEnd

Movement_0358:
    Move 12, 1
    MoveEnd
    Move 13, 1
    MoveEnd

Movement_0368:
    Move 61, 1
    Move 35, 1
    Move 34, 1
    Move 61, 1
    MoveEnd
    Move 75, 1
    MoveEnd

Movement_0384:
    Move 33, 1
    Move 75, 1
    MoveEnd
    Move 0, 1
    MoveEnd

Movement_0398:
    Move 1, 1
    MoveEnd

Movement_03A0:
    Move 2, 1
    MoveEnd

Movement_03A8:
    Move 3, 1
    MoveEnd
