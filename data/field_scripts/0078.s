#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    FadeInBlack
    FadeWait
    ActorCmdExec 0, Movement_0204
    ActorCmdWait
    ActorCmdExec 255, Movement_022C
    ActorCmdWait
    ActorCmdExec 0, Movement_0220
    ActorCmdWait
    VMStackPush 0x417b
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01E8
    ActorMsg 1024, 12, 0, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8020, 0
    RTCGetWeekDay 0x8020
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_006C
    VMJump L_0092

L_006C:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 42
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_01E8

L_0092:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_00A5
    VMJump L_00CB

L_00A5:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 43
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_01E8

L_00CB:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_00DE
    VMJump L_0104

L_00DE:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 42
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_01E8

L_0104:
    WorkCmpConst 0x8020, 4
    VMJumpIf 1, L_0117
    VMJump L_013D

L_0117:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 54
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_01E8

L_013D:
    WorkCmpConst 0x8020, 5
    VMJumpIf 1, L_0150
    VMJump L_0176

L_0150:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 42
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_01E8

L_0176:
    WorkCmpConst 0x8020, 6
    VMJumpIf 1, L_0189
    VMJump L_01AF

L_0189:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 504
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_01E8

L_01AF:
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_01C2
    VMJump L_01E8

L_01C2:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 50
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_01E8

L_01E8:
    ActorMsg 1024, 10, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x417b, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0204:
    Move 35, 1
    Move 1, 1
    Move 71, 1
    Move 12, 1
    Move 72, 1
    Move 33, 1
    MoveEnd

Movement_0220:
    Move 13, 1
    Move 34, 1
    MoveEnd

Movement_022C:
    Move 14, 2
    Move 3, 1
    MoveEnd

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    VMStackPushFlag 2744
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0414
    RTCGetDayPart 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_03FE
    MoneyWinDisp 31, 1
    ActorMsg 1024, 0, 0, 2, 0
    WorkSetConst 0x8024, 0

L_029A:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_03F8
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32803
    ListMenuAdd 13, 65535, 0
    ListMenuAdd 14, 65535, 1
    ListMenuAdd 15, 65535, 2
    ListMenuShow
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_02E3
    VMJump L_038A

L_02E3:
    WorkSetConst 0x8024, 1
    MoneyCheck 0x8022, 1000
    VMStackPush 0x8022
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0372
    WorkSetConst 0x8025, 0
    Cmd_024A 0x8025
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0366
    ActorMsg 1024, 7, 0, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_034E
    VMCall L_0450
    VMJump L_0360

L_034E:
    MoneyWinClose
    ActorMsg 1024, 9, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0360:
    VMJump L_036C

L_0366:
    VMCall L_0450

L_036C:
    VMJump L_0384

L_0372:
    MoneyWinClose
    ActorMsg 1024, 3, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0384:
    VMJump L_03F2

L_038A:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_039D
    VMJump L_03A9

L_039D:
    VMCall L_04BD
    VMJump L_03F2

L_03A9:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_03BC
    VMJump L_03DA

L_03BC:
    MoneyWinClose
    WorkSetConst 0x8024, 1
    ActorMsg 1024, 9, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03F2

L_03DA:
    MoneyWinClose
    WorkSetConst 0x8024, 1
    ActorMsg 1024, 9, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_03F2:
    VMJump L_029A

L_03F8:
    VMJump L_040E

L_03FE:
    ActorMsg 1024, 2, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_040E:
    VMJump L_0424

L_0414:
    ActorMsg 1024, 11, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0424:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_042C:
    Move 1, 1
    Move 71, 1
    Move 12, 1
    Move 72, 1
    Move 33, 1
    MoveEnd

Movement_0444:
    Move 65, 1
    Move 15, 3
    MoveEnd

L_0450:
    MoneySub 1000
    MoneyWinUpdate
    SEPlay 1621
    SEWait
    FieldSubscreenDisable
    FunfestBGMReturn
    ActorMsg 1024, 8, 0, 2, 0
    MsgWinCloseAll
    MoneyWinClose
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_048B
    PlayerSetSpecialSequence 1

L_048B:
    ActorCmdExec 0, Movement_042C
    ActorCmdExec 255, Movement_0444
    ActorCmdWait
    RecordAdd 126, 1
    WorkSetConst 0x417b, 0
    FlagSet 2744
    RTReserveScript 29
    MapChangeWarp 52, 29, 29, 0
    VMReturn

L_04BD:
    ActorMsg 1024, 1, 0, 2, 0
    ActorMsg 1024, 5, 0, 2, 0
    ActorMsg 1024, 6, 0, 2, 0
    ActorMsg 1024, 4, 0, 2, 0
    VMReturn
    .balign 4, 0
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
