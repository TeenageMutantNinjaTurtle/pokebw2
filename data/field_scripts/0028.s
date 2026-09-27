#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_003F
    WorkSetConst 0x4020, 209
    VMJump L_0045

L_003F:
    WorkSetConst 0x4020, 129

L_0045:
    VMHalt

Script_2:
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
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 504, 0
    ParentActorMsg 1024, 2, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_00DE
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 546, 0
    ParentActorMsg 1024, 3, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_00FA

L_00DE:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 548, 0
    ParentActorMsg 1024, 4, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose

L_00FA:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
