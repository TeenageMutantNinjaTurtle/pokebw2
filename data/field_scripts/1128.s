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
    ScriptEntry Script_25
    ScriptEntry Script_26
    ScriptEntry Script_27
    ScriptEntry Script_28
    ScriptEntry Script_29
    ScriptEntry Script_30
    ScriptEntry Script_31
    ScriptEntry Script_32
    ScriptEntry Script_33
    ScriptEntry Script_34
    ScriptEntry Script_35
    ScriptEntry Script_36
    ScriptEntry Script_37
    ScriptEntry Script_38
    ScriptEntry Script_39
    ScriptEntry Script_40
    ScriptEntry Script_41
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0

Script_1:
    VMStackPush 0x40f4
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_00E7
    FlagSet 845

L_00E7:
    VMHalt

Script_2:
    VMStackPush 0x40f4
    VMStackPushConst 2
    VMStackCmp 0
    VMStackPush 0x4105
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0118
    ActorSetGPos 10, 15, 0, 16, 0

L_0118:
    VMCall L_0128
    VMHalt

Script_3:
    VMCall L_0128
    VMHalt

L_0128:
    VMStackPush 0x40f5
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0147
    .byte 0xe9
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x1e
    .byte 0x00
    .byte 0x06
    .byte 0x00
    .byte 0x00
    .byte 0x00

L_0147:
    .byte 0xe9
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x09
    .byte 0x00
    .byte 0xf6
    .byte 0x40
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
    .byte 0x0c
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    .byte 0x01
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x1e
    .byte 0x00
    .byte 0x06
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    .byte 0x01
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x09
    .byte 0x00
    .byte 0xf7
    .byte 0x40
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
    .byte 0x0c
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    VMHalt
    .byte 0x00
    .byte 0x00
    .byte 0x1e
    .byte 0x00
    .byte 0x06
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0x09
    .byte 0x00
    .byte 0xf8
    .byte 0x40
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
    .byte 0x0c
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    VMSleep 0
    VMJump L_01BC
    .byte 0xe9
    .byte 0x03
    VMSleep 1

L_01BC:
    VMReturn

Script_16:
    ActorsPauseAll
    ActorCmdExec 9, Movement_0C0C
    ActorCmdExec 255, Movement_0C04
    ActorCmdWait
    ActorCmdExec 9, Movement_0BC4
    ActorCmdWait
    ActorMsg 1024, 5, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_0BF4
    ActorCmdWait
    ActorMsg 1024, 6, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_0BFC
    ActorCmdWait
    ActorMsg 1024, 7, 9, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x4103, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_41:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    FlagReset 843
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
    ActorCmdExec 255, Movement_0BF4
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
    VMJumpIf 255, L_02F4
    CallTrainerBattleEnd
    VMJump L_02FA

L_02F4:
    FlagSet 843
    CallTrainerLose

L_02FA:
    ActorCmdExec 10, Movement_0328
    ActorCmdWait
    ActorMsg 1024, 11, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4105, 1
    WorkSetConst 0x40f3, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0328:
    Move 71, 1
    Move 9, 1
    Move 72, 1
    MoveEnd

Script_19:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 12, 2
    VMStackPushFlag 909
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0361
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_0365

L_0361:
    LastKeyWait
    MsgWinCloseAll

L_0365:
    VMStackPushFlag 909
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0389
    PVPlay 646, 0
    InfoMsg 14, 2
    PVWait
    LastKeyWait
    MsgWinCloseAll

L_0389:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 13, 2
    VMStackPushFlag 909
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03B8
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_03BC

L_03B8:
    LastKeyWait
    MsgWinCloseAll

L_03BC:
    VMStackPushFlag 909
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03E0
    PVPlay 646, 0
    InfoMsg 14, 2
    PVWait
    LastKeyWait
    MsgWinCloseAll

L_03E0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_24:
    ActorsPauseAll
    ActorCmdExec 11, Movement_0C0C
    ActorCmdWait
    ActorCmdExec 11, Movement_0BF4
    ActorCmdExec 255, Movement_0BEC
    ActorCmdWait
    ActorMsg 1024, 15, 11, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 11, Movement_0C04
    ActorCmdExec 255, Movement_0BBC
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_25:
    ActorsPauseAll
    ActorCmdExec 11, Movement_0C0C
    ActorCmdWait
    ActorCmdExec 11, Movement_0BF4
    ActorCmdExec 255, Movement_0BEC
    ActorCmdWait
    ActorMsg 1024, 16, 11, 0, 0
    MsgWinCloseAll
    VMCall L_04BB
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_26:
    ActorsPauseAll
    VMStackPush 0x4125
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0493
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04B5

L_0493:
    SEPlay 1351
    ActorCmdExec 11, Movement_0C0C
    ActorCmdWait
    ActorMsg 1024, 16, 11, 0, 0
    MsgWinCloseAll
    VMCall L_04BB

L_04B5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_04BB:
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8022
    VMStackPushConst 9
    VMStackCmp 1
    VMJumpIf 255, L_04E2
    ActorCmdExec 11, Movement_0510
    VMJump L_04F0

L_04E2:
    ActorWalkRoute 11, 13, 19, 0, 4, 0

L_04F0:
    VMSleep 8
    ActorCmdExec 255, Movement_0C04
    ActorCmdWait
    ActorDelete 11
    FlagSet 841
    WorkSetConst 0x4125, 2
    VMReturn
    .balign 4, 0

Movement_0510:
    Move 17, 1
    Move 19, 5
    Move 17, 7
    MoveEnd

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
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

Script_12:
    ActorsPauseAll
    WorkSetConst 0x40f5, 1
    SEPlay 2217
    InfoMsg 3, 2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0612
    MsgWaitAdvance
    VMJump L_0614

L_0612:
    LastKeyWait

L_0614:
    MsgWinCloseAll
    SEWait
    .byte 0xeb
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0xea
    .byte 0x03
    VMNop
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_066C
    InfoMsg 4, 2
    LastKeyWait
    MsgWinCloseAll

L_066C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    WorkSetConst 0x40f6, 1
    SEPlay 2217
    InfoMsg 3, 2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_06CE
    MsgWaitAdvance
    VMJump L_06D0

L_06CE:
    LastKeyWait

L_06D0:
    MsgWinCloseAll
    SEWait
    .byte 0xeb
    .byte 0x03
    .byte 0x01
    .byte 0x00
    .byte 0xea
    .byte 0x03
    VMNop2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0728
    InfoMsg 4, 2
    LastKeyWait
    MsgWinCloseAll

L_0728:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    WorkSetConst 0x40f7, 1
    SEPlay 2217
    InfoMsg 3, 2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_078A
    MsgWaitAdvance
    VMJump L_078C

L_078A:
    LastKeyWait

L_078C:
    MsgWinCloseAll
    SEWait
    .byte 0xeb
    .byte 0x03
    VMHalt
    .byte 0xea
    .byte 0x03
    VMHalt
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_07E4
    InfoMsg 4, 2
    LastKeyWait
    MsgWinCloseAll

L_07E4:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    WorkSetConst 0x40f8, 1
    SEPlay 2217
    InfoMsg 3, 2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0846
    MsgWaitAdvance
    VMJump L_0848

L_0846:
    LastKeyWait

L_0848:
    MsgWinCloseAll
    SEWait
    .byte 0xeb
    .byte 0x03
    .byte 0x03
    .byte 0x00
    .byte 0xea
    .byte 0x03
    .byte 0x03
    .byte 0x00
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_08A0
    InfoMsg 4, 2
    LastKeyWait
    MsgWinCloseAll

L_08A0:
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
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0955
    CallTrainerBattleEnd
    VMJump L_0957

L_0955:
    CallTrainerLose

L_0957:
    VMReturn

Script_11:
    ActorsPauseAll
    ActorCmdExec 255, Movement_0B8C
    ActorCmdWait
    SEPlay 2221
    ActorCmdExec 255, Movement_0B98
    ActorCmdWait
    SEWait
    InfoMsg 20, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_27:
    ActorsPauseAll
    WorkSetConst 0x8024, 11
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 48
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_28:
    ActorsPauseAll
    WorkSetConst 0x8024, 7
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 16
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_29:
    ActorsPauseAll
    WorkSetConst 0x8024, 5
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 41
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_30:
    ActorsPauseAll
    WorkSetConst 0x8024, 7
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 21
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_31:
    ActorsPauseAll
    WorkSetConst 0x8024, 25
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 41
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_32:
    ActorsPauseAll
    WorkSetConst 0x8024, 23
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 16
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_33:
    ActorsPauseAll
    WorkSetConst 0x8024, 19
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 48
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_34:
    ActorsPauseAll
    WorkSetConst 0x8024, 23
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 21
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_35:
    ActorsPauseAll
    WorkSetConst 0x8024, 5
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 54
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_36:
    ActorsPauseAll
    WorkSetConst 0x8024, 11
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 41
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_37:
    ActorsPauseAll
    WorkSetConst 0x8024, 25
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 54
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_38:
    ActorsPauseAll
    WorkSetConst 0x8024, 11
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 54
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_39:
    ActorsPauseAll
    WorkSetConst 0x8024, 19
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 54
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_40:
    ActorsPauseAll
    WorkSetConst 0x8024, 19
    WorkSetConst 0x8025, 65533
    WorkSetConst 0x8026, 41
    VMCall L_0B44
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0B44:
    WorkSetConst 0x8027, 0
    DebugPrint 0x8024
    DebugPrint 0x8026
    SEPlay 2223
    PlayerGetDir 0x8027
    FadeEx 3, 0, 16, 2
    FadeExWait
    VMSleep 6
    ActorSetGPos 255, 0x8024, 0x8025, 0x8026, 0x8027
    FadeEx 3, 16, 0, 2
    FadeExWait
    WorkSetConst 0x8027, 0
    VMReturn
    .balign 4, 0

Movement_0B8C:
    Move 0, 1
    Move 75, 1
    MoveEnd

Movement_0B98:
    Move 71, 1
    Move 36, 2
    Move 17, 2
    Move 72, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0BBC:
    Move 15, 1
    MoveEnd

Movement_0BC4:
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

Movement_0BEC:
    Move 32, 1
    MoveEnd

Movement_0BF4:
    Move 33, 1
    MoveEnd

Movement_0BFC:
    Move 34, 1
    MoveEnd

Movement_0C04:
    Move 35, 1
    MoveEnd

Movement_0C0C:
    Move 75, 1
    MoveEnd
