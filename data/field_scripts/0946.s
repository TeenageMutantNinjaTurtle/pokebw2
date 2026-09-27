#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 7
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0051
    VMCall L_009C
    VMJump L_0096

L_0051:
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0080
    ActorMsg 1024, 6, 0, 0, 0
    MsgWaitAdvance
    ActorMsgClose
    VMCall L_0250
    VMJump L_0096

L_0080:
    ActorMsg 1024, 7, 0, 0, 0
    MsgWaitAdvance
    ActorMsgClose
    VMCall L_0250

L_0096:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_009C:
    ParentActorMsg 1024, 0, 0, 0
    ActorMsgClose
    WorkSetConst 0x8023, 0
    GameGetDifficulty 0x8023
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00D3
    CallTrainerBattle 771, 0, 0
    VMJump L_00DB

L_00D3:
    CallTrainerBattle 160, 0, 0

L_00DB:
    WorkSetConst 0x8023, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0100
    CallTrainerBattleEnd
    VMJump L_0102

L_0100:
    CallTrainerLose

L_0102:
    ParentActorMsg 1024, 1, 0, 0
    ActorMsgClose
    TrainerCardSaveGymVictoryParty 7
    TrainerCardAddBadge 7
    WordSetPlayerName 0
    MEPlay 1306
    WorkSetConst 0x8024, 0
    TrainerCardGetSex 0x8024
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0144
    PlayFieldEffect 10
    VMJump L_0148

L_0144:
    PlayFieldEffect 62

L_0148:
    MEWait
    WorkSetConst 0x8024, 0
    SystemMsg 2, 0
    InfoMsgClose
    ParentActorMsg 1024, 3, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 382
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 4, 0, 0
    ParentActorMsg 1024, 5, 0, 0
    ActorMsgClose
    TrainerFlagSet 350
    TrainerFlagSet 352
    TrainerFlagSet 354
    TrainerFlagSet 351
    TrainerFlagSet 353
    TrainerFlagSet 355
    FlagSet 2421
    WorkSetConst 0x40df, 1
    WorkSetConst 0x40e3, 1
    FlagReset 810
    FlagSet 1002
    Cmd_0262 1, 27
    PlayerGetDir 0x8020
    ActorCmdExec 0, Movement_0434
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01FD
    ActorCmdExec 255, Movement_043C
    VMJump L_022C

L_01FD:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_022C
    VMSleep 4
    ActorCmdExec 255, Movement_049C

L_022C:
    ActorCmdWait
    ActorJumpToGPos 0, 16, 0xfffc, 1
    Cmd_02A2
    ActorCmdExec 0, Movement_0454
    ActorCmdWait
    VMSleep 35
    Cmd_02A3
    VMSleep 80
    VMReturn

L_0250:
    PlayerGetDir 0x8020
    ActorCmdExec 0, Movement_0434
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_027D
    ActorCmdExec 255, Movement_043C
    VMJump L_02AC

L_027D:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_02AC
    VMSleep 4
    ActorCmdExec 255, Movement_049C

L_02AC:
    ActorCmdWait
    ActorJumpToGPos 0, 16, 0xfffc, 1
    Cmd_02A2
    ActorCmdExec 0, Movement_0454
    ActorCmdWait
    VMSleep 35
    Cmd_02A3
    VMSleep 80
    VMReturn

Script_4:
    ActorsPauseAll
    ActorCmdExec 7, Movement_0310
    VMSleep 16
    ActorCmdExec 255, Movement_04A4
    ActorCmdWait
    ActorMsg 1024, 8, 7, 0, 0
    MsgWaitAdvance
    ActorMsgClose
    ActorCmdExec 7, Movement_04A4
    ActorCmdExec 255, Movement_045C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0310:
    Move 32, 1
    Move 75, 1
    MoveEnd

Script_2:
    ActorsPauseAll
    VMStackPush 0x411f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_034B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_03EF

L_034B:
    TrainerCardHasBadge 0x8008, 7
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03DB
    VMStackPushFlag 117
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03C1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 30
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 117
    VMJump L_03D5

L_03C1:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose

L_03D5:
    VMJump L_03EF

L_03DB:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose

L_03EF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    TrainerCardHasBadge 0x8008, 7
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0425
    InfoMsg 12, 2
    VMJump L_042A

L_0425:
    InfoMsg 13, 2

L_042A:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0434:
    Move 16, 2
    MoveEnd

Movement_043C:
    Move 3, 1
    Move 71, 1
    Move 18, 1
    Move 72, 1
    Move 32, 1
    MoveEnd

Movement_0454:
    Move 69, 1
    MoveEnd

Movement_045C:
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd

Movement_049C:
    Move 32, 1
    MoveEnd

Movement_04A4:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
