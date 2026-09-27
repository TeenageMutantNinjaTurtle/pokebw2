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
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0
    WorkSetConst 0x8028, 0
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0

Script_1:
    VMHalt

Script_2:
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_00FE
    VMStackPushFlag 972
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00F8
    FlagReset 972
    ActorAdd 10

L_00F8:
    VMJump L_0147

L_00FE:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_0147
    VMStackPushFlag 972
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_012C
    FlagReset 972
    ActorAdd 10

L_012C:
    VMStackPushFlag 973
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0147
    FlagReset 973
    ActorAdd 6

L_0147:
    VMHalt

Script_3:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 358, 0, 0x109000, 0x1c8000, 0x8501f, 0x158000, 1
    ActorCmdExec 255, Movement_0A54
    ActorCmdWait
    EvCameraWait
    MapChangeWarp 478, 7, 14, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 126, 1
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_019D:
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 0x802e
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F2
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_01D6
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_01D6
    VMJump L_01E6

L_01D6:
    ParentActorMsg 1024, 0x8022, 2, 0
    VMJump L_01F0

L_01E6:
    ParentActorMsg 1024, 0x8021, 2, 0

L_01F0:
    MoneyWinDisp 31, 1
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32808
    ListMenuAdd 155, 65535, 0
    ListMenuAdd 156, 65535, 1
    ListMenuShow
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02DC
    ItemCheckSpace 0x802b, 1, 0x8029
    MoneyCheck 0x802a, 0x802c
    VMStackPush 0x8029
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0259
    ParentActorMsg 1024, 0x8024, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02D6

L_0259:
    VMStackPush 0x802a
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0280
    ParentActorMsg 1024, 0x8025, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02D6

L_0280:
    SEPlay 1621
    MoneySub 0x802c
    MoneyWinUpdate
    SEWait
    ParentActorMsg 1024, 0x8023, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 0x802b
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 0x8026, 2, 0
    LastKeyWait
    MsgWinCloseAll
    RecordAdd 21, 1
    RecordAdd 22, 0x802c
    FlagSet 0x802e

L_02D6:
    VMJump L_02EA

L_02DC:
    ParentActorMsg 1024, 0x8026, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_02EA:
    MoneyWinClose
    VMJump L_0300

L_02F2:
    ParentActorMsg 1024, 0x8027, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0300:
    VMReturn

Script_5:
    ActorsPauseAll
    RTCGetWeekDay 0x802d
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_0328
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_0328
    VMJump L_033A

L_0328:
    WorkSetConst 0x802b, 226
    WorkSetConst 0x802c, 1000
    VMJump L_0346

L_033A:
    WorkSetConst 0x802b, 85
    WorkSetConst 0x802c, 1000

L_0346:
    WordSetItemNameWithArticle 0, 0x802b
    WordSetNumber 1, 0x802c, 4
    WorkSetConst 0x8021, 127
    WorkSetConst 0x8022, 128
    WorkSetConst 0x8023, 129
    WorkSetConst 0x8024, 130
    WorkSetConst 0x8025, 131
    WorkSetConst 0x8026, 132
    WorkSetConst 0x8027, 133
    WorkSetConst 0x802e, 2785
    VMCall L_019D
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    RTCGetWeekDay 0x802d
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_03B4
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_03B4
    VMJump L_03C6

L_03B4:
    WorkSetConst 0x802b, 227
    WorkSetConst 0x802c, 2000
    VMJump L_03D2

L_03C6:
    WorkSetConst 0x802b, 84
    WorkSetConst 0x802c, 2000

L_03D2:
    WordSetItemNameWithArticle 0, 0x802b
    WordSetNumber 1, 0x802c, 5
    WorkSetConst 0x8021, 134
    WorkSetConst 0x8022, 135
    WorkSetConst 0x8023, 136
    WorkSetConst 0x8024, 137
    WorkSetConst 0x8025, 138
    WorkSetConst 0x8026, 139
    WorkSetConst 0x8027, 140
    WorkSetConst 0x802e, 2786
    VMCall L_019D
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    RTCGetWeekDay 0x802d
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_0440
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_0440
    VMJump L_0452

L_0440:
    WorkSetConst 0x802b, 235
    WorkSetConst 0x802c, 4000
    VMJump L_045E

L_0452:
    WorkSetConst 0x802b, 107
    WorkSetConst 0x802c, 4000

L_045E:
    WordSetItemNameWithArticle 0, 0x802b
    WordSetNumber 1, 0x802c, 5
    WorkSetConst 0x8021, 141
    WorkSetConst 0x8022, 142
    WorkSetConst 0x8023, 143
    WorkSetConst 0x8024, 144
    WorkSetConst 0x8025, 145
    WorkSetConst 0x8026, 146
    WorkSetConst 0x8027, 147
    WorkSetConst 0x802e, 2787
    VMCall L_019D
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    RTCGetWeekDay 0x802d
    WorkCmpConst 0x802d, 6
    VMJumpIf 1, L_04CC
    WorkCmpConst 0x802d, 0
    VMJumpIf 1, L_04CC
    VMJump L_04DE

L_04CC:
    WorkSetConst 0x802b, 221
    WorkSetConst 0x802c, 6000
    VMJump L_04EA

L_04DE:
    WorkSetConst 0x802b, 110
    WorkSetConst 0x802c, 6000

L_04EA:
    WordSetItemNameWithArticle 0, 0x802b
    WordSetNumber 1, 0x802c, 5
    WorkSetConst 0x8021, 148
    WorkSetConst 0x8022, 149
    WorkSetConst 0x8023, 150
    WorkSetConst 0x8024, 151
    WorkSetConst 0x8025, 152
    WorkSetConst 0x8026, 153
    WorkSetConst 0x8027, 154
    WorkSetConst 0x802e, 2788
    VMCall L_019D
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_0565
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_05C9

L_0565:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_05A2
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_05C9

L_05A2:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_05C9
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    ActorMsgClose

L_05C9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_0602
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0669

L_0602:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_063F
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0669

L_063F:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_0669
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 18, 0, 0
    LastKeyWait
    ActorMsgClose

L_0669:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    WordSetPlayerName 0
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMJumpIf 255, L_06A5
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_06CC

L_06A5:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_06CC
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose

L_06CC:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_0705
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 48, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_076C

L_0705:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0742
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 49, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_076C

L_0742:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_076C
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 50, 0, 0
    LastKeyWait
    ActorMsgClose

L_076C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_07A5
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 68, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_080F

L_07A5:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_07E5
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 69, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_080F

L_07E5:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_080F
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 70, 0, 0
    LastKeyWait
    ActorMsgClose

L_080F:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_0848
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 76, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_08AC

L_0848:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0885
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 77, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_08AC

L_0885:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_08AC
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 78, 0, 0
    LastKeyWait
    ActorMsgClose

L_08AC:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    Cmd_02D1 0x8020
    VMStackPush 0x8020
    VMStackPushConst 4
    VMStackCmp 3
    VMJumpIf 255, L_08E5
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 104, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_094C

L_08E5:
    VMStackPush 0x8020
    VMStackPushConst 5
    VMStackCmp 4
    VMStackPush 0x8020
    VMStackPushConst 9
    VMStackCmp 3
    VMStackCmp 7
    VMJumpIf 255, L_0922
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 105, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_094C

L_0922:
    VMStackPush 0x8020
    VMStackPushConst 10
    VMStackCmp 4
    VMJumpIf 255, L_094C
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 106, 0, 0
    LastKeyWait
    ActorMsgClose

L_094C:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    WordSetPlayerName 0
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 116, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 518, 0
    ParentActorMsg 1024, 120, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_18:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 504, 0
    ParentActorMsg 1024, 121, 0, 0
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
    PVPlay 548, 0
    ParentActorMsg 1024, 122, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 531, 0
    ParentActorMsg 1024, 123, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_21:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 619, 0
    ParentActorMsg 1024, 124, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_22:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 524, 0
    ParentActorMsg 1024, 125, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
    Move 13, 1
    MoveEnd

Movement_0A54:
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
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
