#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntry Script_9
    ScriptEntry Script_10
    ScriptEntry Script_11
    ScriptEntry Script_12
    ScriptEntry Script_13
    ScriptEntry Script_14
    ScriptEntry Script_15
    ScriptEntry Script_16
    ScriptEntry Script_17
    ScriptEntry Script_18
    ScriptEntry Script_19
    ScriptEntry Script_20
    ScriptEntry Script_21
    ScriptEntry Script_22
    ScriptEntry Script_23
    ScriptEntry Script_24
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_1:
    VMStackPush 0x40f4
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0091
    FlagSet 844

L_0091:
    VMHalt

Script_2:
    VMStackPush 0x40f4
    VMStackPushConst 2
    VMStackCmp 0
    VMStackPush 0x4104
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00C2
    ActorSetGPos 10, 15, 0, 16, 0

L_00C2:
    VMCall L_00D2
    VMHalt

Script_3:
    VMCall L_00D2
    VMHalt

L_00D2:
    VMStackPush 0x40fa
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00FD
    .byte 0xe9
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    .byte 0x01
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    VMSleep 1

L_00FD:
    VMReturn

Script_13:
    ActorsPauseAll
    ActorCmdExec 11, Movement_0754
    ActorCmdExec 255, Movement_074C
    ActorCmdWait
    ActorCmdExec 11, Movement_070C
    ActorCmdWait
    ActorMsg 1024, 5, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_073C
    ActorCmdWait
    ActorMsg 1024, 6, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_0744
    ActorCmdWait
    ActorMsg 1024, 7, 11, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x4102, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_24:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    FlagReset 842
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0xaf000, 28
    EvCameraWait
    InfoMsg 9, 2
    MsgWinCloseAll
    ActorAdd 10
    BGMPlayPush 1240
    PlayerGetGPos 0x8022, 0x8023
    WorkAdd 0x8023, 2
    ActorWalkRoute 10, 0x8022, 0x8023, 1, 16, 0
    ActorCmdExec 255, Movement_073C
    EvCameraMoveToDefault 20
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdWait
    ActorMsg 1024, 10, 10, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 497, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0235
    CallTrainerBattleEnd
    VMJump L_023B

L_0235:
    FlagSet 842
    CallTrainerLose

L_023B:
    ActorCmdExec 10, Movement_0268
    ActorCmdWait
    ActorMsg 1024, 11, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4104, 1
    WorkSetConst 0x40f3, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0268:
    Move 71, 1
    Move 9, 1
    Move 72, 1
    MoveEnd

Script_16:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 12, 2
    VMStackPushFlag 909
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02A1
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_02A5

L_02A1:
    LastKeyWait
    MsgWinCloseAll

L_02A5:
    VMStackPushFlag 909
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02C9
    PVPlay 646, 0
    InfoMsg 14, 2
    PVWait
    LastKeyWait
    MsgWinCloseAll

L_02C9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 13, 2
    VMStackPushFlag 909
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F8
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_02FC

L_02F8:
    LastKeyWait
    MsgWinCloseAll

L_02FC:
    VMStackPushFlag 909
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0320
    PVPlay 646, 0
    InfoMsg 14, 2
    PVWait
    LastKeyWait
    MsgWinCloseAll

L_0320:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    ActorCmdExec 9, Movement_0754
    ActorCmdWait
    ActorCmdExec 9, Movement_073C
    ActorCmdExec 255, Movement_0734
    ActorCmdWait
    ActorMsg 1024, 15, 9, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 9, Movement_074C
    ActorCmdExec 255, Movement_0704
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    ActorCmdExec 9, Movement_0754
    ActorCmdWait
    ActorCmdExec 9, Movement_073C
    ActorCmdExec 255, Movement_0734
    ActorCmdWait
    ActorMsg 1024, 16, 9, 0, 0
    MsgWinCloseAll
    VMCall L_03FB
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    VMStackPush 0x4125
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03D3
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_03F5

L_03D3:
    SEPlay 1351
    ActorCmdExec 9, Movement_0754
    ActorCmdWait
    ActorMsg 1024, 16, 9, 0, 0
    MsgWinCloseAll
    VMCall L_03FB

L_03F5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_03FB:
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8022
    VMStackPushConst 9
    VMStackCmp 1
    VMJumpIf 255, L_0422
    ActorCmdExec 9, Movement_0450
    VMJump L_0430

L_0422:
    ActorWalkRoute 9, 13, 19, 0, 4, 0

L_0430:
    VMSleep 8
    ActorCmdExec 255, Movement_074C
    ActorCmdWait
    ActorDelete 9
    FlagSet 840
    WorkSetConst 0x4125, 2
    VMReturn
    .balign 4, 0

Movement_0450:
    Move 17, 1
    Move 19, 5
    Move 17, 7
    MoveEnd

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    PlayerGetDir 0x8021
    MapChangeWarpPad 554, 11, 5, 32801
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    PlayerGetDir 0x8021
    MapChangeWarpPad 555, 7, 14, 32801
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    PlayerGetDir 0x8021
    MapChangeWarpPad 557, 8, 9, 32801
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    WorkSetConst 0x4000, 1
    WorkSetConst 0x4001, 0
    WorkSetConst 0x4002, 0
    WorkSetConst 0x4003, 0
    .byte 0xe8
    .byte 0x03
    VMNop
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    WorkSetConst 0x4001, 1
    WorkSetConst 0x4000, 0
    WorkSetConst 0x4002, 0
    WorkSetConst 0x4003, 0
    .byte 0xe8
    .byte 0x03
    VMNop2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    WorkSetConst 0x4002, 1
    WorkSetConst 0x4000, 0
    WorkSetConst 0x4001, 0
    WorkSetConst 0x4003, 0
    .byte 0xe8
    .byte 0x03
    VMHalt
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    WorkSetConst 0x4003, 1
    WorkSetConst 0x4000, 0
    WorkSetConst 0x4001, 0
    WorkSetConst 0x4002, 0
    .byte 0xe8
    .byte 0x03
    VMSleep 48
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 356
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_05AF
    SystemMsg 0, 2
    LastKeyWait
    MsgWinCloseAll
    VMJump L_067A

L_05AF:
    VMStackPush 0x40fa
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0670
    .byte 0xed
    .byte 0x03
    .byte 0x0a
    .byte 0x40
    .byte 0x06
    .byte 0x00
    .byte 0x0a
    .byte 0x40
    .byte 0xa6
    .byte 0x00
    .byte 0xa6
    .byte 0x08
    .byte 0xa8
    .byte 0x00
    .byte 0x34
    .byte 0x00
    VMNop2
    VMHalt
    .byte 0x47
    .byte 0x00
    .byte 0x10
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x10
    .byte 0x80
    .byte 0x08
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x11
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x7b
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x3f
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x24
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0xec
    .byte 0x03
    .byte 0x24
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x24
    .byte 0x80
    .byte 0x08
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x11
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x46
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xa6
    .byte 0x00
    .byte 0xa7
    .byte 0x08
    .byte 0x34
    .byte 0x00
    .byte 0x03
    .byte 0x00
    VMHalt
    .byte 0xa8
    .byte 0x00
    .byte 0x4b
    .byte 0x00
    .byte 0x3f
    .byte 0x00
    .byte 0xea
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0x03
    .byte 0x00
    .byte 0x08
    .byte 0x00
    .byte 0xea
    .byte 0x03
    .byte 0x01
    .byte 0x00
    .byte 0x03
    .byte 0x00
    VMStackPushConst 1002
    VMHalt
    .byte 0x03
    .byte 0x00
    .byte 0x08
    .byte 0x00
    .byte 0xea
    .byte 0x03
    .byte 0x03
    .byte 0x00
    SystemMsg 4, 2
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40fa, 1
    FlagSet 357
    VMJump L_0662
    SEPlay 2216
    SEWait
    SystemMsg 2, 2
    LastKeyWait
    MsgWinCloseAll

L_0662:
    VMJump L_066A
    MsgWinCloseAll

L_066A:
    VMJump L_067A

L_0670:
    SystemMsg 4, 2
    LastKeyWait
    MsgWinCloseAll

L_067A:
    WorkSetConst 0x8024, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    ActorCmdExec 255, Movement_06D4
    ActorCmdWait
    SEPlay 2221
    ActorCmdExec 255, Movement_06E0
    ActorCmdWait
    SEWait
    InfoMsg 23, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06D0
    CallTrainerBattleEnd
    VMJump L_06D2

L_06D0:
    CallTrainerLose

L_06D2:
    VMReturn

Movement_06D4:
    Move 0, 1
    Move 75, 1
    MoveEnd

Movement_06E0:
    Move 71, 1
    Move 36, 2
    Move 17, 2
    Move 72, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0704:
    Move 15, 1
    MoveEnd

Movement_070C:
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

Movement_0734:
    Move 32, 1
    MoveEnd

Movement_073C:
    Move 33, 1
    MoveEnd

Movement_0744:
    Move 34, 1
    MoveEnd

Movement_074C:
    Move 35, 1
    MoveEnd

Movement_0754:
    Move 75, 1
    MoveEnd
