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
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 0, 0, 0, 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 15
    WorkSet 0x8001, 0
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    MoneyWinDisp 31, 1
    ActorMsg 1024, 2, 1, 4, 0
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32801
    ListMenuAdd 8, 65535, 0
    ListMenuAdd 9, 65535, 1
    ListMenuAdd 10, 65535, 2
    ListMenuShow
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E0
    WorkSetConst 0x8020, 1
    WorkSetConst 0x8022, 500
    VMJump L_0105

L_00E0:
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0105
    WorkSetConst 0x8020, 12
    WorkSetConst 0x8022, 6000
    VMJump L_0105

L_0105:
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0201
    ItemCheckSpace 33, 0x8020, 0x8024
    MoneyCheck 0x8023, 0x8022
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0161
    MoneyWinClose
    ActorMsg 1024, 4, 1, 4, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01FB

L_0161:
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_018C
    MoneyWinClose
    ActorMsg 1024, 5, 1, 4, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01FB

L_018C:
    SEPlay 1621
    MoneySub 0x8022
    MoneyWinUpdate
    SEWait
    RecordAdd 21, 1
    RecordAdd 22, 0x8022
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01CB
    ActorMsg 1024, 3, 1, 4, 0
    MsgWinCloseAll
    VMJump L_01D9

L_01CB:
    ActorMsg 1024, 7, 1, 4, 0
    MsgWinCloseAll

L_01D9:
    MoneyWinClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 33
    WorkSet 0x8001, 0x8020
    RTCallGlobal 2802
    VMStackPop 0x8001
    VMStackPop 0x8000

L_01FB:
    VMJump L_0213

L_0201:
    MoneyWinClose
    ActorMsg 1024, 6, 1, 4, 0
    LastKeyWait
    MsgWinCloseAll

L_0213:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 24, 3, 0, 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 16
    WorkSet 0x8001, 0
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 18, 19, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 20, 21, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 22, 23, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 324
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_040E
    ParentActorMsg 1024, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03FA
    ParentActorMsg 1024, 13, 0, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    PokePartyGetCount 0x8025, 0

L_034F:
    VMStackPush 0x8025
    VMStackPush 0x8026
    VMStackCmp 2
    VMJumpIf 255, L_038F
    PokePartyGetParam 0x8027, 0x8026, 158
    VMStackPush 0x8027
    VMStackPushConst 30
    VMStackCmp 4
    VMJumpIf 255, L_0383
    WorkAdd 0x8028, 1

L_0383:
    WorkAdd 0x8026, 1
    VMJump L_034F

L_038F:
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_03E6
    ParentActorMsg 1024, 14, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 268
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 324
    VMJump L_03F4

L_03E6:
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03F4:
    VMJump L_0408

L_03FA:
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0408:
    VMJump L_041C

L_040E:
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_041C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
