#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntry Script_9
    ScriptEntry Script_10
    ScriptEntry Script_11
    ScriptEntriesEnd

Script_11:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 10
    WorkSet 0x8001, 0
    RTCallGlobal 10536
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorWalkRoute 255, 9, 18, 0, 8, 0
    ActorNew 9, 20, 0, 251, 103, 0
    ActorDelete 254
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x98000, 0, 0xf5000, 40
    ActorWalkRoute 251, 8, 18, 0, 8, 0
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 0, 251, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 9, 16, 0, 8, 0
    ActorCmdWait
    ActorMsg 1024, 1, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_028C
    ActorCmdWait
    ActorMsg 1024, 2, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_015C
    ActorCmdWait
    ActorMsg 1024, 3, 251, 0, 0
    MsgWinCloseAll
    VMSleep 8
    ActorCmdExec 251, Movement_0174
    ActorCmdWait
    ActorMsg 1024, 4, 251, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 40
    ActorWalkRoute 251, 8, 20, 0, 8, 0
    VMSleep 40
    ActorCmdExec 255, Movement_028C
    ActorCmdWait
    SEPlay 1369
    ActorDelete 251
    SEWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    WorkSetConst 0x4113, 2
    FlagSet 415
    FlagReset 911
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_015C:
    Move 30, 1
    Move 63, 1
    Move 31, 1
    Move 63, 1
    Move 29, 1
    MoveEnd

Movement_0174:
    Move 182, 1
    MoveEnd

Script_10:
    ActorsPauseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 5, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 6, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 7, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 8, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 9, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 10, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 11, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 12, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 13, 2
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
    Move 32, 1
    MoveEnd

Movement_028C:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
