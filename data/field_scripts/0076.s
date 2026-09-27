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

Script_7:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    RTCGetDate 0x8020, 0x8021
    WorkCmpConst 0x8021, 2
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 3
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 5
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 7
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 11
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 13
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 17
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 19
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 23
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 29
    VMJumpIf 1, L_00C9
    WorkCmpConst 0x8021, 31
    VMJumpIf 1, L_00C9
    VMJump L_00D5

L_00C9:
    WorkSetConst 0x4001, 1
    VMJump L_00DB

L_00D5:
    WorkSetConst 0x4001, 0

L_00DB:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    VMHalt

Script_6:
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0106
    BMSetVisible 8, 0, 10, 0

L_0106:
    VMHalt

Script_8:
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0125
    BMSetVisible 8, 0, 10, 0

L_0125:
    VMHalt

Script_2:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    CallPlaceNameDisp
    VMSleep 70
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_02BC
    ActorCmdExec 255, Movement_02BC
    ActorCmdWait
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_02C4
    ActorCmdWait
    ActorMsg 1024, 2, 1, 0, 0
    MsgWinCloseAll
    SEPlay 2177
    SEWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9467, 0, 0x17b000, 0x136000, 0, 0x98000, 56
    ActorWalkRoute 1, 16, 9, 1, 8, 0
    ActorCmdExec 255, Movement_02D4
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 3, 1, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 56
    ActorCmdExec 1, Movement_0208
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdWait
    SEPlay 1369
    ActorDelete 1
    SEWait
    Cmd_0263 1
    WorkSetConst 0x40ae, 2
    WorkSetConst 0x40e2, 1
    FlagSet 748
    Cmd_0262 1, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0208:
    Move 12, 10
    MoveEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 4, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0263
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    RTReserveScript 5
    MapChangeCore 452, 6, 0, 5, 1
    VMJump L_0273

L_0263:
    ActorMsg 1024, 6, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0273:
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

Movement_02BC:
    Move 32, 1
    MoveEnd

Movement_02C4:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_02D4:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Script_3:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    VMStackPush 0x40ae
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_030B
    CallPlaceNameDisp
    DebugPrint 22

L_030B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMStackPushFlag 2478
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_035C
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0370

L_035C:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose

L_0370:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
