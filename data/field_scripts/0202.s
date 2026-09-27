#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
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
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    PokeDexGetCount 0, 0x8020
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8020
    VMStackPushConst 70
    VMStackCmp 4
    VMJumpIf 255, L_00FE
    VMStackPushFlag 319
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00E8
    ActorMsg 1024, 2, 0, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 253
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 3, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 319
    VMJump L_00F8

L_00E8:
    ActorMsg 1024, 3, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_00F8:
    VMJump L_010E

L_00FE:
    ActorMsg 1024, 1, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_010E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
