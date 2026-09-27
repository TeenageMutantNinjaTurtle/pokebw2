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
    ScriptEntriesEnd

Script_3:
    VMStackPushFlag 264
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0055
    FlagReset 2429

L_0055:
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    Cmd_0266 0x8020
    RTCGetWeekDay 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_007C
    VMJump L_0088

L_007C:
    WorkSetConst 0x8021, 291
    VMJump L_00E5

L_0088:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_009B
    VMJump L_00A7

L_009B:
    WorkSetConst 0x8021, 249
    VMJump L_00E5

L_00A7:
    WorkCmpConst 0x8010, 5
    VMJumpIf 1, L_00BA
    VMJump L_00C6

L_00BA:
    WorkSetConst 0x8021, 103
    VMJump L_00E5

L_00C6:
    WorkCmpConst 0x8010, 6
    VMJumpIf 1, L_00D9
    VMJump L_00E5

L_00D9:
    WorkSetConst 0x8021, 223
    VMJump L_00E5

L_00E5:
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_012D
    TrainerCardGetSex 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_011B
    WorkSetConst 0x4020, 290
    VMJump L_0121

L_011B:
    WorkSetConst 0x4020, 289

L_0121:
    WorkSetConst 0x4188, 2
    VMJump L_01E7

L_012D:
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 2
    VMStackPushFlag 2773
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0172
    WorkGet 0x4020, 0x8021
    WorkSetConst 0x4188, 1
    VMJump L_01E7

L_0172:
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    RTCGetSeason 0x8023
    VMStackPush 0x4173
    VMStackPush 0x8023
    VMStackCmp 5
    VMJumpIf 255, L_0199
    FlagReset 2740

L_0199:
    VMStackPush 0x8000
    VMStackPush 0x8001
    RTCGetSeason 0x8000
    TrainerCardGetSex 0x8001
    WorkSet 0x8022, 0x8000
    WorkMul 0x8022, 2
    WorkAdd 0x8022, 0x8001
    VMStackPop 0x8001
    VMStackPop 0x8000
    Cmd_021F 0x8022, 0x8010
    WorkGet 0x4020, 0x8010
    WorkGet 0x4173, 0x8023
    WorkSetConst 0x4188, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8022, 0

L_01E7:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8024, 0
    RTCGetWeekDay 0x8024
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPushFlag 2773
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_023C
    Cmd_0262 1, 44
    VMJump L_02B4

L_023C:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 1
    VMStackPushFlag 2773
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_027B
    Cmd_0262 3, 11
    VMJump L_02B4

L_027B:
    VMStackPush 0x8024
    VMStackPushConst 6
    VMStackCmp 1
    VMStackPushFlag 2773
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_02B4
    Cmd_0262 2, 13

L_02B4:
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 5
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_035E
    VMStackPushFlag 417
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 491
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0306
    Cmd_0262 1, 41
    VMJump L_035E

L_0306:
    VMStackPushFlag 417
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 491
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0335
    Cmd_0262 1, 42
    VMJump L_035E

L_0335:
    VMStackPushFlag 417
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 491
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_035E
    Cmd_0262 1, 43

L_035E:
    VMStackPush 0x8024
    VMStackPushConst 3
    VMStackCmp 5
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0387
    Cmd_0262 3, 0

L_0387:
    VMStackPush 0x8024
    VMStackPushConst 6
    VMStackCmp 5
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03E2
    VMStackPush 0x4111
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03C9
    Cmd_0262 2, 14
    VMJump L_03E2

L_03C9:
    VMStackPush 0x4111
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03E2
    Cmd_0262 2, 0

L_03E2:
    WorkSetConst 0x8024, 0
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 8, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 16, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    WorkSetConst 0x8025, 0
    TrainerCardGetSex 0x8025
    ActorDelete 11
    WorkCmpConst 0x8025, 0
    VMJumpIf 1, L_0445
    VMJump L_046B

L_0445:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 637
    WorkSet 0x8001, 1
    RTCallGlobal 2807
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_04A4

L_046B:
    WorkCmpConst 0x8025, 1
    VMJumpIf 1, L_047E
    VMJump L_04A4

L_047E:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 636
    WorkSet 0x8001, 1
    RTCallGlobal 2807
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_04A4

L_04A4:
    MEPlay 1327
    WorkCmpConst 0x8025, 0
    VMJumpIf 1, L_04BB
    VMJump L_04C7

L_04BB:
    SystemMsg 4, 2
    VMJump L_04E6

L_04C7:
    WorkCmpConst 0x8025, 1
    VMJumpIf 1, L_04DA
    VMJump L_04E6

L_04DA:
    SystemMsg 6, 2
    VMJump L_04E6

L_04E6:
    MEWait
    WordSetPlayerName 0
    WorkCmpConst 0x8025, 0
    VMJumpIf 1, L_04FE
    VMJump L_050A

L_04FE:
    SystemMsg 5, 2
    VMJump L_0529

L_050A:
    WorkCmpConst 0x8025, 1
    VMJumpIf 1, L_051D
    VMJump L_0529

L_051D:
    SystemMsg 7, 2
    VMJump L_0529

L_0529:
    MsgWinCloseAll
    FadeOutBlackQ
    FadeWait
    WorkCmpConst 0x8025, 0
    VMJumpIf 1, L_0542
    VMJump L_054E

L_0542:
    CallXTransceiver 2, 1
    VMJump L_056D

L_054E:
    WorkCmpConst 0x8025, 1
    VMJumpIf 1, L_0561
    VMJump L_056D

L_0561:
    CallXTransceiver 3, 1
    VMJump L_056D

L_056D:
    FadeInBlackQ
    FadeWait
    Cmd_0263 5
    FlagSet 671
    WorkSetConst 0x4126, 1
    WorkSetConst 0x4127, 1
    WorkSetConst 0x4128, 1
    WorkSetConst 0x4129, 1
    WorkSetConst 0x412a, 1
    WorkSetConst 0x412b, 1
    WorkSetConst 0x412c, 1
    WorkSetConst 0x412d, 1
    WorkSetConst 0x412e, 1
    WorkSetConst 0x412f, 1
    WorkSetConst 0x4130, 1
    WorkSetConst 0x4131, 1
    WorkSetConst 0x4132, 1
    WorkSetConst 0x4133, 1
    WorkSetConst 0x4134, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
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
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 531, 0
    ParentActorMsg 1024, 13, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 559, 0
    ParentActorMsg 1024, 14, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
