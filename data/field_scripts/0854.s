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
    ScriptEntry Script_17
    ScriptEntry Script_18
    ScriptEntry Script_19
    ScriptEntry Script_20
    ScriptEntry Script_21
    ScriptEntry Script_22
    ScriptEntry Script_23
    ScriptEntry Script_24
    ScriptEntry Script_25
    ScriptEntry Script_26
    ScriptEntry Script_27
    ScriptEntry Script_28
    ScriptEntry Script_29
    ScriptEntry Script_30
    ScriptEntry Script_31
    ScriptEntry Script_32
    ScriptEntry Script_33
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_5:
    VMHalt

Script_6:
    VMStackPush 0x40a1
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D1
    ActorSetGPos 3, 42, 1, 751, 3
    ActorSetGPos 0, 43, 1, 751, 2
    VMJump L_0121

L_00D1:
    VMStackPush 0x40a1
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00EA
    VMJump L_0121

L_00EA:
    VMStackPush 0x40a1
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_0121
    ActorSetGPos 2, 49, 1, 740, 2
    ActorSetGPos 1, 38, 1, 740, 3
    ActorSetGPos 3, 38, 1, 741, 3

L_0121:
    VMStackPush 0x40a1
    VMStackPushConst 2
    VMStackCmp 0
    VMStackPush 0x40a8
    VMStackPushConst 1
    VMStackCmp 4
    VMStackCmp 6
    VMJumpIf 255, L_0150
    ActorSetGPos 6, 36, 1, 741, 3

L_0150:
    VMStackPush 0x40a8
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_016F
    ActorSetGPos 2, 42, 1, 741, 2

L_016F:
    VMStackPush 0x40a8
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_018E
    ActorSetGPos 2, 40, 1, 741, 1

L_018E:
    VMStackPush 0x4115
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01B9
    ActorSetGPos 0, 45, 1, 762, 3
    ActorSetGPos 3, 45, 1, 763, 3

L_01B9:
    VMHalt

Script_22:
    ActorsPauseAll
    ActorCmdExec 254, Movement_1F14
    ActorCmdWait
    ActorCmdExec 254, Movement_1EB4
    ActorCmdExec 255, Movement_1EDC
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 17, 254, 0, 0
    MsgWinCloseAll
    FlagReset 745
    ActorAdd 0
    PlayerGetGPos 0x8021, 0x8022
    ActorSetGPos 0, 0x8021, 7, 720, 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 1
    WorkSet 0x8001, 0
    RTCallGlobal 10536
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorDelete 254
    VMStackPush 0x8021
    VMStackPushConst 36
    VMStackCmp 5
    VMJumpIf 255, L_0255
    ActorWalkRoute 0, 36, 720, 0, 8, 1
    ActorCmdWait
    ActorCmdExec 0, Movement_1ED4
    ActorCmdWait

L_0255:
    WorkSetConst 0x40a4, 1
    WorkSetConst 0x40a1, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40a1
    VMStackPushConst 2
    VMStackCmp 3
    VMJumpIf 255, L_029B
    WordSetLoadRivalName 1
    ActorMsg 1024, 18, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02D1

L_029B:
    VMStackPush 0x40a1
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_02C7
    WordSetLoadRivalName 1
    ActorMsg 1024, 29, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02D1

L_02C7:
    BGMPlay 1237
    VMCall L_0B1A

L_02D1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    VMStackPush 0x40a1
    VMStackPushConst 2
    VMStackCmp 3
    VMJumpIf 255, L_02F8
    VMCall L_03EB
    VMJump L_03E5

L_02F8:
    VMStackPush 0x40a1
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0317
    VMCall L_0538
    VMJump L_03E5

L_0317:
    VMStackPush 0x40a1
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0346
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 51, 2, 1, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03E5

L_0346:
    VMStackPush 0x40a1
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_0373
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 59, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_03E5

L_0373:
    VMStackPush 0x40a8
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_03D1
    GameCommCheckDSiWiFi 0x8008
    VMStackPush 0x8008
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03B7
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 106, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_03CB

L_03B7:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 107, 0, 0
    LastKeyWait
    ActorMsgClose

L_03CB:
    VMJump L_03E5

L_03D1:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 58, 0, 0
    LastKeyWait
    ActorMsgClose

L_03E5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_03EB:
    SEPlay 1351
    BGMPlay 1088
    ActorMsg 1024, 20, 2, 1, 0
    MsgWinCloseAll
    PlayerGetDir 0x8020
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_0418
    VMJump L_0426

L_0418:
    ActorCmdExec 2, Movement_1EDC
    VMJump L_0468

L_0426:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_0439
    VMJump L_0447

L_0439:
    ActorCmdExec 2, Movement_1EEC
    VMJump L_0468

L_0447:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_045A
    VMJump L_0468

L_045A:
    ActorCmdExec 2, Movement_1EE4
    VMJump L_0468

L_0468:
    ActorCmdWait
    ActorMsg 1024, 21, 2, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1F14
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 22, 2, 1, 0
    YesNoWin 0x8010
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1F14
    ActorCmdWait
    ActorMsgGendered 1024, 23, 24, 2, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0528
    ActorCmdWait
    ActorMsg 1024, 26, 2, 1, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_050D
    WorkSetConst 0x8023, 1

L_04E4:
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_050D
    ActorMsg 1024, 28, 2, 1, 0
    YesNoWin 0x8023
    VMJump L_04E4

L_050D:
    ActorMsg 1024, 27, 2, 1, 0
    LastKeyWait
    MsgWinCloseAll
    BGMChangeMap
    WorkSetConst 0x40a1, 3
    VMReturn
    .balign 4, 0

Movement_0528:
    Move 100, 1
    MoveEnd
    VMStackAdd
    VMHalt
    .byte 0xfe
    .byte 0x00
    VMNop

L_0538:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 31, 2, 1, 0
    MsgWinCloseAll
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    FadeOutBlackQ
    FadeWait
    FieldClose
    callPoke3Select 0x8024
    FieldOpen
    FadeInWhiteQ
    FadeWait
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_059D
    WorkSetConst 0x4030, 0
    Cmd_0209 8, 3
    WorkSetConst 0x8025, 495
    WordSetPokeSpecies 1, 495
    WordSetPokeSpecies 2, 495
    VMJump L_05EE

L_059D:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05D2
    WorkSetConst 0x4030, 1
    Cmd_0209 8, 1
    WorkSetConst 0x8025, 498
    WordSetPokeSpecies 1, 498
    WordSetPokeSpecies 2, 498
    VMJump L_05EE

L_05D2:
    WorkSetConst 0x4030, 2
    Cmd_0209 8, 2
    WorkSetConst 0x8025, 501
    WordSetPokeSpecies 1, 501
    WordSetPokeSpecies 2, 501

L_05EE:
    MEPlay 1304
    WordSetPlayerName 0
    SystemMsg 43, 1
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    PokePartyAdd 0x8010, 0x8025, 0, 5
    FlagSet 2401
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    ActorMsg 1024, 44, 2, 1, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_064C
    MsgWinCloseAll
    VMCall L_06C6
    VMJump L_0658

L_064C:
    ActorMsg 1024, 45, 2, 1, 0

L_0658:
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0528
    ActorCmdWait
    ActorMsg 1024, 48, 2, 1, 0
    MsgWinCloseAll
    FlagSet 2402
    MEPlay 1303
    TrainerCardGetSex 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_069B
    PlayFieldEffect 63
    VMJump L_069F

L_069B:
    PlayFieldEffect 64

L_069F:
    WordSetPlayerName 0
    SystemMsg 49, 1
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    ActorMsg 1024, 50, 2, 1, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40a1, 4
    VMReturn

L_06C6:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0

L_06D2:
    VMStackPush 0x8026
    VMStackPushConst 555
    VMStackCmp 5
    VMJumpIf 255, L_0758
    FadeOutBlackQ
    FadeWait
    CallPokeNameInput 0x8010, 0, 0
    FadeInBlackQ
    FadeWait
    PokePartyGetParam 0x8027, 0, 117
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_074C
    WordSetPartyPokeName 0, 0
    ActorMsg 1024, 46, 2, 1, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0744
    WorkSetConst 0x8026, 555
    VMJump L_0746

L_0744:
    MsgWinCloseAll

L_0746:
    VMJump L_0752

L_074C:
    WorkSetConst 0x8026, 555

L_0752:
    VMJump L_06D2

L_0758:
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0782
    WordSetPartyPokeName 0, 0
    ActorMsg 1024, 47, 2, 1, 0
    VMJump L_078E

L_0782:
    ActorMsg 1024, 45, 2, 1, 0

L_078E:
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    VMReturn

Script_24:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 94, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07D8
    WordSetPokeSpecies 2, 495
    VMJump L_07FB

L_07D8:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07F6
    WordSetPokeSpecies 2, 498
    VMJump L_07FB

L_07F6:
    WordSetPokeSpecies 2, 501

L_07FB:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 76, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    WordSetLoadRivalName 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 77, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    ActorCmdExec 0, Movement_1F14
    ActorCmdWait
    ActorCmdExec 0, Movement_1EEC
    VMSleep 8
    ActorCmdExec 255, Movement_1EE4
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 19, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_1E9C
    ActorCmdWait
    ActorCmdExec 0, Movement_1ED4
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    ActorCmdExec 0, Movement_1F14
    ActorCmdWait
    ActorCmdExec 0, Movement_1EEC
    VMSleep 8
    ActorCmdExec 255, Movement_1EE4
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 30, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_1E9C
    ActorCmdWait
    ActorCmdExec 0, Movement_1ED4
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_33:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 0, 0x8021, 716, 0, 8, 0
    ActorCmdWait
    PlayerGetDir 0x8010
    VMStackPush 0x8010
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0907
    ActorCmdExec 255, Movement_1EDC
    ActorCmdWait

L_0907:
    WordSetLoadRivalName 1
    ActorMsg 1024, 52, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_1F14
    ActorCmdWait
    ActorCmdExec 0, Movement_1E9C
    ActorCmdWait
    ActorMsg 1024, 53, 0, 0, 0
    MsgWinCloseAll
    WorkCmpConst 0x8021, 36
    VMJumpIf 1, L_094D
    VMJump L_0959

L_094D:
    WorkSetConst 0x8021, 37
    VMJump L_0997

L_0959:
    WorkCmpConst 0x8021, 37
    VMJumpIf 1, L_096C
    VMJump L_0978

L_096C:
    WorkSetConst 0x8021, 36
    VMJump L_0997

L_0978:
    WorkCmpConst 0x8021, 38
    VMJumpIf 1, L_098B
    VMJump L_0997

L_098B:
    WorkSetConst 0x8021, 37
    VMJump L_0997

L_0997:
    ActorWalkRoute 2, 0x8021, 713, 0, 8, 0
    ActorCmdWait
    ActorMsg 1024, 54, 2, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_1EDC
    ActorCmdWait
    ActorCmdExec 0, Movement_1F24
    ActorCmdWait
    VMSleep 30
    ActorWalkRoute 0, 0x8021, 715, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_1ED4
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8021, 36
    VMJumpIf 1, L_0A00
    VMJump L_0A0E

L_0A00:
    ActorCmdExec 255, Movement_1EEC
    VMJump L_0A50

L_0A0E:
    WorkCmpConst 0x8021, 37
    VMJumpIf 1, L_0A21
    VMJump L_0A2F

L_0A21:
    ActorCmdExec 255, Movement_1EE4
    VMJump L_0A50

L_0A2F:
    WorkCmpConst 0x8021, 38
    VMJumpIf 1, L_0A42
    VMJump L_0A50

L_0A42:
    ActorCmdExec 255, Movement_1EE4
    VMJump L_0A50

L_0A50:
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 55, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1F1C
    ActorCmdWait
    ActorMsg 1024, 56, 2, 0, 0
    MsgWinCloseAll
    WordSetLoadRivalName 1
    ActorMsg 1024, 57, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1EE4
    ActorCmdWait
    ActorCmdExec 2, Movement_1F24
    ActorCmdWait
    VMSleep 20
    ActorCmdExec 2, Movement_1EDC
    ActorCmdWait
    ActorMsg 1024, 58, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1E94
    ActorCmdWait
    WorkSetConst 0x40a1, 5
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    ActorCmdExec 0, Movement_1F14
    ActorCmdWait
    BGMPlay 1237
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 0, 0x8021, 715, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_1EDC
    VMSleep 8
    ActorCmdExec 255, Movement_1ED4
    ActorCmdWait
    VMCall L_0B1A
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0B1A:
    WordSetLoadRivalName 1
    WorkCmpConst 0x4030, 0
    VMJumpIf 1, L_0B30
    VMJump L_0B3B

L_0B30:
    WordSetPokeSpecies 3, 498
    VMJump L_0B77

L_0B3B:
    WorkCmpConst 0x4030, 1
    VMJumpIf 1, L_0B4E
    VMJump L_0B59

L_0B4E:
    WordSetPokeSpecies 3, 501
    VMJump L_0B77

L_0B59:
    WorkCmpConst 0x4030, 2
    VMJumpIf 1, L_0B6C
    VMJump L_0B77

L_0B6C:
    WordSetPokeSpecies 3, 495
    VMJump L_0B77

L_0B77:
    ActorCmdExec 2, Movement_1EBC
    ActorCmdExec 0, Movement_1F34
    ActorCmdWait
    ActorMsg 1024, 60, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0BB8
    CallTrainerBattle 161, 0, 1
    VMJump L_0BE1

L_0BB8:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0BD9
    CallTrainerBattle 162, 0, 1
    VMJump L_0BE1

L_0BD9:
    CallTrainerBattle 163, 0, 1

L_0BE1:
    CallTrainerBattleEnd
    WordSetLoadRivalName 1
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C0F
    ActorMsg 1024, 61, 0, 0, 0
    VMJump L_0C1D

L_0C0F:
    PokePartyRecoverAll
    ActorMsg 1024, 62, 0, 0, 0

L_0C1D:
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 37
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 715
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0C5C
    ActorWalkRoute 0, 37, 724, 2, 8, 1
    VMJump L_0C6A

L_0C5C:
    ActorWalkRoute 0, 37, 724, 2, 8, 0

L_0C6A:
    FlagSet 745
    VMSleep 20
    ActorCmdExec 255, Movement_1EDC
    BGMChangeMap
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8021, 36
    VMJumpIf 1, L_0C97
    VMJump L_0CA3

L_0C97:
    WorkAdd 0x8021, 1
    VMJump L_0CE1

L_0CA3:
    WorkCmpConst 0x8021, 37
    VMJumpIf 1, L_0CB6
    VMJump L_0CC2

L_0CB6:
    WorkSub 0x8021, 1
    VMJump L_0CE1

L_0CC2:
    WorkCmpConst 0x8021, 38
    VMJumpIf 1, L_0CD5
    VMJump L_0CE1

L_0CD5:
    WorkSub 0x8021, 1
    VMJump L_0CE1

L_0CE1:
    ActorWalkRoute 2, 0x8021, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorMsg 1024, 63, 2, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8021, 36
    VMJumpIf 1, L_0D18
    VMJump L_0D32

L_0D18:
    ActorCmdExec 2, Movement_1EE4
    VMSleep 8
    ActorCmdExec 255, Movement_1EEC
    VMJump L_0D8C

L_0D32:
    WorkCmpConst 0x8021, 37
    VMJumpIf 1, L_0D45
    VMJump L_0D5F

L_0D45:
    ActorCmdExec 2, Movement_1EEC
    VMSleep 8
    ActorCmdExec 255, Movement_1EE4
    VMJump L_0D8C

L_0D5F:
    WorkCmpConst 0x8021, 38
    VMJumpIf 1, L_0D72
    VMJump L_0D8C

L_0D72:
    ActorCmdExec 2, Movement_1EEC
    VMSleep 8
    ActorCmdExec 255, Movement_1EE4
    VMJump L_0D8C

L_0D8C:
    ActorCmdWait
    ActorMsg 1024, 64, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0E90
    VMSleep 6
    ActorCmdExec 255, Movement_0E90
    VMSleep 10
    FadeEx 3, 0, 16, 4
    FadeExWait
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x308000, 0x1000f, 0x2e48000, 1
    EvCameraWait
    ActorSetGPos 2, 47, 1, 741, 0
    ActorSetGPos 255, 49, 1, 741, 0
    VMSleep 60
    FadeEx 3, 16, 0, 4
    FadeExWait
    ActorMsg 1024, 65, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0E70
    ActorCmdWait
    WorkSetConst 0x8028, 0
    BMCreateHandleByGPos 0x8028, 1, 48, 739
    BMHndAudioVisualAnmPlay 0x8028, 0
    BMHndAnmWait 0x8028
    ActorCmdExec 2, Movement_0E7C
    ActorCmdWait
    ActorDelete 2
    ActorCmdExec 255, Movement_0E84
    ActorCmdWait
    RTReserveScript 3
    MapChangeWarp 435, 7, 19, 0
    EvCameraRebind
    EvCameraEnd
    FlagSet 745
    WorkSetConst 0x8028, 0
    VMReturn

Movement_0E70:
    Move 15, 1
    Move 12, 1
    MoveEnd

Movement_0E7C:
    Move 12, 1
    MoveEnd

Movement_0E84:
    Move 14, 1
    Move 12, 2
    MoveEnd

Movement_0E90:
    Move 168, 6
    MoveEnd

Script_4:
    ActorsPauseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0EB8
    WordSetPokeSpecies 2, 495
    VMJump L_0EDB

L_0EB8:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0ED6
    WordSetPokeSpecies 2, 498
    VMJump L_0EDB

L_0ED6:
    WordSetPokeSpecies 2, 501

L_0EDB:
    ActorCmdExec 2, Movement_1F14
    ActorCmdWait
    ActorCmdExec 255, Movement_1EE4
    ActorCmdWait
    ActorWalkRoute 1, 46, 740, 1, 8, 0
    VMSleep 4
    ActorWalkRoute 3, 46, 741, 1, 8, 0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 66, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_1F14
    ActorCmdWait
    ActorMsg 1024, 67, 1, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 1, 47, 740, 1, 8, 0
    ActorCmdWait
    GiveRunningShoes
    MEPlay 1303
    WordSetPlayerName 0
    SystemMsg 68, 0
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    ActorMsg 1024, 69, 1, 1, 0
    MsgWinCloseAll
    ActorWalkRoute 3, 48, 741, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 3, Movement_1ED4
    VMSleep 8
    ActorCmdExec 255, Movement_1EDC
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 70, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 442
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorCmdExec 2, Movement_1EDC
    ActorCmdWait
    ActorCmdExec 2, Movement_1F1C
    ActorCmdWait
    ActorMsg 1024, 72, 2, 0, 0
    MsgWinCloseAll
    WordSetLoadRivalName 1
    ActorMsg 1024, 73, 3, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1EE4
    ActorCmdWait
    ActorMsg 1024, 74, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_1EEC
    ActorCmdWait
    ActorMsg 1024, 75, 2, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 2, 53, 725, 1, 8, 0
    VMSleep 20
    ActorCmdExec 3, Movement_1EEC
    ActorCmdWait
    ActorDelete 2
    ActorCmdExec 255, Movement_1EE4
    ActorCmdExec 3, Movement_1ED4
    ActorCmdWait
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1077
    WordSetPokeSpecies 2, 495
    VMJump L_109A

L_1077:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1095
    WordSetPokeSpecies 2, 498
    VMJump L_109A

L_1095:
    WordSetPokeSpecies 2, 501

L_109A:
    ActorMsg 1024, 76, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40a1, 7
    FlagSet 742
    FlagSet 740
    FlagSet 803
    Cmd_0262 4, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    ActorMsgGendered 1024, 78, 79, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1EAC
    ActorCmdExec 255, Movement_1524
    ActorCmdWait
    ActorMsg 1024, 80, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1EAC
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 354
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 81, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1530
    ActorCmdWait
    ActorMsg 1024, 82, 2, 0, 0
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x278000, 0x1000f, 0x2e2b000, 24
    SEPlay 1369
    FlagReset 741
    ActorAdd 7
    SEWait
    EvCameraWait
    ActorMsg 1024, 83, 7, 3, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1540
    ActorCmdExec 255, Movement_1ED4
    ActorCmdWait
    ActorMsg 1024, 84, 2, 5, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1ED4
    ActorCmdWait
    ActorMsg 1024, 85, 2, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 86, 7, 3, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 24
    ActorWalkRoute 7, 39, 740, 1, 8, 0
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 7, Movement_1EDC
    VMSleep 8
    ActorCmdExec 255, Movement_1ED4
    ActorCmdWait
    SEPlay 2177
    SEWait
    ActorMsg 1024, 87, 7, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 88, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1EE4
    VMSleep 8
    ActorCmdExec 255, Movement_1EEC
    ActorCmdWait
    SEPlay 2177
    SEWait
    ActorMsg 1024, 89, 2, 0, 0
    MsgWinCloseAll
    Cmd_0263 2
    Cmd_0263 3
    Cmd_0263 0
    MEPlay 1327
    SystemMsg 90, 2
    MEWait
    WordSetPlayerName 0
    SystemMsg 91, 2
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    CallXTransceiver 6, 0
    FadeInBlackQ
    FadeWait
    ActorCmdExec 2, Movement_1F2C
    ActorCmdWait
    ActorMsg 1024, 92, 2, 0, 0
    ActorMsg 1024, 93, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 7, Movement_1EDC
    VMSleep 8
    ActorCmdExec 255, Movement_1ED4
    ActorCmdWait
    ActorMsg 1024, 94, 7, 0, 0
    MsgWinCloseAll
    ActorNew 53, 740, 1, 251, 291, 0
    ActorWalkRoute 251, 41, 740, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 251, Movement_1F14
    VMSleep 8
    ActorCmdExec 7, Movement_1EEC
    VMSleep 8
    ActorCmdExec 2, Movement_1EB4
    ActorCmdExec 255, Movement_1ECC
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 95, 251, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 96, 7, 0, 0
    MsgWinCloseAll
    ActorCmdExec 7, Movement_1548
    VMSleep 8
    ActorCmdExec 255, Movement_1EB4
    ActorCmdWait
    SEPlay 1369
    ActorDelete 7
    SEWait
    ActorCmdExec 251, Movement_1550
    ActorCmdWait
    ActorMsg 1024, 97, 251, 0, 1
    ActorMsgClose
    ActorWalkRoute 251, 39, 738, 4, 4, 0
    ActorCmdWait
    SEPlay 1369
    ActorDelete 251
    SEWait
    ActorMsg 1024, 98, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_1EE4
    VMSleep 8
    ActorCmdExec 255, Movement_1EEC
    ActorCmdWait
    ActorMsg 1024, 99, 2, 0, 0
    MsgWinCloseAll
    VMCall L_1406
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40a8, 3
    WorkSetConst 0x40ab, 1
    WorkSetConst 0x4153, 1
    FlagSet 741
    FlagSet 106
    FlagReset 1032
    Cmd_0262 3, 1
    Cmd_00E7 1
    Cmd_00E7 2
    MedalDiscover 73
    MedalDiscover 174
    MedalDiscover 179
    MedalDiscover 180
    MedalDiscover 195
    MedalDiscover 199
    MedalDiscover 232
    MedalDiscover 233
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_1406:
    MEPlay 1303
    WordSetPlayerName 0
    SystemMsg 100, 2
    MEWait
    MsgWaitAdvance
    CGearControlWarning 1
    WorkSetConst 0x8029, 0

L_1421:
    VMStackPush 0x8029
    VMStackPushConst 555
    VMStackCmp 5
    VMJumpIf 255, L_151B
    SystemMsg 101, 2
    ListMenu_AnchorTopRight 31, 13, 0, 1, 32784
    ListMenuAdd 102, 65535, 0
    ListMenuAdd 103, 65535, 1
    ListMenuShow
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_14C5
    CGearControlWarning 0
    GameCommCheckDSiWiFi 0x8008
    VMStackPush 0x8008
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_14A1
    MsgWinCloseAll
    SEPlay 1358
    CGearPowerOn 1
    SEWait
    ActorMsg 1024, 106, 2, 0, 0
    VMJump L_14B9

L_14A1:
    SystemMsg 105, 2
    MsgWinCloseAll
    CGearPowerOn 0
    ActorMsg 1024, 107, 2, 0, 0

L_14B9:
    WorkSetConst 0x8029, 555
    VMJump L_1515

L_14C5:
    SystemMsg 104, 2
    ListMenu_AnchorTopRight 31, 13, 0, 1, 32784
    ListMenuAdd 102, 65535, 0
    ListMenuAdd 103, 65535, 1
    ListMenuShow
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1515
    MsgWinCloseAll
    CGearControlWarning 0
    CGearPowerOn 0
    ActorMsg 1024, 107, 2, 0, 0
    WorkSetConst 0x8029, 555

L_1515:
    VMJump L_1421

L_151B:
    WorkSetConst 0x8029, 0
    VMReturn
    .balign 4, 0

Movement_1524:
    Move 13, 2
    Move 35, 1
    MoveEnd

Movement_1530:
    Move 32, 1
    Move 63, 3
    Move 34, 1
    MoveEnd

Movement_1540:
    Move 50, 1
    MoveEnd

Movement_1548:
    Move 12, 2
    MoveEnd

Movement_1550:
    Move 42, 4
    MoveEnd

Script_18:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    InfoMsg 0, 2
    MsgWinCloseAll
    ActorWalkRoute 3, 42, 758, 1, 8, 0
    ActorWalkRoute 0, 43, 758, 1, 8, 0
    VMSleep 30
    ActorWalkRoute 255, 43, 760, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_1F34
    ActorCmdWait
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_1F14
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 4, 3, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_1EE4
    ActorCmdWait
    ActorCmdExec 0, Movement_1F24
    ActorCmdWait
    VMSleep 20
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_1EDC
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_1EE4
    VMSleep 8
    ActorCmdExec 3, Movement_1EEC
    ActorCmdWait
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 3, Movement_1EDC
    ActorCmdWait
    ActorMsg 1024, 8, 3, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 3, 43, 751, 0, 8, 0
    ActorCmdExec 0, Movement_1EDC
    VMSleep 16
    ActorMsg 1024, 9, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdWait
    ActorDelete 3
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 41
    VMStackCmp 1
    VMJumpIf 255, L_16B0
    WorkAdd 0x8021, 1
    VMJump L_16B6

L_16B0:
    WorkSub 0x8021, 1

L_16B6:
    ActorWalkRoute 0, 0x8021, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_1EEC
    VMSleep 8
    ActorCmdExec 255, Movement_1EE4
    ActorCmdWait
    ActorMsg 1024, 130, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    WorkSet 0x8000, 0
    WorkSet 0x8001, 2
    WorkSet 0x8002, 1
    WorkSet 0x8003, 0
    WorkSet 0x8004, 10539
    RTCallGlobal 10535
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    WorkSetConst 0x40a1, 1
    FlagSet 744
    FlagSet 745
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    VMCall L_17B9
    WordSetLoadRivalName 1
    ActorMsg 1024, 14, 254, 0, 0
    MsgWinCloseAll
    VMCall L_186F
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    VMCall L_17B9
    WordSetLoadRivalName 1
    ActorMsg 1024, 15, 254, 0, 0
    MsgWinCloseAll
    VMCall L_186F
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    VMCall L_17B9
    WordSetLoadRivalName 1
    ActorMsg 1024, 16, 254, 0, 0
    MsgWinCloseAll
    VMCall L_186F
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_17B9:
    PlayerGetDir 0x8020
    ActorCmdExec 254, Movement_1F14
    ActorCmdWait
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_17DA
    VMJump L_17F0

L_17DA:
    ActorCmdExec 255, Movement_1EEC
    ActorCmdExec 254, Movement_1EC4
    VMJump L_186B

L_17F0:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_1803
    VMJump L_1819

L_1803:
    ActorCmdExec 255, Movement_1EE4
    ActorCmdExec 254, Movement_1ECC
    VMJump L_186B

L_1819:
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_182C
    VMJump L_1842

L_182C:
    ActorCmdExec 255, Movement_1EDC
    ActorCmdExec 254, Movement_1EB4
    VMJump L_186B

L_1842:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_1855
    VMJump L_186B

L_1855:
    ActorCmdExec 255, Movement_1ED4
    ActorCmdExec 254, Movement_1EBC
    VMJump L_186B

L_186B:
    ActorCmdWait
    VMReturn

L_186F:
    ActorPairSetMoveEnable 1
    ActorCmdExec 255, Movement_1E94
    ActorCmdWait
    ActorPairSetMoveEnable 0
    VMReturn

Script_11:
    ActorsPauseAll
    VMStackPush 0x40a8
    VMStackPushConst 1
    VMStackCmp 0
    VMJumpIf 255, L_18B0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 116, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_18C4

L_18B0:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 117, 0, 0
    LastKeyWait
    ActorMsgClose

L_18C4:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_31:
    ActorsPauseAll
    VMStackPush 0x40a8
    VMStackPushConst 1
    VMStackCmp 0
    VMJumpIf 255, L_18F9
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 114, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_190D

L_18F9:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 115, 0, 0
    LastKeyWait
    ActorMsgClose

L_190D:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 118, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 119, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_26:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 120, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_27:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 121, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_28:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 122, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 125, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    WordSetPlayerName 0
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 126, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 127, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    VMStackPush 0x40a8
    VMStackPushConst 1
    VMStackCmp 0
    VMJumpIf 255, L_1A1D
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 128, 2
    MsgPlaceSignClose
    VMJump L_1A2F

L_1A1D:
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 129, 2
    MsgPlaceSignClose

L_1A2F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_25:
    ActorsPauseAll
    ActorCmdExec 255, Movement_1EE4
    ActorCmdWait
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorMsg 1024, 108, 0, 1, 0
    MsgWinCloseAll
    ActorWalkRoute 3, 47, 763, 1, 8, 0
    VMSleep 8
    ActorCmdExec 255, Movement_1EDC
    ActorCmdWait
    ActorCmdExec 3, Movement_1ED4
    ActorCmdWait
    ActorMsg 1024, 109, 3, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 110, 0, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 111, 3, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_1EE4
    ActorCmdExec 3, Movement_1DB0
    ActorMsg 1024, 112, 0, 1, 0
    ActorCmdWait
    MsgWinCloseAll
    ActorCmdExec 0, Movement_1DC0
    ActorCmdExec 3, Movement_1DD0
    ActorCmdWait
    ActorCmdExec 0, Movement_1DE0
    ActorCmdWait
    ActorMsg 1024, 113, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_1DF8
    ActorCmdExec 3, Movement_1DEC
    ActorCmdWait
    ActorDelete 0
    ActorDelete 3
    FlagSet 745
    FlagSet 744
    WorkSetConst 0x4115, 2
    Cmd_0262 0, 10
    Cmd_0262 1, 41
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_29:
    ActorsPauseAll
    ActorNew 45, 763, 3, 251, 357, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_30:
    ActorsPauseAll
    .byte 0xe8
    .byte 0x03
    ActorCmdExec 251, Movement_1E38
    ActorCmdWait
    VMSleep 45
    MEPlay 1327
    MEWait
    ActorCmdExec 251, Movement_1F14
    ActorCmdWait
    ActorCmdExec 251, Movement_1E44
    ActorCmdWait
    ActorMsg 1024, 123, 251, 0, 0
    MsgWinCloseAll
    VMSleep 30
    ActorMsg 1024, 124, 251, 0, 0
    MsgWinCloseAll
    VMSleep 15
    SEPlay 1853
    ActorCmdExec 251, Movement_1E4C
    ActorCmdWait
    SEWait
    ActorWalkRoute 251, 47, 762, 1, 8, 0
    ActorCmdWait
    BMCreateHandleByGPos 0x8010, 1, 47, 761
    BMHndAudioVisualAnmPlay 0x8010, 0
    BMHndAnmWait 0x8010
    ActorCmdExec 251, Movement_1E9C
    ActorCmdWait
    ActorDelete 251
    FadeOutBlack
    RTReserveScript 17
    FadeWait
    MapChangeCore 428, 14, 0, 3, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_32:
    ActorsPauseAll
    .byte 0xf3
    .byte 0x03
    ActorDelete 4
    ActorSetGPos 255, 53, 0, 750, 1
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_1C26
    FadeEx 1, 16, 0, 2
    VMJump L_1C30

L_1C26:
    FadeEx 4, 16, 0, 2

L_1C30:
    ActorCmdExec 255, Movement_1E54
    FadeExWait
    ActorCmdWait
    VMSleep 30
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x2b9000, 0x1000f, 0x2fb8000, 60
    EvCameraWait
    VMSleep 20
    ActorCmdExec 13, Movement_1EF4
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 255, Movement_1E68
    ActorCmdWait
    VMSleep 30
    EvCameraMoveTo 9688, 0, 0xed000, 0x2f8000, 0x1000f, 0x2fa8000, 60
    ActorWalkRoute 13, 46, 763, 0, 16, 0
    VMSleep 4
    ActorWalkRoute 255, 46, 762, 0, 16, 0
    ActorCmdWait
    EvCameraWait
    ActorCmdExec 13, Movement_1EF4
    VMSleep 8
    ActorCmdExec 255, Movement_1EDC
    ActorCmdWait
    VMSleep 60
    ActorWalkRoute 13, 47, 762, 0, 16, 0
    VMSleep 24
    ActorCmdExec 255, Movement_1EEC
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 13, Movement_1EF4
    ActorCmdWait
    BMCreateHandleByGPos 0x8010, 1, 47, 761
    BMHndAudioVisualAnmPlay 0x8010, 0
    BMHndAnmWait 0x8010
    ActorCmdExec 13, Movement_1E70
    VMSleep 8
    ActorCmdExec 255, Movement_1EA4
    ActorCmdWait
    ActorCmdExec 255, Movement_1EFC
    ActorCmdWait
    VMSleep 45
    EvCameraMoveTo 9688, 0, 0xed000, 0x2f8000, 0xb500f, 0x2fa8000, 100
    VMSleep 20
    ActorCmdExec 255, Movement_1E7C
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_1D81
    FadeEx 1, 0, 16, 4
    VMJump L_1D8B

L_1D81:
    FadeEx 4, 0, 16, 4

L_1D8B:
    ActorCmdWait
    BMHndAudioVisualAnmPlay 0x8010, 1
    BMHndAnmWait 0x8010
    BMReleaseHandle 0x8010
    FadeExWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    FlagSet 1007
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_1DB0:
    Move 63, 2
    Move 14, 2
    Move 35, 1
    MoveEnd

Movement_1DC0:
    Move 14, 1
    Move 12, 1
    Move 75, 1
    MoveEnd

Movement_1DD0:
    Move 14, 2
    Move 12, 3
    Move 33, 1
    MoveEnd

Movement_1DE0:
    Move 13, 1
    Move 35, 1
    MoveEnd

Movement_1DEC:
    Move 63, 2
    Move 12, 9
    MoveEnd

Movement_1DF8:
    Move 12, 11
    MoveEnd
    Move 13, 1
    Move 14, 1
    Move 32, 1
    MoveEnd
    VMStackSub
    VMHalt
    Move 32, 1
    MoveEnd
    VMStackSub
    VMHalt
    VMStackDiv
    DebugPrint 12
    VMStackDiscard
    PokePartyGetSpecies 0, 13
    VMHalt
    VMStackDiv
    VMHalt
    .byte 0xfe
    .balign 4, 0

Movement_1E38:
    Move 100, 1
    Move 1, 1
    MoveEnd

Movement_1E44:
    Move 183, 1
    MoveEnd

Movement_1E4C:
    Move 186, 1
    MoveEnd

Movement_1E54:
    Move 13, 2
    Move 14, 10
    Move 13, 2
    Move 9, 2
    MoveEnd

Movement_1E68:
    Move 164, 6
    MoveEnd

Movement_1E70:
    Move 167, 1
    Move 69, 1
    MoveEnd

Movement_1E7C:
    Move 167, 1
    Move 62, 1
    Move 69, 1
    MoveEnd
    Move 154, 1
    MoveEnd

Movement_1E94:
    Move 13, 1
    MoveEnd

Movement_1E9C:
    Move 12, 1
    MoveEnd

Movement_1EA4:
    Move 15, 1
    MoveEnd

Movement_1EAC:
    Move 14, 1
    MoveEnd

Movement_1EB4:
    Move 0, 1
    MoveEnd

Movement_1EBC:
    Move 1, 1
    MoveEnd

Movement_1EC4:
    Move 2, 1
    MoveEnd

Movement_1ECC:
    Move 3, 1
    MoveEnd

Movement_1ED4:
    Move 32, 1
    MoveEnd

Movement_1EDC:
    Move 33, 1
    MoveEnd

Movement_1EE4:
    Move 34, 1
    MoveEnd

Movement_1EEC:
    Move 35, 1
    MoveEnd

Movement_1EF4:
    Move 28, 1
    MoveEnd

Movement_1EFC:
    Move 29, 1
    MoveEnd
    Move 30, 1
    MoveEnd
    Move 31, 1
    MoveEnd

Movement_1F14:
    Move 75, 1
    MoveEnd

Movement_1F1C:
    Move 159, 1
    MoveEnd

Movement_1F24:
    Move 161, 1
    MoveEnd

Movement_1F2C:
    Move 160, 1
    MoveEnd

Movement_1F34:
    Move 100, 1
    MoveEnd
