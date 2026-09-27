#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0

Script_1:
    VMCall L_0075
    VMHalt

Script_2:
    FieldGetContinueFlag 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0073
    VMCall L_0075

L_0073:
    VMHalt

L_0075:
    .byte 0xe8
    .byte 0x03
    .byte 0xe8
    .byte 0x03
    VMCall L_00E2
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00BF
    FlagReset 746
    MedalGetGuruActor 0x8010, 0x8024
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B3
    ActorAdd 0x8024

L_00B3:
    VMCall L_0151
    VMJump L_00E0

L_00BF:
    MedalGetGuruActor 0x8010, 0x8024
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00DC
    ActorDelete 0x8024

L_00DC:
    FlagSet 746

L_00E0:
    VMReturn

L_00E2:
    ItemCheckAmount 627, 1, 0x8010
    DebugPrint 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0109
    WorkSetConst 0x8010, 0
    VMReturn

L_0109:
    MedalGetCount 2, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0129
    WorkSetConst 0x8010, 1
    VMReturn

L_0129:
    MedalGetCount 0, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0149
    WorkSetConst 0x8010, 1
    VMReturn

L_0149:
    VMCall L_06BB
    VMReturn

L_0151:
    ActorGetGPos 0x8024, 0x8025, 0x8026
    PlayerGetGPos 0x8027, 0x8028
    VMStackPush 0x8027
    VMStackPush 0x8025
    VMStackCmp 1
    VMStackPush 0x8028
    VMStackPush 0x8026
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0194
    WorkAdd 0x8025, 1
    ActorSetGPos 0x8024, 0x8025, 0, 0x8026, 1

L_0194:
    VMReturn

Script_3:
    ActorsPauseAll
    ActorCmdExec 255, Movement_07A0
    ActorCmdWait
    ActorCmdExec 1, Movement_0348
    ActorCmdWait
    ActorWalkRoute 1, 107, 664, 1, 8, 1
    ActorCmdWait
    VMCall L_0299
    ActorCmdExec 1, Movement_0354
    ActorCmdWait
    ActorDelete 1
    FlagSet 730
    FlagReset 731
    ActorAdd 0
    BMCreateHandleByGPos 0x8029, 1, 107, 661
    BMHndAudioVisualAnmPlay 0x8029, 0
    BMHndAnmWait 0x8029
    SEPlay 1369
    ActorSetGPos 0, 107, 2, 661, 1
    SEWait
    ActorWalkRoute 0, 107, 662, 1, 8, 0
    ActorCmdExec 255, Movement_07E0
    ActorCmdWait
    BMHndAudioVisualAnmPlay 0x8029, 1
    BMHndAnmWait 0x8029
    BMReleaseHandle 0x8029
    WordSetPlayerName 0
    ActorMsg 1024, 61, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_07E0
    ActorCmdWait
    BMCreateHandleByGPos 0x8029, 1, 107, 661
    BMHndAudioVisualAnmPlay 0x8029, 0
    BMHndAnmWait 0x8029
    ActorCmdExec 0, Movement_07A8
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    BMHndAudioVisualAnmPlay 0x8029, 1
    BMHndAnmWait 0x8029
    BMReleaseHandle 0x8029
    FlagSet 731
    WorkSetConst 0x40a5, 6
    FlagSet 267
    WorkSetConst 0x40a8, 1
    WorkSetConst 0x409e, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0299:
    ActorMsg 1024, 11, 1, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 627
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 12, 1, 0, 0
    YesNoWin 0x8010
    ActorMsg 1024, 13, 1, 0, 0
    ActorMsgClose
    WorkSetConst 0x8020, 0
    VMCall L_0771
    ActorMsg 1024, 14, 1, 0, 0
    ActorMsgClose
    MedalDiscoverInitial
    MedalGetCount 1, 0x8022
    WordSetPlayerName 0
    WordSetNumber 1, 0x8022, 3
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_032F
    SystemMsg 9, 0
    VMJump L_0335

L_032F:
    SystemMsg 10, 0

L_0335:
    InfoMsgClose
    ActorMsg 1024, 15, 1, 0, 0
    ActorMsgClose
    VMReturn
    .balign 4, 0

Movement_0348:
    Move 75, 1
    Move 32, 1
    MoveEnd

Movement_0354:
    Move 13, 4
    Move 15, 6
    Move 13, 5
    MoveEnd

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x409e, 0
    VMJumpIf 1, L_037F
    VMJump L_0391

L_037F:
    VMCall L_0299
    WorkSetConst 0x409e, 1
    VMJump L_0486

L_0391:
    WorkCmpConst 0x409e, 2
    VMJumpIf 1, L_03A4
    VMJump L_03BD

L_03A4:
    WordSetPlaceName 0, 28
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0486

L_03BD:
    WorkCmpConst 0x409e, 4
    VMJumpIf 1, L_03D0
    VMJump L_03E7

L_03D0:
    WordSetPlayerName 0
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0486

L_03E7:
    WorkCmpConst 0x409e, 1
    VMJumpIf 1, L_03FA
    VMJump L_0451

L_03FA:
    VMCall L_0490
    VMCall L_0511
    MedalGetCount 3, 0x8022
    MedalGetCount 4, 0x8023
    VMStackPush 0x8022
    VMStackPush 0x8023
    VMStackCmp 4
    VMJumpIf 255, L_0441
    WorkSetConst 0x409e, 2
    WordSetPlayerName 0
    WordSetPlaceName 1, 28
    ParentActorMsg 1024, 4, 0, 0
    VMJump L_0447

L_0441:
    VMCall L_0708

L_0447:
    LastKeyWait
    ActorMsgClose
    VMJump L_0486

L_0451:
    WorkCmpConst 0x409e, 3
    VMJumpIf 1, L_0464
    VMJump L_0486

L_0464:
    VMCall L_0490
    VMCall L_0511
    VMCall L_059F
    VMCall L_0708
    LastKeyWait
    ActorMsgClose
    VMJump L_0486

L_0486:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    VMReturn
    VMReturn

L_0490:
    MedalGetCount 2, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04AA
    VMReturn

L_04AA:
    WordSetPlayerName 0
    ParentActorMsg 1024, 20, 0, 0
    ActorMsgClose
    .byte 0xe9
    .byte 0x03
    .byte 0x10
    .byte 0x80
    .byte 0x20
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x10
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
    .byte 0x99
    VMHalt
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    .byte 0x10
    .byte 0x80
    .byte 0x20
    .byte 0x80
    .byte 0x09
    .byte 0x00
    .byte 0x10
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
    .byte 0x1e
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x3d
    .byte 0x00
    .byte 0x00
    .byte 0x04
    .byte 0x15
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x3e
    .byte 0x00
    .byte 0x04
    .byte 0x00
    .byte 0x6e
    VMHalt
    .byte 0x00
    .byte 0xe9
    .byte 0x03
    .byte 0x10
    .byte 0x80
    .byte 0x20
    .byte 0x80
    .byte 0x1e
    .byte 0x00
    .byte 0xcf
    .byte 0xff
    .byte 0xff
    .byte 0xff
    VMReturn

L_0511:
    MedalGetCount 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_052B
    VMReturn

L_052B:
    WordSetPlayerName 0
    WordSetNumber 1, 0x8010, 3
    ParentActorMsg 1024, 5, 0, 0
    ActorMsgClose
    MedalGetCount 0, 0x8022
    WordSetPlayerName 0
    WordSetNumber 1, 0x8022, 3
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_056F
    SystemMsg 9, 0
    VMJump L_0575

L_056F:
    SystemMsg 10, 0

L_0575:
    InfoMsgClose
    .byte 0xe8
    .byte 0x03
    .byte 0xea
    .byte 0x03
    MedalGetCount 5, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_059D
    ParentActorMsg 1024, 6, 0, 0

L_059D:
    VMReturn

L_059F:
    VMCall L_06BB
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_05BA
    VMReturn

L_05BA:
    WordSetPlayerName 0
    ParentActorMsg 1024, 16, 0, 0
    ActorMsgClose

L_05C9:
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06B9
    .byte 0xe8
    .byte 0x03
    .byte 0xeb
    .byte 0x03
    MedalGetCount 7, 0x8021
    WordSetMedalRank 1, 0x8021
    SystemMsg 19, 0
    MEPlay 1335
    MEWait
    MsgWaitAdvance
    InfoMsgClose
    ParentActorMsg 1024, 17, 0, 0
    ActorMsgClose
    WorkCmpConst 0x8021, 1
    VMJumpIf 1, L_0619
    VMJump L_0625

L_0619:
    WorkSetConst 0x8020, 2
    VMJump L_0688

L_0625:
    WorkCmpConst 0x8021, 2
    VMJumpIf 1, L_0638
    VMJump L_0644

L_0638:
    WorkSetConst 0x8020, 3
    VMJump L_0688

L_0644:
    WorkCmpConst 0x8021, 3
    VMJumpIf 1, L_0657
    VMJump L_0663

L_0657:
    WorkSetConst 0x8020, 4
    VMJump L_0688

L_0663:
    WorkCmpConst 0x8021, 4
    VMJumpIf 1, L_0676
    VMJump L_0682

L_0676:
    WorkSetConst 0x8020, 5
    VMJump L_0688

L_0682:
    WorkSetConst 0x8020, 1

L_0688:
    VMCall L_0771
    VMCall L_06BB
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06B3
    ParentActorMsg 1024, 18, 0, 0
    ActorMsgClose

L_06B3:
    VMJump L_05C9

L_06B9:
    VMReturn

L_06BB:
    MedalGetCount 7, 0x8021
    VMStackPush 0x8021
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_06DB
    WorkSetConst 0x8010, 0
    VMReturn

L_06DB:
    MedalGetCount 3, 0x8022
    MedalGetCount 4, 0x8023
    VMStackPush 0x8022
    VMStackPush 0x8023
    VMStackCmp 4
    VMJumpIf 255, L_0700
    WorkSetConst 0x8010, 1
    VMReturn

L_0700:
    WorkSetConst 0x8010, 0
    VMReturn

L_0708:
    MedalGetCount 6, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 3
    VMJumpIf 255, L_0735
    WorkSetConst 0x409e, 4
    WordSetPlayerName 0
    ParentActorMsg 1024, 0, 0, 0
    VMReturn

L_0735:
    MedalGetCount 7, 0x8021
    VMStackPush 0x8021
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0759
    ParentActorMsg 1024, 2, 0, 0
    VMReturn

L_0759:
    MedalGetCount 4, 0x8023
    WordSetNumber 0, 0x8023, 3
    ParentActorMsg 1024, 1, 0, 0
    VMReturn

L_0771:
    WorkSetConst 0x802a, 0
    MedalGetFieldEffectID 0x8020, 0x802a
    DebugPrint 0x802a
    PlayFieldEffect 0x802a
    MedalAcknowledge 0x8020, 1
    WordSetPlayerName 0
    WordSetMedalName 1, 0x8020
    SystemMsg 22, 0
    InfoMsgClose
    VMReturn
    .balign 4, 0

Movement_07A0:
    Move 13, 1
    MoveEnd

Movement_07A8:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd

Movement_07E0:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
