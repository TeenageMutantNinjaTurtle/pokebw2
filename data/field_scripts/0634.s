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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_9:
    VMCall L_0081
    VMHalt

Script_8:
    Cmd_02B2 0, 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0079
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0079
    VMStackPush 0x4136
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0079
    WorkSetConst 0x4136, 1

L_0079:
    VMCall L_0081
    VMHalt

L_0081:
    Cmd_02B2 0, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00A0
    WorkSetConst 0x4136, 0

L_00A0:
    VMReturn

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 5, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 6, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 7, 0
    MsgPlaceSignClose
    FlagSet 2664
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 17
    WorkSet 0x8001, 1
    WorkSet 0x8002, 425
    WorkSet 0x8003, 0
    WorkSet 0x8004, 1
    WorkSet 0x8005, 1
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    Cmd_02B2 0, 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_019B
    Cmd_02B5 0, 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01AF

L_019B:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose

L_01AF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    ActorNew 788, 721, 1, 251, 249, 0
    TrainerCardGetSex 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0204
    VMJump L_020F

L_0204:
    InfoMsg 8, 1
    VMJump L_022D

L_020F:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_0222
    VMJump L_022D

L_0222:
    InfoMsg 9, 1
    VMJump L_022D

L_022D:
    InfoMsgClose_0039
    BGMPlay 1088
    ActorCmdExec 255, Movement_0618
    ActorCmdWait
    ActorGetGPos 255, 0x8021, 0x8022
    PlayerGetDir 0x8010
    ActorWalkRoute 251, 788, 730, 1, 8, 1
    WorkCmpConst 0x8021, 786
    VMJumpIf 1, L_026A
    VMJump L_0299

L_026A:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_028B
    ActorCmdExec 255, Movement_0634
    VMJump L_0293

L_028B:
    ActorCmdExec 255, Movement_0648

L_0293:
    VMJump L_03E3

L_0299:
    WorkCmpConst 0x8021, 787
    VMJumpIf 1, L_02AC
    VMJump L_02DB

L_02AC:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_02CD
    ActorCmdExec 255, Movement_0658
    VMJump L_02D5

L_02CD:
    ActorCmdExec 255, Movement_066C

L_02D5:
    VMJump L_03E3

L_02DB:
    WorkCmpConst 0x8021, 788
    VMJumpIf 1, L_02EE
    VMJump L_031D

L_02EE:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_030F
    ActorCmdExec 255, Movement_05D0
    VMJump L_0317

L_030F:
    ActorCmdExec 255, Movement_05B0

L_0317:
    VMJump L_03E3

L_031D:
    WorkCmpConst 0x8021, 789
    VMJumpIf 1, L_0330
    VMJump L_035F

L_0330:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0351
    ActorCmdExec 255, Movement_067C
    VMJump L_0359

L_0351:
    ActorCmdExec 255, Movement_0690

L_0359:
    VMJump L_03E3

L_035F:
    WorkCmpConst 0x8021, 790
    VMJumpIf 1, L_0372
    VMJump L_03A1

L_0372:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0393
    ActorCmdExec 255, Movement_06A0
    VMJump L_039B

L_0393:
    ActorCmdExec 255, Movement_06B4

L_039B:
    VMJump L_03E3

L_03A1:
    WorkCmpConst 0x8021, 791
    VMJumpIf 1, L_03B4
    VMJump L_03E3

L_03B4:
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_03D5
    ActorCmdExec 255, Movement_06C4
    VMJump L_03DD

L_03D5:
    ActorCmdExec 255, Movement_06D8

L_03DD:
    VMJump L_03E3

L_03E3:
    ActorCmdWait
    ActorCmdExec 251, Movement_0628
    ActorCmdWait
    ActorMsg 1024, 10, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_05D8
    ActorCmdWait
    Cmd_02B5 0, 1
    ActorMsg 1024, 11, 251, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 789, 731, 1, 8, 0
    VMSleep 15
    ActorCmdExec 255, Movement_05E8
    ActorCmdWait
    Cmd_02B5 0, 1
    ActorCmdExec 251, Movement_05E0
    ActorCmdWait
    ActorMsg 1024, 12, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_05D0
    ActorCmdExec 251, Movement_05D0
    ActorCmdWait
    ActorMsg 1024, 13, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0598
    ActorCmdExec 251, Movement_0598
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 251, Movement_05E0
    VMSleep 10
    ActorCmdExec 255, Movement_05E8
    ActorCmdWait
    Cmd_02B5 0, 1
    ActorMsg 1024, 14, 251, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    Cmd_02B3 0, 0x8023
    WorkCmpConst 0x8023, 0
    VMJumpIf 1, L_04DA
    VMJump L_04E6

L_04DA:
    WorkSetConst 0x8024, 706
    VMJump L_0524

L_04E6:
    WorkCmpConst 0x8023, 1
    VMJumpIf 1, L_04F9
    VMJump L_0505

L_04F9:
    WorkSetConst 0x8024, 707
    VMJump L_0524

L_0505:
    WorkCmpConst 0x8023, 2
    VMJumpIf 1, L_0518
    VMJump L_0524

L_0518:
    WorkSetConst 0x8024, 708
    VMJump L_0524

L_0524:
    CallTrainerBattle 0x8024, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_054B
    CallTrainerBattleEnd
    VMJump L_054D

L_054B:
    CallTrainerLose

L_054D:
    Cmd_02B5 0, 1
    ActorMsg 1024, 15, 251, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 789, 721, 4, 8, 1
    VMSleep 20
    ActorCmdExec 255, Movement_05D0
    ActorCmdWait
    ActorDelete 251
    BGMChangeMap
    WorkSetConst 0x4136, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_0598:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd

Movement_05B0:
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

Movement_05D0:
    Move 32, 1
    MoveEnd

Movement_05D8:
    Move 33, 1
    MoveEnd

Movement_05E0:
    Move 34, 1
    MoveEnd

Movement_05E8:
    Move 35, 1
    MoveEnd
    FinishAllEvents
    VMNop2
    PokePartyGetSpecies 0, 49
    VMNop2
    PokePartyGetSpecies 0, 50
    VMNop2
    PokePartyGetSpecies 0, 51
    VMNop2
    PokePartyGetSpecies 0, 49
    VMHalt
    .byte 0xfe
    .balign 4, 0

Movement_0618:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Movement_0628:
    Move 35, 1
    Move 34, 1
    MoveEnd

Movement_0634:
    Move 32, 1
    Move 65, 1
    Move 15, 2
    Move 32, 1
    MoveEnd

Movement_0648:
    Move 65, 1
    Move 15, 2
    Move 32, 1
    MoveEnd

Movement_0658:
    Move 32, 1
    Move 65, 1
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_066C:
    Move 65, 1
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_067C:
    Move 32, 1
    Move 65, 1
    Move 14, 1
    Move 32, 1
    MoveEnd

Movement_0690:
    Move 65, 1
    Move 14, 1
    Move 32, 1
    MoveEnd

Movement_06A0:
    Move 32, 1
    Move 65, 1
    Move 14, 2
    Move 32, 1
    MoveEnd

Movement_06B4:
    Move 65, 1
    Move 14, 2
    Move 32, 1
    MoveEnd

Movement_06C4:
    Move 32, 1
    Move 65, 1
    Move 14, 3
    Move 32, 1
    MoveEnd

Movement_06D8:
    Move 65, 1
    Move 14, 3
    Move 32, 1
    MoveEnd
    Move 12, 10
    MoveEnd
