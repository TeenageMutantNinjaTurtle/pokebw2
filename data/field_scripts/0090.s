#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd

Script_1:
    ActorsPauseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    VMStackPush 0x8002
    VMStackPush 0x8003
    VMStackPush 0x8004
    VMStackPush 0x8005
    VMStackPush 0x8006
    WorkSet 0x8000, 232
    WorkSet 0x8001, 1
    WorkSet 0x8002, 143
    WorkSet 0x8003, 0
    WorkSet 0x8004, 1
    WorkSet 0x8005, 1
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

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 210
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00F5
    ParentActorMsg 1024, 2, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 501, 0, 0
    VMCall L_0109
    ParentActorMsg 1024, 3, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 15
    WorkSet 0x8001, 2
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 210
    VMJump L_0103

L_00F5:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0103:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0109:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0128
    CallTrainerBattleEnd
    VMJump L_012A

L_0128:
    CallTrainerLose

L_012A:
    VMReturn

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 362
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01A7
    ParentActorMsg 1024, 5, 0, 0
    MsgWinCloseAll
    CallTrainerBattle 502, 0, 0
    VMCall L_0109
    ParentActorMsg 1024, 6, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 10
    WorkSet 0x8001, 5
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 362
    VMJump L_01B5

L_01A7:
    ParentActorMsg 1024, 7, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_01B5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
