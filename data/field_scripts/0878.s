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
    ScriptEntry Script_14
    ScriptEntry Script_15
    ScriptEntry Script_16
    ScriptEntry Script_17
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_1:
    VMStackPush 0x40a5
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0083
    ObjInitNPCGPos 0, 1, 113, 2, 669
    VMJump L_00B2

L_0083:
    VMStackPush 0x40a5
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x40a5
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_00B2
    ObjInitNPCGPos 0, 3, 111, 2, 669

L_00B2:
    VMHalt

Script_2:
    VMHalt

Script_3:
    ActorsPauseAll
    ActorCmdExec 0, Movement_0134
    ActorCmdWait
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 695
    VMStackCmp 5
    VMJumpIf 255, L_00F5
    ActorWalkRoute 0, 110, 0x8023, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 0, Movement_071C
    ActorCmdWait

L_00F5:
    WordSetPlayerName 0
    ActorMsg 1024, 0, 0, 0, 0
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0140
    ActorCmdWait
    ActorSetGPos 0, 113, 2, 669, 1
    WorkSetConst 0x40a5, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_0134:
    Move 75, 1
    Move 34, 1
    MoveEnd

Movement_0140:
    Move 15, 3
    Move 12, 11
    MoveEnd

Script_4:
    ActorsPauseAll
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8022
    VMStackPushConst 113
    VMStackCmp 5
    VMJumpIf 255, L_0187
    WorkSub 0x8023, 1
    ActorWalkRoute 0, 0x8022, 0x8023, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_0714
    ActorCmdWait

L_0187:
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0734
    ActorCmdWait
    ActorMsg 1024, 3, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_072C
    ActorCmdWait
    ActorMsg 1024, 4, 0, 0, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01E3
    WordSetPokeSpecies 0, 501
    VMJump L_0206

L_01E3:
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0201
    WordSetPokeSpecies 0, 498
    VMJump L_0206

L_0201:
    WordSetPokeSpecies 0, 495

L_0206:
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x718000, 0x2001f, 0x29a5000, 40
    ActorCmdExec 0, Movement_027C
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 40
    ActorWalkRoute 0, 111, 669, 1, 8, 0
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 0, Movement_0724
    ActorCmdWait
    WorkSetConst 0x40a5, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_027C:
    Move 12, 2
    Move 35, 1
    MoveEnd

Script_5:
    ActorsPauseAll
    ActorCmdExec 0, Movement_072C
    ActorCmdWait
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 668
    VMStackCmp 1
    VMJumpIf 255, L_02C3
    ActorCmdExec 255, Movement_0714
    ActorCmdExec 0, Movement_070C
    VMJump L_02E6

L_02C3:
    VMStackPush 0x8023
    VMStackPushConst 670
    VMStackCmp 1
    VMJumpIf 255, L_02E6
    ActorCmdExec 255, Movement_070C
    ActorCmdExec 0, Movement_0714

L_02E6:
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_06DC
    VMSleep 8
    ActorCmdExec 0, Movement_0724
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0312:
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 107, 662, 1, 8, 0
    VMSleep 16
    ActorCmdExec 255, Movement_071C
    ActorCmdWait
    BMCreateHandleByGPos 0x8020, 1, 107, 661
    BMHndAudioVisualAnmPlay 0x8020, 0
    BMHndAnmWait 0x8020
    ActorCmdExec 0, Movement_06D4
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    BMHndAudioVisualAnmPlay 0x8020, 1
    BMHndAnmWait 0x8020
    BMReleaseHandle 0x8020
    WorkSetConst 0x40a5, 4
    FlagSet 731
    VMReturn

Script_6:
    ActorsPauseAll
    PlayerGetGPos 0x8022, 0x8023
    ActorWalkRoute 0, 0x8022, 669, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_070C
    ActorCmdWait
    VMCall L_0312
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    PlayerGetGPos 0x8022, 0x8023
    ActorWalkRoute 0, 0x8022, 668, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_0714
    ActorCmdWait
    VMCall L_0312
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    VMNop
    VMStackMul
    DebugPrint 12
    DebugStack 254
    VMNop

Script_17:
    ActorsPauseAll
    WordSetPlayerName 0
    ActorNew 113, 662, 0, 251, 249, 0
    WorkSetConst 0x8024, 0
    TrainerCardGetSex 0x8024
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0423
    InfoMsg 22, 2
    VMJump L_0428

L_0423:
    InfoMsg 23, 2

L_0428:
    MsgWinCloseAll
    WorkSetConst 0x8024, 0
    BGMPlay 1088
    ActorCmdExec 255, Movement_071C
    ActorCmdWait
    PlayerGetGPos 0x8022, 0x8023
    WorkSub 0x8022, 2
    ActorWalkRoute 251, 0x8022, 0x8023, 1, 8, 1
    ActorCmdWait
    ActorMsg 1024, 24, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_06DC
    ActorCmdWait
    SEPlay 2176
    SystemMsg 25, 0
    SEWait
    MsgWaitAdvance
    InfoMsgClose
    PokeDexEnableHabitatList
    ActorMsg 1024, 26, 251, 0, 0
    ActorMsg 1024, 27, 251, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04EE
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8025, 0

L_04BF:
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04E8
    ActorMsg 1024, 27, 251, 0, 0
    YesNoWin 0x8025
    VMJump L_04BF

L_04E8:
    WorkSetConst 0x8025, 0

L_04EE:
    MsgWinCloseAll
    ActorCmdExec 251, Movement_072C
    ActorCmdWait
    ActorMsg 1024, 28, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_070C
    ActorCmdWait
    VMSleep 16
    ActorCmdExec 251, Movement_0724
    ActorCmdWait
    ActorMsg 1024, 29, 251, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 113, 662, 1, 8, 0
    VMSleep 16
    BGMChangeMap
    ActorCmdWait
    ActorDelete 251
    WorkSetConst 0x4153, 2
    Cmd_0262 3, 0
    FlagSet 742
    FlagSet 741
    WorkSetConst 0x40a8, 4
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 20, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 21, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0665
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0673

L_0665:
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0673:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06B6
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_06C4

L_06B6:
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_06C4:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_06D4:
    Move 12, 1
    MoveEnd

Movement_06DC:
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

Movement_070C:
    Move 32, 1
    MoveEnd

Movement_0714:
    Move 33, 1
    MoveEnd

Movement_071C:
    Move 34, 1
    MoveEnd

Movement_0724:
    Move 35, 1
    MoveEnd

Movement_072C:
    Move 75, 1
    MoveEnd

Movement_0734:
    Move 159, 1
    MoveEnd
