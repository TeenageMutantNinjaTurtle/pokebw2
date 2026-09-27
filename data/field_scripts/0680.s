#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMStackPush 0x40ee
    VMStackPushConst 4
    VMStackCmp 4
    VMStackPushFlag 825
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_004B
    ActorSetGPos 1, 17, 0, 23, 0

L_004B:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40ee
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_00FF
    ParentActorMsg 1024, 0, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 459, 0, 0
    VMCall L_0126
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkSetConst 0x40ee, 4
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 17
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 23
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00DF
    ActorWalkRoute 1, 17, 21, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 1, Movement_0154
    ActorCmdWait
    VMJump L_00F9

L_00DF:
    ActorWalkRoute 1, 17, 23, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 1, Movement_014C
    ActorCmdWait

L_00F9:
    VMJump L_0120

L_00FF:
    VMStackPush 0x40ee
    VMStackPushConst 4
    VMStackCmp 4
    VMJumpIf 255, L_0120
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0120:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0126:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0145
    CallTrainerBattleEnd
    VMJump L_0147

L_0145:
    CallTrainerLose

L_0147:
    VMReturn
    .balign 4, 0

Movement_014C:
    Move 32, 1
    MoveEnd

Movement_0154:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
