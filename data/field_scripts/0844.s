#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

Script_1:
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 102
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0030
    InfoMsg 0, 2
    FlagSet 102

L_0030:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

L_003C:
    VMStackPush 0x8020
    VMStackPushConst 255
    VMStackCmp 5
    VMJumpIf 255, L_0136
    InfoMsg 2, 2
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32801
    ListMenuAdd 41, 65535, 4
    ListMenuAdd 36, 65535, 0
    ListMenuAdd 37, 65535, 1
    ListMenuAdd 39, 65535, 2
    ListMenuAdd 40, 65535, 3
    ListMenuAdd 42, 65535, 255
    ListMenuShow
    WorkCmpConst 0x8021, 0
    VMJumpIf 1, L_00A2
    VMJump L_00B2

L_00A2:
    InfoMsg 3, 2
    InfoMsg 4, 2
    VMJump L_0130

L_00B2:
    WorkCmpConst 0x8021, 1
    VMJumpIf 1, L_00C5
    VMJump L_00D0

L_00C5:
    InfoMsg 5, 2
    VMJump L_0130

L_00D0:
    WorkCmpConst 0x8021, 2
    VMJumpIf 1, L_00E3
    VMJump L_00EE

L_00E3:
    InfoMsg 8, 2
    VMJump L_0130

L_00EE:
    WorkCmpConst 0x8021, 3
    VMJumpIf 1, L_0101
    VMJump L_010C

L_0101:
    InfoMsg 7, 2
    VMJump L_0130

L_010C:
    WorkCmpConst 0x8021, 4
    VMJumpIf 1, L_011F
    VMJump L_012A

L_011F:
    InfoMsg 9, 2
    VMJump L_0130

L_012A:
    WorkSetConst 0x8020, 255

L_0130:
    VMJump L_003C

L_0136:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
