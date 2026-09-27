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
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2772
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02FC
    VMStackPushFlag 2771
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00CC

L_008A:
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00C8
    Random 0x8020, 201
    VMStackPush 0x8020
    VMStackPushConst 50
    VMStackCmp 4
    VMJumpIf 255, L_00C2
    WorkGet 0x4187, 0x8020
    WorkSetConst 0x8021, 1

L_00C2:
    VMJump L_008A

L_00C8:
    FlagSet 2771

L_00CC:
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    WordSetNumber 1, 0x4187, 3
    ParentActorMsg 1024, 2, 0, 0
    MsgWaitAdvance
    PokePartyGetCount 0x8022, 0

L_00F1:
    VMStackPush 0x8022
    VMStackPush 0x8023
    VMStackCmp 2
    VMJumpIf 255, L_0177
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_016B
    PokePartyGetParam 0x8024, 0x8023, 162
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
    VMJumpIf 255, L_016B
    WordSetPartyPokeSpecies 0, 0x8023
    WorkSetConst 0x8026, 1

L_016B:
    WorkAdd 0x8023, 1
    VMJump L_00F1

L_0177:
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0216
    WorkSetConst 0x8023, 0

L_0190:
    VMStackPush 0x8022
    VMStackPush 0x8023
    VMStackCmp 2
    VMJumpIf 255, L_0216
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_020A
    PokePartyGetParam 0x8024, 0x8023, 162
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
    VMJumpIf 255, L_020A
    WordSetPartyPokeSpecies 0, 0x8023
    WorkSetConst 0x8025, 1

L_020A:
    WorkAdd 0x8023, 1
    VMJump L_0190

L_0216:
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0279
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0310
    ActorCmdWait
    ParentActorMsg 1024, 4, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 570
    WorkSet 0x8001, 5
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2772
    VMJump L_02F6

L_0279:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02DC
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0310
    ActorCmdWait
    ParentActorMsg 1024, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 570
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2772
    VMJump L_02F6

L_02DC:
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0310
    ActorCmdWait
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02F6:
    VMJump L_030A

L_02FC:
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_030A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0310:
    Move 161, 1
    MoveEnd
