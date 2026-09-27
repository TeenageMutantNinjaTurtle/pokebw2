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
    VMStackPush 0x40ee
    VMStackPushConst 3
    VMStackCmp 4
    VMStackPushFlag 824
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0053
    ActorSetGPos 2, 14, 0, 7, 1

L_0053:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40ee
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0107
    ParentActorMsg 1024, 0, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 458, 0, 0
    VMCall L_01AB
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkSetConst 0x40ee, 3
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 14
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 7
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00E7
    ActorWalkRoute 2, 14, 9, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 2, Movement_024C
    ActorCmdWait
    VMJump L_0101

L_00E7:
    ActorWalkRoute 2, 14, 7, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 2, Movement_0254
    ActorCmdWait

L_0101:
    VMJump L_0128

L_0107:
    VMStackPush 0x40ee
    VMStackPushConst 3
    VMStackCmp 4
    VMJumpIf 255, L_0128
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0128:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerFlagGet 455, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0197
    TrainerBGMPlayPush 455
    ParentActorMsg 1024, 2, 0, 0
    ActorMsgClose
    CallTrainerBattle 455, 0, 0
    VMCall L_01AB
    WorkSetConst 0x40ef, 1
    FlagSet 341
    FlagSet 827
    FlagReset 828
    TrainerFlagSet 455
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01A5

L_0197:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01A5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_01AB:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01CA
    CallTrainerBattleEnd
    VMJump L_01CC

L_01CA:
    CallTrainerLose

L_01CC:
    VMReturn

Script_4:
    ActorsPauseAll
    TrainerBGMPlayPush 455
    ActorCmdExec 3, Movement_026C
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    WorkSub 0x8022, 1
    ActorWalkRoute 3, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_024C
    ActorCmdWait
    ActorMsg 1024, 2, 3, 0, 0
    ActorMsgClose
    CallTrainerBattle 455, 0, 0
    VMCall L_01AB
    WorkSetConst 0x40ef, 1
    FlagSet 341
    FlagSet 827
    FlagReset 828
    TrainerFlagSet 455
    ActorMsg 1024, 3, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_024C:
    Move 32, 1
    MoveEnd

Movement_0254:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_026C:
    Move 189, 1
    MoveEnd
