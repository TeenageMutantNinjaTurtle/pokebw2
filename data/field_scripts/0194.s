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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_9:
    VMHalt

Script_10:
    TrainerCardHasBadge 0x8008, 4
    VMStackPush 0x8008
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00AE
    ActorSetGPos 0, 9, 0, 84, 1
    VMStackPushFlag 1001
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00AE
    ActorSetGPos 7, 11, 1, 72, 1

L_00AE:
    VMHalt

Script_2:
    ActorsPauseAll
    Cmd_0186
    FadeInBlack
    Cmd_018D 0
    FadeWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 4
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02E9
    ActorMsg 1024, 0, 7, 0, 0
    ActorMsgClose
    WorkSetConst 0x8021, 0
    GameGetDifficulty 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_011C
    CallTrainerBattle 768, 0, 0
    VMJump L_0124

L_011C:
    CallTrainerBattle 158, 0, 0

L_0124:
    WorkSetConst 0x8021, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0149
    CallTrainerBattleEnd
    VMJump L_014B

L_0149:
    CallTrainerLose

L_014B:
    ActorMsg 1024, 1, 7, 0, 0
    ActorMsgClose
    TrainerCardSaveGymVictoryParty 4
    TrainerCardAddBadge 4
    MEPlay 1306
    WorkSetConst 0x8022, 0
    TrainerCardGetSex 0x8022
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_018C
    PlayFieldEffect 7
    VMJump L_0190

L_018C:
    PlayFieldEffect 59

L_0190:
    MEWait
    WorkSetConst 0x8022, 0
    WordSetPlayerName 0
    SystemMsg 2, 0
    InfoMsgClose
    ActorMsg 1024, 3, 7, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 405
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    TrainerFlagSet 319
    TrainerFlagSet 320
    TrainerFlagSet 321
    TrainerFlagSet 322
    TrainerFlagSet 323
    TrainerFlagSet 324
    TrainerFlagSet 325
    FlagSet 2418
    ActorCmdExec 7, Movement_073C
    ActorCmdWait
    VMSleep 30
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0216
    VMJump L_0224

L_0216:
    ActorCmdExec 7, Movement_072C
    VMJump L_0245

L_0224:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0237
    VMJump L_0245

L_0237:
    ActorCmdExec 7, Movement_0734
    VMJump L_0245

L_0245:
    ActorCmdWait
    ActorMsg 1024, 5, 7, 0, 0
    ActorMsgClose
    ActorCmdExec 7, Movement_06A4
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0270
    VMJump L_028C

L_0270:
    ActorCmdExec 255, Movement_0690
    ActorCmdWait
    VMSleep 10
    ActorCmdExec 255, Movement_072C
    VMJump L_02B1

L_028C:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_029F
    VMJump L_02B1

L_029F:
    VMSleep 10
    ActorCmdExec 255, Movement_06A4
    VMJump L_02B1

L_02B1:
    ActorCmdWait
    FadeOutBlack
    Cmd_018D 2
    FadeWait
    SEPlay 1738
    VMSleep 40
    SEStop
    SEPlay 1738
    VMSleep 40
    SEStop
    SEPlay 1738
    RTReserveScript 3
    MapChangeCore 98, 6, 0, 4, 1
    VMJump L_0322

L_02E9:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0312
    ActorMsg 1024, 6, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0322

L_0312:
    ActorMsg 1024, 4, 7, 0, 0
    LastKeyWait
    ActorMsgClose

L_0322:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 4
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03B4
    VMStackPushFlag 111
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03A0
    ParentActorMsg 1024, 21, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 30
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 111
    VMJump L_03AE

L_03A0:
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose

L_03AE:
    VMJump L_03C2

L_03B4:
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose

L_03C2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    VMCall L_04B0
    SEPlay 1740
    SEWait
    VMCall L_04C2
    Cmd_018C 0, 0
    VMCall L_058C
    Cmd_018C 0, 1
    VMCall L_0656
    SEWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    WorkSetConst 0x8020, 1
    VMCall L_04B0
    SEPlay 1740
    SEWait
    VMCall L_04C2
    Cmd_018C 1, 0
    VMCall L_058C
    Cmd_018C 1, 1
    VMCall L_0656
    SEWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    WorkSetConst 0x8020, 2
    VMCall L_04B0
    SEPlay 1740
    SEWait
    VMCall L_04C2
    Cmd_018C 2, 0
    VMCall L_058C
    Cmd_018C 2, 1
    VMCall L_0656
    SEWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    WorkSetConst 0x8020, 3
    VMCall L_04B0
    SEPlay 1740
    SEWait
    VMCall L_04C2
    Cmd_018C 3, 0
    VMCall L_058C
    Cmd_018C 3, 1
    VMCall L_0656
    SEWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_04B0:
    SEPlay 1351
    WordSetPlayerName 0
    InfoMsg 24, 2
    MsgWaitAdvance
    MsgWinCloseAll
    VMReturn

L_04C2:
    EvCameraInit
    EvCameraUnbind
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_04D9
    VMJump L_04F7

L_04D9:
    EvCameraMoveTo 10840, 0, 0xed000, 0x110000, 0xc6000, 0x1be000, 30
    VMJump L_058A

L_04F7:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_050A
    VMJump L_0528

L_050A:
    EvCameraMoveTo 10840, 0, 0xed000, 0x2f0000, 0xc6000, 0x1be000, 30
    VMJump L_058A

L_0528:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_053B
    VMJump L_0559

L_053B:
    EvCameraMoveTo 10840, 0, 0xed000, 0x110000, 0xc6000, 0x3ce000, 30
    VMJump L_058A

L_0559:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_056C
    VMJump L_058A

L_056C:
    EvCameraMoveTo 10840, 0, 0xed000, 0x2f0000, 0xc6000, 0x3ce000, 30
    VMJump L_058A

L_058A:
    VMReturn

L_058C:
    EvCameraWait
    LastKeyWait
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_05A3
    VMJump L_05C1

L_05A3:
    EvCameraMoveTo 9688, 0, 0xed000, 0x118000, 0, 0x1d8000, 30
    VMJump L_0654

L_05C1:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_05D4
    VMJump L_05F2

L_05D4:
    EvCameraMoveTo 9688, 0, 0xed000, 0x2f8000, 0, 0x1d8000, 30
    VMJump L_0654

L_05F2:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_0605
    VMJump L_0623

L_0605:
    EvCameraMoveTo 9688, 0, 0xed000, 0x118000, 0, 0x3e8000, 30
    VMJump L_0654

L_0623:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_0636
    VMJump L_0654

L_0636:
    EvCameraMoveTo 9688, 0, 0xed000, 0x2f8000, 0, 0x3e8000, 30
    VMJump L_0654

L_0654:
    VMReturn

L_0656:
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMReturn

Script_8:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1740
    InfoMsg 24, 2
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    FadeOutBlack
    Cmd_018D 1
    FadeWait
    RTReserveScript 2
    MapChangeCore 98, 8, 0, 4, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0690:
    Move 3, 1
    Move 73, 1
    Move 14, 1
    Move 74, 1
    MoveEnd

Movement_06A4:
    Move 13, 1
    MoveEnd

Movement_06AC:
    Move 12, 1
    MoveEnd

Movement_06B4:
    Move 15, 1
    MoveEnd
    VMStackMul
    VMNop2
    PokePartyGetSpecies 0, 13
    VMHalt
    PokePartyGetSpecies 0, 12
    VMHalt
    .byte 0xfe
    .balign 4, 0

Movement_06D4:
    Move 15, 2
    MoveEnd
    VMStackMul
    VMHalt
    .byte 0xfe
    .balign 4, 0
    Move 13, 3
    MoveEnd
    Move 12, 3
    MoveEnd

Movement_06F4:
    Move 15, 3
    MoveEnd

Movement_06FC:
    Move 14, 3
    MoveEnd

Movement_0704:
    Move 0, 1
    MoveEnd

Movement_070C:
    Move 1, 1
    MoveEnd

Movement_0714:
    Move 2, 1
    MoveEnd

Movement_071C:
    Move 3, 1
    MoveEnd

Movement_0724:
    Move 32, 1
    MoveEnd

Movement_072C:
    Move 33, 1
    MoveEnd

Movement_0734:
    Move 34, 1
    MoveEnd

Movement_073C:
    Move 35, 1
    MoveEnd

Movement_0744:
    Move 189, 1
    MoveEnd

Script_11:
    ActorsPauseAll
    VMStackPush 0x40b9
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07C4
    SEPlay 1351
    ActorSetEyeToEye
    ActorCmdExec 6, Movement_0744
    TrainerBGMPlayPush 324
    ActorCmdWait
    ParentActorMsg 1024, 7, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 324, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07A8
    CallTrainerBattleEnd
    VMJump L_07AA

L_07A8:
    CallTrainerLose

L_07AA:
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40b9, 1
    VMJump L_07D8

L_07C4:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose

L_07D8:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    ActorCmdExec 6, Movement_0744
    TrainerBGMPlayPush 324
    ActorCmdWait
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    PlayerGetGPos 0x8023, 0x8024
    WorkCmpConst 0x8023, 5
    VMJumpIf 1, L_0813
    VMJump L_0821

L_0813:
    ActorCmdExec 6, Movement_071C
    VMJump L_088C

L_0821:
    WorkCmpConst 0x8023, 6
    VMJumpIf 1, L_0834
    VMJump L_0842

L_0834:
    ActorCmdExec 6, Movement_06B4
    VMJump L_088C

L_0842:
    WorkCmpConst 0x8023, 7
    VMJumpIf 1, L_0855
    VMJump L_0863

L_0855:
    ActorCmdExec 6, Movement_06D4
    VMJump L_088C

L_0863:
    WorkCmpConst 0x8023, 8
    VMJumpIf 1, L_0876
    VMJump L_0884

L_0876:
    ActorCmdExec 6, Movement_06F4
    VMJump L_088C

L_0884:
    ActorCmdExec 6, Movement_0724

L_088C:
    ActorCmdWait
    ActorCmdExec 255, Movement_0714
    ActorCmdWait
    ActorMsg 1024, 7, 6, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 324, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_08CD
    CallTrainerBattleEnd
    VMJump L_08CF

L_08CD:
    CallTrainerLose

L_08CF:
    ActorMsg 1024, 8, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40b9, 1
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    VMStackPush 0x40ba
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_096F
    SEPlay 1351
    ActorSetEyeToEye
    ActorCmdExec 1, Movement_0744
    TrainerBGMPlayPush 323
    ActorCmdWait
    ParentActorMsg 1024, 9, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 323, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0953
    CallTrainerBattleEnd
    VMJump L_0955

L_0953:
    CallTrainerLose

L_0955:
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40ba, 1
    VMJump L_0983

L_096F:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose

L_0983:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    ActorCmdExec 1, Movement_0744
    TrainerBGMPlayPush 323
    ActorCmdWait
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    PlayerGetGPos 0x8025, 0x8026
    WorkCmpConst 0x8026, 61
    VMJumpIf 1, L_09BE
    VMJump L_09CC

L_09BE:
    ActorCmdExec 1, Movement_06AC
    VMJump L_09D4

L_09CC:
    ActorCmdExec 1, Movement_0724

L_09D4:
    ActorCmdWait
    ActorCmdExec 255, Movement_070C
    ActorCmdWait
    ActorMsg 1024, 9, 1, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 323, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A15
    CallTrainerBattleEnd
    VMJump L_0A17

L_0A15:
    CallTrainerLose

L_0A17:
    ActorMsg 1024, 10, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40ba, 1
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    VMStackPush 0x40bb
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0AB7
    SEPlay 1351
    ActorSetEyeToEye
    ActorCmdExec 2, Movement_0744
    TrainerBGMPlayPush 321
    ActorCmdWait
    ParentActorMsg 1024, 15, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 321, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A9B
    CallTrainerBattleEnd
    VMJump L_0A9D

L_0A9B:
    CallTrainerLose

L_0A9D:
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40bb, 1
    VMJump L_0ACB

L_0AB7:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose

L_0ACB:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    ActorCmdExec 2, Movement_0744
    TrainerBGMPlayPush 321
    ActorCmdWait
    ActorCmdExec 255, Movement_0704
    ActorCmdWait
    ActorMsg 1024, 15, 2, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 321, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B20
    CallTrainerBattleEnd
    VMJump L_0B22

L_0B20:
    CallTrainerLose

L_0B22:
    ActorMsg 1024, 16, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40bb, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    VMStackPush 0x40bc
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0BB6
    SEPlay 1351
    ActorSetEyeToEye
    ActorCmdExec 3, Movement_0744
    TrainerBGMPlayPush 322
    ActorCmdWait
    ParentActorMsg 1024, 11, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 322, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B9A
    CallTrainerBattleEnd
    VMJump L_0B9C

L_0B9A:
    CallTrainerLose

L_0B9C:
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40bc, 1
    VMJump L_0BCA

L_0BB6:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose

L_0BCA:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    ActorCmdExec 3, Movement_0744
    TrainerBGMPlayPush 322
    ActorCmdWait
    ActorCmdExec 3, Movement_06F4
    ActorCmdWait
    ActorMsg 1024, 11, 3, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 322, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C1F
    CallTrainerBattleEnd
    VMJump L_0C21

L_0C1F:
    CallTrainerLose

L_0C21:
    ActorMsg 1024, 12, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40bc, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    VMStackPush 0x40bd
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0CB5
    SEPlay 1351
    ActorSetEyeToEye
    ActorCmdExec 4, Movement_0744
    TrainerBGMPlayPush 320
    ActorCmdWait
    ParentActorMsg 1024, 13, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 320, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C99
    CallTrainerBattleEnd
    VMJump L_0C9B

L_0C99:
    CallTrainerLose

L_0C9B:
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40bd, 1
    VMJump L_0CC9

L_0CB5:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose

L_0CC9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    ActorCmdExec 4, Movement_0744
    TrainerBGMPlayPush 320
    ActorCmdWait
    ActorCmdExec 255, Movement_070C
    ActorCmdWait
    ActorMsg 1024, 13, 4, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 320, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D1E
    CallTrainerBattleEnd
    VMJump L_0D20

L_0D1E:
    CallTrainerLose

L_0D20:
    ActorMsg 1024, 14, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40bd, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    VMStackPush 0x40be
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0DB4
    SEPlay 1351
    ActorSetEyeToEye
    ActorCmdExec 5, Movement_0744
    TrainerBGMPlayPush 319
    ActorCmdWait
    ParentActorMsg 1024, 17, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 319, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D98
    CallTrainerBattleEnd
    VMJump L_0D9A

L_0D98:
    CallTrainerLose

L_0D9A:
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40be, 1
    VMJump L_0DC8

L_0DB4:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose

L_0DC8:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    ActorCmdExec 5, Movement_0744
    TrainerBGMPlayPush 319
    ActorCmdWait
    ActorCmdExec 255, Movement_0704
    ActorCmdWait
    ActorMsg 1024, 17, 5, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 319, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E1D
    CallTrainerBattleEnd
    VMJump L_0E1F

L_0E1D:
    CallTrainerLose

L_0E1F:
    ActorMsg 1024, 18, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40be, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    VMStackPush 0x40bf
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0EB3
    SEPlay 1351
    ActorSetEyeToEye
    ActorCmdExec 8, Movement_0744
    TrainerBGMPlayPush 325
    ActorCmdWait
    ParentActorMsg 1024, 19, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 325, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E97
    CallTrainerBattleEnd
    VMJump L_0E99

L_0E97:
    CallTrainerLose

L_0E99:
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40bf, 1
    VMJump L_0EC7

L_0EB3:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose

L_0EC7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_24:
    ActorsPauseAll
    ActorCmdExec 8, Movement_0744
    TrainerBGMPlayPush 325
    ActorCmdWait
    ActorCmdExec 8, Movement_06FC
    ActorCmdWait
    ActorMsg 1024, 19, 8, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 325, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0F1C
    CallTrainerBattleEnd
    VMJump L_0F1E

L_0F1C:
    CallTrainerLose

L_0F1E:
    ActorMsg 1024, 20, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40bf, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
