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
    ScriptEntriesEnd

Script_1:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    VMStackPushFlag 377
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0075
    WorkSetConst 0x8020, 1
    VMJump L_007B

L_0075:
    WorkSetConst 0x8020, 0

L_007B:
    VMStackPushFlag 378
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_009A
    WorkSetConst 0x8021, 1
    VMJump L_00A0

L_009A:
    WorkSetConst 0x8021, 0

L_00A0:
    Cmd_017B 0x8020, 0x8021
    VMHalt

Script_13:
    VMStackPushFlag 377
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C7
    ActorSetGPos 1, 17, 2, 17, 2

L_00C7:
    VMStackPushFlag 378
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00E6
    ActorSetGPos 0, 51, 2, 42, 2

L_00E6:
    VMHalt

Script_14:
    FieldGetContinueFlag 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0101
    Cmd_024D

L_0101:
    VMHalt

Script_10:
    ActorsPauseAll
    ActorCmdExec 255, Movement_0118
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0118:
    Move 56, 1
    Move 34, 1
    MoveEnd

Script_11:
    ActorsPauseAll
    ActorCmdExec 255, Movement_0138
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0138:
    Move 57, 1
    MoveEnd

Script_12:
    ActorsPauseAll
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8022
    VMStackPushConst 16
    VMStackCmp 1
    VMJumpIf 255, L_0173
    VMCall L_018B
    VMJump L_0179

L_0173:
    VMCall L_0195

L_0179:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_018B:
    FlagReset 895
    ActorAdd 1
    VMReturn

L_0195:
    FlagReset 896
    ActorAdd 0
    VMReturn

Script_2:
    ActorsPauseAll
    Cmd_017C 0
    VMCall L_01E7
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    Cmd_017C 1
    VMCall L_01E7
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    Cmd_017C 2
    VMCall L_01E7
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    Cmd_017C 3
    VMCall L_01E7
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_01E7:
    WordSetPlayerName 0
    SystemMsg 10, 2
    LastKeyWait
    InfoMsgClose
    VMReturn

Script_6:
    ActorsPauseAll
    ActorCmdExec 255, Movement_03B0
    ActorCmdWait
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    PlayerGetGPos 0x8024, 0x8025
    VMStackPush 0x8024
    VMStackPushConst 16
    VMStackCmp 1
    VMJumpIf 255, L_0233
    VMCall L_024B
    VMJump L_0239

L_0233:
    VMCall L_026D

L_0239:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_024B:
    ActorCmdExec 255, Movement_03C0
    ActorCmdExec 1, Movement_03B8
    ActorCmdWait
    ActorMsg 1024, 2, 1, 0, 0
    ActorMsgClose
    VMReturn

L_026D:
    ActorCmdExec 255, Movement_03C0
    ActorCmdExec 0, Movement_03B8
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    ActorMsgClose
    VMReturn

Script_7:
    ActorsPauseAll
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    PlayerGetGPos 0x8026, 0x8027
    VMStackPush 0x8026
    VMStackPushConst 16
    VMStackCmp 1
    VMJumpIf 255, L_02C6
    VMCall L_02E2
    Cmd_017D 1
    VMJump L_02D0

L_02C6:
    VMCall L_0349
    Cmd_017D 2

L_02D0:
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_02E2:
    TrainerBGMPlayPush 621
    ActorCmdExec 1, Movement_03D0
    ActorCmdWait
    ActorMsg 1024, 3, 1, 0, 0
    ActorMsgClose
    CallTrainerBattle 621, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0325
    CallTrainerBattleEnd
    VMJump L_032B

L_0325:
    FlagSet 895
    CallTrainerLose

L_032B:
    ActorMsg 1024, 4, 1, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_03D8
    ActorCmdWait
    FlagSet 377
    VMReturn

L_0349:
    TrainerBGMPlayPush 148
    ActorCmdExec 0, Movement_03D0
    ActorCmdWait
    ActorMsg 1024, 7, 0, 0, 0
    ActorMsgClose
    CallTrainerBattle 148, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_038C
    CallTrainerBattleEnd
    VMJump L_0392

L_038C:
    FlagSet 896
    CallTrainerLose

L_0392:
    ActorMsg 1024, 8, 0, 0, 0
    ActorMsgClose
    ActorCmdExec 0, Movement_03D8
    ActorCmdWait
    FlagSet 378
    VMReturn

Movement_03B0:
    Move 75, 1
    MoveEnd

Movement_03B8:
    Move 57, 1
    MoveEnd

Movement_03C0:
    Move 71, 1
    Move 17, 2
    Move 72, 1
    MoveEnd

Movement_03D0:
    Move 13, 1
    MoveEnd

Movement_03D8:
    Move 2, 1
    Move 71, 1
    Move 15, 1
    Move 72, 1
    MoveEnd

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    VMStackPushFlag 459
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0453
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_049B

L_0453:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 22
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 459
    FlagSet 669

L_049B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
