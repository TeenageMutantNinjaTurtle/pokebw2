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
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0

Script_1:
    VMCall L_004C
    RTEndGlobal

L_004C:
    ActorMsg 1024, 17, 0x8011, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0081
    ActorMsg 1024, 18, 0x8011, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_0081:
    MoveTutorCheckParty 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00B2
    ActorMsg 1024, 20, 0x8011, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_00D7

L_00B2:
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00D7
    ActorMsg 1024, 19, 0x8011, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_00D7:
    ActorMsg 1024, 21, 0x8011, 0, 0
    ActorMsgClose
    MoveTutorCallPokeSelect 0, 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0112
    ActorMsg 1024, 18, 0x8011, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_0112:
    PokePartyIsEgg 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_013D
    ActorMsg 1024, 23, 0x8011, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_013D:
    MoveTutorCheckPkm 0, 0x8020, 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0158
    VMJump L_0170

L_0158:
    ActorMsg 1024, 19, 0x8011, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_01CB

L_0170:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0183
    VMJump L_019B

L_0183:
    ActorMsg 1024, 22, 0x8011, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_01CB

L_019B:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_01AE
    VMJump L_01CB

L_01AE:
    WordSetMoveName 0, 434
    ActorMsg 1024, 24, 0x8011, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_01CB

L_01CB:
    WorkSetConst 0x8021, 434
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 1
    VMCall L_098A
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0206
    ActorMsg 1024, 25, 0x8011, 0, 0
    LastKeyWait
    ActorMsgClose

L_0206:
    VMReturn

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_021C
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_021C:
    ParentActorMsg 1024, 26, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_024D
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_024D:
    MoveTutorCheckParty 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_027C
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_029F

L_027C:
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_029F
    ParentActorMsg 1024, 33, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_029F:
    ParentActorMsg 1024, 30, 0, 0
    ActorMsgClose
    MoveTutorCallPokeSelect 1, 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02D6
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_02D6:
    PokePartyIsEgg 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02FF
    ParentActorMsg 1024, 32, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_02FF:
    MoveTutorCheckPkm 1, 0x8020, 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_031A
    VMJump L_0330

L_031A:
    ParentActorMsg 1024, 33, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_0382

L_0330:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0343
    VMJump L_0359

L_0343:
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_0382

L_0359:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_036C
    VMJump L_0382

L_036C:
    ParentActorMsg 1024, 34, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_0382

L_0382:
    MoveTutorGetMoveID 1, 0x8020, 0x8021
    WordSetPartyPokeName 0, 0x8020
    WordSetMoveName 1, 0x8021
    ParentActorMsg 1024, 35, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03C5
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_03C5:
    ActorMsgClose
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    VMCall L_098A
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03EC

L_03EC:
    VMReturn

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0402
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0402:
    VMStackPushFlag 253
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0429
    ParentActorMsg 1024, 37, 0, 0
    FlagSet 253
    VMJump L_0433

L_0429:
    ParentActorMsg 1024, 38, 0, 0

L_0433:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_045A
    ParentActorMsg 1024, 40, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_045A:
    MoveTutorCheckParty 2, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0489
    ParentActorMsg 1024, 39, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_04AC

L_0489:
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_04AC
    ParentActorMsg 1024, 44, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_04AC:
    ParentActorMsg 1024, 41, 0, 0
    ActorMsgClose
    MoveTutorCallPokeSelect 2, 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04E3
    ParentActorMsg 1024, 40, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_04E3:
    PokePartyIsEgg 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_050C
    ParentActorMsg 1024, 43, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_050C:
    MoveTutorCheckPkm 2, 0x8020, 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0527
    VMJump L_053D

L_0527:
    ParentActorMsg 1024, 44, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_058F

L_053D:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0550
    VMJump L_0566

L_0550:
    ParentActorMsg 1024, 42, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_058F

L_0566:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0579
    VMJump L_058F

L_0579:
    ParentActorMsg 1024, 45, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    VMJump L_058F

L_058F:
    MoveTutorGetMoveID 2, 0x8020, 0x8021
    WordSetPartyPokeName 0, 0x8020
    WordSetMoveName 1, 0x8021
    ParentActorMsg 1024, 46, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05D2
    ParentActorMsg 1024, 40, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_05D2:
    ActorMsgClose
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    VMCall L_098A
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05F9

L_05F9:
    VMReturn

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 72
    VMStackPushFlag 325
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0638
    WordSetItemNameEx 0, 0x8024, 2, 0
    ParentActorMsg 1024, 48, 0, 0
    FlagSet 325
    VMJump L_0642

L_0638:
    ParentActorMsg 1024, 49, 0, 0

L_0642:
    VMCall L_0747
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 73
    VMStackPushFlag 326
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_068B
    WordSetItemNameEx 0, 0x8024, 2, 0
    ParentActorMsg 1024, 48, 0, 0
    FlagSet 326
    VMJump L_0695

L_068B:
    ParentActorMsg 1024, 49, 0, 0

L_0695:
    VMCall L_0747
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 74
    VMStackPushFlag 327
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06DE
    WordSetItemNameEx 0, 0x8024, 2, 0
    ParentActorMsg 1024, 48, 0, 0
    FlagSet 327
    VMJump L_06E8

L_06DE:
    ParentActorMsg 1024, 49, 0, 0

L_06E8:
    VMCall L_0747
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 75
    VMStackPushFlag 328
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0731
    WordSetItemNameEx 0, 0x8024, 2, 0
    ParentActorMsg 1024, 48, 0, 0
    FlagSet 328
    VMJump L_073B

L_0731:
    ParentActorMsg 1024, 49, 0, 0

L_073B:
    VMCall L_0747
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0747:
    ParentActorMsg 1024, 50, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0780
    WordSetItemNameEx 0, 0x8024, 2, 0
    ParentActorMsg 1024, 52, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_0780:
    ParentActorMsg 1024, 51, 0, 0
    WorkSetConst 0x400c, 0
    WorkSetConst 0x400d, 0
    WorkSetConst 0x400e, 0
    WorkSetConst 0x400f, 0
    WorkCmpConst 0x8024, 72
    VMJumpIf 1, L_07B5
    VMJump L_07DB

L_07B5:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 246
    WorkSet 0x8001, 0
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0886

L_07DB:
    WorkCmpConst 0x8024, 73
    VMJumpIf 1, L_07EE
    VMJump L_0814

L_07EE:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 245
    WorkSet 0x8001, 0
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0886

L_0814:
    WorkCmpConst 0x8024, 74
    VMJumpIf 1, L_0827
    VMJump L_084D

L_0827:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 244
    WorkSet 0x8001, 0
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0886

L_084D:
    WorkCmpConst 0x8024, 75
    VMJumpIf 1, L_0860
    VMJump L_0886

L_0860:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 243
    WorkSet 0x8001, 0
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0886

L_0886:
    DebugPrint 0x400c
    DebugPrint 0x400d
    DebugPrint 0x400e
    DebugPrint 0x400f
    VMStackPush 0x400c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08C1
    WordSetItemNameEx 0, 0x8024, 2, 0
    ParentActorMsg 1024, 52, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_08C1:
    VMStackPush 0x400c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_08E4
    ParentActorMsg 1024, 54, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_08E4:
    PokePartyHasMove 0x8010, 0x400d, 0x400e
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_090F
    ParentActorMsg 1024, 55, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_090F:
    WorkGet 0x8021, 0x400d
    WorkGet 0x8020, 0x400e
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 1
    VMCall L_098A
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0956
    WordSetItemNameEx 0, 0x8024, 2, 0
    ParentActorMsg 1024, 52, 0, 0
    LastKeyWait
    ActorMsgClose

L_0956:
    VMReturn

Script_8:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 47, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0

L_098A:
    WorkSetConst 0x8028, 0
    PokePartyGetMoveCount 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 4
    VMStackCmp 5
    VMJumpIf 255, L_0A39
    WordSetPartyPokeName 0, 0x8020
    WordSetMoveName 1, 0x8021
    MEPlay 1301
    SystemMsg 10, 0
    MEWait
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09DA
    LastKeyWait
    VMJump L_09DC

L_09DA:
    MsgWaitAdvance

L_09DC:
    VMStackPush 0x400c
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 2
    VMStackCmp 7
    VMJumpIf 255, L_0A2D
    WorkSetConst 0x8029, 0
    ItemSub 0x8024, 0x400f, 0x8029
    WordSetPlayerName 0
    WordSetItemNameEx 1, 0x8024, 0x400f, 0
    WordSetNumber 2, 0x400f, 2
    SystemMsg 53, 0
    LastKeyWait
    WorkSetConst 0x8029, 0

L_0A2D:
    InfoMsgClose
    PokePartyLearnMove 0x8020, 0x8010, 0x8021
    VMReturn

L_0A39:
    WorkSetConst 0x8027, 1

L_0A3F:
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0AA8
    VMCall L_0B0B
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A7D
    WorkSetConst 0x8010, 1
    WorkSetConst 0x8027, 0
    VMJump L_0AA2

L_0A7D:
    VMCall L_0AAA
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0AA2
    WorkSetConst 0x8010, 0
    WorkSetConst 0x8027, 0

L_0AA2:
    VMJump L_0A3F

L_0AA8:
    VMReturn

L_0AAA:
    WordSetMoveName 0, 0x8021
    SystemMsg 12, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B03
    WordSetPartyPokeName 0, 0x8020
    WordSetMoveName 1, 0x8021
    SystemMsg 13, 0
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0AF7
    LastKeyWait
    VMJump L_0AF9

L_0AF7:
    MsgWaitAdvance

L_0AF9:
    InfoMsgClose
    WorkSetConst 0x8028, 1
    VMReturn

L_0B03:
    WorkSetConst 0x8028, 0
    VMReturn

L_0B0B:
    WorkSetConst 0x8028, 0
    WordSetPartyPokeName 0, 0x8020
    WordSetMoveName 1, 0x8021
    SystemMsg 11, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B3A
    VMReturn

L_0B3A:
    InfoMsgClose
    CallPokeMoveReplace 0x8010, 0x8025, 0x8020, 0x8021
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B5B
    VMReturn

L_0B5B:
    PokePartyGetMove 0x8026, 0x8020, 0x8025
    WordSetMoveName 0, 0x8026
    SystemMsg 14, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B87
    VMReturn

L_0B87:
    PokePartyGetMove 0x8026, 0x8020, 0x8025
    WordSetPartyPokeName 0, 0x8020
    WordSetMoveName 1, 0x8026
    WordSetMoveName 2, 0x8021
    SystemMsg 15, 0
    SystemMsg 16, 0
    MEPlay 1301
    MEWait
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0BCB
    LastKeyWait
    VMJump L_0BCD

L_0BCB:
    MsgWaitAdvance

L_0BCD:
    VMStackPush 0x400c
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 2
    VMStackCmp 7
    VMJumpIf 255, L_0C1E
    WorkSetConst 0x802a, 0
    ItemSub 0x8024, 0x400f, 0x802a
    WordSetPlayerName 0
    WordSetItemNameEx 1, 0x8024, 0x400f, 0
    WordSetNumber 2, 0x400f, 2
    SystemMsg 53, 0
    LastKeyWait
    WorkSetConst 0x802a, 0

L_0C1E:
    InfoMsgClose
    PokePartyLearnMove 0x8020, 0x8025, 0x8021
    WorkSetConst 0x8028, 1
    VMReturn
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0

Script_9:
    WorkGet 0x8020, 0x8000
    WorkGet 0x8021, 0x8001
    WorkSetConst 0x8022, 1
    WorkSetConst 0x8023, 1
    VMCall L_098A
    RTEndGlobal
    VMHalt
    .balign 4, 0
