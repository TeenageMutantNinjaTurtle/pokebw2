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
    ScriptEntry Script_31
    ScriptEntry Script_32
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_8:
    WorkSetConst 0x417c, 1
    WorkSetConst 0x4160, 0
    FlagReset 220
    FlagSet 622
    FlagSet 623
    FlagSet 624
    FlagSet 625
    FlagSet 626
    FlagSet 661
    FlagSet 662
    FlagSet 663
    FlagSet 664
    FlagSet 665
    FlagSet 242
    VMStackPushFlag 764
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0112
    TrainerCardGetSex 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_010C
    WorkSetConst 0x4020, 240
    VMJump L_0112

L_010C:
    WorkSetConst 0x4020, 231

L_0112:
    VMStackPush 0x4111
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0141
    Cmd_0262 2, 14
    VMJump L_016A

L_0141:
    VMStackPush 0x4111
    VMStackPushConst 0
    VMStackCmp 5
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_016A
    Cmd_0262 2, 0

L_016A:
    VMHalt

Script_9:
    VMCall L_0174
    VMHalt

L_0174:
    VMStackPush 0x40c0
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01C3
    ActorSetGPos 3, 407, 1, 438, 0
    ActorSetGPos 1, 406, 1, 438, 3
    ActorSetGPos 4, 407, 1, 437, 1
    ActorSetGPos 0, 406, 1, 439, 3
    ActorSetGPos 2, 407, 1, 440, 0

L_01C3:
    VMReturn

Script_7:
    ActorsPauseAll
    CallPlaceNameDisp
    ActorCmdExec 255, Movement_01DC
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_01DC:
    Move 13, 1
    MoveEnd
    WorkSetConst 0x8024, 0

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 56, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 57, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 58, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 59, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 60, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 61, 0
    MsgPlaceSignClose
    FlagSet 2660
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 62, 0
    MsgPlaceSignClose
    FlagSet 2661
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 63, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 43, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_23:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 44, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_24:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 45, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_25:
    ActorsPauseAll
    WordSetLoadJoinAvenueName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 46, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_26:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 47, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_27:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 48, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_28:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 513, 0
    ParentActorMsg 1024, 49, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_29:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 50, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_30:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 51, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    WorkSetConst 0x40c0, 2
    Cmd_0262 1, 7
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x1978000, 0x1000f, 0x1b68000, 20
    EvCameraWait
    BGMPlay 1266
    WordSetLoadRivalName 1
    ActorMsg 1024, 0, 3, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0FC8
    VMSleep 6
    ActorCmdExec 1, Movement_0FD0
    ActorCmdWait
    VMSleep 40
    ActorCmdExec 0, Movement_0F94
    ActorCmdExec 1, Movement_0F94
    ActorCmdWait
    ActorMsg 1024, 1, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 3, Movement_0F74
    ActorCmdWait
    ActorMsg 1024, 2, 3, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 4, Movement_0F9C
    VMSleep 3
    ActorCmdExec 2, Movement_0F9C
    ActorCmdWait
    ActorCmdExec 4, Movement_0FD0
    VMSleep 3
    ActorCmdExec 2, Movement_0FC8
    ActorCmdWait
    ActorCmdExec 3, Movement_0FB4
    ActorCmdWait
    VMSleep 8
    ActorCmdExec 3, Movement_0FE0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 4, 3, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 3, Movement_0FC8
    ActorCmdWait
    EvCameraReturn 20
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    BGMChangeMap
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ParentActorMsg 1024, 5, 0, 0
    MsgWinCloseAll
    ActorCmdExec 3, Movement_0FC8
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0544
    PlayerSetSpecialSequence 1

L_0544:
    TrainerBGMPlayPush 359
    ParentActorMsg 1024, 6, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 359, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0581
    WorkAdd 0x40c0, 1
    CallTrainerBattleEnd
    VMJump L_0589

L_0581:
    WorkSetConst 0x40c0, 2
    CallTrainerLose

L_0589:
    ParentActorMsg 1024, 8, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 405, 439, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_0FE0
    ActorCmdWait
    ActorWalkRoute 4, 405, 437, 1, 8, 0
    VMSleep 3
    ActorCmdExec 3, Movement_0FD8
    ActorCmdWait
    ActorCmdExec 4, Movement_0FE0
    ActorCmdWait
    TrainerBGMPlayPush 751
    ActorCmdExec 255, Movement_0FD0
    ActorCmdExec 2, Movement_0FC8
    ActorCmdWait
    ActorMsg 1024, 11, 2, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 751, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0626
    WorkAdd 0x40c0, 1
    CallTrainerBattleEnd
    VMJump L_062E

L_0626:
    WorkSetConst 0x40c0, 2
    CallTrainerLose

L_062E:
    ActorMsg 1024, 12, 2, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 2, 405, 440, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 2, Movement_0FE0
    ActorCmdWait
    VMCall L_0828
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0685
    PlayerSetSpecialSequence 1

L_0685:
    TrainerBGMPlayPush 751
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 751, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06C2
    WorkAdd 0x40c0, 1
    CallTrainerBattleEnd
    VMJump L_06CA

L_06C2:
    WorkSetConst 0x40c0, 2
    CallTrainerLose

L_06CA:
    ParentActorMsg 1024, 12, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 2, 405, 440, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 2, Movement_0FE0
    ActorCmdWait
    ActorWalkRoute 4, 405, 437, 1, 8, 0
    VMSleep 3
    ActorCmdExec 3, Movement_0FD8
    ActorCmdWait
    ActorCmdExec 4, Movement_0FE0
    ActorCmdWait
    TrainerBGMPlayPush 359
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 408
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 440
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0759
    WorkSub 0x8022, 1
    ActorWalkRoute 0, 0x8021, 0x8022, 1, 8, 0
    ActorCmdWait

L_0759:
    PlayerGetDir 0x8020
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_0770
    VMJump L_0786

L_0770:
    ActorCmdExec 255, Movement_0FC8
    ActorCmdExec 0, Movement_0FD0
    VMJump L_07AF

L_0786:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_0799
    VMJump L_07AF

L_0799:
    ActorCmdExec 255, Movement_0FD8
    ActorCmdExec 0, Movement_0FE0
    VMJump L_07AF

L_07AF:
    ActorCmdWait
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 359, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07EC
    WorkAdd 0x40c0, 1
    CallTrainerBattleEnd
    VMJump L_07F4

L_07EC:
    WorkSetConst 0x40c0, 2
    CallTrainerLose

L_07F4:
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 0, 405, 439, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 0, Movement_0FE0
    ActorCmdWait
    VMCall L_0828
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0828:
    ActorsPauseAll
    WorkSetConst 0x40c0, 4
    ActorWalkRoute 1, 405, 438, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 1, Movement_0FE0
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 408
    VMStackCmp 1
    VMStackPush 0x8022
    VMStackPushConst 440
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0883
    ActorWalkRoute 255, 407, 439, 1, 8, 1
    ActorCmdWait

L_0883:
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_08A4
    ActorCmdExec 255, Movement_0FD8
    ActorCmdWait

L_08A4:
    ActorMsg 1024, 13, 1, 0, 0
    MsgWinCloseAll
    VMSleep 15
    FadeEx 3, 0, 16, 4
    FadeExWait
    ActorDelete 1
    ActorDelete 0
    ActorDelete 4
    ActorDelete 2
    BGMFadeOutAll 40
    VMSleep 45
    FlagSet 762
    FadeEx 3, 16, 0, 4
    FadeExWait
    VMSleep 45
    ActorCmdExec 3, Movement_0FAC
    ActorCmdWait
    BGMPlay 1095
    WordSetLoadRivalName 1
    ActorMsg 1024, 14, 3, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 3, 406, 439, 0, 8, 1
    ActorCmdWait
    ActorCmdExec 3, Movement_0FE0
    ActorCmdWait
    ActorMsg 1024, 15, 3, 0, 0
    MsgWinCloseAll
    PokePartyRecoverAll
    SEPlay 1391
    SEWait
    WordSetLoadRivalName 1
    WordSetPlayerName 0
    SystemMsg 16, 0
    MsgWaitAdvance
    InfoMsgClose
    ActorMsg 1024, 17, 3, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 3, 411, 440, 1, 8, 1
    VMSleep 20
    ActorCmdExec 255, Movement_0FE0
    ActorCmdWait
    ActorWalkRoute 3, 411, 447, 1, 8, 1
    ActorCmdWait
    ActorDelete 3
    FlagSet 761
    Cmd_0262 1, 8
    BGMChangeMap
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    VMStackPushFlag 288
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09D0
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgGendered 1024, 18, 25, 5, 2, 0
    FlagSet 288
    VMJump L_09E4

L_09D0:
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgGendered 1024, 20, 27, 5, 2, 0

L_09E4:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0DC0
    ActorMsgGendered 1024, 21, 28, 5, 2, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_0FC8
    VMSleep 8
    ActorCmdExec 255, Movement_0FC8
    ActorCmdWait
    ActorMsgGendered 1024, 22, 29, 5, 2, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_0FE0
    ActorCmdExec 7, Movement_0FD8
    ActorCmdWait
    VMSleep 30
    ActorCmdExec 6, Movement_0FD0
    ActorCmdExec 7, Movement_0FD0
    ActorCmdWait
    FadeEx 3, 0, 16, 2
    FadeExWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x1a68000, 0x1000f, 0x1ce8000, 1
    EvCameraWait
    ActorSetGPos 255, 420, 1, 461, 3
    ActorSetGPos 5, 420, 1, 463, 3
    ActorSetGPos 6, 424, 1, 463, 2
    ActorSetGPos 7, 424, 1, 461, 2
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0ACE
    PlayerSetSpecialSequence 1

L_0ACE:
    VMSleep 60
    FadeEx 3, 16, 0, 2
    FadeExWait
    ActorMsg 1024, 34, 6, 2, 0
    MsgWinCloseAll
    ActorMsg 1024, 35, 7, 1, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0F6C
    ActorCmdExec 5, Movement_0F6C
    ActorCmdExec 6, Movement_0F74
    ActorCmdExec 7, Movement_0F74
    ActorCmdWait
    TrainerCardGetSex 0x8023
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0B53
    CallTrainerMultiBattle 363, 732, 733, 0
    VMJump L_0C29

L_0B53:
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0B86
    CallTrainerMultiBattle 360, 732, 733, 0
    VMJump L_0C29

L_0B86:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0BB9
    CallTrainerMultiBattle 364, 732, 733, 0
    VMJump L_0C29

L_0BB9:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0BEC
    CallTrainerMultiBattle 361, 732, 733, 0
    VMJump L_0C29

L_0BEC:
    VMStackPush 0x4030
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0C1F
    CallTrainerMultiBattle 365, 732, 733, 0
    VMJump L_0C29

L_0C1F:
    CallTrainerMultiBattle 362, 732, 733, 0

L_0C29:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0C81
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x1a68000, 0x1000f, 0x1ce8000, 1
    EvCameraWait
    PokePartyGetCount 0x8008, 2
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0C79
    PokePartyRecoverAll

L_0C79:
    CallTrainerBattleEnd
    VMJump L_0C83

L_0C81:
    CallTrainerLose

L_0C83:
    VMSleep 30
    ActorMsg 1024, 36, 6, 2, 0
    MsgWinCloseAll
    ActorCmdExec 7, Movement_0FD8
    ActorCmdWait
    ActorMsg 1024, 37, 7, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 38, 6, 2, 0
    MsgWinCloseAll
    ActorWalkRoute 7, 422, 459, 1, 8, 1
    VMSleep 2
    ActorWalkRoute 6, 422, 460, 1, 8, 1
    VMSleep 16
    ActorCmdExec 5, Movement_0F7C
    ActorCmdExec 255, Movement_0F7C
    ActorCmdWait
    ActorCmdExec 6, Movement_0F7C
    ActorCmdWait
    ActorDelete 7
    ActorWalkRoute 6, 422, 459, 1, 8, 1
    ActorCmdWait
    SEPlay 1369
    ActorDelete 6
    SEWait
    VMSleep 15
    ActorWalkRoute 5, 422, 461, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 5, Movement_0FD8
    VMSleep 10
    ActorCmdExec 255, Movement_0FE0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsgGendered 1024, 23, 30, 5, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 465
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsgGendered 1024, 24, 31, 5, 2, 0
    MsgWinCloseAll
    ActorWalkRoute 5, 422, 459, 1, 8, 1
    VMSleep 8
    ActorCmdExec 255, Movement_0F7C
    ActorCmdWait
    SEPlay 1369
    ActorDelete 5
    SEWait
    EvCameraReturn 16
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    FlagSet 764
    VMJump L_0DDC

L_0DC0:
    ActorMsgGendered 1024, 19, 26, 5, 2, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 5, Movement_0FC8
    ActorCmdWait

L_0DDC:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 32, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 33, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 39, 0, 0
    MsgWinCloseAll
    VMSleep 4
    ActorCmdExec 9, Movement_0FE0
    ActorCmdExec 8, Movement_0FD8
    ActorCmdWait
    ParentActorMsg 1024, 40, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8020
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_0E67
    VMJump L_0E75

L_0E67:
    ActorCmdExec 9, Movement_0FD0
    VMJump L_0E96

L_0E75:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_0E88
    VMJump L_0E96

L_0E88:
    ActorCmdExec 9, Movement_0FD8
    VMJump L_0E96

L_0E96:
    ActorCmdWait
    ParentActorMsg 1024, 41, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 438
    VMStackCmp 1
    VMJumpIf 255, L_0EEF
    ActorWalkRoute 9, 417, 437, 1, 8, 0
    ActorWalkRoute 8, 418, 437, 1, 8, 0
    VMSleep 8
    ActorCmdExec 255, Movement_0FD8
    ActorCmdWait
    VMJump L_0F19

L_0EEF:
    ActorWalkRoute 9, 417, 438, 1, 8, 1
    ActorWalkRoute 8, 418, 438, 1, 8, 1
    VMSleep 16
    ActorCmdExec 255, Movement_0FD8
    ActorCmdWait

L_0F19:
    ActorDelete 9
    ActorDelete 8
    VMSleep 8
    FlagSet 864
    FlagSet 865
    FlagReset 866
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 511, 0
    ParentActorMsg 1024, 42, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0F5C:
    Move 13, 1
    MoveEnd

Movement_0F64:
    Move 12, 1
    MoveEnd

Movement_0F6C:
    Move 15, 1
    MoveEnd

Movement_0F74:
    Move 14, 1
    MoveEnd

Movement_0F7C:
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0xfe
    .balign 4, 0

Movement_0F94:
    Move 3, 1
    MoveEnd

Movement_0F9C:
    Move 15, 2
    MoveEnd
    VMStackMul
    VMHalt
    .byte 0xfe
    .balign 4, 0

Movement_0FAC:
    Move 10, 1
    MoveEnd

Movement_0FB4:
    Move 61, 1
    Move 32, 1
    Move 33, 1
    Move 61, 1
    MoveEnd

Movement_0FC8:
    Move 32, 1
    MoveEnd

Movement_0FD0:
    Move 33, 1
    MoveEnd

Movement_0FD8:
    Move 34, 1
    MoveEnd

Movement_0FE0:
    Move 35, 1
    MoveEnd
    Move 71, 1
    Move 11, 1
    Move 72, 1
    MoveEnd

Movement_0FF8:
    Move 71, 1
    Move 13, 1
    Move 72, 1
    MoveEnd

Movement_1008:
    Move 0, 1
    Move 75, 1
    MoveEnd

Script_32:
    ActorsPauseAll
    ItemCheckAmount 465, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_104B
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 54, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_105F

L_104B:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 55, 0, 0
    LastKeyWait
    ActorMsgClose

L_105F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_31:
    ActorsPauseAll
    WorkSetConst 0x8025, 0
    BMCreateHandleByGPos 0x8025, 1, 399, 467
    BMHndAudioVisualAnmPlay 0x8025, 0
    BMHndAnmWait 0x8025
    ActorNew 399, 467, 1, 251, 31, 0
    ActorCmdExec 255, Movement_1008
    ActorCmdWait
    ActorCmdExec 251, Movement_0F5C
    ActorCmdExec 255, Movement_0FF8
    ActorCmdWait
    BMHndAudioVisualAnmPlay 0x8025, 1
    BMHndAnmWait 0x8025
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_10E6
    WorkSetConst 0x8026, 52
    WorkSetConst 0x8027, 53
    VMJump L_10F2

L_10E6:
    WorkSetConst 0x8026, 54
    WorkSetConst 0x8027, 55

L_10F2:
    ItemCheckAmount 465, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_111F
    ActorMsg 1024, 0x8026, 251, 0, 0
    VMJump L_112B

L_111F:
    ActorMsg 1024, 0x8027, 251, 0, 0

L_112B:
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1172
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0FC8
    ActorCmdWait
    BMHndAudioVisualAnmPlay 0x8025, 0
    BMHndAnmWait 0x8025
    ActorCmdExec 251, Movement_0F64
    ActorCmdWait
    ActorDelete 251
    BMHndAudioVisualAnmPlay 0x8025, 1
    BMHndAnmWait 0x8025
    VMJump L_1182

L_1172:
    LastKeyWait
    MsgWinCloseAll
    FlagReset 1033
    ActorAdd 19
    ActorDelete 251

L_1182:
    BMReleaseHandle 0x8025
    WorkSetConst 0x4141, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
