#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9694, 0, 0xecf8c, 0x98000, 0x54000, 0x98000, 1
    EvCameraWait
    ActorCmdExec 255, Movement_02C0
    ActorCmdWait
    ActorNew 10, 9, 2, 251, 337, 0
    FadeInBlackQ
    EvCameraReturn 60
    EvCameraWait
    FadeWait
    ActorCmdExec 251, Movement_02D0
    ActorCmdWait
    ActorMsg 1024, 0, 251, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 2, 251, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 4, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0288
    ActorCmdWait
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0258
    ActorCmdWait
    ActorMsg 1024, 6, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0298
    ActorCmdWait
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 8, 251, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 10, 251, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 11, 0, 0, 0
    ActorMsg 1024, 12, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0338
    ActorCmdWait
    ActorCmdExec 0, Movement_0344
    ActorCmdWait
    ActorCmdExec 251, Movement_02A0
    ActorCmdWait
    ActorMsg 1024, 13, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_02D8
    ActorCmdWait
    ActorDelete 251
    ActorNew 10, 9, 2, 251, 338, 0
    ActorCmdExec 251, Movement_02D8
    ActorCmdWait
    ActorMsg 1024, 14, 251, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 15, 0, 0, 0
    ActorMsg 1024, 16, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 17, 251, 0, 0
    ActorCmdExec 251, Movement_0318
    ActorCmdWait
    ActorMsg 1024, 18, 251, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 19, 0, 0, 0
    MsgWinCloseAll
    EvCameraMoveTo 9694, 0, 0xecf8c, 0x98000, 0x54000, 0x98000, 30
    FadeOutBlack
    FadeWait
    EvCameraWait
    RTReserveScript 30
    EvCameraRebind
    EvCameraEnd
    MapChangeCore 120, 418, 0, 170, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
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
    Move 11, 1
    MoveEnd
    Move 48, 1
    MoveEnd
    Move 49, 1
    MoveEnd
    Move 51, 1
    MoveEnd

Movement_0258:
    Move 50, 1
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

Movement_0288:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_0298:
    Move 35, 1
    MoveEnd

Movement_02A0:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 71, 1
    Move 169, 1
    Move 72, 1
    MoveEnd

Movement_02C0:
    Move 69, 1
    MoveEnd
    Move 13, 4
    MoveEnd

Movement_02D0:
    Move 50, 2
    MoveEnd

Movement_02D8:
    Move 0, 1
    Move 61, 1
    Move 3, 1
    Move 61, 1
    Move 1, 1
    Move 61, 1
    Move 2, 1
    Move 61, 1
    Move 0, 1
    Move 61, 1
    Move 3, 1
    Move 61, 1
    Move 1, 1
    Move 61, 1
    Move 2, 1
    MoveEnd

Movement_0318:
    Move 0, 1
    Move 61, 1
    Move 3, 1
    Move 61, 1
    Move 1, 1
    Move 61, 1
    Move 2, 1
    MoveEnd

Movement_0338:
    Move 11, 1
    Move 35, 1
    MoveEnd

Movement_0344:
    Move 10, 1
    Move 3, 1
    MoveEnd
