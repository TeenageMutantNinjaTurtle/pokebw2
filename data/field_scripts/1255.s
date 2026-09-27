#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 252
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0043
    ParentActorMsg 1024, 1, 0, 0
    VMJump L_0051

L_0043:
    ParentActorMsg 1024, 0, 0, 0
    FlagSet 252

L_0051:
    ActorMsgClose
    VMCall L_005F
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_005F:
    CallPokeSelect 0, 0x8010, 0x8020, 0
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_008C
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_008C:
    PokePartyIsEgg 0x8010, 0x8020
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00B5
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_00B5:
    PokePartyGetIV 0x8020, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 90
    VMStackCmp 3
    VMJumpIf 255, L_00E0
    ParentActorMsg 1024, 4, 0, 0
    VMJump L_0130

L_00E0:
    VMStackPush 0x8010
    VMStackPushConst 120
    VMStackCmp 3
    VMJumpIf 255, L_0103
    ParentActorMsg 1024, 5, 0, 0
    VMJump L_0130

L_0103:
    VMStackPush 0x8010
    VMStackPushConst 150
    VMStackCmp 3
    VMJumpIf 255, L_0126
    ParentActorMsg 1024, 6, 0, 0
    VMJump L_0130

L_0126:
    ParentActorMsg 1024, 7, 0, 0

L_0130:
    PokePartyGetIV 0x8020, 1, 0x8022
    WorkSetConst 0x8021, 1
    PokePartyGetIV 0x8020, 2, 0x8010
    VMStackPush 0x8010
    VMStackPush 0x8022
    VMStackCmp 1
    VMJumpIf 255, L_0169
    WorkSetConst 0x8021, 0
    ParentActorMsg 1024, 8, 0, 0

L_0169:
    PokePartyGetIV 0x8020, 3, 0x8010
    VMStackPush 0x8010
    VMStackPush 0x8022
    VMStackCmp 1
    VMJumpIf 255, L_01B7
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01A7
    ParentActorMsg 1024, 9, 0, 0
    VMJump L_01B1

L_01A7:
    ParentActorMsg 1024, 14, 0, 0

L_01B1:
    WorkSetConst 0x8021, 0

L_01B7:
    PokePartyGetIV 0x8020, 4, 0x8010
    VMStackPush 0x8010
    VMStackPush 0x8022
    VMStackCmp 1
    VMJumpIf 255, L_0205
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01F5
    ParentActorMsg 1024, 10, 0, 0
    VMJump L_01FF

L_01F5:
    ParentActorMsg 1024, 15, 0, 0

L_01FF:
    WorkSetConst 0x8021, 0

L_0205:
    PokePartyGetIV 0x8020, 6, 0x8010
    VMStackPush 0x8010
    VMStackPush 0x8022
    VMStackCmp 1
    VMJumpIf 255, L_0253
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0243
    ParentActorMsg 1024, 11, 0, 0
    VMJump L_024D

L_0243:
    ParentActorMsg 1024, 16, 0, 0

L_024D:
    WorkSetConst 0x8021, 0

L_0253:
    PokePartyGetIV 0x8020, 7, 0x8010
    VMStackPush 0x8010
    VMStackPush 0x8022
    VMStackCmp 1
    VMJumpIf 255, L_02A1
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0291
    ParentActorMsg 1024, 12, 0, 0
    VMJump L_029B

L_0291:
    ParentActorMsg 1024, 17, 0, 0

L_029B:
    WorkSetConst 0x8021, 0

L_02A1:
    PokePartyGetIV 0x8020, 5, 0x8010
    VMStackPush 0x8010
    VMStackPush 0x8022
    VMStackCmp 1
    VMJumpIf 255, L_02EF
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02DF
    ParentActorMsg 1024, 13, 0, 0
    VMJump L_02E9

L_02DF:
    ParentActorMsg 1024, 18, 0, 0

L_02E9:
    WorkSetConst 0x8021, 0

L_02EF:
    VMStackPush 0x8022
    VMStackPushConst 15
    VMStackCmp 3
    VMJumpIf 255, L_0312
    ParentActorMsg 1024, 19, 0, 0
    VMJump L_0362

L_0312:
    VMStackPush 0x8022
    VMStackPushConst 25
    VMStackCmp 3
    VMJumpIf 255, L_0335
    ParentActorMsg 1024, 20, 0, 0
    VMJump L_0362

L_0335:
    VMStackPush 0x8022
    VMStackPushConst 30
    VMStackCmp 3
    VMJumpIf 255, L_0358
    ParentActorMsg 1024, 21, 0, 0
    VMJump L_0362

L_0358:
    ParentActorMsg 1024, 22, 0, 0

L_0362:
    LastKeyWait
    ActorMsgClose
    VMReturn
