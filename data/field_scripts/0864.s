#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPushFlag 2401
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0039
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_004D

L_0039:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_004D:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    VMStackPushFlag 2401
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0086
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgGendered 1024, 3, 4, 1, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_009A

L_0086:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_009A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
