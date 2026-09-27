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
    FlagReset 2407
    FlagReset 2408
    FlagReset 2409
    FlagReset 2410
    VMStackPush 0x4109
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_004D
    ObjInitNPCGPos 1, 1, 32, 1, 46

L_004D:
    FlagSet 367
    VMHalt

Script_2:
    VMHalt

Script_3:
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 4, 1, 1, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 5, 0, 1, 0
    PlayerGetDir 0x8010
    VMStackPush 0x8010
    VMStackPushConst 3
    VMStackCmp 5
    VMJumpIf 255, L_00AC
    MsgWinCloseAll
    ActorCmdExec 0, Movement_01F0
    ActorCmdWait

L_00AC:
    ActorMsg 1024, 6, 0, 1, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_01E8
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    ActorCmdExec 1, Movement_01D8
    ActorCmdWait
    PlayerGetDir 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_00F9
    ActorCmdExec 255, Movement_01E0
    ActorCmdWait

L_00F9:
    VMStackPushFlag 366
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0128
    ActorMsg 1024, 0, 1, 5, 0
    FlagSet 366
    Cmd_0262 1, 39
    VMJump L_0134

L_0128:
    ActorMsg 1024, 1, 1, 5, 0

L_0134:
    YesNoWin 0x8010
    PlayerGetGPos 0x8008, 0x8009
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01B7
    ActorMsg 1024, 2, 1, 5, 0
    MsgWinCloseAll
    VMStackPush 0x8008
    VMStackPushConst 31
    VMStackCmp 1
    VMJumpIf 255, L_0180
    ActorCmdExec 1, Movement_0200
    VMJump L_01A9

L_0180:
    VMStackPush 0x8008
    VMStackPushConst 32
    VMStackCmp 1
    VMJumpIf 255, L_01A1
    ActorCmdExec 1, Movement_0210
    VMJump L_01A9

L_01A1:
    ActorCmdExec 1, Movement_0224

L_01A9:
    ActorCmdWait
    WorkSetConst 0x4109, 1
    VMJump L_01CF

L_01B7:
    ActorMsg 1024, 3, 1, 5, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0234
    ActorCmdWait

L_01CF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_01D8:
    Move 75, 1
    MoveEnd

Movement_01E0:
    Move 32, 1
    MoveEnd

Movement_01E8:
    Move 33, 1
    MoveEnd

Movement_01F0:
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_0200:
    Move 13, 2
    Move 15, 2
    Move 33, 1
    MoveEnd

Movement_0210:
    Move 14, 1
    Move 13, 2
    Move 14, 1
    Move 33, 1
    MoveEnd

Movement_0224:
    Move 13, 2
    Move 14, 2
    Move 33, 1
    MoveEnd

Movement_0234:
    Move 13, 1
    MoveEnd

Script_7:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 1055, 0, 0x150000, 0x208000, 0x4a6a0, 0x398000, 1
    EvCameraWait
    FadeInBlack
    EvCameraMoveTo 1055, 0, 0x150000, 0x208000, 0, 0x398000, 110
    CallPlaceNameDisp
    VMSleep 96
    FadeWait
    FadeEx 3, 0, 16, 4
    EvCameraWait
    FadeExWait
    EvCameraMoveTo 6563, 0, 0x160000, 0x208000, 0x186a0, 0x398000, 1
    EvCameraWait
    FadeEx 3, 16, 0, 4
    EvCameraMoveToDefault 60
    VMSleep 40
    ActorCmdExec 255, Movement_02D4
    EvCameraWait
    ActorCmdWait
    FadeExWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_02D4:
    Move 12, 3
    MoveEnd
