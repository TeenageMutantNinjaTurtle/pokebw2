#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPush 0x4150
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0035
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0049

L_0035:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0049:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
