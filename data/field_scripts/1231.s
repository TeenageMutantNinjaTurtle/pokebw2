#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntry Script_9
    ScriptEntry Script_10
    ScriptEntry Script_11
    ScriptEntriesEnd

Script_3:
    Cmd_02B2 0, 0x400f
    DebugPrint 80
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x404c
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0063
    DebugPrint 99
    FlagReset 989

L_0063:
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_007E
    DebugPrint 40
    FlagSet 989

L_007E:
    WorkSetConst 0x400f, 0
    VMHalt

Script_4:
    VMHalt

Script_5:
    Cmd_02B2 0, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0310
    DebugPrint 30
    RTGetZoneID 0x400c
    VMStackPushFlag 989
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0300
    WorkCmpConst 0x400c, 8
    VMJumpIf 1, L_00CF
    VMJump L_00D9

L_00CF:
    ActorDelete 11
    VMJump L_0300

L_00D9:
    WorkCmpConst 0x400c, 20
    VMJumpIf 1, L_00EC
    VMJump L_00F6

L_00EC:
    ActorDelete 11
    VMJump L_0300

L_00F6:
    WorkCmpConst 0x400c, 41
    VMJumpIf 1, L_0109
    VMJump L_0113

L_0109:
    ActorDelete 12
    VMJump L_0300

L_0113:
    WorkCmpConst 0x400c, 65
    VMJumpIf 1, L_0126
    VMJump L_0130

L_0126:
    ActorDelete 11
    VMJump L_0300

L_0130:
    WorkCmpConst 0x400c, 99
    VMJumpIf 1, L_0143
    VMJump L_014D

L_0143:
    ActorDelete 10
    VMJump L_0300

L_014D:
    WorkCmpConst 0x400c, 109
    VMJumpIf 1, L_0160
    VMJump L_016A

L_0160:
    ActorDelete 11
    VMJump L_0300

L_016A:
    WorkCmpConst 0x400c, 115
    VMJumpIf 1, L_017D
    VMJump L_0187

L_017D:
    ActorDelete 11
    VMJump L_0300

L_0187:
    WorkCmpConst 0x400c, 122
    VMJumpIf 1, L_019A
    VMJump L_01A4

L_019A:
    ActorDelete 12
    VMJump L_0300

L_01A4:
    WorkCmpConst 0x400c, 146
    VMJumpIf 1, L_01B7
    VMJump L_01C1

L_01B7:
    ActorDelete 6
    VMJump L_0300

L_01C1:
    WorkCmpConst 0x400c, 1
    VMJumpIf 1, L_01D4
    VMJump L_01DE

L_01D4:
    ActorDelete 9
    VMJump L_0300

L_01DE:
    WorkCmpConst 0x400c, 425
    VMJumpIf 1, L_01F1
    VMJump L_01FB

L_01F1:
    ActorDelete 9
    VMJump L_0300

L_01FB:
    WorkCmpConst 0x400c, 435
    VMJumpIf 1, L_020E
    VMJump L_0218

L_020E:
    ActorDelete 11
    VMJump L_0300

L_0218:
    WorkCmpConst 0x400c, 454
    VMJumpIf 1, L_022B
    VMJump L_0235

L_022B:
    ActorDelete 11
    VMJump L_0300

L_0235:
    WorkCmpConst 0x400c, 472
    VMJumpIf 1, L_0248
    VMJump L_0252

L_0248:
    ActorDelete 10
    VMJump L_0300

L_0252:
    WorkCmpConst 0x400c, 398
    VMJumpIf 1, L_0265
    VMJump L_026F

L_0265:
    ActorDelete 10
    VMJump L_0300

L_026F:
    WorkCmpConst 0x400c, 407
    VMJumpIf 1, L_0282
    VMJump L_028C

L_0282:
    ActorDelete 9
    VMJump L_0300

L_028C:
    WorkCmpConst 0x400c, 413
    VMJumpIf 1, L_029F
    VMJump L_02A9

L_029F:
    ActorDelete 11
    VMJump L_0300

L_02A9:
    WorkCmpConst 0x400c, 443
    VMJumpIf 1, L_02BC
    VMJump L_02C6

L_02BC:
    ActorDelete 11
    VMJump L_0300

L_02C6:
    WorkCmpConst 0x400c, 460
    VMJumpIf 1, L_02D9
    VMJump L_02E3

L_02D9:
    ActorDelete 11
    VMJump L_0300

L_02E3:
    WorkCmpConst 0x400c, 602
    VMJumpIf 1, L_02F6
    VMJump L_0300

L_02F6:
    ActorDelete 6
    VMJump L_0300

L_0300:
    FlagSet 989
    WorkSetConst 0x400f, 0
    WorkSetConst 0x400c, 0

L_0310:
    VMHalt
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Cmd_00CE 0x8021
    TrainerCardGetBirthDate 0x8025, 0x8026
    RTCGetDate 0x8023, 0x8024
    VMStackPush 0x8023
    VMStackPush 0x8025
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPush 0x8026
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0389
    VMCall L_05E8
    VMJump L_03D8

L_0389:
    VMStackPush 0x8021
    VMStackPushConst 4
    VMStackCmp 0
    VMJumpIf 255, L_03A8
    VMCall L_04E3
    VMJump L_03D8

L_03A8:
    VMStackPushFlag 100
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03CB
    VMCall L_05B8
    FlagSet 100
    VMJump L_03D8

L_03CB:
    WordSetPlayerName 0
    ParentActorMsg 1024, 11, 0, 0

L_03D8:
    YesNoWin 0x8022
    ActorMsgClose
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04A7
    VMStackPush 0x4078
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_040A
    WorkSetConst 0x4078, 2

L_040A:
    PlayerSetSpecialSequence 64
    ActorCmdExec 255, Movement_05A0
    ActorCmdWait
    PlayerSetSpecialSequence 8
    ActorCmdExec 255, Movement_05A8
    ActorCmdWait
    ParentActorMsg 1024, 6, 0, 0
    VMCall L_0625
    PokePartyRecoverAll
    RecordAdd 11, 1
    ActorMsgClose
    PlayerSetSpecialSequence 64
    ActorCmdExec 255, Movement_05B0
    ActorCmdWait
    PlayerSetSpecialSequence 8
    PokePartyCheckPokerus 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 101
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0491
    FlagSet 101
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_04A1

L_0491:
    ParentActorMsg 1024, 7, 0, 0
    VMCall L_0578

L_04A1:
    VMJump L_04AD

L_04A7:
    VMCall L_0578

L_04AD:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0

L_04E3:
    WorkSetConst 0x8028, 0
    RTCGetDayPart 0x8028
    WorkCmpConst 0x8028, 0
    VMJumpIf 1, L_0500
    VMJump L_0510

L_0500:
    ParentActorMsg 1024, 1, 0, 0
    VMJump L_0570

L_0510:
    WorkCmpConst 0x8028, 1
    VMJumpIf 1, L_0523
    VMJump L_0533

L_0523:
    ParentActorMsg 1024, 2, 0, 0
    VMJump L_0570

L_0533:
    WorkCmpConst 0x8028, 2
    VMJumpIf 1, L_0560
    WorkCmpConst 0x8028, 3
    VMJumpIf 1, L_0560
    WorkCmpConst 0x8028, 4
    VMJumpIf 1, L_0560
    VMJump L_0570

L_0560:
    ParentActorMsg 1024, 0, 0, 0
    VMJump L_0570

L_0570:
    WorkSetConst 0x8028, 0
    VMReturn

L_0578:
    ActorCmdExec 0x8011, Movement_0594
    ActorCmdWait
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    VMReturn
    .balign 4, 0

Movement_0594:
    Move 100, 1
    Move 62, 1
    MoveEnd

Movement_05A0:
    Move 102, 1
    MoveEnd

Movement_05A8:
    Move 0, 1
    MoveEnd

Movement_05B0:
    Move 104, 1
    MoveEnd

L_05B8:
    ParentActorMsg 1024, 9, 0, 0
    ActorCmdExec 0x8011, Movement_05E0
    ActorCmdWait
    ActorMsgClose
    WordSetPlayerName 0
    ParentActorMsg 1024, 10, 0, 0
    VMReturn
    .balign 4, 0

Movement_05E0:
    Move 75, 1
    MoveEnd

L_05E8:
    ParentActorMsg 1024, 3, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0619
    ParentActorMsg 1024, 4, 0, 0
    VMJump L_0623

L_0619:
    ParentActorMsg 1024, 5, 0, 0

L_0623:
    VMReturn

L_0625:
    WorkSetConst 0x8029, 0
    ActorCmdExec 0x8011, Movement_0654
    ActorCmdWait
    PokePartyGetCount 0x8029, 1
    PokecenPlayHealingSequence 0x8029
    ActorCmdExec 0x8011, Movement_065C
    ActorCmdWait
    VMReturn
    .byte 0x28
    .byte 0x00
    .byte 0x29
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .balign 4, 0

Movement_0654:
    Move 0, 1
    MoveEnd

Movement_065C:
    Move 1, 1
    MoveEnd

Script_2:
    ActorsPauseAll
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0
    FlagGet 106, 0x802a
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    PokePartyGetCount 0x802d, 4
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x802a
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_06C1
    ActorMsg 1024, 21, 0x8011, 4, 0

L_06C1:
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 2
    VMJumpIf 255, L_06E0
    ActorMsg 1024, 22, 0x8011, 4, 0

L_06E0:
    VMStackPush 0x802a
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0797
    ActorMsg 1024, 13, 0x8011, 4, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32814
    ListMenuAdd 18, 65535, 18
    ListMenuAdd 20, 65535, 20
    ListMenuAdd 19, 65535, 19
    ListMenuShow
    WorkCmpConst 0x802e, 18
    VMJumpIf 1, L_0745
    VMJump L_0759

L_0745:
    WorkSetConst 0x802b, 1
    Cmd_01DD 2, 0, 0
    VMJump L_0797

L_0759:
    WorkCmpConst 0x802e, 19
    VMJumpIf 1, L_076C
    VMJump L_0778

L_076C:
    WorkSetConst 0x802b, 0
    VMJump L_0797

L_0778:
    WorkCmpConst 0x802e, 20
    VMJumpIf 1, L_078B
    VMJump L_0797

L_078B:
    WorkSetConst 0x802c, 1
    VMJump L_0797

L_0797:
    VMStackPush 0x802c
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07D3
    ActorMsg 1024, 14, 0x8011, 4, 0
    YesNoWin 0x802e
    VMStackPush 0x802e
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07D3
    WorkSetConst 0x802b, 1

L_07D3:
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0809
    GameCommCheckDSiWiFi 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0809
    ActorMsgClose
    RTCallGlobal 2005
    WorkSetConst 0x802b, 0

L_0809:
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0846
    Cmd_00E5 0x8008, 0x8009
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0846
    WordSetTrainerClassName 0, 0x8009
    ActorMsg 1024, 23, 0x8011, 4, 0

L_0846:
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0882
    ActorMsg 1024, 15, 0x8011, 4, 0
    YesNoWin 0x802e
    VMStackPush 0x802e
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0882
    WorkSetConst 0x802b, 0

L_0882:
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_08EA
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    RTCallGlobal 2003
    WorkSet 0x802e, 0x8000
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMStackPush 0x802e
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_08EA
    WorkSetConst 0x802b, 0

L_08EA:
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0947
    VMStackPush 0x8000
    RTCallGlobal 2004
    WorkSet 0x802e, 0x8000
    VMStackPop 0x8000
    VMStackPush 0x802e
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_092E
    WorkSetConst 0x802b, 0
    VMJump L_0947

L_092E:
    VMStackPush 0x802e
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0947
    WorkSetConst 0x802b, 0

L_0947:
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_097E
    Cmd_02C5 16
    FunfestBGMReturn
    ActorMsg 1024, 16, 0x8011, 4, 0
    ActorMsgClose
    VMCall L_09CD
    PokePartyRecoverAll
    FieldSetNextZoneHere
    FlagSet 2405
    MapChangeUnionRoom

L_097E:
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_09A1
    ActorMsg 1024, 17, 0x8011, 4, 0
    LastKeyWait
    ActorMsgClose

L_09A1:
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802a, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    VMCall L_09CD
    RTEndGlobal

L_09CD:
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8030, 0
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8032, 0
    WorkSetConst 0x4041, 1
    PlayerGetGPos 0x802f, 0x8030
    WorkSub 0x8030, 3
    BMCreateHandleByGPos 0x8031, 5, 0x802f, 0x8030
    ActorCmdExec 0x8011, Movement_0A94
    VMSleep 16
    ActorCmdExec 255, Movement_0AA4
    ActorCmdWait
    SEPlay 1671
    BMHndAudioVisualAnmPlay 0x8031, 0
    BMHndAnmWait 0x8031
    SEWait
    ActorCmdExec 255, Movement_0AAC
    ActorCmdWait
    SEPlay 1671
    BMHndAudioVisualAnmPlay 0x8031, 1
    BMHndAnmWait 0x8031
    SEWait
    BMReleaseHandle 0x8031
    EvCameraInit
    EvCameraUnbind
    BMCreateHandleByGPos 0x8032, 6, 0x802f, 0x8030
    SEPlay 1672
    BMHndAudioVisualAnmPlay 0x8032, 1
    PlayerMoveToYAsync_ 0, 40, 64, 0
    BMHndAnmWait 0x8032
    FadeOutBlackQ
    FadeWait
    SEStop
    BMReleaseHandle 0x8032
    EvCameraRebind
    EvCameraEnd
    VMReturn
    .byte 0x28
    .byte 0x00
    .byte 0x32
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x31
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x30
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x2f
    .byte 0x80
    .balign 4, 0

Movement_0A94:
    Move 12, 1
    Move 14, 1
    Move 3, 1
    MoveEnd

Movement_0AA4:
    Move 12, 2
    MoveEnd

Movement_0AAC:
    Move 12, 2
    Move 1, 1
    MoveEnd
    WorkSetConst 0x8033, 0

Script_7:
    WorkSetConst 0x8033, 0
    VMCall L_0ADA
    RTEndGlobal

Script_8:
    WorkSetConst 0x8033, 1
    VMCall L_0ADA
    RTEndGlobal

L_0ADA:
    WorkSetConst 0x8034, 0
    WorkSetConst 0x8035, 0
    WorkSetConst 0x8036, 0
    WorkSetConst 0x8037, 0
    WorkSetConst 0x8038, 0
    WorkSetConst 0x8039, 0
    WorkSetConst 0x4041, 0
    FlagReset 2405
    PlayerGetGPos 0x8034, 0x8035
    WorkAdd 0x8035, 3
    ActorFindByGPos 0x8036, 0x8010, 0x8034, 3, 0x8035
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B51
    WorkSub 0x8034, 1
    WorkSub 0x8035, 1
    ActorSetGPos 0x8036, 0x8034, 3, 0x8035, 3
    WorkGet 0x8011, 0x8036

L_0B51:
    EvCameraInit
    EvCameraUnbind
    ActorCmdExec 255, Movement_0C50
    ActorCmdWait
    PlayerGetGPos 0x8034, 0x8035
    BMCreateHandleByGPos 0x8037, 6, 0x8034, 0x8035
    BMHndAudioVisualAnmPlay 0x8037, 0
    BMHndAnmPause 0x8037
    VMStackPush 0x8033
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B94
    CallSeasonBanner
    VMJump L_0B96

L_0B94:
    FadeInBlackQ_

L_0B96:
    FadeWait
    SEPlay 1672
    BMHndAudioVisualAnmPlay 0x8037, 0
    PlayerMoveToYAsync_ 1, 40, 64, 0
    VMSleep 2
    ActorCmdExec 255, Movement_0C58
    ActorCmdWait
    BMHndAnmWait 0x8037
    SEStop
    BMReleaseHandle 0x8037
    BMCreateHandleByGPos 0x8038, 5, 0x8034, 0x8035
    SEPlay 1671
    BMHndAudioVisualAnmPlay 0x8038, 0
    BMHndAnmWait 0x8038
    SEWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 255, Movement_0C70
    ActorCmdWait
    ActorCmdExec 0x8011, Movement_0C64
    ActorCmdWait
    SEPlay 1671
    BMHndAudioVisualAnmPlay 0x8038, 1
    BMHndAnmWait 0x8038
    SEWait
    BMReleaseHandle 0x8038
    .byte 0xed
    .byte 0x03
    .byte 0x04
    .byte 0x00
    .byte 0x39
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x39
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
    .byte 0x06
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x04
    .byte 0x00
    .byte 0xe6
    .byte 0x03
    VMNop
    VMReturn
    .byte 0x28
    .byte 0x00
    .byte 0x39
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x38
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x37
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x36
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x35
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x34
    .byte 0x80
    .balign 4, 0

Movement_0C50:
    Move 69, 1
    MoveEnd

Movement_0C58:
    Move 70, 1
    Move 1, 1
    MoveEnd

Movement_0C64:
    Move 15, 1
    Move 13, 1
    MoveEnd

Movement_0C70:
    Move 13, 4
    MoveEnd

Script_9:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 106
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C99
    CallGeonet
    VMJump L_0CA2

L_0C99:
    InfoMsg 24, 2
    LastKeyWait
    InfoMsgClose_0039

L_0CA2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    VMStackPush 0x404c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0CED
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 27, 0, 0
    MsgWinCloseAll
    RTGetZoneID 0x4192
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 607, 9, 0, 19, 1
    VMJump L_0D01

L_0CED:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose

L_0D01:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    WorkCmpConst 0x4192, 8
    VMJumpIf 1, L_0D20
    VMJump L_0D32

L_0D20:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0D32:
    WorkCmpConst 0x4192, 20
    VMJumpIf 1, L_0D45
    VMJump L_0D57

L_0D45:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0D57:
    WorkCmpConst 0x4192, 41
    VMJumpIf 1, L_0D6A
    VMJump L_0D7C

L_0D6A:
    ActorMsg 1024, 28, 12, 0, 0
    VMJump L_0FF1

L_0D7C:
    WorkCmpConst 0x4192, 65
    VMJumpIf 1, L_0D8F
    VMJump L_0DA1

L_0D8F:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0DA1:
    WorkCmpConst 0x4192, 99
    VMJumpIf 1, L_0DB4
    VMJump L_0DC6

L_0DB4:
    ActorMsg 1024, 28, 10, 0, 0
    VMJump L_0FF1

L_0DC6:
    WorkCmpConst 0x4192, 109
    VMJumpIf 1, L_0DD9
    VMJump L_0DEB

L_0DD9:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0DEB:
    WorkCmpConst 0x4192, 115
    VMJumpIf 1, L_0DFE
    VMJump L_0E10

L_0DFE:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0E10:
    WorkCmpConst 0x4192, 122
    VMJumpIf 1, L_0E23
    VMJump L_0E35

L_0E23:
    ActorMsg 1024, 28, 12, 0, 0
    VMJump L_0FF1

L_0E35:
    WorkCmpConst 0x4192, 146
    VMJumpIf 1, L_0E48
    VMJump L_0E5A

L_0E48:
    ActorMsg 1024, 28, 6, 0, 0
    VMJump L_0FF1

L_0E5A:
    WorkCmpConst 0x4192, 1
    VMJumpIf 1, L_0E6D
    VMJump L_0E7F

L_0E6D:
    ActorMsg 1024, 28, 9, 0, 0
    VMJump L_0FF1

L_0E7F:
    WorkCmpConst 0x4192, 425
    VMJumpIf 1, L_0E92
    VMJump L_0EA4

L_0E92:
    ActorMsg 1024, 28, 9, 0, 0
    VMJump L_0FF1

L_0EA4:
    WorkCmpConst 0x4192, 435
    VMJumpIf 1, L_0EB7
    VMJump L_0EC9

L_0EB7:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0EC9:
    WorkCmpConst 0x4192, 454
    VMJumpIf 1, L_0EDC
    VMJump L_0EEE

L_0EDC:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0EEE:
    WorkCmpConst 0x4192, 472
    VMJumpIf 1, L_0F01
    VMJump L_0F13

L_0F01:
    ActorMsg 1024, 28, 10, 0, 0
    VMJump L_0FF1

L_0F13:
    WorkCmpConst 0x4192, 398
    VMJumpIf 1, L_0F26
    VMJump L_0F38

L_0F26:
    ActorMsg 1024, 28, 10, 0, 0
    VMJump L_0FF1

L_0F38:
    WorkCmpConst 0x4192, 407
    VMJumpIf 1, L_0F4B
    VMJump L_0F5D

L_0F4B:
    ActorMsg 1024, 28, 9, 0, 0
    VMJump L_0FF1

L_0F5D:
    WorkCmpConst 0x4192, 413
    VMJumpIf 1, L_0F70
    VMJump L_0F82

L_0F70:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0F82:
    WorkCmpConst 0x4192, 443
    VMJumpIf 1, L_0F95
    VMJump L_0FA7

L_0F95:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0FA7:
    WorkCmpConst 0x4192, 460
    VMJumpIf 1, L_0FBA
    VMJump L_0FCC

L_0FBA:
    ActorMsg 1024, 28, 11, 0, 0
    VMJump L_0FF1

L_0FCC:
    WorkCmpConst 0x4192, 602
    VMJumpIf 1, L_0FDF
    VMJump L_0FF1

L_0FDF:
    ActorMsg 1024, 28, 6, 0, 0
    VMJump L_0FF1

L_0FF1:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x404c, 1
    WorkSetConst 0x4192, 0
    FlagSet 989
    FlagSet 2442
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .byte 0x28
    .byte 0x00
    .byte 0x3a
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0x28
    .byte 0x00
    .byte 0x3b
    .byte 0x80
    .byte 0x00
    .byte 0x00
    .byte 0xed
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0x3a
    .byte 0x80
    .byte 0x64
    .byte 0x00
    .byte 0xff
    .byte 0x00
    .byte 0xa7
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x65
    .byte 0x00
    .byte 0x09
    .byte 0x00
    .byte 0x3a
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
    .byte 0x14
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x3c
    .byte 0x00
    .byte 0x00
    .byte 0x04
    RTEndGlobal
    .byte 0x11
    .byte 0x80
    .byte 0x04
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x3e
    .byte 0x00
    .byte 0x1e
    .byte 0x00
    .byte 0x3d
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xed
    .byte 0x03
    .byte 0x03
    .byte 0x00
    .byte 0x3b
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x3b
    .byte 0x80
    .byte 0x08
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x11
    .byte 0x00
    VMHalt
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x24
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xf1
    .byte 0x03
    .byte 0x3b
    .byte 0x80
    .byte 0x4c
    .byte 0x00
    .byte 0x00
    .byte 0x34
    .byte 0x00
    .byte 0x1e
    SurveyGetCurrentAnswerIDs 0x5c00, 256, 0x803b
    VMHalt
    .byte 0xa9
    .byte 0x00
    .byte 0x26
    .byte 0x05
    .byte 0x34
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    VMHalt
    .byte 0xaa
    .byte 0x00
    .byte 0x4b
    .byte 0x00
    .byte 0x36
    .byte 0x00
    .byte 0xf0
    .byte 0x03
    .byte 0x04
    .byte 0x00
    VMNop
    SystemMsg 32, 2
    VMSleep 1
    MsgSetLoadingSpinner 0
    SaveDataWrite 0x803b
    VMStackPush 0x803a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_10C0
    Cmd_02ED 1, 0

L_10C0:
    MsgWinCloseAll
    WorkSetConst 0x803b, 0
    WorkSetConst 0x803a, 0
    VMReturn
    Move 0, 1
    MoveEnd
