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

Script_5:
    WorkSetConst 0x8020, 0
    RTCGetSeason 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0069
    Random 0x4003, 9
    WorkAdd 0x4003, 11
    VMJump L_00BF

L_0069:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_008E
    Random 0x4003, 16
    WorkAdd 0x4003, 19
    VMJump L_00BF

L_008E:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00B3
    Random 0x4003, 9
    WorkAdd 0x4003, 11
    VMJump L_00BF

L_00B3:
    Random 0x4003, 9
    WorkAdd 0x4003, 1

L_00BF:
    WorkSetConst 0x8020, 0
    VMHalt

Script_3:
    ActorsPauseAll
    ActorWalkRoute 255, 6, 7, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    ActorMsg 1024, 1, 0, 0, 0
    ActorMsg 1024, 2, 0, 0, 0
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 6, 6, 1, 8, 0
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 422
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 4, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2439
    Cmd_0262 2, 6
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    WorkSetConst 0x8021, 0
    RTCGetSeason 0x8021
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01A5
    InfoMsg 19, 2
    VMJump L_01E6

L_01A5:
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01C3
    InfoMsg 20, 2
    VMJump L_01E6

L_01C3:
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01E1
    InfoMsg 21, 2
    VMJump L_01E6

L_01E1:
    InfoMsg 22, 2

L_01E6:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8021, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    RTCGetSeason 0x8022
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0231
    WordSetNumber 0, 0x4003, 2
    InfoMsg 23, 2
    VMJump L_0287

L_0231:
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0256
    WordSetNumber 0, 0x4003, 2
    InfoMsg 24, 2
    VMJump L_0287

L_0256:
    VMStackPush 0x8022
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_027B
    WordSetNumber 0, 0x4003, 2
    InfoMsg 25, 2
    VMJump L_0287

L_027B:
    WordSetNumber 0, 0x4003, 2
    InfoMsg 26, 2

L_0287:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 426
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0335
    ActorMsg 1024, 7, 8, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_031F
    VMCall L_034B
    VMJump L_032F

L_031F:
    ActorMsg 1024, 12, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_032F:
    VMJump L_0345

L_0335:
    ActorMsg 1024, 13, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0345:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_034B:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    PokePartyGetCount 0x8024, 0
    VMStackPush 0x8024
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_038C
    ActorMsg 1024, 11, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_04A0

L_038C:
    ActorMsg 1024, 8, 8, 0, 0
    MsgWinCloseAll
    RTCGetSeason 0x8025
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03CB
    PokePartyAddEx 0x8010, 585, 0, 30, 3, 2, 0, 0, 4
    VMJump L_044C

L_03CB:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03F8
    PokePartyAddEx 0x8010, 585, 1, 30, 3, 2, 0, 0, 4
    VMJump L_044C

L_03F8:
    VMStackPush 0x8025
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0425
    PokePartyAddEx 0x8010, 585, 2, 30, 3, 2, 0, 0, 4
    VMJump L_044C

L_0425:
    VMStackPush 0x8025
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_044C
    PokePartyAddEx 0x8010, 585, 3, 30, 3, 2, 0, 0, 4

L_044C:
    WordSetPlayerName 0
    MEPlay 1304
    SystemMsg 9, 0
    MEWait
    MsgWaitAdvance
    SystemMsg 10, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_048A
    MsgWinCloseAll
    CallPokeNameInput 0x8026, 0x8024, 1
    VMJump L_048C

L_048A:
    MsgWinCloseAll

L_048C:
    ActorMsg 1024, 13, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 426

L_04A0:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    VMReturn

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 585, 0
    ParentActorMsg 1024, 14, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 585, 0
    ParentActorMsg 1024, 15, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 585, 0
    ParentActorMsg 1024, 16, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 585, 0
    ParentActorMsg 1024, 17, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8030, 0
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8032, 0
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8034, 0
    WorkSetConst 0x8035, 0
    WorkSetConst 0x8036, 0
    WorkSetConst 0x8037, 0
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8039, 0
    WorkSetConst 0x8035, 1
    WorkSetConst 0x8036, 2
    WorkSetConst 0x8037, 3
    WorkSetConst 0x8038, 4
    WorkSetConst 0x8039, 5
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardGetBirthDate 0x8027, 0x8028
    RTCGetDate 0x8029, 0x802a
    VMStackPush 0x8029
    VMStackPush 0x8027
    VMStackCmp 1
    VMStackPush 0x802a
    VMStackPush 0x8028
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0631
    ParentActorMsg 1024, 59, 0, 0

L_0631:
    VMStackPush 0x8029
    VMStackPushConst 12
    VMStackCmp 1
    VMStackPush 0x802a
    VMStackPushConst 31
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_065E
    ParentActorMsg 1024, 60, 0, 0

L_065E:
    PokePartyGetCount 0x802b, 0

L_0664:
    VMStackPush 0x802b
    VMStackPush 0x802c
    VMStackCmp 2
    VMJumpIf 255, L_0B0B
    PokePartyGetParam 0x8030, 0x802c, 10
    PokePartyIsEgg 0x802d, 0x802c
    VMStackPush 0x8030
    VMStackPushConst 70
    VMStackCmp 1
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_06D4
    WorkGet 0x8034, 0x8035
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetLoadAbility 2, 0x8030
    WorkSetConst 0x8032, 1
    VMJump L_0859

L_06D4:
    VMStackPush 0x8030
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0723
    WorkGet 0x8034, 0x8036
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetLoadAbility 2, 0x8030
    WorkSetConst 0x8032, 1
    VMJump L_0859

L_0723:
    VMStackPush 0x8030
    VMStackPushConst 117
    VMStackCmp 1
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0772
    WorkGet 0x8034, 0x8037
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetLoadAbility 2, 0x8030
    WorkSetConst 0x8032, 1
    VMJump L_0859

L_0772:
    VMStackPush 0x8030
    VMStackPushConst 45
    VMStackCmp 1
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_07C1
    WorkGet 0x8034, 0x8038
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetLoadAbility 2, 0x8030
    WorkSetConst 0x8032, 1
    VMJump L_0859

L_07C1:
    VMStackPush 0x8030
    VMStackPushConst 76
    VMStackCmp 1
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0810
    WorkGet 0x8034, 0x8039
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetLoadAbility 2, 0x8030
    WorkSetConst 0x8032, 1
    VMJump L_0859

L_0810:
    VMStackPush 0x8030
    VMStackPushConst 13
    VMStackCmp 1
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0859
    WorkGet 0x8034, 0x8039
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetLoadAbility 2, 0x8030
    WorkSetConst 0x8032, 1

L_0859:
    VMStackPush 0x8032
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0907
    VMStackPush 0x8034
    VMStackPush 0x8035
    VMStackCmp 1
    VMJumpIf 255, L_088B
    VMCall L_0B42
    VMJump L_0901

L_088B:
    VMStackPush 0x8034
    VMStackPush 0x8036
    VMStackCmp 1
    VMJumpIf 255, L_08AA
    VMCall L_0BF6
    VMJump L_0901

L_08AA:
    VMStackPush 0x8034
    VMStackPush 0x8037
    VMStackCmp 1
    VMJumpIf 255, L_08C9
    VMCall L_0CAA
    VMJump L_0901

L_08C9:
    VMStackPush 0x8034
    VMStackPush 0x8038
    VMStackCmp 1
    VMJumpIf 255, L_08E8
    VMCall L_0D5E
    VMJump L_0901

L_08E8:
    VMStackPush 0x8034
    VMStackPush 0x8039
    VMStackCmp 1
    VMJumpIf 255, L_0901
    VMCall L_0E06

L_0901:
    VMJump L_0AFF

L_0907:
    WorkSetConst 0x802f, 0
    PokePartyGetMoveCount 0x802e, 0x802c

L_0913:
    VMStackPush 0x802e
    VMStackPush 0x802f
    VMStackCmp 2
    VMJumpIf 255, L_0AFF
    PokePartyGetMove 0x8031, 0x802c, 0x802f
    PokePartyIsEgg 0x802d, 0x802c
    VMStackPush 0x8031
    VMStackPushConst 241
    VMStackCmp 1
    VMStackPush 0x8033
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0983
    WorkGet 0x8034, 0x8035
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetMoveName 1, 241
    WorkSetConst 0x8033, 1
    VMJump L_0A6A

L_0983:
    VMStackPush 0x8031
    VMStackPushConst 240
    VMStackCmp 1
    VMStackPush 0x8033
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_09D2
    WorkGet 0x8034, 0x8036
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetMoveName 1, 240
    WorkSetConst 0x8033, 1
    VMJump L_0A6A

L_09D2:
    VMStackPush 0x8031
    VMStackPushConst 258
    VMStackCmp 1
    VMStackPush 0x8033
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0A21
    WorkGet 0x8034, 0x8037
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetMoveName 1, 258
    WorkSetConst 0x8033, 1
    VMJump L_0A6A

L_0A21:
    VMStackPush 0x8031
    VMStackPushConst 201
    VMStackCmp 1
    VMStackPush 0x8033
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0A6A
    WorkGet 0x8034, 0x8038
    WordSetPartyPokeSpecies 0, 0x802c
    WordSetMoveName 1, 201
    WorkSetConst 0x8033, 1

L_0A6A:
    VMStackPush 0x8033
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0AF3
    VMStackPush 0x8034
    VMStackPush 0x8035
    VMStackCmp 1
    VMJumpIf 255, L_0A9C
    VMCall L_0B42
    VMJump L_0AF3

L_0A9C:
    VMStackPush 0x8034
    VMStackPush 0x8036
    VMStackCmp 1
    VMJumpIf 255, L_0ABB
    VMCall L_0BF6
    VMJump L_0AF3

L_0ABB:
    VMStackPush 0x8034
    VMStackPush 0x8037
    VMStackCmp 1
    VMJumpIf 255, L_0ADA
    VMCall L_0CAA
    VMJump L_0AF3

L_0ADA:
    VMStackPush 0x8034
    VMStackPush 0x8038
    VMStackCmp 1
    VMJumpIf 255, L_0AF3
    VMCall L_0D5E

L_0AF3:
    WorkAdd 0x802f, 1
    VMJump L_0913

L_0AFF:
    WorkAdd 0x802c, 1
    VMJump L_0664

L_0B0B:
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8033
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0B3C
    ParentActorMsg 1024, 57, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0B3C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0B42:
    VMStackPush 0x8033
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B67
    ParentActorMsg 1024, 27, 0, 0
    MsgWaitAdvance
    VMJump L_0B86

L_0B67:
    VMStackPush 0x8032
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B86
    ParentActorMsg 1024, 28, 0, 0
    MsgWaitAdvance

L_0B86:
    ParentActorMsg 1024, 36, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 37, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 38, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 39, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 40, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 41, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 42, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 56, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x802c, 6
    WorkSetConst 0x802f, 4
    VMReturn

L_0BF6:
    VMStackPush 0x8033
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C1B
    ParentActorMsg 1024, 27, 0, 0
    MsgWaitAdvance
    VMJump L_0C3A

L_0C1B:
    VMStackPush 0x8032
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C3A
    ParentActorMsg 1024, 28, 0, 0
    MsgWaitAdvance

L_0C3A:
    ParentActorMsg 1024, 29, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 30, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 31, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 32, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 33, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 34, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 35, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 56, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x802c, 6
    WorkSetConst 0x802f, 4
    VMReturn

L_0CAA:
    VMStackPush 0x8033
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0CCF
    ParentActorMsg 1024, 27, 0, 0
    MsgWaitAdvance
    VMJump L_0CEE

L_0CCF:
    VMStackPush 0x8032
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0CEE
    ParentActorMsg 1024, 28, 0, 0
    MsgWaitAdvance

L_0CEE:
    ParentActorMsg 1024, 43, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 44, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 45, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 46, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 47, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 48, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 49, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 56, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x802c, 6
    WorkSetConst 0x802f, 4
    VMReturn

L_0D5E:
    VMStackPush 0x8033
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D83
    ParentActorMsg 1024, 27, 0, 0
    MsgWaitAdvance
    VMJump L_0DA2

L_0D83:
    VMStackPush 0x8032
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0DA2
    ParentActorMsg 1024, 28, 0, 0
    MsgWaitAdvance

L_0DA2:
    ParentActorMsg 1024, 50, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 51, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 52, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 53, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 54, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 55, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 56, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x802c, 6
    WorkSetConst 0x802f, 4
    VMReturn

L_0E06:
    ParentActorMsg 1024, 58, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x802c, 6
    VMReturn
