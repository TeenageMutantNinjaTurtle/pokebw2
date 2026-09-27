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

Script_14:
    VMStackPush 0x40d4
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0083
    ActorSetRailPos 8, 8, 2, 12

L_0083:
    VMHalt

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 32, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 32, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 33, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    ISSSwitchQuery 0x8010, 1
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_013D
    VMStackPush 0x400a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_011F
    ISSSwitchEnable 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0137

L_011F:
    ISSSwitchEnable 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    ActorMsgClose

L_0137:
    VMJump L_018C

L_013D:
    VMStackPush 0x400a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0174
    ISSSwitchDisable 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x400a, 1
    VMJump L_018C

L_0174:
    ISSSwitchDisable 1
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait
    ActorMsgClose

L_018C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    ISSSwitchQuery 0x8010, 3
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01FC
    VMStackPush 0x400b
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01DE
    ISSSwitchEnable 3
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_01F6

L_01DE:
    ISSSwitchEnable 3
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose

L_01F6:
    VMJump L_024B

L_01FC:
    VMStackPush 0x400b
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0233
    ISSSwitchDisable 3
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x400b, 1
    VMJump L_024B

L_0233:
    ISSSwitchDisable 3
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose

L_024B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    ISSSwitchQuery 0x8010, 2
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02BB
    VMStackPush 0x400c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_029D
    ISSSwitchEnable 2
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_02B5

L_029D:
    ISSSwitchEnable 2
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose

L_02B5:
    VMJump L_030A

L_02BB:
    VMStackPush 0x400c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F2
    ISSSwitchDisable 2
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x400c, 1
    VMJump L_030A

L_02F2:
    ISSSwitchDisable 2
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose

L_030A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    ISSSwitchQuery 0x8010, 4
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_037A
    VMStackPush 0x400d
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_035C
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    ISSSwitchEnable 4
    VMJump L_0374

L_035C:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    ActorMsgClose
    ISSSwitchEnable 4

L_0374:
    VMJump L_03C9

L_037A:
    VMStackPush 0x400d
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03B1
    ISSSwitchDisable 4
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose
    WorkSetConst 0x400d, 1
    VMJump L_03C9

L_03B1:
    ISSSwitchDisable 4
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 27, 0, 0
    LastKeyWait
    ActorMsgClose

L_03C9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_03EB:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_040A
    CallTrainerBattleEnd
    VMJump L_040C

L_040A:
    CallTrainerLose

L_040C:
    VMReturn

Script_9:
    ActorsPauseAll
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0427
    VMJump L_0435

L_0427:
    ActorCmdExec 8, Movement_0C14
    VMJump L_0456

L_0435:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0448
    VMJump L_0456

L_0448:
    ActorCmdExec 8, Movement_0C0C
    VMJump L_0456

L_0456:
    ActorCmdWait
    ActorCmdExec 8, Movement_0C88
    ActorCmdWait
    PlayerGetRailPos 0x8023, 0x8024, 0x8025
    WorkCmpConst 0x8025, 5
    VMJumpIf 1, L_047D
    VMJump L_048B

L_047D:
    ActorCmdExec 8, Movement_0AD4
    VMJump L_056A

L_048B:
    WorkCmpConst 0x8025, 6
    VMJumpIf 1, L_049E
    VMJump L_04AC

L_049E:
    ActorCmdExec 8, Movement_0AE0
    VMJump L_056A

L_04AC:
    WorkCmpConst 0x8025, 7
    VMJumpIf 1, L_04BF
    VMJump L_04CD

L_04BF:
    ActorCmdExec 8, Movement_0AEC
    VMJump L_056A

L_04CD:
    WorkCmpConst 0x8025, 8
    VMJumpIf 1, L_04E0
    VMJump L_04E6

L_04E0:
    VMJump L_056A

L_04E6:
    WorkCmpConst 0x8025, 9
    VMJumpIf 1, L_04F9
    VMJump L_0507

L_04F9:
    ActorCmdExec 8, Movement_0AF8
    VMJump L_056A

L_0507:
    WorkCmpConst 0x8025, 10
    VMJumpIf 1, L_051A
    VMJump L_0528

L_051A:
    ActorCmdExec 8, Movement_0B04
    VMJump L_056A

L_0528:
    WorkCmpConst 0x8025, 11
    VMJumpIf 1, L_053B
    VMJump L_0549

L_053B:
    ActorCmdExec 8, Movement_0B10
    VMJump L_056A

L_0549:
    WorkCmpConst 0x8025, 12
    VMJumpIf 1, L_055C
    VMJump L_056A

L_055C:
    ActorCmdExec 8, Movement_0B1C
    VMJump L_056A

L_056A:
    ActorCmdWait
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0583
    VMJump L_0591

L_0583:
    ActorCmdExec 8, Movement_0BDC
    VMJump L_05B2

L_0591:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_05A4
    VMJump L_05B2

L_05A4:
    ActorCmdExec 8, Movement_0BE4
    VMJump L_05B2

L_05B2:
    ActorCmdWait
    ActorMsg 1024, 1, 8, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0719
    ActorMsg 1024, 2, 8, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 177, 0, 0
    VMCall L_03EB
    WorkSetConst 0x40d4, 1
    ActorMsg 1024, 4, 8, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    PlayerGetRailPos 0x8023, 0x8024, 0x8025
    WorkCmpConst 0x8025, 5
    VMJumpIf 1, L_0624
    VMJump L_0632

L_0624:
    ActorCmdExec 8, Movement_0B60
    VMJump L_0711

L_0632:
    WorkCmpConst 0x8025, 6
    VMJumpIf 1, L_0645
    VMJump L_0653

L_0645:
    ActorCmdExec 8, Movement_0B6C
    VMJump L_0711

L_0653:
    WorkCmpConst 0x8025, 7
    VMJumpIf 1, L_0666
    VMJump L_0674

L_0666:
    ActorCmdExec 8, Movement_0B78
    VMJump L_0711

L_0674:
    WorkCmpConst 0x8025, 8
    VMJumpIf 1, L_0687
    VMJump L_0695

L_0687:
    ActorCmdExec 8, Movement_0B84
    VMJump L_0711

L_0695:
    WorkCmpConst 0x8025, 9
    VMJumpIf 1, L_06A8
    VMJump L_06B6

L_06A8:
    ActorCmdExec 8, Movement_0B90
    VMJump L_0711

L_06B6:
    WorkCmpConst 0x8025, 10
    VMJumpIf 1, L_06C9
    VMJump L_06D7

L_06C9:
    ActorCmdExec 8, Movement_0B9C
    VMJump L_0711

L_06D7:
    WorkCmpConst 0x8025, 11
    VMJumpIf 1, L_06EA
    VMJump L_06F8

L_06EA:
    ActorCmdExec 8, Movement_0BA8
    VMJump L_0711

L_06F8:
    WorkCmpConst 0x8025, 12
    VMJumpIf 1, L_070B
    VMJump L_0711

L_070B:
    VMJump L_0711

L_0711:
    ActorCmdWait
    VMJump L_0913

L_0719:
    ActorMsg 1024, 3, 8, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0740
    VMJump L_0756

L_0740:
    ActorCmdExec 8, Movement_0BCC
    ActorCmdExec 255, Movement_0BCC
    VMJump L_077F

L_0756:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0769
    VMJump L_077F

L_0769:
    ActorCmdExec 8, Movement_0BD4
    ActorCmdExec 255, Movement_0BD4
    VMJump L_077F

L_077F:
    ActorCmdWait
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0794
    VMJump L_07A2

L_0794:
    ActorCmdExec 8, Movement_0BF4
    VMJump L_07C3

L_07A2:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_07B5
    VMJump L_07C3

L_07B5:
    ActorCmdExec 8, Movement_0BEC
    VMJump L_07C3

L_07C3:
    ActorCmdWait
    PlayerGetRailPos 0x8023, 0x8024, 0x8025
    WorkCmpConst 0x8025, 5
    VMJumpIf 1, L_07E0
    VMJump L_07EE

L_07E0:
    ActorCmdExec 8, Movement_0B28
    VMJump L_08CD

L_07EE:
    WorkCmpConst 0x8025, 6
    VMJumpIf 1, L_0801
    VMJump L_080F

L_0801:
    ActorCmdExec 8, Movement_0B30
    VMJump L_08CD

L_080F:
    WorkCmpConst 0x8025, 7
    VMJumpIf 1, L_0822
    VMJump L_0830

L_0822:
    ActorCmdExec 8, Movement_0B38
    VMJump L_08CD

L_0830:
    WorkCmpConst 0x8025, 8
    VMJumpIf 1, L_0843
    VMJump L_0849

L_0843:
    VMJump L_08CD

L_0849:
    WorkCmpConst 0x8025, 9
    VMJumpIf 1, L_085C
    VMJump L_086A

L_085C:
    ActorCmdExec 8, Movement_0B40
    VMJump L_08CD

L_086A:
    WorkCmpConst 0x8025, 10
    VMJumpIf 1, L_087D
    VMJump L_088B

L_087D:
    ActorCmdExec 8, Movement_0B48
    VMJump L_08CD

L_088B:
    WorkCmpConst 0x8025, 11
    VMJumpIf 1, L_089E
    VMJump L_08AC

L_089E:
    ActorCmdExec 8, Movement_0B50
    VMJump L_08CD

L_08AC:
    WorkCmpConst 0x8025, 12
    VMJumpIf 1, L_08BF
    VMJump L_08CD

L_08BF:
    ActorCmdExec 8, Movement_0B58
    VMJump L_08CD

L_08CD:
    ActorCmdWait
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_08E2
    VMJump L_08F0

L_08E2:
    ActorCmdExec 8, Movement_0C60
    VMJump L_0911

L_08F0:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0903
    VMJump L_0911

L_0903:
    ActorCmdExec 8, Movement_0C58
    VMJump L_0911

L_0911:
    ActorCmdWait

L_0913:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4108
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0A87
    ParentActorMsg 1024, 5, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A73
    ItemSub 30, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0A5F
    MsgWinCloseAll
    SEPlay 2017
    SEWait
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    PlayerGetRailPos 0x8026, 0x8027, 0x8028
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A31
    ActorCmdExec 18, Movement_0AB0
    VMJump L_0A39

L_0A31:
    ActorCmdExec 18, Movement_0AC0

L_0A39:
    VMSleep 20
    ActorCmdExec 255, Movement_0ACC
    ActorCmdWait
    ActorDelete 18
    WorkSetConst 0x4108, 4
    FlagSet 861
    FlagReset 862
    VMJump L_0A6D

L_0A5F:
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0A6D:
    VMJump L_0A81

L_0A73:
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0A81:
    VMJump L_0AA8

L_0A87:
    VMStackPush 0x4108
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0AA8
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0AA8:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0AB0:
    Move 36, 4
    Move 16, 1
    Move 19, 13
    MoveEnd

Movement_0AC0:
    Move 39, 4
    Move 19, 13
    MoveEnd

Movement_0ACC:
    Move 3, 1
    MoveEnd

Movement_0AD4:
    Move 36, 2
    Move 16, 3
    MoveEnd

Movement_0AE0:
    Move 36, 2
    Move 16, 2
    MoveEnd

Movement_0AEC:
    Move 36, 2
    Move 16, 1
    MoveEnd

Movement_0AF8:
    Move 37, 2
    Move 17, 1
    MoveEnd

Movement_0B04:
    Move 37, 2
    Move 17, 2
    MoveEnd

Movement_0B10:
    Move 37, 2
    Move 17, 3
    MoveEnd

Movement_0B1C:
    Move 37, 2
    Move 17, 4
    MoveEnd

Movement_0B28:
    Move 17, 3
    MoveEnd

Movement_0B30:
    Move 17, 2
    MoveEnd

Movement_0B38:
    Move 17, 1
    MoveEnd

Movement_0B40:
    Move 16, 1
    MoveEnd

Movement_0B48:
    Move 16, 2
    MoveEnd

Movement_0B50:
    Move 16, 3
    MoveEnd

Movement_0B58:
    Move 16, 4
    MoveEnd

Movement_0B60:
    Move 13, 7
    Move 32, 1
    MoveEnd

Movement_0B6C:
    Move 13, 6
    Move 32, 1
    MoveEnd

Movement_0B78:
    Move 13, 5
    Move 32, 1
    MoveEnd

Movement_0B84:
    Move 13, 4
    Move 32, 1
    MoveEnd

Movement_0B90:
    Move 13, 3
    Move 32, 1
    MoveEnd

Movement_0B9C:
    Move 13, 2
    Move 32, 1
    MoveEnd

Movement_0BA8:
    Move 13, 1
    Move 32, 1
    MoveEnd
    Move 32, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0BCC:
    Move 15, 1
    MoveEnd

Movement_0BD4:
    Move 14, 1
    MoveEnd

Movement_0BDC:
    Move 19, 1
    MoveEnd

Movement_0BE4:
    Move 18, 1
    MoveEnd

Movement_0BEC:
    Move 19, 2
    MoveEnd

Movement_0BF4:
    Move 18, 2
    MoveEnd
    Move 0, 1
    MoveEnd
    Move 1, 1
    MoveEnd

Movement_0C0C:
    Move 2, 1
    MoveEnd

Movement_0C14:
    Move 3, 1
    MoveEnd
    VMStackDiv
    VMHalt
    PokePartyGetSpecies 0, 14
    VMHalt
    .byte 0xfe
    .balign 4, 0
    Move 10, 1
    MoveEnd
    Move 61, 1
    Move 32, 1
    Move 33, 1
    Move 61, 1
    MoveEnd
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd

Movement_0C58:
    Move 34, 1
    MoveEnd

Movement_0C60:
    Move 35, 1
    MoveEnd
    Move 71, 1
    Move 11, 1
    Move 72, 1
    MoveEnd
    Move 71, 1
    Move 13, 1
    Move 72, 1
    MoveEnd

Movement_0C88:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 161, 1
    MoveEnd
    Move 160, 1
    MoveEnd

Script_15:
    ActorsPauseAll
    VMStackPushFlag 468
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0CD7
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 30, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0D68

L_0CD7:
    VMStackPushFlag 466
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0D54
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 158
    WorkSet 0x8001, 5
    WorkSet 0x8002, 468
    WorkSet 0x8003, 29
    WorkSet 0x8004, 30
    WorkSet 0x8005, 30
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_0D68

L_0D54:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose

L_0D68:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
