#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

L_003A:
    VMStackPushFlag 364
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_005D
    ObjInitWarpGPos 1, 34, 0, 47
    VMJump L_0067

L_005D:
    ObjInitWarpGPos 2, 34, 0, 47

L_0067:
    VMReturn

Script_1:
    VMCall L_003A
    VMHalt

Script_8:
    VMCall L_003A
    VMHalt

Script_2:
    VMHalt

Script_7:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    FlagReset 878
    FlagReset 880
    ActorAdd 9
    ActorAdd 10
    ActorWalkRoute 9, 61, 36, 1, 8, 1
    VMSleep 40
    ActorCmdExec 255, Movement_02FC
    ActorCmdWait
    ActorMsg 1024, 2, 9, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 10, 60, 41, 1, 8, 1
    VMSleep 8
    ActorCmdExec 6, Movement_0304
    ActorCmdExec 11, Movement_0304
    VMSleep 16
    ActorCmdExec 9, Movement_0324
    ActorCmdExec 255, Movement_0304
    ActorCmdWait
    InfoMsg 3, 2
    MsgWinCloseAll
    ActorMsg 1024, 4, 6, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 6, 61, 45, 1, 8, 1
    ActorWalkRoute 11, 61, 45, 1, 8, 0
    VMSleep 16
    ActorCmdExec 10, Movement_0304
    ActorCmdWait
    ActorDelete 11
    ActorDelete 6
    ActorWalkRoute 9, 61, 39, 1, 8, 1
    VMSleep 4
    ActorWalkRoute 255, 60, 39, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_0304
    ActorCmdWait
    ActorMsg 1024, 5, 9, 5, 0
    MsgWinCloseAll
    ActorCmdExec 10, Movement_0324
    ActorCmdWait
    ActorCmdExec 10, Movement_02FC
    ActorCmdWait
    ActorMsg 1024, 6, 10, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 7, 9, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 8, 10, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 9, 5, 0
    MsgWinCloseAll
    ActorWalkRoute 9, 61, 51, 1, 4, 1
    VMSleep 12
    ActorCmdExec 10, Movement_0304
    ActorCmdWait
    ActorCmdExec 10, Movement_02FC
    ActorCmdWait
    ActorMsg 1024, 10, 10, 4, 0
    MsgWinCloseAll
    ActorWalkRoute 10, 60, 51, 1, 8, 1
    ActorCmdWait
    ActorDelete 9
    ActorDelete 10
    FlagSet 876
    FlagSet 878
    FlagSet 880
    FlagSet 857
    WorkSetConst 0x4070, 2
    Cmd_0262 1, 33
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    Move 14, 1
    Move 33, 1
    MoveEnd

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorMsg 1024, 0, 11, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 1, 6, 5, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorMsg 1024, 11, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorMsg 1024, 12, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd

Movement_02FC:
    Move 32, 1
    MoveEnd

Movement_0304:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd

Movement_0324:
    Move 159, 1
    MoveEnd
