#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

L_0036:
    VMStackPush 0x4106
    VMStackPushConst 3
    VMStackCmp 5
    VMJumpIf 255, L_0053
    ObjInitWarpGPos 2, 787, 0xfffd, 247

L_0053:
    VMReturn

Script_1:
    VMCall L_0036
    VMHalt

Script_2:
    VMStackPush 0x4106
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0082
    ActorSetGPos 9, 797, 0xfffb, 242, 3
    VMJump L_00E6

L_0082:
    VMStackPush 0x4106
    VMStackPushConst 4
    VMStackCmp 1
    VMStackPushFlag 855
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00B7
    ActorSetGPos 9, 798, 0xfffb, 241, 3
    VMJump L_00E6

L_00B7:
    VMStackPush 0x4106
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPushFlag 857
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00E6
    ActorSetGPos 11, 796, 0xfffb, 242, 3

L_00E6:
    VMHalt

Script_3:
    VMCall L_0036
    VMHalt

Script_4:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    FlagReset 855
    FlagReset 856
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x3219000, 0xfffaffb1, 0xf02000, 48
    EvCameraWait
    VMSleep 80
    EvCameraMoveToDefault 48
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    SEPlay 1369
    ActorAdd 9
    SEWait
    ActorCmdExec 9, Movement_06B4
    ActorCmdWait
    PlayerGetGPos 0x8022, 0x8023
    WorkSub 0x8022, 1
    ActorWalkRoute 9, 0x8022, 0x8023, 1, 8, 1
    VMSleep 16
    ActorCmdExec 255, Movement_06A4
    ActorCmdWait
    ActorMsg 1024, 0, 9, 0, 0
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x3204000, 0xfffaffb1, 0xf28000, 26
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 239
    VMStackCmp 1
    VMJumpIf 255, L_01C5
    ActorCmdExec 9, Movement_02D0
    VMSleep 20
    ActorCmdExec 255, Movement_02A4
    VMJump L_0242

L_01C5:
    VMStackPush 0x8023
    VMStackPushConst 240
    VMStackCmp 1
    VMJumpIf 255, L_01F2
    ActorCmdExec 9, Movement_02DC
    VMSleep 20
    ActorCmdExec 255, Movement_02B0
    VMJump L_0242

L_01F2:
    VMStackPush 0x8023
    VMStackPushConst 241
    VMStackCmp 1
    VMJumpIf 255, L_021F
    ActorCmdExec 9, Movement_02E8
    VMSleep 20
    ActorCmdExec 255, Movement_02BC
    VMJump L_0242

L_021F:
    VMStackPush 0x8023
    VMStackPushConst 242
    VMStackCmp 1
    VMJumpIf 255, L_0242
    ActorCmdExec 9, Movement_02F4
    ActorCmdExec 255, Movement_02C4

L_0242:
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 1, 9, 0, 0
    MsgWinCloseAll
    InfoMsg 2, 2
    MsgWinCloseAll
    Cmd_02E8 1, 1
    SEPlay 2199
    InfoMsg 3, 2
    MsgWinCloseAll
    SEWait
    EvCameraMoveToDefault 1
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    MapReplaceSetEvent 5, 0, 0
    MapReplaceSetEvent 6, 1, 1
    WorkSetConst 0x4106, 2
    RTReserveScript 7
    MapChangeCore 463, 797, 65531, 241, 3
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_02A4:
    Move 13, 2
    Move 15, 1
    MoveEnd

Movement_02B0:
    Move 13, 1
    Move 15, 1
    MoveEnd

Movement_02BC:
    Move 15, 1
    MoveEnd

Movement_02C4:
    Move 12, 1
    Move 15, 1
    MoveEnd

Movement_02D0:
    Move 13, 3
    Move 15, 2
    MoveEnd

Movement_02DC:
    Move 13, 2
    Move 15, 2
    MoveEnd

Movement_02E8:
    Move 13, 1
    Move 15, 2
    MoveEnd

Movement_02F4:
    Move 15, 2
    MoveEnd

Script_7:
    ActorsPauseAll
    Cmd_02E9 1, 1
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 10, Movement_04BC
    ActorCmdWait
    ActorMsg 1024, 4, 10, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 5, 9, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 6, 10, 0, 0
    ActorMsg 1024, 7, 10, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 8, 9, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 10, 0, 0
    MsgWinCloseAll
    ActorCmdExec 10, Movement_06AC
    ActorCmdWait
    ActorMsg 1024, 10, 10, 0, 0
    MsgWinCloseAll
    ActorCmdExec 10, Movement_06A4
    ActorCmdWait
    ActorMsg 1024, 11, 10, 0, 0
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x3198000, 0xfffaffb1, 0xf18000, 40
    ActorCmdExec 10, Movement_04C4
    VMSleep 32
    ActorCmdExec 255, Movement_06A4
    ActorCmdExec 9, Movement_06A4
    ActorCmdWait
    SEPlay 1369
    ActorDelete 10
    SEWait
    EvCameraWait
    ActorMsg 1024, 12, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_0694
    ActorCmdExec 255, Movement_069C
    ActorCmdWait
    ActorMsg 1024, 13, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_04D8
    VMSleep 4
    ActorCmdExec 255, Movement_06AC
    ActorCmdWait
    SEPlay 1369
    ActorDelete 9
    ActorCmdWait
    SEWait
    EvCameraMoveToDefault 40
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ObjInitWarpGPos 2, 800, 0xfffb, 241
    WorkSetConst 0x4106, 3
    FlagSet 855
    FlagSet 856
    FlagReset 830
    FlagReset 832
    FlagSet 831
    FlagSet 829
    FlagReset 1002
    Cmd_0262 1, 30
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_049D
    WorkSetConst 0x40f1, 0
    WorkSetConst 0x40f2, 1
    WorkSetConst 0x4103, 1
    WorkSetConst 0x4102, 1
    VMJump L_04B5

L_049D:
    WorkSetConst 0x40f1, 1
    WorkSetConst 0x40f2, 0
    WorkSetConst 0x4103, 1
    WorkSetConst 0x4102, 1

L_04B5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04BC:
    Move 14, 3
    MoveEnd

Movement_04C4:
    Move 12, 1
    Move 14, 6
    Move 13, 1
    Move 14, 2
    MoveEnd

Movement_04D8:
    Move 19, 1
    Move 16, 1
    Move 19, 3
    MoveEnd

Script_5:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    FlagReset 857
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorMsg 1024, 14, 9, 0, 0
    MsgWinCloseAll
    SEPlay 1369
    ActorAdd 11
    ActorCmdWait
    SEWait
    ActorWalkRoute 11, 796, 242, 1, 8, 1
    VMSleep 8
    ActorCmdExec 9, Movement_06A4
    ActorCmdExec 255, Movement_06A4
    ActorCmdWait
    ActorMsg 1024, 15, 11, 0, 0
    MsgWinCloseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorMsg 1024, 16, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_069C
    ActorCmdExec 255, Movement_0694
    ActorCmdWait
    ActorMsg 1024, 17, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_0624
    VMSleep 8
    ActorCmdExec 11, Movement_06A4
    ActorCmdExec 255, Movement_06A4
    ActorCmdWait
    SEPlay 1369
    ActorDelete 9
    SEWait
    ActorCmdExec 11, Movement_06AC
    ActorCmdWait
    ActorMsg 1024, 18, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_060C
    ActorCmdWait
    ActorMsgVersioned 1024, 19, 20, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4106, 5
    WorkSetConst 0x4070, 1
    FlagSet 855
    FlagSet 364
    Cmd_0262 2, 9
    Cmd_0262 1, 32
    Cmd_0262 3, 7
    Cmd_0262 0, 6
    Cmd_0262 4, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_060C:
    Move 33, 1
    Move 161, 1
    Move 181, 1
    Move 66, 2
    Move 1, 1
    MoveEnd

Movement_0624:
    Move 18, 7
    MoveEnd
    Move 12, 1
    Move 35, 1
    MoveEnd

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
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

Movement_0694:
    Move 32, 1
    MoveEnd

Movement_069C:
    Move 33, 1
    MoveEnd

Movement_06A4:
    Move 34, 1
    MoveEnd

Movement_06AC:
    Move 35, 1
    MoveEnd

Movement_06B4:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
