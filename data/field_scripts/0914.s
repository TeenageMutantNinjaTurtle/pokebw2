#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntry Script_7
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_6:
    WorkCmpConst 0x40dd, 0
    VMJumpIf 1, L_0043
    VMJump L_0055

L_0043:
    ActorSetGPos 7, 29, 0, 32, 0
    VMJump L_009F

L_0055:
    WorkCmpConst 0x40dd, 1
    VMJumpIf 1, L_0068
    VMJump L_007A

L_0068:
    ActorSetGPos 7, 8, 0, 47, 2
    VMJump L_009F

L_007A:
    WorkCmpConst 0x40dd, 2
    VMJumpIf 1, L_008D
    VMJump L_009F

L_008D:
    ActorSetGPos 7, 20, 0xffff, 58, 3
    VMJump L_009F

L_009F:
    VMHalt

Script_1:
    ActorsPauseAll
    VMStackPushFlag 306
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0109
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F5
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 306
    VMJump L_0103

L_00F5:
    ParentActorMsg 1024, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0103:
    VMJump L_01BA

L_0109:
    VMStackPushFlag 307
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 308
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 309
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_01A6
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 619
    WorkSet 0x8001, 1
    WorkSet 0x8002, 465
    WorkSet 0x8003, 4
    WorkSet 0x8004, 5
    WorkSet 0x8005, 5
    RTGetTextFile 0x8006
    RTCallGlobal 2800
    VMStackPop 0x8006
    VMStackPop 0x8005
    VMStackPop 0x8004
    VMStackPop 0x8003
    VMStackPop 0x8002
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_01BA

L_01A6:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose

L_01BA:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 306
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01EF
    ParentActorMsg 1024, 6, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_025D

L_01EF:
    VMStackPushFlag 307
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0216
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_025D

L_0216:
    ParentActorMsg 1024, 7, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 203, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0249
    CallTrainerBattleEnd
    VMJump L_024B

L_0249:
    CallTrainerLose

L_024B:
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 307

L_025D:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 306
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0292
    ParentActorMsg 1024, 9, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0300

L_0292:
    VMStackPushFlag 308
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02B9
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0300

L_02B9:
    ParentActorMsg 1024, 10, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 204, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_02EC
    CallTrainerBattleEnd
    VMJump L_02EE

L_02EC:
    CallTrainerLose

L_02EE:
    ParentActorMsg 1024, 11, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 308

L_0300:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 306
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0335
    ParentActorMsg 1024, 12, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03A3

L_0335:
    VMStackPushFlag 309
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_035C
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03A3

L_035C:
    ParentActorMsg 1024, 13, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 205, 0, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_038F
    CallTrainerBattleEnd
    VMJump L_0391

L_038F:
    CallTrainerLose

L_0391:
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 309

L_03A3:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    WorkCmpConst 0x40dd, 0
    VMJumpIf 1, L_03C2
    VMJump L_04C6

L_03C2:
    ParentActorMsg 1024, 15, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 7, Movement_0850
    ActorCmdWait
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_03F1
    VMJump L_03FF

L_03F1:
    ActorCmdExec 7, Movement_0838
    VMJump L_0441

L_03FF:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0412
    VMJump L_0420

L_0412:
    ActorCmdExec 7, Movement_0840
    VMJump L_0441

L_0420:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0433
    VMJump L_0441

L_0433:
    ActorCmdExec 7, Movement_0848
    VMJump L_0441

L_0441:
    ActorCmdWait
    ParentActorMsg 1024, 16, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0464
    VMJump L_0472

L_0464:
    ActorCmdExec 7, Movement_0780
    VMJump L_04A0

L_0472:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0492
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0492
    VMJump L_04A0

L_0492:
    ActorCmdExec 7, Movement_078C
    VMJump L_04A0

L_04A0:
    VMSleep 16
    ActorCmdExec 255, Movement_0838
    ActorCmdWait
    ActorSetGPos 7, 8, 0, 47, 2
    WorkSetConst 0x40dd, 1
    VMJump L_0710

L_04C6:
    WorkCmpConst 0x40dd, 1
    VMJumpIf 1, L_04D9
    VMJump L_05F1

L_04D9:
    ParentActorMsg 1024, 17, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 7, Movement_0850
    ActorCmdWait
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0508
    VMJump L_0516

L_0508:
    ActorCmdExec 7, Movement_0838
    VMJump L_0558

L_0516:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_0529
    VMJump L_0537

L_0529:
    ActorCmdExec 7, Movement_0848
    VMJump L_0558

L_0537:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_054A
    VMJump L_0558

L_054A:
    ActorCmdExec 7, Movement_0830
    VMJump L_0558

L_0558:
    ActorCmdWait
    ParentActorMsg 1024, 18, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_057B
    VMJump L_0589

L_057B:
    ActorCmdExec 7, Movement_0794
    VMJump L_05CB

L_0589:
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_059C
    VMJump L_05AA

L_059C:
    ActorCmdExec 7, Movement_07A8
    VMJump L_05CB

L_05AA:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_05BD
    VMJump L_05CB

L_05BD:
    ActorCmdExec 7, Movement_07B8
    VMJump L_05CB

L_05CB:
    VMSleep 16
    ActorCmdExec 255, Movement_0848
    ActorCmdWait
    ActorSetGPos 7, 20, 0xffff, 58, 3
    WorkSetConst 0x40dd, 2
    VMJump L_0710

L_05F1:
    WorkCmpConst 0x40dd, 2
    VMJumpIf 1, L_0604
    VMJump L_0710

L_0604:
    ParentActorMsg 1024, 19, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_0629
    VMJump L_0637

L_0629:
    ActorCmdExec 7, Movement_0840
    VMJump L_0658

L_0637:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_064A
    VMJump L_0658

L_064A:
    ActorCmdExec 7, Movement_0830
    VMJump L_0658

L_0658:
    ActorCmdWait
    VMStackPushFlag 310
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_06F6
    ParentActorMsg 1024, 20, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ItemCheckSpace 38, 1, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_06C6
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 38
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 310
    VMCall L_0716
    VMJump L_06F0

L_06C6:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 38
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorCmdExec 7, Movement_0848
    ActorCmdWait

L_06F0:
    VMJump L_070A

L_06F6:
    ParentActorMsg 1024, 21, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMCall L_0716

L_070A:
    VMJump L_0710

L_0710:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0716:
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_072D
    VMJump L_073B

L_072D:
    ActorCmdExec 7, Movement_07E0
    VMJump L_075C

L_073B:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_074E
    VMJump L_075C

L_074E:
    ActorCmdExec 7, Movement_07CC
    VMJump L_075C

L_075C:
    VMSleep 16
    ActorCmdExec 255, Movement_0840
    ActorCmdWait
    ActorSetGPos 7, 29, 0, 32, 0
    WorkSetConst 0x40dd, 0
    VMReturn
    .balign 4, 0

Movement_0780:
    Move 15, 1
    Move 13, 8
    MoveEnd

Movement_078C:
    Move 13, 8
    MoveEnd

Movement_0794:
    Move 15, 1
    Move 13, 1
    Move 15, 6
    Move 13, 5
    MoveEnd

Movement_07A8:
    Move 13, 1
    Move 15, 7
    Move 13, 5
    MoveEnd

Movement_07B8:
    Move 15, 1
    Move 13, 2
    Move 15, 6
    Move 13, 5
    MoveEnd

Movement_07CC:
    Move 14, 1
    Move 12, 1
    Move 14, 3
    Move 12, 8
    MoveEnd

Movement_07E0:
    Move 12, 1
    Move 14, 4
    Move 12, 8
    MoveEnd
    Move 13, 1
    MoveEnd
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

Movement_0830:
    Move 32, 1
    MoveEnd

Movement_0838:
    Move 33, 1
    MoveEnd

Movement_0840:
    Move 34, 1
    MoveEnd

Movement_0848:
    Move 35, 1
    MoveEnd

Movement_0850:
    Move 75, 1
    MoveEnd

Script_7:
    ActorsPauseAll
    VMStackPushFlag 467
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_08F2
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    PokeDexCheckHabitatList 456, 0, 0, 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_08DE
    ParentActorMsg 1024, 24, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 3
    WorkSet 0x8001, 5
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 467
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_08EC

L_08DE:
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_08EC:
    VMJump L_0906

L_08F2:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose

L_0906:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
