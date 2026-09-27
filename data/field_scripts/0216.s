#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd

Script_2:
    FlagSet 496
    VMHalt

Script_3:
    VMStackPush 0x409f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0049
    ActorSetGPos 5, 11, 0, 37, 1
    VMJump L_0049

L_0049:
    Gym0601FanAmbienceStart
    VMHalt

Script_4:
    Gym0601FanAmbienceStart
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 5
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_007E
    VMCall L_00F6
    VMJump L_00F0

L_007E:
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40cb
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00B7
    ActorMsg 1024, 4, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_00F0

L_00B7:
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E0
    ActorMsg 1024, 5, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_00F0

L_00E0:
    ActorMsg 1024, 6, 3, 0, 0
    LastKeyWait
    ActorMsgClose

L_00F0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_00F6:
    ParentActorMsg 1024, 0, 0, 0
    ActorMsgClose
    WorkSetConst 0x8020, 0
    GameGetDifficulty 0x8020
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_012D
    CallTrainerBattle 769, 0, 0
    VMJump L_0135

L_012D:
    CallTrainerBattle 155, 0, 0

L_0135:
    WorkSetConst 0x8020, 0
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
    ParentActorMsg 1024, 1, 0, 0
    ActorMsgClose
    TrainerCardSaveGymVictoryParty 5
    TrainerCardAddBadge 5
    WordSetPlayerName 0
    MEPlay 1306
    WorkSetConst 0x8021, 0
    TrainerCardGetSex 0x8021
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_019E
    PlayFieldEffect 8
    VMJump L_01A2

L_019E:
    PlayFieldEffect 60

L_01A2:
    MEWait
    WorkSetConst 0x8021, 0
    SystemMsg 2, 0
    InfoMsgClose
    ParentActorMsg 1024, 3, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 389
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    VMStackPush 0x40c2
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0211
    Cmd_0262 0, 3
    Cmd_0262 1, 18
    VMJump L_0217

L_0211:
    Cmd_0262 1, 19

L_0217:
    TrainerFlagSet 149
    TrainerFlagSet 150
    TrainerFlagSet 151
    TrainerFlagSet 152
    TrainerFlagSet 332
    FlagSet 2419
    WorkSetConst 0x40c1, 1
    WorkAdd 0x40c2, 1
    VMReturn

Script_5:
    ActorsPauseAll
    VMStackPush 0x409f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0326
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    PlayerGetGPos 0x8022, 0x8023
    ActorSetGPos 5, 0x8022, 0, 37, 2
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    ActorCmdExec 255, Movement_032C
    ActorCmdWait
    Cmd_028E 5
    VMSleep 30
    ActorCmdExec 255, Movement_0334
    ActorCmdWait
    VMStackPushFlag 112
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02DD
    ActorMsg 1024, 7, 5, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 30
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 112

L_02DD:
    ActorWalkRoute 5, 12, 46, 1, 8, 0
    ActorCmdExec 5, Movement_033C
    ActorCmdWait
    ActorWalkRoute 255, 11, 46, 1, 8, 0
    ActorCmdExec 255, Movement_0344
    ActorCmdWait
    VMCall L_034C
    InfoMsg 9, 2
    MsgWinCloseAll
    VMCall L_036A
    WorkSetConst 0x409f, 1

L_0326:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_032C:
    Move 75, 1
    MoveEnd

Movement_0334:
    Move 12, 1
    MoveEnd

Movement_033C:
    Move 2, 1
    MoveEnd

Movement_0344:
    Move 3, 1
    MoveEnd

L_034C:
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 4056, 0, 0xed000, 0xb8000, 0, 0x143000, 90
    VMReturn

L_036A:
    EvCameraWait
    EvCameraMoveToDefault 60
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMReturn

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 5
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03AD
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_03BB

L_03AD:
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose

L_03BB:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    WorkSetConst 0x8024, 0
    TrainerCardHasBadge 0x8008, 5
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03F4
    WordSetPlayerName 0
    InfoMsg 11, 2
    VMJump L_0420

L_03F4:
    VMStackPushFlag 2485
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0415
    WordSetPlayerName 0
    InfoMsg 12, 2
    VMJump L_0420

L_0415:
    WordSetLoadRivalName 1
    WordSetPlayerName 0
    InfoMsg 13, 2

L_0420:
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
