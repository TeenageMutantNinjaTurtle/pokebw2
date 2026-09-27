#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9694, 0, 0xecf27, 0x78000, 0x48000, 0x38000, 1
    EvCameraWait
    ActorCmdExec 255, Movement_03C4
    ActorCmdExec 3, Movement_03C4
    ActorCmdExec 4, Movement_03C4
    ActorCmdExec 5, Movement_03C4
    ActorCmdWait
    FadeInBlackQ
    EvCameraMoveTo 9694, 0, 0xed02b, 0x78000, 0, 0x38000, 60
    EvCameraWait
    FadeWait
    ActorMsg 1024, 0, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 2, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 4, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 5, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 6, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 3, Movement_03F8
    ActorCmdWait
    ActorMsg 1024, 8, 3, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_03F8
    ActorCmdExec 5, Movement_03F8
    ActorCmdWait
    EvCameraMoveTo 9688, 0, 0xed000, 0xa3000, 0, 0x38000, 30
    ActorCmdExec 0, Movement_03A4
    ActorCmdExec 2, Movement_03A4
    VMSleep 10
    ActorCmdExec 1, Movement_03AC
    ActorCmdWait
    ActorCmdExec 0, Movement_039C
    ActorCmdExec 2, Movement_039C
    ActorCmdExec 1, Movement_03CC
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 9, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 10, 5, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_039C
    ActorCmdWait
    ActorMsg 1024, 11, 0, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 2
    ActorCmdExec 0, Movement_0354
    ActorCmdExec 2, Movement_0354
    ActorCmdExec 3, Movement_035C
    ActorCmdExec 4, Movement_035C
    ActorCmdExec 5, Movement_035C
    ActorCmdExec 1, Movement_0354
    ActorCmdWait
    FadeExWait
    VMSleep 90
    FadeEx 3, 16, 0, 2
    FadeExWait
    ActorCmdExec 0, Movement_03B4
    ActorCmdExec 2, Movement_03B4
    ActorCmdExec 1, Movement_03B4
    ActorCmdWait
    VMSleep 30
    ActorMsg 1024, 12, 3, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_038C
    ActorCmdWait
    ActorMsg 1024, 13, 4, 0, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_0384
    ActorCmdWait
    ActorMsg 1024, 14, 5, 0, 0
    MsgWinCloseAll
    ActorCmdExec 3, Movement_0404
    ActorCmdExec 4, Movement_0404
    ActorCmdExec 5, Movement_0404
    ActorCmdWait
    EvCameraMoveTo 9694, 0, 0xed02b, 0x78000, 0, 0x38000, 30
    EvCameraWait
    VMSleep 30
    ActorCmdExec 0, Movement_0394
    ActorCmdWait
    ActorMsg 1024, 15, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0384
    ActorCmdWait
    ActorMsg 1024, 16, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 17, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 18, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_038C
    ActorCmdExec 2, Movement_0394
    ActorCmdWait
    ActorMsg 1024, 19, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 20, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 21, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 22, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 23, 2, 0, 0
    MsgWinCloseAll
    EvCameraMoveTo 9694, 0, 0xecf27, 0x78000, 0x48000, 0x38000, 30
    FadeOutBlack
    FadeWait
    EvCameraWait
    RTReserveScript 15
    EvCameraRebind
    EvCameraEnd
    MapChangeCore 7, 11, 0, 3, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0354:
    Move 15, 1
    MoveEnd

Movement_035C:
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

Movement_0384:
    Move 32, 1
    MoveEnd

Movement_038C:
    Move 33, 1
    MoveEnd

Movement_0394:
    Move 34, 1
    MoveEnd

Movement_039C:
    Move 35, 1
    MoveEnd

Movement_03A4:
    Move 75, 1
    MoveEnd

Movement_03AC:
    Move 159, 1
    MoveEnd

Movement_03B4:
    Move 71, 1
    Move 169, 1
    Move 72, 1
    MoveEnd

Movement_03C4:
    Move 69, 1
    MoveEnd

Movement_03CC:
    Move 13, 1
    Move 15, 1
    MoveEnd
    Move 10, 1
    MoveEnd
    Move 14, 1
    Move 32, 1
    MoveEnd
    Move 15, 1
    Move 33, 1
    MoveEnd

Movement_03F8:
    Move 70, 1
    Move 184, 1
    MoveEnd

Movement_0404:
    Move 185, 1
    Move 69, 1
    MoveEnd
