#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntry Script_9
    ScriptEntry Script_10
    ScriptEntry Script_11
    ScriptEntry Script_12
    ScriptEntry Script_13
    ScriptEntriesEnd

Script_8:
    VMHalt

Script_9:
    VMStackPush 0x4071
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0093
    ActorSetGPos 3, 26, 0, 65, 1
    ActorSetGPos 13, 24, 0, 62, 1
    ActorSetGPos 4, 28, 0, 69, 2
    ActorSetGPos 5, 28, 0, 70, 2
    ActorSetGPos 0, 25, 0, 65, 0
    ActorSetGPos 1, 27, 0, 65, 0

L_0093:
    VMHalt

Script_1:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 6, Movement_06DC
    ActorCmdWait
    ActorMsg 1024, 0, 6, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 255, 25, 70, 1, 8, 0
    ActorCmdExec 6, Movement_06E4
    ActorCmdWait
    ActorCmdExec 255, Movement_06EC
    ActorCmdWait
    ActorMsg 1024, 1, 6, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_06D4
    ActorCmdExec 6, Movement_06D4
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x1a8000, 0, 0x428000, 40
    ActorCmdExec 6, Movement_06D4
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 2, 2, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 4, 3, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 40
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 6, Movement_04A4
    ActorCmdWait
    ActorMsg 1024, 4, 6, 6, 0
    MsgWinCloseAll
    ActorWalkRoute 6, 26, 69, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 5, 6, 6, 1
    ActorMsgClose
    ActorCmdExec 4, Movement_06F4
    ActorCmdExec 7, Movement_06FC
    ActorCmdExec 8, Movement_06FC
    ActorCmdExec 12, Movement_06FC
    ActorCmdExec 5, Movement_06F4
    ActorCmdExec 2, Movement_054C
    ActorCmdExec 0, Movement_0540
    ActorCmdExec 1, Movement_0540
    ActorCmdWait
    ActorMsg 1024, 6, 6, 6, 0
    MsgWinCloseAll
    InfoMsg 7, 1
    MsgWinCloseAll
    ActorMsg 1024, 8, 6, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 6, 6, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_06FC
    VMSleep 8
    ActorCmdExec 0, Movement_06FC
    ActorCmdExec 1, Movement_06FC
    ActorCmdWait
    ActorMsg 1024, 10, 6, 6, 0
    MsgWinCloseAll
    InfoMsg 11, 1
    MsgWinCloseAll
    ActorWalkRoute 4, 28, 69, 1, 8, 0
    ActorWalkRoute 5, 28, 70, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 4, Movement_06E4
    ActorCmdExec 5, Movement_06E4
    ActorCmdWait
    ActorCmdExec 6, Movement_06EC
    ActorCmdExec 255, Movement_06EC
    ActorCmdWait
    ActorMsg 1024, 12, 6, 5, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_06EC
    ActorWalkRoute 255, 26, 70, 1, 8, 0
    ActorCmdWait
    ActorWalkRoute 4, 27, 69, 1, 8, 0
    VMSleep 4
    ActorWalkRoute 5, 27, 70, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 13, 5, 6, 0
    MsgWinCloseAll
    CallTrainerBattle 724, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02EC
    FlagReset 882
    ActorAdd 3
    ActorAdd 13
    CallTrainerBattleEnd
    VMJump L_02EE

L_02EC:
    CallTrainerLose

L_02EE:
    ActorCmdExec 4, Movement_0530
    VMSleep 4
    ActorCmdExec 5, Movement_0530
    ActorCmdWait
    ActorCmdExec 2, Movement_0500
    VMSleep 24
    ActorCmdExec 6, Movement_06E4
    ActorCmdExec 255, Movement_06E4
    ActorCmdWait
    ActorCmdExec 2, Movement_06EC
    ActorCmdWait
    ActorMsg 1024, 14, 2, 3, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 29
    WorkSet 0x8001, 3
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 2, Movement_0514
    ActorCmdWait
    ActorCmdExec 2, Movement_06EC
    ActorCmdWait
    ActorMsg 1024, 15, 2, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 16, 6, 5, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_06D4
    ActorCmdExec 255, Movement_06D4
    ActorCmdWait
    ActorMsg 1024, 17, 6, 5, 0
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x1a8000, 0, 0x428000, 40
    ActorCmdExec 3, Movement_04B0
    ActorCmdExec 13, Movement_04D8
    ActorCmdWait
    EvCameraWait
    ActorCmdExec 2, Movement_0520
    ActorWalkRoute 0, 25, 65, 1, 8, 1
    ActorWalkRoute 1, 27, 65, 1, 8, 1
    ActorCmdWait
    ActorMsg 1024, 18, 2, 3, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_06DC
    ActorCmdWait
    ActorMsg 1024, 19, 2, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 20, 6, 5, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_0558
    ActorCmdExec 2, Movement_06D4
    ActorCmdWait
    ActorMsg 1024, 21, 2, 3, 0
    MsgWaitAdvance
    MsgWinCloseAll
    EvCameraMoveToDefault 40
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorDelete 6
    FlagSet 884
    WorkSetConst 0x4071, 1
    WorkSetConst 0x4072, 1
    FlagSet 975
    Cmd_0262 0, 6
    Cmd_0262 1, 35
    Cmd_0262 2, 9
    Cmd_0262 3, 7
    Cmd_0262 4, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04A4:
    Move 1, 1
    Move 100, 1
    MoveEnd

Movement_04B0:
    Move 71, 1
    Move 17, 1
    Move 73, 1
    Move 17, 1
    Move 74, 1
    Move 72, 1
    Move 13, 2
    Move 14, 6
    Move 13, 4
    MoveEnd

Movement_04D8:
    Move 71, 1
    Move 17, 1
    Move 73, 1
    Move 17, 1
    Move 74, 1
    Move 72, 1
    Move 13, 2
    Move 14, 9
    Move 13, 1
    MoveEnd

Movement_0500:
    Move 13, 2
    Move 14, 1
    Move 13, 2
    Move 35, 0
    MoveEnd

Movement_0514:
    Move 12, 1
    Move 35, 0
    MoveEnd

Movement_0520:
    Move 12, 2
    Move 15, 1
    Move 12, 1
    MoveEnd

Movement_0530:
    Move 71, 1
    Move 11, 1
    Move 72, 1
    MoveEnd

Movement_0540:
    Move 33, 1
    Move 75, 1
    MoveEnd

Movement_054C:
    Move 33, 1
    Move 159, 1
    MoveEnd

Movement_0558:
    Move 16, 1
    Move 19, 2
    Move 16, 5
    Move 19, 4
    Move 16, 2
    Move 71, 1
    Move 16, 1
    Move 73, 1
    Move 16, 3
    Move 74, 1
    Move 72, 1
    MoveEnd

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 30, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 27, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
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

Movement_06D4:
    Move 32, 1
    MoveEnd

Movement_06DC:
    Move 33, 1
    MoveEnd

Movement_06E4:
    Move 34, 1
    MoveEnd

Movement_06EC:
    Move 35, 1
    MoveEnd

Movement_06F4:
    Move 75, 1
    MoveEnd

Movement_06FC:
    Move 159, 1
    MoveEnd
