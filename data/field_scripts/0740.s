#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 5, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 6, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 7, 0
    MsgPlaceSignClose
    FlagSet 2674
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    ActorCmdExec 255, Movement_03B4
    ActorCmdWait
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x2ac8000, 0, 0xbe8000, 32
    EvCameraWait
    VMStackPush 0x8022
    VMStackPushConst 187
    VMStackCmp 1
    VMJumpIf 255, L_00CB
    ActorCmdExec 21, Movement_03CC
    ActorCmdWait

L_00CB:
    PVPlay 638, 0
    ScreamMsg 0, 1
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    EvCameraMoveToDefault 32
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    WorkSetConst 0x40db, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 638, 0
    ScreamMsg 0, 1
    PVWait
    MsgWaitAdvance
    InfoMsgClose_0039
    VMStackPushFlag 302
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_013E
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8023, 1
    CallWildBattle 638, 45, 0x8023
    WorkSetConst 0x8023, 0
    VMJump L_0158

L_013E:
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8024, 1
    CallWildBattle 638, 65, 0x8024
    WorkSetConst 0x8024, 0

L_0158:
    WildBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0183
    FlagSet 802
    FlagSet 302
    ActorDelete 21
    CallWildBattleEnd
    VMJump L_0185

L_0183:
    CallWildLose

L_0185:
    WildBattleGetResult 0x8010
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_019C
    VMJump L_01A6

L_019C:
    FlagSet 303
    VMJump L_01CC

L_01A6:
    WorkCmpConst 0x8010, 1
    VMJumpIf 1, L_01C6
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_01C6
    VMJump L_01CC

L_01C6:
    VMJump L_01CC

L_01CC:
    VMStackPushFlag 303
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01E9
    SystemMsg 1, 2
    LastKeyWait
    InfoMsgClose

L_01E9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 218
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0238
    ParentActorMsg 1024, 2, 0, 0
    MsgWinCloseAll
    VMCall L_0289
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2738
    FlagSet 218
    VMJump L_0283

L_0238:
    VMStackPushFlag 2738
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0275
    ParentActorMsg 1024, 3, 0, 0
    MsgWinCloseAll
    VMCall L_0289
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2738
    VMJump L_0283

L_0275:
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0283:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0289:
    WorkSetConst 0x8025, 0
    Random 0x8025, 5
    WorkCmpConst 0x8025, 0
    VMJumpIf 1, L_02A8
    VMJump L_02CE

L_02A8:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 65
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_03B2

L_02CE:
    WorkCmpConst 0x8025, 1
    VMJumpIf 1, L_02E1
    VMJump L_0307

L_02E1:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 66
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_03B2

L_0307:
    WorkCmpConst 0x8025, 2
    VMJumpIf 1, L_031A
    VMJump L_0340

L_031A:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 67
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_03B2

L_0340:
    WorkCmpConst 0x8025, 3
    VMJumpIf 1, L_0353
    VMJump L_0379

L_0353:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 68
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_03B2

L_0379:
    WorkCmpConst 0x8025, 4
    VMJumpIf 1, L_038C
    VMJump L_03B2

L_038C:
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 69
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    VMJump L_03B2

L_03B2:
    VMReturn

Movement_03B4:
    Move 75, 1
    MoveEnd
    Move 35, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_03CC:
    Move 32, 1
    MoveEnd
    Move 33, 1
    MoveEnd
    Move 34, 1
    Move 75, 1
    MoveEnd
