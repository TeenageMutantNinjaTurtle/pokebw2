#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd

Script_5:
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_003F
    WorkSetConst 0x4020, 209
    WorkSetConst 0x4021, 209
    VMJump L_004B

L_003F:
    WorkSetConst 0x4020, 129
    WorkSetConst 0x4021, 129

L_004B:
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 256
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_007E
    ActorMsg 1024, 5, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0155

L_007E:
    ActorMsg 1024, 0, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0145
    ActorMsgClose
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    CallPokeSelect 0, 0x8021, 0x8020, 0
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_012F
    WorkSetConst 0x8022, 0
    FieldTradeCheck 0x8022, 26, 0x8020
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0119
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FieldTradeStart 26, 0x8020
    ActorMsg 1024, 2, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 256
    VMJump L_0129

L_0119:
    ActorMsg 1024, 3, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0129:
    VMJump L_013F

L_012F:
    ActorMsg 1024, 4, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_013F:
    VMJump L_0155

L_0145:
    ActorMsg 1024, 4, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0155:
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_01C4
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 546, 0
    ParentActorMsg 1024, 9, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_01E0

L_01C4:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 548, 0
    ParentActorMsg 1024, 7, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose

L_01E0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0221
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 546, 0
    ParentActorMsg 1024, 10, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_023D

L_0221:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 548, 0
    ParentActorMsg 1024, 8, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose

L_023D:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
