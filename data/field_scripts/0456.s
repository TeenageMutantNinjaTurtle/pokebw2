#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetGPos 0x8021, 0x8022
    SEPlay 1369
    ActorNew 21, 0x8022, 0, 251, 291, 0
    SEWait
    BGMPlay 1237
    InfoMsg 0, 2
    InfoMsgClose_0039
    ActorCmdExec 255, Movement_018C
    ActorCmdWait
    WorkAdd 0x8021, 2
    ActorWalkRoute 251, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorMsg 1024, 1, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_016C
    ActorCmdWait
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_009E
    CallTrainerBattle 684, 0, 0
    VMJump L_00C7

L_009E:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00BF
    CallTrainerBattle 685, 0, 0
    VMJump L_00C7

L_00BF:
    CallTrainerBattle 686, 0, 0

L_00C7:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00E6
    CallTrainerBattleEnd
    VMJump L_00E8

L_00E6:
    CallTrainerLose

L_00E8:
    VMSleep 8
    ActorCmdExec 251, Movement_017C
    ActorCmdWait
    ActorMsg 1024, 2, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_01AC
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 351
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 3, 251, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 21, 0x8022, 1, 8, 0
    ActorCmdWait
    SEPlay 1369
    ActorDelete 251
    SEWait
    BGMChangeMap
    WorkSetConst 0x4124, 1
    Cmd_0262 1, 38
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_016C:
    Move 100, 1
    MoveEnd
    Move 32, 1
    MoveEnd

Movement_017C:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_018C:
    Move 35, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd

Movement_01AC:
    Move 14, 1
    MoveEnd
