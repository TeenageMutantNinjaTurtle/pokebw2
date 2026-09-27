#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMStackPush 0x40ee
    VMStackPushConst 2
    VMStackCmp 4
    VMStackPushFlag 823
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0057
    ActorSetGPos 1, 15, 0, 24, 1

L_0057:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8008, 5
    VMStackPush 0x40c2
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C0
    ParentActorMsg 1024, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 231
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkAdd 0x40c2, 1
    VMJump L_0271

L_00C0:
    VMStackPush 0x40c2
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8008
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0250
    ParentActorMsg 1024, 3, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0114
    ActorCmdExec 0, Movement_02B8
    VMJump L_0171

L_0114:
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0135
    ActorCmdExec 0, Movement_02D8
    VMJump L_0171

L_0135:
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0156
    ActorCmdExec 0, Movement_0278
    VMJump L_0171

L_0156:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0171
    ActorCmdExec 0, Movement_0298

L_0171:
    ActorCmdWait
    ParentActorMsg 1024, 4, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 231
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 5, 0, 0
    ParentActorMsg 1024, 6, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 17
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 16
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0210
    ActorWalkRoute 0, 16, 15, 1, 8, 0
    ActorCmdWait
    ActorWalkRoute 0, 16, 27, 1, 8, 1
    VMSleep 16
    ActorCmdExec 255, Movement_0434
    ActorCmdWait
    VMJump L_022C

L_0210:
    ActorWalkRoute 0, 17, 27, 1, 8, 1
    VMSleep 8
    ActorCmdExec 255, Movement_0434
    ActorCmdWait

L_022C:
    ActorDelete 0
    WorkAdd 0x40c2, 1
    FlagSet 766
    FlagReset 768
    Cmd_0262 0, 3
    Cmd_0262 1, 18
    VMJump L_0271

L_0250:
    VMStackPush 0x40c2
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0271
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0271:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0278:
    Move 35, 1
    Move 62, 1
    Move 33, 1
    Move 62, 1
    Move 32, 1
    Move 63, 1
    Move 34, 1
    MoveEnd

Movement_0298:
    Move 34, 1
    Move 62, 1
    Move 33, 1
    Move 62, 1
    Move 32, 1
    Move 63, 1
    Move 35, 1
    MoveEnd

Movement_02B8:
    Move 34, 1
    Move 62, 1
    Move 33, 1
    Move 62, 1
    Move 35, 1
    Move 63, 1
    Move 32, 1
    MoveEnd

Movement_02D8:
    Move 34, 1
    Move 62, 1
    Move 32, 1
    Move 62, 1
    Move 35, 1
    Move 63, 1
    Move 33, 1
    MoveEnd

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40ee
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03AA
    ParentActorMsg 1024, 9, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 457, 0, 0
    VMCall L_0409
    ParentActorMsg 1024, 10, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkSetConst 0x40ee, 2
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 15
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 24
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_038A
    ActorWalkRoute 1, 15, 26, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 1, Movement_042C
    ActorCmdWait
    VMJump L_03A4

L_038A:
    ActorWalkRoute 1, 15, 24, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 1, Movement_0434
    ActorCmdWait

L_03A4:
    VMJump L_03CB

L_03AA:
    VMStackPush 0x40ee
    VMStackPushConst 2
    VMStackCmp 4
    VMJumpIf 255, L_03CB
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03CB:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0409:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0428
    CallTrainerBattleEnd
    VMJump L_042A

L_0428:
    CallTrainerLose

L_042A:
    VMReturn

Movement_042C:
    Move 32, 1
    MoveEnd

Movement_0434:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
