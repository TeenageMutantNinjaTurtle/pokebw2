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
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 255
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 22
    WorkSet 0x8001, 1
    RTCallGlobal 10110
    VMStackPop 0x8001
    VMStackPop 0x8000
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

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 0
    TrainerCardGetBadgeCount 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C5
    ActorMsg 1024, 1, 7, 0, 0
    VMJump L_00D8

L_00C5:
    WordSetNumber 0, 0x8020, 1
    ActorMsg 1024, 2, 7, 0, 0

L_00D8:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 3, 8, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 0, 32784
    ListMenuAdd 11, 65535, 1
    ListMenuAdd 12, 65535, 2
    ListMenuAdd 13, 65535, 3
    ListMenuShow
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0138
    WorkSetConst 0x8008, 1
    VMJump L_0170

L_0138:
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0157
    WorkSetConst 0x8008, 2
    VMJump L_0170

L_0157:
    VMStackPush 0x8010
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0170
    WorkSetConst 0x8008, 3

L_0170:
    ActorMsg 1024, 4, 8, 2, 0
    ListMenu_AnchorTopRight 31, 1, 0, 0, 32784
    ListMenuAdd 14, 65535, 1
    ListMenuAdd 15, 65535, 2
    ListMenuAdd 13, 65535, 3
    ListMenuShow
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01BE
    WorkSetConst 0x8009, 1
    VMJump L_01F6

L_01BE:
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01DD
    WorkSetConst 0x8009, 2
    VMJump L_01F6

L_01DD:
    VMStackPush 0x8010
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_01F6
    WorkSetConst 0x8009, 3

L_01F6:
    ActorMsg 1024, 5, 8, 2, 0
    VMStackPush 0x8008
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8009
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_023B
    ActorMsg 1024, 6, 8, 2, 0
    Cmd_02DA 0
    VMJump L_0319

L_023B:
    VMStackPush 0x8008
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8009
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0274
    ActorMsg 1024, 7, 8, 2, 0
    Cmd_02DA 1
    VMJump L_0319

L_0274:
    VMStackPush 0x8008
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8009
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02AD
    ActorMsg 1024, 8, 8, 2, 0
    Cmd_02DA 2
    VMJump L_0319

L_02AD:
    VMStackPush 0x8008
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8009
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02E6
    ActorMsg 1024, 9, 8, 2, 0
    Cmd_02DA 4
    VMJump L_0319

L_02E6:
    VMStackPush 0x8008
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8009
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0319
    ActorMsg 1024, 10, 8, 2, 0
    Cmd_02DA 3

L_0319:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
