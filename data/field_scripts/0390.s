#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    VMStackPush 0x40d2
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f0
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0070
    VMStackPushFlag 788
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_006A
    FlagSet 788

L_006A:
    VMJump L_0089

L_0070:
    VMStackPush 0x40d2
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0089
    Cmd_0262 3, 2

L_0089:
    VMHalt

Script_2:
    VMStackPush 0x40d2
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00AA
    ActorSetGPos 13, 11, 0, 48, 3

L_00AA:
    VMHalt

Script_3:
    ActorsPauseAll
    ActorCmdExec 13, Movement_0270
    ActorCmdWait
    ActorMsgGendered 1024, 0, 1, 13, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 11
    VMStackCmp 1
    VMJumpIf 255, L_00FD
    WorkSub 0x8022, 1
    ActorWalkRoute 13, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    VMJump L_011D

L_00FD:
    WorkSub 0x8022, 1
    ActorWalkRoute 13, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 13, Movement_024C
    ActorCmdWait

L_011D:
    WordSetPlayerName 0
    ActorMsg 1024, 2, 13, 0, 0
    MsgWinCloseAll
    ActorCmdExec 13, Movement_0254
    ActorCmdWait
    VMSleep 8
    ActorCmdExec 13, Movement_024C
    ActorCmdWait
    ActorMsg 1024, 3, 13, 0, 0
    MsgWinCloseAll
    ActorCmdExec 13, Movement_0268
    ActorCmdWait
    ActorMsg 1024, 4, 13, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 13, 14, 45, 1, 8, 1
    ActorCmdWait
    ActorWalkRoute 13, 15, 40, 1, 8, 0
    ActorCmdWait
    WorkSetConst 0x40d2, 1
    VMStackPush 0x40f0
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_01B3
    ActorDelete 13
    FlagSet 788
    VMJump L_01BF

L_01B3:
    ActorSetGPos 13, 37, 0, 37, 3

L_01BF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    ActorMsg 1024, 8, 11, 0, 0
    ActorMsg 1024, 9, 11, 0, 0
    MsgWinCloseAll
    SEPlay 1369
    ActorDelete 11
    SEWait
    FlagSet 789
    WorkSetConst 0x40d3, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 35, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 32, 1
    MoveEnd

Movement_024C:
    Move 33, 1
    MoveEnd

Movement_0254:
    Move 61, 1
    Move 35, 1
    Move 34, 1
    Move 61, 1
    MoveEnd

Movement_0268:
    Move 75, 1
    MoveEnd

Movement_0270:
    Move 33, 1
    Move 75, 1
    MoveEnd

Script_7:
    ActorsPauseAll
    VMStackPushFlag 2448
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02FC
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    SEPlay 1908
    GameGetVersion 0x8010
    VMStackPush 0x8010
    VMStackPushConst 22
    VMStackCmp 1
    VMJumpIf 255, L_02D1
    Cmd_0275 0, 18, 0
    SystemMsg 12, 0
    VMJump L_02DE

L_02D1:
    Cmd_0275 0, 17, 0
    SystemMsg 11, 0

L_02DE:
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2448
    VMJump L_0310

L_02FC:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose

L_0310:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
