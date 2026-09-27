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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMStackPushFlag 2780
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_007D
    WorkSetConst 0x4000, 1

L_007D:
    VMHalt

Script_2:
    VMStackPush 0x40df
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_009E
    ActorSetGPos 0, 787, 0xfffc, 176, 2

L_009E:
    VMStackPushFlag 311
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_010F
    VMStackPushFlag 806
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 807
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00F4
    FlagSet 806
    FlagSet 807
    ActorDelete 2
    ActorDelete 3

L_00F4:
    VMStackPushFlag 808
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_010F
    FlagReset 808
    ActorAdd 5

L_010F:
    VMHalt

Script_3:
    ActorsPauseAll
    PlayerGetDir 0x8020
    ActorCmdExec 0, Movement_0780
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_013A
    ActorCmdExec 255, Movement_0770

L_013A:
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 0, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40de, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    ActorNew 792, 100, 1, 251, 230, 0
    .byte 0xe8
    .byte 0x03
    .byte 0x17
    .byte 0x03
    .byte 0xfb
    .byte 0xff
    .byte 0x97
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    MoneyCheck 791, 156
    VMNop2
    ActorMsg 1024, 4, 251, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorCmdExec 255, Movement_0768
    VMStackPush 0x8022
    VMStackPushConst 156
    VMStackCmp 1
    VMJumpIf 255, L_01BA
    ActorCmdExec 251, Movement_0220
    VMJump L_01C2

L_01BA:
    ActorCmdExec 251, Movement_0228

L_01C2:
    ActorCmdWait
    ActorMsg 1024, 5, 251, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8022
    VMStackPushConst 156
    VMStackCmp 1
    VMJumpIf 255, L_01F7
    ActorCmdExec 251, Movement_0234
    VMSleep 40
    VMJump L_0203

L_01F7:
    ActorCmdExec 251, Movement_0240
    VMSleep 32

L_0203:
    ActorCmdExec 255, Movement_0778
    ActorCmdWait
    ActorDelete 251
    WorkSetConst 0x411f, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0220:
    Move 15, 2
    MoveEnd

Movement_0228:
    Move 13, 1
    Move 15, 2
    MoveEnd

Movement_0234:
    Move 15, 1
    Move 13, 9
    MoveEnd

Movement_0240:
    Move 15, 1
    Move 13, 8
    MoveEnd

Script_4:
    ActorsPauseAll
    ActorCmdExec 0, Movement_0780
    ActorCmdWait
    ActorWalkRoute 0, 784, 176, 1, 8, 0
    ActorCmdExec 255, Movement_0388
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 6, 0, 5, 0
    MsgWinCloseAll
    FlagReset 805
    ActorAdd 1
    ActorWalkRoute 1, 783, 178, 1, 8, 1
    VMSleep 32
    ActorCmdExec 255, Movement_0778
    ActorCmdExec 0, Movement_0778
    ActorCmdWait
    ActorMsg 1024, 7, 1, 6, 0
    MsgWinCloseAll
    WordSetLoadRivalName 1
    ActorMsg 1024, 8, 0, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 1, 6, 0
    ActorMsg 1024, 10, 1, 6, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_030F
    ActorMsg 1024, 11, 1, 6, 0
    MsgWinCloseAll
    VMJump L_031D

L_030F:
    ActorMsg 1024, 12, 1, 6, 0
    MsgWinCloseAll

L_031D:
    ActorCmdExec 1, Movement_0778
    ActorCmdWait
    ActorMsg 1024, 13, 1, 6, 0
    MsgWinCloseAll
    ActorWalkRoute 1, 783, 184, 1, 8, 1
    ActorCmdWait
    ActorDelete 1
    WordSetLoadRivalName 1
    ActorMsg 1024, 14, 0, 5, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 783, 184, 1, 8, 1
    ActorCmdWait
    ActorDelete 0
    WorkSetConst 0x40df, 2
    FlagSet 804
    FlagSet 805
    Cmd_0262 1, 28
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0388:
    Move 13, 3
    Move 35, 1
    MoveEnd

Script_5:
    ActorsPauseAll
    VMStackPush 0x40de
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03CE
    SEPlay 1351
    ActorSetEyeToEye
    WordSetLoadRivalName 1
    ActorMsg 1024, 0, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40de, 2
    VMJump L_03E5

L_03CE:
    WordSetLoadRivalName 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_03E5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    VMStackPushFlag 806
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0434
    FlagSet 311

L_0434:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    VMStackPushFlag 2451
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0482
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    MsgWinCloseAll
    Cmd_0275 0, 40, 0
    SEPlay 1908
    SystemMsg 23, 0
    SEWait
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2451
    VMJump L_0496

L_0482:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose

L_0496:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_04C3
    ActorCmdExec 255, Movement_0778
    ActorCmdWait

L_04C3:
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04EF
    InfoMsg 29, 2
    LastKeyWait
    InfoMsgClose_0039
    FlagSet 2780
    WorkSetConst 0x4000, 1
    VMJump L_070A

L_04EF:
    FlagReset 985
    WorkSetConst 0x4000, 1
    InfoMsg 30, 2
    InfoMsgClose_0039
    ActorAdd 6
    Random 0x4001, 4
    VMStackPush 0x4001
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0531
    ActorNew 777, 182, 3, 251, 230, 0
    VMJump L_05A0

L_0531:
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0558
    ActorNew 777, 182, 3, 251, 22, 0
    VMJump L_05A0

L_0558:
    VMStackPush 0x4001
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_057F
    ActorNew 777, 182, 3, 251, 52, 0
    VMJump L_05A0

L_057F:
    VMStackPush 0x4001
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_05A0
    ActorNew 777, 182, 3, 251, 315, 0

L_05A0:
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 786
    VMStackCmp 1
    VMJumpIf 255, L_05CF
    ActorCmdExec 6, Movement_0788
    ActorCmdExec 251, Movement_07B0
    VMJump L_05DF

L_05CF:
    ActorCmdExec 6, Movement_079C
    ActorCmdExec 251, Movement_07C4

L_05DF:
    ActorCmdWait
    ActorMsg 1024, 31, 6, 0, 0
    MsgWinCloseAll
    SEPlay 2063
    FadeEx 12, 16, 0, 2
    FadeExWait
    SEWait
    VMSleep 8
    VMStackPush 0x4001
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_062A
    ActorMsg 1024, 32, 251, 0, 0
    VMJump L_069D

L_062A:
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_064F
    ActorMsg 1024, 33, 251, 0, 0
    VMJump L_069D

L_064F:
    VMStackPush 0x4001
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0674
    ActorMsg 1024, 34, 251, 0, 0
    VMJump L_069D

L_0674:
    VMStackPush 0x4001
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_069D
    PVPlay 575, 0
    ActorMsg 1024, 35, 251, 0, 0
    PVWait
    MsgWaitAdvance

L_069D:
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 786
    VMStackCmp 1
    VMJumpIf 255, L_06D4
    ActorCmdExec 6, Movement_07D0
    ActorCmdExec 251, Movement_07F0
    VMSleep 16
    ActorCmdExec 255, Movement_0768
    VMJump L_06F0

L_06D4:
    ActorCmdExec 6, Movement_07E0
    ActorCmdExec 251, Movement_0804
    VMSleep 8
    ActorCmdExec 255, Movement_0768

L_06F0:
    ActorCmdWait
    ActorDelete 6
    ActorDelete 251
    VMSleep 16
    MedalGive 98
    FlagSet 985
    FlagSet 2780

L_070A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 26, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 27, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 28, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 35, 1
    MoveEnd

Movement_0768:
    Move 34, 1
    MoveEnd

Movement_0770:
    Move 32, 1
    MoveEnd

Movement_0778:
    Move 33, 1
    MoveEnd

Movement_0780:
    Move 75, 1
    MoveEnd

Movement_0788:
    Move 15, 7
    Move 13, 1
    Move 15, 2
    Move 32, 1
    MoveEnd

Movement_079C:
    Move 15, 7
    Move 13, 1
    Move 15, 3
    Move 32, 1
    MoveEnd

Movement_07B0:
    Move 15, 7
    Move 12, 1
    Move 15, 3
    Move 13, 1
    MoveEnd

Movement_07C4:
    Move 15, 9
    Move 33, 1
    MoveEnd

Movement_07D0:
    Move 14, 2
    Move 12, 1
    Move 14, 7
    MoveEnd

Movement_07E0:
    Move 14, 3
    Move 12, 1
    Move 14, 7
    MoveEnd

Movement_07F0:
    Move 12, 1
    Move 14, 3
    Move 13, 1
    Move 14, 7
    MoveEnd

Movement_0804:
    Move 14, 9
    MoveEnd

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    VMStackPushFlag 2454
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_090A
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 36, 0, 0
    MsgWinCloseAll
    Cmd_0275 0, 25, 0
    SEPlay 1908
    SystemMsg 37, 0
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    ParentActorMsg 1024, 38, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2454
    VMJump L_091E

L_090A:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 38, 0, 0
    LastKeyWait
    ActorMsgClose

L_091E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
