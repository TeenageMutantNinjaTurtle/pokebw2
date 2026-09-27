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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0

Script_21:
    VMCall L_0213
    VMHalt

Script_1:
    VMStackPush 0x407c
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPushFlag 447
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_00A5
    ActorSetGPos 2, 13, 0, 11, 0

L_00A5:
    VMStackPushFlag 695
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00C4
    ActorSetGPos 9, 12, 3, 4, 1

L_00C4:
    GameGetVersion 0x8010
    DebugPrint 0x8010
    WorkCmpConst 0x8010, 23
    VMJumpIf 1, L_00DF
    VMJump L_00EB

L_00DF:
    WorkSetConst 0x4020, 143
    VMJump L_010A

L_00EB:
    WorkCmpConst 0x8010, 22
    VMJumpIf 1, L_00FE
    VMJump L_010A

L_00FE:
    WorkSetConst 0x4020, 144
    VMJump L_010A

L_010A:
    VMHalt

Script_2:
    Cmd_02B2 12, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4046
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 495
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_014F
    FlagReset 695
    WorkSetConst 0x4140, 1

L_014F:
    VMStackPush 0x400f
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4046
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPushFlag 495
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_018C
    FlagSet 695
    WorkSetConst 0x4140, 2

L_018C:
    VMCall L_01DE
    FlagReset 495
    GameGetVersion 0x8010
    DebugPrint 0x8010
    WorkCmpConst 0x8010, 23
    VMJumpIf 1, L_01B1
    VMJump L_01BD

L_01B1:
    WorkSetConst 0x4020, 143
    VMJump L_01DC

L_01BD:
    WorkCmpConst 0x8010, 22
    VMJumpIf 1, L_01D0
    VMJump L_01DC

L_01D0:
    WorkSetConst 0x4020, 144
    VMJump L_01DC

L_01DC:
    VMHalt

L_01DE:
    Cmd_02B2 12, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4046
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_0211
    FlagSet 695
    WorkSetConst 0x4140, 0

L_0211:
    VMReturn

L_0213:
    Cmd_02B2 12, 0x400f
    VMStackPush 0x400f
    VMStackPushConst 0
    VMStackCmp 1
    VMStackPush 0x4046
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_025D
    VMStackPushFlag 695
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0253
    ActorDelete 9

L_0253:
    FlagSet 695
    WorkSetConst 0x4140, 0

L_025D:
    VMReturn

Script_18:
    ActorsPauseAll
    ActorCmdExec 9, Movement_08C4
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8022
    VMStackPushConst 3
    VMStackCmp 1
    VMJumpIf 255, L_0294
    ActorCmdExec 9, Movement_08EC
    ActorCmdWait
    VMJump L_02C7

L_0294:
    WorkSub 0x8022, 2
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 5
    VMJumpIf 255, L_02C7
    ActorWalkRoute 9, 0x8021, 0x8022, 0, 8, 0
    ActorCmdWait
    ActorCmdExec 9, Movement_08F4
    ActorCmdWait

L_02C7:
    ActorMsg 1024, 28, 9, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 598, 5, 1, 4, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_20:
    ActorsPauseAll
    FlagReset 695
    ActorWalkRoute 255, 12, 6, 0, 8, 1
    ActorCmdWait
    ActorAdd 9
    SEPlay 1369
    ActorSetGPos 9, 12, 0, 2, 1
    SEWait
    ActorCmdExec 255, Movement_08EC
    ActorCmdWait
    ActorWalkRoute 9, 12, 4, 4, 8, 1
    ActorCmdWait
    ActorMsg 1024, 28, 9, 0, 0
    MsgWinCloseAll
    FadeOutBlack
    RTReserveScript 1
    FadeWait
    MapChangeCore 598, 5, 1, 4, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_19:
    ActorsPauseAll
    FadeInBlack
    FadeWait
    ActorMsg 1024, 29, 9, 0, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorWalkRoute 9, 12, 2, 1, 8, 1
    ActorCmdWait
    SEPlay 1369
    VMSleep 8
    ActorDelete 9
    SEWait
    WorkSetConst 0x4140, 3
    WorkSetConst 0x4046, 1
    FlagSet 695
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    ActorMsg 1024, 3, 2, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 12
    VMStackCmp 5
    VMJumpIf 255, L_03F2
    WorkSub 0x8022, 1
    ActorWalkRoute 2, 0x8021, 0x8022, 1, 8, 0
    ActorCmdWait

L_03F2:
    ActorCmdExec 2, Movement_08DC
    ActorCmdWait
    ActorMsg 1024, 4, 2, 0, 0
    MsgWinCloseAll
    ActorNew 8, 11, 1, 251, 86, 0
    PlayerGetGPos 0x8021, 0x8022
    WorkSub 0x8021, 1
    ActorWalkRoute 251, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 255, Movement_08D4
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 5, 251, 2, 0

L_044D:
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 5
    VMJumpIf 255, L_05D6
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32804
    ListMenuAdd 6, 65535, 0
    ListMenuAdd 7, 65535, 1
    ListMenuAdd 8, 65535, 2
    ListMenuShow
    WorkCmpConst 0x8024, 0
    VMJumpIf 1, L_0496
    VMJump L_0509

L_0496:
    ActorMsg 1024, 9, 251, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_04F7
    ActorMsg 1024, 13, 251, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 572
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 445
    WorkSetConst 0x8025, 1
    VMJump L_0503

L_04F7:
    ActorMsg 1024, 11, 251, 2, 0

L_0503:
    VMJump L_05D0

L_0509:
    WorkCmpConst 0x8024, 1
    VMJumpIf 1, L_051C
    VMJump L_058F

L_051C:
    ActorMsg 1024, 10, 251, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_057D
    ActorMsg 1024, 14, 251, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 573
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 445
    WorkSetConst 0x8025, 1
    VMJump L_0589

L_057D:
    ActorMsg 1024, 11, 251, 2, 0

L_0589:
    VMJump L_05D0

L_058F:
    WorkCmpConst 0x8024, 2
    VMJumpIf 1, L_05A2
    VMJump L_05BC

L_05A2:
    ActorMsg 1024, 12, 251, 2, 0
    MsgWinCloseAll
    WorkSetConst 0x8025, 1
    VMJump L_05D0

L_05BC:
    ActorMsg 1024, 12, 251, 2, 0
    MsgWinCloseAll
    WorkSetConst 0x8025, 1

L_05D0:
    VMJump L_044D

L_05D6:
    ActorCmdExec 2, Movement_08D4
    ActorCmdWait
    ActorMsg 1024, 15, 2, 0, 0
    MsgWinCloseAll
    VMStackPushFlag 445
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0613
    ActorMsg 1024, 16, 251, 0, 0
    VMJump L_061F

L_0613:
    ActorMsg 1024, 17, 251, 0, 0

L_061F:
    MsgWinCloseAll
    ActorWalkRoute 251, 8, 11, 1, 8, 0
    ActorCmdWait
    ActorDelete 251
    ActorCmdExec 2, Movement_08DC
    ActorCmdExec 255, Movement_08E4
    ActorCmdWait
    ActorMsg 1024, 18, 2, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 2, 6, 13, 1, 8, 0
    ActorWalkRoute 255, 6, 14, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 2, Movement_08D4
    ActorCmdExec 255, Movement_08D4
    ActorCmdWait
    ActorMsg 1024, 19, 2, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 2, 7, 11, 1, 8, 1
    ActorWalkRoute 255, 6, 11, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 2, Movement_08E4
    ActorCmdWait
    ActorMsgVersioned 1024, 21, 20, 2, 0, 0
    MsgWinCloseAll
    ActorWalkRoute 2, 13, 11, 1, 8, 0
    ActorWalkRoute 255, 12, 11, 1, 8, 0
    ActorCmdWait
    ActorCmdExec 2, Movement_08E4
    ActorCmdExec 255, Movement_08E4
    ActorCmdWait
    ActorMsg 1024, 22, 2, 0, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x407c, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ActorMsgVersioned 1024, 2, 1, 1, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    VMStackPushFlag 447
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0782
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 22, 0, 0
    LastKeyWait
    ActorMsgClose
    VMJump L_0796

L_0782:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 23, 0, 0
    LastKeyWait
    ActorMsgClose

L_0796:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 25, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 26, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 27, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 30, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 31, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 32, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    GameGetVersion 0x8023
    VMStackPush 0x8023
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0873
    InfoMsg 34, 2
    VMJump L_0878

L_0873:
    InfoMsg 35, 2

L_0878:
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 36, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_16:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 37, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_17:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 38, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_08C4:
    Move 75, 1
    MoveEnd
    Move 35, 1
    MoveEnd

Movement_08D4:
    Move 34, 1
    MoveEnd

Movement_08DC:
    Move 33, 1
    MoveEnd

Movement_08E4:
    Move 32, 1
    MoveEnd

Movement_08EC:
    Move 32, 1
    MoveEnd

Movement_08F4:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd
    Move 35, 1
    MoveEnd
