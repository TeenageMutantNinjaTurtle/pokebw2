#include "asm/field_script.inc"

// Script plugin 10, from the zones that start its scripts

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntry Script_9
    ScriptEntriesEnd

Script_1:
    FlagSet 914
    FlagReset 915
    VMStackPushFlag 2440
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_004F
    FlagReset 963
    FlagReset 964
    VMJump L_0057

L_004F:
    FlagSet 963
    FlagSet 964

L_0057:
    VMHalt

Script_2:
    VMStackPushFlag 2440
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00B5
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    PlayerGetGPos 0x8020, 0x8021
    VMStackPush 0x8021
    VMStackPushConst 21
    VMStackCmp 4
    VMJumpIf 255, L_009D
    ActorSetGPos 1, 14, 0, 20, 0

L_009D:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    WorkSetConst 0x4000, 1
    VMJump L_00BB

L_00B5:
    WorkSetConst 0x4000, 0

L_00BB:
    VMStackPushFlag 458
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00DA
    ActorSetGPos 4, 2, 3, 7, 3

L_00DA:
    VMHalt
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0

Script_3:
    ActorsPauseAll
    Plugin10_Cmd1011
    WorkSetConst 0x8022, 1
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2440
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2547
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_015E
    WordSetPlayerName 0
    ActorMsg 1024, 22, 0x8011, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0164

L_015E:
    VMCall L_016C

L_0164:
    Plugin10_Cmd1012
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_016C:
    ActorMsg 1024, 0, 0x8011, 2, 0
    VMStackPushFlag 2440
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01BF
    Plugin10_Cmd1016 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B9
    WordSetPlayerName 0
    ActorMsg 1024, 13, 0x8011, 2, 0
    SEPlay 1924
    SEWait
    MsgWaitAdvance

L_01B9:
    VMCall L_09F1

L_01BF:
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0348
    WorkCmpConst 0x8022, 1
    VMJumpIf 1, L_01E5
    VMJump L_01F1

L_01E5:
    VMCall L_04A9
    VMJump L_0342

L_01F1:
    WorkCmpConst 0x8022, 2
    VMJumpIf 1, L_0204
    VMJump L_0235

L_0204:
    VMStackPushFlag 2440
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0229
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8022, 3
    VMJump L_022F

L_0229:
    VMCall L_0526

L_022F:
    VMJump L_0342

L_0235:
    WorkCmpConst 0x8022, 3
    VMJumpIf 1, L_0248
    VMJump L_0254

L_0248:
    VMCall L_0565
    VMJump L_0342

L_0254:
    WorkCmpConst 0x8022, 4
    VMJumpIf 1, L_0267
    VMJump L_0273

L_0267:
    VMCall L_0620
    VMJump L_0342

L_0273:
    WorkCmpConst 0x8022, 5
    VMJumpIf 1, L_0286
    VMJump L_02AA

L_0286:
    Cmd_02C5 3
    Cmd_01DD 14, 0x8024, 0
    VMCall L_0655
    VMCall L_034A
    VMCall L_0714
    VMJump L_0342

L_02AA:
    WorkCmpConst 0x8022, 6
    VMJumpIf 1, L_02BD
    VMJump L_02C9

L_02BD:
    VMCall L_043A
    VMJump L_0342

L_02C9:
    WorkCmpConst 0x8022, 7
    VMJumpIf 1, L_02DC
    VMJump L_030D

L_02DC:
    VMStackPushFlag 2440
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0301
    WorkSetConst 0x4001, 1
    WorkSetConst 0x8022, 0
    VMJump L_0307

L_0301:
    VMCall L_0969

L_0307:
    VMJump L_0342

L_030D:
    WorkCmpConst 0x8022, 8
    VMJumpIf 1, L_0320
    VMJump L_033C

L_0320:
    ActorMsg 1024, 10, 0x8011, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8022, 0
    VMJump L_0342

L_033C:
    WorkSetConst 0x8022, 0

L_0342:
    VMJump L_01BF

L_0348:
    VMReturn

L_034A:
    ActorCmdExec 255, Movement_0410
    ActorCmdWait
    WorkSetConst 0x8025, 1

L_035A:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03F7
    WorkSetConst 0x8010, 30
    VMCall L_0420
    MsgWinCloseAll
    Plugin10_Cmd1000 0x8026, 0x8024, 0x8010
    DebugPrint 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03D7
    WorkSetConst 0x8010, 41
    VMCall L_0420
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_03C3
    VMJump L_03D1

L_03C3:
    MsgWinCloseAll
    WorkSetConst 0x8022, 8
    WorkSetConst 0x8025, 0

L_03D1:
    VMJump L_03F1

L_03D7:
    WorkSetConst 0x8010, 36
    VMCall L_0420
    MsgWinCloseAll
    WorkSetConst 0x8022, 6
    WorkSetConst 0x8025, 0

L_03F1:
    VMJump L_035A

L_03F7:
    ActorCmdExec 255, Movement_0418
    ActorCmdWait
    MapChangeWarp 568, 14, 11, 1
    VMReturn
    .balign 4, 0

Movement_0410:
    Move 12, 6
    MoveEnd

Movement_0418:
    Move 13, 6
    MoveEnd

L_0420:
    Plugin10_Cmd1020 0x8024, 0x8027
    WorkAdd 0x8010, 0x8027
    ActorMsg 1024, 0x8010, 1, 2, 0
    VMReturn

L_043A:
    WorkSetConst 0x8011, 0
    VMStackPushFlag 2440
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0463
    WorkSetConst 0x4001, 1
    FlagSet 701
    WorkSetConst 0x40ab, 4

L_0463:
    VMCall L_0744
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0488
    WorkSetConst 0x8022, 7
    VMJump L_04A7

L_0488:
    WorkSetConst 0x8022, 8
    VMStackPushFlag 2440
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04A7
    WorkSetConst 0x4001, 0

L_04A7:
    VMReturn

L_04A9:
    ActorMsg 1024, 2, 0x8011, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32803
    ListMenuAdd 25, 65535, 0
    ListMenuAdd 26, 65535, 1
    ListMenuAdd 27, 65535, 2
    ListMenuShow
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_04EB
    VMJump L_04F7

L_04EB:
    WorkSetConst 0x8022, 2
    VMJump L_0524

L_04F7:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_050A
    VMJump L_051E

L_050A:
    ActorMsg 1024, 3, 0x8011, 2, 0
    MsgWinCloseAll
    VMJump L_0524

L_051E:
    WorkSetConst 0x8022, 8

L_0524:
    VMReturn

L_0526:
    ActorMsg 1024, 6, 0x8011, 2, 0
    MsgWinCloseAll
    WorkSetConst 0x8024, 41
    Plugin10_Cmd1002 0x8024
    DebugPrint 0x8024
    VMStackPush 0x8024
    VMStackPushConst 41
    VMStackCmp 4
    VMJumpIf 255, L_055D
    WorkSetConst 0x8022, 8
    VMReturn

L_055D:
    WorkSetConst 0x8022, 3
    VMReturn

L_0565:
    ActorMsg 1024, 7, 0x8011, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32803
    ListMenuAdd 29, 65535, 0
    ListMenuAdd 28, 65535, 1
    ListMenuAdd 27, 65535, 2
    ListMenuShow
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_05A7
    VMJump L_05C5

L_05A7:
    ActorMsg 1024, 9, 0x8011, 2, 0
    MsgWinCloseAll
    WorkSetConst 0x8022, 5
    Plugin10_Cmd1014 0
    VMJump L_061E

L_05C5:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_05D8
    VMJump L_0618

L_05D8:
    Plugin10_Cmd1006 2, 0x8024, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0603
    WorkSetConst 0x8022, 4
    Plugin10_Cmd1014 1
    VMJump L_0612

L_0603:
    WordSetPlayerName 0
    ActorMsg 1024, 14, 0x8011, 2, 0

L_0612:
    VMJump L_061E

L_0618:
    WorkSetConst 0x8022, 8

L_061E:
    VMReturn

L_0620:
    ActorMsg 1024, 8, 0x8011, 2, 0
    MsgWinCloseAll
    Plugin10_Cmd1013 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_064D
    WorkSetConst 0x8022, 8
    VMReturn

L_064D:
    WorkSetConst 0x8022, 5
    VMReturn

L_0655:
    FunfestBGMReturn
    ActorMsg 1024, 11, 0x8011, 2, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8029, 0x802a
    WorkCmpConst 0x8029, 12
    VMJumpIf 1, L_067E
    VMJump L_068C

L_067E:
    ActorCmdExec 255, Movement_06F0
    VMJump L_06CE

L_068C:
    WorkCmpConst 0x8029, 13
    VMJumpIf 1, L_069F
    VMJump L_06AD

L_069F:
    ActorCmdExec 255, Movement_0700
    VMJump L_06CE

L_06AD:
    WorkCmpConst 0x8029, 14
    VMJumpIf 1, L_06C0
    VMJump L_06CE

L_06C0:
    ActorCmdExec 255, Movement_070C
    VMJump L_06CE

L_06CE:
    ActorCmdWait
    Plugin10_Cmd1019 0x8024, 0x4020, 0x4021
    FlagReset 914
    FlagSet 915
    FlagSet 963
    MapChangeWarp 567, 15, 16, 0
    VMReturn

Movement_06F0:
    Move 13, 1
    Move 15, 2
    Move 12, 2
    MoveEnd

Movement_0700:
    Move 15, 1
    Move 12, 2
    MoveEnd

Movement_070C:
    Move 12, 1
    MoveEnd

L_0714:
    FlagSet 914
    FlagReset 915
    ActorCmdExec 0, Movement_0730
    ActorCmdExec 255, Movement_0738
    ActorCmdWait
    VMReturn

Movement_0730:
    Move 35, 1
    MoveEnd

Movement_0738:
    Move 13, 1
    Move 34, 1
    MoveEnd

L_0744:
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802b, 1
    WorkSetConst 0x802c, 0

L_075C:
    VMStackPush 0x802b
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0955
    WorkCmpConst 0x802b, 1
    VMJumpIf 1, L_0782
    VMJump L_07E8

L_0782:
    ActorMsg 1024, 12, 0x8011, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_07B1
    WorkSetConst 0x802b, 2
    VMJump L_07E2

L_07B1:
    Plugin10_Cmd1008 0x8028
    VMStackPush 0x8028
    VMStackPushConst 8
    VMStackCmp 1
    VMJumpIf 255, L_07D4
    WorkSetConst 0x802b, 3
    VMJump L_07E2

L_07D4:
    VMCall L_09AF
    MsgWinCloseAll
    WorkSetConst 0x802b, 4

L_07E2:
    VMJump L_094F

L_07E8:
    WorkCmpConst 0x802b, 2
    VMJumpIf 1, L_07FB
    VMJump L_083C

L_07FB:
    ActorMsg 1024, 16, 0x8011, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0830
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    VMJump L_0836

L_0830:
    WorkSetConst 0x802b, 1

L_0836:
    VMJump L_094F

L_083C:
    WorkCmpConst 0x802b, 3
    VMJumpIf 1, L_084F
    VMJump L_08BD

L_084F:
    ActorMsg 1024, 4, 0x8011, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08B1
    ActorMsg 1024, 5, 0x8011, 2, 0
    MsgWinCloseAll
    Plugin10_Cmd1003 1, 0x8026
    VMStackPush 0x8026
    VMStackPushConst 8
    VMStackCmp 1
    VMJumpIf 255, L_08A5
    WorkSetConst 0x802b, 2
    VMJump L_08AB

L_08A5:
    WorkSetConst 0x802b, 4

L_08AB:
    VMJump L_08B7

L_08B1:
    WorkSetConst 0x802b, 2

L_08B7:
    VMJump L_094F

L_08BD:
    WorkCmpConst 0x802b, 4
    VMJumpIf 1, L_08D0
    VMJump L_0943

L_08D0:
    DebugPrint 0x8026
    Plugin10_Cmd1004 0x8026
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    RTCallGlobal 2003
    WorkSet 0x8010, 0x8000
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0937
    WorkSetConst 0x802c, 1
    WorkSetConst 0x802b, 0
    VMJump L_093D

L_0937:
    WorkSetConst 0x802b, 2

L_093D:
    VMJump L_094F

L_0943:
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802b, 0

L_094F:
    VMJump L_075C

L_0955:
    WorkGet 0x8010, 0x802c
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802b, 0
    VMReturn

L_0969:
    WordSetPlayerName 0
    ActorMsg 1024, 17, 0x8011, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09A7
    MsgWinCloseAll
    MapChangeWarp 574, 9, 11, 0
    WorkSetConst 0x8022, 0
    VMJump L_09AD

L_09A7:
    WorkSetConst 0x8022, 8

L_09AD:
    VMReturn

L_09AF:
    WorkSetConst 0x8026, 0

L_09B5:
    VMStackPush 0x8026
    VMStackPushConst 8
    VMStackCmp 0
    VMJumpIf 255, L_09EF
    Plugin10_Cmd1009 0x8026, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09E3
    VMReturn

L_09E3:
    WorkAdd 0x8026, 1
    VMJump L_09B5

L_09EF:
    VMReturn

L_09F1:
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8024, 0

L_0A15:
    VMStackPush 0x8024
    VMStackPushConst 41
    VMStackCmp 0
    VMJumpIf 255, L_0B8C
    Plugin10_Cmd1015 0x8024, 0x802d, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B80
    WordSetPlayerName 0
    Plugin10_Cmd1005 1, 0x8024
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_0A5E
    VMJump L_0A70

L_0A5E:
    ActorMsg 1024, 1, 0x8011, 2, 0
    VMJump L_0B80

L_0A70:
    WorkCmpConst 0x802d, 1
    VMJumpIf 1, L_0A83
    VMJump L_0AAE

L_0A83:
    VMStackPush 0x802e
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0AA8
    WorkSetConst 0x802e, 1
    ActorMsg 1024, 21, 0x8011, 2, 0

L_0AA8:
    VMJump L_0B80

L_0AAE:
    WorkCmpConst 0x802d, 2
    VMJumpIf 1, L_0AC1
    VMJump L_0AD3

L_0AC1:
    ActorMsg 1024, 19, 0x8011, 2, 0
    VMJump L_0B80

L_0AD3:
    WorkCmpConst 0x802d, 3
    VMJumpIf 1, L_0AE6
    VMJump L_0AF8

L_0AE6:
    ActorMsg 1024, 18, 0x8011, 2, 0
    VMJump L_0B80

L_0AF8:
    WorkCmpConst 0x802d, 4
    VMJumpIf 1, L_0B0B
    VMJump L_0B1D

L_0B0B:
    ActorMsg 1024, 20, 0x8011, 2, 0
    VMJump L_0B80

L_0B1D:
    WorkCmpConst 0x802d, 5
    VMJumpIf 1, L_0B30
    VMJump L_0B5B

L_0B30:
    VMStackPush 0x802f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B55
    WorkSetConst 0x802f, 1
    ActorMsg 1024, 23, 0x8011, 2, 0

L_0B55:
    VMJump L_0B80

L_0B5B:
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_0B6E
    VMJump L_0B80

L_0B6E:
    ActorMsg 1024, 24, 0x8011, 2, 0
    VMJump L_0B80

L_0B80:
    WorkAdd 0x8024, 1
    VMJump L_0A15

L_0B8C:
    WorkSetConst 0x802f, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802d, 0
    VMReturn

Script_5:
    ActorsPauseAll
    VMSleep 10
    WordSetPlayerName 0
    ActorMsg 1024, 46, 1, 2, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0E64
    ActorCmdWait
    ActorCmdExec 1, Movement_0CAC
    ActorCmdWait
    ActorCmdExec 255, Movement_0CB8
    ActorCmdWait
    ActorMsg 1024, 47, 2, 2, 0
    MsgWinCloseAll
    ActorMsg 1024, 48, 1, 2, 0
    MsgWinCloseAll
    ActorMsg 1024, 49, 2, 2, 0
    ActorCmdExec 2, Movement_0E5C
    ActorCmdWait
    ActorMsg 1024, 50, 2, 2, 0
    MsgWinCloseAll
    SEPlay 1369
    SEWait
    ActorNew 14, 11, 1, 251, 91, 0
    ActorCmdExec 251, Movement_0CC0
    ActorCmdWait
    ActorCmdExec 2, Movement_0E74
    ActorCmdWait
    ActorMsg 1024, 51, 251, 2, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0E64
    ActorCmdWait
    ActorMsg 1024, 52, 2, 2, 0
    MsgWinCloseAll
    ActorMsg 1024, 53, 251, 2, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0CD0
    ActorCmdWait
    ActorDelete 251
    SEPlay 1369
    SEWait
    ActorMsg 1024, 54, 2, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorMsg 1024, 56, 1, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0CAC:
    Move 14, 1
    Move 0, 1
    MoveEnd

Movement_0CB8:
    Move 12, 3
    MoveEnd

Movement_0CC0:
    Move 13, 1
    Move 15, 1
    Move 13, 4
    MoveEnd

Movement_0CD0:
    Move 12, 4
    Move 14, 1
    Move 12, 1
    MoveEnd

Script_4:
    ActorsPauseAll
    ActorCmdExec 1, Movement_0E7C
    ActorCmdWait
    ActorCmdExec 1, Movement_0E74
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 56, 1, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0D1C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0D1C:
    Move 12, 1
    MoveEnd

Script_6:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 55, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 56, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 61, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    ActorCmdExec 2, Movement_0E34
    ActorCmdExec 255, Movement_0E64
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 57, 2, 2, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0E3C
    ActorCmdWait
    ActorMsg 1024, 58, 1, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0E64
    ActorCmdWait
    ActorMsg 1024, 59, 2, 2, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0E5C
    ActorCmdWait
    ActorMsg 1024, 60, 2, 2, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0E44
    ActorCmdExec 1, Movement_0E4C
    ActorCmdWait
    FlagSet 963
    FlagSet 964
    ActorDelete 2
    ActorDelete 1
    FlagReset 2440
    FlagSet 2547
    MedalDiscover 216
    MedalDiscover 218
    MedalDiscover 219
    WorkSetConst 0x4000, 0
    WorkSetConst 0x4001, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0E34:
    Move 12, 3
    MoveEnd

Movement_0E3C:
    Move 12, 4
    MoveEnd

Movement_0E44:
    Move 13, 8
    MoveEnd

Movement_0E4C:
    Move 35, 1
    Move 63, 3
    Move 13, 4
    MoveEnd

Movement_0E5C:
    Move 32, 1
    MoveEnd

Movement_0E64:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_0E74:
    Move 35, 1
    MoveEnd

Movement_0E7C:
    Move 75, 1
    MoveEnd
