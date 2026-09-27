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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0

Script_11:
    VMStackPush 0x4111
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0065
    Cmd_0262 2, 14

L_0065:
    VMHalt

Script_3:
    ActorsPauseAll
    VMStackPushFlag 2406
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0088
    VMCall L_03D8
    VMJump L_008E

L_0088:
    VMCall L_0269

L_008E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    WordSetPlayerName 0
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 5
    WorkSet 0x8001, 0
    RTCallGlobal 10536
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorWalkRoute 255, 43, 30, 0, 8, 1
    ActorCmdExec 21, Movement_01F8
    ActorCmdWait
    ActorNew 43, 41, 0, 251, 190, 0
    ActorWalkRoute 251, 43, 32, 0, 4, 1
    ActorCmdWait
    ActorMsg 1024, 12, 251, 4, 1
    ActorMsgClose
    ActorCmdExec 255, Movement_01EC
    ActorCmdExec 21, Movement_01EC
    ActorCmdWait
    ActorMsg 1024, 13, 251, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 14, 21, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 15, 251, 4, 0
    ActorMsg 1024, 16, 251, 4, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0210
    VMSleep 16
    ActorCmdExec 255, Movement_059C
    ActorCmdExec 21, Movement_059C
    ActorCmdWait
    ActorMsg 1024, 17, 21, 5, 0
    MsgWinCloseAll
    ActorCmdExec 21, Movement_0594
    ActorCmdWait
    ActorMsg 1024, 18, 21, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 252
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 19, 21, 5, 0
    MsgWinCloseAll
    ActorCmdExec 21, Movement_0208
    ActorCmdWait
    ActorDelete 21
    ActorDelete 251
    ActorDelete 24
    WorkSetConst 0x4111, 1
    FlagSet 908
    FlagSet 999
    Cmd_0262 2, 0
    FlagReset 1000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_01EC:
    Move 75, 1
    Move 33, 1
    MoveEnd

Movement_01F8:
    Move 12, 2
    Move 15, 1
    Move 12, 2
    MoveEnd

Movement_0208:
    Move 15, 7
    MoveEnd

Movement_0210:
    Move 12, 1
    Move 15, 8
    MoveEnd

Script_5:
    ActorsPauseAll
    SEPlay 1351
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    WorkSetConst 0x8008, 5
    WorkAdd 0x8008, 0x418a
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 0x8008, 254, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMStackPush 0x418a
    VMStackPushConst 4
    VMStackCmp 5
    VMJumpIf 255, L_0263
    WorkAdd 0x418a, 1

L_0263:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0269:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetGPos 0x8021, 0x8022
    ActorGetGPos 21, 0x8023, 0x8024
    VMStackPush 0x8022
    VMStackPush 0x8024
    VMStackCmp 5
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_02B4
    DebugPrint 99
    ActorWalkRoute 21, 68, 0x8022, 0, 8, 0
    ActorCmdWait

L_02B4:
    VMStackPush 0x8022
    VMStackPush 0x8024
    VMStackCmp 5
    VMJumpIf 255, L_02D1
    ActorCmdExec 21, Movement_059C
    ActorCmdWait

L_02D1:
    VMStackPushFlag 407
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F6
    ActorMsg 1024, 0, 21, 1, 0
    VMJump L_0302

L_02F6:
    ActorMsg 1024, 4, 21, 1, 0

L_0302:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03A6
    ActorMsg 1024, 2, 21, 1, 0
    MsgWinCloseAll
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0342
    PlayerSetSpecialSequence 1

L_0342:
    ActorCmdExec 255, Movement_055C
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    WorkSet 0x8000, 21
    WorkSet 0x8001, 5
    WorkSet 0x8002, 0
    WorkSet 0x8003, 632
    WorkSet 0x8004, 5
    RTCallGlobal 10535
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 407
    WorkSetConst 0x400f, 0
    VMJump L_03D6

L_03A6:
    ActorCmdExec 21, Movement_053C
    ActorCmdWait
    ActorMsg 1024, 1, 21, 1, 0
    MsgWinCloseAll
    ActorCmdExec 21, Movement_057C
    ActorCmdExec 255, Movement_0554
    ActorCmdWait
    WorkSetConst 0x400f, 1

L_03D6:
    VMReturn

L_03D8:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 255, Movement_0594
    ActorCmdExec 254, Movement_057C
    ActorCmdWait
    ActorMsg 1024, 3, 254, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_046F
    ActorMsg 1024, 1, 254, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 5
    WorkSet 0x8001, 0
    RTCallGlobal 10536
    VMStackPop 0x8001
    VMStackPop 0x8000
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 21, 67, 69, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 21, Movement_059C
    ActorCmdExec 255, Movement_0554
    ActorCmdWait
    VMJump L_048D

L_046F:
    ActorMsg 1024, 2, 254, 0, 0
    MsgWinCloseAll
    ActorPairSetMoveEnable 1
    ActorCmdExec 255, Movement_055C
    ActorCmdWait
    ActorPairSetMoveEnable 0

L_048D:
    VMReturn

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 27, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 24, Movement_059C
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 28, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 29, 0
    MsgPlaceSignClose
    FlagSet 2663
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_053C:
    Move 181, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0554:
    Move 15, 1
    MoveEnd

Movement_055C:
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

Movement_057C:
    Move 3, 1
    MoveEnd
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd

Movement_0594:
    Move 34, 1
    MoveEnd

Movement_059C:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Script_6:
    ActorsPauseAll
    VMStackPushFlag 470
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0694
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    PokeDexCheckHabitatList 154, 0, 0, 0x8025
    PokeDexCheckHabitatList 154, 1, 0, 0x8026
    PokeDexCheckHabitatList 154, 2, 0, 0x8027
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0680
    ParentActorMsg 1024, 25, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 8
    WorkSet 0x8001, 5
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 470
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_068E

L_0680:
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_068E:
    VMJump L_06A8

L_0694:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    ActorMsgClose

L_06A8:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
