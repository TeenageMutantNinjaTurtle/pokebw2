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

Script_11:
    ActorsPauseAll
    FadeInBlackQ
    FadeWait
    CallPlaceNameDisp
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    WorkSetConst 0x8029, 0
    WorkSetConst 0x802a, 0
    WorkSetConst 0x802b, 0
    WorkSetConst 0x802c, 0
    WorkSetConst 0x802d, 0
    WorkSetConst 0x802e, 0
    RTCGetDate 0x802a, 0x8029
    ItemGetCount 134, 0x802b
    ItemCheckSpace 93, 1, 0x802c
    WordSetItemName 0, 93
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 34, 1, 0, 0
    VMStackPush 0x802a
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x802a
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0111
    VMStackPush 0x8029
    VMStackPushConst 14
    VMStackCmp 1
    VMJumpIf 255, L_0105
    WorkSetConst 0x802e, 5
    VMJump L_010B

L_0105:
    WorkSetConst 0x802e, 10

L_010B:
    VMJump L_0117

L_0111:
    WorkSetConst 0x802e, 10

L_0117:
    DebugPrint 0x802e
    DebugPrint 0x802b
    VMStackPush 0x802b
    VMStackPush 0x802e
    VMStackCmp 4
    VMJumpIf 255, L_01B0
    VMStackPush 0x802a
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x802a
    VMStackPushConst 3
    VMStackCmp 1
    VMStackCmp 6
    VMJumpIf 255, L_0198
    VMStackPush 0x8029
    VMStackPushConst 14
    VMStackCmp 1
    VMJumpIf 255, L_0180
    ActorMsg 1024, 36, 1, 0, 0
    VMCall L_0266
    VMJump L_0192

L_0180:
    ActorMsg 1024, 35, 1, 0, 0
    VMCall L_01C6

L_0192:
    VMJump L_01AA

L_0198:
    ActorMsg 1024, 35, 1, 0, 0
    VMCall L_01C6

L_01AA:
    VMJump L_01C0

L_01B0:
    ActorMsg 1024, 37, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01C0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_01C6:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0254
    VMStackPush 0x802c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0206
    ActorMsg 1024, 39, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_024E

L_0206:
    ActorCmdExec 1, Movement_0860
    ActorCmdWait
    ActorMsg 1024, 38, 1, 0, 0
    MsgWinCloseAll
    SystemMsg 41, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 93
    WorkSet 0x8001, 1
    RTCallGlobal 2802
    VMStackPop 0x8001
    VMStackPop 0x8000
    ItemSub 134, 10, 0x802d

L_024E:
    VMJump L_0264

L_0254:
    ActorMsg 1024, 40, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0264:
    VMReturn

L_0266:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02F4
    VMStackPush 0x802c
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02A6
    ActorMsg 1024, 39, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_02EE

L_02A6:
    ActorCmdExec 1, Movement_0860
    ActorCmdWait
    ActorMsg 1024, 38, 1, 0, 0
    MsgWinCloseAll
    SystemMsg 41, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 93
    WorkSet 0x8001, 1
    RTCallGlobal 2802
    VMStackPop 0x8001
    VMStackPop 0x8000
    ItemSub 134, 5, 0x802d

L_02EE:
    VMJump L_0304

L_02F4:
    ActorMsg 1024, 40, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0304:
    VMReturn

Script_2:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 244
    WorkSet 0x8001, 1
    WorkSet 0x8002, 121
    WorkSet 0x8003, 32
    WorkSet 0x8004, 33
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

Script_3:
    ActorsPauseAll
    TrainerCardHasBadge 0x8008, 5
    VMStackPush 0x40c2
    VMStackPushConst 3
    VMStackCmp 3
    VMStackPush 0x8008
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_03B9
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 0, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0524

L_03B9:
    VMStackPush 0x40c2
    VMStackPushConst 4
    VMStackCmp 1
    VMJumpIf 255, L_0524
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 290
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03FB
    ActorMsg 1024, 1, 4, 0, 0
    FlagSet 290
    VMJump L_0407

L_03FB:
    ActorMsg 1024, 4, 4, 0, 0

L_0407:
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0514
    ActorMsg 1024, 2, 4, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0840
    ActorCmdWait
    ActorMsg 1024, 6, 2, 0, 0
    MsgWinCloseAll
    FlagReset 769
    SEPlay 1369
    ActorAdd 3
    SEWait
    ActorWalkRoute 3, 18, 21, 1, 4, 1
    ActorCmdWait
    ActorCmdExec 3, Movement_0848
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0483
    VMJump L_0491

L_0483:
    ActorCmdExec 255, Movement_0850
    VMJump L_04BA

L_0491:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_04A4
    VMJump L_04BA

L_04A4:
    ActorCmdExec 255, Movement_0850
    ActorCmdExec 4, Movement_0850
    VMJump L_04BA

L_04BA:
    ActorCmdExec 2, Movement_0850
    ActorCmdWait
    ActorMsg 1024, 7, 3, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 8, 2, 1, 0
    MsgWinCloseAll
    ActorMsg 1024, 9, 4, 1, 0
    MsgWinCloseAll
    VMCall L_07D6
    FlagSet 767
    FlagSet 768
    FlagSet 769
    FlagSet 790
    FlagReset 1006
    WorkSetConst 0x40cb, 1
    VMJump L_0524

L_0514:
    ActorMsg 1024, 3, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0524:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 5, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkSetConst 0x802f, 0
    MedalIsObtained 0x802f, 57
    VMStackPush 0x802f
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_05AE
    VMStackPushFlag 375
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_059A
    ParentActorMsg 1024, 28, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 375
    VMJump L_05A8

L_059A:
    ParentActorMsg 1024, 29, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_05A8:
    VMJump L_05FA

L_05AE:
    VMStackPush 0x802f
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_05FA
    VMStackPushFlag 376
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_05EC
    ParentActorMsg 1024, 30, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 376
    VMJump L_05FA

L_05EC:
    ParentActorMsg 1024, 31, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_05FA:
    WorkSetConst 0x802f, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40cb
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0637
    ActorMsg 1024, 10, 6, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_07D0

L_0637:
    ItemCheckAmount 630, 1, 0x8020
    VMStackPush 0x8020
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06A5
    ActorMsg 1024, 11, 6, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_068F
    ActorMsg 1024, 12, 6, 2, 0
    MsgWinCloseAll
    VMCall L_07F6
    VMJump L_069F

L_068F:
    ActorMsg 1024, 13, 6, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_069F:
    VMJump L_07D0

L_06A5:
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 421
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0737
    ActorMsg 1024, 14, 6, 2, 0
    MsgWinCloseAll
    ActorCmdExec 6, Movement_0858
    ActorCmdWait
    ActorMsg 1024, 15, 6, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0721
    FlagSet 421
    ActorMsg 1024, 12, 6, 2, 0
    MsgWinCloseAll
    VMCall L_0816
    VMJump L_0731

L_0721:
    ActorMsg 1024, 13, 6, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0731:
    VMJump L_07D0

L_0737:
    ActorMsg 1024, 16, 6, 2, 0
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32801
    ListMenuAdd 17, 65535, 0
    ListMenuAdd 18, 65535, 1
    ListMenuAdd 19, 65535, 2
    ListMenuShow
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0793
    ActorMsg 1024, 12, 6, 2, 0
    MsgWinCloseAll
    VMCall L_07F6
    VMJump L_07D0

L_0793:
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_07C0
    ActorMsg 1024, 12, 6, 2, 0
    MsgWinCloseAll
    VMCall L_0816
    VMJump L_07D0

L_07C0:
    ActorMsg 1024, 13, 6, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_07D0:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_07D6:
    FadeOutBlackQ
    FadeWait
    FieldClose
    Call3DDemo 24, 0
    FieldOpen
    RTReserveScript 9
    MapChangeCore 458, 617, 65531, 305, 2
    VMReturn

L_07F6:
    FadeOutBlackQ
    FadeWait
    FieldClose
    Call3DDemo 24, 0
    FieldOpen
    RTReserveScript 9
    MapChangeCore 458, 616, 65531, 305, 1
    VMReturn

L_0816:
    FadeOutBlackQ
    FadeWait
    FieldClose
    Call3DDemo 24, 0
    FieldOpen
    RTReserveScript 3
    MapChangeCore 584, 21, 0, 31, 0
    VMReturn
    .balign 4, 0
    Move 35, 1
    MoveEnd

Movement_0840:
    Move 34, 1
    MoveEnd

Movement_0848:
    Move 32, 1
    MoveEnd

Movement_0850:
    Move 33, 1
    MoveEnd

Movement_0858:
    Move 75, 1
    MoveEnd

Movement_0860:
    Move 160, 1
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

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 572, 0
    ParentActorMsg 1024, 27, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 472
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_09A2
    ParentActorMsg 1024, 22, 0, 0
    VMCall L_09BC
    VMStackPush 0x8027
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_098E
    ParentActorMsg 1024, 23, 0, 0
    MsgWinCloseAll
    FadeEx 3, 0, 16, 4
    FadeExWait
    VMSleep 45
    FadeEx 3, 16, 0, 4
    FadeExWait
    ParentActorMsg 1024, 24, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 6
    WorkSet 0x8001, 5
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 472
    VMJump L_099C

L_098E:
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_099C:
    VMJump L_09B6

L_09A2:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose

L_09B6:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_09BC:
    WorkSetConst 0x8023, 0
    PokePartyGetCount 0x8022, 0

L_09C8:
    VMStackPush 0x8022
    VMStackPush 0x8023
    VMStackCmp 2
    VMJumpIf 255, L_0A5C
    PokePartyGetTypes 0x8024, 0x8025, 0x8023
    PokePartyIsEgg 0x8028, 0x8023
    VMStackPush 0x8024
    VMStackPushConst 13
    VMStackCmp 1
    VMStackPush 0x8024
    VMStackPushConst 2
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 13
    VMStackCmp 1
    VMStackPush 0x8025
    VMStackPushConst 2
    VMStackCmp 1
    VMStackCmp 6
    VMStackCmp 6
    VMStackCmp 6
    VMJumpIf 255, L_0A50
    VMStackPush 0x8028
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0A50
    PokePartyGetSpecies 0x8026, 0x8023
    WordSetPokeSpecies 0, 0x8026
    WorkSetConst 0x8027, 1

L_0A50:
    WorkAdd 0x8023, 1
    VMJump L_09C8

L_0A5C:
    VMReturn
    .balign 4, 0
