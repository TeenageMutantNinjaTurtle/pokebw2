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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8022, 0
    Cmd_0167 0, 0, 0, 0
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 0, 0x8011, 2, 0
    VMCall L_0851
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_010E
    VMCall L_0A74
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00BA
    VMCall L_0816
    VMJump L_0108

L_00BA:
    VMCall L_0AF1
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00DF
    VMCall L_0816
    VMJump L_0108

L_00DF:
    ActorMsg 1024, 1, 0x8011, 2, 0
    ActorMsgClose
    Cmd_02C5 5
    FunfestBGMReturn
    VMCall L_0B9C
    SEPlay 1369
    FadeOutBlackQ
    SEWait
    FadeWait
    Cmd_0163 0x8021, 0

L_0108:
    VMJump L_0114

L_010E:
    VMCall L_0816

L_0114:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    WorkSetConst 0x8022, 0
    Cmd_0167 0, 0, 0, 0
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0206
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x8022, 1
    Cmd_0167 0, 0, 0, 0
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 56, 0x8011, 2, 0
    VMCall L_0851
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01D0
    VMCall L_0A74
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01D0
    ActorMsg 1024, 57, 0x8011, 2, 0
    ActorMsgClose
    FunfestBGMReturn
    VMCall L_0BC8
    SEPlay 1369
    FadeOutBlackQ
    BGMPush 6
    FadeWait
    SEWait
    FieldClose
    Cmd_0164 0x8021
    FieldOpen
    VMCall L_0BDE
    FadeInWhiteQ
    BGMPop 0, 60
    FadeWait

L_01D0:
    VMCall L_0816
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    MsgSetAutoscrolls 0
    Cmd_0167 21, 0, 0, 0x8010
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    MsgSetAutoscrolls 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0206:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    ActorMsg 1024, 43, 0x8011, 2, 0
    VMCall L_0851
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0245
    VMCall L_0816
    VMReturn

L_0245:
    GameCommCheckDSiWiFi 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_026A
    ActorMsgClose
    RTCallGlobal 2005
    VMCall L_0816
    VMReturn

L_026A:
    VMCall L_0A74
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_028B
    VMCall L_0816
    VMReturn

L_028B:
    ActorMsg 1024, 46, 0x8011, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32805
    ListMenuAdd 47, 65535, 0
    ListMenuAdd 48, 65535, 1
    ListMenuAdd 40, 65535, 2
    ListMenuShow
    VMStackPush 0x8025
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 65534
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_02E5
    VMCall L_0816
    VMReturn

L_02E5:
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_030A
    ActorMsg 1024, 50, 0x8011, 2, 0
    VMJump L_0316

L_030A:
    ActorMsg 1024, 52, 0x8011, 2, 0

L_0316:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0335
    VMCall L_0816
    VMReturn

L_0335:
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    RTCallGlobal 2003
    WorkSet 0x8023, 0x8000
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_038C
    VMCall L_0816
    VMReturn

L_038C:
    VMStackPush 0x8000
    RTCallGlobal 2004
    WorkSet 0x8023, 0x8000
    VMStackPop 0x8000
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03BD
    WorkSetConst 0x8023, 0
    VMJump L_03E2

L_03BD:
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_03DC
    WorkSetConst 0x8023, 0
    VMJump L_03E2

L_03DC:
    WorkSetConst 0x8023, 1

L_03E2:
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03FD
    VMCall L_0816
    VMReturn

L_03FD:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 1

L_040F:
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0653
    ActorMsg 1024, 51, 0x8011, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32804
    ListMenuAdd 39, 65535, 1
    ListMenuAdd 38, 65535, 0
    ListMenuAdd 40, 65535, 2
    ListMenuShow
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 65534
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0482
    VMCall L_0816
    VMReturn
    VMJump L_064D

L_0482:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04A1
    VMCall L_0AF1
    VMJump L_04A7

L_04A1:
    WorkSetConst 0x8010, 1

L_04A7:
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_064D
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0556
    ActorMsgClose
    Cmd_0167 10, 1, 0, 0
    Cmd_0167 16, 1, 0, 0
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0502
    VMCall L_06BD
    VMJump L_0508

L_0502:
    VMCall L_0707

L_0508:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0550
    Cmd_0167 11, 1, 0, 0
    ActorMsg 1024, 50, 0x8011, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0550
    VMCall L_0816
    VMReturn

L_0550:
    VMJump L_060F

L_0556:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_060F
    ActorMsgClose
    Cmd_0167 10, 0, 0, 0
    Cmd_0167 16, 0, 0, 0
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_059E
    VMCall L_0751
    VMJump L_05A4

L_059E:
    VMCall L_07BA

L_05A4:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_05F2
    Cmd_0167 11, 0, 0, 0
    ActorMsg 1024, 52, 0x8011, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05EC
    VMCall L_0816
    VMReturn

L_05EC:
    VMJump L_060F

L_05F2:
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_060F
    Cmd_0167 11, 0, 0, 0

L_060F:
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0628
    WorkSetConst 0x8026, 0

L_0628:
    Cmd_0167 22, 0, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_064D
    VMCall L_0804
    VMReturn

L_064D:
    VMJump L_040F

L_0653:
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    Cmd_0167 21, 0, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0682
    VMJump L_06BB

L_0682:
    ActorMsg 1024, 53, 0x8011, 2, 0
    ActorMsgClose
    Cmd_0167 14, 10, 0, 0
    Cmd_02C5 5
    FunfestBGMReturn
    VMCall L_0BB2
    SEPlay 1369
    FadeOutBlackQ
    SEWait
    FadeWait
    Cmd_0163 0x8021, 1
    VMCall L_0804

L_06BB:
    VMReturn

L_06BD:
    Cmd_0167 18, 0, 0, 0x8010
    WorkCmpConst 0x8010, 5
    VMJumpIf 1, L_06DA
    VMJump L_06E6

L_06DA:
    WorkSetConst 0x8010, 1
    VMJump L_0705

L_06E6:
    WorkCmpConst 0x8010, 6
    VMJumpIf 1, L_06F9
    VMJump L_0705

L_06F9:
    WorkSetConst 0x8010, 0
    VMJump L_0705

L_0705:
    VMReturn

L_0707:
    Cmd_0167 18, 1, 0, 0x8010
    WorkCmpConst 0x8010, 5
    VMJumpIf 1, L_0724
    VMJump L_0730

L_0724:
    WorkSetConst 0x8010, 1
    VMJump L_074F

L_0730:
    WorkCmpConst 0x8010, 6
    VMJumpIf 1, L_0743
    VMJump L_074F

L_0743:
    WorkSetConst 0x8010, 0
    VMJump L_074F

L_074F:
    VMReturn

L_0751:
    Cmd_0167 12, 0, 0, 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_076E
    VMJump L_077A

L_076E:
    WorkSetConst 0x8010, 1
    VMJump L_07B8

L_077A:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_078D
    VMJump L_0799

L_078D:
    WorkSetConst 0x8010, 0
    VMJump L_07B8

L_0799:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_07AC
    VMJump L_07B8

L_07AC:
    WorkSetConst 0x8010, 2
    VMJump L_07B8

L_07B8:
    VMReturn

L_07BA:
    Cmd_0167 13, 0, 0, 0x8010
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_07D7
    VMJump L_07E3

L_07D7:
    WorkSetConst 0x8010, 1
    VMJump L_0802

L_07E3:
    WorkCmpConst 0x8010, 4
    VMJumpIf 1, L_07F6
    VMJump L_0802

L_07F6:
    WorkSetConst 0x8010, 0
    VMJump L_0802

L_0802:
    VMReturn

L_0804:
    Cmd_0167 11, 0, 0, 0
    VMCall L_0816
    VMReturn

L_0816:
    Cmd_0167 22, 0, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0843
    ActorMsg 1024, 2, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose

L_0843:
    Cmd_0167 1, 0, 0, 0
    Cmd_013C
    VMReturn

L_0851:
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 1

L_0863:
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A72
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32784
    ListMenuAdd 35, 65535, 0
    ListMenuAdd 36, 65535, 1
    ListMenuAdd 37, 65535, 2
    ListMenuShow
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08BE
    WorkSetConst 0x8010, 1
    WorkSetConst 0x8028, 0
    VMJump L_0A6C

L_08BE:
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 65534
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_08F3
    WorkSetConst 0x8010, 0
    WorkSetConst 0x8028, 0
    VMJump L_0A6C

L_08F3:
    WorkSetConst 0x8029, 1

L_08F9:
    VMStackPush 0x8029
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A6C
    ActorMsg 1024, 59, 0x8011, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32784
    ListMenuAdd 60, 65535, 0
    ListMenuAdd 62, 65535, 1
    ListMenuAdd 64, 65535, 2
    ListMenuAdd 66, 65535, 3
    ListMenuAdd 68, 65535, 4
    ListMenuAdd 40, 65535, 5
    ListMenuShow
    VMStackPush 0x8010
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 65534
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_09B3
    WorkSetConst 0x8029, 0
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_09A1
    ActorMsg 1024, 58, 0x8011, 2, 0
    VMJump L_09AD

L_09A1:
    ActorMsg 1024, 54, 0x8011, 2, 0

L_09AD:
    VMJump L_0A66

L_09B3:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09D8
    ActorMsg 1024, 61, 0x8011, 2, 0
    VMJump L_0A66

L_09D8:
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_09FD
    ActorMsg 1024, 63, 0x8011, 2, 0
    VMJump L_0A66

L_09FD:
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0A22
    ActorMsg 1024, 65, 0x8011, 2, 0
    VMJump L_0A66

L_0A22:
    VMStackPush 0x8010
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0A47
    ActorMsg 1024, 67, 0x8011, 2, 0
    VMJump L_0A66

L_0A47:
    VMStackPush 0x8010
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0A66
    ActorMsg 1024, 69, 0x8011, 2, 0

L_0A66:
    VMJump L_08F9

L_0A6C:
    VMJump L_0863

L_0A72:
    VMReturn

L_0A74:
    WorkSetConst 0x802a, 0
    Cmd_0165 11, 0, 0x802a
    VMStackPush 0x802a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0AA8
    ActorMsg 1024, 44, 0x8011, 2, 0
    WorkSetConst 0x8010, 0
    VMReturn

L_0AA8:
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    ActorMsg 1024, 4, 0x8011, 2, 0
    ActorMsgClose
    Cmd_016A 0x802b, 0x8021
    VMStackPush 0x802b
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0AE3
    WorkSetConst 0x8010, 0
    VMReturn

L_0AE3:
    WorkSetConst 0x802b, 0
    WorkSetConst 0x8010, 1
    VMReturn

L_0AF1:
    WorkSetConst 0x802c, 0
    Cmd_0165 14, 0, 0x802c
    ActorMsg 1024, 3, 0x8011, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32784
    ListMenuAdd 29, 65535, 0
    ListMenuAdd 30, 65535, 1
    ListMenuAdd 31, 65535, 2
    ListMenuAdd 32, 65535, 3
    VMStackPush 0x802c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B54
    WordSetMusicalInfo 0, 0, 0
    ListMenuAdd 33, 65535, 4

L_0B54:
    ListMenuAdd 34, 65535, 5
    ListMenuShow
    VMStackPush 0x8010
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 65534
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0B8D
    WorkSetConst 0x8010, 0
    VMJump L_0B9A

L_0B8D:
    Cmd_0165 5, 0x8010, 0
    WorkSetConst 0x8010, 1

L_0B9A:
    VMReturn

L_0B9C:
    ActorCmdExec 0, Movement_0BF8
    ActorCmdWait
    ActorCmdExec 255, Movement_0C28
    ActorCmdWait
    VMReturn

L_0BB2:
    ActorCmdExec 15, Movement_0C10
    ActorCmdWait
    ActorCmdExec 255, Movement_0C44
    ActorCmdWait
    VMReturn

L_0BC8:
    ActorCmdExec 16, Movement_0BF8
    ActorCmdWait
    ActorCmdExec 255, Movement_0C60
    ActorCmdWait
    VMReturn

L_0BDE:
    ActorSetGPos 16, 18, 0, 11, 1
    ActorSetGPos 255, 18, 0, 12, 0
    VMReturn

Movement_0BF8:
    Move 0, 1
    Move 12, 1
    Move 3, 1
    Move 15, 1
    Move 2, 1
    MoveEnd

Movement_0C10:
    Move 0, 1
    Move 12, 1
    Move 2, 1
    Move 14, 1
    Move 3, 1
    MoveEnd

Movement_0C28:
    Move 0, 1
    Move 12, 2
    Move 2, 1
    Move 14, 2
    Move 0, 1
    Move 12, 2
    MoveEnd

Movement_0C44:
    Move 0, 1
    Move 12, 2
    Move 3, 1
    Move 15, 2
    Move 0, 1
    Move 12, 2
    MoveEnd

Movement_0C60:
    Move 0, 1
    Move 12, 4
    MoveEnd

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32784
    ListMenuAdd 29, 65535, 0
    ListMenuAdd 30, 65535, 1
    ListMenuAdd 31, 65535, 2
    ListMenuAdd 32, 65535, 3
    ListMenuAdd 33, 65535, 4
    ListMenuAdd 34, 65535, 5
    ListMenuShow
    ActorMsgClose
    VMStackPush 0x8010
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 65534
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0CE4
    VMJump L_0CEB

L_0CE4:
    Cmd_0165 5, 0x8010, 0

L_0CEB:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0CF1:
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8030, 0
    SEPlay 1351
    ActorSetEyeToEye
    Cmd_0166 0x8020, 0, 0x802d
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0D3D
    ParentActorMsg 1024, 25, 0, 0
    ABKeyWait
    ActorMsgClose
    VMJump L_0DE2

L_0D3D:
    Cmd_0166 0x8020, 3, 0x802f
    Cmd_0166 0x8020, 4, 0x8030
    WorkCmpConst 0x802f, 0
    VMJumpIf 1, L_0D5E
    VMJump L_0D7C

L_0D5E:
    Cmd_0166 0x8020, 1, 0x802e
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x802e, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0DE2

L_0D7C:
    WorkCmpConst 0x802f, 1
    VMJumpIf 1, L_0D8F
    VMJump L_0DC5

L_0D8F:
    Cmd_0166 0x8020, 2, 0x802e
    WordSetPlayerName 0
    WordSetMusicalInfo 1, 1, 0x8030
    ParentActorMsg 1024, 0x802e, 0, 0
    ActorMsgClose
    WorkGet 0x8008, 0x8030
    WorkSetConst 0x8009, 0
    RTCallGlobal 10466
    Cmd_0169 0x8020
    VMJump L_0DE2

L_0DC5:
    WorkCmpConst 0x802f, 2
    VMJumpIf 1, L_0DD8
    VMJump L_0DE2

L_0DD8:
    Cmd_0169 0x8020
    VMJump L_0DE2

L_0DE2:
    WorkSetConst 0x8030, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802d, 0
    VMReturn

Script_7:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    WorkSetConst 0x8020, 1
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    WorkSetConst 0x8020, 2
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    WorkSetConst 0x8020, 3
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    WorkSetConst 0x8020, 4
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    WorkSetConst 0x8020, 5
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    WorkSetConst 0x8020, 6
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    WorkSetConst 0x8020, 7
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    WorkSetConst 0x8020, 8
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    WorkSetConst 0x8020, 9
    VMCall L_0CF1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetMusicalInfo 1, 1, 0x8008
    MEPlay 1308
    SystemMsg 26, 0
    MEWait
    MsgWaitAdvance
    VMStackPush 0x8009
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0EFC
    SystemMsg 28, 0
    VMJump L_0F04

L_0EFC:
    SystemMsg 27, 0
    LastKeyWait

L_0F04:
    InfoMsgClose
    Cmd_0168 0x8008
    RTEndGlobal
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
