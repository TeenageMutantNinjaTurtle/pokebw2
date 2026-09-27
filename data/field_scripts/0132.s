#include "asm/field_script.inc"

// Script plugin 1, from the zones that use this file

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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0

Script_5:
    ActorsPauseAll
    CallPlaceNameDisp
    ActorCmdExec 255, Movement_006C
    ActorCmdWait
    PlayerSetRailPos 2, 0, 1
    WorkSetConst 0x417c, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Movement_006C:
    Move 14, 10
    MoveEnd

Script_4:
    ActorsPauseAll
    PlayerSetRailPos 6, 0, 0
    ActorCmdExec 255, Movement_00A0
    ActorCmdWait
    RTReserveScript 7
    LensFlareRequest
    MapChangeWarp 62, 422, 459, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_00A0:
    Move 15, 8
    MoveEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 0, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 1, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 2400
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_010B
    ParentActorMsg 1024, 3, 0, 0
    VMJump L_0115

L_010B:
    ParentActorMsg 1024, 2, 0, 0

L_0115:
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    WorkSetConst 0x8022, 0
    SEPlay 1351
    ActorSetEyeToEye
    VMCall L_01A6
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0152
    WorkSetConst 0x8022, 10
    VMJump L_0190

L_0152:
    DebugPrint 0x8020
    DebugPrint 0x8020
    VMStackPush 0x8020
    VMStackPushConst 65535
    VMStackCmp 1
    VMJumpIf 255, L_0179
    WorkSetConst 0x8022, 12
    VMJump L_0188

L_0179:
    WordSetTrendName 0, 0x8020
    WorkSetConst 0x8022, 9
    DebugPrint 0x8020

L_0188:
    DebugPrint 0x8010
    DebugPrint 0x8022

L_0190:
    ActorMsg 1024, 0x8022, 0x8011, 4, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_01A6:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    ActorMsg 1024, 4, 0x8011, 4, 0

L_01C4:
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0372
    ListMenu_AnchorTopRight 31, 1, 0, 1, 32804
    ListMenuAdd 13, 65535, 1
    ListMenuAdd 14, 65535, 2
    ListMenuAdd 15, 65535, 3
    ListMenuAdd 16, 65535, 4
    ListMenuAdd 17, 65535, 0
    ListMenuShow
    VMStackPush 0x8024
    VMStackPushConst 65534
    VMStackCmp 5
    VMJumpIf 255, L_0360
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_034E
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0
    WorkCmpConst 0x8024, 1
    VMJumpIf 1, L_024F
    VMJump L_0261

L_024F:
    WorkSetConst 0x8026, 5
    WorkSetConst 0x8025, 0
    VMJump L_02D0

L_0261:
    WorkCmpConst 0x8024, 2
    VMJumpIf 1, L_0274
    VMJump L_0286

L_0274:
    WorkSetConst 0x8026, 7
    WorkSetConst 0x8025, 1
    VMJump L_02D0

L_0286:
    WorkCmpConst 0x8024, 3
    VMJumpIf 1, L_0299
    VMJump L_02AB

L_0299:
    WorkSetConst 0x8026, 6
    WorkSetConst 0x8025, 2
    VMJump L_02D0

L_02AB:
    WorkCmpConst 0x8024, 4
    VMJumpIf 1, L_02BE
    VMJump L_02D0

L_02BE:
    WorkSetConst 0x8026, 8
    WorkSetConst 0x8025, 3
    VMJump L_02D0

L_02D0:
    ActorMsg 1024, 0x8026, 0x8011, 4, 0
    ActorMsgClose
    FadeOutBlackQ
    FadeWait
    FieldClose
    CallPhraseSelect 0x8025, 0x8020, 0x8021, 0x8010
    FieldOpen
    FadeInBlackQ
    FadeWait
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_033C
    ActorMsg 1024, 11, 0x8011, 4, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 5
    VMJumpIf 255, L_0336
    WorkSetConst 0x8010, 1
    WorkSetConst 0x8023, 1

L_0336:
    VMJump L_0348

L_033C:
    WorkSetConst 0x8010, 0
    WorkSetConst 0x8023, 1

L_0348:
    VMJump L_035A

L_034E:
    WorkSetConst 0x8010, 0
    WorkSetConst 0x8023, 1

L_035A:
    VMJump L_036C

L_0360:
    WorkSetConst 0x8010, 0
    WorkSetConst 0x8023, 1

L_036C:
    VMJump L_01C4

L_0372:
    VMReturn

Script_7:
    ActorsPauseAll
    SEPlay 1351
    Plugin1_Cmd1003 43, 0, 0, 32784
    DebugPrint 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_03AB
    SystemMsg 26, 2
    LastKeyWait
    MsgWinCloseAll
    VMJump L_03B5

L_03AB:
    Plugin1_Cmd1003 111, 0, 0, 32784

L_03B5:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_8:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 18, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 19, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 20, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_11:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 21, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_12:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 22, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_13:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 23, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_14:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 24, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_15:
    ActorsPauseAll
    SEPlay 1351
    SystemMsg 25, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
