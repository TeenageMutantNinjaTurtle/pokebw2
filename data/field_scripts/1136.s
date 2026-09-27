#include "asm/field_script.inc"

// Script plugin 10, from the zones that use this file

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8021, 0

L_003C:
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_01C7
    ActorMsg 1024, 16, 3, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32800
    ListMenuAdd 23, 65535, 0
    ListMenuAdd 24, 65535, 1
    ListMenuAdd 29, 65535, 2
    ListMenuAdd 25, 65535, 3
    ListMenuAdd 26, 65535, 4
    ListMenuAdd 27, 65535, 5
    ListMenuAdd 28, 65535, 6
    ListMenuShow
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_00B1
    VMJump L_00C3

L_00B1:
    ActorMsg 1024, 17, 3, 4, 0
    VMJump L_01C1

L_00C3:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_00D6
    VMJump L_00E8

L_00D6:
    ActorMsg 1024, 18, 3, 4, 0
    VMJump L_01C1

L_00E8:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_00FB
    VMJump L_010D

L_00FB:
    ActorMsg 1024, 30, 3, 4, 0
    VMJump L_01C1

L_010D:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_0120
    VMJump L_0132

L_0120:
    ActorMsg 1024, 19, 3, 4, 0
    VMJump L_01C1

L_0132:
    WorkCmpConst 0x8020, 4
    VMJumpIf 1, L_0145
    VMJump L_0157

L_0145:
    ActorMsg 1024, 20, 3, 4, 0
    VMJump L_01C1

L_0157:
    WorkCmpConst 0x8020, 5
    VMJumpIf 1, L_016A
    VMJump L_017C

L_016A:
    ActorMsg 1024, 21, 3, 4, 0
    VMJump L_01C1

L_017C:
    WorkCmpConst 0x8020, 6
    VMJumpIf 1, L_018F
    VMJump L_01AB

L_018F:
    ActorMsg 1024, 22, 3, 4, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8021, 1
    VMJump L_01C1

L_01AB:
    ActorMsg 1024, 22, 3, 4, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8021, 1

L_01C1:
    VMJump L_003C

L_01C7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    WordSetPlayerName 0
    VMStackPushFlag 458
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01FF
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0213

L_01FF:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_0213:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    Cmd_02CB 0x400f
    WordSetPlayerName 0
    VMStackPush 0x400f
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_024F
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0263

L_024F:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0263:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorMsg 1024, 4, 5, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 5, 6, 4, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 618, 0
    ParentActorMsg 1024, 6, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    WordSetPlayerName 0
    Cmd_02CB 0x400f
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8022, 7
    WorkAdd 0x8022, 0x400f
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8022, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x8022, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    WordSetPlayerName 0
    Cmd_02CB 0x400f
    WorkSetConst 0x8023, 0
    WorkCmpConst 0x400f, 0
    VMJumpIf 1, L_0314
    VMJump L_0320

L_0314:
    WorkSetConst 0x8023, 12
    VMJump L_0378

L_0320:
    WorkCmpConst 0x400f, 1
    VMJumpIf 1, L_034D
    WorkCmpConst 0x400f, 2
    VMJumpIf 1, L_034D
    WorkCmpConst 0x400f, 3
    VMJumpIf 1, L_034D
    VMJump L_0359

L_034D:
    WorkSetConst 0x8023, 13
    VMJump L_0378

L_0359:
    WorkCmpConst 0x400f, 4
    VMJumpIf 1, L_036C
    VMJump L_0378

L_036C:
    WorkSetConst 0x8023, 14
    VMJump L_0378

L_0378:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0x8023, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x8023, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
