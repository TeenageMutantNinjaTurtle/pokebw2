#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkSetConst 0x8027, 0

Script_1:
    ActorsPauseAll
    VMStackPush 0x4107
    VMStackPushConst 1
    VMStackCmp 3
    VMJumpIf 255, L_005F
    VMCall L_00E8
    VMJump L_00E2

L_005F:
    ISSSwitchQuery 0x8010, 1
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00D5
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00C1
    ParentActorMsg 1024, 9, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0480
    ActorCmdWait
    ISSSwitchEnable 1
    VMJump L_00CF

L_00C1:
    ParentActorMsg 1024, 10, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_00CF:
    VMJump L_00E2

L_00D5:
    SEPlay 1351
    InfoMsg 11, 2
    LastKeyWait
    MsgWinCloseAll

L_00E2:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_00E8:
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x4107
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0243
    PokePartyGetCount 0x8023, 0

L_0107:
    VMStackPush 0x8023
    VMStackPush 0x8024
    VMStackCmp 2
    VMJumpIf 255, L_015B
    PokePartyGetSpecies 0x8025, 0x8024
    PokePartyIsEgg 0x8027, 0x8024
    VMStackPush 0x8025
    VMStackPushConst 401
    VMStackCmp 1
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_014F
    WorkSetConst 0x8026, 1

L_014F:
    WorkAdd 0x8024, 1
    VMJump L_0107

L_015B:
    ParentActorMsg 1024, 0, 0, 0
    ParentActorMsg 1024, 1, 0, 0
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0239
    MsgWaitAdvance
    MsgWinCloseAll
    PVPlay 401, 0
    PVWait
    ActorCmdExec 0, Movement_04A0
    ActorCmdWait
    VMSleep 8
    ParentActorMsg 1024, 2, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0480
    ActorCmdWait
    VMSleep 32
    PlayerGetDir 0x8020
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_01CD
    VMJump L_01DB

L_01CD:
    ActorCmdExec 0, Movement_0488
    VMJump L_021D

L_01DB:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_01EE
    VMJump L_01FC

L_01EE:
    ActorCmdExec 0, Movement_0498
    VMJump L_021D

L_01FC:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_020F
    VMJump L_021D

L_020F:
    ActorCmdExec 0, Movement_0490
    VMJump L_021D

L_021D:
    ActorCmdWait
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x4107, 1
    VMJump L_023D

L_0239:
    LastKeyWait
    MsgWinCloseAll

L_023D:
    VMJump L_03CC

L_0243:
    VMStackPush 0x4107
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03CC
    PokePartyGetCount 0x8023, 0

L_025C:
    VMStackPush 0x8023
    VMStackPush 0x8024
    VMStackCmp 2
    VMJumpIf 255, L_02B0
    PokePartyGetSpecies 0x8025, 0x8024
    PokePartyIsEgg 0x8027, 0x8024
    VMStackPush 0x8025
    VMStackPushConst 293
    VMStackCmp 1
    VMStackPush 0x8027
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_02A4
    WorkSetConst 0x8026, 1

L_02A4:
    WorkAdd 0x8024, 1
    VMJump L_025C

L_02B0:
    ParentActorMsg 1024, 4, 0, 0
    VMStackPush 0x8026
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_03C8
    MsgWaitAdvance
    MsgWinCloseAll
    PVPlay 293, 0
    PVWait
    ActorCmdExec 0, Movement_04A0
    ActorCmdWait
    VMSleep 8
    ParentActorMsg 1024, 5, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0480
    ActorCmdWait
    VMSleep 16
    ActorCmdExec 0, Movement_04A8
    ActorCmdWait
    ActorCmdExec 0, Movement_0480
    ActorCmdWait
    VMSleep 32
    PlayerGetDir 0x8020
    WorkCmpConst 0x8020, 0
    VMJumpIf 1, L_0332
    VMJump L_0340

L_0332:
    ActorCmdExec 0, Movement_0488
    VMJump L_0382

L_0340:
    WorkCmpConst 0x8020, 3
    VMJumpIf 1, L_0353
    VMJump L_0361

L_0353:
    ActorCmdExec 0, Movement_0498
    VMJump L_0382

L_0361:
    WorkCmpConst 0x8020, 2
    VMJumpIf 1, L_0374
    VMJump L_0382

L_0374:
    ActorCmdExec 0, Movement_0490
    VMJump L_0382

L_0382:
    ActorCmdWait
    ParentActorMsg 1024, 6, 0, 0
    ParentActorMsg 1024, 7, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 277
    WorkSet 0x8001, 1
    RTCallGlobal 2802
    VMStackPop 0x8001
    VMStackPop 0x8000
    WorkSetConst 0x4107, 2
    VMJump L_03CC

L_03C8:
    LastKeyWait
    MsgWinCloseAll

L_03CC:
    VMReturn

Script_2:
    ActorsPauseAll
    ISSSwitchQuery 0x8010, 2
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0446
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 12, 0, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0432
    ParentActorMsg 1024, 13, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0488
    ActorCmdWait
    ISSSwitchEnable 2
    VMJump L_0440

L_0432:
    ParentActorMsg 1024, 14, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0440:
    VMJump L_0453

L_0446:
    SEPlay 1351
    InfoMsg 15, 2
    LastKeyWait
    MsgWinCloseAll

L_0453:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 572, 0
    ParentActorMsg 1024, 16, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0480:
    Move 32, 1
    MoveEnd

Movement_0488:
    Move 33, 1
    MoveEnd

Movement_0490:
    Move 35, 1
    MoveEnd

Movement_0498:
    Move 34, 1
    MoveEnd

Movement_04A0:
    Move 75, 1
    MoveEnd

Movement_04A8:
    Move 61, 1
    Move 35, 1
    Move 34, 1
    Move 61, 1
    MoveEnd
