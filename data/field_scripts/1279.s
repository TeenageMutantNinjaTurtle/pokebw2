#include "asm/field_script.inc"

// Script plugin 6, from the only plugin whose commands it decodes with

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Plugin6_Cmd1022 0, 0x8010
    VMCall L_0060
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Plugin6_Cmd1022 1, 0x8010
    VMCall L_0060
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Plugin6_Cmd1022 2, 0x8010
    VMCall L_0060
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0060:
    ParentActorMsg 1024, 0x8010, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Plugin6_Cmd1018 4, 17, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B9
    ParentActorMsg 1024, 176, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_00BF

L_00B9:
    VMCall L_00C5

L_00BF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_00C5:
    ParentActorMsg 1024, 56, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32802
    VMCall L_11DE
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_00F9
    ListMenuAdd 60, 65535, 60

L_00F9:
    VMCall L_129A
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_011A
    ListMenuAdd 61, 65535, 61

L_011A:
    VMCall L_131A
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_013B
    ListMenuAdd 62, 65535, 62

L_013B:
    VMCall L_138E
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_015C
    ListMenuAdd 63, 65535, 63

L_015C:
    VMCall L_141A
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_017D
    ListMenuAdd 64, 65535, 64

L_017D:
    ListMenuAdd 59, 65535, 59
    ListMenuShow
    WorkCmpConst 0x8022, 60
    VMJumpIf 1, L_019A
    VMJump L_01A6

L_019A:
    VMCall L_0232
    VMJump L_0222

L_01A6:
    WorkCmpConst 0x8022, 61
    VMJumpIf 1, L_01B9
    VMJump L_01C5

L_01B9:
    VMCall L_0672
    VMJump L_0222

L_01C5:
    WorkCmpConst 0x8022, 62
    VMJumpIf 1, L_01D8
    VMJump L_01E4

L_01D8:
    VMCall L_095E
    VMJump L_0222

L_01E4:
    WorkCmpConst 0x8022, 63
    VMJumpIf 1, L_01F7
    VMJump L_0203

L_01F7:
    VMCall L_0C06
    VMJump L_0222

L_0203:
    WorkCmpConst 0x8022, 64
    VMJumpIf 1, L_0216
    VMJump L_0222

L_0216:
    VMCall L_0F36
    VMJump L_0222

L_0222:
    ParentActorMsg 1024, 58, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_0232:
    WorkSetConst 0x8020, 1

L_0238:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0670
    ParentActorMsg 1024, 57, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32802
    Cmd_02D5 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_027F
    ListMenuAdd 65, 65535, 65

L_027F:
    Cmd_02D5 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02A0
    ListMenuAdd 66, 65535, 66

L_02A0:
    Cmd_02D5 2, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02C1
    ListMenuAdd 67, 65535, 67

L_02C1:
    Cmd_02D5 3, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02E2
    ListMenuAdd 68, 65535, 68

L_02E2:
    Cmd_02D5 4, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0303
    ListMenuAdd 69, 65535, 69

L_0303:
    Cmd_02D5 5, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0324
    ListMenuAdd 70, 65535, 70

L_0324:
    Cmd_02D5 6, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0345
    ListMenuAdd 71, 65535, 71

L_0345:
    Cmd_02D5 7, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0366
    ListMenuAdd 72, 65535, 72

L_0366:
    Cmd_02D5 8, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0387
    ListMenuAdd 73, 65535, 73

L_0387:
    Cmd_02D5 9, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03A8
    ListMenuAdd 74, 65535, 74

L_03A8:
    Cmd_02D5 10, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03C9
    ListMenuAdd 75, 65535, 75

L_03C9:
    Cmd_02D5 11, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03EA
    ListMenuAdd 76, 65535, 76

L_03EA:
    Cmd_02D5 12, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_040B
    ListMenuAdd 77, 65535, 77

L_040B:
    Cmd_02D5 13, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_042C
    ListMenuAdd 78, 65535, 78

L_042C:
    Cmd_02D5 19, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_044D
    ListMenuAdd 84, 65535, 84

L_044D:
    ListMenuAdd 59, 65535, 59
    ListMenuShow
    WorkCmpConst 0x8022, 65
    VMJumpIf 1, L_046A
    VMJump L_047A

L_046A:
    ParentActorMsg 1024, 121, 2, 0
    VMJump L_066A

L_047A:
    WorkCmpConst 0x8022, 66
    VMJumpIf 1, L_048D
    VMJump L_049D

L_048D:
    ParentActorMsg 1024, 122, 2, 0
    VMJump L_066A

L_049D:
    WorkCmpConst 0x8022, 67
    VMJumpIf 1, L_04B0
    VMJump L_04C0

L_04B0:
    ParentActorMsg 1024, 123, 2, 0
    VMJump L_066A

L_04C0:
    WorkCmpConst 0x8022, 68
    VMJumpIf 1, L_04D3
    VMJump L_04E3

L_04D3:
    ParentActorMsg 1024, 124, 2, 0
    VMJump L_066A

L_04E3:
    WorkCmpConst 0x8022, 69
    VMJumpIf 1, L_04F6
    VMJump L_0506

L_04F6:
    ParentActorMsg 1024, 125, 2, 0
    VMJump L_066A

L_0506:
    WorkCmpConst 0x8022, 70
    VMJumpIf 1, L_0519
    VMJump L_0529

L_0519:
    ParentActorMsg 1024, 126, 2, 0
    VMJump L_066A

L_0529:
    WorkCmpConst 0x8022, 71
    VMJumpIf 1, L_053C
    VMJump L_054C

L_053C:
    ParentActorMsg 1024, 127, 2, 0
    VMJump L_066A

L_054C:
    WorkCmpConst 0x8022, 72
    VMJumpIf 1, L_055F
    VMJump L_056F

L_055F:
    ParentActorMsg 1024, 128, 2, 0
    VMJump L_066A

L_056F:
    WorkCmpConst 0x8022, 73
    VMJumpIf 1, L_0582
    VMJump L_0592

L_0582:
    ParentActorMsg 1024, 129, 2, 0
    VMJump L_066A

L_0592:
    WorkCmpConst 0x8022, 74
    VMJumpIf 1, L_05A5
    VMJump L_05B5

L_05A5:
    ParentActorMsg 1024, 130, 2, 0
    VMJump L_066A

L_05B5:
    WorkCmpConst 0x8022, 75
    VMJumpIf 1, L_05C8
    VMJump L_05D8

L_05C8:
    ParentActorMsg 1024, 131, 2, 0
    VMJump L_066A

L_05D8:
    WorkCmpConst 0x8022, 76
    VMJumpIf 1, L_05EB
    VMJump L_05FB

L_05EB:
    ParentActorMsg 1024, 132, 2, 0
    VMJump L_066A

L_05FB:
    WorkCmpConst 0x8022, 77
    VMJumpIf 1, L_060E
    VMJump L_061E

L_060E:
    ParentActorMsg 1024, 133, 2, 0
    VMJump L_066A

L_061E:
    WorkCmpConst 0x8022, 78
    VMJumpIf 1, L_0631
    VMJump L_0641

L_0631:
    ParentActorMsg 1024, 134, 2, 0
    VMJump L_066A

L_0641:
    WorkCmpConst 0x8022, 84
    VMJumpIf 1, L_0654
    VMJump L_0664

L_0654:
    ParentActorMsg 1024, 140, 2, 0
    VMJump L_066A

L_0664:
    WorkSetConst 0x8020, 0

L_066A:
    VMJump L_0238

L_0670:
    VMReturn

L_0672:
    WorkSetConst 0x8020, 1

L_0678:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_095C
    ParentActorMsg 1024, 57, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32802
    Cmd_02D5 20, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06BF
    ListMenuAdd 85, 65535, 85

L_06BF:
    Cmd_02D5 21, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06E0
    ListMenuAdd 86, 65535, 86

L_06E0:
    Cmd_02D5 22, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0701
    ListMenuAdd 87, 65535, 87

L_0701:
    Cmd_02D5 23, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0722
    ListMenuAdd 88, 65535, 88

L_0722:
    Cmd_02D5 24, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0743
    ListMenuAdd 89, 65535, 89

L_0743:
    Cmd_02D5 25, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0764
    ListMenuAdd 90, 65535, 90

L_0764:
    Cmd_02D5 26, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0785
    ListMenuAdd 91, 65535, 91

L_0785:
    Cmd_02D5 35, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07A6
    ListMenuAdd 100, 65535, 100

L_07A6:
    Cmd_02D5 14, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07C7
    ListMenuAdd 79, 65535, 79

L_07C7:
    Cmd_02D5 53, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07E8
    ListMenuAdd 118, 65535, 118

L_07E8:
    ListMenuAdd 59, 65535, 59
    ListMenuShow
    WorkCmpConst 0x8022, 85
    VMJumpIf 1, L_0805
    VMJump L_0815

L_0805:
    ParentActorMsg 1024, 141, 2, 0
    VMJump L_0956

L_0815:
    WorkCmpConst 0x8022, 86
    VMJumpIf 1, L_0828
    VMJump L_0838

L_0828:
    ParentActorMsg 1024, 142, 2, 0
    VMJump L_0956

L_0838:
    WorkCmpConst 0x8022, 87
    VMJumpIf 1, L_084B
    VMJump L_085B

L_084B:
    ParentActorMsg 1024, 143, 2, 0
    VMJump L_0956

L_085B:
    WorkCmpConst 0x8022, 88
    VMJumpIf 1, L_086E
    VMJump L_087E

L_086E:
    ParentActorMsg 1024, 144, 2, 0
    VMJump L_0956

L_087E:
    WorkCmpConst 0x8022, 89
    VMJumpIf 1, L_0891
    VMJump L_08A1

L_0891:
    ParentActorMsg 1024, 145, 2, 0
    VMJump L_0956

L_08A1:
    WorkCmpConst 0x8022, 90
    VMJumpIf 1, L_08B4
    VMJump L_08C4

L_08B4:
    ParentActorMsg 1024, 146, 2, 0
    VMJump L_0956

L_08C4:
    WorkCmpConst 0x8022, 91
    VMJumpIf 1, L_08D7
    VMJump L_08E7

L_08D7:
    ParentActorMsg 1024, 147, 2, 0
    VMJump L_0956

L_08E7:
    WorkCmpConst 0x8022, 100
    VMJumpIf 1, L_08FA
    VMJump L_090A

L_08FA:
    ParentActorMsg 1024, 156, 2, 0
    VMJump L_0956

L_090A:
    WorkCmpConst 0x8022, 79
    VMJumpIf 1, L_091D
    VMJump L_092D

L_091D:
    ParentActorMsg 1024, 135, 2, 0
    VMJump L_0956

L_092D:
    WorkCmpConst 0x8022, 118
    VMJumpIf 1, L_0940
    VMJump L_0950

L_0940:
    ParentActorMsg 1024, 174, 2, 0
    VMJump L_0956

L_0950:
    WorkSetConst 0x8020, 0

L_0956:
    VMJump L_0678

L_095C:
    VMReturn

L_095E:
    WorkSetConst 0x8020, 1

L_0964:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C04
    ParentActorMsg 1024, 57, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32802
    Cmd_02D5 27, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_09AB
    ListMenuAdd 92, 65535, 92

L_09AB:
    Cmd_02D5 28, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_09CC
    ListMenuAdd 93, 65535, 93

L_09CC:
    Cmd_02D5 29, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_09ED
    ListMenuAdd 94, 65535, 94

L_09ED:
    Cmd_02D5 30, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A0E
    ListMenuAdd 95, 65535, 95

L_0A0E:
    Cmd_02D5 31, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A2F
    ListMenuAdd 96, 65535, 96

L_0A2F:
    Cmd_02D5 32, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A50
    ListMenuAdd 97, 65535, 97

L_0A50:
    Cmd_02D5 33, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A71
    ListMenuAdd 98, 65535, 98

L_0A71:
    Cmd_02D5 34, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A92
    ListMenuAdd 99, 65535, 99

L_0A92:
    Cmd_02D5 15, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0AB3
    ListMenuAdd 80, 65535, 80

L_0AB3:
    ListMenuAdd 59, 65535, 59
    ListMenuShow
    WorkCmpConst 0x8022, 92
    VMJumpIf 1, L_0AD0
    VMJump L_0AE0

L_0AD0:
    ParentActorMsg 1024, 148, 2, 0
    VMJump L_0BFE

L_0AE0:
    WorkCmpConst 0x8022, 93
    VMJumpIf 1, L_0AF3
    VMJump L_0B03

L_0AF3:
    ParentActorMsg 1024, 149, 2, 0
    VMJump L_0BFE

L_0B03:
    WorkCmpConst 0x8022, 94
    VMJumpIf 1, L_0B16
    VMJump L_0B26

L_0B16:
    ParentActorMsg 1024, 150, 2, 0
    VMJump L_0BFE

L_0B26:
    WorkCmpConst 0x8022, 95
    VMJumpIf 1, L_0B39
    VMJump L_0B49

L_0B39:
    ParentActorMsg 1024, 151, 2, 0
    VMJump L_0BFE

L_0B49:
    WorkCmpConst 0x8022, 96
    VMJumpIf 1, L_0B5C
    VMJump L_0B6C

L_0B5C:
    ParentActorMsg 1024, 152, 2, 0
    VMJump L_0BFE

L_0B6C:
    WorkCmpConst 0x8022, 97
    VMJumpIf 1, L_0B7F
    VMJump L_0B8F

L_0B7F:
    ParentActorMsg 1024, 153, 2, 0
    VMJump L_0BFE

L_0B8F:
    WorkCmpConst 0x8022, 98
    VMJumpIf 1, L_0BA2
    VMJump L_0BB2

L_0BA2:
    ParentActorMsg 1024, 154, 2, 0
    VMJump L_0BFE

L_0BB2:
    WorkCmpConst 0x8022, 99
    VMJumpIf 1, L_0BC5
    VMJump L_0BD5

L_0BC5:
    ParentActorMsg 1024, 155, 2, 0
    VMJump L_0BFE

L_0BD5:
    WorkCmpConst 0x8022, 80
    VMJumpIf 1, L_0BE8
    VMJump L_0BF8

L_0BE8:
    ParentActorMsg 1024, 136, 2, 0
    VMJump L_0BFE

L_0BF8:
    WorkSetConst 0x8020, 0

L_0BFE:
    VMJump L_0964

L_0C04:
    VMReturn

L_0C06:
    WorkSetConst 0x8020, 1

L_0C0C:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0F34
    ParentActorMsg 1024, 57, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32802
    Cmd_02D5 36, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C53
    ListMenuAdd 101, 65535, 101

L_0C53:
    Cmd_02D5 37, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C74
    ListMenuAdd 102, 65535, 102

L_0C74:
    Cmd_02D5 38, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C95
    ListMenuAdd 103, 65535, 103

L_0C95:
    Cmd_02D5 39, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0CB6
    ListMenuAdd 104, 65535, 104

L_0CB6:
    Cmd_02D5 40, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0CD7
    ListMenuAdd 105, 65535, 105

L_0CD7:
    Cmd_02D5 41, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0CF8
    ListMenuAdd 106, 65535, 106

L_0CF8:
    Cmd_02D5 42, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D19
    ListMenuAdd 107, 65535, 107

L_0D19:
    Cmd_02D5 43, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D3A
    ListMenuAdd 108, 65535, 108

L_0D3A:
    Cmd_02D5 44, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D5B
    ListMenuAdd 109, 65535, 109

L_0D5B:
    Cmd_02D5 16, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D7C
    ListMenuAdd 81, 65535, 81

L_0D7C:
    Cmd_02D5 17, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D9D
    ListMenuAdd 82, 65535, 82

L_0D9D:
    ListMenuAdd 59, 65535, 59
    ListMenuShow
    WorkCmpConst 0x8022, 101
    VMJumpIf 1, L_0DBA
    VMJump L_0DCA

L_0DBA:
    ParentActorMsg 1024, 157, 2, 0
    VMJump L_0F2E

L_0DCA:
    WorkCmpConst 0x8022, 102
    VMJumpIf 1, L_0DDD
    VMJump L_0DED

L_0DDD:
    ParentActorMsg 1024, 158, 2, 0
    VMJump L_0F2E

L_0DED:
    WorkCmpConst 0x8022, 103
    VMJumpIf 1, L_0E00
    VMJump L_0E10

L_0E00:
    ParentActorMsg 1024, 159, 2, 0
    VMJump L_0F2E

L_0E10:
    WorkCmpConst 0x8022, 104
    VMJumpIf 1, L_0E23
    VMJump L_0E33

L_0E23:
    ParentActorMsg 1024, 160, 2, 0
    VMJump L_0F2E

L_0E33:
    WorkCmpConst 0x8022, 105
    VMJumpIf 1, L_0E46
    VMJump L_0E56

L_0E46:
    ParentActorMsg 1024, 161, 2, 0
    VMJump L_0F2E

L_0E56:
    WorkCmpConst 0x8022, 106
    VMJumpIf 1, L_0E69
    VMJump L_0E79

L_0E69:
    ParentActorMsg 1024, 162, 2, 0
    VMJump L_0F2E

L_0E79:
    WorkCmpConst 0x8022, 107
    VMJumpIf 1, L_0E8C
    VMJump L_0E9C

L_0E8C:
    ParentActorMsg 1024, 163, 2, 0
    VMJump L_0F2E

L_0E9C:
    WorkCmpConst 0x8022, 108
    VMJumpIf 1, L_0EAF
    VMJump L_0EBF

L_0EAF:
    ParentActorMsg 1024, 164, 2, 0
    VMJump L_0F2E

L_0EBF:
    WorkCmpConst 0x8022, 109
    VMJumpIf 1, L_0ED2
    VMJump L_0EE2

L_0ED2:
    ParentActorMsg 1024, 165, 2, 0
    VMJump L_0F2E

L_0EE2:
    WorkCmpConst 0x8022, 81
    VMJumpIf 1, L_0EF5
    VMJump L_0F05

L_0EF5:
    ParentActorMsg 1024, 137, 2, 0
    VMJump L_0F2E

L_0F05:
    WorkCmpConst 0x8022, 82
    VMJumpIf 1, L_0F18
    VMJump L_0F28

L_0F18:
    ParentActorMsg 1024, 138, 2, 0
    VMJump L_0F2E

L_0F28:
    WorkSetConst 0x8020, 0

L_0F2E:
    VMJump L_0C0C

L_0F34:
    VMReturn

L_0F36:
    WorkSetConst 0x8020, 1

L_0F3C:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_11DC
    ParentActorMsg 1024, 57, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32802
    Cmd_02D5 45, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0F83
    ListMenuAdd 110, 65535, 110

L_0F83:
    Cmd_02D5 46, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0FA4
    ListMenuAdd 111, 65535, 111

L_0FA4:
    Cmd_02D5 47, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0FC5
    ListMenuAdd 112, 65535, 112

L_0FC5:
    Cmd_02D5 48, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0FE6
    ListMenuAdd 113, 65535, 113

L_0FE6:
    Cmd_02D5 49, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1007
    ListMenuAdd 114, 65535, 114

L_1007:
    Cmd_02D5 50, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1028
    ListMenuAdd 115, 65535, 115

L_1028:
    Cmd_02D5 51, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1049
    ListMenuAdd 116, 65535, 116

L_1049:
    Cmd_02D5 52, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_106A
    ListMenuAdd 117, 65535, 117

L_106A:
    Cmd_02D5 18, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_108B
    ListMenuAdd 83, 65535, 83

L_108B:
    ListMenuAdd 59, 65535, 59
    ListMenuShow
    WorkCmpConst 0x8022, 110
    VMJumpIf 1, L_10A8
    VMJump L_10B8

L_10A8:
    ParentActorMsg 1024, 166, 2, 0
    VMJump L_11D6

L_10B8:
    WorkCmpConst 0x8022, 111
    VMJumpIf 1, L_10CB
    VMJump L_10DB

L_10CB:
    ParentActorMsg 1024, 167, 2, 0
    VMJump L_11D6

L_10DB:
    WorkCmpConst 0x8022, 112
    VMJumpIf 1, L_10EE
    VMJump L_10FE

L_10EE:
    ParentActorMsg 1024, 168, 2, 0
    VMJump L_11D6

L_10FE:
    WorkCmpConst 0x8022, 113
    VMJumpIf 1, L_1111
    VMJump L_1121

L_1111:
    ParentActorMsg 1024, 169, 2, 0
    VMJump L_11D6

L_1121:
    WorkCmpConst 0x8022, 114
    VMJumpIf 1, L_1134
    VMJump L_1144

L_1134:
    ParentActorMsg 1024, 170, 2, 0
    VMJump L_11D6

L_1144:
    WorkCmpConst 0x8022, 115
    VMJumpIf 1, L_1157
    VMJump L_1167

L_1157:
    ParentActorMsg 1024, 171, 2, 0
    VMJump L_11D6

L_1167:
    WorkCmpConst 0x8022, 116
    VMJumpIf 1, L_117A
    VMJump L_118A

L_117A:
    ParentActorMsg 1024, 172, 2, 0
    VMJump L_11D6

L_118A:
    WorkCmpConst 0x8022, 117
    VMJumpIf 1, L_119D
    VMJump L_11AD

L_119D:
    ParentActorMsg 1024, 173, 2, 0
    VMJump L_11D6

L_11AD:
    WorkCmpConst 0x8022, 83
    VMJumpIf 1, L_11C0
    VMJump L_11D0

L_11C0:
    ParentActorMsg 1024, 139, 2, 0
    VMJump L_11D6

L_11D0:
    WorkSetConst 0x8020, 0

L_11D6:
    VMJump L_0F3C

L_11DC:
    VMReturn

L_11DE:
    WorkSetConst 0x8021, 0
    Cmd_02D5 0, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 1, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 2, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 3, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 4, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 5, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 6, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 7, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 8, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 9, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 10, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 11, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 12, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 13, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 19, 0x8010
    WorkAdd 0x8021, 0x8010
    VMReturn

L_129A:
    WorkSetConst 0x8021, 0
    Cmd_02D5 20, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 21, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 22, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 23, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 24, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 25, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 26, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 35, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 14, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 53, 0x8010
    WorkAdd 0x8021, 0x8010
    VMReturn

L_131A:
    WorkSetConst 0x8021, 0
    Cmd_02D5 27, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 28, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 29, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 30, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 31, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 32, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 33, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 34, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 15, 0x8010
    WorkAdd 0x8021, 0x8010
    VMReturn

L_138E:
    WorkSetConst 0x8021, 0
    Cmd_02D5 36, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 37, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 38, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 39, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 40, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 41, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 42, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 43, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 44, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 16, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 17, 0x8010
    WorkAdd 0x8021, 0x8010
    VMReturn

L_141A:
    WorkSetConst 0x8021, 0
    Cmd_02D5 45, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 46, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 47, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 48, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 49, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 50, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 51, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 52, 0x8010
    WorkAdd 0x8021, 0x8010
    Cmd_02D5 18, 0x8010
    WorkAdd 0x8021, 0x8010
    VMReturn
    .balign 4, 0
