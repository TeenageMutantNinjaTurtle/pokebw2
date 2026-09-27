#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    ActorsPauseAll
    WordSetPlayerName 0
    BGMPlay 1160
    ActorCmdExec 1, Movement_00D4
    ActorCmdWait
    ActorMsg 1024, 0, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_00DC
    ActorCmdWait
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_00E4
    ActorCmdWait
    ActorMsg 1024, 2, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_00EC
    ActorCmdWait
    ActorMsg 1024, 3, 1, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B4
    VMCall L_00F4
    BGMChangeMap
    VMJump L_00CC

L_00B4:
    ActorMsg 1024, 5, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    BGMChangeMap
    WorkSetConst 0x4098, 2

L_00CC:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_00D4:
    Move 75, 1
    MoveEnd

Movement_00DC:
    Move 13, 2
    MoveEnd

Movement_00E4:
    Move 35, 1
    MoveEnd

Movement_00EC:
    Move 33, 1
    MoveEnd

L_00F4:
    WordSetPlayerName 0
    ActorMsg 1024, 4, 1, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 456, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_012C
    CallTrainerBattleEnd
    VMJump L_0134

L_012C:
    WorkSetConst 0x4098, 2
    CallTrainerLose

L_0134:
    ActorMsg 1024, 7, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4098, 3
    WorkSetConst 0x400f, 1
    VMReturn

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WordSetPlayerName 0
    WorkSetConst 0x8021, 0
    RTCGetSeason 0x8021
    VMStackPush 0x4098
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01BF
    ActorMsg 1024, 6, 1, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01A9
    VMCall L_00F4
    VMJump L_01B9

L_01A9:
    ActorMsg 1024, 5, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01B9:
    VMJump L_044C

L_01BF:
    VMStackPush 0x4098
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01F8
    ActorMsg 1024, 8, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_044C

L_01F8:
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2745
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03BB
    VMStackPush 0x4166
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2748
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0254
    ActorMsg 1024, 9, 1, 0, 0
    FlagSet 2748
    VMJump L_02CE

L_0254:
    VMStackPush 0x4166
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2748
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0289
    ActorMsg 1024, 12, 1, 0, 0
    VMJump L_02CE

L_0289:
    VMStackPush 0x4166
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2748
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02C2
    ActorMsg 1024, 14, 1, 0, 0
    FlagSet 2748
    VMJump L_02CE

L_02C2:
    ActorMsg 1024, 17, 1, 0, 0

L_02CE:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0380
    VMStackPush 0x4166
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_030A
    ActorMsg 1024, 10, 1, 0, 0
    VMJump L_0316

L_030A:
    ActorMsg 1024, 15, 1, 0, 0

L_0316:
    MsgWinCloseAll
    CallTrainerBattle 456, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0343
    FlagSet 2745
    CallTrainerBattleEnd
    VMJump L_0345

L_0343:
    CallTrainerLose

L_0345:
    VMStackPush 0x4166
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_036A
    ActorMsg 1024, 13, 1, 0, 0
    VMJump L_0376

L_036A:
    ActorMsg 1024, 18, 1, 0, 0

L_0376:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03B5

L_0380:
    VMStackPush 0x4166
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03A5
    ActorMsg 1024, 11, 1, 0, 0
    VMJump L_03B1

L_03A5:
    ActorMsg 1024, 16, 1, 0, 0

L_03B1:
    LastKeyWait
    MsgWinCloseAll

L_03B5:
    VMJump L_044C

L_03BB:
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2745
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0419
    VMStackPush 0x4166
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0403
    ActorMsg 1024, 13, 1, 0, 0
    VMJump L_040F

L_0403:
    ActorMsg 1024, 18, 1, 0, 0

L_040F:
    LastKeyWait
    MsgWinCloseAll
    VMJump L_044C

L_0419:
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_044C
    WorkSetConst 0x8020, 29
    WorkAdd 0x8020, 0x4166
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8020, 0, 0
    LastKeyWait
    ActorMsgClose

L_044C:
    WorkSetConst 0x8021, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x8020, 19
    WorkAdd 0x8020, 0x4167
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8020, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    WorkSetConst 0x8020, 24
    WorkAdd 0x8020, 0x4168
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8020, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    WorkSetConst 0x8020, 39
    WorkAdd 0x8020, 0x416a
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8020, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    WorkSetConst 0x8020, 44
    WorkAdd 0x8020, 0x416b
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8020, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    WorkSetConst 0x8020, 34
    WorkAdd 0x8020, 0x416c
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8020, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 49, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
