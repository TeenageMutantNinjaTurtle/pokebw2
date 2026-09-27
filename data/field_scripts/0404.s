#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_2:
    FlagSet 690
    WorkSetConst 0x8020, 0
    RTCGetSeason 0x8020
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0033
    FlagReset 690

L_0033:
    WorkSetConst 0x8020, 0
    VMHalt

Script_1:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_006A
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_024B

L_006A:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2747
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0237
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 1, 2, 0, 0
    ActorMsgClose
    Random 0x400f, 7
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E0
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 99
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_021D

L_00E0:
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0119
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 100
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_021D

L_0119:
    VMStackPush 0x400f
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0152
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 101
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_021D

L_0152:
    VMStackPush 0x400f
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_018B
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 102
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_021D

L_018B:
    VMStackPush 0x400f
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_01C4
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 103
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_021D

L_01C4:
    VMStackPush 0x400f
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_01FD
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 104
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_021D

L_01FD:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 105
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000

L_021D:
    ActorMsg 1024, 2, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 2747
    VMJump L_024B

L_0237:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_024B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40fe
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02EA
    WorkSetConst 0x40fe, 1
    ActorMsg 1024, 3, 7, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02D0

L_02A7:
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02D0
    ActorMsg 1024, 5, 7, 2, 0
    YesNoWin 0x8010
    VMJump L_02A7

L_02D0:
    ActorMsg 1024, 4, 7, 2, 0
    MsgWaitAdvance
    VMCall L_046C
    VMJump L_0466

L_02EA:
    VMStackPush 0x40fe
    VMStackPushConst 1
    VMStackCmp 4
    VMStackPush 0x40fe
    VMStackPushConst 5
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_040E
    VMStackPushFlag 2769
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0336
    ActorMsg 1024, 34, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0408

L_0336:
    VMStackPushFlag 2770
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_035F
    ActorMsg 1024, 35, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0408

L_035F:
    ActorMsg 1024, 6, 7, 2, 0
    MsgWaitAdvance
    WorkCmpConst 0x40fe, 1
    VMJumpIf 1, L_0380
    VMJump L_038C

L_0380:
    VMCall L_046C
    VMJump L_0408

L_038C:
    WorkCmpConst 0x40fe, 2
    VMJumpIf 1, L_039F
    VMJump L_03AB

L_039F:
    VMCall L_04EE
    VMJump L_0408

L_03AB:
    WorkCmpConst 0x40fe, 3
    VMJumpIf 1, L_03BE
    VMJump L_03CA

L_03BE:
    VMCall L_0570
    VMJump L_0408

L_03CA:
    WorkCmpConst 0x40fe, 4
    VMJumpIf 1, L_03DD
    VMJump L_03E9

L_03DD:
    VMCall L_05F2
    VMJump L_0408

L_03E9:
    WorkCmpConst 0x40fe, 5
    VMJumpIf 1, L_03FC
    VMJump L_0408

L_03FC:
    VMCall L_0674
    VMJump L_0408

L_0408:
    VMJump L_0466

L_040E:
    VMStackPush 0x40fe
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_0466
    WorkSetConst 0x8024, 0
    MedalIsObtained 0x8024, 99
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0456
    ActorMsg 1024, 37, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0466

L_0456:
    ActorMsg 1024, 38, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0466:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_046C:
    ActorMsg 1024, 7, 7, 2, 0
    MsgWaitAdvance
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32801
    ListMenuAdd 8, 65535, 0
    ListMenuAdd 9, 65535, 1
    ListMenuAdd 10, 65535, 2
    ListMenuAdd 11, 65535, 3
    ListMenuShow
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04D8
    ActorMsg 1024, 32, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2769
    WorkSetConst 0x40fe, 2
    VMJump L_04EC

L_04D8:
    ActorMsg 1024, 33, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2770

L_04EC:
    VMReturn

L_04EE:
    ActorMsg 1024, 12, 7, 2, 0
    MsgWaitAdvance
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32801
    ListMenuAdd 13, 65535, 0
    ListMenuAdd 14, 65535, 1
    ListMenuAdd 15, 65535, 2
    ListMenuAdd 16, 65535, 3
    ListMenuShow
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_055A
    ActorMsg 1024, 32, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2769
    WorkSetConst 0x40fe, 3
    VMJump L_056E

L_055A:
    ActorMsg 1024, 33, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2770

L_056E:
    VMReturn

L_0570:
    ActorMsg 1024, 17, 7, 2, 0
    MsgWaitAdvance
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32801
    ListMenuAdd 18, 65535, 0
    ListMenuAdd 19, 65535, 1
    ListMenuAdd 20, 65535, 2
    ListMenuAdd 21, 65535, 3
    ListMenuShow
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_05DC
    ActorMsg 1024, 32, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2769
    WorkSetConst 0x40fe, 4
    VMJump L_05F0

L_05DC:
    ActorMsg 1024, 33, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2770

L_05F0:
    VMReturn

L_05F2:
    ActorMsg 1024, 22, 7, 2, 0
    MsgWaitAdvance
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32801
    ListMenuAdd 23, 65535, 0
    ListMenuAdd 24, 65535, 1
    ListMenuAdd 25, 65535, 2
    ListMenuAdd 26, 65535, 3
    ListMenuShow
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_065E
    ActorMsg 1024, 32, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2769
    WorkSetConst 0x40fe, 5
    VMJump L_0672

L_065E:
    ActorMsg 1024, 33, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2770

L_0672:
    VMReturn

L_0674:
    ActorMsg 1024, 27, 7, 2, 0
    MsgWaitAdvance
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32801
    ListMenuAdd 28, 65535, 0
    ListMenuAdd 29, 65535, 1
    ListMenuAdd 30, 65535, 2
    ListMenuAdd 31, 65535, 3
    ListMenuShow
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0700
    ActorMsg 1024, 32, 7, 2, 0
    MsgWaitAdvance
    ActorMsg 1024, 36, 7, 2, 0
    MsgWaitAdvance
    ActorMsg 1024, 37, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    MedalGive 99
    FlagSet 2769
    WorkSetConst 0x40fe, 6
    VMJump L_0714

L_0700:
    ActorMsg 1024, 33, 7, 2, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2770

L_0714:
    VMReturn
    .balign 4, 0
