#include "asm/field_script.inc"

// Script plugin 1, from the zones that use this file

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

Script_1:
    Plugin1_Cmd1003 21, 0, 0, 32803
    ActorSetGPos 0, 17, 0, 14, 3
    ActorSetGPos 1, 76, 0, 14, 2
    VMStackPush 0x4179
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_008B
    Plugin1_Cmd1003 18, 0x8023, 1, 0
    ActorSetGPos 255, 75, 0, 12, 1
    Plugin1_Cmd1003 329, 0, 0, 0

L_008B:
    VMHalt

Script_2:
    Plugin1_Cmd1003 21, 0, 0, 32803
    FieldGetContinueFlag 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00F0
    VMStackPush 0x4179
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_00F0
    Plugin1_Cmd1001 1, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 8
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_00F0
    WorkSetConst 0x4179, 3

L_00F0:
    Plugin1_Cmd1003 18, 0x8023, 1, 0
    VMStackPush 0x4179
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0117
    Plugin1_Cmd1003 20, 1, 0, 0

L_0117:
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4179
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01AB
    ActorMsg 1024, 15, 0x8011, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32784
    ListMenuAdd 16, 65535, 0
    ListMenuAdd 17, 65535, 1
    ListMenuAdd 18, 65535, 2
    ListMenuShow
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0176
    VMJump L_0184

L_0176:
    MsgWinCloseAll
    VMCall L_01B7
    VMJump L_01A5

L_0184:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0197
    VMJump L_01A3

L_0197:
    VMCall L_0A9E
    VMJump L_01A5

L_01A3:
    MsgWinCloseAll

L_01A5:
    VMJump L_01B1

L_01AB:
    VMCall L_0A9E

L_01B1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_01B7:
    Plugin1_Cmd1003 21, 0, 0, 32803
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_01D4
    VMJump L_01E0

L_01D4:
    VMCall L_02BB
    VMJump L_02B9

L_01E0:
    WorkCmpConst 0x8023, 5
    VMJumpIf 1, L_01F3
    VMJump L_01FF

L_01F3:
    VMCall L_02BB
    VMJump L_02B9

L_01FF:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_0212
    VMJump L_021E

L_0212:
    VMCall L_02BB
    VMJump L_02B9

L_021E:
    WorkCmpConst 0x8023, 6
    VMJumpIf 1, L_0231
    VMJump L_023D

L_0231:
    VMCall L_02BB
    VMJump L_02B9

L_023D:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_0250
    VMJump L_025C

L_0250:
    VMCall L_02BB
    VMJump L_02B9

L_025C:
    WorkCmpConst 0x8023, 7
    VMJumpIf 1, L_026F
    VMJump L_027B

L_026F:
    VMCall L_02BB
    VMJump L_02B9

L_027B:
    WorkCmpConst 0x8023, 3
    VMJumpIf 1, L_028E
    VMJump L_029A

L_028E:
    VMCall L_0438
    VMJump L_02B9

L_029A:
    WorkCmpConst 0x8023, 8
    VMJumpIf 1, L_02AD
    VMJump L_02B9

L_02AD:
    VMCall L_0438
    VMJump L_02B9

L_02B9:
    VMReturn

L_02BB:
    WorkSetConst 0x8024, 0
    WorkGet 0x8024, 0x8011
    RTCallGlobal 10345
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F0
    ActorMsg 1024, 31, 0x8024, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_02F0:
    WorkGet 0x8008, 0x8024
    RTCallGlobal 10346
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_031F
    ActorMsg 1024, 31, 0x8008, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_031F:
    Plugin1_Cmd1003 310, 0, 0, 32803
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 7
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0391
    VMCall L_03F4
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8008, 2
    RTCallGlobal 10347
    ActorCmdExec 255, Movement_03EC
    ActorCmdWait
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0391
    ActorMsg 1024, 31, 0x8024, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_0391:
    WorkSetConst 0x4176, 4
    WorkSetConst 0x4178, 1
    Plugin1_Cmd1003 322, 0, 0, 0
    Plugin1_Cmd1003 316, 0, 0, 0
    SystemMsg 2, 2
    SaveDataWrite 0x8010
    MsgWinCloseAll
    RecordAdd 48, 1
    VMCall L_157C
    FlagSet 604
    FlagSet 605
    WorkSetConst 0x4179, 0
    MapChangeCore 75, 7, 0, 4, 0
    WorkSetConst 0x8024, 0
    VMReturn
    .balign 4, 0

Movement_03EC:
    Move 34, 1
    MoveEnd

L_03F4:
    FadeEx 3, 0, 16, 2
    FadeExWait
    Plugin1_Cmd1003 35, 0, 3, 0
    ActorSetGPos 255, 18, 0, 14, 3
    ActorSetGPos 2, 19, 0, 14, 2
    Plugin1_Cmd1003 36, 2, 0, 0
    FadeEx 3, 16, 0, 2
    VMReturn

L_0438:
    SystemMsg 118, 2
    Plugin1_Cmd1003 319, 0, 0, 0
    Plugin1_Cmd1003 402, 100, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0475
    MsgWinCloseAll
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_0475:
    WorkSetConst 0x4000, 0
    Plugin1_Cmd1003 405, 2, 0x4000, 0
    Plugin1_Cmd1003 415, 0, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04B2
    MsgWinCloseAll
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_04B2:
    Plugin1_Cmd1003 406, 2, 0, 16384
    MsgWinCloseAll
    Plugin1_Cmd1003 415, 0, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04E9
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_04E9:
    VMStackPush 0x4000
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0508
    VMCall L_0510
    VMJump L_050E

L_0508:
    VMCall L_052E

L_050E:
    VMReturn

L_0510:
    ParentActorMsg 1024, 20, 0, 0
    VMSleep 30
    MsgWinCloseAll
    VMCall L_1718
    VMCall L_0A7C
    VMReturn

L_052E:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    Plugin1_Cmd1003 319, 0, 0, 0
    Plugin1_Cmd1003 402, 105, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_056F
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_056F:
    RTCallGlobal 10345
    WorkGet 0x8025, 0x8010
    VMSleep 30
    SystemMsg 19, 2
    Plugin1_Cmd1003 402, 106, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_05B0
    InfoMsgClose
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_05B0:
    Plugin1_Cmd1003 405, 5, 0x8025, 0
    Plugin1_Cmd1003 415, 0, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05E7
    InfoMsgClose
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_05E7:
    Plugin1_Cmd1003 406, 5, 0, 32806
    Plugin1_Cmd1003 415, 0, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_061E
    MsgWinCloseAll
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_061E:
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_06A5
    InfoMsgClose
    Plugin1_Cmd1003 402, 107, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_066E
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_066E:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0693
    ActorMsg 1024, 30, 0x8011, 2, 0
    VMJump L_069F

L_0693:
    ActorMsg 1024, 31, 0x8011, 2, 0

L_069F:
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_06A5:
    Plugin1_Cmd1003 402, 108, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06D2
    InfoMsgClose
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_06D2:
    InfoMsgClose
    WorkGet 0x8008, 0x8011
    RTCallGlobal 10346
    WorkGet 0x8025, 0x8010
    SystemMsg 19, 2
    Plugin1_Cmd1003 402, 109, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0717
    InfoMsgClose
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_0717:
    Plugin1_Cmd1003 405, 6, 0x8025, 0
    Plugin1_Cmd1003 415, 0, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_074E
    MsgWinCloseAll
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_074E:
    Plugin1_Cmd1003 406, 6, 0, 32806
    Plugin1_Cmd1003 415, 0, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0785
    MsgWinCloseAll
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_0785:
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_080C
    InfoMsgClose
    Plugin1_Cmd1003 402, 110, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07D5
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_07D5:
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_07FA
    ActorMsg 1024, 30, 0x8011, 2, 0
    VMJump L_0806

L_07FA:
    ActorMsg 1024, 31, 0x8011, 2, 0

L_0806:
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_080C:
    Plugin1_Cmd1003 319, 0, 0, 0
    Plugin1_Cmd1003 402, 111, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0843
    InfoMsgClose
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_0843:
    Plugin1_Cmd1003 405, 0, 0, 0
    Plugin1_Cmd1003 415, 0, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_087A
    MsgWinCloseAll
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_087A:
    Plugin1_Cmd1003 406, 0, 0, 32806
    Plugin1_Cmd1003 415, 0, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_08B1
    MsgWinCloseAll
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_08B1:
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_091F
    InfoMsgClose
    WorkGet 0x8008, 0x8011
    WorkGet 0x8009, 0x8026
    RTCallGlobal 10348
    SystemMsgAsync 19, 2
    Plugin1_Cmd1003 402, 112, 0, 32802
    VMSleep 15
    MsgWinCloseAll
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_090D
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_090D:
    ActorMsg 1024, 30, 0x8011, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_091F:
    Plugin1_Cmd1003 402, 113, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_094C
    InfoMsgClose
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_094C:
    SystemMsg 2, 2
    WorkSetConst 0x4176, 4
    WorkSetConst 0x4178, 1
    Plugin1_Cmd1003 21, 0, 0, 32803
    Plugin1_Cmd1003 322, 0, 0, 0
    Plugin1_Cmd1003 319, 0, 0, 0
    Plugin1_Cmd1003 402, 102, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09A9
    MsgWinCloseAll
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_09A9:
    Plugin1_Cmd1003 407, 0, 0, 32801
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09E0
    Plugin1_Cmd1003 316, 0, 0, 0
    Plugin1_Cmd1003 405, 1, 0, 32801
    VMJump L_09EA

L_09E0:
    Plugin1_Cmd1003 406, 1, 0, 16384

L_09EA:
    Plugin1_Cmd1003 415, 0, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A17
    MsgWinCloseAll
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_0A17:
    SaveDataWrite 0x8010
    MsgWinCloseAll
    Plugin1_Cmd1003 402, 103, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A48
    VMCall L_16F4
    VMCall L_0A7C
    VMReturn

L_0A48:
    RecordAdd 48, 1
    VMCall L_157C
    FlagSet 604
    FlagSet 605
    WorkSetConst 0x4179, 0
    MapChangeCore 75, 7, 0, 4, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    VMReturn

L_0A7C:
    WorkSetConst 0x4176, 2
    VMCall L_157C
    FlagSet 604
    FlagSet 605
    WorkSetConst 0x4179, 0
    VMCall L_1776
    VMReturn

L_0A9E:
    WorkSetConst 0x8027, 0
    ParentActorMsg 1024, 13, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0AC9
    MsgWinCloseAll
    VMReturn

L_0AC9:
    ParentActorMsg 1024, 14, 0, 0
    MsgWinCloseAll
    Plugin1_Cmd1003 331, 0, 0, 32807
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0AF8
    VMCall L_0B20

L_0AF8:
    WorkSetConst 0x4176, 2
    VMCall L_157C
    FlagSet 604
    FlagSet 605
    WorkSetConst 0x4179, 0
    VMCall L_1776
    WorkSetConst 0x8027, 0
    VMReturn

L_0B20:
    SystemMsg 19, 2
    Plugin1_Cmd1003 319, 0, 0, 0
    Plugin1_Cmd1003 402, 100, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B5B
    MsgWinCloseAll
    VMCall L_16F4
    VMJump L_0B7D

L_0B5B:
    WorkSetConst 0x4000, 1
    Plugin1_Cmd1003 405, 2, 0x4000, 0
    Plugin1_Cmd1003 406, 2, 0, 16384
    VMCall L_1718
    MsgWinCloseAll

L_0B7D:
    VMReturn

Script_4:
    ActorsPauseAll
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    Plugin1_Cmd1003 21, 0, 0, 32803
    Plugin1_Cmd1003 6, 0x8023, 0, 32809
    TrainerCardGetSex 0x8028
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0BFC
    WorkSetConst 0x8020, 23
    VMStackPush 0x8029
    VMStackPushConst 49
    VMStackCmp 4
    VMJumpIf 255, L_0BDD
    WorkSetConst 0x8020, 27
    VMJump L_0BF6

L_0BDD:
    VMStackPush 0x8029
    VMStackPushConst 21
    VMStackCmp 4
    VMJumpIf 255, L_0BF6
    WorkSetConst 0x8020, 25

L_0BF6:
    VMJump L_0C3A

L_0BFC:
    WorkSetConst 0x8020, 24
    VMStackPush 0x8029
    VMStackPushConst 49
    VMStackCmp 4
    VMJumpIf 255, L_0C21
    WorkSetConst 0x8020, 28
    VMJump L_0C3A

L_0C21:
    VMStackPush 0x8029
    VMStackPushConst 21
    VMStackCmp 4
    VMJumpIf 255, L_0C3A
    WorkSetConst 0x8020, 26

L_0C3A:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8020, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    Plugin1_Cmd1003 21, 0, 0, 32803
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0C95
    SEPlay 1351
    ActorSetEyeToEye
    Plugin1_Cmd1003 37, 0x8011, 0, 0
    VMJump L_0CDC

L_0C95:
    Plugin1_Cmd1003 39, 0x8011, 0, 32784
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0CBE
    VMCall L_0CE2
    VMJump L_0CDC

L_0CBE:
    Plugin1_Cmd1003 26, 0x8011, 0, 32800
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8020, 0, 0
    LastKeyWait
    ActorMsgClose

L_0CDC:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0CE2:
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    WorkGet 0x802d, 0x8011
    Plugin1_Cmd1003 40, 0x802d, 0, 32810
    Plugin1_Cmd1003 41, 0x802d, 0, 32811
    Plugin1_Cmd1003 42, 0x802d, 0, 32812
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 0x802c
    WorkSet 0x8001, 1
    WorkSet 0x8002, 1
    WorkSet 0x8003, 0x802a
    WorkSet 0x8004, 0x802b
    WorkSet 0x8005, 0x802b
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802a, 0
    VMReturn

Script_6:
    ActorsPauseAll
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8030, 0
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8031, 0
    WorkSetConst 0x802e, 1
    Plugin1_Cmd1003 310, 0, 0, 32803
    Plugin1_Cmd1003 312, 0, 0, 32815
    WorkSetConst 0x4179, 2
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_0DEF
    VMJump L_0E0E

L_0DEF:
    VMStackPush 0x802f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E08
    WorkSetConst 0x4179, 3

L_0E08:
    VMJump L_0ECD

L_0E0E:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_0E21
    VMJump L_0E40

L_0E21:
    VMStackPush 0x802f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E3A
    WorkSetConst 0x4179, 3

L_0E3A:
    VMJump L_0ECD

L_0E40:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_0E53
    VMJump L_0E72

L_0E53:
    VMStackPush 0x802f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E6C
    WorkSetConst 0x4179, 3

L_0E6C:
    VMJump L_0ECD

L_0E72:
    WorkCmpConst 0x8023, 3
    VMJumpIf 1, L_0E85
    VMJump L_0EAE

L_0E85:
    Plugin1_Cmd1003 358, 0, 0, 32784
    VMStackPush 0x8010
    VMStackPushConst 21
    VMStackCmp 4
    VMJumpIf 255, L_0EA8
    WorkSetConst 0x4179, 3

L_0EA8:
    VMJump L_0ECD

L_0EAE:
    WorkCmpConst 0x8023, 4
    VMJumpIf 1, L_0EC1
    VMJump L_0ECD

L_0EC1:
    WorkSetConst 0x4179, 3
    VMJump L_0ECD

L_0ECD:
    VMCall L_13CB
    Plugin1_Cmd1003 5, 0, 0, 0
    VMStackPush 0x802f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1113
    Plugin1_Cmd1003 326, 0, 0, 32784
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0FFE
    ActorMsg 1024, 4, 0x802e, 2, 0
    MsgWinCloseAll
    Plugin1_Cmd1003 313, 0, 0, 32816
    WordSetPlayerName 0
    WordSetNumber 1, 0x8030, 2
    SystemMsg 0, 2
    MEPlay 1318
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    Plugin1_Cmd1003 14, 0x8023, 0, 32784
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0FF8
    ActorMsg 1024, 8, 0x802e, 2, 0
    MEPlay 1316
    MEWait
    MsgWaitAdvance
    MsgWinCloseAll
    Plugin1_Cmd1003 15, 0x8023, 0, 0
    Cmd_01DD 8, 0, 0
    WorkCmpConst 0x8023, 5
    VMJumpIf 1, L_0F97
    VMJump L_0FA1

L_0F97:
    FlagReset 733
    VMJump L_0FF8

L_0FA1:
    WorkCmpConst 0x8023, 6
    VMJumpIf 1, L_0FB4
    VMJump L_0FBE

L_0FB4:
    FlagReset 734
    VMJump L_0FF8

L_0FBE:
    WorkCmpConst 0x8023, 7
    VMJumpIf 1, L_0FD1
    VMJump L_0FDB

L_0FD1:
    FlagReset 735
    VMJump L_0FF8

L_0FDB:
    WorkCmpConst 0x8023, 8
    VMJumpIf 1, L_0FEE
    VMJump L_0FF8

L_0FEE:
    FlagReset 735
    VMJump L_0FF8

L_0FF8:
    VMJump L_110D

L_0FFE:
    ActorMsg 1024, 4, 0x802e, 2, 0
    MsgWinCloseAll
    Plugin1_Cmd1003 313, 0, 0, 32816
    WordSetPlayerName 0
    WordSetNumber 1, 0x8030, 2
    SystemMsg 0, 2
    MEPlay 1318
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    Plugin1_Cmd1003 358, 0, 0, 32784
    VMStackPush 0x8010
    VMStackPushConst 21
    VMStackCmp 4
    VMJumpIf 255, L_110D
    Plugin1_Cmd1003 14, 0x8023, 0, 32784
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_110D
    WordSetPlayerName 0
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_1080
    VMJump L_1092

L_1080:
    ActorMsg 1024, 5, 0x802e, 2, 0
    VMJump L_1101

L_1092:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_10A5
    VMJump L_10B7

L_10A5:
    ActorMsg 1024, 6, 0x802e, 2, 0
    VMJump L_1101

L_10B7:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_10CA
    VMJump L_10DC

L_10CA:
    ActorMsg 1024, 7, 0x802e, 2, 0
    VMJump L_1101

L_10DC:
    WorkCmpConst 0x8023, 3
    VMJumpIf 1, L_10EF
    VMJump L_1101

L_10EF:
    ActorMsg 1024, 7, 0x802e, 2, 0
    VMJump L_1101

L_1101:
    MsgWinCloseAll
    Plugin1_Cmd1003 15, 0x8023, 0, 0

L_110D:
    VMJump L_11AA

L_1113:
    ActorMsg 1024, 3, 0x802e, 2, 0
    MsgWinCloseAll
    Plugin1_Cmd1003 313, 0, 0, 32816
    WordSetPlayerName 0
    WordSetNumber 1, 0x8030, 2
    SystemMsg 0, 2
    MEPlay 1318
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    VMStackPush 0x8023
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_11AA
    Plugin1_Cmd1003 358, 0, 0, 32784
    VMStackPush 0x8010
    VMStackPushConst 21
    VMStackCmp 4
    VMJumpIf 255, L_11AA
    Plugin1_Cmd1003 14, 0x8023, 0, 32784
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_11AA
    ActorMsg 1024, 7, 0x802e, 2, 0
    MsgWinCloseAll
    Plugin1_Cmd1003 15, 0x8023, 0, 0

L_11AA:
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_1252
    Plugin1_Cmd1003 109, 0, 0, 32801
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1252
    Plugin1_Cmd1003 28, 0, 0, 32801
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1217
    Plugin1_Cmd1003 27, 0, 0, 32801
    WordSetPlayerName 0
    WordSetNumber 1, 0x8021, 2
    ActorMsg 1024, 21, 0x802e, 2, 0

L_1217:
    ActorMsg 1024, 22, 0x802e, 2, 0
    YesNoWin 0x8010
    MsgWinCloseAll
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1248
    WorkSetConst 0x8031, 1
    VMJump L_1252

L_1248:
    Plugin1_Cmd1003 100, 1, 0, 0

L_1252:
    VMStackPush 0x4179
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_126F
    Plugin1_Cmd1003 349, 0, 0, 0

L_126F:
    VMStackPush 0x4165
    VMStackPushConst 10
    VMStackCmp 0
    VMJumpIf 255, L_1288
    WorkAdd 0x4165, 1

L_1288:
    Plugin1_Cmd1003 321, 0, 0, 0
    VMStackPush 0x8031
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_12B5
    SystemMsg 2, 2
    SaveDataWrite 0x8010
    MsgWinCloseAll
    RTCallGlobal 10344

L_12B5:
    SystemMsg 1, 2
    SaveDataWrite 0x8010
    InfoMsgClose
    VMStackPush 0x4179
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_12E6
    ActorMsg 1024, 9, 0x802e, 2, 0
    VMJump L_139F

L_12E6:
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_12F9
    VMJump L_130B

L_12F9:
    ActorMsg 1024, 10, 0x802e, 2, 0
    VMJump L_139F

L_130B:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_131E
    VMJump L_1330

L_131E:
    ActorMsg 1024, 11, 0x802e, 2, 0
    VMJump L_139F

L_1330:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_1343
    VMJump L_1355

L_1343:
    ActorMsg 1024, 12, 0x802e, 2, 0
    VMJump L_139F

L_1355:
    WorkCmpConst 0x8023, 3
    VMJumpIf 1, L_1368
    VMJump L_137A

L_1368:
    ActorMsg 1024, 12, 0x802e, 2, 0
    VMJump L_139F

L_137A:
    WorkCmpConst 0x8023, 4
    VMJumpIf 1, L_138D
    VMJump L_139F

L_138D:
    ActorMsg 1024, 29, 0x802e, 2, 0
    VMJump L_139F

L_139F:
    LastKeyWait
    MsgWinCloseAll
    Plugin1_Cmd1003 333, 0, 0, 0
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8030, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x802e, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_13CB:
    WorkSetConst 0x8032, 0
    Plugin1_Cmd1003 310, 0, 0, 32803
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 7
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_140A
    WorkSetConst 0x8032, 1
    VMJump L_1410

L_140A:
    WorkSetConst 0x8032, 0

L_1410:
    Plugin1_Cmd1003 13, 255, 1, 0
    Plugin1_Cmd1003 23, 255, 0, 0
    VMStackPush 0x8032
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_147D
    Plugin1_Cmd1003 31, 0, 0, 16416
    FlagReset 604
    ActorAdd 2
    Plugin1_Cmd1003 23, 2, 0, 0
    Plugin1_Cmd1003 13, 2, 1, 0
    Plugin1_Cmd1003 36, 2, 0, 0
    Plugin1_Cmd1003 35, 2, 1, 0
    ActorSetGPos 2, 75, 0, 12, 1

L_147D:
    Plugin1_Cmd1003 19, 2, 0, 0
    FadeInBlackQ
    FadeWait
    VMSleep 10
    SEPlay 1972
    VMSleep 60
    SEPlay 1970
    ActorCmdExec 255, Movement_1548
    VMStackPush 0x8032
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_14BE
    ActorCmdExec 2, Movement_155C

L_14BE:
    ActorCmdWait
    Plugin1_Cmd1003 24, 255, 0, 0
    VMStackPush 0x8032
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_14E7
    Plugin1_Cmd1003 24, 2, 0, 0

L_14E7:
    VMStackPush 0x4179
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_153E
    VMSleep 30
    Plugin1_Cmd1003 19, 0, 0, 0
    SEPlay 1970
    VMSleep 20
    SEPlay 1973
    VMSleep 30
    FadeEx 3, 0, 16, 2
    FadeExWait
    Plugin1_Cmd1003 20, 1, 0, 0
    VMSleep 30
    FadeEx 3, 16, 0, 2
    FadeExWait

L_153E:
    WorkSetConst 0x8032, 0
    VMReturn
    .balign 4, 0

Movement_1548:
    Move 70, 1
    Move 60, 4
    Move 13, 2
    Move 35, 1
    MoveEnd

Movement_155C:
    Move 60, 14
    Move 70, 1
    Move 60, 4
    Move 13, 1
    Move 14, 1
    Move 13, 1
    Move 35, 1
    MoveEnd

L_157C:
    WorkSetConst 0x8033, 0
    FadeEx 3, 0, 16, 2
    FadeExWait
    Plugin1_Cmd1003 35, 0, 3, 0
    Plugin1_Cmd1003 310, 0, 0, 32803
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 7
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_15D1
    WorkSetConst 0x8033, 1
    VMJump L_15D7

L_15D1:
    WorkSetConst 0x8033, 0

L_15D7:
    ActorSetGPos 255, 18, 0, 14, 2
    Plugin1_Cmd1003 23, 255, 0, 0
    VMStackPush 0x8033
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1620
    ActorSetGPos 2, 19, 0, 14, 2
    Plugin1_Cmd1003 23, 2, 0, 0
    Plugin1_Cmd1003 36, 2, 0, 0

L_1620:
    FadeEx 3, 16, 0, 2
    VMStackPush 0x4179
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_1661
    Plugin1_Cmd1003 19, 2, 1, 0
    Plugin1_Cmd1003 20, 0, 0, 0
    SEPlay 1972
    VMSleep 70
    SEPlay 1970
    VMSleep 20

L_1661:
    FadeExWait
    ActorCmdExec 255, Movement_16B0
    VMStackPush 0x8033
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1686
    ActorCmdExec 2, Movement_16C4

L_1686:
    ActorCmdWait
    Plugin1_Cmd1003 19, 3, 1, 0
    SEPlay 1970
    VMSleep 30
    SEPlay 1971
    VMSleep 30
    FadeOutBlackQ
    FadeWait
    WorkSetConst 0x8033, 0
    VMReturn
    .balign 4, 0

Movement_16B0:
    Move 32, 1
    Move 12, 2
    Move 60, 8
    Move 69, 1
    MoveEnd

Movement_16C4:
    Move 60, 16
    Move 14, 1
    Move 12, 2
    Move 60, 8
    Move 69, 1
    MoveEnd

L_16DC:
    Plugin1_Cmd1003 401, 0, 0, 0
    Cmd_013C
    Plugin1_Cmd1003 330, 0, 0, 0
    VMReturn

L_16F4:
    Plugin1_Cmd1003 413, 0, 0, 0
    VMCall L_16DC
    VMReturn
    Plugin1_Cmd1003 414, 0, 0, 0
    VMCall L_16DC
    VMReturn

L_1718:
    Plugin1_Cmd1003 402, 104, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_173F
    Plugin1_Cmd1003 413, 0, 0, 0

L_173F:
    VMCall L_16DC
    VMReturn
    Plugin1_Cmd1003 402, 104, 0, 32802
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_176E
    Plugin1_Cmd1003 414, 0, 0, 0

L_176E:
    VMCall L_16DC
    VMReturn

L_1776:
    Plugin1_Cmd1003 202, 99, 0, 0
    Plugin1_Cmd1003 21, 0, 0, 32803
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_179D
    VMJump L_17AF

L_179D:
    MapChangeCore 67, 11, 0, 15, 3
    VMJump L_18E3

L_17AF:
    WorkCmpConst 0x8023, 5
    VMJumpIf 1, L_17C2
    VMJump L_17D4

L_17C2:
    MapChangeCore 68, 11, 0, 15, 3
    VMJump L_18E3

L_17D4:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_17E7
    VMJump L_17F9

L_17E7:
    MapChangeCore 69, 11, 0, 15, 3
    VMJump L_18E3

L_17F9:
    WorkCmpConst 0x8023, 6
    VMJumpIf 1, L_180C
    VMJump L_181E

L_180C:
    MapChangeCore 70, 11, 0, 15, 3
    VMJump L_18E3

L_181E:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_1831
    VMJump L_1843

L_1831:
    MapChangeCore 71, 11, 0, 15, 3
    VMJump L_18E3

L_1843:
    WorkCmpConst 0x8023, 3
    VMJumpIf 1, L_1856
    VMJump L_1868

L_1856:
    MapChangeCore 71, 11, 0, 15, 3
    VMJump L_18E3

L_1868:
    WorkCmpConst 0x8023, 7
    VMJumpIf 1, L_187B
    VMJump L_188D

L_187B:
    MapChangeCore 72, 11, 0, 15, 3
    VMJump L_18E3

L_188D:
    WorkCmpConst 0x8023, 8
    VMJumpIf 1, L_18A0
    VMJump L_18B2

L_18A0:
    MapChangeCore 72, 11, 0, 15, 3
    VMJump L_18E3

L_18B2:
    WorkCmpConst 0x8023, 4
    VMJumpIf 1, L_18C5
    VMJump L_18D7

L_18C5:
    MapChangeCore 73, 11, 0, 15, 3
    VMJump L_18E3

L_18D7:
    MapChangeCore 67, 11, 0, 15, 3

L_18E3:
    Plugin1_Cmd1003 202, 100, 0, 0
    VMReturn

Script_7:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 117, 2
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallPokedexDiploma 2, 0
    FieldOpen
    FadeInBlackQ
    FadeWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
