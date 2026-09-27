#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    VMStackPush 0x40a7
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40a1
    VMStackPushConst 7
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0045
    FlagSet 803
    VMJump L_0049

L_0045:
    FlagReset 803

L_0049:
    VMStackPushFlag 965
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0083
    VMStackPushFlag 483
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 490
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0083
    FlagReset 965

L_0083:
    VMHalt

Script_2:
    ActorsPauseAll
    WordSetPlayerName 0
    RecordGet 71, 0x400f
    VMStackPush 0x40a1
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00BD
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01E1

L_00BD:
    VMStackPush 0x40a7
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x40a1
    VMStackPushConst 8
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0100
    VMCall L_01E7
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01E1

L_0100:
    VMStackPush 0x40a7
    VMStackPushConst 1
    VMStackCmp 4
    VMStackPush 0x40a8
    VMStackPushConst 2
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0143
    VMCall L_01E7
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01E1

L_0143:
    VMStackPush 0x4124
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01C7
    VMCall L_01E7
    VMStackPushFlag 483
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 490
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 965
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_01A9
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01C1

L_01A9:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 490

L_01C1:
    VMJump L_01E1

L_01C7:
    VMCall L_01E7
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose

L_01E1:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_01E7:
    PokePartyGetMemberByType 0x8020, 2
    WordSetPartyPokeSpecies 1, 0x8020
    VMReturn

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 510, 0
    ParentActorMsg 1024, 6, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 8, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
