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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

L_005A:
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0081
    ObjInitWarpGPos 6, 707, 0xfffc, 299
    VMJump L_008B

L_0081:
    ObjInitWarpGPos 5, 707, 0xfffc, 299

L_008B:
    VMReturn

Script_3:
    VMCall L_005A
    FlagSet 678
    WorkSetConst 0x8024, 0
    RTCGetSeason 0x8024
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C4
    FlagReset 678

L_00C4:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0321
    VMStackPush 0x4098
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4098
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0118
    FlagSet 684
    FlagSet 685
    FlagSet 687
    FlagSet 688
    FlagSet 689
    FlagReset 683
    VMJump L_031B

L_0118:
    VMStackPush 0x4098
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_031B
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2746
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_01E6
    FlagSet 683
    FlagSet 684
    FlagSet 685
    FlagSet 687
    FlagSet 688
    FlagSet 689
    FlagReset 683
    Random 0x8026, 2
    WorkGet 0x4166, 0x8026
    Random 0x8025, 4
    VMStackPush 0x8025
    VMStackPushConst 2
    VMStackCmp 3
    VMJumpIf 255, L_01A5
    FlagReset 684
    Random 0x8026, 5
    WorkGet 0x4167, 0x8026
    VMJump L_01A9

L_01A5:
    FlagSet 684

L_01A9:
    Random 0x8025, 2
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01D8
    FlagReset 685
    Random 0x8026, 5
    WorkGet 0x4168, 0x8026
    VMJump L_01DC

L_01D8:
    FlagSet 685

L_01DC:
    FlagSet 2746
    VMJump L_031B

L_01E6:
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 2746
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02E0
    FlagSet 683
    FlagSet 684
    FlagSet 685
    FlagSet 687
    FlagSet 688
    FlagSet 689
    Random 0x8026, 5
    WorkGet 0x4166, 0x8026
    FlagReset 683
    Random 0x8025, 4
    DebugPrint 0x8025
    VMStackPush 0x8025
    VMStackPushConst 2
    VMStackCmp 3
    VMJumpIf 255, L_0264
    FlagReset 687
    Random 0x8026, 5
    WorkGet 0x416a, 0x8026
    VMJump L_0268

L_0264:
    FlagSet 687

L_0268:
    Random 0x8025, 2
    DebugPrint 0x8025
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_029B
    FlagReset 688
    Random 0x8026, 5
    WorkGet 0x416b, 0x8026
    VMJump L_029F

L_029B:
    FlagSet 688

L_029F:
    Random 0x8025, 4
    DebugPrint 0x8025
    VMStackPush 0x8025
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_02D2
    FlagReset 689
    Random 0x8026, 5
    WorkGet 0x416c, 0x8026
    VMJump L_02D6

L_02D2:
    FlagSet 689

L_02D6:
    FlagSet 2746
    VMJump L_031B

L_02E0:
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_031B
    FlagSet 683
    FlagSet 684
    FlagSet 685
    FlagSet 687
    FlagSet 688
    FlagSet 689

L_031B:
    VMJump L_0339

L_0321:
    FlagSet 683
    FlagSet 684
    FlagSet 685
    FlagSet 687
    FlagSet 688
    FlagSet 689

L_0339:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 417
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0366
    FlagReset 944
    Cmd_0262 1, 41

L_0366:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    VMHalt

Script_16:
    VMCall L_005A
    VMHalt

Script_4:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    PlayerGetGPos 0x8021, 0x8022
    ActorNew 0x8021, 307, 1, 251, 291, 0
    BGMPlay 1237
    InfoMsg 0, 2
    ActorCmdExec 255, Movement_0B14
    ActorCmdWait
    InfoMsgClose_0039
    WorkAdd 0x8022, 2
    ActorWalkRoute 251, 0x8021, 0x8022, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 1, 251, 0, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03F8
    CallTrainerBattle 378, 0, 0
    VMJump L_0421

L_03F8:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0419
    CallTrainerBattle 379, 0, 0
    VMJump L_0421

L_0419:
    CallTrainerBattle 380, 0, 0

L_0421:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0440
    CallTrainerBattleEnd
    VMJump L_0442

L_0440:
    CallTrainerLose

L_0442:
    ActorMsg 1024, 2, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0B24
    ActorCmdWait
    ActorMsg 1024, 3, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0B0C
    ActorCmdWait
    ActorMsg 1024, 4, 251, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 752
    VMStackCmp 2
    VMJumpIf 255, L_04A1
    ActorCmdExec 251, Movement_04E4
    VMJump L_04A9

L_04A1:
    ActorCmdExec 251, Movement_04D8

L_04A9:
    VMSleep 12
    ActorCmdExec 255, Movement_0B0C
    ActorCmdWait
    SEPlay 1369
    ActorDelete 251
    SEWait
    BGMChangeMap
    WorkSetConst 0x40cd, 1
    Cmd_0262 1, 21
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04D8:
    Move 15, 1
    Move 12, 5
    MoveEnd

Movement_04E4:
    Move 14, 1
    Move 12, 5
    MoveEnd

Script_12:
    ActorsPauseAll
    MEPlay 1327
    SystemMsg 33, 2
    MEWait
    WordSetPlayerName 0
    SystemMsg 34, 2
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    CallXTransceiver 7, 0
    FadeInBlackQ
    FadeWait
    WorkSetConst 0x4146, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 11, 0, 0, 1
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    Cmd_02D5 18, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0576
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_058A

L_0576:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose

L_058A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 19, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
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
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 20, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    VMStackPushFlag 414
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0800
    ParentActorMsg 1024, 5, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 425
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 414
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ParentActorMsg 1024, 6, 0, 0
    ParentActorMsg 1024, 7, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_07E6
    ParentActorMsg 1024, 8, 0, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0719
    CallTrainerBattle 693, 0, 0
    VMJump L_0742

L_0719:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_073A
    CallTrainerBattle 694, 0, 0
    VMJump L_0742

L_073A:
    CallTrainerBattle 695, 0, 0

L_0742:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0761
    CallTrainerBattleEnd
    VMJump L_0763

L_0761:
    CallTrainerLose

L_0763:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 300
    VMStackCmp 1
    VMJumpIf 255, L_07A2
    ActorWalkRoute 6, 752, 296, 1, 8, 0
    VMJump L_07B0

L_07A2:
    ActorWalkRoute 6, 753, 296, 1, 8, 1

L_07B0:
    VMSleep 24
    ActorCmdExec 255, Movement_0B0C
    ActorCmdWait
    SEPlay 1369
    ActorDelete 6
    SEWait
    FlagSet 417
    FlagSet 944
    FlagReset 974
    Cmd_0262 1, 42
    VMCall L_093B
    VMJump L_07FA

L_07E6:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_07FA:
    VMJump L_0935

L_0800:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ParentActorMsg 1024, 7, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0921
    ParentActorMsg 1024, 8, 0, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0854
    CallTrainerBattle 693, 0, 0
    VMJump L_087D

L_0854:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0875
    CallTrainerBattle 694, 0, 0
    VMJump L_087D

L_0875:
    CallTrainerBattle 695, 0, 0

L_087D:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_089C
    CallTrainerBattleEnd
    VMJump L_089E

L_089C:
    CallTrainerLose

L_089E:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 300
    VMStackCmp 1
    VMJumpIf 255, L_08DD
    ActorWalkRoute 6, 752, 296, 1, 8, 0
    VMJump L_08EB

L_08DD:
    ActorWalkRoute 6, 753, 296, 1, 8, 1

L_08EB:
    VMSleep 24
    ActorCmdExec 255, Movement_0B0C
    ActorCmdWait
    SEPlay 1369
    ActorDelete 6
    SEWait
    FlagSet 417
    FlagSet 944
    FlagReset 974
    Cmd_0262 1, 42
    VMCall L_093B
    VMJump L_0935

L_0921:
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0935:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_093B:
    FlagReset 979
    ActorAdd 7
    ActorSetGPos 7, 764, 0xfffb, 304, 2
    PlayerGetGPos 0x8021, 0x8022
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkCmpConst 0x8021, 752
    VMJumpIf 1, L_0974
    VMJump L_0986

L_0974:
    WorkSetConst 0x8027, 753
    WorkSetConst 0x8028, 301
    VMJump L_09EF

L_0986:
    WorkCmpConst 0x8021, 753
    VMJumpIf 1, L_0999
    VMJump L_09CA

L_0999:
    WorkSetConst 0x8027, 753
    VMStackPush 0x8022
    VMStackPushConst 302
    VMStackCmp 1
    VMJumpIf 255, L_09BE
    WorkSetConst 0x8028, 303
    VMJump L_09C4

L_09BE:
    WorkSetConst 0x8028, 301

L_09C4:
    VMJump L_09EF

L_09CA:
    WorkCmpConst 0x8021, 754
    VMJumpIf 1, L_09DD
    VMJump L_09EF

L_09DD:
    WorkSetConst 0x8027, 753
    WorkSetConst 0x8028, 301
    VMJump L_09EF

L_09EF:
    ActorWalkRoute 7, 0x8027, 0x8028, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_0B2C
    ActorCmdWait
    WorkCmpConst 0x8021, 752
    VMJumpIf 1, L_0A1C
    VMJump L_0A32

L_0A1C:
    ActorCmdExec 255, Movement_0B24
    ActorCmdExec 7, Movement_0B1C
    VMJump L_0A84

L_0A32:
    WorkCmpConst 0x8021, 753
    VMJumpIf 1, L_0A45
    VMJump L_0A5B

L_0A45:
    ActorCmdExec 255, Movement_0B14
    ActorCmdExec 7, Movement_0B0C
    VMJump L_0A84

L_0A5B:
    WorkCmpConst 0x8021, 754
    VMJumpIf 1, L_0A6E
    VMJump L_0A84

L_0A6E:
    ActorCmdExec 255, Movement_0B1C
    ActorCmdExec 7, Movement_0B24
    VMJump L_0A84

L_0A84:
    ActorCmdWait
    ActorMsg 1024, 22, 7, 0, 0
    MsgWinCloseAll
    WordSetPlayerName 0
    SystemMsg 23, 2
    MsgWaitAdvance
    InfoMsgClose
    ActorMsg 1024, 24, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMStackPush 0x418f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0ACA
    WorkSetConst 0x418f, 1

L_0ACA:
    VMReturn
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

Movement_0B0C:
    Move 32, 1
    MoveEnd

Movement_0B14:
    Move 33, 1
    MoveEnd

Movement_0B1C:
    Move 34, 1
    MoveEnd

Movement_0B24:
    Move 35, 1
    MoveEnd

Movement_0B2C:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x418f, 0
    VMJumpIf 1, L_0B57
    VMJump L_0B61

L_0B57:
    DebugPrint 0x418f
    VMJump L_0D80

L_0B61:
    WorkCmpConst 0x418f, 1
    VMJumpIf 1, L_0B74
    VMJump L_0B88

L_0B74:
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0D80

L_0B88:
    WorkCmpConst 0x418f, 2
    VMJumpIf 1, L_0B9B
    VMJump L_0BB9

L_0B9B:
    ParentActorMsg 1024, 25, 0, 0
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0D80

L_0BB9:
    WorkCmpConst 0x418f, 3
    VMJumpIf 1, L_0BCC
    VMJump L_0BEA

L_0BCC:
    ParentActorMsg 1024, 26, 0, 0
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0D80

L_0BEA:
    WorkCmpConst 0x418f, 4
    VMJumpIf 1, L_0BFD
    VMJump L_0C2B

L_0BFD:
    ParentActorMsg 1024, 30, 0, 0
    ParentActorMsg 1024, 27, 0, 0
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x418f, 5
    VMJump L_0D80

L_0C2B:
    WorkCmpConst 0x418f, 5
    VMJumpIf 1, L_0C3E
    VMJump L_0C5C

L_0C3E:
    ParentActorMsg 1024, 27, 0, 0
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0D80

L_0C5C:
    WorkCmpConst 0x418f, 6
    VMJumpIf 1, L_0C6F
    VMJump L_0C9D

L_0C6F:
    ParentActorMsg 1024, 30, 0, 0
    ParentActorMsg 1024, 28, 0, 0
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x418f, 7
    VMJump L_0D80

L_0C9D:
    WorkCmpConst 0x418f, 7
    VMJumpIf 1, L_0CB0
    VMJump L_0CCE

L_0CB0:
    ParentActorMsg 1024, 28, 0, 0
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0D80

L_0CCE:
    WorkCmpConst 0x418f, 8
    VMJumpIf 1, L_0CE1
    VMJump L_0D80

L_0CE1:
    ParentActorMsg 1024, 30, 0, 0
    ParentActorMsg 1024, 29, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 89
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 32, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 300
    VMStackCmp 1
    VMJumpIf 255, L_0D50
    ActorWalkRoute 7, 752, 296, 1, 8, 0
    VMJump L_0D5E

L_0D50:
    ActorWalkRoute 7, 753, 296, 1, 8, 1

L_0D5E:
    VMSleep 24
    ActorCmdExec 255, Movement_0B0C
    ActorCmdWait
    SEPlay 1369
    ActorDelete 7
    SEWait
    FlagSet 979
    VMJump L_0D80

L_0D80:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
