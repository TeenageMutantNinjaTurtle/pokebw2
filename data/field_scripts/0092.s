#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    ActorCmdExec 2, Movement_01DC
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 10
    VMStackCmp 1
    VMJumpIf 255, L_006B
    WorkSub 0x8022, 1
    ActorWalkRoute 2, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 2, Movement_01CC
    ActorCmdWait
    VMJump L_0081

L_006B:
    WorkSub 0x8022, 1
    ActorWalkRoute 2, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait

L_0081:
    ActorMsg 1024, 0, 2, 5, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorCmdExec 2, Movement_019C
    ActorCmdExec 1, Movement_01BC
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 11
    VMStackCmp 1
    VMJumpIf 255, L_00E0
    WorkSub 0x8022, 1
    ActorWalkRoute 1, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 1, Movement_01CC
    ActorCmdWait
    VMJump L_00F6

L_00E0:
    WorkSub 0x8022, 1
    ActorWalkRoute 1, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait

L_00F6:
    ActorMsg 1024, 1, 1, 3, 0
    MsgWinCloseAll
    CallTrainerBattle 503, 0, 0
    VMCall L_013E
    ActorMsg 1024, 2, 1, 3, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorMsg 1024, 3, 2, 5, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40fd, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_013E:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_015D
    CallTrainerBattleEnd
    VMJump L_015F

L_015D:
    CallTrainerLose

L_015F:
    VMReturn

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_019C:
    Move 15, 1
    Move 33, 1
    MoveEnd
    VMStackMul
    VMNop2
    RTReserveScript 1
    PokePartyGetSpecies 0, 15
    VMHalt
    .byte 0xfe
    .balign 4, 0

Movement_01BC:
    Move 14, 2
    MoveEnd
    Move 32, 1
    MoveEnd

Movement_01CC:
    Move 33, 1
    MoveEnd
    Move 75, 1
    MoveEnd

Movement_01DC:
    Move 33, 1
    Move 75, 1
    MoveEnd
