#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
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

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 320
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00A9
    SystemMsg 2, 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 197
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    PVPlay 610, 0
    ActorMsg 1024, 3, 2, 0, 0
    PVWait
    LastKeyWait
    MsgWinCloseAll
    FlagSet 320
    VMJump L_00C5

L_00A9:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 610, 0
    ParentActorMsg 1024, 3, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose

L_00C5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
