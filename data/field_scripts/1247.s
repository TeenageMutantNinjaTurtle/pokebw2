#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    WorkGet 0x8021, 0x8000
    WorkGet 0x8022, 0x8001
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0043
    ActorMsg 1024, 4, 0x8011, 2, 0

L_0043:
    WorkCmpConst 0x8021, 246
    VMJumpIf 1, L_007D
    WorkCmpConst 0x8021, 245
    VMJumpIf 1, L_007D
    WorkCmpConst 0x8021, 244
    VMJumpIf 1, L_007D
    WorkCmpConst 0x8021, 243
    VMJumpIf 1, L_007D
    VMJump L_0089

L_007D:
    VMCall L_0261
    VMJump L_00BB

L_0089:
    WorkCmpConst 0x8021, 254
    VMJumpIf 1, L_00A9
    WorkCmpConst 0x8021, 253
    VMJumpIf 1, L_00A9
    VMJump L_00B5

L_00A9:
    VMCall L_0202
    VMJump L_00BB

L_00B5:
    VMCall L_00BD

L_00BB:
    RTEndGlobal

L_00BD:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    VMStackPush 0x8022
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00F4
    ActorMsg 1024, 1, 0x8011, 2, 0
    VMJump L_0100

L_00F4:
    ActorMsg 1024, 0, 0x8011, 2, 0

L_0100:
    WorkSetConst 0x8024, 1
    WorkSetConst 0x8025, 1

L_010C:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01DE
    WorkCmpConst 0x8024, 0
    VMJumpIf 1, L_0132
    VMJump L_014A

L_0132:
    ActorMsg 1024, 2, 0x8011, 2, 0
    WorkSetConst 0x8024, 1
    VMJump L_01D8

L_014A:
    WorkCmpConst 0x8024, 1
    VMJumpIf 1, L_015D
    VMJump L_016F

L_015D:
    VMCall L_0275
    WorkGet 0x8024, 0x8020
    VMJump L_01D8

L_016F:
    WorkCmpConst 0x8024, 2
    VMJumpIf 1, L_0182
    VMJump L_0194

L_0182:
    VMCall L_02CB
    WorkGet 0x8024, 0x8020
    VMJump L_01D8

L_0194:
    WorkCmpConst 0x8024, 3
    VMJumpIf 1, L_01A7
    VMJump L_01B9

L_01A7:
    VMCall L_030C
    WorkGet 0x8024, 0x8020
    VMJump L_01D8

L_01B9:
    WorkCmpConst 0x8024, 255
    VMJumpIf 1, L_01CC
    VMJump L_01D8

L_01CC:
    WorkSetConst 0x8025, 0
    VMJump L_01D8

L_01D8:
    VMJump L_010C

L_01DE:
    ActorMsg 1024, 3, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    VMReturn

L_0202:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    ActorMsg 1024, 8, 0x8011, 2, 0
    YesNoWin 0x8026
    VMStackPush 0x8026
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_023D
    VMCall L_02CB

L_023D:
    ActorMsg 1024, 9, 0x8011, 2, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    VMReturn

L_0261:
    WorkSetConst 0x8029, 0
    VMCall L_02CB
    WorkSetConst 0x8029, 0
    VMReturn

L_0275:
    WorkSetConst 0x802a, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32810
    ListMenuAdd 5, 65535, 2
    ListMenuAdd 6, 65535, 3
    ListMenuAdd 7, 65535, 255
    ListMenuShow
    VMStackPush 0x802a
    VMStackPushConst 65534
    VMStackCmp 1
    VMJumpIf 255, L_02BD
    WorkSetConst 0x8020, 255
    VMJump L_02C3

L_02BD:
    WorkGet 0x8020, 0x802a

L_02C3:
    WorkSetConst 0x802a, 0
    VMReturn

L_02CB:
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802b, 1
    ActorMsgClose
    CallFriendlyShopBuy 0x8021, 0x802b
    VMStackPush 0x802b
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02FE
    WorkSetConst 0x8020, 255
    VMJump L_0304

L_02FE:
    WorkSetConst 0x8020, 0

L_0304:
    WorkSetConst 0x802b, 0
    VMReturn

L_030C:
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    FadeOutBlackQ
    FadeWait
    ActorMsgClose
    FieldClose
    CallBag 0, 0x802c, 0x802d
    FieldOpen
    FadeInBlackQ
    FadeWait
    VMStackPush 0x802c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_034D
    WorkSetConst 0x8020, 255
    VMJump L_0353

L_034D:
    WorkSetConst 0x8020, 0

L_0353:
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802c, 0
    VMReturn
    .byte 0x28
    .byte 0x00
    .byte 0x22
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x21
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .balign 4, 0
