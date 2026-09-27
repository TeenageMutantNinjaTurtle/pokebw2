#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 1, 0, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    ActorMsg 1024, 2, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0248
    ActorCmdWait
    ActorCmdExec 1, Movement_0260
    ActorCmdWait
    PlayerGetGPos 0x8020, 0x8021
    WorkSub 0x8021, 1
    ActorWalkRoute 1, 0x8020, 0x8021, 1, 8, 0
    ActorCmdWait
    VMStackPush 0x8020
    VMStackPushConst 22
    VMStackCmp 5
    VMJumpIf 255, L_0089

L_0089:
    ActorMsg 1024, 3, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0240
    ActorCmdWait
    VMSleep 20
    ActorMsgVersioned 1024, 5, 4, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0248
    ActorCmdWait
    ActorMsgVersioned 1024, 7, 6, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0260
    ActorCmdWait
    ActorMsgVersioned 1024, 9, 8, 1, 0, 0
    ActorMsg 1024, 10, 1, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 54
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 11, 1, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8021, 51
    VMStackPush 0x8020
    VMStackPushConst 21
    VMStackCmp 5
    VMJumpIf 255, L_0150
    ActorWalkRoute 1, 21, 0x8021, 2, 8, 0
    VMJump L_0168

L_0150:
    ActorCmdExec 1, Movement_0210
    ActorCmdWait
    ActorWalkRoute 1, 22, 0x8021, 2, 8, 1

L_0168:
    WorkCmpConst 0x8020, 20
    VMJumpIf 1, L_017B
    VMJump L_0185

L_017B:
    VMSleep 24
    VMJump L_01DC

L_0185:
    WorkCmpConst 0x8020, 21
    VMJumpIf 1, L_0198
    VMJump L_01A2

L_0198:
    VMSleep 18
    VMJump L_01DC

L_01A2:
    WorkCmpConst 0x8020, 22
    VMJumpIf 1, L_01B5
    VMJump L_01BF

L_01B5:
    VMSleep 24
    VMJump L_01DC

L_01BF:
    WorkCmpConst 0x8020, 23
    VMJumpIf 1, L_01D2
    VMJump L_01DC

L_01D2:
    VMSleep 30
    VMJump L_01DC

L_01DC:
    ActorCmdExec 255, Movement_0248
    ActorCmdWait
    SEPlay 1369
    ActorDelete 1
    SEWait
    FlagSet 1012
    WorkSetConst 0x4148, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0210:
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

Movement_0240:
    Move 32, 1
    MoveEnd

Movement_0248:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_0260:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 161, 1
    MoveEnd
    Move 160, 1
    MoveEnd
