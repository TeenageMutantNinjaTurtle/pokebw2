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
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 2, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 3, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 4, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 5, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 6, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 7, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2731
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D5
    Random 0x417d, 16
    FlagSet 2731

L_00D5:
    WordSetPokeTypeName 0, 0x417d
    VMStackPushFlag 2732
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03CA
    ActorMsg 1024, 8, 1, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03B4
    ActorMsg 1024, 9, 1, 2, 0
    ActorMsgClose
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    CallPokeSelect 0, 0x8021, 0x8020, 0
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_039E
    WorkSetConst 0x8022, 0
    PokePartyIsEgg 0x8022, 0x8020
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_017C
    ActorMsg 1024, 21, 1, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0398

L_017C:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    PokePartyGetTypes 0x8023, 0x8024, 0x8020
    VMStackPush 0x417d
    VMStackPush 0x8023
    VMStackCmp 1
    VMStackPush 0x417d
    VMStackPush 0x8024
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0388
    ActorMsg 1024, 10, 1, 2, 0
    WorkSetConst 0x8025, 0
    ListMenu_AnchorTopRight 31, 1, 0, 0, 32805
    ListMenuAdd 11, 65535, 0
    ListMenuAdd 12, 65535, 1
    ListMenuAdd 13, 65535, 2
    ListMenuAdd 14, 65535, 3
    ListMenuAdd 15, 65535, 4
    ListMenuShow
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0244
    WordSetItemName 0, 149
    ActorMsg 1024, 16, 1, 2, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 149
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_036E

L_0244:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0290
    WordSetItemName 0, 150
    ActorMsg 1024, 16, 1, 2, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 150
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_036E

L_0290:
    VMStackPush 0x8025
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_02DC
    WordSetItemName 0, 151
    ActorMsg 1024, 16, 1, 2, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 151
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_036E

L_02DC:
    VMStackPush 0x8025
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0328
    WordSetItemName 0, 152
    ActorMsg 1024, 16, 1, 2, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 152
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_036E

L_0328:
    VMStackPush 0x8025
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_036E
    WordSetItemName 0, 153
    ActorMsg 1024, 16, 1, 2, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 153
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000

L_036E:
    ActorMsg 1024, 17, 1, 2, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 2732
    VMJump L_0398

L_0388:
    ActorMsg 1024, 20, 1, 2, 0
    LastKeyWait
    ActorMsgClose

L_0398:
    VMJump L_03AE

L_039E:
    ActorMsg 1024, 19, 1, 2, 0
    LastKeyWait
    ActorMsgClose

L_03AE:
    VMJump L_03C4

L_03B4:
    ActorMsg 1024, 19, 1, 2, 0
    LastKeyWait
    ActorMsgClose

L_03C4:
    VMJump L_03DA

L_03CA:
    ActorMsg 1024, 18, 1, 2, 0
    LastKeyWait
    ActorMsgClose

L_03DA:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 22, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 23, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 24, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
