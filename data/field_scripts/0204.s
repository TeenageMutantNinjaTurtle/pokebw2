#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

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

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 321
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B0
    WorkSetConst 0x8020, 0
    ActorMsg 1024, 1, 0, 0, 0
    YesNoWin 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0096
    VMCall L_0148
    VMJump L_00A6

L_0096:
    ActorMsg 1024, 5, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_00A6:
    FlagSet 321
    VMJump L_0142

L_00B0:
    VMStackPushFlag 2759
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_012D
    VMStackPushFlag 2758
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0121
    WorkSetConst 0x8021, 0
    ActorMsg 1024, 2, 0, 0, 0
    YesNoWin 0x8021
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_010B
    VMCall L_0148
    VMJump L_011B

L_010B:
    ActorMsg 1024, 5, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_011B:
    VMJump L_0127

L_0121:
    VMCall L_0148

L_0127:
    VMJump L_0142

L_012D:
    WordSetMoveName 0, 0x4183
    ActorMsg 1024, 8, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0142:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0148:
    VMStackPushFlag 2758
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01FD
    ItemGetRandomOwnedTMMove 0x4183
    FlagSet 2758
    WordSetMoveName 0, 0x4183
    WorkSetConst 0x8022, 0
    PokePartyHasMoveAny 0x8022, 0x4183
    DebugPrint 0x8022
    DebugPrint 0x4183
    VMStackPush 0x8022
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_01A5
    ActorMsg 1024, 6, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01F1

L_01A5:
    WordSetPartyPokeSpecies 1, 0x8022
    ActorMsg 1024, 4, 0, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 93
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    WordSetMoveName 0, 0x4183
    ActorMsg 1024, 8, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 2759

L_01F1:
    WorkSetConst 0x8022, 0
    VMJump L_0291

L_01FD:
    WordSetMoveName 0, 0x4183
    WorkSetConst 0x8023, 0
    PokePartyHasMoveAny 0x8023, 0x4183
    DebugPrint 0x8023
    DebugPrint 0x4183
    VMStackPush 0x8023
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_023F
    ActorMsg 1024, 6, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_028B

L_023F:
    WordSetPartyPokeSpecies 1, 0x8023
    ActorMsg 1024, 7, 0, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 93
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    WordSetMoveName 0, 0x4183
    ActorMsg 1024, 8, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 2759

L_028B:
    WorkSetConst 0x8023, 0

L_0291:
    VMReturn
    .balign 4, 0
