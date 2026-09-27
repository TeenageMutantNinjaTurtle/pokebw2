#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

L_003A:
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0061
    ObjInitWarpGPos 2, 9, 0, 11
    VMJump L_006B

L_0061:
    ObjInitWarpGPos 1, 9, 0, 11

L_006B:
    VMReturn

Script_5:
    VMCall L_003A
    VMHalt

Script_8:
    VMCall L_003A
    VMHalt

Script_6:
    VMHalt

Script_1:
    ActorsPauseAll
    Cmd_017A 36
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FlagReset 814
    SEPlay 1369
    ActorAdd 2
    SEWait
    BGMPlay 1088
    TrainerCardGetSex 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00C1
    InfoMsg 0, 2
    VMJump L_00C6

L_00C1:
    InfoMsg 1, 2

L_00C6:
    MsgWinCloseAll
    PlayerGetGPos 0x8022, 0x8023
    WorkAdd 0x8023, 1
    ActorWalkRoute 2, 0x8022, 0x8023, 1, 8, 0
    VMSleep 8
    ActorCmdExec 255, Movement_0368
    ActorCmdWait
    ActorMsg 1024, 2, 2, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 471
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 3, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0340
    ActorCmdWait
    ActorMsg 1024, 4, 2, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 2, 5, 14, 1, 8, 0
    ActorCmdWait
    SEPlay 1369
    ActorDelete 2
    SEWait
    BGMChangeMap
    FlagSet 814
    WorkSetConst 0x40ed, 1
    MedalDiscover 60
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 5, 6, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40e2
    VMStackPushConst 6
    VMStackCmp 5
    VMJumpIf 255, L_031F
    ParentActorMsg 1024, 8, 0, 0
    VMStackPush 0x40e2
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_022E
    ParentActorMsg 1024, 13, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 50
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40e2, 6
    VMJump L_0319

L_022E:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0

L_023A:
    VMStackPush 0x8025
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0304
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 312
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0288
    ActorMsg 1024, 9, 3, 0, 0
    WorkAdd 0x8024, 1
    VMJump L_02F8

L_0288:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 313
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02C3
    ActorMsg 1024, 10, 3, 0, 0
    WorkAdd 0x8024, 1
    VMJump L_02F8

L_02C3:
    VMStackPush 0x8025
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPushFlag 314
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02F8
    ActorMsg 1024, 11, 3, 0, 0
    WorkAdd 0x8024, 1

L_02F8:
    WorkAdd 0x8025, 1
    VMJump L_023A

L_0304:
    WordSetNumber 0, 0x8024, 1
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0319:
    VMJump L_032D

L_031F:
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_032D:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0340:
    Move 13, 1
    Move 75, 1
    Move 32, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 32, 1
    MoveEnd

Movement_0368:
    Move 33, 1
    MoveEnd
