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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_24:
    VMStackPush 0x40ac
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_00C3
    ObjInitNPCGPos 8, 3, 240, 0, 671
    ObjInitNPCGPos 7, 3, 240, 0, 669
    ObjInitNPCGPos 9, 2, 240, 0, 670
    ObjInitNPCGPos 11, 2, 241, 0, 671
    ObjInitNPCGPos 10, 2, 241, 0, 669
    VMJump L_00EE

L_00C3:
    VMStackPush 0x40ac
    VMStackPushConst 7
    VMStackCmp 1
    VMJumpIf 255, L_00EE
    ObjInitNPCGPos 1, 3, 241, 0, 670
    ObjInitNPCGPos 0, 2, 243, 0, 670

L_00EE:
    VMHalt

Script_14:
    VMStackPush 0x40ac
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_013F
    ActorSetGPos 8, 240, 0, 671, 3
    ActorSetGPos 7, 240, 0, 669, 3
    ActorSetGPos 9, 240, 0, 670, 2
    ActorSetGPos 11, 241, 0, 671, 2
    ActorSetGPos 10, 241, 0, 669, 2

L_013F:
    VMHalt

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xd28000, 0, 0x28b8000, 45
    EvCameraWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0214
    ActorCmdWait
    ActorMsg 1024, 1, 1, 4, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0254
    ActorCmdWait
    ActorMsg 1024, 2, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_01E8
    ActorCmdWait
    ActorDelete 0
    ActorMsg 1024, 3, 1, 4, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_01FC
    ActorCmdWait
    ActorDelete 1
    EvCameraMoveToDefault 45
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    WorkSetConst 0x40ac, 2
    FlagSet 726
    FlagSet 2489
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_01E8:
    Move 15, 5
    Move 12, 10
    MoveEnd
    Move 39, 4
    MoveEnd

Movement_01FC:
    Move 13, 8
    MoveEnd

Movement_0204:
    Move 13, 1
    MoveEnd

Movement_020C:
    Move 12, 1
    MoveEnd

Movement_0214:
    Move 15, 1
    MoveEnd

Movement_021C:
    Move 14, 1
    MoveEnd
    Move 0, 1
    MoveEnd

Movement_022C:
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0

Movement_023C:
    Move 3, 1
    MoveEnd

Movement_0244:
    Move 32, 1
    MoveEnd

Movement_024C:
    Move 33, 1
    MoveEnd

Movement_0254:
    Move 34, 1
    MoveEnd

Movement_025C:
    Move 35, 1
    MoveEnd

Movement_0264:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Movement_0274:
    Move 161, 1
    MoveEnd
    Move 160, 1
    MoveEnd

Script_2:
    ActorsPauseAll
    VMStackPushFlag 492
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02B3
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_02EB

L_02B3:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 25, 2, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 4
    WorkSet 0x8001, 5
    RTCallGlobal 2806
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 492

L_02EB:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 27, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    PlayerGetGPos 0x8020, 0x8021
    WorkCmpConst 0x8020, 215
    VMJumpIf 1, L_0396
    VMJump L_03AE

L_0396:
    ActorCmdExec 6, Movement_04C4
    ActorCmdWait
    ActorCmdExec 255, Movement_025C
    VMJump L_042F

L_03AE:
    WorkCmpConst 0x8020, 216
    VMJumpIf 1, L_03C1
    VMJump L_03D9

L_03C1:
    ActorCmdExec 6, Movement_04D4
    ActorCmdWait
    ActorCmdExec 255, Movement_025C
    VMJump L_042F

L_03D9:
    WorkCmpConst 0x8020, 218
    VMJumpIf 1, L_03EC
    VMJump L_0404

L_03EC:
    ActorCmdExec 6, Movement_04E0
    ActorCmdWait
    ActorCmdExec 255, Movement_0254
    VMJump L_042F

L_0404:
    WorkCmpConst 0x8020, 219
    VMJumpIf 1, L_0417
    VMJump L_042F

L_0417:
    ActorCmdExec 6, Movement_04EC
    ActorCmdWait
    ActorCmdExec 255, Movement_0254
    VMJump L_042F

L_042F:
    ActorCmdWait
    ActorMsg 1024, 5, 6, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0204
    ActorCmdWait
    WorkCmpConst 0x8020, 215
    VMJumpIf 1, L_045C
    VMJump L_046A

L_045C:
    ActorCmdExec 6, Movement_04FC
    VMJump L_04B9

L_046A:
    WorkCmpConst 0x8020, 216
    VMJumpIf 1, L_048A
    WorkCmpConst 0x8020, 218
    VMJumpIf 1, L_048A
    VMJump L_0498

L_048A:
    ActorCmdExec 6, Movement_022C
    VMJump L_04B9

L_0498:
    WorkCmpConst 0x8020, 219
    VMJumpIf 1, L_04AB
    VMJump L_04B9

L_04AB:
    ActorCmdExec 6, Movement_0508
    VMJump L_04B9

L_04B9:
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_04C4:
    Move 2, 1
    Move 75, 1
    Move 14, 1
    MoveEnd

Movement_04D4:
    Move 2, 1
    Move 75, 1
    MoveEnd

Movement_04E0:
    Move 3, 1
    Move 75, 1
    MoveEnd

Movement_04EC:
    Move 3, 1
    Move 75, 1
    Move 15, 1
    MoveEnd

Movement_04FC:
    Move 15, 1
    Move 33, 1
    MoveEnd

Movement_0508:
    Move 14, 1
    Move 33, 1
    MoveEnd

Script_9:
    ActorsPauseAll
    MEPlay 1327
    SystemMsg 6, 2
    MEWait
    WordSetPlayerName 0
    SystemMsg 7, 2
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    CallXTransceiver 1, 0
    FadeInBlackQ
    FadeWait
    WorkSetConst 0x40ac, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    VMCall L_0555
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0555:
    BGMPlay 1266
    ActorMsg 1024, 8, 7, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 8, Movement_0214
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 10, 8, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 11, 11, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 12, 10, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 13, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_021C
    VMSleep 8
    ActorCmdExec 11, Movement_021C
    ActorCmdExec 10, Movement_021C
    ActorCmdWait
    VMSleep 20
    ActorCmdExec 8, Movement_0214
    ActorCmdExec 7, Movement_0214
    ActorCmdWait
    ActorCmdExec 8, Movement_0988
    ActorCmdWait
    ActorMsg 1024, 14, 8, 0, 0
    MsgWinCloseAll
    BGMChangeMap
    WorkSetConst 0x40ac, 5
    VMReturn

Script_11:
    ActorsPauseAll
    VMStackPush 0x40ac
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_064C
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 7, Movement_025C
    ActorCmdWait
    VMJump L_0666

L_064C:
    SEPlay 1351
    ActorWalkRoute 255, 239, 670, 0, 8, 1
    ActorCmdWait
    VMCall L_0555

L_0666:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    VMStackPush 0x40ac
    VMStackPushConst 5
    VMStackCmp 1
    VMJumpIf 255, L_069F
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    SEPlay 1351
    ParentActorMsg 1024, 16, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMJump L_0703

L_069F:
    SEPlay 1351
    WorkSetConst 0x8022, 0
    PlayerGetDir 0x8022
    WorkCmpConst 0x8022, 3
    VMJumpIf 1, L_06C0
    VMJump L_06D4

L_06C0:
    ActorWalkRoute 255, 239, 670, 0, 8, 1
    VMJump L_06FB

L_06D4:
    WorkCmpConst 0x8022, 1
    VMJumpIf 1, L_06E7
    VMJump L_06FB

L_06E7:
    ActorWalkRoute 255, 239, 670, 0, 8, 0
    VMJump L_06FB

L_06FB:
    ActorCmdWait
    VMCall L_0555

L_0703:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_091B
    TrainerBGMPlayPush 751
    ParentActorMsg 1024, 18, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 690, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0769
    CallTrainerBattleEnd
    VMJump L_076B

L_0769:
    CallTrainerLose

L_076B:
    ActorCmdExec 8, Movement_023C
    ActorCmdExec 7, Movement_023C
    ActorCmdWait
    ActorCmdExec 9, Movement_09B0
    VMSleep 8
    ActorCmdExec 11, Movement_09B0
    ActorCmdExec 10, Movement_09B0
    ActorCmdWait
    ParentActorMsg 1024, 20, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_09C0
    ActorCmdWait
    ActorCmdExec 9, Movement_09CC
    ActorCmdExec 255, Movement_0990
    ActorCmdWait
    ActorWalkRoute 9, 228, 670, 1, 4, 0
    ActorWalkRoute 10, 228, 670, 1, 4, 1
    VMSleep 4
    ActorWalkRoute 11, 228, 670, 1, 4, 1
    VMSleep 16
    ActorCmdExec 255, Movement_0254
    ActorCmdExec 7, Movement_0254
    ActorCmdExec 8, Movement_0254
    ActorCmdWait
    ActorDelete 9
    ActorDelete 10
    ActorDelete 11
    ActorCmdExec 8, Movement_021C
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 21, 8, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 22, 7, 0, 0
    MsgWinCloseAll
    ActorCmdExec 7, Movement_0930
    ActorCmdWait
    ActorWalkRoute 7, 237, 669, 0, 8, 1
    ActorCmdWait
    ActorMsg 1024, 23, 7, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 420
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorWalkRoute 7, 228, 669, 0, 4, 0
    ActorCmdWait
    ActorDelete 7
    ActorWalkRoute 8, 238, 670, 0, 8, 1
    ActorCmdWait
    ActorCmdExec 8, Movement_0244
    VMSleep 8
    ActorCmdExec 255, Movement_024C
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 24, 8, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 8, 228, 670, 0, 4, 0
    VMSleep 8
    ActorCmdExec 255, Movement_0254
    ActorCmdWait
    ActorDelete 8
    SEWait
    WorkSetConst 0x40ac, 6
    FlagSet 724
    FlagReset 701
    FlagReset 702
    FlagSet 2558
    WorkSetConst 0x40ab, 5
    VMJump L_0929

L_091B:
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0929:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0930:
    Move 17, 1
    Move 18, 5
    Move 10, 1
    Move 63, 2
    Move 3, 1
    MoveEnd
    Move 13, 1
    Move 15, 3
    MoveEnd
    Move 14, 8
    MoveEnd
    Move 79, 2
    MoveEnd
    Move 14, 1
    Move 32, 1
    MoveEnd
    VMStackDiv
    VMSleep 12
    VMHalt
    .byte 0xfe
    .balign 4, 0
    Move 12, 1
    Move 69, 1
    MoveEnd

Movement_0988:
    Move 100, 1
    MoveEnd

Movement_0990:
    Move 71, 1
    Move 18, 1
    Move 72, 1
    Move 1, 1
    Move 71, 1
    Move 16, 1
    Move 72, 1
    MoveEnd

Movement_09B0:
    Move 71, 1
    Move 11, 1
    Move 72, 1
    MoveEnd

Movement_09C0:
    Move 38, 4
    Move 18, 1
    MoveEnd

Movement_09CC:
    Move 18, 2
    MoveEnd

Script_15:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 41, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 42, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 43, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 505, 0
    ParentActorMsg 1024, 30, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 32, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 33, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 34, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0xf18000, 0, 0x29e8000, 20
    EvCameraWait
    ActorMsg 1024, 36, 1, 4, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0274
    ActorCmdWait
    ActorMsg 1024, 37, 0, 6, 0
    MsgWinCloseAll
    ActorMsg 1024, 38, 1, 4, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0254
    ActorCmdWait
    ActorCmdExec 1, Movement_0264
    ActorCmdWait
    PlayerGetGPos 0x8020, 0x8021
    WorkCmpConst 0x8021, 669
    VMJumpIf 1, L_0B37
    VMJump L_0B43

L_0B37:
    WorkSetConst 0x8021, 670
    VMJump L_0B81

L_0B43:
    WorkCmpConst 0x8021, 670
    VMJumpIf 1, L_0B56
    VMJump L_0B62

L_0B56:
    WorkSetConst 0x8020, 240
    VMJump L_0B81

L_0B62:
    WorkCmpConst 0x8021, 671
    VMJumpIf 1, L_0B75
    VMJump L_0B81

L_0B75:
    WorkSetConst 0x8021, 670
    VMJump L_0B81

L_0B81:
    ActorWalkRoute 1, 0x8020, 0x8021, 1, 8, 1
    ActorCmdWait
    PlayerGetGPos 0x8020, 0x8021
    WorkCmpConst 0x8021, 669
    VMJumpIf 1, L_0BAA
    VMJump L_0BC6

L_0BAA:
    ActorCmdExec 1, Movement_0244
    VMSleep 8
    ActorCmdExec 255, Movement_024C
    ActorCmdWait
    VMJump L_0C0E

L_0BC6:
    WorkCmpConst 0x8021, 670
    VMJumpIf 1, L_0BD9
    VMJump L_0BDF

L_0BD9:
    VMJump L_0C0E

L_0BDF:
    WorkCmpConst 0x8021, 671
    VMJumpIf 1, L_0BF2
    VMJump L_0C0E

L_0BF2:
    ActorCmdExec 1, Movement_024C
    VMSleep 8
    ActorCmdExec 255, Movement_0244
    ActorCmdWait
    VMJump L_0C0E

L_0C0E:
    WordSetLoadRivalName 1
    ActorMsg 1024, 39, 1, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8020, 0x8021
    WorkCmpConst 0x8021, 669
    VMJumpIf 1, L_0C38
    VMJump L_0C44

L_0C38:
    WorkSetConst 0x8021, 670
    VMJump L_0C82

L_0C44:
    WorkCmpConst 0x8021, 670
    VMJumpIf 1, L_0C57
    VMJump L_0C63

L_0C57:
    WorkSetConst 0x8021, 669
    VMJump L_0C82

L_0C63:
    WorkCmpConst 0x8021, 671
    VMJumpIf 1, L_0C76
    VMJump L_0C82

L_0C76:
    WorkSetConst 0x8021, 670
    VMJump L_0C82

L_0C82:
    ActorWalkRoute 1, 228, 0x8021, 1, 8, 1
    VMSleep 12
    ActorCmdExec 255, Movement_0254
    ActorCmdWait
    ActorDelete 1
    ActorMsg 1024, 40, 0, 6, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_025C
    ActorWalkRoute 0, 242, 669, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_020C
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    EvCameraMoveToDefault 20
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    FlagSet 726
    FlagReset 763
    WorkSetConst 0x40ac, 8
    FlagReset 722
    FlagReset 723
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
