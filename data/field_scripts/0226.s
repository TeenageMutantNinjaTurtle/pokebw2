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

Script_14:
    WorkSetConst 0x8020, 0
    RTCGetSeason 0x8020
    WorkCmpConst 0x418c, 1
    VMJumpIf 1, L_0057
    VMJump L_0076

L_0057:
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0070
    WorkSetConst 0x418c, 0

L_0070:
    VMJump L_010C

L_0076:
    WorkCmpConst 0x418c, 2
    VMJumpIf 1, L_0089
    VMJump L_00A8

L_0089:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_00A2
    WorkSetConst 0x418c, 0

L_00A2:
    VMJump L_010C

L_00A8:
    WorkCmpConst 0x418c, 3
    VMJumpIf 1, L_00BB
    VMJump L_00DA

L_00BB:
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 5
    VMJumpIf 255, L_00D4
    WorkSetConst 0x418c, 0

L_00D4:
    VMJump L_010C

L_00DA:
    WorkCmpConst 0x418c, 4
    VMJumpIf 1, L_00ED
    VMJump L_010C

L_00ED:
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 5
    VMJumpIf 255, L_0106
    WorkSetConst 0x418c, 0

L_0106:
    VMJump L_010C

L_010C:
    FlagReset 2559
    WorkSetConst 0x8020, 0
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 23, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 24, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 25, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 0, 1, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 3, 4, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    WorkSetConst 0x8021, 0
    RTCGetSeason 0x8021
    VMStackPush 0x8021
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0287
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_029B

L_0287:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose

L_029B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    FlagReset 925
    FlagReset 926
    FlagReset 927
    ActorAdd 10
    ActorAdd 11
    ActorAdd 12
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    PlayerGetGPos 0x8022, 0x8023
    WorkCmpConst 0x8023, 195
    VMJumpIf 1, L_02E0
    VMJump L_030A

L_02E0:
    ActorSetGPos 10, 219, 3, 195, 2
    ActorSetGPos 11, 221, 3, 196, 2
    ActorSetGPos 12, 221, 3, 195, 2
    VMJump L_0347

L_030A:
    WorkCmpConst 0x8023, 196
    VMJumpIf 1, L_031D
    VMJump L_0347

L_031D:
    ActorSetGPos 10, 219, 3, 196, 2
    ActorSetGPos 11, 221, 3, 195, 2
    ActorSetGPos 12, 221, 3, 196, 2
    VMJump L_0347

L_0347:
    ActorCmdExec 10, Movement_0828
    ActorCmdExec 11, Movement_0828
    ActorCmdExec 12, Movement_0828
    ActorCmdWait
    ActorCmdExec 255, Movement_0808
    ActorCmdWait
    BGMPlay 1239
    VMStackPushFlag 406
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0398
    ActorMsg 1024, 12, 10, 0, 0
    FlagSet 406
    VMJump L_03A4

L_0398:
    ActorMsg 1024, 13, 10, 0, 0

L_03A4:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06C4
    VMCall L_070A
    ActorMsg 1024, 14, 10, 0, 0
    MsgWinCloseAll
    ActorCmdExec 10, Movement_07C0
    ActorCmdWait
    CallTrainerBattle 687, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0400
    CallTrainerBattleEnd
    VMJump L_0408

L_0400:
    VMCall L_0792
    CallTrainerLose

L_0408:
    ActorCmdExec 10, Movement_0844
    ActorCmdWait
    ActorDelete 10
    ActorCmdExec 11, Movement_0844
    ActorCmdWait
    WorkCmpConst 0x8023, 195
    VMJumpIf 1, L_0433
    VMJump L_0445

L_0433:
    ActorSetGPos 11, 219, 3, 195, 2
    VMJump L_046A

L_0445:
    WorkCmpConst 0x8023, 196
    VMJumpIf 1, L_0458
    VMJump L_046A

L_0458:
    ActorSetGPos 11, 219, 3, 196, 2
    VMJump L_046A

L_046A:
    ActorCmdExec 11, Movement_0838
    ActorCmdWait
    FlagSet 925
    WorkSetConst 0x8024, 0
    PokePartyGetCount 0x8024, 2
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 4
    VMJumpIf 255, L_068E
    ActorMsg 1024, 16, 11, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0658
    ActorMsg 1024, 17, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_07C0
    ActorCmdWait
    CallTrainerBattle 688, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04F9
    CallTrainerBattleEnd
    VMJump L_0501

L_04F9:
    VMCall L_0792
    CallTrainerLose

L_0501:
    ActorCmdExec 11, Movement_0844
    ActorCmdWait
    ActorDelete 11
    FlagSet 926
    ActorCmdExec 12, Movement_0844
    ActorCmdWait
    WorkCmpConst 0x8023, 195
    VMJumpIf 1, L_0530
    VMJump L_0542

L_0530:
    ActorSetGPos 12, 219, 3, 195, 2
    VMJump L_0567

L_0542:
    WorkCmpConst 0x8023, 196
    VMJumpIf 1, L_0555
    VMJump L_0567

L_0555:
    ActorSetGPos 12, 219, 3, 196, 2
    VMJump L_0567

L_0567:
    ActorCmdExec 12, Movement_0838
    ActorCmdWait
    PokePartyGetCount 0x8024, 2
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 4
    VMJumpIf 255, L_0632
    ActorMsg 1024, 20, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_060C
    ActorMsg 1024, 21, 12, 0, 0
    MsgWinCloseAll
    ActorCmdExec 12, Movement_07C0
    ActorCmdWait
    CallTrainerBattle 689, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05EC
    CallTrainerBattleEnd
    VMJump L_05F4

L_05EC:
    VMCall L_0792
    CallTrainerLose

L_05F4:
    ActorCmdExec 12, Movement_0844
    ActorCmdWait
    ActorDelete 12
    FlagSet 927
    VMJump L_062C

L_060C:
    ActorMsg 1024, 22, 12, 0, 0
    MsgWinCloseAll
    ActorCmdExec 12, Movement_0844
    ActorCmdWait
    ActorDelete 12
    FlagSet 927

L_062C:
    VMJump L_0652

L_0632:
    ActorMsg 1024, 19, 12, 0, 0
    MsgWinCloseAll
    ActorCmdExec 12, Movement_0844
    ActorCmdWait
    ActorDelete 12
    FlagSet 927

L_0652:
    VMJump L_0688

L_0658:
    ActorMsg 1024, 18, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_0844
    ActorCmdExec 12, Movement_0844
    ActorCmdWait
    ActorDelete 11
    ActorDelete 12
    FlagSet 926
    FlagSet 927

L_0688:
    VMJump L_06BE

L_068E:
    ActorMsg 1024, 15, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_0844
    ActorCmdExec 12, Movement_0844
    ActorCmdWait
    ActorDelete 11
    ActorDelete 12
    FlagSet 926
    FlagSet 927

L_06BE:
    VMJump L_0702

L_06C4:
    MsgWinCloseAll
    FlagSet 925
    FlagSet 926
    FlagSet 927
    ActorCmdExec 10, Movement_0844
    ActorCmdExec 11, Movement_0844
    ActorCmdExec 12, Movement_0844
    ActorCmdWait
    ActorDelete 10
    ActorDelete 11
    ActorDelete 12
    ActorCmdExec 255, Movement_07B8
    ActorCmdWait

L_0702:
    BGMChangeMap
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_070A:
    WorkSetConst 0x8025, 0
    RTCGetSeason 0x8025
    WorkCmpConst 0x8025, 0
    VMJumpIf 1, L_0727
    VMJump L_0733

L_0727:
    WorkSetConst 0x418c, 1
    VMJump L_0790

L_0733:
    WorkCmpConst 0x8025, 1
    VMJumpIf 1, L_0746
    VMJump L_0752

L_0746:
    WorkSetConst 0x418c, 2
    VMJump L_0790

L_0752:
    WorkCmpConst 0x8025, 2
    VMJumpIf 1, L_0765
    VMJump L_0771

L_0765:
    WorkSetConst 0x418c, 3
    VMJump L_0790

L_0771:
    WorkCmpConst 0x8025, 3
    VMJumpIf 1, L_0784
    VMJump L_0790

L_0784:
    WorkSetConst 0x418c, 4
    VMJump L_0790

L_0790:
    VMReturn

L_0792:
    FlagSet 925
    FlagSet 926
    FlagSet 927
    VMReturn
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd

Movement_07B8:
    Move 14, 1
    MoveEnd

Movement_07C0:
    Move 18, 1
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
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_0808:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 71, 1
    Move 169, 1
    Move 72, 1
    MoveEnd

Movement_0828:
    Move 184, 1
    MoveEnd
    Move 185, 1
    MoveEnd

Movement_0838:
    Move 70, 1
    Move 184, 1
    MoveEnd

Movement_0844:
    Move 185, 1
    Move 69, 1
    MoveEnd
