#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
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
    VMJumpIf 255, L_0071
    ParentActorMsg 1024, 1, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    ActorCmdExec 7, Movement_00AC
    FadeWait
    ActorCmdWait
    SEPlay 2225
    SEWait
    FlagSet 951
    FlagReset 948
    RTReserveScript 7
    MapChangeCore 506, 27, 0, 38, 2
    VMJump L_007F

L_0071:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_007F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_00AC:
    Move 35, 1
    MoveEnd
