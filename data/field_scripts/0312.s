#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

Script_1:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 331
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_003B
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0061

L_003B:
    ParentActorMsg 1024, 0, 0, 0
    ParentActorMsg 1024, 1, 0, 0
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 331

L_0061:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
