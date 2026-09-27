#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    InfoMsg 2, 1
    InfoMsgClose_0039
    ActorCmdExec 255, Movement_0550
    ActorCmdWait
    PlayerGetDir 0x8020
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_004A
    VMJump L_0058

L_004A:
    ActorCmdExec 255, Movement_0558
    VMJump L_0079

L_0058:
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_006B
    VMJump L_0079

L_006B:
    ActorCmdExec 255, Movement_0570
    VMJump L_0079

L_0079:
    ActorCmdWait
    FlagReset 811
    ActorAdd 7
    PlayerGetGPos 0x8021, 0x8022
    BGMPlay 1238
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_00A0
    VMJump L_00B2

L_00A0:
    WorkAdd 0x8021, 2
    WorkSetConst 0x8022, 138
    VMJump L_00DD

L_00B2:
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_00C5
    VMJump L_00DD

L_00C5:
    ActorSetGPos 7, 723, 0, 146, 0
    WorkAdd 0x8022, 2
    VMJump L_00DD

L_00DD:
    ActorWalkRoute 7, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_0106
    VMJump L_0139

L_0106:
    VMStackPush 0x8022
    VMStackPushConst 138
    VMStackCmp 5
    VMJumpIf 255, L_0133
    ActorWalkRoute 7, 729, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 7, Movement_0560
    ActorCmdWait

L_0133:
    VMJump L_016F

L_0139:
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_014C
    VMJump L_016F

L_014C:
    VMStackPush 0x8021
    VMStackPushConst 724
    VMStackCmp 1
    VMJumpIf 255, L_0169
    ActorCmdExec 7, Movement_0568
    ActorCmdWait

L_0169:
    VMJump L_016F

L_016F:
    ActorMsg 1024, 3, 7, 0, 0
    MsgWinCloseAll
    WorkCmpConst 0x8021, 727
    VMJumpIf 1, L_0190
    VMJump L_019E

L_0190:
    ActorCmdExec 7, Movement_0570
    VMJump L_01CC

L_019E:
    WorkCmpConst 0x8021, 723
    VMJumpIf 1, L_01BE
    WorkCmpConst 0x8021, 724
    VMJumpIf 1, L_01BE
    VMJump L_01CC

L_01BE:
    ActorCmdExec 7, Movement_0558
    VMJump L_01CC

L_01CC:
    ActorCmdWait
    ActorMsg 1024, 4, 7, 0, 0
    MsgWinCloseAll
    WorkCmpConst 0x8021, 727
    VMJumpIf 1, L_01EF
    VMJump L_01FD

L_01EF:
    ActorCmdExec 7, Movement_0560
    VMJump L_022B

L_01FD:
    WorkCmpConst 0x8021, 723
    VMJumpIf 1, L_021D
    WorkCmpConst 0x8021, 724
    VMJumpIf 1, L_021D
    VMJump L_022B

L_021D:
    ActorCmdExec 7, Movement_0568
    VMJump L_022B

L_022B:
    ActorCmdWait
    ActorMsg 1024, 5, 7, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0264
    ActorMsg 1024, 6, 7, 0, 0
    MsgWinCloseAll
    VMJump L_0272

L_0264:
    ActorMsg 1024, 7, 7, 0, 0
    MsgWinCloseAll

L_0272:
    WorkCmpConst 0x8021, 727
    VMJumpIf 1, L_0285
    VMJump L_0293

L_0285:
    ActorCmdExec 7, Movement_0590
    VMJump L_02C1

L_0293:
    WorkCmpConst 0x8021, 723
    VMJumpIf 1, L_02B3
    WorkCmpConst 0x8021, 724
    VMJumpIf 1, L_02B3
    VMJump L_02C1

L_02B3:
    ActorCmdExec 7, Movement_0580
    VMJump L_02C1

L_02C1:
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 635
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 8, 7, 0, 0
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    WorkCmpConst 0x8021, 727
    VMJumpIf 1, L_0308
    VMJump L_033E

L_0308:
    EvCameraMoveTo 9688, 0, 0xed000, 0x2db8000, 0xfffefff1, 0x8a8000, 40
    ActorWalkRoute 7, 730, 138, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 7, Movement_05A8
    VMJump L_0394

L_033E:
    WorkCmpConst 0x8021, 723
    VMJumpIf 1, L_035E
    WorkCmpConst 0x8021, 724
    VMJumpIf 1, L_035E
    VMJump L_0394

L_035E:
    EvCameraMoveTo 9688, 0, 0xed000, 0x2d48000, 0, 0x918000, 40
    ActorWalkRoute 7, 724, 144, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 7, Movement_0598
    VMJump L_0394

L_0394:
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 9, 7, 0, 0
    MsgWinCloseAll
    ActorCmdExec 7, Movement_05D8
    ActorCmdWait
    EvCameraReturn 30
    WorkCmpConst 0x8021, 727
    VMJumpIf 1, L_03C7
    VMJump L_03DB

L_03C7:
    ActorWalkRoute 7, 737, 138, 1, 8, 0
    VMJump L_040F

L_03DB:
    WorkCmpConst 0x8021, 723
    VMJumpIf 1, L_03FB
    WorkCmpConst 0x8021, 724
    VMJumpIf 1, L_03FB
    VMJump L_040F

L_03FB:
    ActorWalkRoute 7, 724, 150, 1, 8, 1
    VMJump L_040F

L_040F:
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdWait
    ActorDelete 7
    BGMChangeMap
    MapReplaceSetEvent 5, 1, 1
    MapReplaceSetEvent 6, 0, 0
    FlagSet 811
    FlagSet 368
    WorkSetConst 0x4044, 1
    WorkSetConst 0x4106, 1
    WorkSetConst 0x40e3, 2
    Cmd_0262 1, 29
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 639, 0
    ScreamMsg 0, 1
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    VMStackPushFlag 329
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_049F
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8023, 1
    CallWildBattle 639, 45, 0x8023
    WorkSetConst 0x8023, 0
    VMJump L_04B9

L_049F:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8024, 1
    CallWildBattle 639, 65, 0x8024
    WorkSetConst 0x8024, 0

L_04B9:
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04E0
    FlagSet 810
    ActorDelete 6
    CallWildBattleEnd
    VMJump L_04E2

L_04E0:
    CallWildLose

L_04E2:
    WildBattleGetResult 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_04F9
    VMJump L_0503

L_04F9:
    FlagSet 330
    VMJump L_0529

L_0503:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0523
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0523
    VMJump L_0529

L_0523:
    VMJump L_0529

L_0529:
    VMStackPushFlag 330
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0546
    SystemMsg 1, 2
    MsgWaitAdvance
    InfoMsgClose

L_0546:
    FlagSet 329
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0550:
    Move 75, 1
    MoveEnd

Movement_0558:
    Move 35, 1
    MoveEnd

Movement_0560:
    Move 34, 1
    MoveEnd

Movement_0568:
    Move 32, 1
    MoveEnd

Movement_0570:
    Move 33, 1
    MoveEnd
    Move 13, 1
    MoveEnd

Movement_0580:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd

Movement_0590:
    Move 14, 1
    MoveEnd

Movement_0598:
    Move 9, 1
    MoveEnd
    Move 8, 1
    MoveEnd

Movement_05A8:
    Move 11, 1
    MoveEnd
    Move 10, 1
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

Movement_05D8:
    Move 100, 1
    MoveEnd
    Move 13, 3
    Move 9, 1
    MoveEnd

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 10, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
