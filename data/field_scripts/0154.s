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
    ScriptEntriesEnd

Script_10:
    VMStackPush 0x4087
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_006F
    ActorSetGPos 11, 14, 0, 13, 0
    VMJump L_008E

L_006F:
    VMStackPush 0x4087
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_008E
    ActorSetGPos 11, 14, 0, 14, 1

L_008E:
    VMHalt

Script_11:
    ActorsPauseAll
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    Cmd_02B4 1, 0x8020
    ActorCmdExec 255, Movement_04BC
    ActorCmdWait
    ActorCmdExec 11, Movement_04C4
    ActorCmdWait
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01EA
    ActorMsg 1024, 38, 11, 0, 0
    MsgWinCloseAll
    VMSleep 16
    ActorCmdExec 11, Movement_0484
    ActorCmdWait
    ActorMsg 1024, 39, 11, 0, 0
    WorkSetConst 0x8022, 0
    YesNoWin 0x8022
    VMStackPush 0x8022
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0122
    ActorMsg 1024, 40, 11, 0, 0
    VMJump L_012E

L_0122:
    ActorMsg 1024, 41, 11, 0, 0

L_012E:
    WorkSetConst 0x8022, 0
    MsgWinCloseAll
    VMSleep 16
    ActorCmdExec 11, Movement_0484
    ActorCmdWait
    Cmd_02B5 1, 0
    ActorMsg 1024, 42, 11, 0, 0
    MsgWinCloseAll
    SystemMsg 55, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01D6
    SystemMsg 56, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01C2
    MsgWinCloseAll
    WorkSetConst 0x4087, 1
    ActorMsg 1024, 53, 11, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 606, 14, 0, 15, 1
    VMJump L_01D0

L_01C2:
    MsgWinCloseAll
    VMCall L_02FA
    VMCall L_026E

L_01D0:
    VMJump L_01E4

L_01D6:
    MsgWinCloseAll
    VMCall L_02FA
    VMCall L_026E

L_01E4:
    VMJump L_025C

L_01EA:
    ActorMsg 1024, 0, 11, 0, 0
    MsgWinCloseAll
    VMSleep 16
    ActorCmdExec 11, Movement_0484
    ActorCmdWait
    ActorMsg 1024, 1, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_04F0
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 578
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorCmdExec 11, Movement_0504
    ActorCmdWait
    ActorMsg 1024, 2, 11, 0, 0
    MsgWinCloseAll
    VMCall L_026E

L_025C:
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_026E:
    Cmd_0167 0, 0, 0, 0
    WorkSetConst 0x8023, 0
    Cmd_0165 11, 0, 0x8023
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02B8
    VMSleep 16
    ActorCmdExec 11, Movement_0484
    ActorCmdWait
    ActorMsg 1024, 3, 11, 0, 0
    VMJump L_02BE

L_02B8:
    VMCall L_034E

L_02BE:
    WorkSetConst 0x8023, 0
    Cmd_0167 1, 0, 0, 0
    ActorMsg 1024, 8, 11, 0, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_0514
    ActorCmdWait
    ActorSetGPos 11, 17, 6, 3, 1
    WorkSetConst 0x4087, 2
    VMReturn

L_02FA:
    ActorMsg 1024, 48, 11, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 11, Movement_04F0
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 578
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorCmdExec 11, Movement_0504
    ActorCmdWait
    ActorMsg 1024, 2, 11, 0, 0
    MsgWinCloseAll
    VMReturn

L_034E:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0

L_035A:
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_039A
    Cmd_016A 0x8025, 0x8024
    VMStackPush 0x8025
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0394
    ActorMsg 1024, 5, 11, 0, 0
    MsgWinCloseAll

L_0394:
    VMJump L_035A

L_039A:
    ActorMsg 1024, 6, 11, 0, 0
    MsgWinCloseAll
    FadeOutBlackQ
    BGMPush 6
    FadeWait
    FieldClose
    Cmd_0164 0x8024
    FieldOpen
    FadeInWhiteQ
    BGMPop 0, 60
    FadeWait
    Cmd_0165 13, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03EE
    ActorMsg 1024, 4, 11, 0, 0
    VMJump L_03FA

L_03EE:
    ActorMsg 1024, 7, 11, 0, 0

L_03FA:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    VMReturn

Script_17:
    ActorsPauseAll
    WorkSetConst 0x8026, 0
    FadeInBlackQ
    FadeWait
    ActorMsg 1024, 54, 11, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 11, Movement_04F0
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 578
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorCmdExec 11, Movement_0504
    ActorCmdWait
    Cmd_02B7 0x8026
    ActorMsg 1024, 43, 11, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x404b, 1
    VMCall L_026E
    WorkSetConst 0x8026, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0484:
    Move 75, 1
    MoveEnd
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 12, 3
    Move 63, 1
    Move 35, 1
    MoveEnd

Movement_04BC:
    Move 12, 4
    MoveEnd

Movement_04C4:
    Move 1, 1
    Move 75, 1
    Move 13, 1
    MoveEnd
    Move 14, 1
    Move 33, 1
    Move 63, 1
    Move 15, 1
    Move 33, 1
    Move 63, 1
    MoveEnd

Movement_04F0:
    Move 13, 1
    Move 63, 2
    Move 33, 1
    Move 63, 1
    MoveEnd

Movement_0504:
    Move 71, 1
    Move 12, 1
    Move 72, 1
    MoveEnd

Movement_0514:
    Move 14, 9
    MoveEnd
    VMStackSub
    VMHalt
    VMStackDiv
    VMNop2
    VMStackSub
    VMHalt
    .byte 0xfe
    .byte 0x00
    VMNop

Script_12:
    ActorsPauseAll
    SEPlay 1351
    Cmd_0165 7, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_055E
    InfoMsg 27, 2
    MsgWinCloseAll
    Cmd_0163 0, 2
    VMJump L_0567

L_055E:
    InfoMsg 28, 2
    LastKeyWait
    MsgWinCloseAll

L_0567:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 34, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
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
    ActorSetEyeToEye
    ParentActorMsg 1024, 30, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0
    SEPlay 1351
    ActorSetEyeToEye
    Cmd_02B4 1, 0x8028
    Cmd_02B6 0, 0x8027
    VMStackPush 0x8028
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0750
    MusicalGetOwnedPropCount 0x802a
    Cmd_02B5 1, 0
    VMStackPush 0x802a
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06AE
    ActorMsg 1024, 44, 11, 0, 0
    ActorMsg 1024, 53, 11, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 606, 14, 0, 15, 1
    VMJump L_074A

L_06AE:
    ActorMsg 1024, 44, 11, 0, 0
    MsgWinCloseAll
    SystemMsg 55, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0738
    SystemMsg 56, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0720
    MsgWinCloseAll
    ActorMsg 1024, 53, 11, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 606, 14, 0, 15, 1
    VMJump L_0732

L_0720:
    MsgWinCloseAll
    ActorMsg 1024, 48, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0732:
    VMJump L_074A

L_0738:
    MsgWinCloseAll
    ActorMsg 1024, 48, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_074A:
    VMJump L_0756

L_0750:
    VMCall L_0804

L_0756:
    WorkSetConst 0x802a, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8027, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    WorkSetConst 0x802b, 0
    FadeInBlackQ
    FadeWait
    Cmd_02B7 0x802b
    VMStackPush 0x802b
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07C8
    WordSetPlayerName 0
    MEPlay 1303
    SystemMsg 46, 0
    MEWait
    InfoMsgClose
    ActorMsg 1024, 54, 11, 0, 0
    MsgWaitAdvance
    ActorMsg 1024, 45, 11, 0, 0
    VMJump L_07EE

L_07C8:
    ActorMsg 1024, 54, 11, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 11, Movement_0484
    ActorCmdWait
    ActorMsg 1024, 49, 11, 0, 0

L_07EE:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x404b, 1
    WorkSetConst 0x802b, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0804:
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802c, 0
    Cmd_0165 15, 24, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08AB
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x8030, 0
    TrainerCardGetBirthDate 0x802e, 0x802d
    RTCGetDate 0x8030, 0x802f
    VMStackPush 0x802e
    VMStackPush 0x8030
    VMStackCmp 1
    VMStackPush 0x802d
    VMStackPush 0x802f
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0893
    WorkSetConst 0x802c, 1
    ParentActorMsg 1024, 17, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8008, 24
    WorkSetConst 0x8009, 0
    RTCallGlobal 10466

L_0893:
    WorkSetConst 0x8030, 0
    WorkSetConst 0x802f, 0
    WorkSetConst 0x802e, 0
    WorkSetConst 0x802d, 0

L_08AB:
    VMStackPush 0x802c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0921
    Cmd_0165 15, 67, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0921
    FlagGet 243, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0921
    WorkSetConst 0x802c, 1
    ParentActorMsg 1024, 11, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8008, 67
    WorkSetConst 0x8009, 1
    RTCallGlobal 10466
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0921:
    VMStackPush 0x802c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0998
    Cmd_0165 15, 55, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0998
    Cmd_0165 1, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 5
    VMStackCmp 4
    VMJumpIf 255, L_0998
    WorkSetConst 0x802c, 1
    ParentActorMsg 1024, 13, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8008, 55
    WorkSetConst 0x8009, 1
    RTCallGlobal 10466
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0998:
    VMStackPush 0x802c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A0F
    Cmd_0165 15, 82, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A0F
    Cmd_0165 1, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_0A0F
    WorkSetConst 0x802c, 1
    ParentActorMsg 1024, 15, 0, 0
    MsgWinCloseAll
    WorkSetConst 0x8008, 82
    WorkSetConst 0x8009, 1
    RTCallGlobal 10466
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0A0F:
    VMStackPush 0x802c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A30
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0A30:
    WorkSetConst 0x802c, 0
    VMReturn

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 552, 0
    ParentActorMsg 1024, 20, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    Cmd_0165 1, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 2
    VMStackCmp 0
    VMJumpIf 255, L_0A98
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0AD9

L_0A98:
    VMStackPush 0x8010
    VMStackPushConst 5
    VMStackCmp 0
    VMJumpIf 255, L_0AC5
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0AD9

L_0AC5:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    ActorMsgClose

L_0AD9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    FlagGet 242, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0B52
    Cmd_0165 6, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0B38
    WordSetMusicalInfo 7, 0, 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 19, 0, 0
    LastKeyWait
    ActorMsgClose
    FlagSet 242
    VMJump L_0B4C

L_0B38:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose

L_0B4C:
    VMJump L_0B66

L_0B52:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose

L_0B66:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 376
    WorkSet 0x8001, 1
    WorkSet 0x8002, 211
    WorkSet 0x8003, 31
    WorkSet 0x8004, 32
    WorkSet 0x8005, 33
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

Script_15:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 35, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    WorkSetConst 0x8031, 0
    WorkSetConst 0x8032, 0
    WorkSetConst 0x8033, 0
    Cmd_02B4 1, 0x8031
    Cmd_02B6 1, 0x8032
    Cmd_0165 0, 0, 0x8033
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x8031
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0C44
    ParentActorMsg 1024, 50, 0, 0
    VMJump L_0C87

L_0C44:
    Cmd_02B5 1, 0
    VMStackPush 0x8032
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x8033
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0C7D
    ParentActorMsg 1024, 51, 0, 0
    VMJump L_0C87

L_0C7D:
    ParentActorMsg 1024, 52, 0, 0

L_0C87:
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8033, 0
    WorkSetConst 0x8032, 0
    WorkSetConst 0x8031, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
