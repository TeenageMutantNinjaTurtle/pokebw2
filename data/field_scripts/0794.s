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

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 20, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PokePartyGetCount 0x8020, 2

L_0094:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_01A9
    PokePartyGetSpecies 0x8022, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 495
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 496
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 497
    VMStackCmp 1
    VMStackCmp 6
    VMStackCmp 6
    VMJumpIf 255, L_00FF
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F9
    WorkSetConst 0x8023, 1

L_00F9:
    VMJump L_019D

L_00FF:
    VMStackPush 0x8022
    VMStackPushConst 498
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 499
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 500
    VMStackCmp 1
    VMStackCmp 6
    VMStackCmp 6
    VMJumpIf 255, L_0151
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_014B
    WorkSetConst 0x8023, 1

L_014B:
    VMJump L_019D

L_0151:
    VMStackPush 0x8022
    VMStackPushConst 501
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 502
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 503
    VMStackCmp 1
    VMStackCmp 6
    VMStackCmp 6
    VMJumpIf 255, L_019D
    VMStackPush 0x4030
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_019D
    WorkSetConst 0x8023, 1

L_019D:
    WorkAdd 0x8021, 1
    VMJump L_0094

L_01A9:
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01D0
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01DE

L_01D0:
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01DE:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0221
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_022F

L_0221:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_022F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 531, 0
    ParentActorMsg 1024, 7, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    InfoMsg 19, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2766
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0320
    VMStackPushFlag 333
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0308
    ParentActorMsg 1024, 8, 0, 0
    MsgWaitAdvance
    FlagSet 333
    VMJump L_0314

L_0308:
    ParentActorMsg 1024, 9, 0, 0
    MsgWaitAdvance

L_0314:
    VMCall L_0334
    VMJump L_032E

L_0320:
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_032E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0334:
    PokePartyGetCount 0x8020, 0

L_033A:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_05BD
    PokePartyGetSpecies 0x8022, 0x8021
    PokePartyIsEgg 0x8028, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 50
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_038D
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 50
    VMJump L_05B1

L_038D:
    VMStackPush 0x8022
    VMStackPushConst 177
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03C1
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 177
    VMJump L_05B1

L_03C1:
    VMStackPush 0x8022
    VMStackPushConst 298
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03F5
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 298
    VMJump L_05B1

L_03F5:
    VMStackPush 0x8022
    VMStackPushConst 406
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0429
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 406
    VMJump L_05B1

L_0429:
    VMStackPush 0x8022
    VMStackPushConst 412
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0498
    PokePartyGetParam 0x8027, 0x8021, 111
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8027
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 6
    VMStackCmp 6
    VMJumpIf 255, L_0492
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 412

L_0492:
    VMJump L_05B1

L_0498:
    VMStackPush 0x8022
    VMStackPushConst 433
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_04CC
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 433
    VMJump L_05B1

L_04CC:
    VMStackPush 0x8022
    VMStackPushConst 492
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_051B
    PokePartyGetParam 0x8027, 0x8021, 111
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0515
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 492

L_0515:
    VMJump L_05B1

L_051B:
    VMStackPush 0x8022
    VMStackPushConst 590
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_054F
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 590
    VMJump L_05B1

L_054F:
    VMStackPush 0x8022
    VMStackPushConst 595
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0583
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 595
    VMJump L_05B1

L_0583:
    VMStackPush 0x8022
    VMStackPushConst 602
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_05B1
    WorkSetConst 0x8024, 1
    WordSetPokeSpeciesWithArticle 0, 602

L_05B1:
    WorkAdd 0x8021, 1
    VMJump L_033A

L_05BD:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0616
    ParentActorMsg 1024, 10, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 63
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2766
    VMJump L_0624

L_0616:
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0624:
    VMReturn

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2767
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0682
    VMStackPushFlag 334
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_066A
    ParentActorMsg 1024, 13, 0, 0
    MsgWaitAdvance
    FlagSet 334
    VMJump L_0676

L_066A:
    ParentActorMsg 1024, 14, 0, 0
    MsgWaitAdvance

L_0676:
    VMCall L_0696
    VMJump L_0690

L_0682:
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0690:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0696:
    PokePartyGetCount 0x8020, 0

L_069C:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_08B0
    PokePartyGetSpecies 0x8022, 0x8021
    PokePartyIsEgg 0x8028, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 95
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_06EF
    WorkSetConst 0x8025, 1
    WordSetPokeSpeciesWithArticle 0, 95
    VMJump L_08A4

L_06EF:
    VMStackPush 0x8022
    VMStackPushConst 130
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0723
    WorkSetConst 0x8025, 1
    WordSetPokeSpeciesWithArticle 0, 130
    VMJump L_08A4

L_0723:
    VMStackPush 0x8022
    VMStackPushConst 208
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0757
    WorkSetConst 0x8025, 1
    WordSetPokeSpeciesWithArticle 0, 208
    VMJump L_08A4

L_0757:
    VMStackPush 0x8022
    VMStackPushConst 249
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_078B
    WorkSetConst 0x8025, 1
    WordSetPokeSpeciesWithArticle 0, 249
    VMJump L_08A4

L_078B:
    VMStackPush 0x8022
    VMStackPushConst 321
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_07BF
    WorkSetConst 0x8025, 1
    WordSetPokeSpeciesWithArticle 0, 321
    VMJump L_08A4

L_07BF:
    VMStackPush 0x8022
    VMStackPushConst 350
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_07F3
    WorkSetConst 0x8025, 1
    WordSetPokeSpeciesWithArticle 0, 350
    VMJump L_08A4

L_07F3:
    VMStackPush 0x8022
    VMStackPushConst 384
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0827
    WorkSetConst 0x8025, 1
    WordSetPokeSpeciesWithArticle 0, 384
    VMJump L_08A4

L_0827:
    VMStackPush 0x8022
    VMStackPushConst 483
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_085B
    WorkSetConst 0x8025, 1
    WordSetPokeSpeciesWithArticle 0, 483
    VMJump L_08A4

L_085B:
    VMStackPush 0x8022
    VMStackPushConst 487
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_08A4
    PokePartyGetParam 0x8027, 0x8021, 111
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_08A4
    WorkSetConst 0x8025, 1
    WordSetPokeSpeciesWithArticle 0, 487

L_08A4:
    WorkAdd 0x8021, 1
    VMJump L_069C

L_08B0:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0909
    ParentActorMsg 1024, 15, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 64
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2767
    VMJump L_0917

L_0909:
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0917:
    VMReturn
    .balign 4, 0
