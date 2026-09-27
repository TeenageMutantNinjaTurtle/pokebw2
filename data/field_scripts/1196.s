#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9698, 0, 0xecf56, 0x58000, 0x5500f, 0x58000, 1
    EvCameraWait
    ActorCmdExec 255, Movement_0340
    ActorCmdWait
    FadeInBlackQ
    EvCameraReturn 60
    EvCameraWait
    FadeWait
    ActorCmdExec 1, Movement_02C8
    ActorCmdWait
    ActorCmdExec 0, Movement_0320
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0328
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 4, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 5, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 7, 1, 0, 0
    MsgWinCloseAll
    InfoMsg 8, 1
    InfoMsgClose_0039
    ActorCmdExec 2, Movement_02C8
    ActorCmdWait
    ActorCmdExec 1, Movement_0310
    ActorCmdWait
    ActorMsg 1024, 9, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 10, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 11, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0318
    ActorCmdWait
    ActorMsg 1024, 12, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 13, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_02F8
    VMSleep 8
    ActorCmdExec 1, Movement_02F8
    ActorCmdWait
    ActorMsg 1024, 14, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0358
    ActorCmdWait
    ActorCmdExec 2, Movement_0310
    ActorCmdExec 1, Movement_0310
    ActorCmdWait
    VMSleep 60
    ActorMsg 1024, 15, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0328
    ActorCmdWait
    ActorMsg 1024, 16, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 17, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0308
    ActorCmdWait
    ActorMsg 1024, 18, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0368
    VMSleep 10
    ActorCmdExec 0, Movement_0300
    ActorCmdExec 1, Movement_0300
    ActorCmdWait
    EvCameraMoveTo 9688, 0, 0xed000, 0x58000, 0, 0x98000, 30
    EvCameraWait
    ActorMsg 1024, 19, 2, 2, 0
    MsgWinCloseAll
    EvCameraReturn 30
    ActorCmdExec 2, Movement_0348
    ActorCmdWait
    EvCameraWait
    VMSleep 30
    ActorCmdExec 0, Movement_0318
    ActorCmdExec 1, Movement_0310
    ActorCmdWait
    ActorMsg 1024, 20, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 21, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 22, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0350
    EvCameraMoveTo 9698, 0, 0xecf56, 0x58000, 0x5500f, 0x58000, 30
    VMSleep 8
    ActorCmdExec 0, Movement_0300
    FadeOutBlack
    FadeWait
    ActorCmdWait
    EvCameraWait
    RTReserveScript 19
    EvCameraRebind
    EvCameraEnd
    MapChangeCore 17, 12, 3, 6, 0
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

Movement_02C8:
    Move 12, 6
    MoveEnd
    Move 9, 1
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

Movement_02F8:
    Move 32, 1
    MoveEnd

Movement_0300:
    Move 33, 1
    MoveEnd

Movement_0308:
    Move 29, 1
    MoveEnd

Movement_0310:
    Move 34, 1
    MoveEnd

Movement_0318:
    Move 35, 1
    MoveEnd

Movement_0320:
    Move 75, 1
    MoveEnd

Movement_0328:
    Move 159, 1
    MoveEnd
    Move 71, 1
    Move 169, 1
    Move 72, 1
    MoveEnd

Movement_0340:
    Move 69, 1
    MoveEnd

Movement_0348:
    Move 13, 4
    MoveEnd

Movement_0350:
    Move 13, 6
    MoveEnd

Movement_0358:
    Move 14, 2
    Move 13, 3
    Move 35, 1
    MoveEnd

Movement_0368:
    Move 13, 1
    Move 15, 1
    Move 13, 1
    Move 9, 1
    Move 65, 1
    Move 32, 1
    MoveEnd
