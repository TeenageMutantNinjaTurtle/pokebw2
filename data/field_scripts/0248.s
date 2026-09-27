#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 539
    WorkSet 0x8001, 1
    WorkSet 0x8002, 240
    WorkSet 0x8003, 3
    WorkSet 0x8004, 4
    WorkSet 0x8005, 4
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    VMStackPushFlag 444
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0163
    VMStackPushFlag 241
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0149
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 6, 1, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0133
    ActorMsg 1024, 8, 1, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 543
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 9, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 241
    VMJump L_0143

L_0133:
    ActorMsg 1024, 7, 1, 0, 0
    LastKeyWait
    ActorMsgClose

L_0143:
    VMJump L_015D

L_0149:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose

L_015D:
    VMJump L_0177

L_0163:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose

L_0177:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 444
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01CB
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01BB
    ParentActorMsg 1024, 0, 0, 0
    VMJump L_01C5

L_01BB:
    ParentActorMsg 1024, 2, 0, 0

L_01C5:
    VMJump L_01D5

L_01CB:
    ParentActorMsg 1024, 1, 0, 0

L_01D5:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
