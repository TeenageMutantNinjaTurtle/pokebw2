#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
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

L_003A:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_008E
    PokePartyIsFullHP 0x8022, 0x8021
    PokePartyIsFullPP 0x8023, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0082
    WorkAdd 0x8024, 1

L_0082:
    WorkAdd 0x8021, 1
    VMJump L_003A

L_008E:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 4
    VMJumpIf 255, L_00E1
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
    VMJump L_00EF

L_00E1:
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00EF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 531, 0
    ParentActorMsg 1024, 2, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 610, 0
    ParentActorMsg 1024, 3, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
