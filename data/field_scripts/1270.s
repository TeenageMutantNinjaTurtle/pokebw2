#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    VMStackPushFlag 225
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0051
    ParentActorMsg 1024, 0, 0, 0
    FlagSet 225

L_0051:
    WorkSetConst 0x8023, 0
    ItemCollectorCheckGroup 0, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0172
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallBag 1, 0x8021, 0x8020
    FieldOpen
    FadeInBlackQ
    FadeWait
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B7
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_016C

L_00B7:
    ItemCollectorGetPrice 0x8020, 0, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E6
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_016C

L_00E6:
    MoneyWinDisp 31, 1
    WordSetLoadItemCollectorPrice 0x8020, 0, 1, 8
    WordSetItemName 0, 0x8020
    ActorMsg 1024, 2, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_015C
    MsgWinCloseAll
    SEPlay 1621
    ItemCollectorSell 0x8020, 0
    MoneyWinUpdate
    SystemMsg 3, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose
    WorkSetConst 0x8024, 0
    ItemSub 0x8020, 1, 0x8024
    MoneyWinClose
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_016C

L_015C:
    MoneyWinClose
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_016C:
    VMJump L_0180

L_0172:
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0180:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    VMStackPushFlag 226
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01DF
    ParentActorMsg 1024, 8, 0, 0
    FlagSet 226

L_01DF:
    WorkSetConst 0x8028, 0
    ItemCollectorCheckGroup 1, 0x8028
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0300
    ParentActorMsg 1024, 9, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallBag 1, 0x8026, 0x8025
    FieldOpen
    FadeInBlackQ
    FadeWait
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0245
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02FA

L_0245:
    ItemCollectorGetPrice 0x8025, 1, 0x8027
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0274
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02FA

L_0274:
    MoneyWinDisp 31, 1
    WordSetLoadItemCollectorPrice 0x8025, 1, 1, 8
    WordSetItemName 0, 0x8025
    ActorMsg 1024, 10, 7, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02EA
    MsgWinCloseAll
    SEPlay 1621
    ItemCollectorSell 0x8025, 1
    MoneyWinUpdate
    SystemMsg 11, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose
    WorkSetConst 0x8029, 0
    ItemSub 0x8025, 1, 0x8029
    MoneyWinClose
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02FA

L_02EA:
    MoneyWinClose
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02FA:
    VMJump L_0310

L_0300:
    MoneyWinClose
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0310:
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    VMStackPushFlag 227
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0375
    ParentActorMsg 1024, 16, 0, 0
    FlagSet 227

L_0375:
    VMStackPushFlag 233
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_044D
    ItemCheckAmount 590, 1, 0x802d
    VMStackPush 0x802d
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0441
    WorkSetConst 0x802a, 590
    ItemCollectorGetPrice 0x802a, 2, 0x802c
    MoneyWinDisp 31, 1
    WordSetLoadItemCollectorPrice 0x802a, 2, 1, 8
    WordSetItemName 0, 0x802a
    ActorMsg 1024, 23, 0, 2, 0
    YesNoWin 0x8010
    FlagSet 233
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_042B
    MsgWinCloseAll
    SEPlay 1621
    ItemCollectorSell 0x802a, 2
    MoneyWinUpdate
    SystemMsg 19, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose
    WorkSetConst 0x802e, 0
    ItemSub 0x802a, 1, 0x802e
    MoneyWinClose
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_043B

L_042B:
    MoneyWinClose
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_043B:
    VMJump L_0447

L_0441:
    VMCall L_0477

L_0447:
    VMJump L_0453

L_044D:
    VMCall L_0477

L_0453:
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802a, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0477:
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8030, 0
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8032, 0
    ItemCollectorCheckGroup 2, 0x8032
    VMStackPush 0x8032
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05AA
    ParentActorMsg 1024, 17, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallBag 1, 0x8030, 0x802f
    FieldOpen
    FadeInBlackQ
    FadeWait
    VMStackPush 0x802f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04EF
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_05A4

L_04EF:
    ItemCollectorGetPrice 0x802f, 2, 0x8031
    VMStackPush 0x8031
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_051E
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_05A4

L_051E:
    MoneyWinDisp 31, 1
    WordSetLoadItemCollectorPrice 0x802f, 2, 1, 8
    WordSetItemName 0, 0x802f
    ActorMsg 1024, 18, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0594
    MsgWinCloseAll
    SEPlay 1621
    ItemCollectorSell 0x802f, 2
    MoneyWinUpdate
    SystemMsg 19, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose
    WorkSetConst 0x8033, 0
    ItemSub 0x802f, 1, 0x8033
    MoneyWinClose
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_05A4

L_0594:
    MoneyWinClose
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_05A4:
    VMJump L_05B8

L_05AA:
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_05B8:
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8032, 0
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8030, 0
    WorkSetConst 0x802f, 0
    VMReturn

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8034, 0
    WorkSetConst 0x8035, 0
    WorkSetConst 0x8036, 0
    VMStackPushFlag 251
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0613
    ParentActorMsg 1024, 25, 0, 0
    FlagSet 251

L_0613:
    WorkSetConst 0x8037, 0
    ItemCollectorCheckGroup 3, 0x8037
    VMStackPush 0x8037
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0734
    ParentActorMsg 1024, 26, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallBag 1, 0x8035, 0x8034
    FieldOpen
    FadeInBlackQ
    FadeWait
    VMStackPush 0x8034
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0679
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_072E

L_0679:
    ItemCollectorGetPrice 0x8034, 3, 0x8036
    VMStackPush 0x8036
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06A8
    ParentActorMsg 1024, 30, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_072E

L_06A8:
    MoneyWinDisp 31, 1
    WordSetLoadItemCollectorPrice 0x8034, 3, 1, 8
    WordSetItemName 0, 0x8034
    ActorMsg 1024, 27, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_071E
    MsgWinCloseAll
    SEPlay 1621
    ItemCollectorSell 0x8034, 3
    MoneyWinUpdate
    SystemMsg 28, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose
    WorkSetConst 0x8038, 0
    ItemSub 0x8034, 1, 0x8038
    MoneyWinClose
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_072E

L_071E:
    MoneyWinClose
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_072E:
    VMJump L_0742

L_0734:
    ParentActorMsg 1024, 32, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0742:
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8037, 0
    WorkSetConst 0x8036, 0
    WorkSetConst 0x8035, 0
    WorkSetConst 0x8034, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8039, 0
    WorkSetConst 0x803a, 0
    WorkSetConst 0x803b, 0
    VMStackPushFlag 332
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07A1
    ParentActorMsg 1024, 33, 0, 0
    FlagSet 332

L_07A1:
    WorkSetConst 0x803c, 0
    ItemCollectorCheckGroup 4, 0x803c
    VMStackPush 0x803c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_08C2
    ParentActorMsg 1024, 34, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallBag 1, 0x803a, 0x8039
    FieldOpen
    FadeInBlackQ
    FadeWait
    VMStackPush 0x8039
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0807
    ParentActorMsg 1024, 39, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08BC

L_0807:
    ItemCollectorGetPrice 0x8039, 4, 0x803b
    VMStackPush 0x803b
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0836
    ParentActorMsg 1024, 38, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08BC

L_0836:
    MoneyWinDisp 31, 1
    WordSetLoadItemCollectorPrice 0x8039, 4, 1, 8
    WordSetItemName 0, 0x8039
    ActorMsg 1024, 35, 7, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08AC
    MsgWinCloseAll
    SEPlay 1621
    ItemCollectorSell 0x8039, 4
    MoneyWinUpdate
    SystemMsg 36, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose
    WorkSetConst 0x803d, 0
    ItemSub 0x8039, 1, 0x803d
    MoneyWinClose
    ParentActorMsg 1024, 37, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08BC

L_08AC:
    MoneyWinClose
    ParentActorMsg 1024, 39, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_08BC:
    VMJump L_08D2

L_08C2:
    MoneyWinClose
    ParentActorMsg 1024, 40, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_08D2:
    WorkSetConst 0x803d, 0
    WorkSetConst 0x803c, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803a, 0
    WorkSetConst 0x8039, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
