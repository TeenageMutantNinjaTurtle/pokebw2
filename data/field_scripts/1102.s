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
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_1:
    RTCGetWeekDay 0x8023
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2774
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_007F
    FlagReset 902
    VMJump L_0083

L_007F:
    FlagSet 902

L_0083:
    VMStackPush 0x4111
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00B2
    Cmd_0262 2, 14
    VMJump L_00DB

L_00B2:
    VMStackPush 0x4111
    VMStackPushConst 0
    VMStackCmp 5
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00DB
    Cmd_0262 2, 0

L_00DB:
    VMHalt

Script_2:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    PlayerGetDir 0x8020
    VMStackPush 0x8021
    VMStackPushConst 407
    VMStackCmp 1
    VMJumpIf 255, L_011E
    ActorCmdExec 14, Movement_03DC
    ActorCmdWait
    ActorCmdExec 14, Movement_03E8
    ActorCmdExec 255, Movement_040C
    ActorCmdWait
    VMJump L_01DE

L_011E:
    VMStackPush 0x8021
    VMStackPushConst 405
    VMStackCmp 1
    VMJumpIf 255, L_0161
    ActorWalkRoute 14, 406, 577, 0, 8, 0
    ActorCmdExec 255, Movement_064C
    ActorCmdWait
    ActorCmdExec 14, Movement_0694
    ActorCmdExec 255, Movement_069C
    ActorCmdWait
    VMJump L_01DE

L_0161:
    VMStackPush 0x8021
    VMStackPushConst 406
    VMStackCmp 1
    VMJumpIf 255, L_0196
    ActorCmdExec 14, Movement_03F0
    ActorCmdWait
    ActorCmdExec 14, Movement_0694
    ActorCmdExec 255, Movement_03FC
    ActorCmdWait
    VMJump L_01DE

L_0196:
    WorkSub 0x8022, 1
    ActorWalkRoute 14, 0x8021, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 14, Movement_068C
    ActorCmdWait
    ActorWalkRoute 14, 406, 577, 4, 8, 0
    ActorWalkRoute 255, 405, 577, 4, 8, 1
    ActorCmdWait
    ActorCmdExec 14, Movement_0694
    ActorCmdWait

L_01DE:
    ActorMsg 1024, 3, 14, 0, 0
    ActorMsg 1024, 4, 14, 0, 0
    MsgWinCloseAll
    ActorCmdExec 14, Movement_0684
    VMSleep 4
    ActorCmdExec 255, Movement_0684
    ActorCmdWait
    SEPlay 1589
    ActorCmdExec 14, Movement_041C
    ActorCmdWait
    SEWait
    ActorCmdExec 15, Movement_0430
    ActorCmdExec 17, Movement_0424
    ActorCmdExec 18, Movement_068C
    VMSleep 4
    ActorCmdExec 16, Movement_0424
    ActorCmdExec 19, Movement_068C
    VMSleep 4
    ActorCmdExec 21, Movement_0424
    ActorCmdExec 20, Movement_068C
    VMSleep 4
    ActorCmdExec 22, Movement_068C
    ActorCmdWait
    ActorCmdExec 20, Movement_0444
    VMSleep 4
    ActorCmdExec 21, Movement_043C
    ActorCmdExec 15, Movement_043C
    ActorCmdExec 16, Movement_043C
    VMSleep 4
    ActorCmdExec 19, Movement_043C
    VMSleep 4
    ActorCmdExec 17, Movement_043C
    VMSleep 4
    ActorCmdExec 18, Movement_043C
    ActorCmdExec 22, Movement_043C
    ActorCmdWait
    ActorMsg 1024, 6, 14, 0, 0
    MsgWinCloseAll
    BGMPlay 1238
    ActorCmdExec 14, Movement_0694
    VMSleep 4
    ActorCmdExec 255, Movement_069C
    ActorCmdWait
    ActorMsg 1024, 7, 14, 0, 0
    MsgWinCloseAll
    ActorCmdExec 14, Movement_041C
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 8, 14, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 358, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0336
    CallTrainerBattleEnd
    VMJump L_0338

L_0336:
    CallTrainerLose

L_0338:
    WordSetPlayerName 0
    ActorMsg 1024, 9, 14, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 46
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    WordSetPlayerName 0
    ActorMsg 1024, 10, 14, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 14, 406, 563, 4, 8, 0
    VMSleep 8
    ActorCmdExec 255, Movement_0684
    ActorCmdWait
    BGMChangeMap
    ActorDelete 14
    ActorDelete 15
    ActorDelete 16
    ActorDelete 17
    ActorDelete 18
    ActorDelete 19
    ActorDelete 21
    ActorDelete 22
    ActorDelete 20
    WorkSetConst 0x40b6, 3
    FlagSet 758
    FlagSet 757
    FlagReset 988
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_03DC:
    Move 15, 2
    Move 33, 1
    MoveEnd

Movement_03E8:
    Move 14, 1
    MoveEnd

Movement_03F0:
    Move 15, 1
    Move 33, 1
    MoveEnd

Movement_03FC:
    Move 14, 1
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_040C:
    Move 14, 2
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_041C:
    Move 182, 1
    MoveEnd

Movement_0424:
    Move 33, 1
    Move 75, 1
    MoveEnd

Movement_0430:
    Move 33, 1
    Move 159, 1
    MoveEnd

Movement_043C:
    Move 12, 12
    MoveEnd

Movement_0444:
    Move 12, 11
    MoveEnd

Script_3:
    ActorsPauseAll
    VMStackPush 0x40b6
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_047B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_048F

L_047B:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_048F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    WordSetPlayerName 0
    SystemMsg 2, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 16, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 17, 0
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 18, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 17, 0
    MsgPlaceSignClose
    FlagSet 2667
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    PVPlay 628, 0
    ScreamMsg 11, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8024, 128
    WorkOr 0x8024, 8
    CallWildBattle 628, 25, 0x8024
    WorkSetConst 0x8024, 0
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05EC
    FlagSet 902
    FlagSet 2774
    ActorDelete 12
    CallWildBattleEnd
    VMJump L_05EE

L_05EC:
    CallWildLose

L_05EE:
    WildBattleGetResult 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0605
    VMJump L_060B

L_0605:
    VMJump L_063B

L_060B:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_062B
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_062B
    VMJump L_063B

L_062B:
    SystemMsg 12, 2
    LastKeyWait
    InfoMsgClose
    VMJump L_063B

L_063B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_064C:
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

Movement_0684:
    Move 32, 1
    MoveEnd

Movement_068C:
    Move 33, 1
    MoveEnd

Movement_0694:
    Move 34, 1
    MoveEnd

Movement_069C:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
