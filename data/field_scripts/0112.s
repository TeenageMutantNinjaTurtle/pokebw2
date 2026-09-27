#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
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
    WorkSetConst 0x8020, 0
    Cmd_01CC 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_006B
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_00D9

L_006B:
    ParentActorMsg 1024, 2, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00CB
    Cmd_01CD 0
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00B7
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_00C5

L_00B7:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00C5:
    VMJump L_00D9

L_00CB:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00D9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x8021, 0
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2761
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_025F
    ActorMsg 1024, 6, 5, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0249
    MsgWinCloseAll
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    CallPokeSelect 0, 0x8023, 0x8022, 0
    PokePartyIsEgg 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0233
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_021D
    ActorMsg 1024, 8, 5, 0, 0
    ActorMsgClose
    FadeEx 3, 0, 16, 2
    FadeExWait
    MEPlay 1937
    MEWait
    FadeEx 3, 16, 0, 2
    FadeExWait
    Random 0x400a, 100
    VMStackPush 0x400a
    VMStackPushConst 5
    VMStackCmp 3
    VMJumpIf 255, L_01CA
    PokePartyAdjustHappiness 0x8022, 30, 1
    ActorMsg 1024, 10, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0213

L_01CA:
    VMStackPush 0x400a
    VMStackPushConst 25
    VMStackCmp 3
    VMJumpIf 255, L_01FB
    PokePartyAdjustHappiness 0x8022, 10, 1
    ActorMsg 1024, 11, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0213

L_01FB:
    PokePartyAdjustHappiness 0x8022, 5, 1
    ActorMsg 1024, 12, 5, 0, 0
    LastKeyWait
    ActorMsgClose

L_0213:
    FlagSet 2761
    VMJump L_022D

L_021D:
    ActorMsg 1024, 7, 5, 0, 0
    LastKeyWait
    ActorMsgClose

L_022D:
    VMJump L_0243

L_0233:
    ActorMsg 1024, 9, 5, 0, 0
    LastKeyWait
    ActorMsgClose

L_0243:
    VMJump L_0259

L_0249:
    ActorMsg 1024, 7, 5, 0, 0
    LastKeyWait
    ActorMsgClose

L_0259:
    VMJump L_026F

L_025F:
    ActorMsg 1024, 13, 5, 0, 0
    LastKeyWait
    ActorMsgClose

L_026F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 505, 0
    ParentActorMsg 1024, 15, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
