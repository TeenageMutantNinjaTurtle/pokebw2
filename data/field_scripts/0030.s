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

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8023, 0
    SEPlay 1351
    SystemMsg 44, 2

L_003E:
    VMStackPush 0x8023
    VMStackPushConst 5
    VMStackCmp 5
    VMJumpIf 255, L_0139
    SystemMsg 45, 2
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32803
    ListMenuAdd 51, 65535, 0
    ListMenuAdd 52, 65535, 1
    ListMenuAdd 53, 65535, 2
    ListMenuAdd 54, 65535, 3
    ListMenuAdd 55, 65535, 4
    ListMenuAdd 56, 65535, 5
    ListMenuShow
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B1
    SystemMsg 46, 2
    VMJump L_0133

L_00B1:
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00D0
    SystemMsg 47, 2
    VMJump L_0133

L_00D0:
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00EF
    SystemMsg 48, 2
    VMJump L_0133

L_00EF:
    VMStackPush 0x8023
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_010E
    SystemMsg 49, 2
    VMJump L_0133

L_010E:
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_012D
    SystemMsg 50, 2
    VMJump L_0133

L_012D:
    WorkSetConst 0x8023, 5

L_0133:
    VMJump L_003E

L_0139:
    InfoMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40f9
    VMStackPushConst 0
    VMStackCmp 4
    VMStackPush 0x40f9
    VMStackPushConst 2
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0537
    WorkSetConst 0x8021, 0

L_0172:
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_049B
    VMStackPush 0x40f9
    VMStackPushConst 1
    VMStackCmp 4
    VMStackPush 0x40f9
    VMStackPushConst 2
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_01D7
    ActorMsg 1024, 8, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01D1
    VMJump L_01D7

L_01D1:
    WorkSetConst 0x8021, 1

L_01D7:
    VMStackPush 0x40f9
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02BF
    ActorMsg 1024, 0, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02B3
    ActorMsg 1024, 1, 0, 2, 0
    MsgWaitAdvance
    ActorMsg 1024, 3, 0, 2, 0
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32800
    ListMenuAdd 4, 65535, 0
    ListMenuAdd 5, 65535, 1
    ListMenuAdd 6, 65535, 2
    ListMenuShow
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 6
    VMStackCmp 6
    VMJumpIf 255, L_02A7
    ActorMsg 1024, 7, 0, 2, 0
    MsgWaitAdvance
    WorkSetConst 0x40f9, 1
    VMJump L_02AD

L_02A7:
    WorkSetConst 0x8021, 1

L_02AD:
    VMJump L_02B9

L_02B3:
    WorkSetConst 0x8021, 1

L_02B9:
    VMJump L_0495

L_02BF:
    VMStackPush 0x40f9
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03A4
    ActorMsg 1024, 9, 0, 2, 0
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32800
    ListMenuAdd 10, 65535, 0
    ListMenuAdd 11, 65535, 1
    ListMenuAdd 12, 65535, 2
    ListMenuShow
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_033E
    ActorMsg 1024, 13, 0, 2, 0
    MsgWaitAdvance
    WorkSetConst 0x40f9, 2
    VMJump L_039E

L_033E:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_036B
    ActorMsg 1024, 14, 0, 2, 0
    MsgWaitAdvance
    WorkSetConst 0x40f9, 2
    VMJump L_039E

L_036B:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0398
    ActorMsg 1024, 15, 0, 2, 0
    MsgWaitAdvance
    WorkSetConst 0x40f9, 2
    VMJump L_039E

L_0398:
    WorkSetConst 0x8021, 1

L_039E:
    VMJump L_0495

L_03A4:
    VMStackPush 0x40f9
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0495
    ActorMsg 1024, 16, 0, 2, 0
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32800
    ListMenuAdd 17, 65535, 0
    ListMenuAdd 18, 65535, 1
    ListMenuAdd 19, 65535, 2
    ListMenuShow
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0429
    ActorMsg 1024, 20, 0, 2, 0
    MsgWaitAdvance
    WorkSetConst 0x40f9, 3
    WorkSetConst 0x8021, 1
    VMJump L_0495

L_0429:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_045C
    ActorMsg 1024, 21, 0, 2, 0
    MsgWaitAdvance
    WorkSetConst 0x40f9, 3
    WorkSetConst 0x8021, 1
    VMJump L_0495

L_045C:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_048F
    ActorMsg 1024, 22, 0, 2, 0
    MsgWaitAdvance
    WorkSetConst 0x40f9, 3
    WorkSetConst 0x8021, 1
    VMJump L_0495

L_048F:
    WorkSetConst 0x8021, 1

L_0495:
    VMJump L_0172

L_049B:
    VMStackPush 0x40f9
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0521
    ActorMsg 1024, 23, 0, 2, 0
    MsgWaitAdvance
    ActorMsg 1024, 24, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_050B
    MsgWinCloseAll
    CallTrainerBattle 493, 0, 0
    VMCall L_05D8
    WorkSetConst 0x40f9, 4
    ActorMsg 1024, 25, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_051B

L_050B:
    ActorMsg 1024, 26, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_051B:
    VMJump L_0531

L_0521:
    ActorMsg 1024, 2, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0531:
    VMJump L_05D2

L_0537:
    VMStackPush 0x40f9
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_05AF
    ActorMsg 1024, 24, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0599
    MsgWinCloseAll
    CallTrainerBattle 493, 0, 0
    VMCall L_05D8
    WorkSetConst 0x40f9, 4
    ActorMsg 1024, 25, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_05A9

L_0599:
    ActorMsg 1024, 26, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_05A9:
    VMJump L_05D2

L_05AF:
    VMStackPush 0x40f9
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_05D2
    ActorMsg 1024, 25, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_05D2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_05D8:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05F7
    CallTrainerBattleEnd
    VMJump L_05F9

L_05F7:
    CallTrainerLose

L_05F9:
    VMReturn

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 27, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 355
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0864
    ActorMsg 1024, 30, 4, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_084E
    ActorMsg 1024, 31, 4, 2, 0
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32800
    ListMenuAdd 32, 65535, 0
    ListMenuAdd 33, 65535, 1
    ListMenuAdd 34, 65535, 2
    ListMenuShow
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06E7
    ActorMsg 1024, 35, 4, 2, 0
    WorkSetConst 0x8022, 1
    VMJump L_0749

L_06E7:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0710
    ActorMsg 1024, 43, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0749

L_0710:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0739
    ActorMsg 1024, 43, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0749

L_0739:
    ActorMsg 1024, 42, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0749:
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0848
    ActorMsg 1024, 36, 4, 2, 0
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32800
    ListMenuAdd 37, 65535, 0
    ListMenuAdd 38, 65535, 1
    ListMenuAdd 39, 65535, 2
    ListMenuShow
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07B4
    ActorMsg 1024, 43, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0848

L_07B4:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07DD
    ActorMsg 1024, 43, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0848

L_07DD:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0838
    ActorMsg 1024, 40, 4, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 156
    WorkSet 0x8001, 3
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 355
    ActorMsg 1024, 41, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0848

L_0838:
    ActorMsg 1024, 42, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0848:
    VMJump L_085E

L_084E:
    ActorMsg 1024, 42, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_085E:
    VMJump L_0874

L_0864:
    ActorMsg 1024, 41, 4, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0874:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
