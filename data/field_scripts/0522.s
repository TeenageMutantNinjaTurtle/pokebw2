#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
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
    PokePartyGetCount 0x8020, 0

L_0036:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_008A
    PokePartyIsFullHP 0x8022, 0x8021
    PokePartyIsFullPP 0x8023, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_007E
    WorkAdd 0x8024, 1

L_007E:
    WorkAdd 0x8021, 1
    VMJump L_0036

L_008A:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_00DD
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 2
    FadeExWait
    PokePartyRecoverAll
    MEPlay 1300
    MEWait
    FadeEx 3, 16, 0, 2
    FadeExWait
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_00EB

L_00DD:
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00EB:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 575, 0
    ParentActorMsg 1024, 2, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
