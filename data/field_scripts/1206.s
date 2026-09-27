#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9690, 0, 0xecfe0, 0x78000, 0x3f000, 0x128000, 1
    EvCameraWait
    ActorCmdExec 255, Movement_0330
    ActorCmdWait
    FadeInBlack
    EvCameraReturn 60
    EvCameraWait
    FadeWait
    ActorMsg 1024, 0, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0310
    ActorCmdWait
    ActorMsg 1024, 1, 1, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 2, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0308
    ActorCmdWait
    ActorMsg 1024, 3, 1, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 4, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0318
    ActorCmdWait
    ActorMsg 1024, 5, 1, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0338
    ActorCmdWait
    ActorMsg 1024, 6, 0, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 7, 1, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 8, 0, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 1, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 10, 0, 1, 1
    ActorMsgClose
    ActorCmdExec 0, Movement_0344
    SEPlay 1653
    ActorCmdWait
    SEWait
    ActorCmdExec 0, Movement_0344
    VMSleep 4
    SEPlay 1653
    ActorCmdWait
    SEWait
    ActorMsg 1024, 11, 1, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0358
    ActorCmdWait
    ActorMsg 1024, 12, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0360
    ActorCmdWait
    ActorMsg 1024, 13, 1, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 14, 0, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 15, 1, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0368
    VMSleep 8
    ActorCmdExec 1, Movement_0374
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 2, Movement_0380
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 2, Movement_02E8
    ActorCmdWait
    ActorMsg 1024, 16, 2, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_038C
    ActorCmdWait
    ActorMsg 1024, 17, 2, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0280
    ActorCmdWait
    ActorMsg 1024, 18, 2, 1, 0
    ActorMsgVersioned 1024, 20, 19, 2, 1, 0
    MsgWinCloseAll
    VMSleep 15
    ActorMsg 1024, 21, 2, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_02E8
    ActorCmdWait
    ActorMsg 1024, 22, 2, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_02F0
    ActorCmdWait
    ActorMsg 1024, 23, 2, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_03A0
    EvCameraMoveTo 9690, 0, 0xecfe0, 0x78000, 0x3f000, 0x128000, 30
    FadeOutBlack
    FadeWait
    ActorCmdWait
    FlagSet 697
    EvCameraWait
    RTReserveScript 17
    EvCameraRebind
    EvCameraEnd
    MapChangeCore 104, 7, 0, 25, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0280:
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

Movement_02E8:
    Move 32, 1
    MoveEnd

Movement_02F0:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_0308:
    Move 75, 1
    MoveEnd

Movement_0310:
    Move 159, 1
    MoveEnd

Movement_0318:
    Move 161, 1
    MoveEnd
    Move 71, 1
    Move 169, 1
    Move 72, 1
    MoveEnd

Movement_0330:
    Move 69, 1
    MoveEnd

Movement_0338:
    Move 75, 1
    Move 39, 4
    MoveEnd

Movement_0344:
    Move 71, 1
    Move 19, 1
    Move 18, 1
    Move 72, 1
    MoveEnd

Movement_0358:
    Move 39, 4
    MoveEnd

Movement_0360:
    Move 38, 4
    MoveEnd

Movement_0368:
    Move 15, 1
    Move 13, 8
    MoveEnd

Movement_0374:
    Move 14, 1
    Move 13, 8
    MoveEnd

Movement_0380:
    Move 15, 2
    Move 13, 8
    MoveEnd

Movement_038C:
    Move 35, 1
    Move 34, 1
    Move 33, 1
    Move 182, 1
    MoveEnd

Movement_03A0:
    Move 13, 8
    MoveEnd
