#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMStackPush 0x4111
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0049
    Cmd_0262 2, 0

L_0049:
    VMHalt

Script_2:
    VMStackPush 0x40a9
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0082
    ActorSetGPos 0, 15, 0, 19, 0
    ActorSetGPos 1, 17, 0, 18, 2
    ActorSetGPos 2, 13, 0, 18, 3

L_0082:
    VMHalt

Script_3:
    ActorsPauseAll
    ActorCmdExec 3, Movement_08E8
    ActorCmdWait
    ActorWalkRoute 3, 14, 23, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 3, Movement_08E0
    VMSleep 8
    ActorCmdExec 255, Movement_08D8
    ActorCmdWait
    ActorMsg 1024, 20, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 30
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 21, 3, 0, 0
    ActorMsg 1024, 22, 3, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 3, 12, 22, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 3, Movement_08E0
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x138000, 40
    ActorCmdExec 255, Movement_08A8
    ActorCmdWait
    EvCameraWait
    ActorCmdExec 0, Movement_08E8
    ActorCmdWait
    ActorWalkRoute 0, 15, 20, 0, 8, 1
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_08D0
    ActorCmdExec 2, Movement_08D0
    ActorCmdWait
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0244
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 40
    ActorCmdExec 1, Movement_08D8
    ActorWalkRoute 2, 13, 12, 1, 8, 1
    VMSleep 20
    ActorWalkRoute 0, 15, 21, 1, 8, 1
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorMsg 1024, 3, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 0, 15, 11, 1, 8, 1
    ActorCmdExec 2, Movement_08E0
    ActorCmdWait
    ActorSetGPos 0, 15, 2, 2, 1
    ActorSetGPos 2, 13, 0, 9, 3
    FlagSet 115
    WorkSetConst 0x40a9, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 33, 1
    Move 75, 1
    MoveEnd
    Move 14, 3
    Move 13, 1
    Move 35, 1
    MoveEnd

Movement_0244:
    Move 34, 1
    Move 63, 1
    Move 35, 1
    Move 63, 1
    MoveEnd

Movement_0258:
    Move 181, 1
    MoveEnd
    Move 12, 1
    Move 34, 1
    MoveEnd

Script_4:
    ActorsPauseAll
    TrainerCardHasBadge 0x8008, 0
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02C2
    VMStackPush 0x40a9
    VMStackPushConst 3
    VMStackCmp 4
    VMJumpIf 255, L_02A6
    VMCall L_030D
    VMJump L_02BC

L_02A6:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 4, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_02BC:
    VMJump L_0307

L_02C2:
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F1
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 10, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0307

L_02F1:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 11, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0307:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_030D:
    SEPlay 1351
    ActorCmdExec 0, Movement_0258
    ActorCmdWait
    VMSleep 35
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0336
    VMJump L_0344

L_0336:
    ActorCmdExec 0, Movement_08C8
    VMJump L_0386

L_0344:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0357
    VMJump L_0365

L_0357:
    ActorCmdExec 0, Movement_08E0
    VMJump L_0386

L_0365:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0378
    VMJump L_0386

L_0378:
    ActorCmdExec 0, Movement_08D8
    VMJump L_0386

L_0386:
    ActorCmdWait
    ParentActorMsg 1024, 5, 0, 0
    ActorMsgClose
    WorkSetConst 0x8023, 0
    GameGetDifficulty 0x8023
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_03BF
    CallTrainerBattle 764, 0, 0
    VMJump L_03C7

L_03BF:
    CallTrainerBattle 156, 0, 0

L_03C7:
    WorkSetConst 0x8023, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03EC
    CallTrainerBattleEnd
    VMJump L_03EE

L_03EC:
    CallTrainerLose

L_03EE:
    ParentActorMsg 1024, 6, 0, 0
    ActorMsgClose
    TrainerCardSaveGymVictoryParty 0
    TrainerCardAddBadge 0
    WordSetPlayerName 0
    MEPlay 1306
    WorkSetConst 0x8024, 0
    TrainerCardGetSex 0x8024
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0430
    PlayFieldEffect 2
    VMJump L_0434

L_0430:
    PlayFieldEffect 55

L_0434:
    MEWait
    WorkSetConst 0x8024, 0
    SystemMsg 7, 0
    InfoMsgClose
    ParentActorMsg 1024, 8, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 410
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 9, 0, 0
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 2414
    WorkSetConst 0x40a8, 2
    FlagReset 742
    FlagSet 739
    FlagSet 1015
    MedalDiscover 130
    VMReturn

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 0
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0642
    TrainerFlagGet 171, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0603
    TrainerBGMPlayPush 171
    ActorMsg 1024, 12, 1, 0, 0
    ActorMsgClose
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x128000, 30
    PlayerGetDir 0x8010
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0533
    ActorCmdExec 255, Movement_0888
    ActorCmdWait
    VMJump L_0533

L_0533:
    ActorWalkRoute 255, 13, 18, 0, 8, 0
    VMSleep 20
    ActorCmdExec 1, Movement_08B8
    ActorCmdWait
    ActorCmdExec 255, Movement_08E0
    ActorCmdWait
    EvCameraWait
    ActorCmdExec 255, Movement_0898
    ActorCmdExec 1, Movement_08A0
    ActorCmdWait
    CallTrainerBattle 171, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05B2
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x128000, 1
    EvCameraWait
    CallTrainerBattleEnd
    VMJump L_05B4

L_05B2:
    CallTrainerLose

L_05B4:
    WorkAdd 0x40a9, 1
    TrainerFlagSet 171
    VMStackPush 0x40a9
    VMStackPushConst 3
    VMStackCmp 4
    VMJumpIf 255, L_05E3
    ActorMsg 1024, 14, 1, 0, 0
    VMJump L_05EF

L_05E3:
    ActorMsg 1024, 13, 1, 0, 0

L_05EF:
    LastKeyWait
    ActorMsgClose
    EvCameraMoveToDefault 10
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMJump L_063C

L_0603:
    VMStackPush 0x40a9
    VMStackPushConst 3
    VMStackCmp 4
    VMJumpIf 255, L_062C
    ActorMsg 1024, 14, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_063C

L_062C:
    ActorMsg 1024, 13, 1, 0, 0
    LastKeyWait
    ActorMsgClose

L_063C:
    VMJump L_0652

L_0642:
    ActorMsg 1024, 15, 1, 0, 0
    LastKeyWait
    ActorMsgClose

L_0652:
    EvCameraRebind
    EvCameraEnd
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_067B
    CallTrainerBattleEnd
    VMJump L_067D

L_067B:
    CallTrainerLose

L_067D:
    VMReturn

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 0
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0821
    TrainerFlagGet 172, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07E2
    TrainerBGMPlayPush 172
    ActorMsg 1024, 16, 2, 0, 0
    ActorMsgClose
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x98000, 30
    PlayerGetDir 0x8010
    VMStackPush 0x8010
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_070E
    ActorCmdExec 255, Movement_0888
    ActorCmdWait
    VMJump L_070E

L_070E:
    ActorWalkRoute 255, 17, 9, 0, 8, 0
    VMSleep 20
    ActorCmdExec 2, Movement_08C0
    ActorCmdWait
    ActorCmdExec 255, Movement_08D8
    ActorCmdWait
    EvCameraWait
    ActorCmdExec 255, Movement_08A0
    ActorCmdExec 2, Movement_0898
    ActorCmdWait
    CallTrainerBattle 172, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_078D
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf8000, 0, 0x98000, 1
    EvCameraWait
    CallTrainerBattleEnd
    VMJump L_078F

L_078D:
    CallTrainerLose

L_078F:
    WorkAdd 0x40a9, 1
    TrainerFlagSet 172
    VMStackPush 0x40a9
    VMStackPushConst 3
    VMStackCmp 4
    VMJumpIf 255, L_07C2
    ActorMsg 1024, 18, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_07D2

L_07C2:
    ActorMsg 1024, 17, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_07D2:
    EvCameraMoveToDefault 10
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMJump L_081B

L_07E2:
    VMStackPush 0x40a9
    VMStackPushConst 3
    VMStackCmp 4
    VMJumpIf 255, L_080B
    ActorMsg 1024, 18, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_081B

L_080B:
    ActorMsg 1024, 17, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_081B:
    VMJump L_0831

L_0821:
    ActorMsg 1024, 19, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_0831:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    TrainerCardHasBadge 0x8008, 0
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_086C
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0880

L_086C:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose

L_0880:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0888:
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0898:
    Move 15, 1
    MoveEnd

Movement_08A0:
    Move 14, 1
    MoveEnd

Movement_08A8:
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd

Movement_08B8:
    Move 2, 1
    MoveEnd

Movement_08C0:
    Move 3, 1
    MoveEnd

Movement_08C8:
    Move 32, 1
    MoveEnd

Movement_08D0:
    Move 33, 1
    MoveEnd

Movement_08D8:
    Move 34, 1
    MoveEnd

Movement_08E0:
    Move 35, 1
    MoveEnd

Movement_08E8:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
