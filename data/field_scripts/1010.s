#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPushFlag 2458
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0050
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    Cmd_0275 0, 15, 0
    SEPlay 1908
    SystemMsg 1, 0
    SEWait
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2458
    VMJump L_0064

L_0050:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0064:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
