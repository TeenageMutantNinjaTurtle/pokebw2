#include "asm/field_script.inc"

// Script plugin 6, from the only plugin whose commands it decodes with

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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_1:
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0075
    WorkSetConst 0x4020, 121
    WorkSetConst 0x4021, 365
    WorkSetConst 0x4022, 368
    VMJump L_0087

L_0075:
    WorkSetConst 0x4020, 121
    WorkSetConst 0x4021, 364
    WorkSetConst 0x4022, 367

L_0087:
    VMHalt

Script_2:
    VMStackPush 0x4072
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00AE
    ActorSetGPos 0, 17, 0, 16, 1
    VMJump L_00D9

L_00AE:
    VMStackPush 0x4072
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_00D9
    ActorSetGPos 3, 15, 0, 22, 0
    ActorSetGPos 0, 17, 0, 16, 2

L_00D9:
    VMStackPush 0x4072
    VMStackPushConst 4
    VMStackCmp 1
    VMStackPush 0x410d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0108
    ActorSetGPos 11, 15, 0, 18, 1

L_0108:
    VMHalt

Script_3:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x108000, 40
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0143
    PlayerSetSpecialSequence 1

L_0143:
    ActorWalkRoute 255, 15, 20, 1, 8, 0
    ActorCmdWait
    EvCameraWait
    VMSleep 10
    BGMPlay 1093
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_06AC
    VMSleep 76
    SEPlay 2274
    SEWait
    ActorCmdWait
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    PlayFieldEffect 109
    ActorSetGPos 2, 14, 0, 16, 1
    ActorSetGPos 0, 18, 0, 16, 1
    FadeEx 12, 16, 0, 1
    FadeExWait
    PVPlay 646, 0
    ActorMsg 1024, 2, 2, 5, 0
    PVWait
    MsgWaitAdvance
    ActorMsgClose
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_06BC
    VMSleep 30
    SEPlay 2274
    SEWait
    ActorCmdWait
    ScreamMsg 4, 1
    InfoMsgClose_0039
    PVPlay 646, 0
    ScreamMsg 5, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    Plugin6_Cmd1002 0
    VMSleep 300
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x13d000, 40
    VMSleep 200
    EvCameraWait
    Cmd_02E8 2, 0
    BGMFadeOutAll 1
    VMSleep 20
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_025D
    ScreamMsg 6, 2
    VMJump L_0262

L_025D:
    ScreamMsg 7, 2

L_0262:
    VMSleep 60
    InfoMsgClose_0039
    Plugin6_Cmd1001
    VMNop2
    Cmd_02E9 2, 0
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_028F
    PlayFieldEffect 107
    VMJump L_0293

L_028F:
    PlayFieldEffect 108

L_0293:
    Plugin6_Cmd1002 1
    VMSleep 50
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x108000, 20
    EvCameraWait
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    BGMPlay 1269
    FlagSet 2556
    BGMAmbienceResume
    Plugin6_Cmd1004 1
    VMSleep 100
    FadeOutBlack
    FadeWait
    EvCameraRebind
    EvCameraEnd
    FlagReset 886
    FlagReset 888
    MapChangeCore 604, 15, 0, 21, 0
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9816, 0, 0xed000, 0xf8000, 0, 0x12c000, 1
    EvCameraWait
    ActorSetGPos 2, 14, 0, 16, 1
    ActorSetGPos 0, 17, 0, 16, 1
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0348
    Plugin6_Cmd1006 3, 0
    VMStackPush 30
    VMStackPushConst 0

L_0348:
    Plugin6_Cmd1006 3, 0
    VMStackPush 1006
    VMCall L_035C
    FadeInBlackQ
    FadeWait

L_035C:
    FlagSet 2555
    FlagReset 2556
    VMSleep 7
    ActorMsgVersioned 1024, 10, 9, 4, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_03A2
    PVPlay 644, 0
    ScreamMsg 11, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    VMJump L_03B3

L_03A2:
    PVPlay 643, 0
    ScreamMsg 12, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039

L_03B3:
    ActorMsg 1024, 13, 0, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 14, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_1190
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 0, Movement_1180
    ActorCmdWait
    ActorMsgVersioned 1024, 16, 15, 0, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 17, 4, 2, 0
    MsgWinCloseAll
    BGMFadeOutAll 12
    ActorMsg 1024, 18, 0, 1, 0
    MsgWinCloseAll
    BGMPlay 1270
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0xf0000, 35
    VMSleep 20
    ActorCmdExec 0, Movement_06D4
    VMSleep 23
    SEPlay 2275
    BGMAmbienceResume
    EvCameraWait
    ActorCmdWait
    SEWait
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_046C
    PlayFieldEffect 110
    VMJump L_0470

L_046C:
    PlayFieldEffect 111

L_0470:
    FadeOutBlackQ
    BGMPush 6
    FadeWait
    ActorDelete 2
    WorkSetConst 0x4020, 366
    ActorAdd 2
    FlagSet 888
    ActorDelete 3
    FieldClose
    Call3DDemo 16, 0
    FieldOpen
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_04BB
    FieldClose
    Call3DDemo 17, 0
    FieldOpen
    VMJump L_04C5

L_04BB:
    FieldClose
    Call3DDemo 20, 0
    FieldOpen

L_04C5:
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x125000, 1
    EvCameraWait
    ActorSetGPos 0, 17, 0, 16, 1
    ActorSetGPos 2, 15, 0, 16, 1
    ActorSetGPos 4, 17, 0, 19, 2
    Plugin6_Cmd1006 4, 0xfffc
    VMNop
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0536
    ActorNew 15, 18, 1, 251, 143, 0
    VMJump L_0544

L_0536:
    ActorNew 15, 18, 1, 251, 144, 0

L_0544:
    Plugin6_Cmd1006 251, 0
    VMStackPushConst 1003
    MoneyCheck 419, 162
    VMNop
    ActorMsg 423, 3, 18, 73, 1024
    VMRegSet8 19, 0
    VMCall L_056E
    MsgWinCloseAll

L_056E:
    ActorMsgVersioned 1024, 22, 21, 0, 1, 0
    MsgWinCloseAll
    FadeOutBlackQ
    BGMPush 6
    FadeWait
    ActorDelete 251
    FlagSet 887
    ActorDelete 2
    EvCameraRebind
    EvCameraEnd
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_05C3
    FieldClose
    Call3DDemo 18, 0
    FieldOpen
    FieldClose
    Call3DDemo 19, 0
    FieldOpen
    VMJump L_05D7

L_05C3:
    FieldClose
    Call3DDemo 21, 0
    FieldOpen
    FieldClose
    Call3DDemo 22, 0
    FieldOpen

L_05D7:
    FlagReset 889
    ActorAdd 1
    ActorSetGPos 0, 17, 0, 16, 1
    ActorSetGPos 255, 15, 0, 20, 0
    ActorSetGPos 4, 17, 0, 19, 0
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x108000, 1
    EvCameraWait
    FadeInBlackQ
    BGMPop 0, 60
    FadeWait
    ActorMsg 1024, 23, 4, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 24, 0, 0, 0
    MsgWinCloseAll
    VMSleep 8
    ActorMsg 1024, 25, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_11A0
    ActorCmdWait
    ActorMsg 1024, 26, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_06D4
    VMSleep 25
    SEPlay 2274
    SEWait
    ActorCmdWait
    ActorMsg 1024, 27, 0, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 10
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    WorkSetConst 0x4072, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_06AC:
    Move 11, 3
    Move 1, 1
    Move 182, 1
    MoveEnd

Movement_06BC:
    Move 1, 1
    Move 182, 1
    MoveEnd
    Move 10, 1
    Move 1, 1
    MoveEnd

Movement_06D4:
    Move 182, 1
    MoveEnd
    Move 35, 1
    Move 63, 1
    Move 33, 1
    MoveEnd

L_06EC:
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0710
    ScreamMsg 33, 2
    PVPlay 644, 0
    VMJump L_071B

L_0710:
    ScreamMsg 34, 2
    PVPlay 643, 0

L_071B:
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    PVPlay 646, 0
    ScreamMsg 35, 5
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0750
    InfoMsg 36, 2
    VMJump L_0755

L_0750:
    InfoMsg 37, 2

L_0755:
    MsgWaitAdvance
    InfoMsgClose_0039
    Cmd_02E9 1, 0
    ActorCmdExec 255, Movement_1190
    ActorCmdWait
    ActorMsgVersioned 1024, 39, 38, 0, 5, 0
    MsgWinCloseAll
    WordSetPlayerName 0
    ActorMsg 1024, 42, 4, 0, 0
    MsgWinCloseAll
    SEPlay 2059
    PokePartyRecoverAll
    SEWait
    WorkSetConst 0x4072, 3
    VMCall L_08D4
    VMReturn

Script_10:
    ActorsPauseAll
    PlayerGetGPos 0x8022, 0x8023
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07C3
    PlayerSetSpecialSequence 1

L_07C3:
    WorkCmpConst 0x8022, 13
    VMJumpIf 1, L_07D6
    VMJump L_07E4

L_07D6:
    ActorCmdExec 255, Movement_0888
    VMJump L_0868

L_07E4:
    WorkCmpConst 0x8022, 14
    VMJumpIf 1, L_07F7
    VMJump L_0805

L_07F7:
    ActorCmdExec 255, Movement_0894
    VMJump L_0868

L_0805:
    WorkCmpConst 0x8022, 15
    VMJumpIf 1, L_0818
    VMJump L_0826

L_0818:
    ActorCmdExec 255, Movement_08A4
    VMJump L_0868

L_0826:
    WorkCmpConst 0x8022, 16
    VMJumpIf 1, L_0839
    VMJump L_0847

L_0839:
    ActorCmdExec 255, Movement_08B4
    VMJump L_0868

L_0847:
    WorkCmpConst 0x8022, 17
    VMJumpIf 1, L_085A
    VMJump L_0868

L_085A:
    ActorCmdExec 255, Movement_08C4
    VMJump L_0868

L_0868:
    ActorCmdWait
    ActorMsgVersioned 1024, 41, 40, 0, 5, 0
    MsgWinCloseAll
    VMCall L_08D4
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0888:
    Move 12, 7
    Move 15, 2
    MoveEnd

Movement_0894:
    Move 14, 1
    Move 12, 7
    Move 15, 2
    MoveEnd

Movement_08A4:
    Move 14, 2
    Move 12, 7
    Move 15, 2
    MoveEnd

Movement_08B4:
    Move 14, 3
    Move 12, 7
    Move 15, 2
    MoveEnd

Movement_08C4:
    Move 14, 4
    Move 12, 7
    Move 15, 2
    MoveEnd

L_08D4:
    CallTrainerBattle 345, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0941
    FlagSet 885
    FlagReset 968
    FlagReset 969
    FlagSet 889
    ActorDelete 0
    ActorAdd 5
    ActorSetGPos 255, 15, 0, 16, 3
    ActorSetGPos 5, 17, 0, 16, 2
    ActorSetGPos 3, 15, 0, 22, 0
    ActorCmdExec 4, Movement_1158
    ActorCmdWait
    CallTrainerBattleEnd
    VMJump L_0943

L_0941:
    CallTrainerLose

L_0943:
    ActorCmdExec 5, Movement_0C6C
    ActorCmdWait
    ActorMsg 1024, 43, 5, 5, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_0C58
    ActorCmdWait
    ActorMsg 1024, 44, 5, 5, 0
    MsgWinCloseAll
    BGMPlay 1271
    ActorMsg 1024, 45, 4, 6, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_1178
    ActorCmdWait
    ActorMsg 1024, 46, 5, 5, 1
    MsgWinCloseAll
    ActorNew 18, 17, 1, 251, 182, 0
    ActorCmdExec 251, Movement_0C7C
    ActorCmdWait
    ActorMsg 1024, 47, 251, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 48, 4, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 49, 251, 5, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_1178
    ActorCmdWait
    ActorCmdExec 251, Movement_0C84
    VMSleep 2
    ActorDelete 5
    ActorCmdWait
    ActorDelete 251
    ActorAdd 6
    VMSleep 16
    ActorCmdExec 4, Movement_0C90
    VMSleep 8
    ActorCmdExec 255, Movement_1180
    ActorCmdWait
    ActorMsg 1024, 50, 4, 6, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_1180
    ActorCmdWait
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0A63
    InfoMsg 51, 1
    PVPlay 644, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_0A74

L_0A63:
    InfoMsg 52, 1
    PVPlay 643, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll

L_0A74:
    ActorCmdExec 4, Movement_1178
    ActorCmdWait
    ActorMsgVersioned 1024, 54, 53, 4, 6, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_1190
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 4, Movement_1178
    ActorCmdWait
    Cmd_02B4 0, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_0AD7
    Cmd_02B5 0, 1
    ActorMsg 1024, 56, 4, 6, 0
    VMJump L_0AE3

L_0AD7:
    ActorMsg 1024, 55, 4, 6, 0

L_0AE3:
    ActorMsgVersioned 1024, 58, 57, 4, 6, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_1140
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsgVersioned 1024, 60, 59, 4, 6, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 4
    ActorCmdExec 4, Movement_0C9C
    VMSleep 8
    ActorCmdExec 255, Movement_0C9C
    ActorCmdWait
    FadeExWait
    ActorDelete 4
    ActorDelete 3
    ActorSetGPos 255, 17, 0, 18, 2
    FadeEx 3, 16, 0, 4
    Plugin6_Cmd1004 0
    VMSleep 10
    FadeExWait
    VMSleep 160
    Plugin6_Cmd1005
    FlagReset 2555
    FlagReset 1031
    ActorAdd 11
    BGMChangeMap
    ActorWalkRoute 11, 15, 18, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 11, Movement_1190
    ActorCmdWait
    ActorMsg 1024, 70, 11, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0BBD
    ActorMsg 1024, 71, 11, 0, 0
    VMJump L_0BC9

L_0BBD:
    ActorMsg 1024, 72, 11, 0, 0

L_0BC9:
    MsgWinCloseAll
    ActorCmdExec 11, Movement_1180
    ActorCmdWait
    ActorMsg 1024, 73, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_0CA8
    ActorCmdWait
    ActorMsg 1024, 74, 11, 0, 0
    ActorMsg 1024, 75, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagReset 364
    WorkSetConst 0x4072, 4
    FlagSet 876
    FlagSet 878
    FlagSet 879
    FlagSet 882
    FlagSet 885
    FlagSet 968
    FlagSet 886
    FlagSet 888
    FlagSet 854
    Cmd_0262 0, 6
    Cmd_0262 1, 36
    Cmd_0262 2, 12
    Cmd_0262 3, 7
    Cmd_0262 4, 0
    VMReturn
    .balign 4, 0

Movement_0C58:
    Move 10, 1
    Move 11, 2
    Move 14, 1
    Move 33, 1
    MoveEnd

Movement_0C6C:
    Move 71, 1
    Move 11, 1
    Move 72, 1
    MoveEnd

Movement_0C7C:
    Move 184, 1
    MoveEnd

Movement_0C84:
    Move 185, 1
    Move 69, 1
    MoveEnd

Movement_0C90:
    Move 14, 2
    Move 12, 1
    MoveEnd

Movement_0C9C:
    Move 13, 1
    Move 9, 2
    MoveEnd

Movement_0CA8:
    Move 161, 1
    Move 35, 1
    MoveEnd

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 30, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 29, 28, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 75, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D29
    PlayerSetSpecialSequence 1

L_0D29:
    SEPlay 1351
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0xff000, 6
    EvCameraWait
    GameGetVersion 0x8020
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8024, 2048
    WorkOr 0x8024, 1
    WorkOr 0x8024, 16
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0DA5
    ActorCmdExec 1, Movement_0EE0
    ActorCmdWait
    ScreamMsg 31, 2
    PVPlay 646, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    CallWildBattleEx 646, 55, 2, 0x8024
    VMJump L_0DCA

L_0DA5:
    ActorCmdExec 1, Movement_0ED8
    ActorCmdWait
    ScreamMsg 32, 2
    PVPlay 646, 1
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    CallWildBattleEx 646, 55, 1, 0x8024

L_0DCA:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WildBattleIsVictory 0x8025
    WildBattleGetResult 0x8026
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E8D
    VMStackPush 0x8026
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0E58
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveToDefault 1
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    FlagSet 889
    FlagReset 888
    ActorDelete 1
    ActorAdd 3
    ActorSetGPos 255, 15, 0, 16, 0
    ActorSetGPos 3, 15, 0, 22, 0
    ActorSetGPos 0, 17, 0, 16, 2
    ActorCmdExec 4, Movement_1158
    ActorCmdWait
    Plugin6_Cmd1007 30, 47
    VMNop

L_0E58:
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E87
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveToDefault 1
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorDelete 1
    ActorAdd 1
    FlagReset 889
    CallWildBattleEnd

L_0E87:
    VMJump L_0EA6

L_0E8D:
    VMStackPushFlag 889
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0EA4
    FlagReset 889

L_0EA4:
    CallWildLose

L_0EA6:
    WorkCmpConst 0x8026, 2
    VMJumpIf 1, L_0EB9
    VMJump L_0EC5

L_0EB9:
    VMCall L_06EC
    VMJump L_0EC5

L_0EC5:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0ED8:
    Move 191, 1
    MoveEnd

Movement_0EE0:
    Move 191, 1
    MoveEnd

Script_7:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 63, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorDelete 7
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 628
    WorkSet 0x8001, 1
    RTCallGlobal 2807
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 1003
    FlagSet 481
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    PVPlay 646, 0
    ScreamMsg 61, 1
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    CallWildBattle 646, 70, 1
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0FB5
    FlagSet 1004
    ActorDelete 8
    VMStackPushFlag 481
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0F8E
    FlagReset 1003
    ActorAdd 7

L_0F8E:
    VMStackPushFlag 483
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0FAD
    ActorSetGPos 255, 15, 0, 16, 0

L_0FAD:
    CallWildBattleEnd
    VMJump L_0FB7

L_0FB5:
    CallWildLose

L_0FB7:
    WildBattleGetResult 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0FCE
    VMJump L_0FDC

L_0FCE:
    FlagSet 249
    Cmd_00E4 2
    VMJump L_100C

L_0FDC:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0FFC
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0FFC
    VMJump L_100C

L_0FFC:
    SystemMsg 62, 0
    MsgWaitAdvance
    InfoMsgClose
    VMJump L_100C

L_100C:
    VMStackPushFlag 483
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1025
    VMCall L_102B

L_1025:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_102B:
    FlagReset 1011
    ActorAdd 9
    ActorAdd 10
    ActorWalkRoute 9, 15, 18, 0, 8, 0
    VMSleep 4
    ActorWalkRoute 10, 14, 18, 0, 8, 0
    VMSleep 40
    ActorCmdExec 255, Movement_1180
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 64, 9, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 65, 10, 4, 0
    VMStackPushFlag 388
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_10B3
    MsgWinCloseAll
    ActorCmdExec 10, Movement_1198
    ActorCmdWait
    ActorMsg 1024, 66, 10, 4, 0
    VMJump L_10BF

L_10B3:
    ActorMsg 1024, 67, 10, 4, 0

L_10BF:
    MsgWinCloseAll
    ActorMsg 1024, 68, 9, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 69, 10, 4, 0
    MsgWinCloseAll
    ActorWalkRoute 9, 15, 25, 0, 8, 0
    VMSleep 4
    ActorWalkRoute 10, 14, 25, 0, 8, 0
    ActorCmdWait
    ActorDelete 9
    ActorDelete 10
    FlagSet 483
    FlagSet 1011
    FlagReset 739
    VMReturn
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1134
    CallTrainerBattleEnd
    VMJump L_1136

L_1134:
    CallTrainerLose

L_1136:
    VMReturn
    Move 13, 1
    MoveEnd

Movement_1140:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd

Movement_1158:
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

Movement_1178:
    Move 32, 1
    MoveEnd

Movement_1180:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_1190:
    Move 35, 1
    MoveEnd

Movement_1198:
    Move 75, 1
    MoveEnd

Movement_11A0:
    Move 159, 1
    MoveEnd
