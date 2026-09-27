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
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0085
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    ActorCmdExec 8, Movement_037C
    FadeWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 956
    FlagReset 950
    RTReserveScript 7
    MapChangeCore 506, 16, 0, 7, 1
    VMJump L_0093

L_0085:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0093:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0100
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    ActorCmdExec 13, Movement_037C
    FadeWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 957
    FlagReset 949
    RTReserveScript 7
    MapChangeCore 506, 24, 0, 14, 2
    VMJump L_010E

L_0100:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_010E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0197
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 2
    ActorCmdExec 9, Movement_0394
    FadeExWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 952
    FlagReset 953
    ActorDelete 9
    ActorAdd 12
    ActorSetGPos 255, 26, 0, 73, 2
    VMSleep 60
    FadeEx 3, 16, 0, 2
    FadeExWait
    VMJump L_01A5

L_0197:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01A5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_022E
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 2
    ActorCmdExec 12, Movement_0394
    FadeExWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 953
    FlagReset 952
    ActorDelete 12
    ActorAdd 9
    ActorSetGPos 255, 58, 0, 90, 2
    VMSleep 60
    FadeEx 3, 16, 0, 2
    FadeExWait
    VMJump L_023C

L_022E:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_023C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02C5
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 2
    ActorCmdExec 10, Movement_037C
    FadeExWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 954
    FlagReset 955
    ActorDelete 10
    ActorAdd 11
    ActorSetGPos 255, 26, 0, 48, 2
    VMSleep 60
    FadeEx 3, 16, 0, 2
    FadeExWait
    VMJump L_02D3

L_02C5:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02D3:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_035C
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 2
    ActorCmdExec 11, Movement_0394
    FadeExWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 955
    FlagReset 954
    ActorDelete 11
    ActorAdd 10
    ActorSetGPos 255, 47, 0, 88, 1
    VMSleep 60
    FadeEx 3, 16, 0, 2
    FadeExWait
    VMJump L_036A

L_035C:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_036A:
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

Movement_037C:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_0394:
    Move 35, 1
    MoveEnd
