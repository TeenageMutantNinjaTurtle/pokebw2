#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_1:
    WorkSetConst 0x8020, 0
    Random 0x8020, 3
    VMStackPushFlag 2754
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2755
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2756
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_009E
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_006A
    FlagSet 2754
    VMJump L_009E

L_006A:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0087
    FlagSet 2755
    VMJump L_009E

L_0087:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_009E
    FlagSet 2756

L_009E:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2754
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00CD
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    VMJump L_0111

L_00CD:
    VMStackPushFlag 2755
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00F2
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    VMJump L_0111

L_00F2:
    VMStackPushFlag 2756
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0111
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait

L_0111:
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2754
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0146
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    VMJump L_018A

L_0146:
    VMStackPushFlag 2755
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_016B
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    VMJump L_018A

L_016B:
    VMStackPushFlag 2756
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_018A
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait

L_018A:
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
