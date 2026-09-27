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

Script_1:
    TrainerCardHasBadge 0x8008, 1
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B3
    VMStackPushFlag 270
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_007C
    WorkSetConst 0x4000, 1
    WorkSetConst 0x4003, 1
    VMJump L_0088

L_007C:
    WorkSetConst 0x4000, 0
    WorkSetConst 0x4003, 0

L_0088:
    VMStackPushFlag 271
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00A7
    WorkSetConst 0x4001, 1
    VMJump L_00AD

L_00A7:
    WorkSetConst 0x4001, 0

L_00AD:
    VMJump L_00BF

L_00B3:
    WorkSetConst 0x4000, 0
    WorkSetConst 0x4001, 0

L_00BF:
    VMStackPushFlag 763
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00EA
    WorkSetConst 0x4000, 1
    WorkSetConst 0x4001, 1
    WorkSetConst 0x4002, 1
    WorkSetConst 0x4003, 1

L_00EA:
    VMHalt

Script_2:
    VMStackPush 0x4000
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0103
    Cmd_0292 1

L_0103:
    VMStackPush 0x4001
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_011A
    Cmd_0292 2

L_011A:
    VMHalt

Script_3:
    ActorsPauseAll
    VMStackPush 0x4000
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4001
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0157
    SEPlay 1351
    WordSetPlayerName 0
    InfoMsg 0, 2
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01CD

L_0157:
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0478
    TrainerCardHasBadge 0x8008, 1
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0188
    VMCall L_01D3
    VMJump L_01CD

L_0188:
    Cmd_0291 0
    Cmd_0291 1
    Cmd_0291 2
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01BD
    ActorMsg 1024, 6, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01CD

L_01BD:
    ActorMsg 1024, 8, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_01CD:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_01D3:
    ActorMsg 1024, 1, 0, 0, 1
    MsgWinCloseAll
    WorkSetConst 0x8024, 0
    GameGetDifficulty 0x8024
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_020C
    CallTrainerBattle 765, 0, 0
    VMJump L_0214

L_020C:
    CallTrainerBattle 157, 0, 0

L_0214:
    WorkSetConst 0x8024, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02B2
    FlagSet 763
    FlagReset 721
    ActorDelete 0
    ActorAdd 4
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0258
    VMJump L_0266

L_0258:
    ActorCmdExec 4, Movement_0744
    VMJump L_02A8

L_0266:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0279
    VMJump L_0287

L_0279:
    ActorCmdExec 4, Movement_075C
    VMJump L_02A8

L_0287:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_029A
    VMJump L_02A8

L_029A:
    ActorCmdExec 4, Movement_0754
    VMJump L_02A8

L_02A8:
    ActorCmdWait
    CallTrainerBattleEnd
    VMJump L_02B4

L_02B2:
    CallTrainerLose

L_02B4:
    VMCall L_0478
    Cmd_0291 0
    Cmd_0291 1
    Cmd_0291 2
    ActorMsg 1024, 2, 4, 0, 0
    ActorMsgClose
    TrainerCardSaveGymVictoryParty 1
    TrainerCardAddBadge 1
    WordSetPlayerName 0
    MEPlay 1306
    WorkSetConst 0x8025, 0
    TrainerCardGetSex 0x8025
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_030A
    PlayFieldEffect 4
    VMJump L_030E

L_030A:
    PlayFieldEffect 56

L_030E:
    MEWait
    WorkSetConst 0x8025, 0
    SystemMsg 3, 0
    InfoMsgClose
    ActorMsg 1024, 4, 4, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 336
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 5, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    TrainerFlagSet 178
    TrainerFlagSet 179
    WorkSetConst 0x40ad, 1
    WorkSetConst 0x410a, 1
    WorkSetConst 0x40ac, 3
    FlagSet 725
    FlagSet 2415
    VMReturn

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 178
    VMStackPushFlag 270
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03CF
    VMCall L_04F9
    VMCall L_049D
    VMJump L_0404

L_03CF:
    VMCall L_050F
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03FE
    CallTrainerBattleEnd
    VMCall L_049D
    FlagSet 270
    VMJump L_0400

L_03FE:
    CallTrainerLose

L_0400:
    TrainerFlagSet 0x8020

L_0404:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 179
    VMStackPushFlag 271
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_043D
    VMCall L_04F9
    VMCall L_04D0
    VMJump L_0472

L_043D:
    VMCall L_050F
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_046C
    CallTrainerBattleEnd
    VMCall L_04D0
    FlagSet 271
    VMJump L_046E

L_046C:
    CallTrainerLose

L_046E:
    TrainerFlagSet 0x8020

L_0472:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0478:
    ISSSwitchQuery 0x8010, 3
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_049B
    ISSSwitchDisable 3
    WorkSetConst 0x4002, 1

L_049B:
    VMReturn

L_049D:
    ISSSwitchQuery 0x8010, 1
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04CE
    ISSSwitchDisable 1
    ISSSwitchDisable 4
    Cmd_0292 1
    WorkSetConst 0x4000, 1
    WorkSetConst 0x4003, 1

L_04CE:
    VMReturn

L_04D0:
    ISSSwitchQuery 0x8010, 2
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04F7
    ISSSwitchDisable 2
    Cmd_0292 2
    WorkSetConst 0x4001, 1

L_04F7:
    VMReturn

L_04F9:
    TrainerGetMessageTypes 0x8021, 0x8022, 0x8023
    TrainerSayMessage 0x8020, 0x8022, 0x8011
    LastKeyWait
    ActorMsgClose
    VMReturn

L_050F:
    TrainerGetMessageTypes 0x8021, 0x8022, 0x8023
    TrainerSayMessage 0x8020, 0x8021, 0x8011
    ActorMsgClose
    CallTrainerBattle 0x8020, 0, 0
    VMReturn

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    PlayerGetGPos 0x8026, 0x8027
    ActorSetGPos 3, 13, 0, 6, 2
    BGMPlay 1203
    VMStackPush 0x8026
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_05A8
    ActorCmdExec 3, Movement_06C0
    VMJump L_05B0

L_05A8:
    ActorCmdExec 3, Movement_06C8

L_05B0:
    ActorCmdWait
    ActorCmdExec 255, Movement_077C
    ActorCmdWait
    ActorMsg 1024, 10, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8026
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_05EF
    ActorCmdExec 3, Movement_06D0
    VMSleep 10
    VMJump L_05FB

L_05EF:
    ActorCmdExec 3, Movement_06D8
    VMSleep 10

L_05FB:
    BGMChangeMap
    VMStackPush 0x8026
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0622
    VMSleep 30
    ActorCmdExec 4, Movement_06E0
    VMJump L_062E

L_0622:
    VMSleep 30
    ActorCmdExec 4, Movement_06F8

L_062E:
    ActorCmdWait
    VMStackPush 0x8026
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0649
    VMJump L_0653

L_0649:
    ActorCmdExec 255, Movement_0774
    ActorCmdWait

L_0653:
    ActorMsg 1024, 7, 4, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8026
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0682
    ActorCmdExec 4, Movement_0710
    VMJump L_0696

L_0682:
    ActorCmdExec 4, Movement_0718
    VMSleep 20
    ActorCmdExec 255, Movement_077C

L_0696:
    ActorCmdWait
    ActorDelete 3
    ActorDelete 4
    WorkSetConst 0x40ad, 2
    FlagSet 721
    FlagSet 720
    FlagSet 725
    WorkSetConst 0x40ac, 3
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_06C0:
    Move 14, 9
    MoveEnd

Movement_06C8:
    Move 14, 8
    MoveEnd

Movement_06D0:
    Move 15, 10
    MoveEnd

Movement_06D8:
    Move 15, 9
    MoveEnd

Movement_06E0:
    Move 14, 1
    Move 13, 1
    Move 14, 3
    Move 13, 2
    Move 34, 1
    MoveEnd

Movement_06F8:
    Move 14, 1
    Move 13, 1
    Move 14, 4
    Move 13, 2
    Move 35, 1
    MoveEnd

Movement_0710:
    Move 15, 10
    MoveEnd

Movement_0718:
    Move 13, 1
    Move 15, 10
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd

Movement_0744:
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd

Movement_0754:
    Move 2, 1
    MoveEnd

Movement_075C:
    Move 3, 1
    MoveEnd
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd

Movement_0774:
    Move 34, 1
    MoveEnd

Movement_077C:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
