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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0

Script_1:
    VMHalt

L_0096:
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 0x802e
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01EB
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_00CF
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_00CF
    VMJump L_00DF

L_00CF:
    ParentActorMsg 1024, 0x8022, 2, 0
    VMJump L_00E9

L_00DF:
    ParentActorMsg 1024, 0x8021, 2, 0

L_00E9:
    MoneyWinDisp 31, 1
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32808
    ListMenuAdd 39, 65535, 0
    ListMenuAdd 40, 65535, 1
    ListMenuShow
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01D5
    ItemCheckSpace 0x802b, 1, 0x8029
    MoneyCheck 0x802a, 0x802c
    VMStackPush 0x8029
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0152
    ParentActorMsg 1024, 0x8024, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01CF

L_0152:
    VMStackPush 0x802a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0179
    ParentActorMsg 1024, 0x8025, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01CF

L_0179:
    SEPlay 1621
    MoneySub 0x802c
    MoneyWinUpdate
    SEWait
    ParentActorMsg 1024, 0x8023, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 0x802b
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 0x8026, 2, 0
    LastKeyWait
    MsgWinCloseAll
    RecordAdd 21, 1
    RecordAdd 22, 0x802c
    FlagSet 0x802e

L_01CF:
    VMJump L_01E3

L_01D5:
    ParentActorMsg 1024, 0x8026, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_01E3:
    MoneyWinClose
    VMJump L_01F9

L_01EB:
    ParentActorMsg 1024, 0x8027, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_01F9:
    VMReturn

Script_2:
    ActorsPauseAll
    RTCGetWeekDay 0x802d
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_0221
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_0221
    VMJump L_0233

L_0221:
    WorkSetConst 0x802b, 321
    WorkSetConst 0x802c, 10000
    VMJump L_023F

L_0233:
    WorkSetConst 0x802b, 83
    WorkSetConst 0x802c, 10000

L_023F:
    WordSetItemNameWithArticle 0, 0x802b
    WordSetNumber 1, 0x802c, 5
    WorkSetConst 0x8021, 11
    WorkSetConst 0x8022, 12
    WorkSetConst 0x8023, 13
    WorkSetConst 0x8024, 14
    WorkSetConst 0x8025, 15
    WorkSetConst 0x8026, 16
    WorkSetConst 0x8027, 17
    WorkSetConst 0x802e, 2789
    VMCall L_0096
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    RTCGetWeekDay 0x802d
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_02AD
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_02AD
    VMJump L_02BF

L_02AD:
    WorkSetConst 0x802b, 233
    WorkSetConst 0x802c, 20000
    VMJump L_02CB

L_02BF:
    WorkSetConst 0x802b, 82
    WorkSetConst 0x802c, 20000

L_02CB:
    WordSetItemNameWithArticle 0, 0x802b
    WordSetNumber 1, 0x802c, 5
    WorkSetConst 0x8021, 18
    WorkSetConst 0x8022, 19
    WorkSetConst 0x8023, 20
    WorkSetConst 0x8024, 21
    WorkSetConst 0x8025, 22
    WorkSetConst 0x8026, 23
    WorkSetConst 0x8027, 24
    WorkSetConst 0x802e, 2790
    VMCall L_0096
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    RTCGetWeekDay 0x802d
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_0339
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_0339
    VMJump L_034B

L_0339:
    WorkSetConst 0x802b, 252
    WorkSetConst 0x802c, 40000
    VMJump L_0357

L_034B:
    WorkSetConst 0x802b, 108
    WorkSetConst 0x802c, 40000

L_0357:
    WordSetItemNameWithArticle 0, 0x802b
    WordSetNumber 1, 0x802c, 5
    WorkSetConst 0x8021, 25
    WorkSetConst 0x8022, 26
    WorkSetConst 0x8023, 27
    WorkSetConst 0x8024, 28
    WorkSetConst 0x8025, 29
    WorkSetConst 0x8026, 30
    WorkSetConst 0x8027, 31
    WorkSetConst 0x802e, 2791
    VMCall L_0096
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    RTCGetWeekDay 0x802d
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_03C5
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_03C5
    VMJump L_03D7

L_03C5:
    WorkSetConst 0x802b, 324
    WorkSetConst 0x802c, 60000
    VMJump L_03E3

L_03D7:
    WorkSetConst 0x802b, 109
    WorkSetConst 0x802c, 60000

L_03E3:
    WordSetItemNameWithArticle 0, 0x802b
    WordSetNumber 1, 0x802c, 5
    WorkSetConst 0x8021, 32
    WorkSetConst 0x8022, 33
    WorkSetConst 0x8023, 34
    WorkSetConst 0x8024, 35
    WorkSetConst 0x8025, 36
    WorkSetConst 0x8026, 37
    WorkSetConst 0x8027, 38
    WorkSetConst 0x802e, 2792
    VMCall L_0096
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_045E
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04C2

L_045E:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_049B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04C2

L_049B:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_04C2
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_04C2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
