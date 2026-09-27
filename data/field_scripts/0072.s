#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_4:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    CallPlaceNameDisp
    ActorCmdExec 255, Movement_01AC
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 446
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00B2
    VMStackPushFlag 248
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_009E
    FlagSet 248
    ParentActorMsg 1024, 2, 0, 0

L_009E:
    ParentActorMsg 1024, 3, 0, 0
    YesNoWin 0x8010
    VMJump L_00C0

L_00B2:
    ParentActorMsg 1024, 6, 0, 0
    YesNoWin 0x8010

L_00C0:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_010D
    ParentActorMsg 1024, 4, 0, 0
    MsgWinCloseAll
    VMCall L_0129
    RTReserveScript 11
    FlagSet 446
    FadeOutBlackQ
    FadeWait
    FieldClose
    Call3DDemo 10, 0
    FieldOpen
    MapChangeCore 235, 295, 1, 748, 3
    VMJump L_0123

L_010D:
    ParentActorMsg 1024, 5, 0, 0
    ActorMsgClose
    ActorCmdExec 1, Movement_01A4
    ActorCmdWait

L_0123:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0129:
    WorkSetConst 0x8020, 0
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_014A
    PlayerSetSpecialSequence 1

L_014A:
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_016F
    ActorCmdExec 255, Movement_01B4
    VMJump L_0198

L_016F:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0190
    ActorCmdExec 255, Movement_01C4
    VMJump L_0198

L_0190:
    ActorCmdExec 255, Movement_01D0

L_0198:
    ActorCmdWait
    WorkSetConst 0x8020, 0
    VMReturn
    .balign 4, 0

Movement_01A4:
    Move 34, 1
    MoveEnd

Movement_01AC:
    Move 15, 1
    MoveEnd

Movement_01B4:
    Move 15, 1
    Move 13, 3
    Move 14, 1
    MoveEnd

Movement_01C4:
    Move 13, 2
    Move 14, 1
    MoveEnd

Movement_01D0:
    Move 13, 1
    Move 14, 1
    MoveEnd
