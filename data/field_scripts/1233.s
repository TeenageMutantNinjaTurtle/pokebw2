#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0047
    VMCall L_017C
    VMJump L_004D

L_0047:
    VMCall L_0053

L_004D:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0053:
    ParentActorMsg 1024, 1, 0, 0
    ActorMsgClose
    CallPokeSelect 0, 0x8010, 0x8020, 0
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0088
    VMCall L_017C
    VMJump L_008E

L_0088:
    VMCall L_0090

L_008E:
    VMReturn

L_0090:
    PokePartyIsEgg 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00BB
    WorkSetConst 0x8021, 8
    VMCall L_016C
    VMJump L_012A

L_00BB:
    WordSetPartyPokeName 0, 0x8020
    PokePartyIsOriginGame 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00EB
    WorkSetConst 0x8021, 7
    VMCall L_016C
    VMJump L_012A

L_00EB:
    ParentActorMsg 1024, 2, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0118
    VMCall L_017C
    VMJump L_012A

L_0118:
    ParentActorMsg 1024, 3, 0, 0
    ActorMsgClose
    VMCall L_012C

L_012A:
    VMReturn

L_012C:
    CallPokeNameInput 0x8010, 0x8020, 1
    WordSetPartyPokeName 0, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_015E
    WorkSetConst 0x8021, 6
    VMCall L_016C
    VMJump L_016A

L_015E:
    WorkSetConst 0x8021, 4
    VMCall L_016C

L_016A:
    VMReturn

L_016C:
    ParentActorMsg 1024, 0x8021, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_017C:
    WorkSetConst 0x8021, 5
    VMCall L_016C
    VMReturn
    .balign 4, 0
