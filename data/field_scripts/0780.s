#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_3:
    VMHalt

Script_4:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x68000, 0, 0x58000, 40
    EvCameraWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0288
    ActorCmdWait
    ActorCmdExec 0, Movement_02A0
    ActorCmdWait
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    EvCameraReturn 30
    ActorWalkRoute 0, 6, 9, 0, 8, 1
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMSleep 16
    ActorCmdExec 0, Movement_02B0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsgGendered 1024, 2, 3, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00C6
    ActorMsg 1024, 4, 0, 0, 0
    VMJump L_00D2

L_00C6:
    ActorMsg 1024, 5, 0, 0, 0

L_00D2:
    ActorMsg 1024, 6, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 0, 6, 5, 0, 8, 1
    ActorCmdWait
    ActorCmdExec 0, Movement_0288
    ActorCmdWait
    WorkSetConst 0x407d, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x400a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0161
    ParentActorMsg 1024, 7, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 2
    FadeExWait
    PokePartyRecoverAll
    MEPlay 1300
    MEWait
    FadeEx 3, 16, 0, 2
    FadeExWait
    WorkSetConst 0x400a, 1
    VMCall L_016D
    VMJump L_0167

L_0161:
    VMCall L_016D

L_0167:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_016D:
    Random 0x8010, 100
    VMStackPush 0x8010
    VMStackPushConst 19
    VMStackCmp 3
    VMJumpIf 255, L_0196
    ParentActorMsg 1024, 8, 0, 0
    VMJump L_021C

L_0196:
    VMStackPush 0x8010
    VMStackPushConst 39
    VMStackCmp 3
    VMJumpIf 255, L_01B9
    ParentActorMsg 1024, 9, 0, 0
    VMJump L_021C

L_01B9:
    VMStackPush 0x8010
    VMStackPushConst 59
    VMStackCmp 3
    VMJumpIf 255, L_01DC
    ParentActorMsg 1024, 10, 0, 0
    VMJump L_021C

L_01DC:
    VMStackPush 0x8010
    VMStackPushConst 79
    VMStackCmp 3
    VMJumpIf 255, L_01FF
    ParentActorMsg 1024, 11, 0, 0
    VMJump L_021C

L_01FF:
    VMStackPush 0x8010
    VMStackPushConst 99
    VMStackCmp 3
    VMJumpIf 255, L_021C
    ParentActorMsg 1024, 12, 0, 0

L_021C:
    LastKeyWait
    MsgWinCloseAll
    DebugPrint 0x8010
    VMReturn

Script_2:
    ActorsPauseAll
    ActorSetGPos 0, 6, 0, 7, 1
    FadeInBlackQ_
    FadeWait
    WordSetPlayerName 0
    ActorMsg 1024, 13, 0, 0, 0
    FadeEx 3, 0, 16, 2
    FadeExWait
    ActorMsgClose
    MEPlay 1300
    MEWait
    PokePartyRecoverAll
    FadeEx 3, 16, 0, 2
    FadeExWait
    ActorMsg 1024, 14, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 32, 1
    MoveEnd

Movement_0288:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_02A0:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Movement_02B0:
    Move 161, 1
    MoveEnd
    Move 160, 1
    MoveEnd
