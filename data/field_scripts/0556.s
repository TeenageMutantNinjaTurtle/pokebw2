#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0

Script_3:
    WorkSetConst 0x8026, 0
    RTCGetDate 0x8026, 0x400f
    VMStackPushFlag 483
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 484
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4194
    VMStackPush 0x8026
    VMStackCmp 5
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0081
    FlagReset 912

L_0081:
    WorkSetConst 0x400f, 0
    WorkSetConst 0x8026, 0
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_00B0
    WorkSetConst 0x4020, 365
    VMJump L_00B6

L_00B0:
    WorkSetConst 0x4020, 364

L_00B6:
    WorkSetConst 0x8027, 0
    TrainerCardGetSex 0x8027
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00DF
    WorkSetConst 0x4021, 231
    VMJump L_00E5

L_00DF:
    WorkSetConst 0x4021, 240

L_00E5:
    WorkSetConst 0x8027, 0
    VMHalt

Script_4:
    VMCall L_00F7
    VMHalt

Script_5:
    VMHalt

L_00F7:
    VMStackPushFlag 912
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_011C
    ActorSetGPos 0, 16, 0, 36, 1
    VMJump L_011C

L_011C:
    VMReturn

Script_1:
    ActorsPauseAll
    FlagReset 912
    FlagReset 913
    FlagReset 1035
    ActorAdd 0
    ActorSetGPos 0, 16, 0, 48, 0
    BGMPlay 1091
    InfoMsg 0, 2
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0A90
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 17
    VMStackCmp 4
    VMJumpIf 255, L_0176
    WorkSub 0x8021, 1
    VMJump L_017C

L_0176:
    WorkAdd 0x8021, 1

L_017C:
    ActorWalkRoute 0, 0x8021, 0x8022, 0, 8, 0
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 17
    VMStackCmp 4
    VMJumpIf 255, L_01BD
    ActorCmdExec 0, Movement_0AA0
    ActorCmdExec 255, Movement_0A98
    ActorCmdWait
    VMJump L_01CF

L_01BD:
    ActorCmdExec 0, Movement_0A98
    ActorCmdExec 255, Movement_0AA0
    ActorCmdWait

L_01CF:
    ActorMsgVersioned 1024, 2, 1, 0, 0, 0
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x108000, 0, 0x243000, 56
    WorkCmpConst 0x8021, 14
    VMJumpIf 1, L_021A
    VMJump L_0234

L_021A:
    ActorCmdExec 0, Movement_03D0
    VMSleep 8
    ActorCmdExec 255, Movement_041C
    VMJump L_02E8

L_0234:
    WorkCmpConst 0x8021, 15
    VMJumpIf 1, L_0247
    VMJump L_0261

L_0247:
    ActorCmdExec 0, Movement_03E0
    VMSleep 8
    ActorCmdExec 255, Movement_042C
    VMJump L_02E8

L_0261:
    WorkCmpConst 0x8021, 16
    VMJumpIf 1, L_0274
    VMJump L_028E

L_0274:
    ActorCmdExec 0, Movement_03EC
    VMSleep 16
    ActorCmdExec 255, Movement_043C
    VMJump L_02E8

L_028E:
    WorkCmpConst 0x8021, 17
    VMJumpIf 1, L_02A1
    VMJump L_02BB

L_02A1:
    ActorCmdExec 0, Movement_0400
    VMSleep 8
    ActorCmdExec 255, Movement_0444
    VMJump L_02E8

L_02BB:
    WorkCmpConst 0x8021, 18
    VMJumpIf 1, L_02CE
    VMJump L_02E8

L_02CE:
    ActorCmdExec 0, Movement_03EC
    VMSleep 8
    ActorCmdExec 255, Movement_0454
    VMJump L_02E8

L_02E8:
    ActorCmdWait
    EvCameraWait
    ActorAdd 2
    ActorCmdExec 255, Movement_0464
    ActorCmdWait
    ActorSetGPos 255, 16, 0, 36, 1
    ActorMsg 1024, 4, 0, 3, 0
    ActorMsgVersioned 1024, 6, 5, 0, 3, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0AA0
    ActorCmdWait
    VMCall L_0474
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0360
    ScreamMsg 7, 1
    PVPlay 644, 0
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    VMJump L_0371

L_0360:
    ScreamMsg 8, 1
    PVPlay 643, 0
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039

L_0371:
    ActorCmdExec 0, Movement_0A90
    ActorCmdWait
    ActorMsgVersioned 1024, 10, 9, 0, 3, 0
    ActorSetGPos 255, 16, 0, 38, 0
    ActorCmdExec 255, Movement_046C
    ActorCmdWait
    ActorDelete 2
    WorkSetConst 0x4114, 2
    WorkSetConst 0x4112, 1
    FlagSet 941
    WorkSetConst 0x411d, 2
    FlagSet 1035
    WorkSetConst 0x400f, 99
    VMCall L_057D
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_03D0:
    Move 15, 1
    Move 12, 6
    Move 33, 1
    MoveEnd

Movement_03E0:
    Move 12, 6
    Move 33, 1
    MoveEnd

Movement_03EC:
    Move 12, 1
    Move 14, 1
    Move 12, 5
    Move 33, 1
    MoveEnd

Movement_0400:
    Move 12, 6
    Move 33, 1
    MoveEnd
    Move 14, 1
    Move 12, 6
    Move 33, 1
    MoveEnd

Movement_041C:
    Move 15, 2
    Move 12, 4
    Move 32, 1
    MoveEnd

Movement_042C:
    Move 15, 1
    Move 12, 4
    Move 32, 1
    MoveEnd

Movement_043C:
    Move 12, 4
    MoveEnd

Movement_0444:
    Move 14, 1
    Move 12, 4
    Move 32, 1
    MoveEnd

Movement_0454:
    Move 14, 2
    Move 12, 4
    Move 32, 1
    MoveEnd

Movement_0464:
    Move 69, 1
    MoveEnd

Movement_046C:
    Move 70, 1
    MoveEnd

L_0474:
    Cmd_020E 0, 18, 0, 36, 3, 8
    Cmd_020F 0, 18, 0, 36
    Cmd_0211 0
    FadeEx 12, 0, 16, 2
    FadeExWait
    ActorAdd 1
    FadeEx 12, 16, 0, 2
    FadeExWait
    Cmd_0210 0
    VMReturn

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4114
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPushFlag 480
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_04E9
    VMCall L_0833
    VMJump L_0530

L_04E9:
    VMStackPush 0x4114
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPushFlag 480
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0526
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 32, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0530

L_0526:
    BGMPlay 1091
    VMCall L_057D

L_0530:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0566
    PVPlay 644, 0
    ScreamMsg 7, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    VMJump L_0577

L_0566:
    PVPlay 643, 0
    ScreamMsg 8, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039

L_0577:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_057D:
    ActorMsg 1024, 11, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_060F
    ActorMsg 1024, 12, 0, 0, 0
    MsgWinCloseAll
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_05E4
    PVPlay 644, 0
    ScreamMsg 13, 1
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    CallTrainerBattle 5, 0, 0
    VMJump L_05FD

L_05E4:
    PVPlay 643, 0
    ScreamMsg 14, 1
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    CallTrainerBattle 6, 0, 0

L_05FD:
    VMCall L_09C0
    VMCall L_0646
    VMJump L_0644

L_060F:
    ActorMsg 1024, 15, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMStackPush 0x400f
    VMStackPushConst 99
    VMStackCmp 1
    VMJumpIf 255, L_0642
    EvCameraMoveToDefault 24
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    WorkSetConst 0x400f, 0

L_0642:
    BGMChangeMap

L_0644:
    VMReturn

L_0646:
    WordSetPlayerName 0
    ActorMsgVersioned 1024, 17, 16, 0, 3, 0
    TrainerCardGetSex 0x8025
    ActorMsg 1024, 18, 0, 3, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0AA0
    ActorCmdWait
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_069A
    ActorMsgVersioned 1024, 21, 19, 0, 3, 0
    VMJump L_06A8

L_069A:
    ActorMsgVersioned 1024, 22, 20, 0, 3, 0

L_06A8:
    MsgWinCloseAll
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_06DF
    PVPlay 644, 0
    ActorMsg 1024, 23, 1, 5, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_06F7

L_06DF:
    PVPlay 643, 0
    ActorMsg 1024, 24, 1, 5, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll

L_06F7:
    ActorCmdExec 0, Movement_0A2C
    ActorCmdWait
    ActorMsgVersioned 1024, 26, 25, 0, 3, 0
    ActorMsg 1024, 27, 0, 3, 0
    MsgWinCloseAll
    FadeEx 12, 0, 16, 4
    FadeExWait
    ActorDelete 1
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0758
    ActorNew 18, 36, 1, 251, 143, 0
    VMJump L_0766

L_0758:
    ActorNew 18, 36, 1, 251, 144, 0

L_0766:
    FadeEx 12, 16, 0, 4
    FadeExWait
    VMSleep 8
    ActorCmdExec 0, Movement_0A58
    ActorCmdWait
    VMSleep 16
    ActorDelete 251
    VMSleep 8
    ActorCmdExec 0, Movement_0A3C
    ActorCmdWait
    ActorMsgVersioned 1024, 29, 28, 0, 3, 0
    MsgWinCloseAll
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_07DF
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 617
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_07FF

L_07DF:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 616
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000

L_07FF:
    ActorMsgVersioned 1024, 31, 30, 0, 3, 0
    MsgWinCloseAll
    BGMChangeMap
    EvCameraMoveToDefault 24
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    WorkSetConst 0x4114, 3
    FlagSet 913
    WorkSetConst 0x411b, 1
    WorkSetConst 0x4148, 1
    VMReturn

L_0833:
    VMStackPushFlag 486
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0858
    ActorMsg 1024, 33, 0, 0, 0
    VMJump L_0864

L_0858:
    ActorMsg 1024, 39, 0, 0, 0

L_0864:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09AA
    ActorMsg 1024, 34, 0, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8028, 0
    RTCGetSeason 0x8028
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08B4
    CallTrainerBattle 782, 0, 0
    VMJump L_0911

L_08B4:
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_08D5
    CallTrainerBattle 783, 0, 0
    VMJump L_0911

L_08D5:
    VMStackPush 0x8028
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_08F6
    CallTrainerBattle 784, 0, 0
    VMJump L_0911

L_08F6:
    VMStackPush 0x8028
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0911
    CallTrainerBattle 785, 0, 0

L_0911:
    VMCall L_09C0
    ActorMsgVersioned 1024, 36, 35, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 37, 0, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0964
    ActorWalkRoute 0, 17, 44, 1, 8, 0
    VMSleep 24
    VMJump L_0976

L_0964:
    ActorWalkRoute 0, 16, 44, 1, 8, 1
    VMSleep 16

L_0976:
    ActorCmdExec 255, Movement_0A90
    ActorCmdWait
    ActorDelete 0
    RTCGetDate 0x8028, 0x400f
    WorkGet 0x4194, 0x8028
    FlagSet 912
    FlagReset 486
    WorkSetConst 0x400f, 0
    WorkSetConst 0x8028, 0
    VMJump L_09BE

L_09AA:
    ActorMsg 1024, 38, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 486

L_09BE:
    VMReturn

L_09C0:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A28
    VMStackPush 0x4114
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0A20
    ActorSetGPos 255, 16, 0, 38, 0
    ActorSetGPos 0, 16, 0, 36, 1
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x108000, 0, 0x243000, 1
    EvCameraWait

L_0A20:
    CallTrainerBattleEnd
    VMJump L_0A2A

L_0A28:
    CallTrainerLose

L_0A2A:
    VMReturn

Movement_0A2C:
    Move 33, 1
    Move 182, 1
    Move 3, 1
    MoveEnd

Movement_0A3C:
    Move 14, 1
    Move 13, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0A58:
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

Movement_0A90:
    Move 33, 1
    MoveEnd

Movement_0A98:
    Move 34, 1
    MoveEnd

Movement_0AA0:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
