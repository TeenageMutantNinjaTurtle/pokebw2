#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9694, 0, 0xecf12, 0x68000, 0x5d007, 0x38000, 1
    EvCameraWait
    ActorCmdExec 255, Movement_03B8
    ActorCmdWait
    FadeInBlackQ
    EvCameraReturn 60
    EvCameraWait
    FadeWait
    MultiMsg 0, 8, 5, 1
    VMSleep 25
    MultiMsg 1, 19, 14, 2
    VMSleep 25
    MsgWinCloseNo 1
    VMSleep 10
    MsgWinCloseNo 2
    VMSleep 40
    MultiMsg 2, 8, 5, 3
    VMSleep 25
    MultiMsg 3, 19, 14, 4
    VMSleep 25
    MsgWinCloseNo 3
    VMSleep 10
    MsgWinCloseNo 4
    VMSleep 40
    MultiMsg 4, 8, 5, 5
    VMSleep 40
    MsgWinCloseNo 5
    VMSleep 50
    ScreamMsg 5, 0
    InfoMsgClose_0039
    ActorCmdExec 0, Movement_0360
    VMSleep 10
    ActorCmdExec 1, Movement_0360
    ActorCmdWait
    ActorCmdExec 2, Movement_03D8
    ActorMsg 1024, 6, 0, 0, 0
    ActorCmdWait
    MsgWinCloseAll
    VMSleep 20
    ActorCmdExec 2, Movement_03E0
    VMSleep 20
    ActorCmdExec 0, Movement_0370
    ActorCmdWait
    ActorMsg 1024, 7, 2, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 8, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0368
    VMSleep 10
    ActorCmdExec 1, Movement_0368
    ActorCmdWait
    ActorMsg 1024, 9, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_03C8
    ActorCmdWait
    ActorCmdExec 0, Movement_0358
    ActorCmdExec 2, Movement_0358
    ActorCmdWait
    ActorMsg 1024, 10, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0318
    ActorCmdWait
    ActorMsg 1024, 11, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0368
    ActorCmdExec 0, Movement_0370
    ActorCmdWait
    ActorMsg 1024, 12, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0380
    ActorCmdWait
    ActorMsg 1024, 13, 1, 0, 0
    ActorCmdExec 1, Movement_0378
    ActorCmdWait
    ActorMsg 1024, 14, 1, 0, 0
    ActorCmdExec 1, Movement_0380
    ActorCmdWait
    ActorMsg 1024, 15, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 16, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_03F8
    ActorCmdWait
    ActorCmdExec 1, Movement_0368
    ActorCmdWait
    ActorMsg 1024, 17, 0, 0, 0
    ActorCmdExec 0, Movement_0388
    ActorCmdWait
    ActorMsg 1024, 18, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 19, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0390
    ActorCmdWait
    ActorMsg 1024, 20, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 21, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_040C
    ActorCmdWait
    ActorMsg 1024, 22, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0414
    VMSleep 15
    ActorCmdExec 0, Movement_0360
    ActorCmdWait
    ActorMsg 1024, 23, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0388
    ActorCmdExec 0, Movement_0390
    ActorCmdWait
    ActorMsg 1024, 24, 0, 0, 1
    ActorMsgClose
    VMSleep 20
    ActorMsg 1024, 25, 2, 0, 1
    ActorMsgClose
    ActorCmdExec 2, Movement_034C
    ActorCmdExec 0, Movement_0340
    ActorCmdWait
    EvCameraMoveTo 9694, 0, 0xecf12, 0x68000, 0x5d007, 0x38000, 30
    FadeOutBlack
    FadeWait
    EvCameraWait
    RTReserveScript 16
    EvCameraRebind
    EvCameraEnd
    MapChangeCore 114, 17, 0, 15, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_0318:
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

Movement_0340:
    Move 39, 1
    Move 19, 1
    MoveEnd

Movement_034C:
    Move 38, 1
    Move 18, 1
    MoveEnd

Movement_0358:
    Move 0, 1
    MoveEnd

Movement_0360:
    Move 1, 1
    MoveEnd

Movement_0368:
    Move 2, 1
    MoveEnd

Movement_0370:
    Move 3, 1
    MoveEnd

Movement_0378:
    Move 32, 1
    MoveEnd

Movement_0380:
    Move 33, 1
    MoveEnd

Movement_0388:
    Move 34, 1
    MoveEnd

Movement_0390:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 71, 1
    Move 169, 1
    Move 72, 1
    MoveEnd

Movement_03B8:
    Move 69, 1
    MoveEnd
    Move 13, 4
    MoveEnd

Movement_03C8:
    Move 8, 1
    Move 10, 1
    Move 32, 1
    MoveEnd

Movement_03D8:
    Move 16, 6
    MoveEnd

Movement_03E0:
    Move 3, 1
    Move 75, 1
    Move 19, 2
    Move 16, 1
    Move 32, 1
    MoveEnd

Movement_03F8:
    Move 10, 1
    Move 65, 1
    Move 1, 1
    Move 3, 1
    MoveEnd

Movement_040C:
    Move 15, 1
    MoveEnd

Movement_0414:
    Move 13, 3
    Move 32, 1
    MoveEnd
