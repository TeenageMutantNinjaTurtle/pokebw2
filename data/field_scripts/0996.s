#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPushFlag 2781
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0035
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_003B

L_0035:
    VMCall L_0041

L_003B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0041:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0168
    ActorCmdWait
    VMSleep 30
    Random 0x8010, 100
    DebugPrint 0x8010
    VMStackPush 0x8010
    VMStackPushConst 89
    VMStackCmp 4
    VMJumpIf 255, L_00C8
    ActorCmdExec 0, Movement_0160
    ActorCmdWait
    VMSleep 15
    ActorCmdExec 0, Movement_0158
    ActorCmdWait
    ParentActorMsg 1024, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 23
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0143

L_00C8:
    VMStackPush 0x8010
    VMStackPushConst 59
    VMStackCmp 4
    VMJumpIf 255, L_0117
    ActorCmdExec 0, Movement_0158
    ActorCmdWait
    ParentActorMsg 1024, 2, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 27
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0143

L_0117:
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 18
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000

L_0143:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2781
    VMReturn
    .balign 4, 0

Movement_0158:
    Move 75, 1
    MoveEnd

Movement_0160:
    Move 159, 1
    MoveEnd

Movement_0168:
    Move 161, 1
    MoveEnd
    Move 160, 1
    MoveEnd
