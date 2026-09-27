#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd

Script_3:
    FlagReset 656
    VMStackPush 0x408f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0066
    WorkSetConst 0x8020, 0
    PokePartyFindEx 649, 0, 0x8020, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_005C
    WorkSetConst 0x408f, 1
    VMJump L_0060

L_005C:
    FlagSet 656

L_0060:
    WorkSetConst 0x8020, 0

L_0066:
    VMHalt

Script_5:
    VMStackPush 0x408f
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0087
    ActorSetGPos 0, 6, 0, 5, 1

L_0087:
    VMHalt

Script_4:
    ActorsPauseAll
    WorkSetConst 0x408f, 2
    VMCall L_012A
    SystemMsg 8, 0
    YesNoWin 0x8010
    InfoMsgClose
    VMCall L_020E
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x408f, 2
    VMJumpIf 1, L_00CA
    VMJump L_00FB

L_00CA:
    ActorMsg 1024, 14, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00EF
    ActorMsgClose

L_00EF:
    VMCall L_020E
    VMJump L_0124

L_00FB:
    WorkCmpConst 0x408f, 3
    VMJumpIf 1, L_010E
    VMJump L_0124

L_010E:
    ActorMsg 1024, 15, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0124

L_0124:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_012A:
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x68000, 0, 0x38000, 16
    EvCameraWait
    ActorCmdExec 0, Movement_03A8
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    ActorMsgClose
    ActorCmdExec 0, Movement_03BC
    ActorCmdExec 255, Movement_03A0
    ActorCmdWait
    ActorMsg 1024, 1, 0, 0, 0
    ActorMsgClose
    EvCameraMoveTo 9688, 0, 0xed000, 0x68000, 0, 0x48000, 8
    ActorCmdExec 0, Movement_03CC
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 2, 0, 0, 0
    ActorMsgClose
    ActorMsg 1024, 3, 0, 0, 1
    ActorMsgClose
    EvCameraMoveToDefault 12
    ActorCmdExec 0, Movement_03CC
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorMsg 1024, 4, 0, 0, 0
    ActorMsgClose
    ActorMsg 1024, 5, 0, 0, 1
    ActorMsgClose
    ActorMsg 1024, 6, 0, 0, 0
    ActorMsgClose
    ActorMsg 1024, 7, 0, 0, 1
    ActorMsgClose
    VMReturn

L_020E:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0341
    CallTrainerBattle 135, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_024E
    VMCall L_0353
    CallTrainerBattleEnd
    VMJump L_0250

L_024E:
    CallTrainerLose

L_0250:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    GameGetVersion 0x8021
    VMStackPush 0x8021
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_028B
    WorkSetConst 0x8022, 117
    WorkSetConst 0x8023, 118
    VMJump L_0297

L_028B:
    WorkSetConst 0x8022, 116
    WorkSetConst 0x8023, 119

L_0297:
    ActorMsg 1024, 9, 0, 0, 0
    ActorMsgClose
    ActorMsg 1024, 10, 0, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 0x8022
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 12, 0, 0, 0
    ActorMsgClose
    ActorCmdExec 0, Movement_03D4
    ActorCmdWait
    ActorMsg 1024, 11, 0, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 0x8023
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorCmdExec 0, Movement_03E8
    ActorCmdWait
    WorkSetConst 0x408f, 3
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8021, 0
    VMJump L_0351

L_0341:
    ActorMsg 1024, 13, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0351:
    VMReturn

L_0353:
    ActorSetGPos 0, 6, 0, 5, 1
    ActorSetGPos 255, 6, 0, 6, 0
    VMReturn

Script_2:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 16, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0398
    SystemMsg 17, 0
    LastKeyWait

L_0398:
    InfoMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_03A0:
    Move 12, 3
    MoveEnd

Movement_03A8:
    Move 75, 1
    Move 62, 1
    Move 33, 1
    Move 63, 1
    MoveEnd

Movement_03BC:
    Move 13, 1
    Move 15, 2
    Move 33, 1
    MoveEnd

Movement_03CC:
    Move 13, 1
    MoveEnd

Movement_03D4:
    Move 12, 1
    Move 63, 1
    Move 75, 1
    Move 13, 1
    MoveEnd

Movement_03E8:
    Move 12, 2
    Move 14, 2
    Move 12, 1
    MoveEnd
