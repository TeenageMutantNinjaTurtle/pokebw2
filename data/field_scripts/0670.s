#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    MsgWaitAdvance
    PokePartyGetCount 0x8020, 0

L_003E:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_0092
    PokePartyGetSpecies 0x8022, 0x8021
    PokePartyIsEgg 0x8024, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 638
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0086
    WorkSetConst 0x8023, 1

L_0086:
    WorkAdd 0x8021, 1
    VMJump L_003E

L_0092:
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C9
    MsgWinCloseAll
    ActorCmdExec 2, Movement_00E0
    ActorCmdWait
    VMSleep 8
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_00D7

L_00C9:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00D7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_00E0:
    Move 75, 1
    MoveEnd
