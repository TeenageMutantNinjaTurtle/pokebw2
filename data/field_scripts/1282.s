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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8023, 0
    WorkGet 0x8023, 0x8000
    VMStackPush 0x8000
    WorkSet 0x8000, 0x8023
    RTCallGlobal 2816
    VMStackPop 0x8000
    WorkSetConst 0x8023, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    VMCall L_0106
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    VMCall L_0144
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    VMCall L_01F7
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMCall L_04AE
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    VMCall L_05B3
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    VMCall L_08DE
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    VMCall L_0A3B
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    VMCall L_0AFF
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    VMCall L_0B90
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_00E6:
    FadeEx 3, 0, 16, 2
    FadeExWait
    VMSleep 8
    FunfestActorDelete
    FadeEx 3, 16, 0, 2
    FadeExWait
    VMReturn

L_0106:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    SystemMsg 2, 0
    MsgWinCloseAll
    ParentActorMsg 1024, 3, 0, 0
    MsgWinCloseAll
    FunfestMissionBroadcast 30, 0
    VMCall L_00E6
    SystemMsg 4, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_0144:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    SEPlay 1351
    ActorSetEyeToEye
    FunfestGetGenericInfo 0, 0x8024
    WordSetItemName 0, 0x8024
    ParentActorMsg 1024, 5, 0, 0
    YesNoWin 0x8025
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0192
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_0192:
    ItemSub 0x8024, 1, 0x8025
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01BD
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_01BD:
    ParentActorMsg 1024, 8, 0, 0
    MsgWinCloseAll
    FunfestMissionBroadcast 31, 0x8024
    SystemMsg 9, 0
    MsgWinCloseAll
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    VMCall L_00E6
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    VMReturn

L_01F7:
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0220
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0218
    VMReturn

L_0218:
    VMCall L_00E6
    VMReturn

L_0220:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    FunfestDispSalesmanMessage 15, 9, 2
    Random 0x8029, 6
    Random 0x802a, 6
    WorkSetConst 0x8026, 0

L_025E:
    VMStackPush 0x8026
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_03F8
    FunfestGetItemExchangeInfo 0x8029, 0x802a, 0x8027, 0x8028
    WordSetItemName 0, 0x8027
    WordSetItemName 1, 0x8028
    FunfestDispSalesmanMessage 16, 9, 2
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32811
    ListMenuAdd 12, 65535, 2
    ListMenuAdd 13, 65535, 1
    ListMenuAdd 14, 65535, 0
    ListMenuShow
    VMStackPush 0x802b
    VMStackPushConst 65534
    VMStackCmp 1
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_02ED
    FunfestDispSalesmanMessage 17, 9, 2
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8020, 0
    VMReturn
    VMJump L_0398

L_02ED:
    VMStackPush 0x802b
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0398
    ItemCheckAmount 0x8027, 1, 0x802b
    VMStackPush 0x802b
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_032F
    FunfestDispSalesmanMessage 20, 9, 2
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8020, 0
    VMReturn

L_032F:
    ItemAdd 0x8028, 1, 0x802b
    VMStackPush 0x802b
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_035E
    FunfestDispSalesmanMessage 21, 9, 2
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8020, 0
    VMReturn

L_035E:
    FunfestDispSalesmanMessage 22, 9, 2
    MsgWinCloseAll
    ItemSub 0x8027, 1, 0x802b
    FunfestMissionBroadcast 32, 0
    MEPlay 1302
    SystemMsg 11, 0
    MEWait
    MsgWaitAdvance
    MsgWinCloseAll
    FunfestDispSalesmanMessage 23, 9, 2
    MsgWinCloseAll
    WorkSetConst 0x8020, 1
    VMReturn

L_0398:
    WorkGet 0x8021, 0x8026
    VMCall L_041E
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03C5
    FunfestDispSalesmanMessage 19, 9, 2
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_03C5:
    FunfestDispSalesmanMessage 18, 9, 2
    WorkAdd 0x802a, 1
    VMStackPush 0x802a
    VMStackPushConst 6
    VMStackCmp 4
    VMJumpIf 255, L_03EC
    WorkSetConst 0x802a, 0

L_03EC:
    WorkAdd 0x8026, 1
    VMJump L_025E

L_03F8:
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    VMReturn

L_041E:
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    WorkGet 0x802c, 0x8021
    WorkSetConst 0x8020, 0
    Random 0x802d, 10000
    VMStackPush 0x802c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_046A
    VMStackPush 0x802d
    VMStackPushConst 6000
    VMStackCmp 4
    VMJumpIf 255, L_0464
    VMReturn

L_0464:
    VMJump L_049A

L_046A:
    VMStackPush 0x802c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0498
    VMStackPush 0x802d
    VMStackPushConst 3000
    VMStackCmp 4
    VMJumpIf 255, L_0492
    VMReturn

L_0492:
    VMJump L_049A

L_0498:
    VMReturn

L_049A:
    WorkSetConst 0x8020, 1
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802c, 0
    VMReturn

L_04AE:
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8030, 0
    SEPlay 1351
    ActorSetEyeToEye
    FunfestGetItemSaleInfo 0x802e, 0x802f
    MoneyWinDisp 31, 1
    WordSetItemName 0, 0x802e
    WordSetNumber 1, 0x802f, 5
    FunfestDispSalesmanMessage 34, 6, 2
    YesNoWin 0x8030
    VMStackPush 0x8030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_050D
    FunfestDispSalesmanMessage 35, 6, 2
    LastKeyWait
    MsgWinCloseAll
    MoneyWinClose
    VMReturn

L_050D:
    MoneyCheck 0x8030, 0x802f
    VMStackPush 0x8030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_053C
    FunfestMissionBroadcast 39, 0
    FunfestDispSalesmanMessage 36, 6, 2
    LastKeyWait
    MsgWinCloseAll
    MoneyWinClose
    VMReturn

L_053C:
    ItemAdd 0x802e, 1, 0x8030
    VMStackPush 0x8030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0567
    FunfestDispSalesmanMessage 37, 6, 2
    LastKeyWait
    MsgWinCloseAll
    MoneyWinClose
    VMReturn

L_0567:
    FunfestDispSalesmanMessage 38, 6, 2
    MsgWinCloseAll
    MoneySub 0x802f
    FunfestMissionBroadcast 33, 0x802e
    SEPlay 1621
    MoneyWinUpdate
    SystemMsg 33, 2
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    FunfestDispSalesmanMessage 39, 6, 2
    MsgWinCloseAll
    MoneyWinClose
    VMCall L_00E6
    WorkSetConst 0x8030, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x802e, 0
    VMReturn

L_05B3:
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0602
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_05E8
    FunfestMissionBroadcast 40, 0
    ParentActorMsg 1024, 53, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_05E8:
    FunfestMissionBroadcast 34, 0
    ParentActorMsg 1024, 54, 0, 0
    MsgWinCloseAll
    VMCall L_00E6
    VMReturn

L_0602:
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8032, 0
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8034, 0
    WorkSetConst 0x8035, 0
    WorkSetConst 0x8036, 0
    ParentActorMsg 1024, 49, 2, 0
    WorkSetConst 0x8031, 1

L_0636:
    VMStackPush 0x8031
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0760
    Random 0x8035, 3
    ListMenu_AnchorTopRight 31, 1, 0, 0, 32820
    ListMenuAdd 46, 65535, 0
    ListMenuAdd 47, 65535, 1
    ListMenuAdd 48, 65535, 2
    ListMenuShow
    MsgWinCloseAll
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0692
    ScreamMsg 50, 2
    VMJump L_0697

L_0692:
    ScreamMsg 52, 2

L_0697:
    WorkGet 0x8021, 0x8034
    WorkGet 0x8022, 0x8035
    VMCall L_0786
    InfoMsgClose_0039
    WorkCmpConst 0x8034, 0
    VMJumpIf 1, L_06BE
    VMJump L_06CA

L_06BE:
    WorkSetConst 0x8036, 1
    VMJump L_0708

L_06CA:
    WorkCmpConst 0x8034, 2
    VMJumpIf 1, L_06DD
    VMJump L_06E9

L_06DD:
    WorkSetConst 0x8036, 0
    VMJump L_0708

L_06E9:
    WorkCmpConst 0x8034, 1
    VMJumpIf 1, L_06FC
    VMJump L_0708

L_06FC:
    WorkSetConst 0x8036, 2
    VMJump L_0708

L_0708:
    VMStackPush 0x8034
    VMStackPush 0x8035
    VMStackCmp 1
    VMJumpIf 255, L_0731
    ParentActorMsg 1024, 51, 2, 0
    WorkSetConst 0x8032, 1
    VMJump L_075A

L_0731:
    VMStackPush 0x8035
    VMStackPush 0x8036
    VMStackCmp 1
    VMJumpIf 255, L_0752
    WorkSetConst 0x8020, 1
    VMReturn
    VMJump L_075A

L_0752:
    WorkSetConst 0x8020, 0
    VMReturn

L_075A:
    VMJump L_0636

L_0760:
    WorkSetConst 0x8036, 0
    WorkSetConst 0x8035, 0
    WorkSetConst 0x8034, 0
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8032, 0
    WorkSetConst 0x8031, 0
    VMReturn

L_0786:
    WorkSetConst 0x8037, 0
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8039, 0
    WorkSetConst 0x803a, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803c, 0
    WorkSetConst 0x803d, 0
    WorkGet 0x8038, 0x8021
    WorkAdd 0x8038, 46
    WorkGet 0x8039, 0x8022
    WorkAdd 0x8039, 46
    PlayerGetDir 0x8037
    WorkCmpConst 0x8037, 0
    VMJumpIf 1, L_07DF
    VMJump L_07FD

L_07DF:
    WorkSetConst 0x803a, 8
    WorkSetConst 0x803b, 14
    WorkSetConst 0x803c, 22
    WorkSetConst 0x803d, 8
    VMJump L_0890

L_07FD:
    WorkCmpConst 0x8037, 1
    VMJumpIf 1, L_0810
    VMJump L_082E

L_0810:
    WorkSetConst 0x803a, 22
    WorkSetConst 0x803b, 8
    WorkSetConst 0x803c, 8
    WorkSetConst 0x803d, 14
    VMJump L_0890

L_082E:
    WorkCmpConst 0x8037, 2
    VMJumpIf 1, L_0841
    VMJump L_085F

L_0841:
    WorkSetConst 0x803a, 22
    WorkSetConst 0x803b, 8
    WorkSetConst 0x803c, 7
    WorkSetConst 0x803d, 8
    VMJump L_0890

L_085F:
    WorkCmpConst 0x8037, 3
    VMJumpIf 1, L_0872
    VMJump L_0890

L_0872:
    WorkSetConst 0x803a, 7
    WorkSetConst 0x803b, 8
    WorkSetConst 0x803c, 22
    WorkSetConst 0x803d, 8
    VMJump L_0890

L_0890:
    MultiMsg 0x8038, 0x803a, 0x803b, 0
    MultiMsg 0x8039, 0x803c, 0x803d, 1
    VMSleep 16
    MsgWaitAdvance
    MsgWinCloseNo 0
    MsgWinCloseNo 1
    WorkSetConst 0x803d, 0
    WorkSetConst 0x803c, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803a, 0
    WorkSetConst 0x8039, 0
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8037, 0
    VMReturn

L_08DE:
    WorkSetConst 0x803e, 0
    WorkSetConst 0x803f, 0
    WorkSetConst 0x8040, 0
    WorkSetConst 0x8041, 0
    WorkSetConst 0x8042, 0
    WorkSetConst 0x8043, 0
    WorkSetConst 0x8044, 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 62, 2, 0
    FunfestGetPokemonQuizInfo 0x8040, 0x8041, 0x8042
    WorkSetConst 0x803f, 0

L_0926:
    VMStackPush 0x803f
    VMStackPush 0x8040
    VMStackCmp 0
    VMJumpIf 255, L_0964
    FunfestGetPokemonQuizSpecies 0x803f, 0x8044
    WordSetPokeSpecies 0, 0x8044
    PVPlay 0x8044, 0
    ParentActorMsg 1024, 56, 2, 0
    PVWait
    MsgWaitAdvance
    WorkAdd 0x803f, 1
    VMJump L_0926

L_0964:
    WorkGet 0x8043, 0x8041
    WorkAdd 0x8043, 1
    WordSetNumber 6, 0x8043, 2
    ParentActorMsg 1024, 63, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 0, 32830
    WorkSetConst 0x803f, 0

L_0990:
    VMStackPush 0x803f
    VMStackPushConst 5
    VMStackCmp 0
    VMJumpIf 255, L_09C2
    FunfestGetPokemonQuizBogusSpecies 0x803f, 0x8044
    WordSetPokeSpecies 1, 0x8044
    ListMenuAdd 57, 65535, 0x803f
    WorkAdd 0x803f, 1
    VMJump L_0990

L_09C2:
    ListMenuShow
    VMStackPush 0x803e
    VMStackPush 0x8042
    VMStackCmp 5
    VMJumpIf 255, L_09ED
    FunfestMissionBroadcast 41, 0
    ParentActorMsg 1024, 64, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_09ED:
    FunfestMissionBroadcast 35, 0
    ParentActorMsg 1024, 65, 2, 0
    ParentActorMsg 1024, 66, 2, 0
    MsgWinCloseAll
    VMCall L_00E6
    WorkSetConst 0x8044, 0
    WorkSetConst 0x8043, 0
    WorkSetConst 0x8042, 0
    WorkSetConst 0x8041, 0
    WorkSetConst 0x8040, 0
    WorkSetConst 0x803f, 0
    WorkSetConst 0x803e, 0
    VMReturn

L_0A3B:
    WorkSetConst 0x8045, 0
    WorkSetConst 0x8046, 0
    WorkSetConst 0x8047, 0
    SEPlay 1351
    ActorSetEyeToEye
    FunfestGetGenericInfo 0, 0x8046
    FunfestDispSalesmanMessage 67, 6, 0
    YesNoWin 0x8045
    VMStackPush 0x8045
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A86
    FunfestDispSalesmanMessage 68, 6, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_0A86:
    FunfestDispSalesmanMessage 69, 6, 0
    MsgWinCloseAll
    WorkSetConst 0x8047, 4
    WorkOr 0x8047, 1
    CallTrainerBattle 0x8046, 0, 0x8047
    CallTrainerBattleEnd
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0ACD
    PokePartyRecoverAll
    FunfestDispSalesmanMessage 72, 6, 0
    VMJump L_0AE3

L_0ACD:
    FunfestMissionBroadcast 36, 0
    FunfestDispSalesmanMessage 70, 6, 0
    FunfestDispSalesmanMessage 71, 6, 0

L_0AE3:
    MsgWinCloseAll
    VMCall L_00E6
    WorkSetConst 0x8047, 0
    WorkSetConst 0x8046, 0
    WorkSetConst 0x8045, 0
    VMReturn

L_0AFF:
    WorkSetConst 0x8048, 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 85, 0, 0
    FunfestGetGenericInfo 0, 0x8048
    ItemCheckSpace 0x8048, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B4E
    WordSetItemNameEx 0, 0x8048, 2, 0
    ParentActorMsg 1024, 87, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_0B4E:
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 0x8048
    WorkSet 0x8001, 1
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 86, 0, 0
    MsgWinCloseAll
    FunfestMissionBroadcast 37, 0x8048
    VMCall L_00E6
    WorkSetConst 0x8048, 0
    VMReturn

L_0B90:
    WorkSetConst 0x8049, 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 88, 0, 0
    MsgWinCloseAll
    FunfestGetGenericInfo 0, 0x8049
    PVPlay 0x8049, 0
    CallPokemonPreview 0x8049, 0, 0, 0
    PVWait
    ParentActorMsg 1024, 89, 0, 0
    MsgWinCloseAll
    CallWordSetPokeNameInput 0x8049, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_0C26
    FunfestMissionBroadcast 41, 0
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0C10
    ParentActorMsg 1024, 90, 0, 0
    VMJump L_0C20

L_0C10:
    SEPlay 1691
    ParentActorMsg 1024, 91, 0, 0
    SEWait

L_0C20:
    LastKeyWait
    MsgWinCloseAll
    VMReturn

L_0C26:
    SEPlay 1690
    ParentActorMsg 1024, 92, 0, 0
    SEWait
    ParentActorMsg 1024, 93, 0, 0
    MsgWinCloseAll
    FunfestMissionBroadcast 38, 0
    VMCall L_00E6
    WorkSetConst 0x8049, 0
    VMReturn
    .balign 4, 0
