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
    WorkSetConst 0x8025, 0
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0061
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01E3

L_0061:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 342
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01B2
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    PokePartyGetCount 0x8020, 0

L_0096:
    VMStackPush 0x8020
    VMStackPush 0x8021
    VMStackCmp 2
    VMJumpIf 255, L_00EA
    PokePartyGetSpecies 0x8022, 0x8021
    PokePartyIsEgg 0x8025, 0x8021
    VMStackPush 0x8022
    VMStackPushConst 370
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00DE
    WorkSetConst 0x8023, 1

L_00DE:
    WorkAdd 0x8021, 1
    VMJump L_0096

L_00EA:
    ItemCheckSpace 93, 5, 0x8024
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_015B
    ParentActorMsg 1024, 2, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 93
    WorkSet 0x8001, 5
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 342
    VMJump L_01AC

L_015B:
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_019E
    ParentActorMsg 1024, 2, 0, 0
    MsgWaitAdvance
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01AC

L_019E:
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01AC:
    VMJump L_01E3

L_01B2:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 342
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01E3
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01E3:
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

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 618, 0
    ParentActorMsg 1024, 7, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
