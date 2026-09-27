#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0

Script_1:
    WordSetPlayerName 0
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0102
    PokeDexGetEvaluationParams 2, 0x8020, 0x8021, 0x8022
    VMStackPushFlag 141
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00A1
    VMCall L_0142
    ParentActorMsg 1024, 2, 0, 0
    MEPlay 0x8022
    MEWait
    MsgWaitAdvance
    ParentActorMsg 1024, 0x8020, 0, 0
    VMJump L_00C3

L_00A1:
    VMCall L_0112
    ParentActorMsg 1024, 1, 0, 0
    MEPlay 0x8022
    MEWait
    MsgWaitAdvance
    ParentActorMsg 1024, 0x8020, 0, 0

L_00C3:
    VMCall L_02FC
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_00EE
    ParentActorMsg 1024, 35, 0, 0
    ActorMsgClose
    VMCall L_03FA

L_00EE:
    ParentActorMsg 1024, 40, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0110

L_0102:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose

L_0110:
    RTEndGlobal

L_0112:
    PokeDexIsComplete 0x8010, 2
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_012F
    FlagSet 141

L_012F:
    PokeDexGetEvaluationParams 2, 0x8020, 0x8021, 0x8022
    WordSetNumber 0, 0x8021, 3
    VMReturn

L_0142:
    PokeDexGetEvaluationParams 3, 0x8020, 0x8021, 0x8022
    WordSetNumber 0, 0x8021, 3
    VMReturn
    PokeDexIsComplete 0x8010, 2
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0178
    MEPlay 1316
    VMJump L_017E

L_0178:
    VMCall L_01AB

L_017E:
    VMReturn
    PokeDexIsComplete 0x8010, 3
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01A3
    MEPlay 1316
    VMJump L_01A9

L_01A3:
    VMCall L_01AB

L_01A9:
    VMReturn

L_01AB:
    VMStackPush 0x8021
    VMStackPushConst 39
    VMStackCmp 3
    VMJumpIf 255, L_01C8
    MEPlay 1311
    VMJump L_0240

L_01C8:
    VMStackPush 0x8021
    VMStackPushConst 99
    VMStackCmp 3
    VMJumpIf 255, L_01E5
    MEPlay 1312
    VMJump L_0240

L_01E5:
    VMStackPush 0x8021
    VMStackPushConst 149
    VMStackCmp 3
    VMJumpIf 255, L_0202
    MEPlay 1313
    VMJump L_0240

L_0202:
    VMStackPush 0x8021
    VMStackPushConst 199
    VMStackCmp 3
    VMJumpIf 255, L_021F
    MEPlay 1314
    VMJump L_0240

L_021F:
    VMStackPush 0x8021
    VMStackPushConst 249
    VMStackCmp 3
    VMJumpIf 255, L_023C
    MEPlay 1315
    VMJump L_0240

L_023C:
    MEPlay 1315

L_0240:
    VMReturn
    PokeDexIsComplete 0x8010, 1
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0265
    MEPlay 1316
    VMJump L_02FA

L_0265:
    VMStackPush 0x8021
    VMStackPushConst 159
    VMStackCmp 3
    VMJumpIf 255, L_0282
    MEPlay 1311
    VMJump L_02FA

L_0282:
    VMStackPush 0x8021
    VMStackPushConst 349
    VMStackCmp 3
    VMJumpIf 255, L_029F
    MEPlay 1312
    VMJump L_02FA

L_029F:
    VMStackPush 0x8021
    VMStackPushConst 449
    VMStackCmp 3
    VMJumpIf 255, L_02BC
    MEPlay 1313
    VMJump L_02FA

L_02BC:
    VMStackPush 0x8021
    VMStackPushConst 549
    VMStackCmp 3
    VMJumpIf 255, L_02D9
    MEPlay 1314
    VMJump L_02FA

L_02D9:
    VMStackPush 0x8021
    VMStackPushConst 633
    VMStackCmp 3
    VMJumpIf 255, L_02F6
    MEPlay 1315
    VMJump L_02FA

L_02F6:
    MEPlay 1315

L_02FA:
    VMReturn

L_02FC:
    WorkSetConst 0x8023, 0
    PokeDexIsComplete 0x8010, 2
    VMStackPushFlag 136
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0337
    WorkSetConst 0x8024, 1
    WorkSetConst 0x8023, 1

L_0337:
    PokeDexIsComplete 0x8010, 3
    VMStackPushFlag 137
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_037C
    WorkSetConst 0x8025, 1
    WorkSetConst 0x8023, 1

L_037C:
    PokeDexIsComplete 0x8010, 1
    VMStackPushFlag 138
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_03C1
    WorkSetConst 0x8026, 1
    WorkSetConst 0x8023, 1

L_03C1:
    VMReturn

L_03C3:
    WorkSetConst 0x8023, 0
    PokeDexIsComplete 0x8010, 1
    VMStackPushFlag 138
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03F8
    WorkSetConst 0x8023, 1

L_03F8:
    VMReturn

L_03FA:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0452
    ItemCheckSpace 630, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0434
    WorkSetConst 0x8008, 630
    RTCallGlobal 2803
    VMReturn

L_0434:
    WorkSetConst 0x8000, 630
    WorkSetConst 0x8001, 1
    RTCallGlobal 2805
    ParentActorMsg 1024, 36, 0, 0
    FlagSet 136

L_0452:
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_04AA
    ItemCheckSpace 631, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_048C
    WorkSetConst 0x8008, 631
    RTCallGlobal 2803
    VMReturn

L_048C:
    WorkSetConst 0x8000, 631
    WorkSetConst 0x8001, 1
    RTCallGlobal 2805
    ParentActorMsg 1024, 37, 0, 0
    FlagSet 137

L_04AA:
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0502
    ItemCheckSpace 632, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04E4
    WorkSetConst 0x8008, 632
    RTCallGlobal 2803
    VMReturn

L_04E4:
    WorkSetConst 0x8000, 632
    WorkSetConst 0x8001, 1
    RTCallGlobal 2805
    ParentActorMsg 1024, 38, 0, 0
    FlagSet 138

L_0502:
    VMReturn

Script_2:
    WordSetPlayerName 0
    ParentActorMsg 1024, 41, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0584
    PokeDexGetEvaluationParams 1, 0x8020, 0x8021, 0x8022
    WordSetNumber 0, 0x8021, 3
    ParentActorMsg 1024, 42, 0, 0
    MEPlay 0x8022
    MEWait
    MsgWaitAdvance
    ParentActorMsg 1024, 0x8020, 0, 0
    VMCall L_03C3
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_057A
    MsgWaitAdvance
    ParentActorMsg 1024, 61, 0, 0

L_057A:
    LastKeyWait
    ActorMsgClose
    VMJump L_0592

L_0584:
    ParentActorMsg 1024, 43, 0, 0
    LastKeyWait
    ActorMsgClose

L_0592:
    RTEndGlobal

Script_3:
    PokeDexHaveNational 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05F9
    PokeDexGetEvaluationParams 1, 0x8020, 0x8021, 0x8022
    WordSetNumber 0, 0x8021, 3
    SystemMsg 42, 2
    MEPlay 0x8022
    MEWait
    MsgWaitAdvance
    SystemMsg 0x8020, 2
    MsgWaitAdvance
    VMCall L_03C3
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_05F3
    SystemMsg 61, 2
    MsgWaitAdvance

L_05F3:
    VMJump L_0667

L_05F9:
    VMStackPushFlag 141
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_062C
    VMCall L_0142
    SystemMsg 2, 2
    MEPlay 0x8022
    MEWait
    MsgWaitAdvance
    SystemMsg 0x8020, 2
    VMJump L_0646

L_062C:
    VMCall L_0112
    SystemMsg 1, 2
    MEPlay 0x8022
    MEWait
    MsgWaitAdvance
    SystemMsg 0x8020, 2

L_0646:
    VMCall L_02FC
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0667
    SystemMsg 34, 2
    MsgWaitAdvance

L_0667:
    RTEndGlobal
    .balign 4, 0
