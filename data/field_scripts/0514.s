#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0

Script_1:
    ActorsPauseAll
    VMStackPushFlag 457
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0077
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0289

L_0077:
    SEPlay 1351
    ActorSetEyeToEye
    TrainerFlagGet 335, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01DD
    VMStackPushFlag 456
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00BD
    ParentActorMsg 1024, 0, 0, 0
    FlagSet 456
    VMJump L_00C7

L_00BD:
    ParentActorMsg 1024, 3, 0, 0

L_00C7:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01C9
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 335, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0115
    CallTrainerBattleEnd
    TrainerFlagSet 335
    VMJump L_0117

L_0115:
    CallTrainerLose

L_0117:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01B5
    ParentActorMsg 1024, 4, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 5, 0, 0
    VMCall L_028F
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01AB
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_03C8
    ActorCmdWait
    ParentActorMsg 1024, 6, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 157
    WorkSet 0x8001, 3
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 457
    VMJump L_01AF

L_01AB:
    LastKeyWait
    MsgWinCloseAll

L_01AF:
    VMJump L_01C3

L_01B5:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01C3:
    VMJump L_01D7

L_01C9:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01D7:
    VMJump L_0289

L_01DD:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_027B
    ParentActorMsg 1024, 4, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 5, 0, 0
    VMCall L_028F
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0271
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_03C8
    ActorCmdWait
    ParentActorMsg 1024, 7, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 157
    WorkSet 0x8001, 3
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 457
    VMJump L_0275

L_0271:
    LastKeyWait
    MsgWinCloseAll

L_0275:
    VMJump L_0289

L_027B:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0289:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_028F:
    PokePartyGetCount 0x8020, 0

L_0295:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_0306
    PokePartyGetParam 0x8022, 0x8021, 10
    PokePartyIsEgg 0x8024, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 118
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_02FA
    PokePartyGetSpecies 0x8026, 0x8021
    WordSetPokeSpecies 0, 0x8026
    WorkSetConst 0x8023, 1

L_02FA:
    WorkAdd 0x8021, 1
    VMJump L_0295

L_0306:
    VMReturn

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 572, 0
    ParentActorMsg 1024, 12, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 504, 0
    ParentActorMsg 1024, 13, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 552, 0
    ParentActorMsg 1024, 14, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_03C8:
    Move 75, 1
    MoveEnd
