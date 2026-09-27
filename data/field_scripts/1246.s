#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0047
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0026:
    ActorMsgClose
    GameCommCheckDSiWiFi 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0045
    RTCallGlobal 2005
    VMReturn

L_0045:
    VMReturn

L_0047:
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    VMStackPushFlag 106
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0084
    ActorMsg 1024, 6, 0x8011, 4, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_0084:
    PokePartyGetCount 0x8022, 4
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_00AF
    ActorMsg 1024, 7, 0x8011, 4, 0
    LastKeyWait
    ActorMsgClose
    VMReturn

L_00AF:
    ActorMsg 1024, 0, 0x8011, 4, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 1

L_00C7:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_029B
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_00ED
    VMJump L_010B

L_00ED:
    ActorMsg 1024, 1, 0x8011, 4, 0
    VMCall L_02B5
    WorkGet 0x8023, 0x8020
    VMJump L_0295

L_010B:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_011E
    VMJump L_0163

L_011E:
    ItemCheckAmount 465, 1, 0x8025
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_014B
    ActorMsg 1024, 5, 0x8011, 4, 0
    VMJump L_0157

L_014B:
    ActorMsg 1024, 97, 0x8011, 4, 0

L_0157:
    WorkSetConst 0x8023, 0
    VMJump L_0295

L_0163:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_0176
    VMJump L_0188

L_0176:
    VMCall L_03A6
    WorkGet 0x8023, 0x8020
    VMJump L_0295

L_0188:
    WorkCmpConst 0x8023, 3
    VMJumpIf 1, L_019B
    VMJump L_01AD

L_019B:
    VMCall L_0A70
    WorkGet 0x8023, 0x8020
    VMJump L_0295

L_01AD:
    WorkCmpConst 0x8023, 4
    VMJumpIf 1, L_01C0
    VMJump L_01D2

L_01C0:
    VMCall L_13E4
    WorkGet 0x8023, 0x8020
    VMJump L_0295

L_01D2:
    WorkCmpConst 0x8023, 5
    VMJumpIf 1, L_01E5
    VMJump L_01F7

L_01E5:
    VMCall L_14A8
    WorkGet 0x8023, 0x8020
    VMJump L_0295

L_01F7:
    WorkCmpConst 0x8023, 10
    VMJumpIf 1, L_020A
    VMJump L_0222

L_020A:
    ActorMsg 1024, 2, 0x8011, 4, 0
    WorkSetConst 0x8023, 12
    VMJump L_0295

L_0222:
    WorkCmpConst 0x8023, 11
    VMJumpIf 1, L_0235
    VMJump L_024D

L_0235:
    ActorMsg 1024, 8, 0x8011, 4, 0
    WorkSetConst 0x8023, 12
    VMJump L_0295

L_024D:
    WorkCmpConst 0x8023, 12
    VMJumpIf 1, L_0260
    VMJump L_0270

L_0260:
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x8024, 0
    VMJump L_0295

L_0270:
    WorkCmpConst 0x8023, 13
    VMJumpIf 1, L_0283
    VMJump L_028F

L_0283:
    WorkSetConst 0x8024, 0
    VMJump L_0295

L_028F:
    WorkSetConst 0x8024, 0

L_0295:
    VMJump L_00C7

L_029B:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    VMReturn

L_02B5:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32806
    ItemCheckAmount 578, 1, 0x8027
    ItemCheckAmount 465, 1, 0x8028
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02FB
    ListMenuAdd 9, 65535, 2

L_02FB:
    ListMenuAdd 10, 65535, 3
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_032E
    ListMenuAdd 11, 65535, 4

L_032E:
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0349
    ListMenuAdd 12, 65535, 5

L_0349:
    ListMenuAdd 13, 65535, 1
    ListMenuAdd 14, 65535, 10
    ListMenuShow
    VMStackPush 0x8026
    VMStackPushConst 65534
    VMStackCmp 1
    VMJumpIf 255, L_037A
    WorkSetConst 0x8020, 10
    VMJump L_0380

L_037A:
    WorkGet 0x8020, 0x8026

L_0380:
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    VMReturn
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0

L_03A6:
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 1

L_03C4:
    VMStackPush 0x802e
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_055B
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_03EA
    VMJump L_0408

L_03EA:
    ActorMsg 1024, 53, 0x8011, 4, 0
    VMCall L_056F
    WorkGet 0x802d, 0x8020
    VMJump L_0555

L_0408:
    WorkCmpConst 0x802d, 4
    VMJumpIf 1, L_041B
    VMJump L_042D

L_041B:
    VMCall L_05C5
    WorkGet 0x802d, 0x8020
    VMJump L_0555

L_042D:
    WorkCmpConst 0x802d, 1
    VMJumpIf 1, L_0440
    VMJump L_0452

L_0440:
    VMCall L_06F5
    WorkGet 0x802d, 0x8020
    VMJump L_0555

L_0452:
    WorkCmpConst 0x802d, 2
    VMJumpIf 1, L_0465
    VMJump L_0477

L_0465:
    VMCall L_07FC
    WorkGet 0x802d, 0x8020
    VMJump L_0555

L_0477:
    WorkCmpConst 0x802d, 3
    VMJumpIf 1, L_048A
    VMJump L_049C

L_048A:
    VMCall L_08AD
    WorkGet 0x802d, 0x8020
    VMJump L_0555

L_049C:
    WorkCmpConst 0x802d, 252
    VMJumpIf 1, L_04AF
    VMJump L_04C1

L_04AF:
    WorkSetConst 0x8020, 11
    WorkSetConst 0x802e, 0
    VMJump L_0555

L_04C1:
    WorkCmpConst 0x802d, 254
    VMJumpIf 1, L_04D4
    VMJump L_04E6

L_04D4:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x802e, 0
    VMJump L_0555

L_04E6:
    WorkCmpConst 0x802d, 255
    VMJumpIf 1, L_04F9
    VMJump L_050B

L_04F9:
    WorkSetConst 0x8020, 10
    WorkSetConst 0x802e, 0
    VMJump L_0555

L_050B:
    WorkCmpConst 0x802d, 251
    VMJumpIf 1, L_051E
    VMJump L_0530

L_051E:
    WorkSetConst 0x8020, 12
    WorkSetConst 0x802e, 0
    VMJump L_0555

L_0530:
    WorkCmpConst 0x802d, 253
    VMJumpIf 1, L_0543
    VMJump L_0555

L_0543:
    WorkSetConst 0x8020, 13
    WorkSetConst 0x802e, 0
    VMJump L_0555

L_0555:
    VMJump L_03C4

L_055B:
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802c, 0
    VMReturn

L_056F:
    WorkSetConst 0x802f, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32815
    ListMenuAdd 54, 65535, 1
    ListMenuAdd 55, 65535, 4
    ListMenuAdd 56, 65535, 254
    ListMenuShow
    VMStackPush 0x802f
    VMStackPushConst 65534
    VMStackCmp 1
    VMJumpIf 255, L_05B7
    WorkSetConst 0x8020, 254
    VMJump L_05BD

L_05B7:
    WorkGet 0x8020, 0x802f

L_05BD:
    WorkSetConst 0x802f, 0
    VMReturn

L_05C5:
    WorkSetConst 0x8030, 0
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8032, 0
    ActorMsg 1024, 57, 0x8011, 4, 0
    WorkSetConst 0x8031, 1

L_05E9:
    VMStackPush 0x8031
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06DB
    ActorMsg 1024, 58, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32816
    ListMenuAdd 59, 65535, 0
    ListMenuAdd 60, 65535, 1
    ListMenuAdd 61, 65535, 2
    ListMenuAdd 99, 65535, 3
    ListMenuAdd 62, 65535, 4
    ListMenuShow
    WorkCmpConst 0x8030, 0
    VMJumpIf 1, L_064E
    VMJump L_0660

L_064E:
    ActorMsg 1024, 63, 0x8011, 4, 0
    VMJump L_06D5

L_0660:
    WorkCmpConst 0x8030, 1
    VMJumpIf 1, L_0673
    VMJump L_0685

L_0673:
    ActorMsg 1024, 64, 0x8011, 4, 0
    VMJump L_06D5

L_0685:
    WorkCmpConst 0x8030, 2
    VMJumpIf 1, L_0698
    VMJump L_06AA

L_0698:
    ActorMsg 1024, 65, 0x8011, 4, 0
    VMJump L_06D5

L_06AA:
    WorkCmpConst 0x8030, 3
    VMJumpIf 1, L_06BD
    VMJump L_06CF

L_06BD:
    ActorMsg 1024, 100, 0x8011, 4, 0
    VMJump L_06D5

L_06CF:
    WorkSetConst 0x8031, 0

L_06D5:
    VMJump L_05E9

L_06DB:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8032, 0
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8030, 0
    VMReturn

L_06F5:
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8034, 0
    .byte 0xed
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0x33
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x33
    .byte 0x80
    .byte 0x08
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x11
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x39
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xed
    .byte 0x03
    VMHalt
    .byte 0x33
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x33
    .byte 0x80
    .byte 0x08
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x11
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x1a
    .byte 0x00
    VMNop
    ActorMsg 1024, 98, 0x8011, 4, 0
    WorkSetConst 0x8020, 251
    VMReturn
    VMJump L_0753
    .byte 0xf0
    .byte 0x03
    VMReturn
    .byte 0x33
    .byte 0x80

L_0753:
    VMCall L_0026
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0774
    WorkSetConst 0x8020, 255
    VMReturn

L_0774:
    ActorMsg 1024, 66, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32819
    ListMenuAdd 67, 65535, 0
    ListMenuAdd 68, 65535, 1
    ListMenuAdd 69, 65535, 2
    ListMenuAdd 70, 65535, 3
    ListMenuAdd 71, 65535, 4
    ListMenuAdd 72, 65535, 5
    ListMenuShow
    VMStackPush 0x8033
    VMStackPushConst 4
    VMStackCmp 2
    VMJumpIf 255, L_07D6
    WorkSetConst 0x8020, 254
    VMReturn

L_07D6:
    WorkGet 0x8029, 0x8033
    WorkSetConst 0x802a, 15
    WorkAdd 0x802a, 0x8033
    WorkSetConst 0x8020, 2
    WorkSetConst 0x8034, 0
    WorkSetConst 0x8033, 0
    VMReturn

L_07FC:
    WorkSetConst 0x8035, 0
    WorkSetConst 0x8036, 0
    WorkSetConst 0x8036, 73
    WorkAdd 0x8036, 0x8029
    ActorMsg 1024, 0x8036, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32821
    ListMenuAdd 78, 65535, 0
    ListMenuAdd 79, 65535, 1
    ListMenuAdd 80, 65535, 2
    ListMenuShow
    VMStackPush 0x8035
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0862
    WorkSetConst 0x8020, 3
    VMJump L_089F

L_0862:
    VMStackPush 0x8035
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0899
    WorkSetConst 0x8036, 81
    WorkAdd 0x8036, 0x8029
    ActorMsg 1024, 0x8036, 0x8011, 4, 0
    WorkSetConst 0x8020, 2
    VMJump L_089F

L_0899:
    WorkSetConst 0x8020, 1

L_089F:
    WorkSetConst 0x8036, 0
    WorkSetConst 0x8035, 0
    VMReturn

L_08AD:
    WorkSetConst 0x8037, 0
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8039, 0
    ActorMsgClose
    Cmd_01B0 0x802a, 0x8037
    VMStackPush 0x8037
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_08E8
    WorkSetConst 0x8020, 254
    VMReturn
    VMJump L_0915

L_08E8:
    VMStackPush 0x8037
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0915
    VMStackPush 0x8000
    WorkSet 0x8000, 0x802a
    RTCallGlobal 10260
    VMStackPop 0x8000
    WorkSetConst 0x8020, 255
    VMReturn

L_0915:
    WorkGet 0x802b, 0x8037
    .byte 0xee
    .byte 0x03
    .byte 0xf0
    .byte 0x03
    .byte 0x04
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0xd3
    .byte 0x00
    .byte 0x39
    .byte 0x80
    .byte 0xdc
    .byte 0x00
    .byte 0x39
    .byte 0x80
    .byte 0x01
    .byte 0x00
    .byte 0x0a
    .byte 0x00
    .byte 0xff
    .byte 0xff
    .byte 0x01
    .byte 0x00
    .byte 0x23
    .byte 0x00
    .byte 0x65
    .byte 0x09
    .byte 0x28
    .byte 0x00
    .byte 0x41
    .byte 0x40
    .byte 0x01
    .byte 0x00
    .byte 0xed
    VMHalt
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x09
    .byte 0x00
    .byte 0x00
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x01
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x02
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x03
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x04
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x05
    .byte 0x80
    .byte 0x1c
    .byte 0x00
    .byte 0xd3
    .byte 0x07
    .byte 0x2a
    .byte 0x00
    .byte 0x37
    .byte 0x80
    .byte 0x00
    .byte 0x80
    .byte 0x0a
    .byte 0x00
    .byte 0x05
    .byte 0x80
    .byte 0x0a
    .byte 0x00
    .byte 0x04
    .byte 0x80
    .byte 0x0a
    .byte 0x00
    .byte 0x03
    .byte 0x80
    .byte 0x0a
    .byte 0x00
    .byte 0x02
    .byte 0x80
    .byte 0x0a
    .byte 0x00
    .byte 0x01
    .byte 0x80
    .byte 0x0a
    .byte 0x00
    .byte 0x00
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x37
    .byte 0x80
    .byte 0x08
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x11
    .byte 0x00
    VMReturn
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x20
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x20
    .byte 0x80
    .byte 0xff
    .byte 0x00
    .byte 0xef
    .byte 0x03
    .byte 0x24
    .byte 0x00
    .byte 0x65
    .byte 0x09
    .byte 0x28
    .byte 0x00
    .byte 0x41
    .byte 0x40
    .byte 0x00
    .byte 0x00
    .byte 0xf0
    .byte 0x03
    .byte 0x04
    .byte 0x00
    VMNop
    Cmd_02ED 1, 0
    VMReturn
    .byte 0x09
    .byte 0x00
    .byte 0x00
    .byte 0x80
    .byte 0x1c
    .byte 0x00
    .byte 0xd4
    .byte 0x07
    .byte 0x2a
    .byte 0x00
    .byte 0x37
    .byte 0x80
    .byte 0x00
    .byte 0x80
    .byte 0x0a
    .byte 0x00
    .byte 0x00
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x37
    .byte 0x80
    .byte 0x08
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x11
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x26
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x20
    .byte 0x80
    .byte 0xff
    .byte 0x00
    .byte 0xef
    .byte 0x03
    .byte 0x24
    .byte 0x00
    .byte 0x65
    .byte 0x09
    .byte 0x28
    .byte 0x00
    .byte 0x41
    .byte 0x40
    .byte 0x00
    .byte 0x00
    .byte 0xf0
    .byte 0x03
    .byte 0x04
    .byte 0x00
    VMNop
    Cmd_02ED 1, 0
    VMReturn
    VMJump L_0A2E
    .byte 0x09
    .byte 0x00
    .byte 0x37
    .byte 0x80
    .byte 0x08
    .byte 0x00
    VMHalt
    .byte 0x11
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x20
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x20
    .byte 0x80
    .byte 0xfc
    .byte 0x00
    .byte 0xef
    .byte 0x03
    .byte 0x24
    .byte 0x00
    .byte 0x65
    .byte 0x09
    .byte 0x28
    .byte 0x00
    .byte 0x41
    .byte 0x40
    .byte 0x00
    .byte 0x00
    .byte 0xf0
    .byte 0x03
    .byte 0x04
    .byte 0x00
    VMNop
    Cmd_02ED 1, 0
    VMReturn

L_0A2E:
    FunfestBGMReturn
    PokePartyRecoverAll
    VMCall L_1656
    NetConnectWiFiBattle 0x802a, 0x802b
    VMCall L_1670
    WorkSetConst 0x8020, 253
    WorkSetConst 0x8039, 0
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8037, 0
    VMReturn
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x8029, 0

L_0A70:
    WorkSetConst 0x803a, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803c, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803c, 1

L_0A8E:
    VMStackPush 0x803c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0BD5
    WorkCmpConst 0x803b, 0
    VMJumpIf 1, L_0AB4
    VMJump L_0AC6

L_0AB4:
    VMCall L_0BE9
    WorkGet 0x803b, 0x8020
    VMJump L_0BCF

L_0AC6:
    WorkCmpConst 0x803b, 3
    VMJumpIf 1, L_0AD9
    VMJump L_0AF1

L_0AD9:
    ActorMsg 1024, 16, 0x8011, 4, 0
    WorkSetConst 0x803b, 0
    VMJump L_0BCF

L_0AF1:
    WorkCmpConst 0x803b, 1
    VMJumpIf 1, L_0B04
    VMJump L_0B16

L_0B04:
    VMCall L_0C53
    WorkGet 0x803b, 0x8020
    VMJump L_0BCF

L_0B16:
    WorkCmpConst 0x803b, 2
    VMJumpIf 1, L_0B29
    VMJump L_0B3B

L_0B29:
    VMCall L_1043
    WorkGet 0x803b, 0x8020
    VMJump L_0BCF

L_0B3B:
    WorkCmpConst 0x803b, 254
    VMJumpIf 1, L_0B4E
    VMJump L_0B60

L_0B4E:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x803c, 0
    VMJump L_0BCF

L_0B60:
    WorkCmpConst 0x803b, 255
    VMJumpIf 1, L_0B73
    VMJump L_0B85

L_0B73:
    WorkSetConst 0x8020, 10
    WorkSetConst 0x803c, 0
    VMJump L_0BCF

L_0B85:
    WorkCmpConst 0x803b, 252
    VMJumpIf 1, L_0B98
    VMJump L_0BAA

L_0B98:
    WorkSetConst 0x8020, 11
    WorkSetConst 0x803c, 0
    VMJump L_0BCF

L_0BAA:
    WorkCmpConst 0x803b, 253
    VMJumpIf 1, L_0BBD
    VMJump L_0BCF

L_0BBD:
    WorkSetConst 0x8020, 13
    WorkSetConst 0x803c, 0
    VMJump L_0BCF

L_0BCF:
    VMJump L_0A8E

L_0BD5:
    WorkSetConst 0x803c, 0
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803a, 0
    VMReturn

L_0BE9:
    WorkSetConst 0x803d, 0
    ActorMsg 1024, 15, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32829
    ListMenuAdd 17, 65535, 1
    ListMenuAdd 18, 65535, 2
    ListMenuAdd 19, 65535, 3
    ListMenuAdd 20, 65535, 254
    ListMenuShow
    VMStackPush 0x803d
    VMStackPushConst 65534
    VMStackCmp 1
    VMJumpIf 255, L_0C45
    WorkSetConst 0x8020, 254
    VMJump L_0C4B

L_0C45:
    WorkGet 0x8020, 0x803d

L_0C4B:
    WorkSetConst 0x803d, 0
    VMReturn

L_0C53:
    WorkSetConst 0x803e, 0
    WorkSetConst 0x803f, 0
    WorkSetConst 0x8040, 0
    WorkSetConst 0x803f, 0
    WorkSetConst 0x8040, 1

L_0C71:
    VMStackPush 0x8040
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D8D
    WorkCmpConst 0x803f, 0
    VMJumpIf 1, L_0C97
    VMJump L_0CA9

L_0C97:
    VMCall L_0DA1
    WorkGet 0x803f, 0x8020
    VMJump L_0D87

L_0CA9:
    WorkCmpConst 0x803f, 1
    VMJumpIf 1, L_0CBC
    VMJump L_0CCE

L_0CBC:
    VMCall L_0E03
    WorkGet 0x803f, 0x8020
    VMJump L_0D87

L_0CCE:
    WorkCmpConst 0x803f, 2
    VMJumpIf 1, L_0CE1
    VMJump L_0CF3

L_0CE1:
    VMCall L_0ECD
    WorkGet 0x803f, 0x8020
    VMJump L_0D87

L_0CF3:
    WorkCmpConst 0x803f, 252
    VMJumpIf 1, L_0D06
    VMJump L_0D18

L_0D06:
    WorkSetConst 0x8020, 252
    WorkSetConst 0x8040, 0
    VMJump L_0D87

L_0D18:
    WorkCmpConst 0x803f, 254
    VMJumpIf 1, L_0D2B
    VMJump L_0D3D

L_0D2B:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8040, 0
    VMJump L_0D87

L_0D3D:
    WorkCmpConst 0x803f, 255
    VMJumpIf 1, L_0D50
    VMJump L_0D62

L_0D50:
    WorkSetConst 0x8020, 255
    WorkSetConst 0x8040, 0
    VMJump L_0D87

L_0D62:
    WorkCmpConst 0x803f, 253
    VMJumpIf 1, L_0D75
    VMJump L_0D87

L_0D75:
    WorkSetConst 0x8020, 253
    WorkSetConst 0x8040, 0
    VMJump L_0D87

L_0D87:
    VMJump L_0C71

L_0D8D:
    WorkSetConst 0x8040, 0
    WorkSetConst 0x803f, 0
    WorkSetConst 0x803e, 0
    VMReturn

L_0DA1:
    WorkSetConst 0x8041, 0
    ActorMsg 1024, 21, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32833
    ListMenuAdd 22, 65535, 2
    ListMenuAdd 23, 65535, 1
    ListMenuAdd 24, 65535, 254
    ListMenuShow
    VMStackPush 0x8041
    VMStackPushConst 65534
    VMStackCmp 1
    VMJumpIf 255, L_0DF5
    WorkSetConst 0x8020, 254
    VMJump L_0DFB

L_0DF5:
    WorkGet 0x8020, 0x8041

L_0DFB:
    WorkSetConst 0x8041, 0
    VMReturn

L_0E03:
    WorkSetConst 0x8042, 0
    WorkSetConst 0x8043, 0
    ActorMsg 1024, 25, 0x8011, 4, 0
    WorkSetConst 0x8043, 1

L_0E21:
    VMStackPush 0x8043
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0EB9
    ActorMsg 1024, 26, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32834
    ListMenuAdd 29, 65535, 0
    ListMenuAdd 30, 65535, 1
    ListMenuAdd 31, 65535, 2
    ListMenuShow
    VMStackPush 0x8042
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0E88
    ActorMsg 1024, 27, 0x8011, 4, 0
    VMJump L_0EB3

L_0E88:
    VMStackPush 0x8042
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0EAD
    ActorMsg 1024, 28, 0x8011, 4, 0
    VMJump L_0EB3

L_0EAD:
    WorkSetConst 0x8043, 0

L_0EB3:
    VMJump L_0E21

L_0EB9:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8043, 0
    WorkSetConst 0x8042, 0
    VMReturn

L_0ECD:
    WorkSetConst 0x8044, 0
    WorkSetConst 0x8045, 0
    WorkSetConst 0x8046, 0
    BoxGetCount 0x8045, 5
    PokePartyGetCount 0x8046, 5
    VMStackPush 0x8045
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8046
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0F22
    ActorMsg 1024, 94, 0x8011, 4, 0
    WorkSetConst 0x8020, 255
    VMReturn

L_0F22:
    PokePartyGetCount 0x8046, 1
    VMStackPush 0x8046
    VMStackPushConst 2
    VMStackCmp 0
    VMJumpIf 255, L_0F4F
    ActorMsg 1024, 95, 0x8011, 4, 0
    WorkSetConst 0x8020, 255
    VMReturn

L_0F4F:
    VMCall L_0026
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0F70
    WorkSetConst 0x8020, 255
    VMReturn

L_0F70:
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    RTCallGlobal 2003
    WorkSet 0x8044, 0x8000
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMStackPush 0x8044
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0FC5
    WorkSetConst 0x8020, 255
    VMReturn

L_0FC5:
    VMStackPush 0x8000
    RTCallGlobal 2004
    WorkSet 0x8044, 0x8000
    VMStackPop 0x8000
    VMStackPush 0x8044
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0FF8
    WorkSetConst 0x8020, 255
    VMReturn
    VMJump L_1013

L_0FF8:
    VMStackPush 0x8044
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_1013
    WorkSetConst 0x8020, 252
    VMReturn

L_1013:
    Cmd_02C5 17
    FunfestBGMReturn
    PokePartyRecoverAll
    VMCall L_1656
    NetConnectGTS
    VMCall L_1670
    WorkSetConst 0x8020, 253
    WorkSetConst 0x8046, 0
    WorkSetConst 0x8045, 0
    WorkSetConst 0x8044, 0
    VMReturn

L_1043:
    WorkSetConst 0x8047, 0
    WorkSetConst 0x8048, 0
    WorkSetConst 0x8049, 0
    WorkSetConst 0x8048, 0
    WorkSetConst 0x8049, 1

L_1061:
    VMStackPush 0x8049
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1189
    WorkCmpConst 0x8048, 0
    VMJumpIf 1, L_1087
    VMJump L_10A5

L_1087:
    ActorMsg 1024, 32, 0x8011, 4, 0
    VMCall L_119D
    WorkGet 0x8048, 0x8020
    VMJump L_1183

L_10A5:
    WorkCmpConst 0x8048, 1
    VMJumpIf 1, L_10B8
    VMJump L_10CA

L_10B8:
    VMCall L_11F3
    WorkGet 0x8048, 0x8020
    VMJump L_1183

L_10CA:
    WorkCmpConst 0x8048, 2
    VMJumpIf 1, L_10DD
    VMJump L_10EF

L_10DD:
    VMCall L_12BD
    WorkGet 0x8048, 0x8020
    VMJump L_1183

L_10EF:
    WorkCmpConst 0x8048, 252
    VMJumpIf 1, L_1102
    VMJump L_1114

L_1102:
    WorkSetConst 0x8020, 252
    WorkSetConst 0x8049, 0
    VMJump L_1183

L_1114:
    WorkCmpConst 0x8048, 254
    VMJumpIf 1, L_1127
    VMJump L_1139

L_1127:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8049, 0
    VMJump L_1183

L_1139:
    WorkCmpConst 0x8048, 255
    VMJumpIf 1, L_114C
    VMJump L_115E

L_114C:
    WorkSetConst 0x8020, 255
    WorkSetConst 0x8049, 0
    VMJump L_1183

L_115E:
    WorkCmpConst 0x8048, 253
    VMJumpIf 1, L_1171
    VMJump L_1183

L_1171:
    WorkSetConst 0x8020, 253
    WorkSetConst 0x8049, 0
    VMJump L_1183

L_1183:
    VMJump L_1061

L_1189:
    WorkSetConst 0x8049, 0
    WorkSetConst 0x8048, 0
    WorkSetConst 0x8047, 0
    VMReturn

L_119D:
    WorkSetConst 0x804a, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32842
    ListMenuAdd 33, 65535, 2
    ListMenuAdd 34, 65535, 1
    ListMenuAdd 35, 65535, 254
    ListMenuShow
    VMStackPush 0x804a
    VMStackPushConst 65534
    VMStackCmp 1
    VMJumpIf 255, L_11E5
    WorkSetConst 0x8020, 254
    VMJump L_11EB

L_11E5:
    WorkGet 0x8020, 0x804a

L_11EB:
    WorkSetConst 0x804a, 0
    VMReturn

L_11F3:
    WorkSetConst 0x804b, 0
    WorkSetConst 0x804c, 0
    ActorMsg 1024, 36, 0x8011, 4, 0
    WorkSetConst 0x804c, 1

L_1211:
    VMStackPush 0x804c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_12A9
    ActorMsg 1024, 37, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32843
    ListMenuAdd 40, 65535, 0
    ListMenuAdd 41, 65535, 1
    ListMenuAdd 42, 65535, 2
    ListMenuShow
    VMStackPush 0x804b
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1278
    ActorMsg 1024, 38, 0x8011, 4, 0
    VMJump L_12A3

L_1278:
    VMStackPush 0x804b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_129D
    ActorMsg 1024, 39, 0x8011, 4, 0
    VMJump L_12A3

L_129D:
    WorkSetConst 0x804c, 0

L_12A3:
    VMJump L_1211

L_12A9:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x804c, 0
    WorkSetConst 0x804b, 0
    VMReturn

L_12BD:
    WorkSetConst 0x804d, 0
    WorkSetConst 0x804e, 0
    PokePartyGetCount 0x804e, 1
    VMStackPush 0x804e
    VMStackPushConst 2
    VMStackCmp 0
    VMJumpIf 255, L_12F6
    ActorMsg 1024, 96, 0x8011, 4, 0
    WorkSetConst 0x8020, 255
    VMReturn

L_12F6:
    VMCall L_0026
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1317
    WorkSetConst 0x8020, 255
    VMReturn

L_1317:
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    RTCallGlobal 2003
    WorkSet 0x804d, 0x8000
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMStackPush 0x804d
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_136C
    WorkSetConst 0x8020, 255
    VMReturn

L_136C:
    VMStackPush 0x8000
    RTCallGlobal 2004
    WorkSet 0x804d, 0x8000
    VMStackPop 0x8000
    VMStackPush 0x804d
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_139F
    WorkSetConst 0x8020, 255
    VMReturn
    VMJump L_13BA

L_139F:
    VMStackPush 0x804d
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_13BA
    WorkSetConst 0x8020, 252
    VMReturn

L_13BA:
    Cmd_02C5 18
    FunfestBGMReturn
    PokePartyRecoverAll
    VMCall L_1656
    NetConnectGTSNegotiation
    VMCall L_1670
    WorkSetConst 0x8020, 253
    WorkSetConst 0x804e, 0
    WorkSetConst 0x804d, 0
    VMReturn

L_13E4:
    WorkSetConst 0x804f, 0
    WorkSetConst 0x8050, 0
    WorkSetConst 0x8050, 1

L_13F6:
    VMStackPush 0x8050
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_149A
    ActorMsg 1024, 48, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32847
    ListMenuAdd 50, 65535, 0
    ListMenuAdd 51, 65535, 1
    ListMenuAdd 52, 65535, 2
    ListMenuShow
    VMStackPush 0x804f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1463
    WorkSetConst 0x8021, 1
    VMCall L_156C
    WorkSetConst 0x8050, 0
    VMJump L_1494

L_1463:
    VMStackPush 0x804f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1488
    ActorMsg 1024, 49, 0x8011, 4, 0
    VMJump L_1494

L_1488:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8050, 0

L_1494:
    VMJump L_13F6

L_149A:
    WorkSetConst 0x8050, 0
    WorkSetConst 0x804f, 0
    VMReturn

L_14A8:
    WorkSetConst 0x8051, 0
    WorkSetConst 0x8052, 0
    WorkSetConst 0x8052, 1

L_14BA:
    VMStackPush 0x8052
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_155E
    ActorMsg 1024, 43, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32849
    ListMenuAdd 45, 65535, 0
    ListMenuAdd 46, 65535, 1
    ListMenuAdd 47, 65535, 2
    ListMenuShow
    VMStackPush 0x8051
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1527
    WorkSetConst 0x8021, 0
    VMCall L_156C
    WorkSetConst 0x8052, 0
    VMJump L_1558

L_1527:
    VMStackPush 0x8051
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_154C
    ActorMsg 1024, 44, 0x8011, 4, 0
    VMJump L_1558

L_154C:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8052, 0

L_1558:
    VMJump L_14BA

L_155E:
    WorkSetConst 0x8052, 0
    WorkSetConst 0x8051, 0
    VMReturn

L_156C:
    WorkSetConst 0x8053, 0
    VMCall L_0026
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1593
    WorkSetConst 0x8020, 10
    VMReturn

L_1593:
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    RTCallGlobal 2003
    WorkSet 0x8053, 0x8000
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMStackPush 0x8053
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_15E8
    WorkSetConst 0x8020, 10
    VMReturn

L_15E8:
    VMStackPush 0x8000
    RTCallGlobal 2004
    WorkSet 0x8053, 0x8000
    VMStackPop 0x8000
    VMStackPush 0x8053
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_161B
    WorkSetConst 0x8020, 10
    VMReturn
    VMJump L_1636

L_161B:
    VMStackPush 0x8053
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_1636
    WorkSetConst 0x8020, 11
    VMReturn

L_1636:
    FunfestBGMReturn
    VMCall L_1656
    NetConnectBattleVideo 0x8021
    VMCall L_1670
    WorkSetConst 0x8020, 13
    WorkSetConst 0x8053, 0
    VMReturn

L_1656:
    ActorMsg 1024, 4, 0x8011, 4, 0
    ActorMsgClose
    RTCallGlobal 2105
    FieldSetNextZoneHere
    FlagSet 2405
    VMReturn

L_1670:
    RTCallGlobal 2106
    VMReturn
    .balign 4, 0
