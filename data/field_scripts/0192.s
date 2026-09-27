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
    ScriptEntry Script_18
    ScriptEntry Script_19
    ScriptEntry Script_20
    ScriptEntry Script_21
    ScriptEntry Script_22
    ScriptEntry Script_23
    ScriptEntry Script_24
    ScriptEntry Script_25
    ScriptEntry Script_26
    ScriptEntry Script_27
    ScriptEntry Script_28
    ScriptEntry Script_29
    ScriptEntry Script_30
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_12:
    FlagSet 950
    FlagSet 951
    FlagSet 953
    FlagSet 955
    FlagSet 957
    FlagReset 948
    FlagReset 949
    FlagReset 952
    FlagReset 954
    FlagReset 956
    VMStackPush 0x40c3
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00E5
    ObjInitNPCGPos 2, 2, 198, 2, 396
    ObjInitNPCGPos 4, 3, 197, 2, 396
    VMJump L_015A

L_00E5:
    VMStackPush 0x40c3
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0116
    ObjInitNPCGPos 2, 1, 198, 2, 396
    ObjInitNPCGPos 4, 1, 197, 2, 396
    VMJump L_015A

L_0116:
    VMStackPush 0x40c3
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_013B
    ObjInitNPCGPos 5, 1, 211, 0, 403
    VMJump L_015A

L_013B:
    VMStackPush 0x40c3
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_015A
    ObjInitNPCGPos 5, 2, 213, 0, 405

L_015A:
    VMHalt

Script_13:
    VMHalt

Script_14:
    ActorsPauseAll
    ActorCmdExec 5, Movement_0274
    VMSleep 16
    ActorWalkRoute 255, 213, 403, 1, 8, 0
    ActorCmdExec 6, Movement_0E24
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 27, 5, 5, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_0280
    VMSleep 16
    ActorCmdExec 5, Movement_0E34
    ActorCmdExec 255, Movement_0E34
    ActorCmdWait
    ActorMsg 1024, 28, 6, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 29, 5, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 30, 6, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 31, 5, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 32, 6, 3, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_029C
    ActorCmdWait
    ActorCmdExec 255, Movement_0E2C
    ActorCmdExec 5, Movement_0E24
    ActorCmdWait
    ActorMsg 1024, 33, 5, 6, 0
    MsgWinCloseAll
    ActorWalkRoute 5, 202, 405, 1, 4, 1
    VMSleep 8
    ActorCmdExec 255, Movement_0E34
    ActorCmdWait
    ActorDelete 6
    ActorDelete 5
    WorkSetConst 0x40c3, 5
    FlagSet 716
    FlagSet 717
    FlagSet 717
    FlagSet 708
    FlagSet 1001
    WorkSetConst 0x40c5, 1
    Cmd_0262 1, 12
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0274:
    Move 75, 1
    Move 12, 1
    MoveEnd

Movement_0280:
    Move 12, 2
    Move 35, 1
    Move 63, 1
    Move 33, 1
    Move 63, 1
    Move 35, 1
    MoveEnd

Movement_029C:
    Move 13, 2
    Move 14, 6
    MoveEnd
    Move 14, 1
    Move 33, 1
    MoveEnd

Script_11:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 255, 220, 432, 1, 8, 0
    ActorCmdWait
    VMStackPush 0x8022
    VMStackPushConst 432
    VMStackCmp 5
    VMJumpIf 255, L_02E9
    ActorCmdExec 255, Movement_0E34
    ActorCmdWait

L_02E9:
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0304
    PlayerSetSpecialSequence 1

L_0304:
    ActorMsg 1024, 3, 3, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 4, 2, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 5, 3, 3, 0
    MsgWinCloseAll
    ActorWalkRoute 3, 218, 432, 1, 4, 1
    VMSleep 7
    SEPlay 1653
    ActorCmdExec 2, Movement_04B0
    ActorCmdWait
    SEWait
    ActorMsg 1024, 6, 3, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 7, 2, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 8, 3, 3, 0
    MsgWinCloseAll
    FlagReset 716
    ActorAdd 5
    ActorMsg 1024, 9, 5, 6, 1
    MsgWinCloseAll
    ActorCmdExec 255, Movement_04A4
    ActorCmdExec 3, Movement_04A4
    ActorCmdExec 2, Movement_04A4
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 5, 219, 432, 1, 4, 0
    VMSleep 28
    ActorCmdExec 255, Movement_04D0
    VMSleep 20
    SEPlay 1420
    ActorCmdExec 3, Movement_04C0
    ActorCmdExec 2, Movement_0E24
    ActorCmdWait
    SEWait
    ActorCmdExec 255, Movement_0E34
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 10, 5, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 11, 3, 3, 0
    MsgWinCloseAll
    ActorWalkRoute 3, 212, 432, 1, 4, 1
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 12, 5, 5, 0
    ActorCmdWait
    MsgWinCloseAll
    ActorWalkRoute 5, 212, 432, 1, 4, 0
    ActorCmdWait
    ActorDelete 5
    ActorDelete 3
    ActorWalkRoute 2, 219, 433, 1, 8, 1
    ActorCmdWait
    ActorMsg 1024, 13, 2, 4, 0
    MsgWinCloseAll
    ActorWalkRoute 2, 212, 433, 1, 8, 1
    ActorCmdWait
    ActorSetGPos 2, 198, 2, 396, 2
    FlagSet 716
    FlagSet 707
    WorkSetConst 0x40c3, 1
    FlagSet 2478
    Cmd_0262 1, 9
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04A4:
    Move 75, 1
    Move 35, 1
    MoveEnd

Movement_04B0:
    Move 71, 1
    Move 17, 1
    Move 72, 1
    MoveEnd

Movement_04C0:
    Move 71, 1
    Move 18, 2
    Move 72, 1
    MoveEnd

Movement_04D0:
    Move 0, 1
    Move 71, 1
    Move 17, 1
    Move 72, 1
    MoveEnd
    VMStackAdd
    VMReturn
    Move 15, 4
    Move 12, 3
    Move 15, 12
    Move 34, 1
    MoveEnd
    Move 12, 6
    Move 15, 4
    Move 12, 3
    Move 15, 11
    MoveEnd

Script_29:
    ActorsPauseAll
    ActorCmdExec 2, Movement_0E44
    ActorCmdWait
    ActorMsg 1024, 14, 2, 5, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    WorkAdd 0x8021, 1
    ActorWalkRoute 2, 0x8021, 0x8022, 1, 8, 1
    VMSleep 16
    ActorCmdExec 4, Movement_0E2C
    ActorCmdWait
    ActorMsg 1024, 15, 2, 5, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8022, 397
    VMJumpIf 1, L_0579
    VMJump L_0587

L_0579:
    ActorCmdExec 255, Movement_064C
    VMJump L_05C9

L_0587:
    WorkCmpConst 0x8022, 398
    VMJumpIf 1, L_059A
    VMJump L_05A8

L_059A:
    ActorCmdExec 255, Movement_065C
    VMJump L_05C9

L_05A8:
    WorkCmpConst 0x8022, 399
    VMJumpIf 1, L_05BB
    VMJump L_05C9

L_05BB:
    ActorCmdExec 255, Movement_0668
    VMJump L_05C9

L_05C9:
    ActorWalkRoute 2, 198, 396, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 2, Movement_0E2C
    ActorCmdWait
    ActorMsg 1024, 16, 4, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 17, 2, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 18, 4, 3, 0
    WorkSetConst 0x40c3, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_063E
    ActorMsg 1024, 20, 4, 3, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0644

L_063E:
    VMCall L_06E0

L_0644:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_064C:
    Move 13, 1
    Move 15, 3
    Move 32, 1
    MoveEnd

Movement_065C:
    Move 15, 3
    Move 32, 1
    MoveEnd

Movement_0668:
    Move 15, 3
    Move 12, 1
    MoveEnd

Script_10:
    ActorsPauseAll
    WordSetLoadRivalName 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 21, 4, 3, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06D4
    ActorMsg 1024, 20, 4, 3, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_06DA

L_06D4:
    VMCall L_06E0

L_06DA:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_06E0:
    ActorMsg 1024, 19, 4, 3, 0
    MsgWinCloseAll
    CallTrainerBattle 346, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_072D
    ActorSetGPos 4, 197, 2, 396, 1
    ActorSetGPos 255, 197, 2, 397, 0
    CallTrainerBattleEnd
    VMJump L_072F

L_072D:
    CallTrainerLose

L_072F:
    ActorMsg 1024, 23, 4, 3, 0
    MsgWinCloseAll
    FlagReset 716
    ActorAdd 5
    ActorSetGPos 5, 185, 2, 398, 3
    ActorCmdExec 5, Movement_07DC
    VMSleep 16
    ActorCmdExec 255, Movement_0E34
    ActorCmdExec 2, Movement_0E34
    ActorCmdExec 4, Movement_0E34
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 24, 5, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 25, 4, 3, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_0DEC
    ActorCmdWait
    SEPlay 1369
    ActorDelete 4
    SEWait
    ActorCmdExec 255, Movement_07E4
    ActorCmdExec 5, Movement_07EC
    ActorCmdWait
    WorkSetConst 0x40c3, 3
    FlagSet 715
    FlagSet 706
    RTReserveScript 1
    MapChangeWarp 104, 7, 25, 0
    VMReturn
    .balign 4, 0

Movement_07DC:
    Move 19, 10
    MoveEnd

Movement_07E4:
    Move 12, 2
    MoveEnd

Movement_07EC:
    Move 15, 2
    Move 12, 1
    MoveEnd

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 65, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 64, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 66, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 67, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 68, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_26:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 69, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x8023, 0
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0990
    VMStackPush 0x4097
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_095B
    ActorMsg 1024, 55, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0945
    WorkSetConst 0x4097, 1
    ActorMsg 1024, 57, 0, 0, 0
    VMCall L_0AF2
    VMJump L_0955

L_0945:
    ActorMsg 1024, 56, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0955:
    VMJump L_098A

L_095B:
    VMStackPush 0x4097
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_097A
    VMCall L_0AF2
    VMJump L_098A

L_097A:
    ActorMsg 1024, 63, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_098A:
    VMJump L_0A29

L_0990:
    VMStackPush 0x4097
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09FA
    ActorMsg 1024, 46, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09E4
    WorkSetConst 0x4097, 1
    ActorMsg 1024, 48, 0, 0, 0
    VMCall L_0A2F
    VMJump L_09F4

L_09E4:
    ActorMsg 1024, 47, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_09F4:
    VMJump L_0A29

L_09FA:
    VMStackPush 0x4097
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A19
    VMCall L_0A2F
    VMJump L_0A29

L_0A19:
    ActorMsg 1024, 54, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0A29:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0A2F:
    ActorMsg 1024, 49, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0ADA
    WorkSetConst 0x8024, 0
    PokePartyGetCount 0x8024, 2
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0A87
    ActorMsg 1024, 51, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0AD4

L_0A87:
    ActorMsg 1024, 50, 0, 0, 0
    ActorMsgClose
    CallTrainerBattle 367, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0ABC
    CallTrainerBattleEnd
    VMJump L_0ABE

L_0ABC:
    CallTrainerLose

L_0ABE:
    ActorMsg 1024, 53, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x4097, 2

L_0AD4:
    VMJump L_0AEA

L_0ADA:
    ActorMsg 1024, 52, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0AEA:
    WorkSetConst 0x8024, 0
    VMReturn

L_0AF2:
    ActorMsg 1024, 58, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B9D
    WorkSetConst 0x8025, 0
    PokePartyGetCount 0x8025, 2
    VMStackPush 0x8025
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0B4A
    ActorMsg 1024, 60, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0B97

L_0B4A:
    ActorMsg 1024, 59, 0, 0, 0
    ActorMsgClose
    CallTrainerBattle 366, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B7F
    CallTrainerBattleEnd
    VMJump L_0B81

L_0B7F:
    CallTrainerLose

L_0B81:
    ActorMsg 1024, 62, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x4097, 2

L_0B97:
    VMJump L_0BAD

L_0B9D:
    ActorMsg 1024, 61, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0BAD:
    WorkSetConst 0x8025, 0
    VMReturn

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 34, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 36, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 37, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 39, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_27:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 552, 0
    ParentActorMsg 1024, 38, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 40, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 41, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 42, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 43, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_24:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 44, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_25:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 45, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_28:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_30:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    PlayerGetDir 0x8020
    VMStackPush 0x8022
    VMStackPushConst 397
    VMStackCmp 1
    VMJumpIf 255, L_0D77
    ActorCmdExec 20, Movement_0DCC
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_0D6F
    VMSleep 16
    ActorCmdExec 255, Movement_0E2C

L_0D6F:
    ActorCmdWait
    VMJump L_0DA0

L_0D77:
    ActorCmdExec 20, Movement_0DD8
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0D9E
    VMSleep 16
    ActorCmdExec 255, Movement_0E24

L_0D9E:
    ActorCmdWait

L_0DA0:
    ActorMsg 1024, 1, 20, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0DF4
    VMSleep 8
    ActorCmdExec 20, Movement_0E3C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0DCC:
    Move 32, 1
    Move 75, 1
    MoveEnd

Movement_0DD8:
    Move 33, 1
    Move 75, 1
    MoveEnd
    Move 13, 1
    MoveEnd

Movement_0DEC:
    Move 12, 1
    MoveEnd

Movement_0DF4:
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

Movement_0E24:
    Move 32, 1
    MoveEnd

Movement_0E2C:
    Move 33, 1
    MoveEnd

Movement_0E34:
    Move 34, 1
    MoveEnd

Movement_0E3C:
    Move 35, 1
    MoveEnd

Movement_0E44:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
