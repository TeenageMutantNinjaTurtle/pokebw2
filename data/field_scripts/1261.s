#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

Script_1:
    Cmd_01DC 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_002D
    FlagReset 654
    VMJump L_0031

L_002D:
    FlagSet 654

L_0031:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_004D
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    WorkSetConst 0x8020, 0

L_004D:
    Cmd_01DC 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_007C
    DebugPrint 0x8010
    ActorMsg 1024, 1, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_007C:
    WordSetPlayerName 0
    ActorMsg 1024, 0, 0x8011, 2, 0
    ActorMsgClose
    Cmd_01DC 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C2
    MEPlay 1302
    SystemMsg 3, 0
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    Cmd_01DC 2, 0x8010
    Cmd_01DC 3, 0x8010

L_00C2:
    Cmd_01DC 4, 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 2
    VMJumpIf 255, L_0112
    WorkSetConst 0x8010, 0

L_00E1:
    VMStackPush 0x8010
    VMStackPush 0x8020
    VMStackCmp 0
    VMJumpIf 255, L_0112
    Cmd_01DC 5, 0x8010
    ActorMsg 1024, 4, 0x8011, 2, 0
    WorkAdd 0x8010, 1
    VMJump L_00E1

L_0112:
    ActorMsg 1024, 2, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
