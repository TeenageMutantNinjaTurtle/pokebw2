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
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0

Script_1:
    RTCGetDayPart 0x8023
    VMStackPush 0x8023
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_009B
    FlagSet 787
    FlagSet 780
    VMJump L_00A3

L_009B:
    FlagReset 787
    FlagReset 780

L_00A3:
    VMStackPush 0x40cc
    VMStackPushConst 4
    VMStackCmp 5
    VMJumpIf 255, L_00BE
    DebugPrint 2323
    FlagSet 780

L_00BE:
    VMStackPush 0x40cc
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_00E9
    ObjInitNPCGPos 6, 1, 655, 0, 170
    ObjInitNPCGPos 9, 0, 655, 0, 171

L_00E9:
    VMStackPush 0x40ce
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0120
    ObjInitNPCGPos 12, 2, 647, 0, 186
    ObjInitNPCGPos 10, 3, 645, 0, 186
    ObjInitNPCGPos 11, 3, 645, 0, 185

L_0120:
    VMHalt

Script_2:
    VMStackPush 0x40cc
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_014D
    ActorSetGPos 6, 655, 0, 170, 1
    ActorSetGPos 9, 655, 0, 171, 0

L_014D:
    VMStackPush 0x40ce
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0184
    ActorSetGPos 12, 647, 0, 186, 2
    ActorSetGPos 10, 645, 0, 186, 3
    ActorSetGPos 11, 645, 0, 185, 3

L_0184:
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x40cc, 1
    FlagSet 960
    FlagSet 776
    FlagSet 2482
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 667
    VMStackCmp 1
    VMJumpIf 255, L_01DD
    ActorWalkRoute 6, 664, 171, 1, 8, 0
    ActorWalkRoute 9, 664, 170, 1, 8, 0
    ActorCmdWait
    WorkSetConst 0x8025, 0
    VMJump L_0219

L_01DD:
    ActorSetGPos 6, 669, 0, 173, 1
    ActorSetGPos 9, 670, 0, 173, 1
    ActorWalkRoute 6, 669, 181, 1, 8, 1
    ActorWalkRoute 9, 670, 181, 1, 8, 1
    ActorCmdWait
    WorkSetConst 0x8025, 3

L_0219:
    WordSetPlayerName 0
    ActorMsg 1024, 0, 6, 0x8025, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 667
    VMStackCmp 1
    VMJumpIf 255, L_029F
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0258
    PlayerSetSpecialSequence 1

L_0258:
    VMStackPush 0x8022
    VMStackPushConst 171
    VMStackCmp 1
    VMJumpIf 255, L_027F
    ActorWalkRoute 255, 666, 171, 1, 8, 0
    VMJump L_0297

L_027F:
    ActorWalkRoute 255, 666, 171, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_0F84

L_0297:
    ActorCmdWait
    VMJump L_0301

L_029F:
    ActorCmdExec 255, Movement_0FDC
    ActorCmdWait
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02C4
    PlayerSetSpecialSequence 1

L_02C4:
    VMStackPush 0x8021
    VMStackPushConst 669
    VMStackCmp 1
    VMJumpIf 255, L_02E7
    ActorCmdExec 255, Movement_0F8C
    ActorCmdWait
    VMJump L_0301

L_02E7:
    ActorWalkRoute 255, 669, 183, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_0F8C
    ActorCmdWait

L_0301:
    ActorMsg 1024, 1, 9, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 2, 6, 0x8025, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 667
    VMStackCmp 1
    VMJumpIf 255, L_033E
    ActorCmdExec 9, Movement_0F94
    VMJump L_0346

L_033E:
    ActorCmdExec 9, Movement_0F84

L_0346:
    ActorCmdWait
    ActorMsg 1024, 3, 9, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 4, 6, 0x8025, 0
    MsgWinCloseAll
    RTCGetDayPart 0x8023
    VMStackPush 0x8023
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0391
    VMJump L_039F

L_0391:
    ActorNew 652, 170, 1, 251, 29, 0

L_039F:
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 171
    VMStackCmp 1
    VMJumpIf 255, L_03D8
    ActorCmdExec 6, Movement_0EEC
    ActorCmdExec 9, Movement_0EF8
    ActorCmdExec 255, Movement_0F0C
    ActorCmdWait
    VMJump L_03F2

L_03D8:
    ActorCmdExec 6, Movement_0F28
    ActorCmdExec 9, Movement_0F38
    ActorCmdExec 255, Movement_0F50
    ActorCmdWait

L_03F2:
    RTCGetDayPart 0x8023
    VMStackPush 0x8023
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 4
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_046F
    ActorMsg 1024, 8, 6, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 6, 652, 170, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 6, Movement_0F8C
    ActorCmdWait
    BMCreateHandleByGPos 0x8024, 1, 652, 169
    BMHndAudioVisualAnmPlay 0x8024, 0
    BMHndAnmWait 0x8024
    ActorCmdExec 6, Movement_0FB4
    ActorCmdWait
    SEPlay 1369
    ActorDelete 6
    SEWait
    VMJump L_04F1

L_046F:
    ActorMsg 1024, 5, 251, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorMsg 1024, 6, 6, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 7, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0F8C
    ActorCmdWait
    BMCreateHandleByGPos 0x8024, 1, 652, 169
    BMHndAudioVisualAnmPlay 0x8024, 0
    BMHndAnmWait 0x8024
    ActorCmdExec 251, Movement_0FB4
    ActorCmdWait
    SEPlay 1369
    ActorDelete 251
    SEWait
    ActorWalkRoute 6, 652, 170, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 6, Movement_0FB4
    ActorCmdWait
    ActorDelete 6
    SEPlay 1369
    SEWait

L_04F1:
    ActorWalkRoute 255, 652, 170, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_0FB4
    ActorCmdWait
    RTReserveScript 3
    FlagSet 780
    MapChangeWarp 409, 6, 9, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    WorkSetConst 0x40cc, 3
    ActorWalkRoute 255, 653, 170, 1, 8, 1
    ActorCmdWait
    ActorMsg 1024, 9, 6, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 10, 9, 0, 0
    MsgWinCloseAll
    ActorMsgVersioned 1024, 12, 11, 6, 1, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_0F84
    VMSleep 8
    ActorCmdExec 9, Movement_0F84
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsgVersioned 1024, 14, 13, 6, 1, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_05BB
    ActorMsgVersioned 1024, 17, 15, 6, 1, 0
    MsgWinCloseAll
    VMJump L_05CE

L_05BB:
    WordSetPlayerName 0
    ActorMsgVersioned 1024, 18, 16, 6, 1, 0
    MsgWinCloseAll

L_05CE:
    ActorCmdExec 9, Movement_0F8C
    VMSleep 8
    ActorCmdExec 6, Movement_0F94
    ActorCmdWait
    ActorMsg 1024, 19, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_0FCC
    ActorCmdWait
    VMSleep 20
    ActorCmdExec 6, Movement_0FEC
    ActorCmdWait
    VMSleep 30
    ActorMsg 1024, 20, 6, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 21, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_0FC4
    ActorCmdWait
    ActorMsgVersioned 1024, 23, 22, 6, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 24, 9, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 25, 6, 1, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_0F84
    VMSleep 8
    ActorCmdExec 6, Movement_0F84
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 26, 6, 1, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_0F8C
    ActorCmdWait
    ActorMsg 1024, 27, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_0F60
    ActorCmdWait
    ActorDelete 6
    ActorWalkRoute 9, 653, 171, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 9, Movement_0F8C
    VMSleep 3
    ActorCmdExec 255, Movement_0F94
    ActorCmdWait
    ActorMsg 1024, 28, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_0F94
    ActorCmdWait
    ActorMsg 1024, 29, 9, 0, 0
    MsgWinCloseAll
    ActorCmdExec 9, Movement_0F6C
    ActorCmdWait
    ActorDelete 9
    FlagSet 778
    FlagSet 779
    Cmd_0262 3, 7
    Cmd_0262 0, 6
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40ce
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0748
    VMCall L_0895
    VMJump L_07A2

L_0748:
    WordSetLoadRivalName 1
    ActorMsg 1024, 35, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0788
    ActorMsg 1024, 33, 12, 0, 0
    MsgWinCloseAll
    VMCall L_0B09
    VMJump L_07A2

L_0788:
    ActorMsg 1024, 34, 12, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 12, Movement_0F84
    ActorCmdWait

L_07A2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8022, 185
    VMJumpIf 1, L_07C3
    VMJump L_07D9

L_07C3:
    ActorCmdExec 12, Movement_0F8C
    ActorCmdExec 255, Movement_0F94
    VMJump L_0802

L_07D9:
    WorkCmpConst 0x8022, 187
    VMJumpIf 1, L_07EC
    VMJump L_0802

L_07EC:
    ActorCmdExec 12, Movement_0F94
    ActorCmdExec 255, Movement_0F8C
    VMJump L_0802

L_0802:
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 35, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_085F
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0845
    PlayerSetSpecialSequence 1

L_0845:
    ActorMsg 1024, 33, 12, 0, 0
    MsgWinCloseAll
    VMCall L_0B09
    VMJump L_0881

L_085F:
    ActorMsg 1024, 34, 12, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 12, Movement_0F84
    ActorCmdExec 255, Movement_0F9C
    ActorCmdWait

L_0881:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    VMCall L_0895
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0895:
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x40ce
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A51
    WorkSetConst 0x40ce, 2
    FlagReset 785
    Cmd_0262 1, 22
    ActorAdd 10
    ActorAdd 11
    VMStackPush 0x8022
    VMStackPushConst 185
    VMStackCmp 1
    VMJumpIf 255, L_08E9
    ActorCmdExec 12, Movement_0F7C
    ActorCmdWait
    VMJump L_0940

L_08E9:
    VMStackPush 0x8022
    VMStackPushConst 186
    VMStackCmp 1
    VMJumpIf 255, L_0916
    ActorCmdExec 12, Movement_0FDC
    ActorCmdWait
    ActorCmdExec 255, Movement_0F8C
    ActorCmdWait
    VMJump L_0940

L_0916:
    ActorCmdExec 12, Movement_0FDC
    ActorCmdWait
    WorkSub 0x8022, 1
    ActorWalkRoute 12, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_0F8C
    ActorCmdWait

L_0940:
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_095B
    PlayerSetSpecialSequence 1

L_095B:
    WordSetLoadRivalName 1
    ActorMsg 1024, 30, 12, 0, 0
    MsgWinCloseAll
    BGMPlay 1266
    ActorCmdExec 10, Movement_0F74
    ActorCmdExec 11, Movement_0F74
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x2868000, 0, 0xba8000, 30
    ActorCmdExec 12, Movement_0F84
    ActorCmdExec 255, Movement_0F84
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 31, 10, 2, 0
    MsgWinCloseAll
    ActorWalkRoute 12, 647, 186, 1, 4, 0
    ActorCmdWait
    ActorCmdExec 12, Movement_0FCC
    ActorCmdWait
    ActorCmdExec 12, Movement_0FFC
    ActorCmdWait
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorMsg 1024, 32, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A31
    ActorMsg 1024, 33, 12, 0, 0
    MsgWinCloseAll
    EvCameraReturn 30
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMCall L_0B09
    VMJump L_0A4B

L_0A31:
    ActorMsg 1024, 34, 12, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    EvCameraReturn 30
    EvCameraWait
    EvCameraRebind
    EvCameraEnd

L_0A4B:
    VMJump L_0B05

L_0A51:
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8022, 185
    VMJumpIf 1, L_0A6A
    VMJump L_0A80

L_0A6A:
    ActorCmdExec 12, Movement_0F8C
    ActorCmdExec 255, Movement_0F94
    VMJump L_0AA9

L_0A80:
    WorkCmpConst 0x8022, 187
    VMJumpIf 1, L_0A93
    VMJump L_0AA9

L_0A93:
    ActorCmdExec 12, Movement_0F94
    ActorCmdExec 255, Movement_0F8C
    VMJump L_0AA9

L_0AA9:
    ActorCmdWait
    WordSetLoadRivalName 1
    ActorMsg 1024, 35, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0AEB
    ActorMsg 1024, 33, 12, 0, 0
    MsgWinCloseAll
    VMCall Script_6
    VMJump L_0B05

L_0AEB:
    ActorMsg 1024, 34, 12, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 12, Movement_0F84
    ActorCmdWait

L_0B05:
    BGMChangeMap
    VMReturn

L_0B09:
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8022, 186
    VMJumpIf 1, L_0B22
    VMJump L_0B44

L_0B22:
    ActorWalkRoute 255, 647, 185, 2, 8, 1
    VMSleep 8
    ActorCmdExec 12, Movement_0F84
    ActorCmdWait
    VMJump L_0B83

L_0B44:
    WorkCmpConst 0x8022, 187
    VMJumpIf 1, L_0B57
    VMJump L_0B83

L_0B57:
    ActorWalkRoute 255, 648, 185, 2, 8, 0
    VMSleep 8
    ActorCmdExec 12, Movement_0F84
    ActorCmdWait
    ActorCmdExec 255, Movement_0FA4
    ActorCmdWait
    VMJump L_0B83

L_0B83:
    VMStackPush 0x8022
    VMStackPushConst 185
    VMStackCmp 1
    VMJumpIf 255, L_0BCF
    VMStackPush 0x8021
    VMStackPushConst 650
    VMStackCmp 1
    VMJumpIf 255, L_0BBD
    ActorWalkRoute 255, 647, 185, 2, 8, 0
    VMJump L_0BCD

L_0BBD:
    ActorCmdExec 12, Movement_0F84
    ActorCmdExec 255, Movement_0F84

L_0BCD:
    ActorCmdWait

L_0BCF:
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0BF2
    CallTrainerMultiBattle 701, 705, 704, 0
    VMJump L_0C1F

L_0BF2:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C15
    CallTrainerMultiBattle 702, 705, 704, 0
    VMJump L_0C1F

L_0C15:
    CallTrainerMultiBattle 703, 705, 704, 0

L_0C1F:
    VMCall L_0CB0
    ActorMsg 1024, 36, 11, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 37, 10, 2, 0
    MsgWinCloseAll
    VMSleep 15
    ActorWalkRoute 10, 637, 186, 1, 4, 0
    VMSleep 8
    ActorWalkRoute 11, 637, 185, 1, 4, 0
    ActorCmdWait
    ActorDelete 10
    ActorDelete 11
    FlagSet 785
    WordSetLoadRivalName 1
    ActorMsg 1024, 38, 12, 0, 1
    ActorMsgClose
    ActorWalkRoute 12, 638, 186, 1, 4, 0
    ActorCmdWait
    ActorDelete 12
    FlagSet 784
    WorkSetConst 0x40ce, 3
    WorkSetConst 0x40cc, 4
    Cmd_0262 1, 23
    VMReturn

L_0CB0:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0CEA
    PokePartyGetCount 0x8008, 2
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0CE2
    PokePartyRecoverAll

L_0CE2:
    CallTrainerBattleEnd
    VMJump L_0CEC

L_0CEA:
    CallTrainerLose

L_0CEC:
    VMReturn

Script_7:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 44, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 39, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0DA2
    ParentActorMsg 1024, 40, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0F7C
    ActorCmdWait
    VMSleep 60
    VMStackPush 0x8021
    VMStackPushConst 670
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 167
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0D84
    ActorCmdExec 0, Movement_0F94
    ActorCmdWait
    VMJump L_0D8E

L_0D84:
    ActorCmdExec 0, Movement_0F84
    ActorCmdWait

L_0D8E:
    ParentActorMsg 1024, 41, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0DB0

L_0DA2:
    ParentActorMsg 1024, 42, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0DB0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 43, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 45, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E1D
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 47, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0E31

L_0E1D:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 46, 0, 0
    LastKeyWait
    ActorMsgClose

L_0E31:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 48, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0E82
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 50, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0E96

L_0E82:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 49, 0, 0
    LastKeyWait
    ActorMsgClose

L_0E96:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 572, 0
    ParentActorMsg 1024, 51, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 52, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    Move 15, 6
    MoveEnd
    Move 15, 6
    MoveEnd

Movement_0EEC:
    Move 14, 13
    Move 32, 1
    MoveEnd

Movement_0EF8:
    Move 63, 2
    Move 13, 1
    Move 14, 11
    Move 32, 1
    MoveEnd

Movement_0F0C:
    Move 14, 14
    Move 32, 1
    MoveEnd
    Move 13, 8
    MoveEnd
    Move 13, 8
    MoveEnd

Movement_0F28:
    Move 12, 10
    Move 14, 18
    Move 32, 1
    MoveEnd

Movement_0F38:
    Move 63, 2
    Move 14, 1
    Move 12, 10
    Move 14, 16
    Move 32, 1
    MoveEnd

Movement_0F50:
    Move 12, 12
    Move 14, 17
    Move 32, 1
    MoveEnd

Movement_0F60:
    Move 14, 1
    Move 13, 4
    MoveEnd

Movement_0F6C:
    Move 17, 4
    MoveEnd

Movement_0F74:
    Move 15, 6
    MoveEnd

Movement_0F7C:
    Move 35, 1
    MoveEnd

Movement_0F84:
    Move 34, 1
    MoveEnd

Movement_0F8C:
    Move 32, 1
    MoveEnd

Movement_0F94:
    Move 33, 1
    MoveEnd

Movement_0F9C:
    Move 15, 1
    MoveEnd

Movement_0FA4:
    Move 14, 1
    MoveEnd
    Move 13, 1
    MoveEnd

Movement_0FB4:
    Move 12, 1
    MoveEnd
    Move 0, 1
    MoveEnd

Movement_0FC4:
    Move 1, 1
    MoveEnd

Movement_0FCC:
    Move 2, 1
    MoveEnd
    Move 3, 1
    MoveEnd

Movement_0FDC:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd

Movement_0FEC:
    Move 161, 1
    MoveEnd
    Move 160, 1
    MoveEnd

Movement_0FFC:
    Move 100, 1
    MoveEnd
