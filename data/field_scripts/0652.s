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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_9:
    RTCGetWeekDay 0x8023
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMStackPushFlag 2774
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_007B
    FlagReset 902
    VMJump L_007F

L_007B:
    FlagSet 902

L_007F:
    VMStackPush 0x4111
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00AE
    Cmd_0262 2, 14
    VMJump L_00D7

L_00AE:
    VMStackPush 0x4111
    VMStackPushConst 0
    VMStackCmp 5
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00D7
    Cmd_0262 2, 0

L_00D7:
    VMHalt

Script_5:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    PlayerGetDir 0x8020
    VMStackPush 0x8021
    VMStackPushConst 432
    VMStackCmp 1
    VMJumpIf 255, L_0139
    ActorCmdExec 15, Movement_04A0
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_011F
    VMSleep 20
    ActorCmdExec 255, Movement_06B8

L_011F:
    ActorCmdWait
    ActorCmdExec 15, Movement_04AC
    ActorCmdExec 255, Movement_04D0
    ActorCmdWait
    VMJump L_01F9

L_0139:
    VMStackPush 0x8021
    VMStackPushConst 430
    VMStackCmp 1
    VMJumpIf 255, L_017C
    ActorWalkRoute 15, 431, 583, 0, 8, 0
    ActorCmdExec 255, Movement_0680
    ActorCmdWait
    ActorCmdExec 15, Movement_06C8
    ActorCmdExec 255, Movement_06D0
    ActorCmdWait
    VMJump L_01F9

L_017C:
    VMStackPush 0x8021
    VMStackPushConst 431
    VMStackCmp 1
    VMJumpIf 255, L_01B1
    ActorCmdExec 15, Movement_04B4
    ActorCmdWait
    ActorCmdExec 15, Movement_06C8
    ActorCmdExec 255, Movement_04C0
    ActorCmdWait
    VMJump L_01F9

L_01B1:
    WorkSub 0x8022, 1
    ActorWalkRoute 15, 0x8021, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 15, Movement_06C0
    ActorCmdWait
    ActorWalkRoute 15, 431, 583, 4, 8, 0
    ActorWalkRoute 255, 430, 583, 4, 8, 1
    ActorCmdWait
    ActorCmdExec 15, Movement_06C8
    ActorCmdWait

L_01F9:
    ActorMsg 1024, 3, 15, 0, 0
    ActorMsg 1024, 4, 15, 0, 0
    MsgWinCloseAll
    ActorCmdExec 15, Movement_06B8
    VMSleep 4
    ActorCmdExec 255, Movement_06B8
    ActorCmdWait
    SEPlay 1589
    ActorCmdExec 15, Movement_04E0
    ActorCmdWait
    SEWait
    ActorCmdExec 12, Movement_04F4
    ActorCmdExec 14, Movement_04E8
    ActorCmdExec 17, Movement_06C0
    VMSleep 4
    ActorCmdExec 23, Movement_04E8
    ActorCmdExec 13, Movement_04E8
    ActorCmdExec 18, Movement_06C0
    ActorCmdWait
    ActorCmdExec 19, Movement_04E8
    ActorCmdExec 21, Movement_06C0
    VMSleep 4
    ActorCmdExec 20, Movement_06C0
    ActorCmdExec 22, Movement_06C0
    ActorCmdExec 24, Movement_04F4
    ActorCmdWait
    FadeEx 3, 0, 16, 4
    ActorCmdExec 21, Movement_0508
    ActorCmdExec 22, Movement_0508
    VMSleep 4
    ActorCmdExec 19, Movement_0500
    ActorCmdExec 24, Movement_0508
    ActorCmdExec 12, Movement_0500
    ActorCmdExec 13, Movement_0500
    VMSleep 4
    ActorCmdExec 18, Movement_0500
    ActorCmdWait
    FadeExWait
    ActorDelete 12
    ActorDelete 13
    ActorDelete 14
    ActorDelete 17
    ActorDelete 18
    ActorDelete 19
    ActorDelete 20
    ActorDelete 21
    ActorDelete 22
    ActorDelete 23
    ActorDelete 24
    FadeEx 3, 16, 0, 4
    FadeExWait
    ActorMsg 1024, 6, 15, 0, 0
    MsgWinCloseAll
    BGMPlay 1238
    ActorCmdExec 15, Movement_06C8
    VMSleep 4
    ActorCmdExec 255, Movement_06D0
    ActorCmdWait
    ActorMsg 1024, 7, 15, 0, 0
    MsgWinCloseAll
    ActorCmdExec 15, Movement_04E0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 8, 15, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 358, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_039B
    CallTrainerBattleEnd
    VMJump L_039D

L_039B:
    CallTrainerLose

L_039D:
    WordSetPlayerName 0
    ActorMsg 1024, 9, 15, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 46
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    WordSetPlayerName 0
    ActorMsg 1024, 10, 15, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 15, 431, 572, 4, 8, 0
    VMSleep 8
    ActorCmdExec 255, Movement_06B8
    ActorCmdWait
    ActorDelete 15
    BGMChangeMap
    WorkSetConst 0x40b6, 3
    FlagSet 758
    FlagSet 757
    FlagReset 988
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    VMStackPush 0x40b6
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_044E
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0462

L_044E:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_0462:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    WordSetPlayerName 0
    SystemMsg 2, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04A0:
    Move 15, 2
    Move 33, 1
    MoveEnd

Movement_04AC:
    Move 14, 1
    MoveEnd

Movement_04B4:
    Move 15, 1
    Move 33, 1
    MoveEnd

Movement_04C0:
    Move 14, 1
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_04D0:
    Move 14, 2
    Move 12, 1
    Move 35, 1
    MoveEnd

Movement_04E0:
    Move 182, 1
    MoveEnd

Movement_04E8:
    Move 33, 1
    Move 75, 1
    MoveEnd

Movement_04F4:
    Move 33, 1
    Move 159, 1
    MoveEnd

Movement_0500:
    Move 12, 8
    MoveEnd

Movement_0508:
    Move 12, 7
    MoveEnd
    VMStackAdd
    DebugPrint 254
    VMNop

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 17, 0
    MsgPlaceSignClose
    FlagSet 2667
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 18, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 16, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    PVPlay 630, 0
    ScreamMsg 11, 2
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8024, 128
    WorkOr 0x8024, 8
    CallWildBattle 630, 25, 0x8024
    WorkSetConst 0x8024, 0
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0620
    FlagSet 902
    FlagSet 2774
    ActorDelete 25
    CallWildBattleEnd
    VMJump L_0622

L_0620:
    CallWildLose

L_0622:
    WildBattleGetResult 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0639
    VMJump L_063F

L_0639:
    VMJump L_066F

L_063F:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_065F
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_065F
    VMJump L_066F

L_065F:
    SystemMsg 12, 2
    LastKeyWait
    InfoMsgClose
    VMJump L_066F

L_066F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_0680:
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

Movement_06B8:
    Move 32, 1
    MoveEnd

Movement_06C0:
    Move 33, 1
    MoveEnd

Movement_06C8:
    Move 34, 1
    MoveEnd

Movement_06D0:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
