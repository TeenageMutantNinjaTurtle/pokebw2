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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0

Script_22:
    VMCall L_00F6
    VMHalt

Script_17:
    WorkSetConst 0x8025, 0
    Cmd_02B2 0, 0x8025
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C9
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00C9
    VMStackPushFlag 438
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00C9
    FlagReset 978

L_00C9:
    WorkSetConst 0x8025, 0
    VMCall L_00D7
    VMHalt

L_00D7:
    Cmd_02B2 0, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F4
    FlagSet 978

L_00F4:
    VMReturn

L_00F6:
    Cmd_02B2 0, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_012A
    VMStackPushFlag 978
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0126
    ActorDelete 21

L_0126:
    FlagSet 978

L_012A:
    VMReturn

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 58, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 59, 2
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 60, 0
    MsgPlaceSignClose
    FlagSet 2668
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1369
    ActorNew 377, 438, 2, 251, 249, 0
    SEWait
    ActorMsgGendered 1024, 45, 46, 251, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0E58
    ActorCmdWait
    PlayerGetGPos 0x8020, 0x8021
    ActorCmdExec 251, Movement_0418
    VMSleep 8
    PlayerGetExState 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01E0
    PlayerSetSpecialSequence 1

L_01E0:
    BGMPlay 1088
    VMStackPush 0x8021
    VMStackPushConst 438
    VMStackCmp 5
    VMJumpIf 255, L_0211
    ActorWalkRoute 255, 372, 438, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 255, Movement_0E08
    ActorCmdWait

L_0211:
    VMStackPush 0x8021
    VMStackPushConst 438
    VMStackCmp 1
    VMJumpIf 255, L_022E
    ActorCmdExec 255, Movement_0E08
    ActorCmdWait

L_022E:
    ActorMsg 1024, 47, 251, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 421
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsgGendered 1024, 48, 49, 251, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0295
    ActorMsg 1024, 50, 251, 0, 0
    VMJump L_02A1

L_0295:
    ActorMsg 1024, 51, 251, 0, 0

L_02A1:
    MsgWinCloseAll
    VMSleep 30
    ActorCmdExec 251, Movement_0E58
    ActorCmdWait
    ActorCmdExec 251, Movement_0DF0
    ActorCmdWait
    ActorMsg 1024, 52, 251, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 251, 372, 436, 1, 8, 1
    VMSleep 15
    ActorCmdExec 255, Movement_0DF0
    ActorCmdWait
    ActorCmdExec 251, Movement_0420
    ActorCmdWait
    VMSleep 20
    ActorCmdExec 251, Movement_0DF8
    ActorCmdWait
    ActorMsg 1024, 53, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_04B8
    VMSleep 5
    ActorWalkRoute 251, 369, 425, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 251, Movement_0438
    ActorCmdWait
    ActorWalkRoute 251, 374, 425, 1, 8, 0
    VMSleep 10
    ActorWalkRoute 255, 373, 425, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 251, Movement_045C
    ActorCmdWait
    ActorMsg 1024, 54, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_047C
    ActorCmdWait
    ActorMsg 1024, 55, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_0DF0
    ActorCmdWait
    SystemMsg 56, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03E8
    InfoMsgClose
    ActorCmdExec 251, Movement_0E00
    VMSleep 8
    ActorCmdExec 255, Movement_0E08
    ActorCmdWait
    ActorMsg 1024, 57, 251, 0, 0
    MsgWinCloseAll
    ActorCmdExec 251, Movement_0DF0
    ActorCmdExec 255, Movement_0DF0
    ActorCmdWait
    VMJump L_03EA

L_03E8:
    InfoMsgClose

L_03EA:
    HiddenHollowSet 1, 0, 0, 0
    RTReserveScript 6
    SEPlay 1369
    HiddenHollowCallWarpIn 1
    BGMChangeMap
    WorkSetConst 0x4139, 1
    MedalDiscover 57
    MedalDiscover 85
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0418:
    Move 14, 4
    MoveEnd

Movement_0420:
    Move 35, 1
    Move 62, 1
    Move 34, 1
    Move 62, 1
    Move 32, 1
    MoveEnd

Movement_0438:
    Move 34, 1
    Move 62, 1
    Move 35, 1
    Move 62, 1
    Move 32, 1
    Move 62, 1
    Move 35, 1
    Move 75, 1
    MoveEnd

Movement_045C:
    Move 30, 1
    Move 62, 1
    Move 31, 1
    Move 62, 1
    Move 29, 1
    Move 62, 1
    Move 159, 1
    MoveEnd

Movement_047C:
    Move 11, 1
    Move 62, 1
    Move 28, 1
    Move 62, 1
    Move 31, 1
    Move 62, 1
    Move 29, 1
    Move 62, 1
    Move 10, 1
    Move 29, 1
    Move 62, 1
    Move 28, 1
    Move 62, 1
    Move 75, 1
    MoveEnd

Movement_04B8:
    Move 12, 2
    Move 14, 3
    Move 12, 10
    MoveEnd

Script_4:
    ActorsPauseAll
    VMStackPushFlag 2750
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04E3
    Random 0x4175, 5

L_04E3:
    VMStackPushFlag 2751
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0508
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_0522
    VMJump L_051C

L_0508:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    ActorMsgClose

L_051C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0522:
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8026, 200
    MoneyWinDisp 31, 1
    WorkCmpConst 0x4175, 0
    VMJumpIf 1, L_0553
    VMJump L_0561

L_0553:
    WordSetItemNameEx 0, 169, 2, 0
    VMJump L_0606

L_0561:
    WorkCmpConst 0x4175, 1
    VMJumpIf 1, L_0574
    VMJump L_0582

L_0574:
    WordSetItemNameEx 0, 170, 2, 0
    VMJump L_0606

L_0582:
    WorkCmpConst 0x4175, 2
    VMJumpIf 1, L_0595
    VMJump L_05A3

L_0595:
    WordSetItemNameEx 0, 171, 2, 0
    VMJump L_0606

L_05A3:
    WorkCmpConst 0x4175, 3
    VMJumpIf 1, L_05B6
    VMJump L_05C4

L_05B6:
    WordSetItemNameEx 0, 172, 2, 0
    VMJump L_0606

L_05C4:
    WorkCmpConst 0x4175, 4
    VMJumpIf 1, L_05D7
    VMJump L_05E5

L_05D7:
    WordSetItemNameEx 0, 173, 2, 0
    VMJump L_0606

L_05E5:
    WorkCmpConst 0x4175, 5
    VMJumpIf 1, L_05F8
    VMJump L_0606

L_05F8:
    WordSetItemNameEx 0, 174, 2, 0
    VMJump L_0606

L_0606:
    VMStackPushFlag 2750
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_062B
    ActorMsg 1024, 30, 0, 2, 0
    VMJump L_0637

L_062B:
    ActorMsg 1024, 36, 0, 2, 0

L_0637:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08FE
    WorkCmpConst 0x4175, 0
    VMJumpIf 1, L_0661
    VMJump L_066F

L_0661:
    ItemCheckSpace 169, 5, 0x8028
    VMJump L_0714

L_066F:
    WorkCmpConst 0x4175, 1
    VMJumpIf 1, L_0682
    VMJump L_0690

L_0682:
    ItemCheckSpace 170, 5, 0x8028
    VMJump L_0714

L_0690:
    WorkCmpConst 0x4175, 2
    VMJumpIf 1, L_06A3
    VMJump L_06B1

L_06A3:
    ItemCheckSpace 171, 5, 0x8028
    VMJump L_0714

L_06B1:
    WorkCmpConst 0x4175, 3
    VMJumpIf 1, L_06C4
    VMJump L_06D2

L_06C4:
    ItemCheckSpace 172, 5, 0x8028
    VMJump L_0714

L_06D2:
    WorkCmpConst 0x4175, 4
    VMJumpIf 1, L_06E5
    VMJump L_06F3

L_06E5:
    ItemCheckSpace 173, 5, 0x8028
    VMJump L_0714

L_06F3:
    WorkCmpConst 0x4175, 5
    VMJumpIf 1, L_0706
    VMJump L_0714

L_0706:
    ItemCheckSpace 174, 5, 0x8028
    VMJump L_0714

L_0714:
    MoneyCheck 0x8027, 0x8026
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0745
    MoneyWinClose
    ActorMsg 1024, 33, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08F8

L_0745:
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0770
    MoneyWinClose
    ActorMsg 1024, 34, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08F8

L_0770:
    SEPlay 1621
    MoneySub 0x8026
    MoneyWinUpdate
    SEWait
    ActorMsg 1024, 32, 0, 2, 0
    MsgWinCloseAll
    MoneyWinClose
    WorkCmpConst 0x4175, 0
    VMJumpIf 1, L_079F
    VMJump L_07C5

L_079F:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 169
    WorkSet 0x8001, 5
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_08E2

L_07C5:
    WorkCmpConst 0x4175, 1
    VMJumpIf 1, L_07D8
    VMJump L_07FE

L_07D8:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 170
    WorkSet 0x8001, 5
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_08E2

L_07FE:
    WorkCmpConst 0x4175, 2
    VMJumpIf 1, L_0811
    VMJump L_0837

L_0811:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 171
    WorkSet 0x8001, 5
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_08E2

L_0837:
    WorkCmpConst 0x4175, 3
    VMJumpIf 1, L_084A
    VMJump L_0870

L_084A:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 172
    WorkSet 0x8001, 5
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_08E2

L_0870:
    WorkCmpConst 0x4175, 4
    VMJumpIf 1, L_0883
    VMJump L_08A9

L_0883:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 173
    WorkSet 0x8001, 5
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_08E2

L_08A9:
    WorkCmpConst 0x4175, 5
    VMJumpIf 1, L_08BC
    VMJump L_08E2

L_08BC:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 174
    WorkSet 0x8001, 5
    RTCallGlobal 2801
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_08E2

L_08E2:
    ActorMsg 1024, 35, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll
    MoneyWinClose
    FlagSet 2751

L_08F8:
    VMJump L_0910

L_08FE:
    MoneyWinClose
    ActorMsg 1024, 31, 0, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0910:
    FlagSet 2750
    VMReturn

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    TrainerCardHasBadge 0x8024, 3
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0959
    ActorMsgVersioned 1024, 0, 10, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    ActorCmdExec 8, Movement_0E48
    ActorCmdWait
    VMJump L_09D3

L_0959:
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 281
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09CD
    ActorMsgVersioned 1024, 1, 11, 8, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09B5
    FlagSet 281
    ActorMsgVersioned 1024, 3, 13, 8, 0, 0
    VMCall L_09D9
    VMJump L_09C7

L_09B5:
    ActorMsgVersioned 1024, 2, 12, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_09C7:
    VMJump L_09D3

L_09CD:
    VMCall L_09D9

L_09D3:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_09D9:
    ActorMsgVersioned 1024, 4, 14, 8, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0C28
    WorkSetConst 0x8029, 0
    PokePartyGetCount 0x8029, 2
    VMStackPush 0x8029
    VMStackPushConst 3
    VMStackCmp 0
    VMJumpIf 255, L_0A35
    ActorMsgVersioned 1024, 6, 16, 8, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0C22

L_0A35:
    ActorMsgVersioned 1024, 5, 15, 8, 0, 0
    ActorMsgClose
    VMCall L_0C42
    GameGetVersion 0x8023
    WorkCmpConst 0x8023, 22
    VMJumpIf 1, L_0A62
    VMJump L_0A70

L_0A62:
    CallTrainerBattle 340, 0, 0
    VMJump L_0A91

L_0A70:
    WorkCmpConst 0x8023, 23
    VMJumpIf 1, L_0A83
    VMJump L_0A91

L_0A83:
    CallTrainerBattle 339, 0, 0
    VMJump L_0A91

L_0A91:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0ACE
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x1558000, 0, 0x1b18000, 1
    EvCameraWait
    CallTrainerBattleEnd
    VMJump L_0AD0

L_0ACE:
    CallTrainerLose

L_0AD0:
    ActorMsgVersioned 1024, 8, 18, 8, 0, 0
    ActorMsgClose
    VMCall L_0D4C
    ActorMsgVersioned 1024, 9, 19, 8, 0, 0
    ActorMsgClose
    VMCall L_0DB6
    VMSleep 30
    EvCameraReturn 20
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 9, Movement_0E20
    VMSleep 8
    ActorCmdExec 255, Movement_0DF8
    ActorCmdExec 13, Movement_0E08
    ActorCmdExec 14, Movement_0E08
    ActorCmdExec 15, Movement_0E08
    ActorCmdExec 16, Movement_0E08
    ActorCmdExec 17, Movement_0E08
    ActorCmdWait
    ActorMsg 1024, 67, 9, 0, 0
    MsgWinCloseAll
    MultiMsg 68, 3, 3, 1
    VMSleep 10
    MultiMsg 69, 20, 13, 2
    VMSleep 10
    MultiMsg 70, 5, 20, 3
    VMSleep 30
    MsgWinCloseNo 1
    VMSleep 5
    MsgWinCloseNo 2
    VMSleep 5
    MsgWinCloseNo 3
    ActorCmdExec 9, Movement_0EAC
    ActorCmdExec 10, Movement_0EBC
    ActorCmdExec 11, Movement_0ECC
    ActorCmdExec 12, Movement_0ED8
    ActorCmdExec 13, Movement_0EE4
    ActorCmdExec 14, Movement_0EEC
    ActorCmdExec 15, Movement_0EF4
    ActorCmdExec 16, Movement_0EFC
    VMSleep 30
    FadeEx 3, 0, 16, 4
    ActorCmdWait
    FadeExWait
    ActorDelete 8
    ActorDelete 9
    ActorDelete 10
    ActorDelete 11
    ActorDelete 12
    ActorDelete 13
    ActorDelete 14
    ActorDelete 15
    ActorDelete 16
    ActorDelete 17
    FlagSet 760
    VMSleep 30
    FadeEx 3, 16, 0, 4
    FadeExWait

L_0C22:
    VMJump L_0C3A

L_0C28:
    ActorMsgVersioned 1024, 7, 17, 8, 0, 0
    LastKeyWait
    ActorMsgClose

L_0C3A:
    WorkSetConst 0x8029, 0
    VMReturn

L_0C42:
    ActorCmdExec 9, Movement_0EA4
    ActorCmdExec 10, Movement_0E18
    ActorCmdExec 11, Movement_0E40
    ActorCmdExec 12, Movement_0E40
    ActorCmdExec 13, Movement_0E48
    ActorCmdExec 14, Movement_0E48
    ActorCmdExec 15, Movement_0E48
    ActorCmdExec 16, Movement_0E48
    ActorCmdWait
    ActorCmdExec 9, Movement_0DF0
    ActorCmdExec 10, Movement_0DF0
    ActorCmdExec 17, Movement_0E48
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x1558000, 0, 0x1b18000, 20
    PlayerGetDir 0x8022
    WorkCmpConst 0x8022, 0
    VMJumpIf 1, L_0CEB
    WorkCmpConst 0x8022, 2
    VMJumpIf 1, L_0CEB
    WorkCmpConst 0x8022, 1
    VMJumpIf 1, L_0CEB
    VMJump L_0CFF

L_0CEB:
    ActorWalkRoute 255, 342, 433, 0, 8, 0
    VMJump L_0D30

L_0CFF:
    WorkCmpConst 0x8022, 3
    VMJumpIf 1, L_0D12
    VMJump L_0D30

L_0D12:
    ActorCmdExec 255, Movement_0E18
    ActorCmdWait
    ActorWalkRoute 255, 342, 433, 0, 8, 0
    VMJump L_0D30

L_0D30:
    VMSleep 8
    ActorCmdExec 8, Movement_0E48
    ActorCmdWait
    ActorCmdExec 255, Movement_0E00
    ActorCmdWait
    EvCameraWait
    VMReturn

L_0D4C:
    ActorWalkRoute 8, 338, 433, 0, 6, 0
    VMSleep 8
    ActorCmdExec 13, Movement_0E38
    ActorCmdExec 14, Movement_0E20
    ActorCmdExec 15, Movement_0E18
    ActorCmdExec 16, Movement_0E40
    ActorCmdWait
    ActorCmdExec 14, Movement_0E38
    ActorCmdExec 15, Movement_0E40
    ActorCmdExec 17, Movement_0E40
    ActorCmdWait
    EvCameraMoveTo 9688, 0, 0xed000, 0x1528000, 0, 0x1b18000, 40
    EvCameraWait
    VMReturn

L_0DB6:
    ActorCmdExec 8, Movement_0E78
    VMSleep 18
    ActorCmdExec 13, Movement_0E50
    ActorCmdExec 14, Movement_0E50
    ActorCmdExec 15, Movement_0E50
    ActorCmdExec 16, Movement_0E50
    ActorCmdExec 17, Movement_0E50
    ActorCmdWait
    VMReturn
    .balign 4, 0

Movement_0DF0:
    Move 32, 1
    MoveEnd

Movement_0DF8:
    Move 33, 1
    MoveEnd

Movement_0E00:
    Move 34, 1
    MoveEnd

Movement_0E08:
    Move 35, 1
    MoveEnd

Movement_0E10:
    Move 38, 3
    MoveEnd

Movement_0E18:
    Move 13, 1
    MoveEnd

Movement_0E20:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd

Movement_0E38:
    Move 1, 1
    MoveEnd

Movement_0E40:
    Move 0, 1
    MoveEnd

Movement_0E48:
    Move 3, 1
    MoveEnd

Movement_0E50:
    Move 2, 1
    MoveEnd

Movement_0E58:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 161, 1
    MoveEnd
    Move 160, 1
    MoveEnd

Movement_0E78:
    Move 10, 1
    Move 14, 1
    Move 22, 8
    MoveEnd
    VMStackAdd
    VMNop2
    VMStackMul
    VMReturn
    .byte 0xfe
    .balign 4, 0
    Move 14, 1
    MoveEnd
    Move 12, 1
    MoveEnd

Movement_0EA4:
    Move 13, 2
    MoveEnd

Movement_0EAC:
    Move 15, 1
    Move 33, 1
    Move 15, 4
    MoveEnd

Movement_0EBC:
    Move 63, 1
    Move 32, 1
    Move 15, 5
    MoveEnd

Movement_0ECC:
    Move 13, 1
    Move 15, 5
    MoveEnd

Movement_0ED8:
    Move 34, 1
    Move 15, 5
    MoveEnd

Movement_0EE4:
    Move 15, 8
    MoveEnd

Movement_0EEC:
    Move 14, 6
    MoveEnd

Movement_0EF4:
    Move 14, 6
    MoveEnd

Movement_0EFC:
    Move 14, 6
    MoveEnd

Script_6:
    ActorsPauseAll
    TrainerCardHasBadge 0x8024, 3
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0F41
    SEPlay 1351
    ActorCmdExec 9, Movement_0E10
    ActorCmdWait
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0F5F

L_0F41:
    SEPlay 1351
    ActorSetEyeToEye
    ActorCmdExec 9, Movement_0E58
    ActorCmdWait
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0F5F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 27, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 37, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 435
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_1090
    ParentActorMsg 1024, 61, 0, 0
    FlagSet 435
    VMJump L_109A

L_1090:
    ParentActorMsg 1024, 62, 0, 0

L_109A:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_11DA
    Cmd_02B5 0, 1
    ParentActorMsg 1024, 63, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    Cmd_02B3 0, 0x802a
    WorkCmpConst 0x802a, 0
    VMJumpIf 1, L_10E8
    VMJump L_10F4

L_10E8:
    WorkSetConst 0x802b, 709
    VMJump L_1132

L_10F4:
    WorkCmpConst 0x802a, 1
    VMJumpIf 1, L_1107
    VMJump L_1113

L_1107:
    WorkSetConst 0x802b, 710
    VMJump L_1132

L_1113:
    WorkCmpConst 0x802a, 2
    VMJumpIf 1, L_1126
    VMJump L_1132

L_1126:
    WorkSetConst 0x802b, 711
    VMJump L_1132

L_1132:
    CallTrainerBattle 0x802b, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1159
    CallTrainerBattleEnd
    VMJump L_115B

L_1159:
    CallTrainerLose

L_115B:
    Cmd_02B5 0, 1
    ActorCmdExec 21, Movement_0DF8
    ActorCmdWait
    ParentActorMsg 1024, 65, 0, 0
    ParentActorMsg 1024, 66, 0, 0
    MsgWinCloseAll
    PlayerGetDir 0x8010
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_11AC
    ActorWalkRoute 21, 370, 438, 0, 8, 1
    VMJump L_11BA

L_11AC:
    ActorWalkRoute 21, 370, 439, 0, 8, 0

L_11BA:
    VMSleep 20
    ActorCmdExec 255, Movement_0E08
    ActorCmdWait
    ActorDelete 21
    FlagSet 978
    FlagSet 438
    VMJump L_11E8

L_11DA:
    ParentActorMsg 1024, 64, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_11E8:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    ItemCheckAmount 578, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_12D8
    SEPlay 1351
    ActorSetEyeToEye
    TrainerFlagGet 256, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_12C4
    TrainerBGMPlayPush 256
    ParentActorMsg 1024, 39, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 256, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_1265
    TrainerFlagSet 256
    CallTrainerBattleEnd
    VMJump L_1267

L_1265:
    CallTrainerLose

L_1267:
    MusicalIsPropOwned 84, 0x4001
    VMStackPush 0x4001
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_12B0
    ParentActorMsg 1024, 40, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8008, 84
    WorkSetConst 0x8009, 1
    RTCallGlobal 10466
    ParentActorMsg 1024, 41, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_12BE

L_12B0:
    ParentActorMsg 1024, 42, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_12BE:
    VMJump L_12D2

L_12C4:
    ParentActorMsg 1024, 41, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_12D2:
    VMJump L_12EC

L_12D8:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 38, 0, 0
    LastKeyWait
    ActorMsgClose

L_12EC:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 43, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 44, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
