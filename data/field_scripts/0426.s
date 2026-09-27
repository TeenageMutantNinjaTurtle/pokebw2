#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    GameGetVersion 0x8020
    VMStackPushFlag 667
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_005C
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0056
    WorkSetConst 0x4020, 365
    VMJump L_005C

L_0056:
    WorkSetConst 0x4020, 364

L_005C:
    VMHalt

Script_2:
    ActorsPauseAll
    GameGetVersion 0x8020
    SEPlay 2031
    EvCameraShake 4, 0, 4, 5, 1, 0, 1, 3
    SEWait
    VMSleep 30
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0160
    SystemMsg 0, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_013D
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 16
    VMStackCmp 5
    VMJumpIf 255, L_00E5
    ActorWalkRoute 255, 16, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_0670
    ActorCmdWait

L_00E5:
    ItemSub 617, 1, 0x8010
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x108000, 0, 0xa8000, 30
    EvCameraWait
    VMSleep 8
    .byte 0xf4
    .byte 0x03
    .byte 0x35
    .byte 0x02
    .byte 0xea
    .byte 0x03
    .byte 0x06
    .byte 0x00
    .byte 0x24
    .byte 0x00
    .byte 0x9b
    .byte 0x02
    .byte 0x28
    .byte 0x00
    .byte 0x1b
    .byte 0x41
    VMHalt
    .byte 0x28
    .byte 0x00
    .byte 0x20
    .byte 0x40
    .byte 0x6d
    .byte 0x01
    .byte 0x34
    .byte 0x00
    VMNop2
    VMHalt
    .byte 0x4b
    .byte 0x00
    .byte 0x3f
    .byte 0x00
    .byte 0x04
    .byte 0x00
    DayCareCalcWithdrawCost 0, 30
    RTEndGlobal
    VMNop

L_013D:
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0698
    ActorCmdWait
    VMSleep 8
    WordSetPlayerName 0
    SystemMsg 2, 2
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0227

L_0160:
    SystemMsg 5, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_020A
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 16
    VMStackCmp 5
    VMJumpIf 255, L_01B2
    ActorWalkRoute 255, 16, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_0670
    ActorCmdWait

L_01B2:
    ItemSub 616, 1, 0x8010
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x108000, 0, 0xa8000, 30
    EvCameraWait
    VMSleep 8
    .byte 0xf4
    .byte 0x03
    .byte 0x35
    .byte 0x02
    .byte 0xea
    .byte 0x03
    .byte 0x06
    .byte 0x00
    .byte 0x24
    .byte 0x00
    .byte 0x9b
    .byte 0x02
    .byte 0x28
    .byte 0x00
    .byte 0x1b
    .byte 0x41
    VMHalt
    .byte 0x28
    .byte 0x00
    .byte 0x20
    .byte 0x40
    .byte 0x6c
    .byte 0x01
    .byte 0x34
    .byte 0x00
    .byte 0x06
    .byte 0x00
    VMHalt
    .byte 0x4b
    .byte 0x00
    .byte 0x3f
    .byte 0x00
    .byte 0x04
    .byte 0x00
    WorkGet 0, 30
    RTEndGlobal
    VMNop

L_020A:
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0698
    ActorCmdWait
    VMSleep 8
    WordSetPlayerName 0
    SystemMsg 7, 2
    LastKeyWait
    MsgWinCloseAll

L_0227:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    FadeOutBlackQ
    FadeWait
    GameGetVersion 0x8020
    DebugPrint 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_025C
    FieldClose
    Call3DDemo 9, 0
    FieldOpen
    VMJump L_0266

L_025C:
    FieldClose
    Call3DDemo 8, 0
    FieldOpen

L_0266:
    ActorAdd 0
    FadeInBlackQ
    FadeWait
    BGMChangeMapEx 6
    EvCameraRebind
    EvCameraEnd
    VMReturn

Script_3:
    ActorsPauseAll
    SEPlay 1351
    WorkSetConst 0x8023, 0
    PlayerGetDir 0x8023
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_029B
    VMJump L_02A9

L_029B:
    ActorCmdExec 255, Movement_0648
    VMJump L_02EB

L_02A9:
    WorkCmpConst 0x8023, 3
    VMJumpIf 1, L_02BC
    VMJump L_02CA

L_02BC:
    ActorCmdExec 255, Movement_0628
    VMJump L_02EB

L_02CA:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_02DD
    VMJump L_02EB

L_02DD:
    ActorCmdExec 255, Movement_0638
    VMJump L_02EB

L_02EB:
    ActorCmdWait
    WorkSetConst 0x8023, 0
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xe5000, 0x108000, 0, 0xb9000, 6
    EvCameraWait
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0336
    ActorCmdExec 0, Movement_0620
    VMJump L_033E

L_0336:
    ActorCmdExec 0, Movement_0618

L_033E:
    ActorCmdWait
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8024, 1
    WorkOr 0x8024, 16
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0388
    PVPlay 644, 0
    ScreamMsg 3, 0
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    CallWildBattle 644, 70, 0x8024
    VMJump L_03A1

L_0388:
    PVPlay 643, 0
    ScreamMsg 8, 0
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    CallWildBattle 643, 70, 0x8024

L_03A1:
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03D6
    ActorDelete 0
    FlagSet 667
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveToDefault 1
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    CallWildBattleEnd
    VMJump L_03D8

L_03D6:
    CallWildLose

L_03D8:
    WorkSetConst 0x8024, 0
    WildBattleGetResult 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_03F5
    VMJump L_03FF

L_03F5:
    FlagSet 234
    VMJump L_0456

L_03FF:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_041F
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_041F
    VMJump L_0456

L_041F:
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0446
    SystemMsg 4, 2
    LastKeyWait
    InfoMsgClose
    VMJump L_0450

L_0446:
    SystemMsg 9, 2
    LastKeyWait
    InfoMsgClose

L_0450:
    VMJump L_0456

L_0456:
    VMStackPushFlag 480
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_046F
    VMCall L_0475

L_046F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0475:
    ActorNew 16, 20, 0, 251, 103, 0
    ActorWalkRoute 251, 16, 14, 0, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_0680
    ActorCmdWait
    GameGetVersion 0x8020
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_04B4
    VMJump L_04EB

L_04B4:
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_04D9
    ActorMsg 1024, 10, 251, 0, 0
    VMJump L_04E5

L_04D9:
    ActorMsg 1024, 13, 251, 0, 0

L_04E5:
    VMJump L_057F

L_04EB:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_04FE
    VMJump L_0535

L_04FE:
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0523
    ActorMsg 1024, 11, 251, 0, 0
    VMJump L_052F

L_0523:
    ActorMsg 1024, 14, 251, 0, 0

L_052F:
    VMJump L_057F

L_0535:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0548
    VMJump L_057F

L_0548:
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_056D
    ActorMsg 1024, 12, 251, 0, 0
    VMJump L_0579

L_056D:
    ActorMsg 1024, 15, 251, 0, 0

L_0579:
    VMJump L_057F

L_057F:
    ActorMsg 1024, 16, 251, 0, 0
    MsgWinCloseAll
    VMSleep 20
    WordSetPlayerName 0
    ActorMsg 1024, 17, 251, 0, 0
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x108000, 0, 0x118000, 32
    ActorCmdExec 251, Movement_06AC
    EvCameraWait
    ActorCmdWait
    ActorCmdExec 251, Movement_0690
    ActorCmdWait
    ActorMsg 1024, 18, 251, 0, 0
    MsgWinCloseAll
    EvCameraReturn 40
    ActorWalkRoute 251, 16, 23, 0, 8, 1
    EvCameraWait
    ActorCmdWait
    ActorDelete 251
    FlagSet 480
    FlagSet 912
    FlagReset 1004
    EvCameraRebind
    EvCameraEnd
    VMReturn
    .balign 4, 0
    Move 172, 1
    MoveEnd

Movement_0618:
    Move 191, 1
    MoveEnd

Movement_0620:
    Move 191, 1
    MoveEnd

Movement_0628:
    Move 13, 1
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_0638:
    Move 13, 1
    Move 14, 1
    Move 32, 1
    MoveEnd

Movement_0648:
    Move 14, 1
    Move 13, 2
    Move 15, 1
    Move 32, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 0, 1
    Move 75, 1
    MoveEnd

Movement_0670:
    Move 32, 1
    MoveEnd
    Move 1, 1
    MoveEnd

Movement_0680:
    Move 29, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_0690:
    Move 34, 1
    MoveEnd

Movement_0698:
    Move 36, 2
    Move 71, 1
    Move 17, 1
    Move 72, 1
    MoveEnd

Movement_06AC:
    Move 13, 2
    Move 9, 1
    Move 63, 3
    Move 182, 1
    MoveEnd
