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
    WorkSetConst 0x8023, 0

Script_1:
    RTCGetDayPart 0x8023
    VMStackPush 0x8023
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0063
    FlagReset 786
    FlagReset 783
    VMJump L_006B

L_0063:
    FlagSet 786
    FlagSet 783

L_006B:
    VMStackPush 0x40cc
    VMStackPushConst 4
    VMStackCmp 5
    VMJumpIf 255, L_0086
    DebugPrint 2323
    FlagReset 783

L_0086:
    VMHalt

Script_2:
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x40cc, 2
    ActorWalkRoute 255, 6, 5, 1, 8, 1
    ActorCmdWait
    FlagReset 782
    ActorAdd 2
    SEPlay 1369
    SEWait
    ActorWalkRoute 2, 6, 6, 1, 8, 1
    ActorCmdWait
    ActorWalkRoute 2, 7, 5, 1, 8, 0
    ActorCmdWait
    RTCGetDayPart 0x8023
    VMStackPush 0x8023
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0113
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll

L_0113:
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0320
    VMSleep 3
    ActorCmdExec 255, Movement_0318
    ActorCmdWait
    ActorMsg 1024, 3, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0318
    ActorCmdWait
    ActorMsg 1024, 4, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0328
    ActorCmdExec 2, Movement_0328
    VMSleep 3
    ActorCmdExec 255, Movement_0328
    ActorCmdWait
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 6, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0338
    ActorCmdWait
    ActorMsg 1024, 8, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 10, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0318
    VMSleep 8
    ActorCmdExec 2, Movement_0350
    ActorCmdExec 255, Movement_0350
    ActorCmdWait
    ActorMsg 1024, 11, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_02EC
    ActorCmdExec 2, Movement_0300
    VMSleep 16
    ActorCmdExec 255, Movement_0330
    ActorCmdWait
    SEPlay 1369
    ActorDelete 1
    ActorDelete 2
    SEWait
    FlagSet 781
    FlagSet 782
    FlagReset 784
    WorkSetConst 0x40ce, 1
    Cmd_0262 3, 6
    Cmd_0262 0, 5
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40cc
    VMStackPushConst 4
    VMStackCmp 5
    VMJumpIf 255, L_0284
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02C7

L_0284:
    ParentActorMsg 1024, 13, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02B9
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02C7

L_02B9:
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02C7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_02EC:
    Move 13, 2
    Move 15, 1
    Move 13, 2
    Move 69, 0
    MoveEnd

Movement_0300:
    Move 63, 1
    Move 13, 2
    Move 14, 1
    Move 13, 2
    Move 69, 0
    MoveEnd

Movement_0318:
    Move 35, 1
    MoveEnd

Movement_0320:
    Move 34, 1
    MoveEnd

Movement_0328:
    Move 32, 1
    MoveEnd

Movement_0330:
    Move 33, 1
    MoveEnd

Movement_0338:
    Move 75, 1
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd

Movement_0350:
    Move 2, 1
    MoveEnd
    Move 3, 1
    MoveEnd
