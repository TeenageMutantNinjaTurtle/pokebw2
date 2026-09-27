#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 4, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_005B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 489
    VMJump L_0152

L_005B:
    SEPlay 1351
    ActorSetEyeToEye
    PlayerGetDir 0x8010
    WordSetPlayerName 0
    ParentActorMsg 1024, 1, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0288
    VMSleep 10
    ActorCmdExec 255, Movement_02D0
    ActorCmdWait
    ParentActorMsg 1024, 2, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_00AD
    VMJump L_00BB

L_00AD:
    ActorCmdExec 0, Movement_0254
    VMJump L_00DC

L_00BB:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_00CE
    VMJump L_00DC

L_00CE:
    ActorCmdExec 0, Movement_0260
    VMJump L_00DC

L_00DC:
    ActorCmdWait
    ParentActorMsg 1024, 3, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_02B0
    ActorCmdWait
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0107
    VMJump L_0117

L_0107:
    ActorJumpToGPos 0, 143, 0, 206
    VMJump L_013A

L_0117:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_012A
    VMJump L_013A

L_012A:
    ActorJumpToGPos 0, 141, 0, 206
    VMJump L_013A

L_013A:
    ActorCmdExec 0, Movement_026C
    ActorCmdWait
    ActorDelete 0
    FlagSet 668
    WorkSetConst 0x413b, 1

L_0152:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01AD
    ActorCmdExec 0, Movement_02E8
    ActorCmdWait
    ActorCmdExec 0, Movement_02B0
    ActorCmdExec 255, Movement_02C8
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0298
    ActorCmdWait
    FlagSet 489
    VMJump L_024E

L_01AD:
    ActorCmdExec 0, Movement_02E8
    ActorCmdWait
    ActorCmdExec 0, Movement_02B0
    ActorCmdExec 255, Movement_02C8
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 1, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0274
    VMSleep 10
    ActorCmdExec 255, Movement_02E0
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_02D8
    ActorCmdWait
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_02B0
    ActorCmdWait
    ActorJumpToGPos 0, 143, 0, 206
    ActorCmdExec 255, Movement_02B0
    ActorCmdExec 0, Movement_026C
    ActorCmdWait
    ActorDelete 0
    FlagSet 668
    WorkSetConst 0x413b, 1

L_024E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0254:
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_0260:
    Move 14, 1
    Move 32, 1
    MoveEnd

Movement_026C:
    Move 13, 8
    MoveEnd

Movement_0274:
    Move 15, 1
    Move 13, 1
    MoveEnd
    Move 13, 1
    MoveEnd

Movement_0288:
    Move 9, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0298:
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd

Movement_02B0:
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0
    Move 3, 1
    MoveEnd

Movement_02C8:
    Move 32, 1
    MoveEnd

Movement_02D0:
    Move 33, 1
    MoveEnd

Movement_02D8:
    Move 34, 1
    MoveEnd

Movement_02E0:
    Move 35, 1
    MoveEnd

Movement_02E8:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
