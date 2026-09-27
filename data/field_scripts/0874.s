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
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_1:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x358000, 0x1000f, 0x2ba8000, 16
    EvCameraWait
    ActorMsgGendered 1024, 0, 1, 5, 0, 0
    MsgWinCloseAll
    VMCall L_0192
    ActorCmdExec 5, Movement_07A8
    ActorCmdWait
    ActorMsg 1024, 2, 5, 0, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_0798
    ActorCmdWait
    ActorMsg 1024, 3, 5, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    EvCameraMoveTo 9688, 0, 0xed000, 0x3d8000, 0x1000f, 0x2b88000, 72
    ActorCmdExec 5, Movement_0250
    ActorCmdExec 255, Movement_0258
    ActorCmdWait
    EvCameraWait
    CallCaptureDemo
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x3d8000, 0x1000f, 0x2b88000, 1
    EvCameraWait
    CallWildBattleEnd
    EvCameraMoveToDefault 32
    ActorWalkRoute 5, 58, 696, 1, 8, 1
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorMsg 1024, 4, 5, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 5, 5, 0, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_07A8
    ActorCmdWait
    ActorMsg 1024, 6, 5, 0, 0
    MsgWinCloseAll
    ActorCmdExec 5, Movement_07A0
    ActorCmdWait
    ActorMsg 1024, 7, 5, 0, 0
    MsgWinCloseAll
    VMCall L_0205
    WorkSetConst 0x40a3, 1
    FlagSet 987
    FlagReset 739
    FlagSet 744
    FlagSet 743
    FlagReset 740
    FlagReset 803
    Cmd_0262 4, 0
    WorkSetConst 0x40a1, 8
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_0192:
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 53
    VMStackCmp 5
    VMJumpIf 255, L_01C1
    ActorWalkRoute 255, 53, 698, 1, 8, 0
    ActorCmdWait
    VMJump L_01CB

L_01C1:
    ActorCmdExec 255, Movement_0758
    ActorCmdWait

L_01CB:
    ActorCmdWait
    VMReturn
    ActorCmdExec 255, Movement_0798
    ActorCmdWait
    ActorNew 53, 703, 0, 251, 249, 0
    PlayerGetGPos 0x8021, 0x8022
    WorkAdd 0x8022, 1
    ActorWalkRoute 251, 0x8021, 0x8022, 1, 8, 0
    ActorCmdWait
    VMReturn

L_0205:
    ActorCmdExec 5, Movement_0264
    VMSleep 16
    ActorCmdExec 255, Movement_0798
    ActorCmdWait
    SEPlay 1369
    ActorDelete 5
    SEWait
    VMReturn
    ActorWalkRoute 251, 53, 702, 1, 8, 1
    ActorCmdWait
    ActorCmdExec 251, Movement_0750
    ActorCmdWait
    SEPlay 1369
    ActorDelete 251
    SEWait
    VMReturn
    .balign 4, 0

Movement_0250:
    Move 15, 8
    MoveEnd

Movement_0258:
    Move 12, 2
    Move 15, 3
    MoveEnd

Movement_0264:
    Move 13, 1
    Move 14, 5
    Move 13, 6
    MoveEnd
    VMStackMul
    VMNop2
    VMStackSub
    VMStackPushConst 254
    VMNop

Script_2:
    ActorsPauseAll
    InfoMsg 8, 1
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x5d8000, 0x6005f, 0x2b38000, 20
    ActorCmdExec 255, Movement_0790
    ActorCmdWait
    EvCameraWait
    BGMPlay 1101
    ActorMsg 1024, 9, 1, 0, 0
    MsgWinCloseAll
    EvCameraMoveToDefault 30
    ActorJumpToGPos 1, 93, 1, 693
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMSleep 14
    PlayerGetGPos 0x8021, 0x8022
    WorkAdd 0x8021, 2
    VMStackPush 0x8022
    VMStackPushConst 693
    VMStackCmp 5
    VMJumpIf 255, L_0308
    ActorWalkRoute 1, 0x8021, 0x8022, 1, 8, 1

L_0308:
    ActorCmdExec 255, Movement_0788
    ActorCmdWait
    ActorCmdExec 1, Movement_07A0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 10, 1, 0, 0
    MsgWinCloseAll
    PlayerGetGPos 0x8021, 0x8022
    WorkCmpConst 0x8022, 693
    VMJumpIf 1, L_0346
    VMJump L_0354

L_0346:
    ActorCmdExec 1, Movement_03C0
    VMJump L_037D

L_0354:
    WorkCmpConst 0x8022, 697
    VMJumpIf 1, L_0367
    VMJump L_0375

L_0367:
    ActorCmdExec 1, Movement_03F4
    VMJump L_037D

L_0375:
    ActorCmdExec 1, Movement_0428

L_037D:
    ActorCmdWait
    WorkSetConst 0x8023, 0
    PokePartyGetMemberByType 0x8023, 2
    WordSetPartyPokeSpecies 1, 0x8023
    ActorMsg 1024, 11, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0464
    ActorCmdWait
    BGMChangeMap
    ActorDelete 1
    WorkSetConst 0x40a3, 2
    FlagSet 738
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_03C0:
    Move 14, 1
    Move 63, 1
    Move 13, 1
    Move 14, 1
    Move 32, 1
    Move 14, 1
    Move 12, 1
    Move 35, 1
    Move 13, 1
    Move 15, 3
    Move 12, 1
    Move 34, 1
    MoveEnd

Movement_03F4:
    Move 14, 1
    Move 63, 1
    Move 12, 1
    Move 14, 1
    Move 33, 1
    Move 14, 1
    Move 13, 1
    Move 35, 1
    Move 12, 1
    Move 15, 3
    Move 13, 1
    Move 34, 1
    MoveEnd

Movement_0428:
    Move 14, 1
    Move 63, 1
    Move 12, 1
    Move 14, 1
    Move 33, 1
    Move 14, 1
    Move 13, 1
    Move 35, 1
    Move 13, 1
    Move 15, 1
    Move 32, 1
    Move 15, 2
    Move 12, 1
    Move 34, 1
    MoveEnd

Movement_0464:
    Move 15, 7
    MoveEnd

Script_7:
    ActorsPauseAll
    FlagReset 738
    ActorAdd 1
    WordSetPlayerName 0
    InfoMsg 25, 2
    MsgWinCloseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x5d8000, 0x6005f, 0x2b38000, 40
    ActorCmdExec 255, Movement_0790
    ActorCmdWait
    EvCameraWait
    BGMPlay 1101
    VMSleep 40
    EvCameraMoveToDefault 64
    ActorJumpToGPos 1, 93, 1, 693
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    VMSleep 14
    PlayerGetGPos 0x8021, 0x8022
    WorkAdd 0x8021, 2
    ActorWalkRoute 1, 0x8021, 0x8022, 1, 8, 1
    ActorCmdExec 255, Movement_07A8
    ActorCmdWait
    ActorMsg 1024, 26, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0768
    ActorCmdWait
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 155
    WorkSet 0x8001, 5
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    ActorCmdExec 1, Movement_05B0
    ActorCmdWait
    WordSetPlayerName 0
    ActorMsg 1024, 27, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0798
    ActorCmdWait
    ActorMsg 1024, 28, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_05A8
    ActorCmdWait
    ActorMsg 1024, 29, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_07A0
    ActorCmdWait
    ActorMsg 1024, 30, 1, 0, 0
    MsgWinCloseAll
    ActorCmdExec 1, Movement_0464
    ActorCmdWait
    BGMChangeMap
    ActorDelete 1
    WorkSetConst 0x40a3, 4
    FlagSet 738
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_05A8:
    Move 100, 1
    MoveEnd

Movement_05B0:
    Move 15, 1
    Move 34, 1
    MoveEnd

Script_8:
    ActorsPauseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    Move 13, 1
    Move 32, 1
    MoveEnd

Script_3:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    VMStackPushFlag 16
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_069F
    ActorMsg 1024, 12, 0, 4, 0
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0689
    FlagSet 16
    ActorMsg 1024, 14, 0, 4, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_07A0
    ActorCmdWait
    ActorMsg 1024, 15, 0, 4, 0
    VMSleep 4
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0740
    VMSleep 4
    PlayerGetDir 0x8020
    VMStackPush 0x8020
    VMStackPushConst 2
    VMStackCmp 5
    VMJumpIf 255, L_0667
    ActorCmdExec 255, Movement_07A0

L_0667:
    ActorCmdWait
    ActorCmdExec 0, Movement_07A8
    ActorCmdWait
    ActorMsg 1024, 16, 0, 3, 0
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0699

L_0689:
    ActorMsg 1024, 13, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_0699:
    VMJump L_06AF

L_069F:
    ActorMsg 1024, 16, 0, 0, 0
    LastKeyWait
    MsgWinCloseAll

L_06AF:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_9:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 24, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_10:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 34, 0, 0
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 31, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 32, 3
    MsgPlaceSignClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    FunfestMissionBroadcast 17, 0
    SEPlay 1351
    MsgPlaceSign 33, 0
    MsgPlaceSignClose
    FlagSet 2677
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0740:
    Move 58, 1
    Move 10, 1
    Move 2, 1
    MoveEnd

Movement_0750:
    Move 13, 1
    MoveEnd

Movement_0758:
    Move 12, 1
    MoveEnd
    Move 15, 1
    MoveEnd

Movement_0768:
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

Movement_0788:
    Move 3, 1
    MoveEnd

Movement_0790:
    Move 32, 1
    MoveEnd

Movement_0798:
    Move 33, 1
    MoveEnd

Movement_07A0:
    Move 34, 1
    MoveEnd

Movement_07A8:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
