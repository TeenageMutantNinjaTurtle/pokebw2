#include "asm/field_script.inc"

// Script plugin 8, from the zones that use this file

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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    VMHalt

Script_2:
    WorkSetConst 0x8021, 0
    VMCall L_0250
    Plugin8_Cmd1031 20, 0x8021
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0065
    WorkSetConst 0x4119, 1

L_0065:
    WorkCmpConst 0x4110, 1
    VMJumpIf 1, L_0078
    VMJump L_00A2

L_0078:
    ActorDelete 0
    ActorSetGPos 1, 15, 0, 70, 1
    ActorSetGPos 2, 14, 0, 70, 1
    ActorDelete 3
    ActorDelete 4
    VMJump L_01C3

L_00A2:
    WorkCmpConst 0x4110, 2
    VMJumpIf 1, L_00B5
    VMJump L_00DF

L_00B5:
    ActorDelete 0
    ActorSetGPos 1, 15, 0, 70, 1
    ActorSetGPos 2, 14, 0, 70, 1
    ActorDelete 3
    ActorDelete 4
    VMJump L_01C3

L_00DF:
    WorkCmpConst 0x4110, 3
    VMJumpIf 1, L_00F2
    VMJump L_011C

L_00F2:
    ActorDelete 0
    ActorSetGPos 1, 15, 0, 70, 1
    ActorSetGPos 2, 14, 0, 70, 1
    ActorDelete 3
    ActorDelete 4
    VMJump L_01C3

L_011C:
    WorkCmpConst 0x4110, 4
    VMJumpIf 1, L_012F
    VMJump L_0159

L_012F:
    ActorDelete 0
    ActorSetGPos 1, 15, 0, 70, 1
    ActorSetGPos 2, 14, 0, 70, 1
    ActorDelete 3
    ActorDelete 4
    VMJump L_01C3

L_0159:
    WorkCmpConst 0x4110, 5
    VMJumpIf 1, L_016C
    VMJump L_0196

L_016C:
    ActorDelete 0
    ActorSetGPos 1, 15, 0, 70, 1
    ActorSetGPos 2, 14, 0, 70, 1
    ActorDelete 3
    ActorDelete 4
    VMJump L_01C3

L_0196:
    WorkCmpConst 0x4110, 6
    VMJumpIf 1, L_01A9
    VMJump L_01C3

L_01A9:
    ActorDelete 0
    ActorDelete 1
    ActorDelete 2
    ActorDelete 3
    ActorDelete 4
    VMJump L_01C3

L_01C3:
    VMStackPush 0x413a
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_023A
    WorkSetConst 0x8022, 0
    ActorSetGPos 255, 15, 0, 70, 0
    Plugin8_Cmd1027 0, 0x8022
    ActorSetGPos 0x8022, 14, 0, 71, 0
    Plugin8_Cmd1027 1, 0x8022
    ActorSetGPos 0x8022, 16, 0, 71, 0
    Plugin8_Cmd1027 2, 0x8022
    ActorSetGPos 0x8022, 13, 0, 72, 0
    Plugin8_Cmd1027 3, 0x8022
    ActorSetGPos 0x8022, 17, 0, 72, 0
    Plugin8_Cmd1030 23, 1
    Plugin8_Cmd1037 1

L_023A:
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    VMHalt

Script_7:
    VMCall L_0250
    VMHalt

L_0250:
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0277
    ObjInitWarpGPos 1, 0, 0, 0
    VMJump L_0281

L_0277:
    ObjInitWarpGPos 0, 0, 0, 0

L_0281:
    VMReturn

Script_3:
    ActorsPauseAll
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    VMSleep 16
    ActorCmdExec 0, Movement_04AC
    ActorCmdExec 3, Movement_04B4
    ActorCmdExec 4, Movement_04B4
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    VMSleep 16
    ActorCmdExec 255, Movement_04AC
    ActorCmdWait
    ActorWalkRoute 255, 15, 72, 0, 8, 0
    ActorCmdWait
    ActorMsg 1024, 3, 0, 0, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8024, 1

L_02FB:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_034F
    YesNoWin 0x8023
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_033D
    ActorMsg 1024, 4, 0, 0, 0
    WorkSetConst 0x8024, 0
    VMJump L_0349

L_033D:
    ActorMsg 1024, 5, 0, 0, 0

L_0349:
    VMJump L_02FB

L_034F:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    MsgWinCloseAll
    SystemMsg 53, 2
    InfoMsgClose
    Plugin8_Cmd1023 2, 0
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    SystemMsg 53, 2
    InfoMsgClose
    Plugin8_Cmd1023 3, 0
    Plugin8_Cmd1007 19, 255, 0, 0
    Plugin8_Cmd1007 20, 255, 0, 1
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    VMSleep 16
    ActorCmdExec 3, Movement_04AC
    ActorCmdWait
    ActorCmdExec 3, Movement_04C4
    ActorCmdWait
    ActorMsg 1024, 25, 3, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_04BC
    ActorCmdWait
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_04CC
    ActorCmdWait
    ActorMsg 1024, 9, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 10, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_04F8
    ActorCmdExec 3, Movement_04D4
    ActorCmdExec 4, Movement_04E4
    ActorCmdExec 255, Movement_0504
    ActorCmdWait
    ActorDelete 3
    ActorDelete 4
    SEPlay 1369
    ActorDelete 0
    SEWait
    ActorCmdExec 1, Movement_0510
    ActorCmdExec 2, Movement_0518
    ActorCmdWait
    ActorCmdExec 255, Movement_04CC
    ActorCmdWait
    ActorMsg 1024, 11, 1, 0, 0
    MsgWinCloseAll
    Plugin8_Cmd1023 1, 0
    Plugin8_Cmd1007 4, 255, 0, 0
    ActorMsg 1024, 12, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    MedalDiscover 182
    MedalDiscover 186
    MedalDiscover 190
    WorkSetConst 0x410b, 1
    WorkSetConst 0x4110, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04AC:
    Move 75, 1
    MoveEnd

Movement_04B4:
    Move 1, 1
    MoveEnd

Movement_04BC:
    Move 3, 1
    MoveEnd

Movement_04C4:
    Move 2, 1
    MoveEnd

Movement_04CC:
    Move 0, 1
    MoveEnd

Movement_04D4:
    Move 15, 1
    Move 14, 1
    Move 13, 9
    MoveEnd

Movement_04E4:
    Move 15, 1
    Move 63, 1
    Move 15, 1
    Move 13, 9
    MoveEnd

Movement_04F8:
    Move 15, 1
    Move 13, 9
    MoveEnd

Movement_0504:
    Move 63, 2
    Move 1, 1
    MoveEnd

Movement_0510:
    Move 13, 2
    MoveEnd

Movement_0518:
    Move 13, 2
    MoveEnd

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Plugin8_Cmd1007 4, 255, 0, 0
    WorkCmpConst 0x4110, 0
    VMJumpIf 1, L_0545
    VMJump L_055B

L_0545:
    ActorMsg 1024, 13, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0640

L_055B:
    WorkCmpConst 0x4110, 1
    VMJumpIf 1, L_056E
    VMJump L_0590

L_056E:
    ActorMsg 1024, 14, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    Plugin8_Cmd1028 1, 0
    WorkSetConst 0x4110, 2
    VMJump L_0640

L_0590:
    WorkCmpConst 0x4110, 2
    VMJumpIf 1, L_05A3
    VMJump L_05B9

L_05A3:
    ActorMsg 1024, 15, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0640

L_05B9:
    WorkCmpConst 0x4110, 3
    VMJumpIf 1, L_05CC
    VMJump L_05EE

L_05CC:
    ActorMsg 1024, 16, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    Plugin8_Cmd1028 1, 1
    WorkSetConst 0x4110, 4
    VMJump L_0640

L_05EE:
    WorkCmpConst 0x4110, 4
    VMJumpIf 1, L_0601
    VMJump L_0617

L_0601:
    ActorMsg 1024, 17, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0640

L_0617:
    WorkCmpConst 0x4110, 5
    VMJumpIf 1, L_062A
    VMJump L_0640

L_062A:
    ActorMsg 1024, 13, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0640

L_0640:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0648:
    Move 63, 2
    Move 14, 4
    MoveEnd

Movement_0654:
    Move 14, 1
    MoveEnd

Movement_065C:
    Move 14, 4
    Move 63, 1
    Move 69, 1
    MoveEnd

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Plugin8_Cmd1007 4, 255, 0, 0
    WorkCmpConst 0x4110, 0
    VMJumpIf 1, L_0691
    VMJump L_06A3

L_0691:
    ActorMsg 1024, 20, 2, 0, 0
    VMJump L_075C

L_06A3:
    WorkCmpConst 0x4110, 1
    VMJumpIf 1, L_06B6
    VMJump L_06C8

L_06B6:
    ActorMsg 1024, 20, 2, 0, 0
    VMJump L_075C

L_06C8:
    WorkCmpConst 0x4110, 2
    VMJumpIf 1, L_06DB
    VMJump L_06ED

L_06DB:
    ActorMsg 1024, 21, 2, 0, 0
    VMJump L_075C

L_06ED:
    WorkCmpConst 0x4110, 3
    VMJumpIf 1, L_0700
    VMJump L_0712

L_0700:
    ActorMsg 1024, 22, 2, 0, 0
    VMJump L_075C

L_0712:
    WorkCmpConst 0x4110, 4
    VMJumpIf 1, L_0725
    VMJump L_0737

L_0725:
    ActorMsg 1024, 23, 2, 0, 0
    VMJump L_075C

L_0737:
    WorkCmpConst 0x4110, 5
    VMJumpIf 1, L_074A
    VMJump L_075C

L_074A:
    ActorMsg 1024, 24, 2, 0, 0
    VMJump L_075C

L_075C:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    ActorCmdExec 1, Movement_04B4
    ActorCmdExec 2, Movement_04B4
    ActorCmdWait
    Plugin8_Cmd1007 4, 255, 0, 0
    ActorMsg 1024, 18, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_065C
    ActorCmdExec 1, Movement_0648
    ActorCmdWait
    ActorDelete 2
    ActorCmdExec 1, Movement_0654
    ActorCmdWait
    SEPlay 1369
    ActorDelete 1
    SEWait
    Plugin8_Cmd1028 3, 4
    Plugin8_Cmd1028 3, 5
    WorkSetConst 0x4110, 6
    Plugin8_Cmd1030 18, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    Plugin8_Cmd1007 8, 255, 0, 0
    Plugin8_Cmd1007 4, 255, 0, 1
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 26, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    Plugin8_Cmd1007 8, 255, 0, 0
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 27, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    Plugin8_Cmd1007 8, 255, 0, 0
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 27, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    ActorFindByGPos 0x8025, 0x8029, 14, 0, 71
    ActorFindByGPos 0x8026, 0x8029, 16, 0, 71
    ActorFindByGPos 0x8027, 0x8029, 13, 0, 72
    ActorFindByGPos 0x8028, 0x8029, 17, 0, 72
    WorkSetConst 0x802a, 0

L_08B8:
    VMStackPush 0x802a
    VMStackPushConst 8
    VMStackCmp 0
    VMJumpIf 255, L_0A6B
    Plugin8_Cmd1030 24, 1
    ActorCmdExec 255, Movement_0D20
    ActorCmdExec 0x8025, Movement_0D20
    ActorCmdExec 0x8026, Movement_0D20
    ActorCmdExec 0x8027, Movement_0D20
    ActorCmdExec 0x8028, Movement_0D20
    ActorCmdWait
    WorkGet 0x802c, 0x802a
    WorkAdd 0x802c, 25
    Plugin8_Cmd1002 0x802c, 0x8029
    VMStackPush 0x8029
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A5F
    VMStackPush 0x802a
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802a
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x802a
    VMStackPushConst 4
    VMStackCmp 1
    VMStackPush 0x802a
    VMStackPushConst 6
    VMStackCmp 1
    VMStackCmp 6
    VMStackCmp 6
    VMStackCmp 6
    VMJumpIf 255, L_0991
    ActorCmdExec 255, Movement_04BC
    ActorCmdExec 0x8025, Movement_04BC
    ActorCmdExec 0x8026, Movement_04BC
    ActorCmdExec 0x8027, Movement_04BC
    ActorCmdExec 0x8028, Movement_04BC
    VMJump L_09B9

L_0991:
    ActorCmdExec 255, Movement_04C4
    ActorCmdExec 0x8025, Movement_04C4
    ActorCmdExec 0x8026, Movement_04C4
    ActorCmdExec 0x8027, Movement_04C4
    ActorCmdExec 0x8028, Movement_04C4

L_09B9:
    ActorCmdWait
    WorkGet 0x802c, 0x802a
    WorkAdd 0x802c, 44
    Plugin8_Cmd1002 0x802c, 0x802b
    Plugin8_Cmd1030 24, 0
    Plugin8_Cmd1007 0, 0, 0x802a, 0
    Plugin8_Cmd1007 6, 0, 0x802a, 1
    Plugin8_Cmd1007 18, 0, 0x802a, 2
    Plugin8_Cmd1007 4, 255, 0, 3
    ActorMsg 1024, 30, 0x802b, 2, 0
    ActorMsgClose
    Plugin8_Cmd1007 0, 0, 0x802a, 0
    Plugin8_Cmd1007 21, 0, 0x802a, 1
    Plugin8_Cmd1007 22, 0, 0x802a, 2
    Plugin8_Cmd1007 23, 0, 0x802a, 3
    Plugin8_Cmd1007 1, 0, 0x802a, 4
    Plugin8_Cmd1007 10, 0, 0x802a, 5
    SystemMsg 31, 2
    SEPlay 2261
    SEPlay 2262
    SystemMsg 32, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose

L_0A5F:
    WorkAdd 0x802a, 1
    VMJump L_08B8

L_0A6B:
    Plugin8_Cmd1030 24, 1
    ActorCmdExec 255, Movement_0D28
    ActorCmdExec 0x8025, Movement_0D28
    ActorCmdExec 0x8026, Movement_0D28
    ActorCmdExec 0x8027, Movement_0D28
    ActorCmdExec 0x8028, Movement_0D28
    ActorCmdWait
    FadeEx 3, 0, 16, 2
    FadeExWait
    Plugin8_Cmd1039 1
    ActorSetGPos 255, 15, 0, 40, 1
    ActorSetGPos 0x8025, 14, 0, 39, 1
    ActorSetGPos 0x8026, 16, 0, 39, 1
    ActorSetGPos 0x8027, 13, 0, 38, 1
    ActorSetGPos 0x8028, 17, 0, 38, 1
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 64037, 0, 0xe1000, 0xf8000, 0x24000, 0x247000, 1
    EvCameraWait
    Plugin8_Cmd1037 0
    FadeEx 3, 16, 0, 2
    FadeExWait
    Plugin8_Cmd1030 24, 0
    WorkSetConst 0x802a, 0

L_0B21:
    VMStackPush 0x802a
    VMStackPushConst 4
    VMStackCmp 0
    VMJumpIf 255, L_0C19
    WorkCmpConst 0x802a, 0
    VMJumpIf 1, L_0B47
    VMJump L_0B53

L_0B47:
    WorkGet 0x802b, 0x8025
    VMJump L_0BB0

L_0B53:
    WorkCmpConst 0x802a, 1
    VMJumpIf 1, L_0B66
    VMJump L_0B72

L_0B66:
    WorkGet 0x802b, 0x8026
    VMJump L_0BB0

L_0B72:
    WorkCmpConst 0x802a, 2
    VMJumpIf 1, L_0B85
    VMJump L_0B91

L_0B85:
    WorkGet 0x802b, 0x8027
    VMJump L_0BB0

L_0B91:
    WorkCmpConst 0x802a, 3
    VMJumpIf 1, L_0BA4
    VMJump L_0BB0

L_0BA4:
    WorkGet 0x802b, 0x8028
    VMJump L_0BB0

L_0BB0:
    VMSleep 10
    ActorCmdExec 0x802b, Movement_0D30
    ActorCmdWait
    WorkGet 0x802c, 0x802a
    WorkAdd 0x802c, 1
    WordSetNumber 4, 0x802c, 1
    Plugin8_Cmd1007 0, 3, 0x802a, 0
    Plugin8_Cmd1007 21, 3, 0x802a, 1
    Plugin8_Cmd1007 22, 3, 0x802a, 2
    Plugin8_Cmd1007 23, 3, 0x802a, 3
    SEPlay 2261
    SEPlay 2262
    SystemMsg 35, 1
    SEWait
    MsgWaitAdvance
    InfoMsgClose
    WorkAdd 0x802a, 1
    VMJump L_0B21

L_0C19:
    VMSleep 10
    Plugin8_Cmd1007 8, 255, 0, 0
    Plugin8_Cmd1007 11, 255, 0, 1
    Plugin8_Cmd1007 4, 255, 0, 2
    SEPlay 2261
    SEPlay 2262
    SystemMsg 33, 1
    SEWait
    MsgWaitAdvance
    RecordGet 127, 0x8029
    WordSetNumber 0, 0x8029, 7
    RecordGet 128, 0x8029
    WordSetNumber 1, 0x8029, 7
    Plugin8_Cmd1007 12, 255, 0, 2
    SystemMsg 34, 1
    Plugin8_Cmd1007 8, 255, 0, 0
    Plugin8_Cmd1002 63, 0x8029
    WorkAdd 0x8029, 36
    SystemMsg 0x8029, 1
    InfoMsgClose
    SEPlay 1578
    FadeOutWhite
    FadeWait
    SEWait
    EvCameraMoveToDefault 1
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    Plugin8_Cmd1039 0
    Plugin8_Cmd1008 1, 3, 0
    Plugin8_Cmd1008 1, 3, 1
    Plugin8_Cmd1008 1, 3, 2
    Plugin8_Cmd1008 1, 3, 3
    WorkSetConst 0x413a, 2
    FlagReset 2545
    MapChangeCore 491, 8, 0, 8, 1
    FadeInWhite
    FadeWait
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0D20:
    Move 12, 7
    MoveEnd

Movement_0D28:
    Move 12, 5
    MoveEnd

Movement_0D30:
    Move 1, 1
    Move 61, 1
    Move 2, 1
    Move 61, 1
    Move 0, 1
    Move 61, 1
    Move 3, 1
    Move 61, 1
    Move 1, 1
    MoveEnd

Script_12:
    ActorsPauseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
