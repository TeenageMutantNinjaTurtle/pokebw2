#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 0, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    VMStackPushFlag 296
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0051
    VMCall Script_4
    VMJump L_0067

L_0051:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 5, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0067:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    VMStackPushFlag 296
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_008E
    VMCall Script_4
    VMJump L_00A4

L_008E:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 6, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00A4:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    SEPlay 1351
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_00C5
    VMJump L_00D3

L_00C5:
    ActorCmdExec 2, Movement_01D8
    VMJump L_00F4

L_00D3:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_00E6
    VMJump L_00F4

L_00E6:
    ActorCmdExec 2, Movement_01E0
    VMJump L_00F4

L_00F4:
    ActorCmdWait
    ActorMsg 1024, 1, 2, 5, 0
    MsgWinCloseAll
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0117
    VMJump L_0125

L_0117:
    ActorCmdExec 1, Movement_01D8
    VMJump L_0146

L_0125:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0138
    VMJump L_0146

L_0138:
    ActorCmdExec 1, Movement_01E0
    VMJump L_0146

L_0146:
    ActorCmdWait
    ActorMsg 1024, 2, 1, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 2, 5, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 92
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 4, 1, 3, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 581
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 5, 2, 5, 0
    ABKeyWait
    MsgWinCloseAll
    ActorMsg 1024, 6, 1, 3, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 296
    VMReturn

Movement_01D8:
    Move 35, 1
    MoveEnd

Movement_01E0:
    Move 34, 1
    MoveEnd
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
