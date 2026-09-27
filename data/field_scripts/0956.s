#include "asm/field_script.inc"

// Script plugin 9, from the zones that use this file

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_0061
    WorkSetConst 0x8021, 0
    VMJump L_0086

L_0061:
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMJumpIf 255, L_0080
    WorkSetConst 0x8021, 1
    VMJump L_0086

L_0080:
    WorkSetConst 0x8021, 2

L_0086:
    ParentActorMsg 1024, 0x8021, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_00C5
    WorkSetConst 0x8021, 3
    VMJump L_00EA

L_00C5:
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMJumpIf 255, L_00E4
    WorkSetConst 0x8021, 4
    VMJump L_00EA

L_00E4:
    WorkSetConst 0x8021, 5

L_00EA:
    ParentActorMsg 1024, 0x8021, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
