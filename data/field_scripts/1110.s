#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_2:
    VMHalt

Script_3:
    VMStackPush 0x40f3
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPushFlag 429
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0069
    ActorSetGPos 0, 7, 0, 9, 1
    VMJump L_0098

L_0069:
    VMStackPush 0x40f3
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPushFlag 429
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0098
    ActorSetGPos 0, 7, 2, 5, 1

L_0098:
    VMHalt

Script_4:
    VMHalt

Script_5:
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x78000, 0, 0x2b000, 80
    ActorCmdExec 255, Movement_04C8
    ActorCmdWait
    EvCameraWait
    BGMPlay 1238
    ActorCmdExec 0, Movement_04D0
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 7, 7, 1, 8, 1
    EvCameraMoveTo 9688, 0, 0xed000, 0x78000, 0x2001f, 0x6a000, 24
    EvCameraWait
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    EvCameraMoveTo 9688, 0, 0xed000, 0x78000, 0, 0x98000, 24
    ActorWalkRoute 0, 7, 9, 1, 8, 1
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 3, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    EvCameraMoveToDefault 40
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    BGMChangeMap
    WorkSetConst 0x40f3, 2
    VMHalt
    .balign 4, 0

Movement_0174:
    Move 15, 1
    MoveEnd

Movement_017C:
    Move 14, 1
    MoveEnd

Movement_0184:
    Move 15, 1
    Move 33, 1
    MoveEnd

Movement_0190:
    Move 15, 1
    Move 32, 1
    MoveEnd

L_019C:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 4, 0, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 344, 0, 0
    VMCall L_045B
    ActorMsg 1024, 5, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01F3
    ActorMsg 1024, 6, 0, 0, 0
    VMJump L_01FF

L_01F3:
    ActorMsg 1024, 7, 0, 0, 0

L_01FF:
    MsgWinCloseAll
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0226
    ActorCmdExec 0, Movement_0498
    VMJump L_022E

L_0226:
    ActorCmdExec 0, Movement_04A0

L_022E:
    ActorCmdWait
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    WorkCmpConst 0x8021, 3
    VMJumpIf 1, L_0251
    VMJump L_025F

L_0251:
    ActorCmdExec 0, Movement_017C
    VMJump L_02C2

L_025F:
    WorkCmpConst 0x8021, 2
    VMJumpIf 1, L_0272
    VMJump L_0280

L_0272:
    ActorCmdExec 0, Movement_0174
    VMJump L_02C2

L_0280:
    WorkCmpConst 0x8021, 0
    VMJumpIf 1, L_0293
    VMJump L_02A1

L_0293:
    ActorCmdExec 0, Movement_0184
    VMJump L_02C2

L_02A1:
    WorkCmpConst 0x8021, 1
    VMJumpIf 1, L_02B4
    VMJump L_02C2

L_02B4:
    ActorCmdExec 0, Movement_0190
    VMJump L_02C2

L_02C2:
    ActorCmdWait
    ActorMsg 1024, 9, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40f3, 3
    WorkSetConst 0x40f4, 1
    WorkSetConst 0x4125, 1
    VMReturn

Script_6:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40f3
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0319
    VMCall L_019C
    VMJump L_0418

L_0319:
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40f3
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0356
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0418

L_0356:
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 429
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_040A
    ParentActorMsg 1024, 10, 0, 0
    ParentActorMsg 1024, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0480
    ActorCmdWait
    CallTrainerBattle 813, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03B6
    CallTrainerBattleEnd
    VMJump L_03B8

L_03B6:
    CallTrainerLose

L_03B8:
    ParentActorMsg 1024, 12, 0, 0
    ParentActorMsg 1024, 13, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 1
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 429
    FlagSet 2793
    VMJump L_0418

L_040A:
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0418:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    GameGetVersion 0x8020
    PlayerGetDir 0x8021
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_044B
    MapChangeWarpPad 561, 26, 10, 32801
    VMJump L_0455

L_044B:
    MapChangeWarpPad 564, 26, 10, 32801

L_0455:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_045B:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_047A
    CallTrainerBattleEnd
    VMJump L_047C

L_047A:
    CallTrainerLose

L_047C:
    VMReturn
    .balign 4, 0

Movement_0480:
    Move 182, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0498:
    Move 15, 1
    MoveEnd

Movement_04A0:
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

Movement_04C8:
    Move 32, 1
    MoveEnd

Movement_04D0:
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
