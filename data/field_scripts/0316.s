#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_4:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    VMStackPushFlag 216
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D5
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 237
    WorkSet 0x8001, 1
    WorkSet 0x8002, 216
    WorkSet 0x8003, 1
    WorkSet 0x8004, 2
    WorkSet 0x8005, 2
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0116

L_00D5:
    VMStackPushFlag 2503
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0102
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0116

L_0102:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_0116:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMStackPushFlag 2447
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_019C
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8021, 0
    GameGetVersion 0x8021
    VMStackPush 0x8021
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_016D
    Cmd_0275 0, 9, 0
    VMJump L_0174

L_016D:
    Cmd_0275 0, 10, 0

L_0174:
    SEPlay 1908
    SystemMsg 6, 0
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2447
    VMJump L_01B0

L_019C:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose

L_01B0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
