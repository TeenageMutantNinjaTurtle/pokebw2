#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40ee
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_00F0
    ParentActorMsg 1024, 0, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 460, 0, 0
    VMCall L_0117
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkSetConst 0x40ee, 5
    FlagSet 823
    FlagSet 824
    FlagSet 825
    FlagSet 826
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 10
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00B6
    ActorWalkRoute 2, 11, 16, 1, 8, 1
    ActorCmdWait
    VMJump L_00D6

L_00B6:
    ActorWalkRoute 2, 12, 10, 1, 8, 0
    ActorCmdWait
    ActorWalkRoute 2, 11, 16, 1, 8, 1
    ActorCmdWait

L_00D6:
    ActorWalkRoute 2, 11, 19, 1, 8, 1
    ActorCmdWait
    ActorDelete 2
    VMJump L_0111

L_00F0:
    VMStackPush 0x40ee
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_0111
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0111:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0117:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0136
    CallTrainerBattleEnd
    VMJump L_0138

L_0136:
    CallTrainerLose

L_0138:
    VMReturn
    .balign 4, 0
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
