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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    Cmd_02A4
    WorkSetConst 0x8023, 0
    TrainerFlagGet 381, 0x8023
    VMStackPush 0x40cf
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_007D
    WorkSetConst 0x4000, 1
    VMJump L_0083

L_007D:
    WorkSetConst 0x4000, 0

L_0083:
    WorkSetConst 0x4001, 0
    WorkSetConst 0x4002, 0
    WorkSetConst 0x4003, 0
    WorkSetConst 0x8023, 0
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 2187
    ActorCmdExec 255, Movement_07CC
    ActorCmdWait
    ActorCmdExec 255, Movement_07C0
    ActorCmdWait
    Cmd_02A5 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 2187
    ActorCmdExec 255, Movement_07DC
    ActorCmdWait
    ActorCmdExec 255, Movement_07C0
    ActorCmdWait
    Cmd_02A5 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 2187
    ActorCmdExec 255, Movement_07EC
    ActorCmdWait
    ActorCmdExec 255, Movement_07C0
    ActorCmdWait
    Cmd_02A5 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 2187
    ActorCmdExec 255, Movement_07FC
    ActorCmdWait
    ActorCmdExec 255, Movement_07C0
    ActorCmdWait
    Cmd_02A5 3
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    WorkSetConst 0x8024, 0

L_0133:
    CallTrainerBattle 0x8024, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_015A
    CallTrainerBattleEnd
    VMJump L_015C

L_015A:
    CallTrainerLose

L_015C:
    TrainerFlagSet 0x8024
    VMReturn

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 381
    WorkSetConst 0x8025, 0
    TrainerFlagGet 0x8024, 0x8025
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01CE
    ParentActorMsg 1024, 0, 0, 0
    MsgWinCloseAll
    VMCall L_0133
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMStackPush 0x40cf
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01C8
    WorkSetConst 0x40cf, 1

L_01C8:
    VMJump L_01DC

L_01CE:
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01DC:
    WorkSetConst 0x8025, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 384
    WorkSetConst 0x8026, 0
    TrainerFlagGet 0x8024, 0x8026
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0289
    WorkSetConst 0x8027, 0
    PokePartyGetCount 0x8027, 2
    VMStackPush 0x8027
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0248
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0283

L_0248:
    ParentActorMsg 1024, 7, 0, 0
    MsgWinCloseAll
    VMCall L_0133
    Cmd_02A6
    VMStackPush 0x40d1
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0275
    WorkSetConst 0x40d1, 1

L_0275:
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0283:
    VMJump L_0297

L_0289:
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0297:
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 385
    WorkSetConst 0x8028, 0
    TrainerFlagGet 0x8024, 0x8028
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_034A
    WorkSetConst 0x8029, 0
    PokePartyGetCount 0x8029, 2
    VMStackPush 0x8029
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0309
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0344

L_0309:
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    VMCall L_0133
    Cmd_02A6
    VMStackPush 0x40d1
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0336
    WorkSetConst 0x40d1, 1

L_0336:
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0344:
    VMJump L_0358

L_034A:
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0358:
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 383
    WorkSetConst 0x802a, 0
    TrainerFlagGet 0x8024, 0x802a
    VMStackPush 0x802a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03D8
    ParentActorMsg 1024, 4, 0, 0
    MsgWinCloseAll
    VMCall L_0133
    Cmd_02A6
    VMStackPush 0x40d0
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03C4
    WorkSetConst 0x40d0, 1

L_03C4:
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03E6

L_03D8:
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03E6:
    WorkSetConst 0x802a, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8024, 382
    WorkSetConst 0x802b, 0
    TrainerFlagGet 0x8024, 0x802b
    VMStackPush 0x802b
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0460
    ParentActorMsg 1024, 2, 0, 0
    MsgWinCloseAll
    VMCall L_0133
    Cmd_02A6
    VMStackPush 0x40d0
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_044C
    WorkSetConst 0x40d0, 1

L_044C:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_046E

L_0460:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_046E:
    WorkSetConst 0x802b, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    ActorCmdExec 0, Movement_080C
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 25
    VMStackCmp 5
    VMJumpIf 255, L_04BF
    WorkSub 0x8022, 1
    ActorWalkRoute 0, 0x8021, 0x8022, 4, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_081C
    ActorCmdWait

L_04BF:
    ActorMsg 1024, 20, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 30
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMCall L_0588
    InfoMsg 21, 2
    VMCall L_05A6
    MsgWaitAdvance
    InfoMsgClose_0039
    VMStackPush 0x8021
    VMStackPushConst 25
    VMStackCmp 5
    VMJumpIf 255, L_052F
    ActorWalkRoute 0, 25, 51, 4, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_081C
    ActorCmdWait

L_052F:
    FlagSet 114
    WorkSetConst 0x4145, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 6
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0574
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0582

L_0574:
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose

L_0582:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0588:
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 5976, 3840, 0xed000, 0x128000, 0x3c2000, 0x16f000, 150
    VMReturn

L_05A6:
    EvCameraWait
    EvCameraMoveToDefault 60
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMReturn

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 6
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_073A
    Cmd_02A8
    WorkSetConst 0x802c, 0
    Cmd_02B2 0, 0x802c
    VMStackPush 0x802c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_060C
    Cmd_02B5 0, 2
    ParentActorMsg 1024, 13, 0, 0
    VMJump L_0616

L_060C:
    ParentActorMsg 1024, 12, 0, 0

L_0616:
    ActorMsgClose
    WorkSetConst 0x802d, 0
    GameGetDifficulty 0x802d
    VMStackPush 0x802d
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0643
    CallTrainerBattle 770, 0, 0
    VMJump L_064B

L_0643:
    CallTrainerBattle 159, 0, 0

L_064B:
    WorkSetConst 0x802d, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0670
    CallTrainerBattleEnd
    VMJump L_0672

L_0670:
    CallTrainerLose

L_0672:
    ParentActorMsg 1024, 14, 0, 0
    ActorMsgClose
    TrainerCardSaveGymVictoryParty 6
    TrainerCardAddBadge 6
    MEPlay 1306
    WorkSetConst 0x802e, 0
    TrainerCardGetSex 0x802e
    Cmd_02A8
    VMStackPush 0x802e
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06B3
    PlayFieldEffect 9
    VMJump L_06B7

L_06B3:
    PlayFieldEffect 61

L_06B7:
    MEWait
    Cmd_02A9
    WorkSetConst 0x802e, 0
    WordSetPlayerName 0
    SystemMsg 15, 0
    InfoMsgClose
    ParentActorMsg 1024, 16, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 409
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 17, 0, 0
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose
    TrainerFlagSet 381
    TrainerFlagSet 384
    TrainerFlagSet 385
    TrainerFlagSet 383
    TrainerFlagSet 382
    FlagSet 2420
    WorkSetConst 0x40d6, 1
    Cmd_0262 1, 24
    VMJump L_0748

L_073A:
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose

L_0748:
    WorkSetConst 0x802c, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    VMStackPush 0x40cf
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0775
    Cmd_02A7 0
    WorkSetConst 0x40cf, 2
    Cmd_02A6

L_0775:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    WorkSetConst 0x802f, 0
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    TrainerCardHasBadge 0x8008, 6
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07B1
    InfoMsg 23, 2
    VMJump L_07B6

L_07B1:
    InfoMsg 24, 2

L_07B6:
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_07C0:
    Move 32, 1
    Move 0, 1
    MoveEnd

Movement_07CC:
    Move 33, 1
    Move 1, 1
    Move 13, 1
    MoveEnd

Movement_07DC:
    Move 32, 1
    Move 0, 1
    Move 12, 1
    MoveEnd

Movement_07EC:
    Move 35, 1
    Move 3, 1
    Move 15, 1
    MoveEnd

Movement_07FC:
    Move 34, 1
    Move 2, 1
    Move 14, 1
    MoveEnd

Movement_080C:
    Move 75, 1
    MoveEnd
    Move 32, 1
    MoveEnd

Movement_081C:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
