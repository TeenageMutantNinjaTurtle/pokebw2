#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Cmd_01F6 0, 0, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0045
    ActorMsg 1024, 0, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_00E8

L_0045:
    Cmd_01F7 0, 0, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0078
    ActorMsg 1024, 1, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_00E8

L_0078:
    VMStackPush 0x408a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B1
    ActorMsg 1024, 8, 0x8011, 2, 0
    YesNoWin 0x8010
    ActorMsg 1024, 9, 0x8011, 2, 0
    RTCallGlobal 10446
    VMJump L_00E8

L_00B1:
    Cmd_01F7 1, 0, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00E4
    ActorMsg 1024, 2, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_00E8

L_00E4:
    RTCallGlobal 10446

L_00E8:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    WorkSetConst 0x8020, 0
    Cmd_01F7 2, 0, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_012D
    ActorMsg 1024, 3, 0x8011, 2, 0
    Cmd_01F7 3, 0, 0, 0
    VMJump L_0164

L_012D:
    VMStackPush 0x408a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0158
    ActorMsg 1024, 4, 0x8011, 2, 0
    WorkSetConst 0x408a, 1
    VMJump L_0164

L_0158:
    ActorMsg 1024, 5, 0x8011, 2, 0

L_0164:
    Cmd_01F8 0, 0
    Cmd_01F8 1, 1
    Cmd_01F8 2, 2
    Cmd_01F8 3, 3
    Cmd_01F8 4, 4
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32800
    ListMenuAdd 10, 65535, 0
    ListMenuAdd 11, 65535, 1
    ListMenuAdd 12, 65535, 2
    ListMenuAdd 13, 65535, 3
    ListMenuAdd 14, 65535, 4
    ListMenuAdd 15, 65535, 5
    ListMenuShow
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8020
    VMStackPushConst 65534
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_01F6
    ActorMsg 1024, 6, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0210

L_01F6:
    Cmd_01F7 4, 0x8020, 0, 0
    ActorMsg 1024, 7, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose

L_0210:
    RTEndGlobal
    VMHalt
