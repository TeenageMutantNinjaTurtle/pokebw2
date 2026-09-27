#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_4:
    VMHalt

Script_5:
    VMStackPush 0x40b2
    VMStackPushConst 1
    VMStackCmp 0
    VMJumpIf 255, L_0055
    ActorSetGPos 0, 11, 0xffff, 21, 3

L_0055:
    VMHalt

Script_1:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9467, 0, 0x123000, 0x81000, 0, 0xdb000, 40
    ActorWalkRoute 255, 8, 14, 0, 8, 1
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 0, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_03C8
    EvCameraMoveTo 9688, 4480, 0xed000, 0x114000, 0, 0x11a000, 50
    VMSleep 120
    EvCameraMoveTo 9467, 0, 0x123000, 0x81000, 0, 0xdb000, 40
    ActorCmdWait
    FlagReset 754
    ActorAdd 2
    ActorCmdExec 1, Movement_03C0
    ActorWalkRoute 2, 8, 15, 0, 4, 1
    ActorCmdWait
    ActorCmdExec 2, Movement_03B0
    ActorCmdExec 255, Movement_03B8
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 1, 2, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0143
    ActorMsg 1024, 2, 2, 0, 0
    VMJump L_014F

L_0143:
    ActorMsg 1024, 3, 2, 0, 0

L_014F:
    ActorMsg 1024, 4, 2, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 40
    ActorCmdExec 2, Movement_01C0
    VMSleep 16
    ActorCmdExec 1, Movement_03B8
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    SEPlay 1369
    ActorDelete 2
    SEWait
    ActorCmdExec 1, Movement_03C0
    ActorCmdExec 255, Movement_03C8
    ActorCmdWait
    ActorMsg 1024, 5, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40b2, 2
    FlagSet 754
    Cmd_0262 1, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_01C0:
    Move 17, 2
    Move 19, 2
    Move 17, 4
    Move 19, 9
    Move 16, 4
    Move 18, 1
    MoveEnd

Script_6:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 1, Movement_03D0
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    WorkSub 0x8022, 2
    ActorWalkRoute 1, 0x8021, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorMsg 1024, 6, 1, 0, 0
    ActorMsg 1024, 7, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40b2, 4
    FlagSet 752
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 1, Movement_03D0
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 1, 6, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 1, Movement_03C0
    ActorCmdWait
    ActorMsg 1024, 6, 1, 0, 0
    ActorMsg 1024, 7, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40b2, 4
    FlagSet 752
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    VMStackPush 0x40b2
    VMStackPushConst 3
    VMStackCmp 2
    VMJumpIf 255, L_02C3
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_02D7

L_02C3:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose

L_02D7:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    VMStackPush 0x40b2
    VMStackPushConst 1
    VMStackCmp 0
    VMJumpIf 255, L_0328
    SEPlay 1351
    ActorMsg 1024, 8, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0369

L_0328:
    VMStackPush 0x40b2
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0355
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0369

L_0355:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose

L_0369:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
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

Movement_03B0:
    Move 32, 1
    MoveEnd

Movement_03B8:
    Move 33, 1
    MoveEnd

Movement_03C0:
    Move 34, 1
    MoveEnd

Movement_03C8:
    Move 35, 1
    MoveEnd

Movement_03D0:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
