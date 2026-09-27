#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0

Script_1:
    ActorsPauseAll
    DebugPrint 0x4188
    WorkCmpConst 0x4188, 2
    VMJumpIf 1, L_0049
    VMJump L_0096

L_0049:
    WorkSetConst 0x8027, 0
    Cmd_0266 0x8027
    VMStackPush 0x8027
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0072
    VMCall L_0B62
    VMJump L_008E

L_0072:
    TrainerCardGetSex 0x8010
    WorkSetConst 0x8026, 4
    WorkAdd 0x8026, 0x8010
    WorkSetConst 0x8023, 373
    VMCall L_0161

L_008E:
    Cmd_0267
    VMJump L_0155

L_0096:
    WorkCmpConst 0x4188, 1
    VMJumpIf 1, L_00A9
    VMJump L_014F

L_00A9:
    RTCGetWeekDay 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_00C0
    VMJump L_00CC

L_00C0:
    WorkSetConst 0x8026, 0
    VMJump L_0133

L_00CC:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_00DF
    VMJump L_00EB

L_00DF:
    WorkSetConst 0x8026, 1
    VMJump L_0133

L_00EB:
    WorkCmpConst 0x8010, 5
    VMJumpIf 1, L_00FE
    VMJump L_010E

L_00FE:
    WorkSetConst 0x8026, 2
    FlagSet 484
    VMJump L_0133

L_010E:
    WorkCmpConst 0x8010, 6
    VMJumpIf 1, L_0121
    VMJump L_012D

L_0121:
    WorkSetConst 0x8026, 3
    VMJump L_0133

L_012D:
    WorkSetConst 0x8026, 0

L_0133:
    WorkSetConst 0x8023, 369
    WorkAdd 0x8023, 0x8026
    VMCall L_0161
    FlagSet 2773
    VMJump L_0155

L_014F:
    VMCall L_069B

L_0155:
    WorkSetConst 0x8027, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0161:
    WorkSetConst 0x8028, 0
    FlagGet 0x8023, 0x8025
    DebugPrint 0x8023
    DebugPrint 0x8026
    DebugPrint 0x8025
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    WorkSet 0x8000, 80
    WorkSet 0x8001, 0x8026
    WorkSet 0x8002, 0x8025
    WorkMul 0x8001, 4
    WorkMul 0x8002, 2
    WorkAdd 0x8000, 0x8001
    WorkAdd 0x8000, 0x8002
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x8000, 0, 0
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsgClose
    BGMPlay 1103
    ActorCmdExec 0x8011, Movement_09E4
    ActorCmdWait
    WorkSetConst 0x8028, 9
    WorkAdd 0x8028, 0x8026
    VMStackPush 0x4188
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0216
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0216
    WorkAdd 0x8028, 2

L_0216:
    FadeOutBlackQ
    FadeWait
    FieldClose
    Call3DDemo 3, 0x8028
    FieldOpen
    ActorSetGPos 255, 54, 1, 16, 0
    ActorSetGPos 0x8011, 54, 1, 15, 1
    ActorSetEyeToEye
    FadeInBlackQ
    FadeWait
    BGMChangeMap
    WorkSetConst 0x8029, 0
    Cmd_0266 0x8029
    VMStackPush 0x4188
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_028E
    PokeDexHaveNational 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8029
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_028E
    VMCall L_045E

L_028E:
    WorkSetConst 0x8029, 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    WorkSet 0x8000, 81
    WorkSet 0x8001, 0x8026
    WorkSet 0x8002, 0x8025
    WorkMul 0x8001, 4
    WorkMul 0x8002, 2
    WorkAdd 0x8000, 0x8001
    WorkAdd 0x8000, 0x8002
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x8000, 0, 0
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    LastKeyWait
    ActorMsgClose
    ActorWalkRoute 0x8011, 45, 15, 0, 8, 1
    VMStackPush 0x4188
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0314
    VMSleep 20
    ActorCmdExec 255, Movement_0CE0

L_0314:
    ActorCmdWait
    ActorDelete 0x8011
    FlagSet 0x8023
    Cmd_02C5 21
    VMCall L_0A10
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03D2
    VMStackPushFlag 417
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 491
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_037A
    Cmd_0262 1, 41
    VMJump L_03D2

L_037A:
    VMStackPushFlag 417
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 491
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03A9
    Cmd_0262 1, 42
    VMJump L_03D2

L_03A9:
    VMStackPushFlag 417
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 491
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03D2
    Cmd_0262 1, 43

L_03D2:
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03FB
    Cmd_0262 3, 0

L_03FB:
    VMStackPush 0x8026
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0456
    VMStackPush 0x4111
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_043D
    Cmd_0262 2, 14
    VMJump L_0456

L_043D:
    VMStackPush 0x4111
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0456
    Cmd_0262 2, 0

L_0456:
    WorkSetConst 0x8028, 0
    VMReturn

L_045E:
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    TrainerCardGetSex 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0493
    WorkSetConst 0x802a, 104
    VMJump L_0499

L_0493:
    WorkSetConst 0x802a, 107

L_0499:
    TrainerCardGetSex 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04BC
    WorkSetConst 0x802b, 12
    VMJump L_04C2

L_04BC:
    WorkSetConst 0x802b, 0

L_04C2:
    WorkAdd 0x802b, 0x4189
    FieldTradeGetSpecies 0x802c, 0x802b
    WordSetPokeSpecies 1, 0x802c
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x802a, 0, 0
    YesNoWin 0x8010
    ActorMsgClose
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0623
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8030, 0
    WorkSetConst 0x8030, 1

L_0517:
    VMStackPush 0x8030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05BD
    CallPokeSelect 0, 0x802f, 0x802d, 0
    VMStackPush 0x802f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05AB
    WorkSetConst 0x8031, 0
    FieldTradeCheck 0x8031, 0x802b, 0x802d
    VMStackPush 0x8031
    VMStackPushConst 4
    VMStackCmp 5
    VMJumpIf 255, L_059D
    WordSetPartyPokeSpecies 2, 0x802d
    WordSetPokeSpecies 1, 0x802c
    SystemMsg 120, 2
    YesNoWin 0x8010
    InfoMsgClose
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0597
    WorkSetConst 0x8030, 0

L_0597:
    VMJump L_05A5

L_059D:
    SystemMsg 121, 2
    InfoMsgClose

L_05A5:
    VMJump L_05B1

L_05AB:
    WorkSetConst 0x8030, 0

L_05B1:
    WorkSetConst 0x8031, 0
    VMJump L_0517

L_05BD:
    VMStackPush 0x802f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_061D
    WordSetPokeSpecies 1, 0x802c
    WordSetPlayerName 0
    WorkAdd 0x802a, 1
    ParentActorMsg 1024, 0x802a, 0, 0
    ActorMsgClose
    PokePartyGetParam 0x802e, 0x802d, 5
    FieldTradeStart 0x802b, 0x802d
    WorkAdd 0x4189, 1
    VMStackPush 0x4189
    VMStackPushConst 12
    VMStackCmp 4
    VMJumpIf 255, L_0617
    WorkSetConst 0x4189, 0

L_0617:
    Cmd_02C3 0x802e
    VMReturn

L_061D:
    VMJump L_0623

L_0623:
    WordSetPokeSpecies 1, 0x802c
    WordSetPlayerName 0
    WorkAdd 0x802a, 2
    ParentActorMsg 1024, 0x802a, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x8030, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802a, 0
    VMReturn
    WorkSetConst 0x8032, 0
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8034, 0
    CallPokeSelect 0, 0x8034, 0x8032, 0
    WorkSetConst 0x8034, 0
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8032, 0
    VMReturn

L_069B:
    WorkSetConst 0x8035, 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    RTCGetSeason 0x8000
    TrainerCardGetSex 0x8001
    WorkSet 0x8021, 0x8000
    WorkMul 0x8021, 2
    WorkAdd 0x8021, 0x8001
    VMStackPop 0x8001
    VMStackPop 0x8000
    Cmd_0220 0x8021, 0x8022
    TrainerFlagGet 0x8022, 0x8024
    RTCGetSeason 0x8035
    WorkSetConst 0x8023, 229
    WorkAdd 0x8023, 0x8035
    FlagGet 0x8023, 0x8025
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0701
    WorkSetConst 0x8035, 0
    VMReturn

L_0701:
    WorkSetConst 0x8036, 0
    WorkSetConst 0x8037, 0
    DebugPrint 0x8021
    DebugPrint 0x8024
    DebugPrint 0x8025
    FlagGet 2740, 0x8036
    VMStackPush 0x8036
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0787
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    WorkSet 0x8000, 4
    WorkSet 0x8001, 0x8021
    WorkSet 0x8002, 0x8025
    WorkMul 0x8001, 10
    WorkMul 0x8002, 5
    WorkAdd 0x8000, 0x8001
    WorkAdd 0x8000, 0x8002
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x8000, 0, 0
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    LastKeyWait
    ActorMsgClose
    VMReturn

L_0787:
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    WorkSet 0x8000, 0
    WorkSet 0x8001, 0x8021
    WorkSet 0x8002, 0x8024
    WorkMul 0x8001, 10
    WorkMul 0x8002, 5
    WorkAdd 0x8000, 0x8001
    WorkAdd 0x8000, 0x8002
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x8000, 0, 0
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    YesNoWin 0x8036
    VMStackPush 0x8036
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0842
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    WorkSet 0x8000, 2
    WorkSet 0x8001, 0x8021
    WorkSet 0x8002, 0x8024
    WorkMul 0x8001, 10
    WorkMul 0x8002, 5
    WorkAdd 0x8000, 0x8001
    WorkAdd 0x8000, 0x8002
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x8000, 0, 0
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    LastKeyWait
    ActorMsgClose
    VMReturn

L_0842:
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    WorkSet 0x8000, 1
    WorkSet 0x8001, 0x8021
    WorkSet 0x8002, 0x8024
    WorkMul 0x8001, 10
    WorkMul 0x8002, 5
    WorkAdd 0x8000, 0x8001
    WorkAdd 0x8000, 0x8002
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x8000, 0, 0
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsgClose
    CallTrainerBattle 0x8022, 0, 0
    TrainerBattleIsVictory 0x8036
    VMStackPush 0x8036
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08BC
    CallTrainerLose
    VMReturn
    VMJump L_08BE

L_08BC:
    CallTrainerBattleEnd

L_08BE:
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    WorkSet 0x8000, 3
    WorkSet 0x8001, 0x8021
    WorkSet 0x8002, 0x8024
    WorkMul 0x8001, 10
    WorkMul 0x8002, 5
    WorkAdd 0x8000, 0x8001
    WorkAdd 0x8000, 0x8002
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x8000, 0, 0
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsgClose
    BGMPlay 1103
    ActorCmdExec 0x8011, Movement_09E4
    ActorCmdWait
    WorkGet 0x8037, 0x8021
    WorkAdd 0x8037, 1
    FadeOutBlackQ
    FadeWait
    FieldClose
    Call3DDemo 3, 0x8037
    FieldOpen
    ActorSetGPos 0x8011, 54, 1, 15, 1
    ActorSetEyeToEye
    FadeInBlackQ
    FadeWait
    BGMChangeMap
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    WorkSet 0x8000, 4
    WorkSet 0x8001, 0x8021
    WorkSet 0x8002, 0x8024
    WorkMul 0x8001, 10
    WorkMul 0x8002, 5
    WorkAdd 0x8000, 0x8001
    WorkAdd 0x8000, 0x8002
    WordSetPlayerName 0
    ParentActorMsg 1024, 0x8000, 0, 0
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    LastKeyWait
    ActorMsgClose
    Cmd_02C5 21
    FlagSet 2740
    TrainerFlagGet 0x8022, 0x8036
    VMStackPush 0x8036
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_09C9
    FlagSet 0x8023
    VMJump L_09CD

L_09C9:
    TrainerFlagSet 0x8022

L_09CD:
    VMCall L_0A10
    WorkSetConst 0x8037, 0
    WorkSetConst 0x8036, 0
    VMReturn
    .balign 4, 0

Movement_09E4:
    Move 8, 1
    MoveEnd
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0

L_0A10:
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8039, 0
    WorkSetConst 0x803a, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803c, 0
    TrainerCardGetSex 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A7B
    Cmd_0220 0, 0x803c
    TrainerFlagGet 0x803c, 0x8038
    Cmd_0220 2, 0x803c
    TrainerFlagGet 0x803c, 0x8039
    Cmd_0220 4, 0x803c
    TrainerFlagGet 0x803c, 0x803a
    Cmd_0220 6, 0x803c
    TrainerFlagGet 0x803c, 0x803b
    VMJump L_0AAB

L_0A7B:
    Cmd_0220 1, 0x803c
    TrainerFlagGet 0x803c, 0x8038
    Cmd_0220 3, 0x803c
    TrainerFlagGet 0x803c, 0x8039
    Cmd_0220 5, 0x803c
    TrainerFlagGet 0x803c, 0x803a
    Cmd_0220 7, 0x803c
    TrainerFlagGet 0x803c, 0x803b

L_0AAB:
    VMStackPush 0x8038
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8039
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x803a
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x803b
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 369
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 370
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 371
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 372
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 373
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0B42
    MedalGive 181

L_0B42:
    WorkSetConst 0x803c, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803a, 0
    WorkSetConst 0x8039, 0
    WorkSetConst 0x8038, 0
    VMReturn

L_0B62:
    WorkSetConst 0x803d, 0
    SEPlay 1351
    ActorSetEyeToEye
    WordSetPlayerName 0
    ActorCmdExec 0x8011, Movement_0CF0
    ActorCmdWait
    ActorMsgGendered 1024, 110, 115, 0x8011, 0, 0
    MsgWinCloseAll
    TrainerCardGetSex 0x803d
    SEPlay 2017
    WorkCmpConst 0x803d, 0
    VMJumpIf 1, L_0BA6
    VMJump L_0BB2

L_0BA6:
    SystemMsg 111, 2
    VMJump L_0BD1

L_0BB2:
    WorkCmpConst 0x803d, 1
    VMJumpIf 1, L_0BC5
    VMJump L_0BD1

L_0BC5:
    SystemMsg 116, 2
    VMJump L_0BD1

L_0BD1:
    InfoMsgClose
    SEWait
    WorkCmpConst 0x803d, 0
    VMJumpIf 1, L_0BE8
    VMJump L_0BF6

L_0BE8:
    ItemSub 637, 1, 0x8010
    VMJump L_0C17

L_0BF6:
    WorkCmpConst 0x803d, 1
    VMJumpIf 1, L_0C09
    VMJump L_0C17

L_0C09:
    ItemSub 636, 1, 0x8010
    VMJump L_0C17

L_0C17:
    ActorMsgGendered 1024, 112, 117, 0x8011, 0, 0
    MsgWinCloseAll
    WorkCmpConst 0x803d, 0
    VMJumpIf 1, L_0C3A
    VMJump L_0C46

L_0C3A:
    SystemMsg 113, 2
    VMJump L_0C65

L_0C46:
    WorkCmpConst 0x803d, 1
    VMJumpIf 1, L_0C59
    VMJump L_0C65

L_0C59:
    SystemMsg 118, 2
    VMJump L_0C65

L_0C65:
    SEPlay 2177
    SEWait
    InfoMsgClose
    ActorMsgGendered 1024, 114, 119, 0x8011, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0C94
    VMJump L_0CA8

L_0C94:
    ActorWalkRoute 0x8011, 45, 16, 0, 8, 1
    VMJump L_0CB6

L_0CA8:
    ActorWalkRoute 0x8011, 45, 15, 0, 8, 1

L_0CB6:
    VMSleep 20
    ActorCmdExec 255, Movement_0CE0
    ActorCmdWait
    ActorDelete 0x8011
    WorkSetConst 0x803d, 0
    VMReturn
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd

Movement_0CE0:
    Move 2, 1
    MoveEnd
    Move 3, 1
    MoveEnd

Movement_0CF0:
    Move 75, 1
    MoveEnd
