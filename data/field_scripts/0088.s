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
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0

Script_1:
    ActorsPauseAll
    InfoMsg 22, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    InfoMsg 23, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 4, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 5, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 361
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02E9
    ActorMsg 1024, 6, 2, 2, 0
    WorkSetConst 0x8024, 0

L_00C7:
    VMStackPush 0x8024
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02E3
    ListMenu_AnchorTopRight 31, 5, 0, 1, 32803
    ListMenuAdd 11, 65535, 0
    ListMenuAdd 12, 65535, 1
    ListMenuAdd 13, 65535, 2
    ListMenuAdd 14, 65535, 3
    ListMenuShow
    VMStackPush 0x8023
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_019B
    ActorMsg 1024, 15, 2, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0189
    ActorMsg 1024, 7, 2, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 239
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 361
    ActorMsg 1024, 10, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8024, 1
    VMJump L_0195

L_0189:
    ActorMsg 1024, 18, 2, 2, 0

L_0195:
    VMJump L_02DD

L_019B:
    VMStackPush 0x8023
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0231
    ActorMsg 1024, 16, 2, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_021F
    ActorMsg 1024, 8, 2, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 243
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 361
    ActorMsg 1024, 10, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8024, 1
    VMJump L_022B

L_021F:
    ActorMsg 1024, 18, 2, 2, 0

L_022B:
    VMJump L_02DD

L_0231:
    VMStackPush 0x8023
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_02C7
    ActorMsg 1024, 17, 2, 2, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02B5
    ActorMsg 1024, 9, 2, 2, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 249
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    FlagSet 361
    ActorMsg 1024, 10, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8024, 1
    VMJump L_02C1

L_02B5:
    ActorMsg 1024, 18, 2, 2, 0

L_02C1:
    VMJump L_02DD

L_02C7:
    ActorMsg 1024, 19, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x8024, 1

L_02DD:
    VMJump L_00C7

L_02E3:
    VMJump L_02F9

L_02E9:
    ActorMsg 1024, 10, 2, 2, 0
    LastKeyWait
    MsgWinCloseAll

L_02F9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 3, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    ActorCmdExec 3, Movement_0484
    ActorCmdWait
    PlayerGetGPos 0x8021, 0x8022
    WorkSub 0x8022, 1
    ActorWalkRoute 3, 0x8021, 0x8022, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 3, Movement_047C
    ActorCmdWait
    ActorMsg 1024, 0, 3, 0, 0
    ActorMsg 1024, 1, 3, 0, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 216
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorMsg 1024, 2, 3, 0, 0
    ActorMsg 1024, 3, 3, 0, 0
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9777, 0, 0xecba0, 0x78000, 0, 0x59000, 30
    ActorWalkRoute 3, 7, 2, 1, 8, 1
    EvCameraWait
    ActorCmdWait
    VMStackPush 0x8021
    VMStackPushConst 7
    VMStackCmp 5
    VMJumpIf 255, L_03EC
    ActorCmdExec 3, Movement_0474
    ActorCmdWait

L_03EC:
    VMSleep 12
    SEPlay 1768
    SEWait
    WorkSetConst 0x8025, 0
    BMCreateHandleByGPos 0x8025, 1, 7, 1
    BMHndAudioVisualAnmPlay 0x8025, 0
    BMHndAnmWait 0x8025
    ActorCmdExec 3, Movement_0448
    ActorCmdWait
    BMHndAudioVisualAnmPlay 0x8025, 1
    BMHndAnmWait 0x8025
    BMReleaseHandle 0x8025
    ActorDelete 3
    EvCameraReturn 30
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    FlagSet 852
    WorkSetConst 0x40fc, 1
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0448:
    Move 12, 2
    Move 33, 1
    MoveEnd
    Move 13, 1
    MoveEnd
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd
    Move 14, 1
    MoveEnd

Movement_0474:
    Move 32, 1
    MoveEnd

Movement_047C:
    Move 33, 1
    MoveEnd

Movement_0484:
    Move 75, 1
    MoveEnd

Script_8:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPush 0x40e2
    VMStackPushConst 6
    VMStackCmp 5
    VMStackPushFlag 314
    VMStackPushConst 0
    VMStackCmp 1
    VMStackCmp 7
    VMJumpIf 255, L_04DB
    SEPlay 1690
    ParentActorMsg 1024, 20, 0, 0
    FlagSet 314
    WorkAdd 0x40e2, 1
    SEWait
    LastKeyWait
    MsgWinCloseAll
    VMJump L_04E9

L_04DB:
    ParentActorMsg 1024, 21, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_04E9:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
