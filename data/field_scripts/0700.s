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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 27, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    RTCGetDayPart 0x8020
    RTCGetWeekDay 0x8021
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01E1
    WorkCmpConst 0x8021, 0
    VMJumpIf 1, L_0115
    VMJump L_0121

L_0115:
    VMCall L_02EC
    VMJump L_01DB

L_0121:
    WorkCmpConst 0x8021, 1
    VMJumpIf 1, L_0134
    VMJump L_0140

L_0134:
    VMCall L_01FB
    VMJump L_01DB

L_0140:
    WorkCmpConst 0x8021, 2
    VMJumpIf 1, L_0153
    VMJump L_015F

L_0153:
    VMCall L_02EC
    VMJump L_01DB

L_015F:
    WorkCmpConst 0x8021, 3
    VMJumpIf 1, L_0172
    VMJump L_017E

L_0172:
    VMCall L_01FB
    VMJump L_01DB

L_017E:
    WorkCmpConst 0x8021, 4
    VMJumpIf 1, L_0191
    VMJump L_019D

L_0191:
    VMCall L_02EC
    VMJump L_01DB

L_019D:
    WorkCmpConst 0x8021, 5
    VMJumpIf 1, L_01B0
    VMJump L_01BC

L_01B0:
    VMCall L_01FB
    VMJump L_01DB

L_01BC:
    WorkCmpConst 0x8021, 6
    VMJumpIf 1, L_01CF
    VMJump L_01DB

L_01CF:
    VMCall L_02EC
    VMJump L_01DB

L_01DB:
    VMJump L_01F5

L_01E1:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose

L_01F5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_01FB:
    WorkSetConst 0x8022, 180
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 5, 3, 2, 0
    MoneyWinDisp 31, 1
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02D8
    ItemCheckSpace 4, 1, 0x8024
    MoneyCheck 0x8023, 0x8022
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0269
    MoneyWinClose
    ActorMsg 1024, 10, 3, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02D2

L_0269:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0294
    MoneyWinClose
    ActorMsg 1024, 11, 3, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02D2

L_0294:
    SEPlay 1621
    MoneySub 0x8022
    MoneyWinUpdate
    SEWait
    ActorMsg 1024, 8, 3, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    MoneyWinClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 4
    WorkSet 0x8001, 1
    RTCallGlobal 2806
    VMStackPop 0x8001
    VMStackPop 0x8000

L_02D2:
    VMJump L_02EA

L_02D8:
    MoneyWinClose
    ActorMsg 1024, 7, 3, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_02EA:
    VMReturn

L_02EC:
    WorkSetConst 0x8022, 270
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 6, 3, 2, 0
    MoneyWinDisp 31, 1
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03C9
    ItemCheckSpace 17, 1, 0x8024
    MoneyCheck 0x8023, 0x8022
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_035A
    MoneyWinClose
    ActorMsg 1024, 10, 3, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03C3

L_035A:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0385
    MoneyWinClose
    ActorMsg 1024, 11, 3, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03C3

L_0385:
    SEPlay 1621
    MoneySub 0x8022
    MoneyWinUpdate
    SEWait
    ActorMsg 1024, 9, 3, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    MoneyWinClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 17
    WorkSet 0x8001, 1
    RTCallGlobal 2806
    VMStackPop 0x8001
    VMStackPop 0x8000

L_03C3:
    VMJump L_03DB

L_03C9:
    MoneyWinClose
    ActorMsg 1024, 7, 3, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_03DB:
    VMReturn

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4184
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2765
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_04DC
    ParentActorMsg 1024, 16, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04C8
    ParentActorMsg 1024, 17, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WordSetPlayerName 0
    SystemMsg 18, 0
    LastKeyWait
    MsgWinCloseAll
    MoneyAdd 1200
    FlagSet 2764
    WorkSetConst 0x4184, 1
    VMJump L_04D6

L_04C8:
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_04D6:
    VMJump L_06A2

L_04DC:
    VMStackPush 0x4184
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2765
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0681
    VMStackPushFlag 2764
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0522
    ParentActorMsg 1024, 20, 0, 0
    VMJump L_052C

L_0522:
    ParentActorMsg 1024, 21, 0, 0

L_052C:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_066D
    ItemCheckAmount 25, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2764
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_05D2
    ParentActorMsg 1024, 22, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkSetConst 0x8025, 0
    ItemSub 25, 1, 0x8025
    WorkSetConst 0x8025, 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 35
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2765
    FlagReset 2764
    WorkSetConst 0x4184, 0
    VMJump L_0667

L_05D2:
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2764
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0659
    ParentActorMsg 1024, 23, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkSetConst 0x8026, 0
    ItemSub 25, 1, 0x8026
    WorkSetConst 0x8026, 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 34
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2765
    FlagReset 2764
    WorkSetConst 0x4184, 0
    VMJump L_0667

L_0659:
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0667:
    VMJump L_067B

L_066D:
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_067B:
    VMJump L_06A2

L_0681:
    VMStackPushFlag 2765
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06A2
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_06A2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 17
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 18
    WorkSet 0x8001, 2
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 19
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 20
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 14
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
