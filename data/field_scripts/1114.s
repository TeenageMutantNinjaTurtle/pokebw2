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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_2:
    VMHalt

Script_3:
    VMStackPush 0x40f4
    VMStackPushConst 4
    VMStackCmp 1
    VMStackPushFlag 854
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0089
    ActorSetGPos 0, 8, 0, 6, 3
    VMJump L_00B8

L_0089:
    VMStackPush 0x40f4
    VMStackPushConst 2
    VMStackCmp 4
    VMStackPushFlag 854
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00B8
    ActorSetGPos 0, 8, 0, 6, 3

L_00B8:
    VMHalt

Script_4:
    VMHalt

Script_5:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    FlagReset 848
    FlagReset 854
    ActorWalkRoute 255, 11, 8, 1, 8, 0
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xb8000, 0, 0x34000, 80
    EvCameraWait
    ActorMsg 1024, 0, 4, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_0988
    ActorCmdWait
    ActorCmdExec 4, Movement_08A0
    VMSleep 24
    SEPlay 2274
    SEWait
    ActorCmdWait
    ActorMsg 1024, 1, 4, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 4, 12, 2, 0, 16, 0
    ActorCmdWait
    ActorMsg 1024, 2, 4, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 4, 12, 3, 0, 16, 0
    ActorCmdWait
    ActorMsg 1024, 3, 4, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 4, 13, 5, 0, 16, 0
    ActorCmdWait
    ActorCmdExec 4, Movement_08A0
    VMSleep 24
    SEPlay 2274
    SEWait
    ActorCmdWait
    ActorMsg 1024, 4, 4, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 60
    ActorWalkRoute 4, 13, 7, 0, 16, 0
    VMSleep 40
    ActorCmdExec 255, Movement_0998
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorMsg 1024, 5, 4, 0, 0
    MsgWinCloseAll
    ActorAdd 1
    FlagSet 2554
    ActorCmdExec 1, Movement_08AC
    BGMChangeMap
    ActorCmdWait
    ActorCmdExec 1, Movement_0998
    ActorCmdExec 4, Movement_0990
    ActorCmdExec 255, Movement_0980
    ActorCmdWait
    ActorMsg 1024, 6, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 7, 4, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_0384
    VMSleep 26
    ActorCmdExec 1, Movement_0988
    ActorCmdExec 255, Movement_0988
    ActorCmdWait
    SEPlay 1369
    ActorDelete 4
    SEWait
    ActorAdd 0
    ActorCmdExec 0, Movement_0374
    ActorCmdWait
    ActorCmdExec 1, Movement_0990
    ActorCmdExec 255, Movement_0990
    ActorCmdWait
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 1, 0, 0
    MsgWinCloseAll
    ActorAdd 2
    PVPlay 510, 0
    ActorMsg 1024, 10, 2, 0, 0
    PVWait
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_09A0
    ActorCmdWait
    ActorMsg 1024, 11, 1, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 12, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 13, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0988
    ActorCmdExec 255, Movement_0980
    ActorCmdWait
    ActorMsg 1024, 14, 1, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 348, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0319
    CallTrainerBattleEnd
    VMJump L_0327

L_0319:
    FlagSet 848
    FlagSet 854
    FlagReset 2554
    CallTrainerLose

L_0327:
    ActorAdd 5
    ActorAdd 3
    ActorCmdExec 5, Movement_08AC
    ActorCmdExec 3, Movement_08AC
    ActorCmdWait
    ActorMsg 1024, 15, 5, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 847
    WorkSetConst 0x40f4, 2
    WorkSetConst 0x4101, 1
    FlagSet 842
    FlagSet 843
    FlagSet 1026
    FlagSet 909
    VMHalt
    .balign 4, 0

Movement_0374:
    Move 68, 1
    Move 16, 3
    Move 39, 1
    MoveEnd

Movement_0384:
    Move 13, 3
    Move 14, 2
    Move 13, 3
    MoveEnd

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    TrainerFlagGet 498, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0430
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 17, 5, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 498, 0, 0
    VMCall L_08C0
    ActorMsg 1024, 18, 5, 0, 0
    WorkAdd 0x40f4, 1
    TrainerFlagSet 498
    VMStackPush 0x40f4
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0426
    MsgWaitAdvance
    MsgWinCloseAll
    VMCall L_04E4
    VMJump L_042A

L_0426:
    LastKeyWait
    MsgWinCloseAll

L_042A:
    VMJump L_0444

L_0430:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose

L_0444:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    TrainerFlagGet 499, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04CA
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 19, 3, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 499, 0, 0
    VMCall L_08C0
    ActorMsg 1024, 20, 3, 0, 0
    WorkAdd 0x40f4, 1
    TrainerFlagSet 499
    VMStackPush 0x40f4
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_04C0
    MsgWaitAdvance
    MsgWinCloseAll
    VMCall L_04E4
    VMJump L_04C4

L_04C0:
    LastKeyWait
    MsgWinCloseAll

L_04C4:
    VMJump L_04DE

L_04CA:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose

L_04DE:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_04E4:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetGPos 0x8022, 0x8023
    PlayerGetDir 0x8021
    VMStackPush 0x8022
    VMStackPushConst 13
    VMStackCmp 4
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 5
    VMStackCmp 7
    VMJumpIf 255, L_0525
    ActorCmdExec 255, Movement_0990
    VMJump L_0540

L_0525:
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 5
    VMJumpIf 255, L_0540
    ActorCmdExec 255, Movement_0980

L_0540:
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x9e000, 0, 0x68000, 32
    EvCameraWait
    ActorCmdWait
    ActorMsg 1024, 22, 1, 0, 0
    ActorCmdExec 1, Movement_0990
    ActorCmdWait
    ActorMsg 1024, 23, 1, 0, 0
    MsgWinCloseAll
    FlagReset 2554
    ActorCmdExec 1, Movement_08B4
    ActorCmdExec 5, Movement_08B4
    ActorCmdExec 3, Movement_08B4
    ActorCmdWait
    BGMChangeMap
    ActorDelete 1
    ActorDelete 5
    ActorDelete 3
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 5
    VMJumpIf 255, L_05D1
    ActorCmdExec 255, Movement_0990
    ActorCmdWait

L_05D1:
    ActorMsg 1024, 25, 0, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    EvCameraMoveToDefault 32
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    WorkSetConst 0x4101, 2
    FlagSet 848
    FlagSet 857
    VMReturn

Script_9:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    VMStackPush 0x40f4
    VMStackPushConst 4
    VMStackCmp 0
    VMJumpIf 255, L_065D
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 24, 0, 0, 0
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0649
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0657

L_0649:
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0998
    ActorCmdWait

L_0657:
    VMJump L_069E

L_065D:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 25, 0, 0, 0
    PlayerGetDir 0x8021
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0690
    LastKeyWait
    MsgWinCloseAll
    VMJump L_069E

L_0690:
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0998
    ActorCmdWait

L_069E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    PVPlay 510, 0
    VMStackPush 0x40f4
    VMStackPushConst 4
    VMStackCmp 0
    VMJumpIf 255, L_06D5
    ActorMsg 1024, 10, 2, 0, 0
    VMJump L_06E1

L_06D5:
    ActorMsg 1024, 30, 2, 0, 0

L_06E1:
    PVWait
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x8022
    VMStackPushConst 10
    VMStackCmp 1
    VMJumpIf 255, L_0716
    ActorCmdExec 5, Movement_076C
    VMJump L_071E

L_0716:
    ActorCmdExec 5, Movement_0784

L_071E:
    VMSleep 46
    ActorCmdExec 255, Movement_07B4
    ActorCmdWait
    ActorMsg 1024, 16, 5, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8022
    VMStackPushConst 10
    VMStackCmp 1
    VMJumpIf 255, L_075B
    ActorCmdExec 5, Movement_079C
    VMJump L_0763

L_075B:
    ActorCmdExec 5, Movement_07A8

L_0763:
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_076C:
    Move 38, 1
    Move 75, 1
    Move 17, 1
    Move 18, 1
    Move 16, 1
    MoveEnd

Movement_0784:
    Move 39, 1
    Move 75, 1
    Move 17, 1
    Move 19, 1
    Move 16, 1
    MoveEnd

Movement_079C:
    Move 19, 1
    Move 36, 1
    MoveEnd

Movement_07A8:
    Move 18, 1
    Move 36, 1
    MoveEnd

Movement_07B4:
    Move 1, 1
    Move 71, 1
    Move 16, 1
    Move 72, 1
    MoveEnd

Script_1:
    ActorsPauseAll
    GameGetVersion 0x8020
    PlayerGetDir 0x8021
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_07F5
    MapChangeWarpPad 561, 4, 10, 32801
    VMJump L_07FF

L_07F5:
    MapChangeWarpPad 564, 4, 10, 32801

L_07FF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0829
    InfoMsg 26, 2
    VMJump L_082E

L_0829:
    InfoMsg 29, 2

L_082E:
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_085C
    InfoMsg 27, 2
    VMJump L_0861

L_085C:
    InfoMsg 29, 2

L_0861:
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_088F
    InfoMsg 28, 2
    VMJump L_0894

L_088F:
    InfoMsg 29, 2

L_0894:
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_08A0:
    Move 1, 1
    Move 182, 1
    MoveEnd

Movement_08AC:
    Move 184, 1
    MoveEnd

Movement_08B4:
    Move 185, 1
    Move 69, 1
    MoveEnd

L_08C0:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0939
    PlayerGetGPos 0x8022, 0x8023
    VMStackPush 0x40f4
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 13
    VMStackCmp 4
    VMStackCmp 7
    VMJumpIf 255, L_0912
    ActorSetGPos 1, 11, 0, 6, 3
    VMJump L_0931

L_0912:
    VMStackPush 0x40f4
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0931
    ActorSetGPos 1, 11, 0, 6, 1

L_0931:
    CallTrainerBattleEnd
    VMJump L_093B

L_0939:
    CallTrainerLose

L_093B:
    VMReturn
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

Movement_0980:
    Move 32, 1
    MoveEnd

Movement_0988:
    Move 33, 1
    MoveEnd

Movement_0990:
    Move 34, 1
    MoveEnd

Movement_0998:
    Move 35, 1
    MoveEnd

Movement_09A0:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 100, 1
    MoveEnd
