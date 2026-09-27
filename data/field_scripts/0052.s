#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntry Script_8
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0

Script_1:
    RTCGetWeekDay 0x8020
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_003F
    VMJump L_0051

L_003F:
    WorkSetConst 0x4020, 43
    WorkSetConst 0x4021, 309
    VMJump L_012F

L_0051:
    WorkCmpConst 0x8020, 1
    VMJumpIf 1, L_0064
    VMJump L_0076

L_0064:
    WorkSetConst 0x4020, 52
    WorkSetConst 0x4021, 131
    VMJump L_012F

L_0076:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_0089
    VMJump L_009B

L_0089:
    WorkSetConst 0x4020, 45
    WorkSetConst 0x4021, 306
    VMJump L_012F

L_009B:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_00AE
    VMJump L_00C0

L_00AE:
    WorkSetConst 0x4020, 16
    WorkSetConst 0x4021, 126
    VMJump L_012F

L_00C0:
    WorkCmpConst 0x8020, 4
    VMJumpIf 1, L_00D3
    VMJump L_00E5

L_00D3:
    WorkSetConst 0x4020, 20
    WorkSetConst 0x4021, 128
    VMJump L_012F

L_00E5:
    WorkCmpConst 0x8020, 5
    VMJumpIf 1, L_00F8
    VMJump L_010A

L_00F8:
    WorkSetConst 0x4020, 64
    WorkSetConst 0x4021, 305
    VMJump L_012F

L_010A:
    WorkCmpConst 0x8020, 6
    VMJumpIf 1, L_011D
    VMJump L_012F

L_011D:
    WorkSetConst 0x4020, 53
    WorkSetConst 0x4021, 314
    VMJump L_012F

L_012F:
    VMHalt

Script_2:
    ActorsPauseAll
    VMStackPushFlag 2735
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0160
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_021A

L_0160:
    RTCGetWeekDay 0x8020
    VMStackPush 0x8020
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_01B5
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 1, 0, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 31
    WorkSet 0x8001, 1
    RTCallGlobal 2806
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 2735
    VMJump L_021A

L_01B5:
    VMStackPush 0x8020
    VMStackPushConst 6
    VMStackCmp 1
    VMJumpIf 255, L_0206
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 3, 0, 0, 0
    ActorMsgClose
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 32
    WorkSet 0x8001, 1
    RTCallGlobal 2806
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 2735
    VMJump L_021A

L_0206:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose

L_021A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x4020, 43
    VMJumpIf 1, L_023B
    VMJump L_0364

L_023B:
    VMStackPush 0x40dc
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02BD
    ParentActorMsg 1024, 5, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02A9
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 634
    WorkSet 0x8001, 1
    RTCallGlobal 2806
    VMStackPop 0x8001
    VMStackPop 0x8000
    WorkSetConst 0x40dc, 1
    VMJump L_02B7

L_02A9:
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_02B7:
    VMJump L_035E

L_02BD:
    VMStackPush 0x40dc
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02E4
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_035E

L_02E4:
    VMStackPush 0x40dc
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_033D
    ParentActorMsg 1024, 9, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 64
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40dc, 3
    VMJump L_035E

L_033D:
    VMStackPush 0x40dc
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_035E
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_035E:
    VMJump L_0584

L_0364:
    WorkCmpConst 0x4020, 52
    VMJumpIf 1, L_0377
    VMJump L_03B0

L_0377:
    VMStackPush 0x40dc
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_039C
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    VMJump L_03A8

L_039C:
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait

L_03A8:
    MsgWinCloseAll
    VMJump L_0584

L_03B0:
    WorkCmpConst 0x4020, 45
    VMJumpIf 1, L_03C3
    VMJump L_03FC

L_03C3:
    VMStackPush 0x40dc
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03E8
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    VMJump L_03F4

L_03E8:
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait

L_03F4:
    MsgWinCloseAll
    VMJump L_0584

L_03FC:
    WorkCmpConst 0x4020, 16
    VMJumpIf 1, L_040F
    VMJump L_0448

L_040F:
    VMStackPush 0x40dc
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0434
    ParentActorMsg 1024, 16, 0, 0
    LastKeyWait
    VMJump L_0440

L_0434:
    ParentActorMsg 1024, 15, 0, 0
    LastKeyWait

L_0440:
    MsgWinCloseAll
    VMJump L_0584

L_0448:
    WorkCmpConst 0x4020, 20
    VMJumpIf 1, L_045B
    VMJump L_04EC

L_045B:
    VMStackPush 0x40dc
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04B3
    ParentActorMsg 1024, 18, 0, 0
    MsgWinCloseAll
    WordSetPlayerName 0
    SEPlay 2017
    SystemMsg 19, 0
    MsgWaitAdvance
    InfoMsgClose
    SEWait
    WorkSetConst 0x8021, 0
    ItemSub 634, 1, 0x8021
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    WorkSetConst 0x40dc, 2
    VMJump L_04E4

L_04B3:
    VMStackPush 0x40dc
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_04D8
    ParentActorMsg 1024, 20, 0, 0
    LastKeyWait
    VMJump L_04E4

L_04D8:
    ParentActorMsg 1024, 17, 0, 0
    LastKeyWait

L_04E4:
    MsgWinCloseAll
    VMJump L_0584

L_04EC:
    WorkCmpConst 0x4020, 64
    VMJumpIf 1, L_04FF
    VMJump L_0538

L_04FF:
    VMStackPush 0x40dc
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0524
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    VMJump L_0530

L_0524:
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait

L_0530:
    MsgWinCloseAll
    VMJump L_0584

L_0538:
    WorkCmpConst 0x4020, 53
    VMJumpIf 1, L_054B
    VMJump L_0584

L_054B:
    VMStackPush 0x40dc
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0570
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    VMJump L_057C

L_0570:
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait

L_057C:
    MsgWinCloseAll
    VMJump L_0584

L_0584:
    WorkSetConst 0x8021, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    WorkCmpConst 0x4021, 309
    VMJumpIf 1, L_05AB
    VMJump L_05CD

L_05AB:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 511, 0
    ParentActorMsg 1024, 25, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_070B

L_05CD:
    WorkCmpConst 0x4021, 131
    VMJumpIf 1, L_05E0
    VMJump L_0602

L_05E0:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 552, 0
    ParentActorMsg 1024, 26, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_070B

L_0602:
    WorkCmpConst 0x4021, 306
    VMJumpIf 1, L_0615
    VMJump L_0637

L_0615:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 506, 0
    ParentActorMsg 1024, 27, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_070B

L_0637:
    WorkCmpConst 0x4021, 126
    VMJumpIf 1, L_064A
    VMJump L_066C

L_064A:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 517, 0
    ParentActorMsg 1024, 28, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_070B

L_066C:
    WorkCmpConst 0x4021, 128
    VMJumpIf 1, L_067F
    VMJump L_06A1

L_067F:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 504, 0
    ParentActorMsg 1024, 29, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_070B

L_06A1:
    WorkCmpConst 0x4021, 305
    VMJumpIf 1, L_06B4
    VMJump L_06D6

L_06B4:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 505, 0
    ParentActorMsg 1024, 30, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_070B

L_06D6:
    WorkCmpConst 0x4021, 314
    VMJumpIf 1, L_06E9
    VMJump L_070B

L_06E9:
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 559, 0
    ParentActorMsg 1024, 31, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    VMJump L_070B

L_070B:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 32, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 33, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 34, 0, 0
    LastKeyWait
    ActorMsgClose
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
    .balign 4, 0
