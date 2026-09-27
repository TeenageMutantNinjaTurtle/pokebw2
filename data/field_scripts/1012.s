#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    MsgWaitAdvance
    PokePartyHasMoveAny 0x8020, 249
    VMStackPush 0x8020
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_0065
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_01C6

L_0065:
    MsgWinCloseAll
    ActorCmdExec 8, Movement_022C
    ActorCmdWait
    ParentActorMsg 1024, 6, 0, 0
    MsgWinCloseAll
    ActorCmdExec 8, Movement_01D4
    VMSleep 5
    ActorCmdExec 7, Movement_01D4
    ActorCmdExec 6, Movement_01D4
    VMSleep 10
    FadeEx 3, 0, 16, 2
    FadeExWait
    ActorCmdWait
    ActorDelete 9
    ActorDelete 10
    ActorDelete 11
    ActorDelete 12
    ActorDelete 13
    ActorDelete 14
    ActorDelete 15
    ActorDelete 19
    ActorDelete 20
    ActorDelete 21
    VMSleep 60
    FadeEx 3, 16, 0, 2
    FadeExWait
    ActorCmdExec 8, Movement_01CC
    VMSleep 5
    ActorCmdExec 7, Movement_01CC
    VMSleep 5
    ActorCmdExec 6, Movement_01CC
    ActorCmdWait
    ParentActorMsg 1024, 7, 1, 0
    MsgWinCloseAll
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0128
    VMJump L_014A

L_0128:
    ActorCmdExec 8, Movement_01E0
    VMSleep 12
    ActorCmdExec 6, Movement_01F8
    ActorCmdExec 7, Movement_01E8
    VMJump L_01B4

L_014A:
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_015D
    VMJump L_017F

L_015D:
    ActorCmdExec 8, Movement_0204
    ActorCmdExec 6, Movement_021C
    VMSleep 12
    ActorCmdExec 7, Movement_0210
    VMJump L_01B4

L_017F:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0192
    VMJump L_01B4

L_0192:
    ActorCmdExec 8, Movement_01E0
    VMSleep 12
    ActorCmdExec 6, Movement_01F8
    ActorCmdExec 7, Movement_01E8
    VMJump L_01B4

L_01B4:
    ActorCmdWait
    ActorDelete 8
    ActorDelete 7
    ActorDelete 6
    FlagSet 958

L_01C6:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_01CC:
    Move 50, 2
    MoveEnd

Movement_01D4:
    Move 50, 1
    Move 42, 20
    MoveEnd

Movement_01E0:
    Move 13, 10
    MoveEnd

Movement_01E8:
    Move 13, 1
    Move 15, 1
    Move 13, 10
    MoveEnd

Movement_01F8:
    Move 15, 1
    Move 13, 10
    MoveEnd

Movement_0204:
    Move 15, 1
    Move 13, 10
    MoveEnd

Movement_0210:
    Move 15, 2
    Move 13, 10
    MoveEnd

Movement_021C:
    Move 12, 1
    Move 15, 2
    Move 13, 10
    MoveEnd

Movement_022C:
    Move 75, 1
    MoveEnd

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02CF
    ParentActorMsg 1024, 2, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    ActorCmdExec 16, Movement_0400
    FadeWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 948
    FlagReset 951
    RTReserveScript 2
    MapChangeCore 507, 27, 0, 14, 2
    VMJump L_02DD

L_02CF:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02DD:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_034A
    ParentActorMsg 1024, 2, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    ActorCmdExec 18, Movement_03E8
    FadeWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 950
    FlagReset 956
    RTReserveScript 7
    MapChangeCore 508, 19, 0, 35, 1
    VMJump L_0358

L_034A:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0358:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03C5
    ParentActorMsg 1024, 2, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    ActorCmdExec 17, Movement_0400
    FadeWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 949
    FlagReset 957
    RTReserveScript 7
    MapChangeCore 508, 56, 0, 84, 1
    VMJump L_03D3

L_03C5:
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_03D3:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_03E8:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_0400:
    Move 35, 1
    MoveEnd
