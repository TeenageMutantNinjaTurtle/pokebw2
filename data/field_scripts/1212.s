#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xe8000, 0x5d000, 0xf8000, 1
    EvCameraWait
    ActorCmdExec 255, Movement_0214
    ActorCmdWait
    FadeInBlackQ
    EvCameraReturn 60
    EvCameraWait
    FadeWait
    Cmd_02B5 1, 0
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0194
    ActorCmdWait
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_021C
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0240
    ActorCmdWait
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0264
    ActorCmdWait
    ActorMsg 1024, 4, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_029C
    ActorCmdWait
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_02B8
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_02E0
    ActorCmdWait
    ActorMsg 1024, 7, 0, 0, 0
    ActorMsg 1024, 8, 0, 0, 0
    ActorMsg 1024, 9, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0320
    EvCameraMoveTo 9688, 0, 0xed000, 0xe8000, 0x5d000, 0xf8000, 30
    FadeOutBlack
    FadeWait
    EvCameraWait
    ActorCmdWait
    VMStackPush 0x4087
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0153
    RTReserveScript 17
    VMJump L_0157

L_0153:
    RTReserveScript 18

L_0157:
    EvCameraRebind
    EvCameraEnd
    VMStackPush 0x4087
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0180
    MapChangeCore 77, 14, 0, 16, 0
    VMJump L_018C

L_0180:
    MapChangeCore 77, 17, 0, 4, 0

L_018C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0194:
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
    Move 71, 1
    Move 169, 1
    Move 72, 1
    MoveEnd

Movement_0214:
    Move 69, 1
    MoveEnd

Movement_021C:
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    MoveEnd

Movement_0240:
    Move 15, 2
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    MoveEnd

Movement_0264:
    Move 12, 2
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 14, 2
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    MoveEnd

Movement_029C:
    Move 14, 2
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    MoveEnd

Movement_02B8:
    Move 13, 2
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    MoveEnd

Movement_02E0:
    Move 15, 2
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 12, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    MoveEnd

Movement_0320:
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    Move 3, 1
    Move 0, 1
    Move 2, 1
    Move 1, 1
    MoveEnd
