#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd

Script_2:
    ActorsPauseAll
    VMStackPush 0x40b1
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0150
    SEPlay 1351
    ActorSetEyeToEye
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 6917, 0, 0xcc000, 0x178000, 0, 0x308000, 40
    EvCameraWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorNew 20, 56, 0, 251, 355, 0
    InfoMsg 1, 2
    MsgWinCloseAll
    ActorWalkRoute 251, 21, 48, 0, 8, 1
    ActorCmdExec 0, Movement_0288
    ActorCmdExec 255, Movement_0210
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 251, 0, 0
    ActorMsg 1024, 4, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0270
    ActorCmdWait
    ActorMsg 1024, 5, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0288
    ActorCmdWait
    ActorMsg 1024, 6, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0220
    VMSleep 6
    ActorCmdExec 0, Movement_0270
    ActorCmdExec 255, Movement_0270
    ActorCmdWait
    ActorDelete 251
    ActorCmdExec 0, Movement_0278
    ActorCmdExec 255, Movement_0280
    ActorCmdWait
    ActorMsg 1024, 7, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    EvCameraMoveToDefault 40
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    WorkSetConst 0x40b1, 1
    FlagReset 751
    VMJump L_0164

L_0150:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose

L_0164:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 13, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0210:
    Move 75, 1
    Move 63, 1
    Move 34, 1
    MoveEnd

Movement_0220:
    Move 17, 8
    MoveEnd
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
    Move 32, 1
    MoveEnd

Movement_0270:
    Move 33, 1
    MoveEnd

Movement_0278:
    Move 34, 1
    MoveEnd

Movement_0280:
    Move 35, 1
    MoveEnd

Movement_0288:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
