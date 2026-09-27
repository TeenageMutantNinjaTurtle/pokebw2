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
    WorkSetConst 0x8020, 0
    MedalGetCount 3, 0x8020
    WordSetNumber 0, 0x8020, 3
    ParentActorMsg 1024, 0, 0, 0
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0069
    ParentActorMsg 1024, 1, 0, 0
    VMJump L_0185

L_0069:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 29
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_009C
    ParentActorMsg 1024, 2, 0, 0
    VMJump L_0185

L_009C:
    VMStackPush 0x8020
    VMStackPushConst 30
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 49
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_00CF
    ParentActorMsg 1024, 3, 0, 0
    VMJump L_0185

L_00CF:
    VMStackPush 0x8020
    VMStackPushConst 50
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 99
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0102
    ParentActorMsg 1024, 4, 0, 0
    VMJump L_0185

L_0102:
    VMStackPush 0x8020
    VMStackPushConst 100
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 199
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0135
    ParentActorMsg 1024, 5, 0, 0
    VMJump L_0185

L_0135:
    VMStackPush 0x8020
    VMStackPushConst 200
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 254
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0168
    ParentActorMsg 1024, 6, 0, 0
    VMJump L_0185

L_0168:
    VMStackPush 0x8020
    VMStackPushConst 255
    VMStackCmp 1
    VMJumpIf 255, L_0185
    ParentActorMsg 1024, 7, 0, 0

L_0185:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 524, 0
    ParentActorMsg 1024, 10, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
