#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2772
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02E0
    VMStackPushFlag 2771
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B0

L_006E:
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00AC
    Random 0x8020, 201
    VMStackPush 0x8020
    VMStackPushConst 50
    VMStackCmp 4
    VMJumpIf 255, L_00A6
    WorkGet 0x4187, 0x8020
    WorkSetConst 0x8021, 1

L_00A6:
    VMJump L_006E

L_00AC:
    FlagSet 2771

L_00B0:
    ParentActorMsg 1024, 0, 0, 0
    MsgWaitAdvance
    WordSetNumber 1, 0x4187, 3
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    PokePartyGetCount 0x8022, 0

L_00D5:
    VMStackPush 0x8022
    VMStackPush 0x8023
    VMStackCmp 2
    VMJumpIf 255, L_015B
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_014F
    PokePartyGetParam 0x8024, 0x8023, 164
    PokePartyIsEgg 0x8027, 0x8023
    PokePartyGetParam 0x8028, 0x8023, 160
    VMStackPush 0x8024
    VMStackPush 0x4187
    VMStackCmp 1
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 2
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_014F
    WordSetPartyPokeSpecies 0, 0x8023
    WorkSetConst 0x8026, 1

L_014F:
    WorkAdd 0x8023, 1
    VMJump L_00D5

L_015B:
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01FA
    WorkSetConst 0x8023, 0

L_0174:
    VMStackPush 0x8022
    VMStackPush 0x8023
    VMStackCmp 2
    VMJumpIf 255, L_01FA
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01EE
    PokePartyGetParam 0x8024, 0x8023, 164
    PokePartyIsEgg 0x8027, 0x8023
    PokePartyGetParam 0x8028, 0x8023, 160
    VMStackPush 0x8024
    VMStackPush 0x4187
    VMStackCmp 4
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 2
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_01EE
    WordSetPartyPokeSpecies 0, 0x8023
    WorkSetConst 0x8025, 1

L_01EE:
    WorkAdd 0x8023, 1
    VMJump L_0174

L_01FA:
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_025D
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0310
    ActorCmdWait
    ParentActorMsg 1024, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 565
    WorkSet 0x8001, 5
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2772
    VMJump L_02DA

L_025D:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02C0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0310
    ActorCmdWait
    ParentActorMsg 1024, 2, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 565
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2772
    VMJump L_02DA

L_02C0:
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0310
    ActorCmdWait
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02DA:
    VMJump L_02EE

L_02E0:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02EE:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0310:
    Move 161, 1
    MoveEnd
