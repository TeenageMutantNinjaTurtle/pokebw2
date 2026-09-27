#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_4:
    ActorsPauseAll
    ActorCmdExec 2, Movement_041C
    VMSleep 4
    ActorCmdExec 4, Movement_0410
    ActorCmdExec 3, Movement_0410
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    WorkSub 0x8022, 1
    ActorWalkRoute 4, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 4, Movement_03F8
    ActorCmdWait
    ActorMsg 1024, 0, 4, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 754, 0, 0
    VMCall L_0382
    ActorMsg 1024, 1, 4, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkSetConst 0x4147, 1
    TrainerFlagSet 754
    ActorCmdExec 4, Movement_03AC
    VMSleep 8
    ActorCmdExec 3, Movement_03BC
    VMSleep 4
    ActorCmdExec 255, Movement_0400
    ActorCmdWait
    VMCall L_020B
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    VMStackPush 0x4147
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_00FD
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0111

L_00FD:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_0111:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    TrainerFlagGet 755, 0x400f
    VMStackPush 0x4147
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_014C
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_018B

L_014C:
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0179
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_018B

L_0179:
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_020B
    VMCall L_0265

L_018B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    TrainerFlagGet 756, 0x400f
    TrainerFlagGet 755, 0x400e
    VMStackPush 0x4147
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_01CC
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0205

L_01CC:
    VMStackPush 0x400e
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01F9
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0205

L_01F9:
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0265

L_0205:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_020B:
    ActorMsg 1024, 4, 3, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 755, 0, 0
    VMCall L_0382
    ActorMsg 1024, 5, 3, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 3, Movement_03CC
    VMSleep 8
    ActorCmdExec 2, Movement_03DC
    VMSleep 4
    ActorCmdExec 255, Movement_03F0
    ActorCmdWait
    WorkSetConst 0x4147, 2
    TrainerFlagSet 755
    VMReturn

L_0265:
    ActorMsg 1024, 8, 2, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 756, 0, 0
    VMCall L_0382
    ActorMsg 1024, 9, 2, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 2, Movement_03E4
    ActorCmdWait
    MedalGive 95
    WorkSetConst 0x4147, 3
    TrainerFlagSet 756
    VMReturn

L_02AB:
    VMStackPush 0x4147
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F4
    ActorSetGPos 255, 17, 0, 6, 3
    ActorSetGPos 2, 17, 0, 4, 1
    ActorSetGPos 4, 18, 0, 6, 2
    ActorSetGPos 3, 15, 0, 5, 1
    VMJump L_0380

L_02F4:
    VMStackPush 0x4147
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_033D
    ActorSetGPos 255, 17, 0, 6, 2
    ActorSetGPos 2, 17, 0, 4, 1
    ActorSetGPos 4, 19, 0, 5, 1
    ActorSetGPos 3, 16, 0, 6, 3
    VMJump L_0380

L_033D:
    VMStackPush 0x4147
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0380
    ActorSetGPos 255, 17, 0, 6, 0
    ActorSetGPos 2, 17, 0, 5, 1
    ActorSetGPos 4, 19, 0, 5, 2
    ActorSetGPos 3, 15, 0, 5, 3

L_0380:
    VMReturn

L_0382:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03A7
    VMCall L_02AB
    CallTrainerBattleEnd
    VMJump L_03A9

L_03A7:
    CallTrainerLose

L_03A9:
    VMReturn
    .balign 4, 0

Movement_03AC:
    Move 15, 1
    Move 12, 1
    Move 33, 1
    MoveEnd

Movement_03BC:
    Move 15, 1
    Move 13, 1
    Move 35, 1
    MoveEnd

Movement_03CC:
    Move 14, 1
    Move 12, 1
    Move 33, 1
    MoveEnd

Movement_03DC:
    Move 13, 1
    MoveEnd

Movement_03E4:
    Move 12, 1
    Move 33, 1
    MoveEnd

Movement_03F0:
    Move 32, 1
    MoveEnd

Movement_03F8:
    Move 33, 1
    MoveEnd

Movement_0400:
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_0410:
    Move 33, 1
    Move 75, 1
    MoveEnd

Movement_041C:
    Move 75, 1
    MoveEnd
