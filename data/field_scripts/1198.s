#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9694, 0, 0xecfca, 0x68000, 0x53000, 0x58000, 1
    EvCameraWait
    ActorCmdExec 255, Movement_02A8
    ActorCmdWait
    FadeInBlackQ
    EvCameraReturn 60
    EvCameraWait
    FadeWait
    ActorMsg 1024, 0, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0290
    ActorCmdWait
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 2, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_02B0
    ActorCmdWait
    ActorMsg 1024, 4, 1, 0, 0
    MsgWinCloseAll
    MultiMsg 5, 8, 5, 1
    VMSleep 50
    MsgWinCloseNo 1
    ActorCmdExec 1, Movement_02B8
    ActorCmdWait
    ActorMsg 1024, 6, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_02C4
    ActorCmdWait
    ActorMsg 1024, 7, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_02CC
    ActorCmdWait
    ActorMsg 1024, 8, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_02B8
    ActorCmdWait
    ActorMsg 1024, 10, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_02C4
    ActorCmdWait
    ActorMsg 1024, 11, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_02C4
    ActorCmdWait
    ActorMsg 1024, 12, 1, 0, 0
    MsgWinCloseAll
    MultiMsg 5, 8, 5, 1
    VMSleep 50
    MsgWinCloseNo 1
    ActorMsg 1024, 13, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0288
    ActorCmdWait
    ActorMsg 1024, 14, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 15, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 16, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 17, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 18, 1, 0, 0
    MsgWinCloseAll
    VMSleep 60
    ActorMsg 1024, 19, 0, 0, 0
    MsgWinCloseAll
    EvCameraMoveTo 9694, 0, 0xecfca, 0x68000, 0x53000, 0x58000, 30
    FadeOutBlack
    FadeWait
    EvCameraWait
    RTReserveScript 10
    EvCameraRebind
    EvCameraEnd
    MapChangeCore 107, 78, 0, 271, 0
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
    Move 12, 6
    MoveEnd
    Move 9, 1
    MoveEnd
    Move 39, 1
    Move 19, 1
    MoveEnd
    Move 38, 1
    Move 18, 1
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
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_0288:
    Move 75, 1
    MoveEnd

Movement_0290:
    Move 159, 1
    MoveEnd
    Move 71, 1
    Move 169, 1
    Move 72, 1
    MoveEnd

Movement_02A8:
    Move 69, 1
    MoveEnd

Movement_02B0:
    Move 11, 1
    MoveEnd

Movement_02B8:
    Move 1, 1
    Move 2, 1
    MoveEnd

Movement_02C4:
    Move 18, 1
    MoveEnd

Movement_02CC:
    Move 11, 2
    MoveEnd
