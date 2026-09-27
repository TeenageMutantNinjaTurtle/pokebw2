#include "asm/field_script.inc"

// Script plugin 8, from the zones that use this file

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_1:
    VMStackPush 0x413a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0056
    Plugin8_Cmd1025 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0056
    WorkSetConst 0x4119, 1

L_0056:
    VMStackPush 0x4119
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0106
    Plugin8_Cmd1031 20, 0x8020
    DebugPrint 0x8020
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_0086
    VMJump L_00A4

L_0086:
    Plugin8_Cmd1028 3, 6
    Plugin8_Cmd1027 2, 0x8022
    ActorSetGPos 0x8022, 6, 0, 4, 1
    VMJump L_0100

L_00A4:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_00B7
    VMJump L_00D5

L_00B7:
    Plugin8_Cmd1028 3, 7
    Plugin8_Cmd1027 3, 0x8022
    ActorSetGPos 0x8022, 6, 0, 4, 1
    VMJump L_0100

L_00D5:
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_00E8
    VMJump L_0100

L_00E8:
    WorkSetConst 0x4119, 0
    ActorDelete 1
    ActorDelete 2
    ActorDelete 3
    VMJump L_0100

L_0100:
    VMJump L_0118

L_0106:
    WorkSetConst 0x4119, 0
    ActorDelete 1
    ActorDelete 2
    ActorDelete 3

L_0118:
    VMStackPush 0x413a
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_014F
    WorkSetConst 0x8024, 0
    Plugin8_Cmd1027 0, 0x8024
    Plugin8_Cmd1027 1, 0x8024
    Plugin8_Cmd1027 2, 0x8024
    Plugin8_Cmd1027 3, 0x8024
    WorkSetConst 0x413a, 0

L_014F:
    WorkSetConst 0x8024, 0
    VMHalt

Script_2:
    ActorsPauseAll
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8025, 1

L_0171:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03DA
    Plugin8_Cmd1007 4, 255, 0, 0
    Plugin8_Cmd1007 8, 255, 0, 1
    ActorMsg 1024, 0, 0, 0, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32806
    ListMenuAdd 22, 65535, 0
    ListMenuAdd 23, 65535, 1
    ListMenuAdd 24, 65535, 2
    ListMenuAdd 25, 65535, 3
    ListMenuAdd 26, 65535, 4
    ListMenuAdd 27, 65535, 5
    Plugin8_Cmd1002 1, 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01FE
    ListMenuAdd 40, 65535, 9

L_01FE:
    ListMenuAdd 29, 65535, 7
    ListMenuAdd 28, 65535, 8
    ListMenuAdd 30, 65535, 6
    ListMenuShow
    VMStackPush 0x8026
    VMStackPushConst 65534
    VMStackCmp 1
    VMJumpIf 255, L_0231
    WorkSetConst 0x8026, 6

L_0231:
    WorkCmpConst 0x8026, 0
    VMJumpIf 1, L_0244
    VMJump L_0256

L_0244:
    ActorMsg 1024, 1, 0, 0, 0
    VMJump L_03D4

L_0256:
    WorkCmpConst 0x8026, 1
    VMJumpIf 1, L_0269
    VMJump L_027B

L_0269:
    ActorMsg 1024, 2, 0, 0, 0
    VMJump L_03D4

L_027B:
    WorkCmpConst 0x8026, 2
    VMJumpIf 1, L_028E
    VMJump L_02CB

L_028E:
    Plugin8_Cmd1002 1, 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02B9
    ActorMsg 1024, 20, 0, 0, 0
    VMJump L_02C5

L_02B9:
    ActorMsg 1024, 3, 0, 0, 0

L_02C5:
    VMJump L_03D4

L_02CB:
    WorkCmpConst 0x8026, 3
    VMJumpIf 1, L_02DE
    VMJump L_02F0

L_02DE:
    ActorMsg 1024, 4, 0, 0, 0
    VMJump L_03D4

L_02F0:
    WorkCmpConst 0x8026, 4
    VMJumpIf 1, L_0303
    VMJump L_0315

L_0303:
    ActorMsg 1024, 5, 0, 0, 0
    VMJump L_03D4

L_0315:
    WorkCmpConst 0x8026, 5
    VMJumpIf 1, L_0328
    VMJump L_033A

L_0328:
    ActorMsg 1024, 6, 0, 0, 0
    VMJump L_03D4

L_033A:
    WorkCmpConst 0x8026, 7
    VMJumpIf 1, L_034D
    VMJump L_035F

L_034D:
    ActorMsg 1024, 7, 0, 0, 0
    VMJump L_03D4

L_035F:
    WorkCmpConst 0x8026, 8
    VMJumpIf 1, L_0372
    VMJump L_037E

L_0372:
    VMCall L_03F0
    VMJump L_03D4

L_037E:
    WorkCmpConst 0x8026, 6
    VMJumpIf 1, L_0391
    VMJump L_03A9

L_0391:
    ActorMsg 1024, 19, 0, 0, 0
    WorkSetConst 0x8025, 0
    VMJump L_03D4

L_03A9:
    WorkCmpConst 0x8026, 9
    VMJumpIf 1, L_03BC
    VMJump L_03CE

L_03BC:
    ActorMsg 1024, 21, 0, 0, 0
    VMJump L_03D4

L_03CE:
    WorkSetConst 0x8025, 0

L_03D4:
    VMJump L_0171

L_03DA:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_03F0:
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 1

L_0402:
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0655
    Plugin8_Cmd1031 25, 0x8020
    ActorMsg 1024, 18, 0, 0, 0
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32808
    ListMenuAdd 31, 65535, 0
    ListMenuAdd 33, 65535, 2
    ListMenuAdd 39, 65535, 8
    ListMenuAdd 36, 65535, 5
    ListMenuAdd 32, 65535, 1
    ListMenuAdd 34, 65535, 3
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_047B
    ListMenuAdd 35, 65535, 4

L_047B:
    ListMenuAdd 37, 65535, 6
    ListMenuAdd 38, 65535, 7
    ListMenuAdd 30, 65535, 9
    ListMenuShow
    VMStackPush 0x8028
    VMStackPushConst 65534
    VMStackCmp 1
    VMJumpIf 255, L_04AE
    WorkSetConst 0x8028, 9

L_04AE:
    WorkCmpConst 0x8028, 0
    VMJumpIf 1, L_04C1
    VMJump L_0502

L_04C1:
    Plugin8_Cmd1007 8, 255, 0, 0
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04F0
    ActorMsg 1024, 17, 0, 0, 0
    VMJump L_04FC

L_04F0:
    ActorMsg 1024, 16, 0, 0, 0

L_04FC:
    VMJump L_064F

L_0502:
    WorkCmpConst 0x8028, 1
    VMJumpIf 1, L_0515
    VMJump L_0527

L_0515:
    ActorMsg 1024, 8, 0, 0, 0
    VMJump L_064F

L_0527:
    WorkCmpConst 0x8028, 2
    VMJumpIf 1, L_053A
    VMJump L_054C

L_053A:
    ActorMsg 1024, 9, 0, 0, 0
    VMJump L_064F

L_054C:
    WorkCmpConst 0x8028, 3
    VMJumpIf 1, L_055F
    VMJump L_0571

L_055F:
    ActorMsg 1024, 10, 0, 0, 0
    VMJump L_064F

L_0571:
    WorkCmpConst 0x8028, 4
    VMJumpIf 1, L_0584
    VMJump L_0596

L_0584:
    ActorMsg 1024, 11, 0, 0, 0
    VMJump L_064F

L_0596:
    WorkCmpConst 0x8028, 5
    VMJumpIf 1, L_05A9
    VMJump L_05BB

L_05A9:
    ActorMsg 1024, 12, 0, 0, 0
    VMJump L_064F

L_05BB:
    WorkCmpConst 0x8028, 6
    VMJumpIf 1, L_05CE
    VMJump L_05E0

L_05CE:
    ActorMsg 1024, 13, 0, 0, 0
    VMJump L_064F

L_05E0:
    WorkCmpConst 0x8028, 7
    VMJumpIf 1, L_05F3
    VMJump L_0605

L_05F3:
    ActorMsg 1024, 14, 0, 0, 0
    VMJump L_064F

L_0605:
    WorkCmpConst 0x8028, 8
    VMJumpIf 1, L_0618
    VMJump L_062A

L_0618:
    ActorMsg 1024, 15, 0, 0, 0
    VMJump L_064F

L_062A:
    WorkCmpConst 0x8028, 9
    VMJumpIf 1, L_063D
    VMJump L_0649

L_063D:
    WorkSetConst 0x8027, 0
    VMJump L_064F

L_0649:
    WorkSetConst 0x8027, 0

L_064F:
    VMJump L_0402

L_0655:
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    VMReturn

Script_3:
    ActorsPauseAll
    Plugin8_Cmd1031 20, 0x8020
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_067E
    VMJump L_068A

L_067E:
    VMCall L_076F
    VMJump L_0763

L_068A:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_069D
    VMJump L_06A9

L_069D:
    VMCall L_07F3
    VMJump L_0763

L_06A9:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_06BC
    VMJump L_06C8

L_06BC:
    VMCall L_0877
    VMJump L_0763

L_06C8:
    WorkCmpConst 0x8020, 4
    VMJumpIf 1, L_06DB
    VMJump L_06E7

L_06DB:
    VMCall L_0996
    VMJump L_0763

L_06E7:
    WorkCmpConst 0x8020, 5
    VMJumpIf 1, L_06FA
    VMJump L_0706

L_06FA:
    VMCall L_0A7F
    VMJump L_0763

L_0706:
    WorkCmpConst 0x8020, 6
    VMJumpIf 1, L_0719
    VMJump L_0725

L_0719:
    VMCall L_0AC3
    VMJump L_0763

L_0725:
    WorkCmpConst 0x8020, 7
    VMJumpIf 1, L_0738
    VMJump L_0744

L_0738:
    VMCall L_0B07
    VMJump L_0763

L_0744:
    WorkCmpConst 0x8020, 8
    VMJumpIf 1, L_0757
    VMJump L_0763

L_0757:
    VMCall L_0B4D
    VMJump L_0763

L_0763:
    WorkSetConst 0x4119, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_076F:
    VMCall L_0BB9
    Plugin8_Cmd1007 4, 255, 0, 0
    ActorMsg 1024, 41, 1, 0, 0
    ActorMsg 1024, 49, 1, 0, 0
    ActorMsgClose
    ActorFindByGPos 0x8022, 0x8020, 6, 0, 4
    VMCall L_0C48
    Plugin8_Cmd1007 0, 3, 2, 0
    Plugin8_Cmd1007 6, 3, 2, 1
    ActorMsg 1024, 66, 0x8022, 0, 0
    ActorMsgClose
    ActorCmdExec 255, Movement_0C7C
    ActorCmdWait
    ActorMsg 1024, 58, 1, 0, 0
    ActorMsgClose
    Plugin8_Cmd1030 21, 1
    VMCall L_0BCB
    VMReturn

L_07F3:
    VMCall L_0BB9
    Plugin8_Cmd1007 4, 255, 0, 0
    ActorMsg 1024, 42, 1, 0, 0
    ActorMsg 1024, 50, 1, 0, 0
    ActorMsgClose
    ActorFindByGPos 0x8022, 0x8020, 6, 0, 4
    VMCall L_0C48
    Plugin8_Cmd1007 0, 3, 3, 0
    Plugin8_Cmd1007 6, 3, 3, 1
    ActorMsg 1024, 67, 0x8022, 0, 0
    ActorMsgClose
    ActorCmdExec 255, Movement_0C7C
    ActorCmdWait
    ActorMsg 1024, 59, 1, 0, 0
    ActorMsgClose
    Plugin8_Cmd1030 21, 2
    VMCall L_0BCB
    VMReturn

L_0877:
    VMCall L_0BB9
    Plugin8_Cmd1007 4, 255, 0, 0
    Plugin8_Cmd1007 4, 255, 0, 1
    ActorMsg 1024, 43, 1, 0, 0
    ActorMsg 1024, 51, 1, 0, 0
    ActorMsgClose
    Plugin8_Cmd1023 0, 0
    Plugin8_Cmd1007 4, 255, 0, 1
    Plugin8_Cmd1007 8, 255, 0, 2
    ActorMsg 1024, 52, 1, 0, 0
    ActorMsgClose
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xe9000, 0, 0x58000, 60
    EvCameraWait
    ActorFindByGPos 0x8022, 0x8020, 13, 0, 5
    Plugin8_Cmd1002 35, 0x8020
    Plugin8_Cmd1002 37, 0x8023
    Plugin8_Cmd1007 0, 3, 0x8023, 0
    Plugin8_Cmd1007 6, 3, 0x8023, 1
    ActorCmdExec 255, Movement_0C84
    ActorCmdExec 0x8022, Movement_0C74
    ActorCmdWait
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0954
    ActorMsg 1024, 68, 0x8022, 0, 0
    VMJump L_0960

L_0954:
    ActorMsg 1024, 69, 0x8022, 0, 0

L_0960:
    ActorMsgClose
    EvCameraReturn 60
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 255, Movement_0C7C
    ActorCmdWait
    ActorMsg 1024, 60, 1, 0, 0
    ActorMsgClose
    Plugin8_Cmd1030 21, 3
    MedalGive 194
    VMCall L_0BCB
    VMReturn

L_0996:
    VMCall L_0BB9
    Plugin8_Cmd1007 4, 255, 0, 0
    ActorMsg 1024, 44, 1, 0, 0
    ActorMsg 1024, 53, 1, 0, 0
    ActorMsgClose
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xb6000, 0, 0xa4000, 60
    EvCameraWait
    ActorFindByGPos 0x8022, 0x8020, 11, 0, 11
    Plugin8_Cmd1002 36, 0x8020
    Plugin8_Cmd1002 38, 0x8023
    Plugin8_Cmd1007 0, 3, 0x8023, 0
    Plugin8_Cmd1007 6, 3, 0x8023, 1
    ActorCmdExec 255, Movement_0C8C
    ActorCmdExec 0x8022, Movement_0C7C
    ActorCmdWait
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A41
    ActorMsg 1024, 70, 0x8022, 0, 0
    VMJump L_0A4D

L_0A41:
    ActorMsg 1024, 71, 0x8022, 0, 0

L_0A4D:
    ActorMsgClose
    EvCameraReturn 60
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 255, Movement_0C7C
    ActorCmdWait
    ActorMsg 1024, 61, 1, 0, 0
    ActorMsgClose
    Plugin8_Cmd1030 21, 4
    VMCall L_0BCB
    VMReturn

L_0A7F:
    VMCall L_0BB9
    Plugin8_Cmd1007 4, 255, 0, 0
    ActorMsg 1024, 45, 1, 0, 0
    ActorMsg 1024, 54, 1, 0, 0
    ActorMsg 1024, 62, 1, 0, 0
    ActorMsgClose
    Plugin8_Cmd1030 21, 5
    VMCall L_0BCB
    VMReturn

L_0AC3:
    VMCall L_0BB9
    Plugin8_Cmd1007 4, 255, 0, 0
    ActorMsg 1024, 46, 1, 0, 0
    ActorMsg 1024, 55, 1, 0, 0
    ActorMsg 1024, 63, 1, 0, 0
    ActorMsgClose
    Plugin8_Cmd1030 21, 6
    VMCall L_0BCB
    VMReturn

L_0B07:
    VMCall L_0BB9
    Plugin8_Cmd1007 4, 255, 0, 0
    ActorMsg 1024, 47, 1, 0, 0
    ActorMsg 1024, 56, 1, 0, 0
    Plugin8_Cmd1030 21, 7
    ActorMsgClose
    WorkSetConst 0x413a, 1
    FlagSet 2545
    MapChangeWarp 490, 15, 70, 0
    VMReturn

L_0B4D:
    VMCall L_0BB9
    Plugin8_Cmd1007 4, 255, 0, 0
    ActorMsg 1024, 48, 1, 0, 0
    ActorMsg 1024, 57, 1, 0, 0
    ActorMsgClose
    Plugin8_Cmd1002 61, 0x8020
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 0x8020
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 65, 1, 0, 0
    ActorMsgClose
    Plugin8_Cmd1030 21, 8
    VMCall L_0BCB
    VMReturn

L_0BB9:
    ActorWalkRoute 255, 8, 5, 0, 8, 1
    ActorCmdWait
    VMReturn

L_0BCB:
    ActorCmdExec 255, Movement_0C04
    ActorCmdExec 1, Movement_0C18
    ActorCmdExec 2, Movement_0C24
    ActorCmdExec 3, Movement_0C34
    ActorCmdWait
    ActorDelete 2
    ActorDelete 3
    SEPlay 1369
    ActorDelete 1
    SEWait
    VMReturn
    .balign 4, 0

Movement_0C04:
    Move 15, 1
    Move 2, 1
    Move 63, 1
    Move 1, 2
    MoveEnd

Movement_0C18:
    Move 13, 9
    Move 69, 1
    MoveEnd

Movement_0C24:
    Move 14, 1
    Move 13, 9
    Move 69, 1
    MoveEnd

Movement_0C34:
    Move 63, 1
    Move 15, 1
    Move 13, 9
    Move 69, 1
    MoveEnd

L_0C48:
    ActorCmdExec 0x8022, Movement_0C5C
    ActorCmdExec 255, Movement_0C68
    ActorCmdWait
    VMReturn

Movement_0C5C:
    Move 13, 1
    Move 15, 1
    MoveEnd

Movement_0C68:
    Move 63, 1
    Move 2, 1
    MoveEnd

Movement_0C74:
    Move 2, 1
    MoveEnd

Movement_0C7C:
    Move 0, 1
    MoveEnd

Movement_0C84:
    Move 3, 1
    MoveEnd

Movement_0C8C:
    Move 1, 1
    MoveEnd
