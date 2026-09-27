#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd

Script_2:
    ActorsPauseAll
    Cmd_0187 0
    FadeInBlack
    Cmd_018E 0
    FadeWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    ActorNew 7, 4, 1, 251, 227, 0
    Cmd_0187 1
    FadeInBlack
    FadeWait
    Cmd_018E 2
    WorkSetConst 0x4000, 1
    ActorCmdExec 251, Movement_01A0
    VMSleep 20
    ActorCmdExec 255, Movement_01A8
    ActorCmdWait
    ActorMsg 1024, 0, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0168
    VMSleep 20
    ActorCmdExec 255, Movement_0198
    ActorCmdWait
    ActorDelete 251
    WorkSetConst 0x40c3, 4
    FlagReset 717
    ObjInitPointGPos 2, 31, 0, 0
    Cmd_0262 1, 11
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    PlayerGetDir 0x8010
    DebugPrint 0x4000
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4000
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0105
    SEPlay 1351
    WordSetPlayerName 0
    SEPlay 1740
    InfoMsg 2, 2
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    FadeOutBlack
    Cmd_018E 1
    FadeWait
    RTReserveScript 2
    MapChangeCore 97, 12, 0, 87, 0

L_0105:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    TrainerCardHasBadge 0x8008, 4
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_013B
    InfoMsg 3, 2
    VMJump L_0140

L_013B:
    InfoMsg 4, 2

L_0140:
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0168:
    Move 13, 10
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
    Move 32, 1
    MoveEnd

Movement_0198:
    Move 33, 1
    MoveEnd

Movement_01A0:
    Move 34, 1
    MoveEnd

Movement_01A8:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
