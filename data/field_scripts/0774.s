#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x2704000, 0x5004f, 0x2c78000, 30
    EvCameraWait
    ActorMsg 1024, 0, 2, 1, 1
    ActorMsgClose
    EvCameraReturn 30
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0075
    VMJump L_0083

L_0075:
    ActorCmdExec 2, Movement_0224
    VMJump L_00A4

L_0083:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0096
    VMJump L_00A4

L_0096:
    ActorCmdExec 2, Movement_0234
    VMJump L_00A4

L_00A4:
    ActorCmdWait
    Cmd_02D5 49, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00D3
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_011A

L_00D3:
    ParentActorMsg 1024, 2, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0104
    ParentActorMsg 1024, 3, 0, 0
    VMJump L_010E

L_0104:
    ParentActorMsg 1024, 4, 0, 0

L_010E:
    ParentActorMsg 1024, 5, 0, 0
    MsgWinCloseAll

L_011A:
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0131
    VMJump L_014D

L_0131:
    ActorCmdExec 2, Movement_01D4
    VMSleep 10
    ActorCmdExec 255, Movement_023C
    ActorCmdWait
    VMJump L_014D

L_014D:
    ActorWalkRoute 2, 632, 711, 1, 8, 0
    VMSleep 10
    ActorCmdExec 255, Movement_01D4
    VMSleep 15
    FadeEx 3, 0, 16, 4
    FadeExWait
    ActorCmdWait
    ActorDelete 2
    FlagSet 849
    VMSleep 30
    FadeEx 3, 16, 0, 4
    FadeExWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorDelete 10
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 458
    WorkSet 0x8001, 1
    RTCallGlobal 2807
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 943
    WorkSetConst 0x4074, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_01D4:
    Move 35, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 154, 1
    MoveEnd
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

Movement_0224:
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0

Movement_0234:
    Move 3, 1
    MoveEnd

Movement_023C:
    Move 0, 1
    Move 71, 1
    Move 13, 1
    Move 72, 1
    MoveEnd
