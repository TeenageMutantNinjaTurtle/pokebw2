#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    RTCGetDayPart 0x8020
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0045
    FlagReset 786
    VMJump L_0049

L_0045:
    FlagSet 786

L_0049:
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
    VMStackPushFlag 2784
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0142
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 1, 2, 0, 0
    ActorMsgClose
    Random 0x400f, 3
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00CF
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 151
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0128

L_00CF:
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0108
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 165
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0128

L_0108:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 154
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000

L_0128:
    ActorMsg 1024, 2, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 2784
    VMJump L_0156

L_0142:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_0156:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
