#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0

Script_1:
    VMStackPush 0x40b3
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2406
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0063
    FlagReset 755

L_0063:
    VMHalt

Script_2:
    VMHalt

Script_4:
    ActorsPauseAll
    VMStackPushFlag 2406
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0088
    VMCall L_026B
    VMJump L_008E

L_0088:
    VMCall L_0094

L_008E:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0094:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetGPos 0x8021, 0x8022
    ActorGetGPos 0, 0x8023, 0x8024
    WorkSub 0x8021, 2
    VMStackPush 0x8022
    VMStackPush 0x8024
    VMStackCmp 5
    VMJumpIf 255, L_00DB
    ActorWalkRoute 0, 0x8021, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_0918
    ActorCmdWait

L_00DB:
    ActorMsg 1024, 0, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0251
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0127
    PlayerSetSpecialSequence 1

L_0127:
    ActorCmdExec 255, Movement_08D8
    ActorCmdWait
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0194
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    WorkSet 0x8000, 0
    WorkSet 0x8001, 6
    WorkSet 0x8002, 1
    WorkSet 0x8003, 588
    WorkSet 0x8004, 10540
    RTCallGlobal 10535
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0241

L_0194:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01F7
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    WorkSet 0x8000, 0
    WorkSet 0x8001, 6
    WorkSet 0x8002, 1
    WorkSet 0x8003, 589
    WorkSet 0x8004, 10540
    RTCallGlobal 10535
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0241

L_01F7:
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    WorkSet 0x8000, 0
    WorkSet 0x8001, 6
    WorkSet 0x8002, 1
    WorkSet 0x8003, 590
    WorkSet 0x8004, 10540
    RTCallGlobal 10535
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000

L_0241:
    FlagSet 755
    Cmd_0262 1, 2
    VMJump L_0269

L_0251:
    ActorMsg 1024, 1, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_08D0
    ActorCmdWait

L_0269:
    VMReturn

L_026B:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_029E
    ActorCmdExec 255, Movement_0900
    ActorCmdExec 254, Movement_08E8
    VMJump L_02D7

L_029E:
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_02C7
    ActorCmdExec 255, Movement_0910
    ActorCmdExec 254, Movement_08F8
    VMJump L_02D7

L_02C7:
    ActorCmdExec 255, Movement_0910
    ActorCmdExec 254, Movement_08F8

L_02D7:
    ActorCmdWait
    ActorMsg 1024, 3, 254, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_036A
    ActorMsg 1024, 1, 254, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorWalkRoute 254, 81, 20, 1, 8, 0
    ActorCmdExec 255, Movement_08D0
    ActorCmdWait
    ActorCmdExec 254, Movement_0918
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 2000
    WorkSet 0x8001, 0
    RTCallGlobal 10536
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagReset 755
    Cmd_0262 1, 3
    ActorAdd 0
    ActorDelete 254
    VMJump L_0388

L_036A:
    ActorMsg 1024, 2, 254, 0, 0
    MsgWinCloseAll
    ActorPairSetMoveEnable 1
    ActorCmdExec 255, Movement_08D8
    ActorCmdWait
    ActorPairSetMoveEnable 0

L_0388:
    VMReturn
    .balign 4, 0
    Move 13, 1
    Move 35, 1
    MoveEnd

Script_3:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetGPos 0x8021, 0x8022
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x338000, 0, 0x65000, 32
    ActorWalkRoute 255, 52, 8, 1, 8, 0
    ActorWalkRoute 254, 50, 8, 1, 8, 0
    ActorCmdWait
    EvCameraWait
    WordSetPlayerName 0
    ActorMsg 1024, 11, 254, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0908
    ActorCmdExec 2, Movement_0908
    ActorCmdWait
    ActorMsg 1024, 12, 1, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 13, 254, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 14, 1, 3, 0
    MsgWinCloseAll
    ActorMsg 1024, 15, 254, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 16, 1, 3, 0
    MsgWinCloseAll
    ActorCmdExec 254, Movement_0918
    VMSleep 4
    ActorCmdExec 255, Movement_0910
    ActorCmdWait
    ActorMsg 1024, 17, 254, 4, 0
    MsgWinCloseAll
    ActorCmdExec 254, Movement_0900
    ActorCmdExec 255, Movement_0900
    ActorCmdWait
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04A4
    CallTrainerMultiBattle 588, 342, 356, 0
    VMJump L_04D1

L_04A4:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04C7
    CallTrainerMultiBattle 589, 342, 356, 0
    VMJump L_04D1

L_04C7:
    CallTrainerMultiBattle 590, 342, 356, 0

L_04D1:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0529
    PokePartyGetCount 0x8008, 2
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0503
    PokePartyRecoverAll

L_0503:
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x338000, 0, 0x65000, 1
    EvCameraWait
    CallTrainerBattleEnd
    VMJump L_052B

L_0529:
    CallTrainerLose

L_052B:
    ActorMsg 1024, 18, 1, 3, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0854
    VMSleep 4
    ActorCmdExec 2, Movement_0864
    VMSleep 8
    ActorCmdExec 255, Movement_0908
    ActorCmdExec 254, Movement_0908
    ActorCmdWait
    ActorDelete 1
    ActorDelete 2
    ActorMsg 1024, 19, 254, 4, 0
    MsgWinCloseAll
    InfoMsg 20, 1
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0920
    ActorCmdExec 254, Movement_0920
    ActorCmdWait
    ActorWalkRoute 20, 51, 7, 0, 8, 0
    VMSleep 40
    ActorCmdExec 254, Movement_0900
    ActorCmdExec 255, Movement_0900
    ActorCmdWait
    ActorCmdExec 20, Movement_0908
    ActorCmdWait
    ActorMsg 1024, 21, 254, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 22, 20, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 23, 254, 4, 0
    MsgWinCloseAll
    ActorMsg 1024, 24, 20, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 25, 254, 4, 0
    MsgWinCloseAll
    ActorCmdExec 254, Movement_0918
    ActorCmdExec 255, Movement_0910
    ActorCmdWait
    ActorMsg 1024, 26, 254, 4, 0
    MsgWinCloseAll
    ActorCmdExec 254, Movement_08D0
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 423
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 27, 254, 4, 0
    MsgWinCloseAll
    ActorCmdExec 254, Movement_0894
    VMSleep 8
    ActorCmdExec 255, Movement_0908
    ActorCmdWait
    ActorWalkRoute 20, 50, 8, 0, 8, 0
    ActorCmdWait
    ActorMsg 1024, 28, 20, 4, 0
    MsgWinCloseAll
    InfoMsg 29, 1
    InfoMsgClose_0039
    ActorCmdExec 255, Movement_0920
    VMSleep 4
    ActorCmdExec 20, Movement_0920
    ActorCmdWait
    SEPlay 1369
    ActorSetGPos 19, 51, 0, 0, 1
    ActorCmdExec 20, Movement_0900
    VMSleep 4
    ActorCmdExec 255, Movement_0900
    VMSleep 4
    SEWait
    ActorCmdWait
    ActorCmdExec 19, Movement_08A0
    ActorCmdWait
    ActorMsg 1024, 30, 19, 5, 0
    MsgWinCloseAll
    ActorCmdExec 19, Movement_08A8
    VMSleep 40
    ActorCmdExec 20, Movement_0908
    ActorCmdExec 255, Movement_0908
    ActorCmdWait
    ActorCmdExec 20, Movement_0928
    ActorCmdWait
    ActorMsg 1024, 31, 20, 4, 0
    MsgWinCloseAll
    ActorCmdExec 20, Movement_0918
    VMSleep 4
    ActorCmdExec 255, Movement_0910
    ActorCmdWait
    ActorMsg 1024, 32, 20, 4, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 32
    ActorCmdExec 20, Movement_08B4
    VMSleep 12
    ActorCmdExec 255, Movement_0908
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 2000
    WorkSet 0x8001, 0
    RTCallGlobal 10536
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorDelete 254
    ActorDelete 19
    ActorDelete 20
    ActorDelete 21
    WorkSetConst 0x40b3, 1
    WorkSetConst 0x40b2, 3
    FlagSet 755
    FlagSet 759
    FlagSet 1005
    FlagSet 752
    Cmd_0262 1, 4
    MedalDiscover 58
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    ActorCmdExec 21, Movement_0848
    VMSleep 40
    ActorCmdExec 255, Movement_0900
    ActorCmdWait
    ActorMsg 1024, 34, 21, 0, 0
    MsgWinCloseAll
    ActorPairSetMoveEnable 1
    ActorCmdExec 21, Movement_0918
    ActorCmdExec 255, Movement_08D0
    ActorCmdWait
    ActorPairSetMoveEnable 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 33, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0848:
    Move 75, 1
    Move 33, 1
    MoveEnd

Movement_0854:
    Move 19, 1
    Move 17, 4
    Move 19, 9
    MoveEnd

Movement_0864:
    Move 18, 1
    Move 17, 4
    Move 19, 9
    MoveEnd
    VMHalt
    .byte 0x01
    .balign 4, 0
    Move 71, 1
    Move 15, 1
    Move 72, 1
    MoveEnd
    Move 14, 1
    Move 32, 1
    MoveEnd

Movement_0894:
    Move 13, 2
    Move 15, 9
    MoveEnd

Movement_08A0:
    Move 13, 5
    MoveEnd

Movement_08A8:
    Move 13, 5
    Move 15, 10
    MoveEnd

Movement_08B4:
    Move 13, 2
    Move 15, 9
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_08D0:
    Move 15, 1
    MoveEnd

Movement_08D8:
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd

Movement_08E8:
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0

Movement_08F8:
    Move 3, 1
    MoveEnd

Movement_0900:
    Move 32, 1
    MoveEnd

Movement_0908:
    Move 33, 1
    MoveEnd

Movement_0910:
    Move 34, 1
    MoveEnd

Movement_0918:
    Move 35, 1
    MoveEnd

Movement_0920:
    Move 75, 1
    MoveEnd

Movement_0928:
    Move 159, 1
    MoveEnd
