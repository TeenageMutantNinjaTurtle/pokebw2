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
    ScriptEntry Script_12
    ScriptEntry Script_13
    ScriptEntry Script_14
    ScriptEntry Script_15
    ScriptEntry Script_16
    ScriptEntry Script_17
    ScriptEntry Script_18
    ScriptEntry Script_19
    ScriptEntry Script_20
    ScriptEntry Script_21
    ScriptEntry Script_22
    ScriptEntriesEnd

Script_3:
    FlagSet 680
    FlagSet 681
    VMStackPush 0x4162
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_00A4
    RTCGetWeekDay 0x8010
    VMStackPush 0x8010
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_00A4
    FlagReset 680
    FlagReset 681

L_00A4:
    VMStackPush 0x4162
    VMStackPushConst 9
    VMStackCmp 1
    VMStackPush 0x4162
    VMStackPushConst 10
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_00CB
    FlagReset 680

L_00CB:
    VMHalt

Script_4:
    VMStackPush 0x4162
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F0
    BMSetVisible 8, 24, 25, 0
    VMJump L_0100

L_00F0:
    Cmd_0221 0x4162, 0x8010
    BMChangeMdlID 8, 24, 25, 0x8010

L_0100:
    VMHalt

Script_5:
    VMStackPush 0x4162
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0125
    BMSetVisible 8, 24, 25, 0
    VMJump L_0135

L_0125:
    Cmd_0221 0x4162, 0x8010
    BMChangeMdlID 8, 24, 25, 0x8010

L_0135:
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 5208, 0, 0xed000, 0x198000, 0x5004f, 0x250000, 15
    EvCameraWait
    VMStackPush 0x4162
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 261
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0192
    ParentActorMsg 1024, 8, 0, 0
    MsgWinCloseAll
    VMJump L_0257

L_0192:
    VMStackPush 0x4162
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_01B5
    ParentActorMsg 1024, 7, 0, 0
    VMJump L_01BF

L_01B5:
    ParentActorMsg 1024, 9, 0, 0

L_01BF:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0228
    VMStackPush 0x4162
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_01F9
    ParentActorMsg 1024, 10, 0, 0
    VMJump L_0203

L_01F9:
    ParentActorMsg 1024, 11, 0, 0

L_0203:
    MsgWinCloseAll
    VMCall L_0267
    VMStackPushFlag 261
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0222
    FlagSet 261

L_0222:
    VMJump L_0257

L_0228:
    VMStackPush 0x4162
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_024B
    ParentActorMsg 1024, 12, 0, 0
    VMJump L_0255

L_024B:
    ParentActorMsg 1024, 13, 0, 0

L_0255:
    MsgWinCloseAll

L_0257:
    EvCameraMoveToDefault 15
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0267:
    WorkSetConst 0x8020, 0
    MsgSetAutoscrolls 1
    FadeEx 3, 0, 16, 4
    FadeExWait
    EvCameraMoveTo 6616, 60032, 0xed000, 0x16f000, 0x47b1f, 0x1db000, 1
    EvCameraWait
    EvCameraMoveTo 6616, 3968, 0xed000, 0x1b6000, 0x47b1f, 0x1db000, 160
    FadeEx 3, 16, 0, 4
    FadeExWait
    WorkSetConst 0x8020, 14
    WorkAdd 0x8020, 0x4162
    InfoMsg 0x8020, 1
    WorkCmpConst 0x4162, 0
    VMJumpIf 1, L_02DF
    VMJump L_02E9

L_02DF:
    VMSleep 30
    VMJump L_03F2

L_02E9:
    WorkCmpConst 0x4162, 1
    VMJumpIf 1, L_02FC
    VMJump L_0306

L_02FC:
    VMSleep 25
    VMJump L_03F2

L_0306:
    WorkCmpConst 0x4162, 2
    VMJumpIf 1, L_0319
    VMJump L_0323

L_0319:
    VMSleep 25
    VMJump L_03F2

L_0323:
    WorkCmpConst 0x4162, 3
    VMJumpIf 1, L_0336
    VMJump L_0340

L_0336:
    VMSleep 30
    VMJump L_03F2

L_0340:
    WorkCmpConst 0x4162, 4
    VMJumpIf 1, L_0353
    VMJump L_035D

L_0353:
    VMSleep 30
    VMJump L_03F2

L_035D:
    WorkCmpConst 0x4162, 5
    VMJumpIf 1, L_0370
    VMJump L_037A

L_0370:
    VMSleep 30
    VMJump L_03F2

L_037A:
    WorkCmpConst 0x4162, 6
    VMJumpIf 1, L_038D
    VMJump L_0397

L_038D:
    VMSleep 30
    VMJump L_03F2

L_0397:
    WorkCmpConst 0x4162, 7
    VMJumpIf 1, L_03AA
    VMJump L_03B4

L_03AA:
    VMSleep 30
    VMJump L_03F2

L_03B4:
    WorkCmpConst 0x4162, 8
    VMJumpIf 1, L_03C7
    VMJump L_03D1

L_03C7:
    VMSleep 45
    VMJump L_03F2

L_03D1:
    WorkCmpConst 0x4162, 9
    VMJumpIf 1, L_03E4
    VMJump L_03EE

L_03E4:
    VMSleep 55
    VMJump L_03F2

L_03EE:
    VMSleep 55

L_03F2:
    FadeEx 3, 0, 16, 4
    FadeExWait
    MsgWinCloseAll
    EvCameraMoveTo 7000, 9600, 0xed000, 0x1b4000, 0x47b1f, 0x1da6a0, 1
    EvCameraWait
    EvCameraMoveTo 7000, 9600, 0xed000, 0x1b4000, 0x47b1f, 0x12a000, 180
    FadeEx 3, 16, 0, 4
    FadeExWait
    WorkSetConst 0x8020, 25
    WorkAdd 0x8020, 0x4162
    InfoMsg 0x8020, 1
    WorkCmpConst 0x4162, 0
    VMJumpIf 1, L_0462
    VMJump L_046C

L_0462:
    VMSleep 30
    VMJump L_0575

L_046C:
    WorkCmpConst 0x4162, 1
    VMJumpIf 1, L_047F
    VMJump L_0489

L_047F:
    VMSleep 80
    VMJump L_0575

L_0489:
    WorkCmpConst 0x4162, 2
    VMJumpIf 1, L_049C
    VMJump L_04A6

L_049C:
    VMSleep 30
    VMJump L_0575

L_04A6:
    WorkCmpConst 0x4162, 3
    VMJumpIf 1, L_04B9
    VMJump L_04C3

L_04B9:
    VMSleep 30
    VMJump L_0575

L_04C3:
    WorkCmpConst 0x4162, 4
    VMJumpIf 1, L_04D6
    VMJump L_04E0

L_04D6:
    VMSleep 30
    VMJump L_0575

L_04E0:
    WorkCmpConst 0x4162, 5
    VMJumpIf 1, L_04F3
    VMJump L_04FD

L_04F3:
    VMSleep 30
    VMJump L_0575

L_04FD:
    WorkCmpConst 0x4162, 6
    VMJumpIf 1, L_0510
    VMJump L_051A

L_0510:
    VMSleep 30
    VMJump L_0575

L_051A:
    WorkCmpConst 0x4162, 7
    VMJumpIf 1, L_052D
    VMJump L_0537

L_052D:
    VMSleep 30
    VMJump L_0575

L_0537:
    WorkCmpConst 0x4162, 8
    VMJumpIf 1, L_054A
    VMJump L_0554

L_054A:
    VMSleep 35
    VMJump L_0575

L_0554:
    WorkCmpConst 0x4162, 9
    VMJumpIf 1, L_0567
    VMJump L_0571

L_0567:
    VMSleep 35
    VMJump L_0575

L_0571:
    VMSleep 45

L_0575:
    WorkCmpConst 0x4162, 0
    VMJumpIf 1, L_0588
    VMJump L_058E

L_0588:
    VMJump L_0697

L_058E:
    WorkCmpConst 0x4162, 1
    VMJumpIf 1, L_05A1
    VMJump L_05AB

L_05A1:
    FlagSet 2678
    VMJump L_0697

L_05AB:
    WorkCmpConst 0x4162, 2
    VMJumpIf 1, L_05BE
    VMJump L_05C8

L_05BE:
    FlagSet 2679
    VMJump L_0697

L_05C8:
    WorkCmpConst 0x4162, 3
    VMJumpIf 1, L_05DB
    VMJump L_05E5

L_05DB:
    FlagSet 2680
    VMJump L_0697

L_05E5:
    WorkCmpConst 0x4162, 4
    VMJumpIf 1, L_05F8
    VMJump L_0602

L_05F8:
    FlagSet 2681
    VMJump L_0697

L_0602:
    WorkCmpConst 0x4162, 5
    VMJumpIf 1, L_0615
    VMJump L_061F

L_0615:
    FlagSet 2682
    VMJump L_0697

L_061F:
    WorkCmpConst 0x4162, 6
    VMJumpIf 1, L_0632
    VMJump L_063C

L_0632:
    FlagSet 2683
    VMJump L_0697

L_063C:
    WorkCmpConst 0x4162, 7
    VMJumpIf 1, L_064F
    VMJump L_0659

L_064F:
    FlagSet 2684
    VMJump L_0697

L_0659:
    WorkCmpConst 0x4162, 8
    VMJumpIf 1, L_066C
    VMJump L_0676

L_066C:
    FlagSet 2685
    VMJump L_0697

L_0676:
    WorkCmpConst 0x4162, 9
    VMJumpIf 1, L_0689
    VMJump L_0693

L_0689:
    FlagSet 2686
    VMJump L_0697

L_0693:
    FlagSet 2687

L_0697:
    FadeEx 3, 0, 16, 4
    FadeExWait
    MsgWinCloseAll
    EvCameraMoveTo 5208, 0, 0xed000, 0x198000, 0x5004f, 0x250000, 1
    EvCameraWait
    FadeEx 3, 16, 0, 4
    FadeExWait
    MsgSetAutoscrolls 0
    WorkSetConst 0x8020, 36
    WorkAdd 0x8020, 0x4162
    ParentActorMsg 1024, 0x8020, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8020, 0
    VMReturn
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8022, 78
    WorkSetConst 0x8024, 2
    WorkSetConst 0x8021, 28
    WorkSetConst 0x8023, 1
    WordSetItemNameEx 0, 0x8022, 0x8024, 0
    WordSetNumber 1, 0x8024, 2
    WordSetItemNameEx 2, 0x8021, 0x8023, 0
    WordSetNumber 3, 0x8023, 2
    VMStackPush 0x400b
    VMStackPushConst 111
    VMStackCmp 5
    VMJumpIf 255, L_0774
    ParentActorMsg 1024, 51, 0, 0
    WorkSetConst 0x400b, 111
    VMJump L_077E

L_0774:
    ParentActorMsg 1024, 52, 0, 0

L_077E:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0826
    VMCall L_083A
    WordSetItemName 0, 0x8022
    WordSetItemName 2, 0x8021
    WorkCmpConst 0x8025, 0
    VMJumpIf 1, L_07B8
    VMJump L_07C8

L_07B8:
    ParentActorMsg 1024, 56, 0, 0
    VMJump L_0820

L_07C8:
    WorkCmpConst 0x8025, 1
    VMJumpIf 1, L_07DB
    VMJump L_07EB

L_07DB:
    ParentActorMsg 1024, 57, 0, 0
    VMJump L_0820

L_07EB:
    ParentActorMsg 1024, 53, 0, 0
    MsgWinCloseAll
    VMCall L_0898
    ParentActorMsg 1024, 55, 0, 0
    VMStackPushFlag 2453
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0820
    VMCall L_0B1E

L_0820:
    VMJump L_0830

L_0826:
    ParentActorMsg 1024, 54, 0, 0

L_0830:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_083A:
    ItemCheckAmount 0x8022, 0x8024, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_085D
    WorkSetConst 0x8025, 0
    VMReturn

L_085D:
    ItemCheckSpace 0x8021, 0x8023, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0880
    WorkSetConst 0x8025, 1
    VMReturn

L_0880:
    ItemSub 0x8022, 0x8024, 0x8010
    ItemAdd 0x8021, 0x8023, 0x8010
    WorkSetConst 0x8025, 2
    VMReturn

L_0898:
    WordSetItemNameEx 0, 0x8022, 0x8024, 0
    WordSetItemNameEx 2, 0x8021, 0x8023, 0
    MEPlay 1302
    SystemMsg 50, 0
    MEWait
    MsgWaitAdvance
    MsgWinCloseAll
    WordSetItemName 0, 0x8022
    WordSetItemName 2, 0x8021
    VMReturn

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8022, 91
    WorkSetConst 0x8024, 1
    WorkSetConst 0x8021, 51
    WorkSetConst 0x8023, 1
    WordSetItemNameEx 0, 0x8022, 0x8024, 0
    WordSetNumber 1, 0x8024, 2
    WordSetItemNameEx 2, 0x8021, 0x8023, 0
    WordSetNumber 3, 0x8023, 2
    VMStackPush 0x400c
    VMStackPushConst 111
    VMStackCmp 5
    VMJumpIf 255, L_092B
    ParentActorMsg 1024, 58, 0, 0
    WorkSetConst 0x400c, 111
    VMJump L_0935

L_092B:
    ParentActorMsg 1024, 59, 0, 0

L_0935:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09DD
    VMCall L_083A
    WordSetItemName 0, 0x8022
    WordSetItemName 2, 0x8021
    WorkCmpConst 0x8025, 0
    VMJumpIf 1, L_096F
    VMJump L_097F

L_096F:
    ParentActorMsg 1024, 63, 0, 0
    VMJump L_09D7

L_097F:
    WorkCmpConst 0x8025, 1
    VMJumpIf 1, L_0992
    VMJump L_09A2

L_0992:
    ParentActorMsg 1024, 64, 0, 0
    VMJump L_09D7

L_09A2:
    ParentActorMsg 1024, 60, 0, 0
    MsgWinCloseAll
    VMCall L_0898
    ParentActorMsg 1024, 62, 0, 0
    VMStackPushFlag 2453
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09D7
    VMCall L_0B1E

L_09D7:
    VMJump L_09E7

L_09DD:
    ParentActorMsg 1024, 61, 0, 0

L_09E7:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8022, 4
    WorkSetConst 0x8024, 20
    WorkSetConst 0x8021, 23
    WorkSetConst 0x8023, 1
    WordSetItemNameEx 0, 0x8022, 0x8024, 0
    WordSetNumber 1, 0x8024, 2
    WordSetItemNameEx 2, 0x8021, 0x8023, 0
    WordSetNumber 3, 0x8023, 2
    VMStackPush 0x400d
    VMStackPushConst 111
    VMStackCmp 5
    VMJumpIf 255, L_0A58
    ParentActorMsg 1024, 67, 0, 0
    WorkSetConst 0x400d, 111
    VMJump L_0A62

L_0A58:
    ParentActorMsg 1024, 68, 0, 0

L_0A62:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B0A
    VMCall L_083A
    WordSetItemName 0, 0x8022
    WordSetItemName 2, 0x8021
    WorkCmpConst 0x8025, 0
    VMJumpIf 1, L_0A9C
    VMJump L_0AAC

L_0A9C:
    ParentActorMsg 1024, 72, 0, 0
    VMJump L_0B04

L_0AAC:
    WorkCmpConst 0x8025, 1
    VMJumpIf 1, L_0ABF
    VMJump L_0ACF

L_0ABF:
    ParentActorMsg 1024, 73, 0, 0
    VMJump L_0B04

L_0ACF:
    ParentActorMsg 1024, 69, 0, 0
    MsgWinCloseAll
    VMCall L_0898
    ParentActorMsg 1024, 71, 0, 0
    VMStackPushFlag 2453
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B04
    VMCall L_0B1E

L_0B04:
    VMJump L_0B14

L_0B0A:
    ParentActorMsg 1024, 70, 0, 0

L_0B14:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0B1E:
    MsgWaitAdvance
    MsgWinCloseAll
    WorkSetConst 0x8026, 0
    GameGetVersion 0x8026
    SEPlay 1908
    VMStackPush 0x8026
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0B56
    Cmd_0275 0, 11, 0
    SystemMsg 65, 0
    VMJump L_0B63

L_0B56:
    Cmd_0275 0, 12, 0
    SystemMsg 66, 0

L_0B63:
    SEWait
    FlagSet 2453
    VMReturn

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    InfoMsg 0, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 86, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 79, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_0F80
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 77, 0, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_0F88
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 74, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 75, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 76, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 78, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    RTCGetWeekDay 0x8010
    VMStackPush 0x8010
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0CB8
    VMStackPush 0x4162
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0CA8
    ParentActorMsg 1024, 82, 0, 0
    VMJump L_0CB2

L_0CA8:
    ParentActorMsg 1024, 81, 0, 0

L_0CB2:
    VMJump L_0CC2

L_0CB8:
    ParentActorMsg 1024, 80, 0, 0

L_0CC2:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4162
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0CF7
    ParentActorMsg 1024, 85, 0, 0
    VMJump L_0D38

L_0CF7:
    RTCGetWeekDay 0x8010
    VMStackPush 0x8010
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0D2E
    ParentActorMsg 1024, 84, 0, 0
    VMJump L_0D38

L_0D2E:
    ParentActorMsg 1024, 83, 0, 0

L_0D38:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 88, 2
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallPokedexDiploma 2, 0
    FieldOpen
    FadeInBlackQ
    FadeWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 87, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 47, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0E4C
    ParentActorMsg 1024, 48, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0DDD
    ActorCmdExec 255, Movement_0F90
    ActorCmdWait
    VMJump L_0E22

L_0DDD:
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E0C
    ActorCmdExec 255, Movement_0F9C
    VMSleep 24
    ActorCmdExec 2, Movement_0FB8
    ActorCmdWait
    VMJump L_0E22

L_0E0C:
    ActorCmdExec 255, Movement_0FAC
    VMSleep 8
    ActorCmdExec 2, Movement_0FB8
    ActorCmdWait

L_0E22:
    VMSleep 16
    RTReserveScript 10342
    FadeOutBlackQ
    FadeWait
    VMSleep 15
    SEPlay 1971
    VMSleep 30
    MapChangeCore 74, 16, 0, 14, 1
    VMJump L_0E5A

L_0E4C:
    ParentActorMsg 1024, 49, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0E5A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 365
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 866
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0ECA
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMStackPushFlag 864
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 865
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0EC4
    FlagReset 864
    FlagReset 865

L_0EC4:
    VMJump L_0F54

L_0ECA:
    VMStackPushFlag 365
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 866
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0F33
    ParentActorMsg 1024, 2, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 213
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 365
    VMJump L_0F54

L_0F33:
    VMStackPushFlag 365
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0F54
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0F54:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 511, 0
    ParentActorMsg 1024, 4, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0F80:
    Move 32, 1
    MoveEnd

Movement_0F88:
    Move 34, 1
    MoveEnd

Movement_0F90:
    Move 13, 1
    Move 35, 1
    MoveEnd

Movement_0F9C:
    Move 14, 1
    Move 13, 3
    Move 15, 1
    MoveEnd

Movement_0FAC:
    Move 13, 2
    Move 15, 1
    MoveEnd

Movement_0FB8:
    Move 33, 1
    MoveEnd
