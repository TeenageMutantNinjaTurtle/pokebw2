#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0

Script_1:
    ActorsPauseAll
    VMStackPushFlag 15
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0051
    PedometerGet 0x400e
    DebugPrint 0x400e

L_0051:
    VMStackPushFlag 2768
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_007E
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_032A

L_007E:
    VMStackPushFlag 2768
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 15
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01E3
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 0, 1, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01CD
    WorkSetConst 0x400e, 0
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8020
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_00F5
    VMJump L_0111

L_00F5:
    ActorCmdExec 255, Movement_0A70
    ActorWalkRoute 0, 5, 4, 0, 8, 0
    VMJump L_016F

L_0111:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_0124
    VMJump L_0140

L_0124:
    ActorCmdExec 255, Movement_0A70
    ActorWalkRoute 0, 5, 2, 0, 8, 0
    VMJump L_016F

L_0140:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_0153
    VMJump L_016F

L_0153:
    ActorCmdExec 255, Movement_0A60
    ActorWalkRoute 0, 7, 2, 0, 8, 0
    VMJump L_016F

L_016F:
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    WorkSet 0x8000, 0
    WorkSet 0x8001, 4
    WorkSet 0x8002, 0
    WorkSet 0x8003, 0
    WorkSet 0x8004, 2
    RTCallGlobal 10535
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    PedometerStart
    WorkSetConst 0x400f, 1
    FlagSet 15
    VMJump L_01DD

L_01CD:
    ActorMsg 1024, 2, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01DD:
    VMJump L_032A

L_01E3:
    VMStackPush 0x400e
    VMStackPushConst 365
    VMStackCmp 0
    VMStackPushFlag 15
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02AC
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8025, 0
    ActorMsg 1024, 5, 1, 4, 0
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32805
    ListMenuAdd 6, 65535, 0
    ListMenuAdd 7, 65535, 1
    ListMenuShow
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0296
    ActorMsg 1024, 9, 1, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 2
    WorkSet 0x8001, 0
    RTCallGlobal 10536
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMCall L_0330
    PedometerEnd
    WorkSetConst 0x400f, 0
    FlagSet 2768
    FlagReset 15
    VMJump L_02A6

L_0296:
    ActorMsg 1024, 8, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02A6:
    VMJump L_032A

L_02AC:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 3, 1, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 88
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 2
    WorkSet 0x8001, 0
    RTCallGlobal 10536
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMCall L_0330
    ActorMsg 1024, 4, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    PedometerEnd
    WorkSetConst 0x400f, 0
    FlagSet 2768
    FlagSet 2783
    FlagReset 15

L_032A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0330:
    PlayerGetGPos 0x8021, 0x8022
    PlayerGetDir 0x8020
    ActorGetGPos 0, 0x8023, 0x8024
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0383
    ActorCmdExec 0, Movement_0684
    VMJump L_0633

L_0383:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_03C4
    ActorCmdExec 0, Movement_0690
    VMJump L_0633

L_03C4:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0405
    ActorCmdExec 0, Movement_06A4
    VMJump L_0633

L_0405:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 8
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0446
    ActorCmdExec 0, Movement_06B4
    VMJump L_0633

L_0446:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0487
    ActorCmdExec 0, Movement_06C8
    VMJump L_0633

L_0487:
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 7
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_04C8
    ActorCmdExec 0, Movement_06D8
    VMJump L_0633

L_04C8:
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 5
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0509
    ActorCmdExec 0, Movement_06EC
    VMJump L_0633

L_0509:
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_054A
    ActorCmdExec 0, Movement_06FC
    VMJump L_0633

L_054A:
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0593
    ActorCmdExec 0, Movement_0708
    ActorCmdExec 255, Movement_0660
    VMJump L_0633

L_0593:
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_05DC
    ActorCmdExec 0, Movement_0714
    ActorCmdExec 255, Movement_0674
    VMJump L_0633

L_05DC:
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 5
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0625
    ActorCmdExec 0, Movement_071C
    ActorCmdExec 255, Movement_0674
    VMJump L_0633

L_0625:
    ActorWalkRoute 0, 5, 3, 1, 8, 0

L_0633:
    ActorCmdWait
    VMReturn
    .balign 4, 0
    Move 0, 1
    Move 71, 1
    Move 13, 1
    Move 72, 1
    MoveEnd
    Move 0, 1
    Move 71, 1
    Move 12, 1
    Move 72, 1
    MoveEnd

Movement_0660:
    Move 14, 1
    Move 13, 1
    Move 15, 2
    Move 32, 1
    MoveEnd

Movement_0674:
    Move 13, 1
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_0684:
    Move 13, 1
    Move 35, 1
    MoveEnd

Movement_0690:
    Move 13, 2
    Move 14, 2
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_06A4:
    Move 14, 2
    Move 13, 1
    Move 35, 1
    MoveEnd

Movement_06B4:
    Move 13, 1
    Move 14, 3
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_06C8:
    Move 14, 2
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_06D8:
    Move 13, 1
    Move 14, 2
    Move 12, 2
    Move 35, 1
    MoveEnd

Movement_06EC:
    Move 14, 1
    Move 12, 2
    Move 35, 1
    MoveEnd

Movement_06FC:
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_0708:
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_0714:
    Move 15, 1
    MoveEnd

Movement_071C:
    Move 13, 1
    Move 35, 1
    MoveEnd

Script_2:
    ActorsPauseAll
    VMStackPushFlag 2406
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2768
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_076F
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 619, 0
    ParentActorMsg 1024, 15, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_08B0

L_076F:
    VMStackPushFlag 2768
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2783
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_07B4
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 619, 0
    ParentActorMsg 1024, 17, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_08B0

L_07B4:
    VMStackPushFlag 2768
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2783
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_07F9
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 619, 0
    ParentActorMsg 1024, 16, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_08B0

L_07F9:
    SEPlay 1351
    ActorSetEyeToEye
    DebugPrint 0x400e
    WordSetPlayerName 0
    PedometerGet 0x400e
    PVPlay 619, 0
    VMStackPush 0x400e
    VMStackPushConst 99
    VMStackCmp 3
    VMJumpIf 255, L_0835
    SystemMsg 22, 2
    PVWait
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08B0

L_0835:
    VMStackPush 0x400e
    VMStackPushConst 199
    VMStackCmp 3
    VMJumpIf 255, L_085A
    SystemMsg 21, 2
    PVWait
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08B0

L_085A:
    VMStackPush 0x400e
    VMStackPushConst 299
    VMStackCmp 3
    VMJumpIf 255, L_087F
    SystemMsg 20, 2
    PVWait
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08B0

L_087F:
    VMStackPush 0x400e
    VMStackPushConst 364
    VMStackCmp 3
    VMJumpIf 255, L_08A4
    SystemMsg 19, 2
    PVWait
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08B0

L_08A4:
    SystemMsg 18, 2
    PVWait
    LastKeyWait
    MsgWinCloseAll

L_08B0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 15
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08DF
    SystemMsg 23, 2
    LastKeyWait
    MsgWinCloseAll
    VMJump L_091A

L_08DF:
    ActorCmdExec 1, Movement_0A38
    ActorCmdWait
    SEPlay 1835
    ScreamMsg 11, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose_0039
    ActorCmdExec 255, Movement_0A60
    ActorCmdWait
    ActorMsg 1024, 14, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0A60
    ActorCmdWait

L_091A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 15
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0949
    SystemMsg 24, 2
    LastKeyWait
    MsgWinCloseAll
    VMJump L_09A2

L_0949:
    ActorCmdExec 1, Movement_0A50
    ActorCmdWait
    SEPlay 1835
    ScreamMsg 11, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose_0039
    ActorWalkRoute 1, 7, 5, 1, 4, 1
    ActorCmdExec 255, Movement_0A68
    ActorCmdWait
    ActorMsg 1024, 13, 1, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 1, 6, 3, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 1, Movement_0A60
    ActorCmdWait

L_09A2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1835
    ActorCmdExec 1, Movement_0A40
    ActorCmdWait
    ScreamMsg 11, 2
    SEWait
    MsgWaitAdvance
    InfoMsgClose_0039
    ActorWalkRoute 1, 5, 6, 1, 4, 1
    ActorCmdExec 255, Movement_0A58
    ActorCmdWait
    ActorMsg 1024, 12, 1, 0, 0
    MsgWinCloseAll
    ActorPairSetMoveEnable 1
    ActorWalkRoute 1, 6, 3, 1, 8, 0
    ActorCmdExec 255, Movement_0A20
    ActorCmdWait
    ActorCmdExec 1, Movement_0A60
    ActorCmdWait
    ActorPairSetMoveEnable 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_0A20:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd

Movement_0A38:
    Move 0, 1
    MoveEnd

Movement_0A40:
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0

Movement_0A50:
    Move 3, 1
    MoveEnd

Movement_0A58:
    Move 32, 1
    MoveEnd

Movement_0A60:
    Move 33, 1
    MoveEnd

Movement_0A68:
    Move 34, 1
    MoveEnd

Movement_0A70:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
