#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 337
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_008A
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_004C
    VMCall L_009E
    VMJump L_0084

L_004C:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_006B
    VMCall L_0172
    VMJump L_0084

L_006B:
    VMStackPush 0x4030
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_0084
    VMCall L_0246

L_0084:
    VMJump L_0098

L_008A:
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0098:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_009E:
    VMStackPushFlag 336
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00C6
    WordSetPokeSpecies 0, 495
    ParentActorMsg 1024, 0, 0, 0
    MsgWaitAdvance
    FlagSet 336

L_00C6:
    ParentActorMsg 1024, 1, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00FB
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0170

L_00FB:
    ParentActorMsg 1024, 3, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0130
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0170

L_0130:
    ParentActorMsg 1024, 4, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 551
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 337

L_0170:
    VMReturn

L_0172:
    VMStackPushFlag 336
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_019A
    WordSetPokeSpecies 0, 498
    ParentActorMsg 1024, 0, 0, 0
    MsgWaitAdvance
    FlagSet 336

L_019A:
    ParentActorMsg 1024, 5, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0236
    ParentActorMsg 1024, 6, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0222
    ParentActorMsg 1024, 7, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 548
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 337
    VMJump L_0230

L_0222:
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0230:
    VMJump L_0244

L_0236:
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0244:
    VMReturn

L_0246:
    VMStackPushFlag 336
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_026E
    WordSetPokeSpecies 0, 501
    ParentActorMsg 1024, 0, 0, 0
    MsgWaitAdvance
    FlagSet 336

L_026E:
    ParentActorMsg 1024, 9, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02A3
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0318

L_02A3:
    ParentActorMsg 1024, 11, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_030A
    ParentActorMsg 1024, 12, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 549
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 13, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 337
    VMJump L_0318

L_030A:
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0318:
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
    WorkSet 0x8000, 4
    WorkSet 0x8001, 10
    WorkSet 0x8002, 103
    WorkSet 0x8003, 14
    WorkSet 0x8004, 15
    WorkSet 0x8005, 15
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
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 505, 0
    ParentActorMsg 1024, 16, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsg 1024, 17, 2, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0512
    ActorMsg 1024, 19, 2, 2, 0
    WorkSetConst 0x8020, 0
    Random 0x8020, 100
    WorkSetConst 0x8021, 0
    ListMenu_AnchorTopRight 31, 1, 0, 0, 32801
    ListMenuAdd 26, 65535, 0
    ListMenuAdd 27, 65535, 1
    ListMenuAdd 28, 65535, 2
    ListMenuShow
    VMStackPush 0x8021
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0468
    VMStackPush 0x8020
    VMStackPushConst 50
    VMStackCmp 4
    VMJumpIf 255, L_0452
    ActorMsg 1024, 20, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0462

L_0452:
    ActorMsg 1024, 21, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0462:
    VMJump L_050C

L_0468:
    VMStackPush 0x8021
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_04BA
    VMStackPush 0x8020
    VMStackPushConst 50
    VMStackCmp 4
    VMJumpIf 255, L_04A4
    ActorMsg 1024, 24, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_04B4

L_04A4:
    ActorMsg 1024, 25, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_04B4:
    VMJump L_050C

L_04BA:
    VMStackPush 0x8021
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_050C
    VMStackPush 0x8020
    VMStackPushConst 50
    VMStackCmp 4
    VMJumpIf 255, L_04F6
    ActorMsg 1024, 22, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0506

L_04F6:
    ActorMsg 1024, 23, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0506:
    VMJump L_050C

L_050C:
    VMJump L_0522

L_0512:
    ActorMsg 1024, 18, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_0522:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
