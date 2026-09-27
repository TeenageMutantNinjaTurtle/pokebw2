#include "asm/field_script.inc"

// Script plugin 10, from the zones that use this file

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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMStackPush 0x413c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C7
    FlagReset 995
    FlagReset 994

L_00C7:
    Cmd_02CB 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00E8
    FlagReset 691
    VMJump L_0151

L_00E8:
    VMStackPush 0x400f
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0109
    FlagReset 691
    FlagReset 692
    VMJump L_0151

L_0109:
    VMStackPush 0x400f
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_012E
    FlagReset 691
    FlagReset 692
    FlagReset 693
    VMJump L_0151

L_012E:
    VMStackPush 0x400f
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0151
    FlagReset 691
    FlagReset 692
    FlagReset 693
    FlagReset 694

L_0151:
    VMHalt

Script_2:
    VMStackPush 0x410a
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0184
    ActorSetGPos 0, 32, 0, 56, 2
    ActorSetGPos 26, 30, 0, 56, 3
    VMJump L_01A3

L_0184:
    VMStackPush 0x410a
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01A3
    ActorSetGPos 0, 45, 0, 19, 1

L_01A3:
    VMStackPush 0x413c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0200
    ActorSetGPos 0, 45, 2, 21, 0
    ActorSetGPos 26, 31, 2, 9, 0
    ActorDelete 17
    VMStackPushFlag 693
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01E9
    ActorDelete 35

L_01E9:
    VMStackPushFlag 694
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0200
    ActorDelete 36

L_0200:
    VMHalt

Script_3:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x1f8000, 0, 0x398000, 30
    EvCameraWait
    ActorMsg 1024, 1, 26, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0E60
    ActorCmdWait
    ActorCmdExec 0, Movement_0E88
    ActorCmdWait
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 26, Movement_0E60
    ActorWalkRoute 255, 31, 58, 1, 8, 0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 4, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0550
    ActorCmdWait
    ActorCmdExec 26, Movement_0E08
    ActorCmdWait
    ActorCmdExec 26, Movement_0E60
    ActorCmdWait
    ActorMsg 1024, 5, 26, 3, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0DF8
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 26, Movement_0E70
    VMSleep 8
    ActorCmdExec 0, Movement_0E68
    ActorCmdWait
    ActorMsg 1024, 7, 26, 3, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 26, 31, 45, 0, 4, 1
    VMSleep 12
    ActorCmdExec 0, Movement_0E58
    ActorCmdWait
    ActorDelete 26
    ActorCmdExec 0, Movement_0E10
    ActorCmdWait
    ActorCmdExec 0, Movement_0E60
    ActorCmdWait
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 15
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 0, Movement_0DF8
    ActorCmdWait
    ActorCmdExec 0, Movement_0E60
    ActorCmdWait
    ActorWalkRoute 0, 31, 32, 0, 8, 0
    VMSleep 4
    ActorWalkRoute 255, 31, 33, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_0E60
    ActorCmdWait
    ActorMsg 1024, 9, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0508
    VMSleep 4
    ActorCmdExec 255, Movement_04E8
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 5848, 0, 0xed000, 0x2d8000, 0x3b01f, 0x138000, 40
    EvCameraWait
    InfoMsg 10, 2
    InfoMsgClose_0039
    EvCameraMoveToDefault 40
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorWalkRoute 0, 45, 20, 0, 8, 1
    ActorCmdWait
    ActorCmdExec 0, Movement_0E60
    ActorCmdWait
    ActorCmdExec 0, Movement_0524
    VMSleep 4
    ActorCmdExec 255, Movement_0500
    ActorCmdWait
    WorkSetConst 0x410a, 2
    MapChangeWarp 574, 15, 31, 0
    RTReserveScript 10867
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_33:
    ActorsPauseAll
    FadeInBlack
    ActorCmdExec 0, Movement_0560
    VMSleep 4
    ActorCmdExec 255, Movement_0530
    FadeWait
    ActorCmdWait
    ActorCmdExec 0, Movement_0570
    VMSleep 8
    ActorCmdExec 255, Movement_053C
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 5592, 0, 0x105000, 0x148000, 0x3000f, 0x118000, 40
    EvCameraWait
    InfoMsg 11, 2
    InfoMsgClose_0039
    EvCameraMoveToDefault 40
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 0, Movement_058C
    ActorCmdWait
    ActorCmdExec 0, Movement_059C
    VMSleep 4
    ActorCmdExec 255, Movement_0584
    ActorCmdWait
    FlagSet 2440
    RTReserveScript 10819
    MapChangeWarp 568, 14, 21, 0
    WorkSetConst 0x410a, 3
    WorkSetConst 0x40ac, 4
    FlagReset 724
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 15, 1
    Move 12, 18
    MoveEnd
    Move 12, 18
    MoveEnd
    Move 14, 1
    Move 12, 18
    MoveEnd

Movement_04E8:
    Move 12, 1
    Move 15, 4
    Move 12, 5
    Move 15, 10
    Move 12, 6
    MoveEnd

Movement_0500:
    Move 12, 3
    MoveEnd

Movement_0508:
    Move 15, 4
    Move 12, 5
    Move 15, 10
    Move 12, 6
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_0524:
    Move 12, 2
    Move 69, 1
    MoveEnd

Movement_0530:
    Move 13, 9
    Move 34, 1
    MoveEnd

Movement_053C:
    Move 14, 10
    Move 12, 3
    Move 14, 15
    Move 32, 1
    MoveEnd

Movement_0550:
    Move 71, 1
    Move 12, 1
    Move 72, 1
    MoveEnd

Movement_0560:
    Move 13, 8
    Move 14, 1
    Move 35, 1
    MoveEnd

Movement_0570:
    Move 14, 9
    Move 12, 3
    Move 14, 16
    Move 32, 1
    MoveEnd

Movement_0584:
    Move 12, 3
    MoveEnd

Movement_058C:
    Move 12, 1
    Move 15, 1
    Move 33, 1
    MoveEnd

Movement_059C:
    Move 12, 3
    MoveEnd
    Move 34, 1
    Move 62, 1
    Move 35, 1
    Move 62, 1
    Move 33, 1
    MoveEnd

Script_4:
    ActorsPauseAll
    ActorCmdExec 0, Movement_0E88
    ActorCmdWait
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    PlayerGetGPos 0x8023, 0x8024
    WorkAdd 0x8024, 1
    ActorWalkRoute 0, 0x8023, 0x8024, 0, 8, 0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 49, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 0, 43, 27, 4, 8, 1
    VMSleep 4
    ActorWalkRoute 255, 44, 27, 4, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_0E60
    ActorCmdExec 0, Movement_0E60
    ActorCmdExec 20, Movement_0E20
    ActorCmdWait
    ActorMsg 1024, 50, 20, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0884
    VMSleep 4
    ActorCmdExec 255, Movement_0884
    VMSleep 8
    ActorCmdExec 20, Movement_0E68
    ActorCmdWait
    ActorCmdExec 21, Movement_0E20
    ActorCmdWait
    ActorMsg 1024, 51, 21, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0890
    VMSleep 4
    ActorCmdExec 255, Movement_0890
    VMSleep 8
    ActorCmdExec 21, Movement_0E68
    ActorCmdWait
    ActorCmdExec 25, Movement_0E00
    ActorCmdWait
    ActorCmdExec 25, Movement_0E80
    ActorCmdWait
    ActorMsg 1024, 52, 25, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_089C
    VMSleep 2
    ActorCmdExec 255, Movement_08B0
    ActorCmdWait
    ActorMsg 1024, 53, 24, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_08C8
    VMSleep 2
    ActorCmdExec 255, Movement_08C8
    ActorCmdWait
    ActorMsg 1024, 54, 23, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_08D4
    VMSleep 2
    ActorCmdExec 255, Movement_08D4
    ActorCmdWait
    ActorCmdExec 22, Movement_0E10
    ActorCmdWait
    ActorMsg 1024, 55, 22, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_08EC
    VMSleep 4
    ActorCmdExec 255, Movement_08EC
    VMSleep 4
    ActorCmdExec 22, Movement_08E0
    ActorCmdWait
    ActorMsg 1024, 56, 0, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_08F4
    VMSleep 8
    ActorCmdExec 255, Movement_0E00
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 27, Movement_0E60
    VMSleep 15
    ActorCmdExec 26, Movement_0E60
    ActorCmdWait
    ActorMsg 1024, 57, 26, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorMsg 1024, 58, 27, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 26, Movement_0DF8
    ActorCmdWait
    ActorMsg 1024, 59, 26, 2, 0
    MEPlay 1346
    MEWait
    MsgWaitAdvance
    ActorMsg 1024, 60, 26, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0E08
    VMSleep 8
    ActorCmdExec 255, Movement_0E68
    ActorCmdWait
    ActorMsg 1024, 61, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    RTReserveScript 2
    MapChangeWarp 586, 11, 16, 3
    FlagSet 458
    FlagSet 995
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    Move 15, 1
    Move 1, 1
    MoveEnd
    Move 13, 1
    Move 14, 1
    Move 1, 1
    MoveEnd
    Move 13, 6
    Move 14, 1
    Move 1, 1
    MoveEnd
    Move 13, 7
    MoveEnd

Movement_0884:
    Move 14, 4
    Move 1, 1
    MoveEnd

Movement_0890:
    Move 14, 4
    Move 1, 1
    MoveEnd

Movement_089C:
    Move 12, 3
    Move 14, 4
    Move 12, 5
    Move 3, 1
    MoveEnd

Movement_08B0:
    Move 14, 1
    Move 12, 3
    Move 14, 4
    Move 12, 4
    Move 3, 1
    MoveEnd

Movement_08C8:
    Move 12, 2
    Move 2, 1
    MoveEnd

Movement_08D4:
    Move 12, 3
    Move 3, 1
    MoveEnd

Movement_08E0:
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_08EC:
    Move 12, 2
    MoveEnd

Movement_08F4:
    Move 14, 2
    Move 35, 1
    MoveEnd

Script_5:
    ActorsPauseAll
    WordSetPlayerName 0
    Cmd_02CB 0x400f
    VMStackPush 0x400f
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0954
    WorkSetConst 0x8025, 0
    Random 0x8025, 4
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8026, 12
    WorkAdd 0x8026, 0x8025
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8026, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0968

L_0954:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose

L_0968:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    WordSetPlayerName 0
    Cmd_02CB 0x400f
    VMStackPush 0x400f
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_09AE
    SEPlay 1351
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_09C0

L_09AE:
    SEPlay 1351
    ParentActorMsg 1024, 27, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_09C0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 506, 0
    ParentActorMsg 1024, 18, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 37, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    WordSetPlayerName 0
    Cmd_02CB 0x400f
    VMStackPush 0x400f
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0AE2
    SEPlay 1351
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0AF4

L_0AE2:
    SEPlay 1351
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0AF4:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    WordSetPlayerName 0
    Cmd_02CB 0x400f
    VMStackPush 0x400f
    VMStackPushConst 2
    VMStackCmp 0
    VMJumpIf 255, L_0B30
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0B71

L_0B30:
    VMStackPush 0x400f
    VMStackPushConst 4
    VMStackCmp 0
    VMJumpIf 255, L_0B5D
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0B71

L_0B5D:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 30, 0, 0
    LastKeyWait
    ActorMsgClose

L_0B71:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    WordSetPlayerName 0
    Cmd_02CB 0x400f
    VMStackPush 0x400f
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0BAD
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 32, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0BC1

L_0BAD:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 33, 0, 0
    LastKeyWait
    ActorMsgClose

L_0BC1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 34, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 36, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 39, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    SEPlay 1351
    ActorCmdExec 18, Movement_0E78
    ActorCmdWait
    ParentActorMsg 1024, 38, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_24:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 40, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_25:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 41, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_26:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 42, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_27:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 43, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_28:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 44, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_29:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 45, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_30:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 46, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_31:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 47, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_32:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 48, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_34:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 62, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_35:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 63, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_36:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 64, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_37:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 65, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_38:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 66, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0DF8:
    Move 13, 1
    MoveEnd

Movement_0E00:
    Move 12, 1
    MoveEnd

Movement_0E08:
    Move 15, 1
    MoveEnd

Movement_0E10:
    Move 14, 1
    MoveEnd
    Move 9, 1
    MoveEnd

Movement_0E20:
    Move 8, 1
    MoveEnd
    Move 11, 1
    MoveEnd
    Move 10, 1
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

Movement_0E58:
    Move 32, 1
    MoveEnd

Movement_0E60:
    Move 33, 1
    MoveEnd

Movement_0E68:
    Move 34, 1
    MoveEnd

Movement_0E70:
    Move 35, 1
    MoveEnd

Movement_0E78:
    Move 36, 4
    MoveEnd

Movement_0E80:
    Move 48, 2
    MoveEnd

Movement_0E88:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
