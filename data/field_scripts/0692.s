#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_2:
    ActorsPauseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    PokePartyGetCount 0x8020, 0

L_003E:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_00CB
    PokePartyGetSpecies 0x8022, 0x8021
    PokePartyGetForme 0x8023, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 647
    VMStackCmp 1
    VMJumpIf 255, L_00BB
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00A2
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 3
    VMJumpIf 255, L_009C
    WorkSetConst 0x8024, 2

L_009C:
    VMJump L_00BB

L_00A2:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 3
    VMJumpIf 255, L_00BB
    WorkSetConst 0x8024, 1

L_00BB:
    DebugPrint 0x8023
    WorkAdd 0x8021, 1
    VMJump L_003E

L_00CB:
    DebugPrint 0x8024
    WorkCmpConst 0x8024, 0
    VMJumpIf 1, L_00E2
    VMJump L_00FC

L_00E2:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0192

L_00FC:
    WorkCmpConst 0x8024, 1
    VMJumpIf 1, L_010F
    VMJump L_0147

L_010F:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    ParentActorMsg 1024, 6, 0, 0
    ParentActorMsg 1024, 7, 0, 0
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0192

L_0147:
    WorkCmpConst 0x8024, 2
    VMJumpIf 1, L_015A
    VMJump L_0192

L_015A:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    ParentActorMsg 1024, 6, 0, 0
    ParentActorMsg 1024, 7, 0, 0
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0192

L_0192:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
