#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0

Script_2:
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    PokePartyFindEx 645, 0, 0x8023, 0x8024
    Cmd_02F2 7, 0x8025
    VMStackPush 0x8024
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x4150
    VMStackPushConst 2
    VMStackCmp 5
    VMStackPush 0x8025
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_008D
    FlagReset 1028
    WorkSetConst 0x4150, 1
    VMJump L_00AA

L_008D:
    FlagSet 1028
    VMStackPush 0x4150
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_00AA
    WorkSetConst 0x4150, 0

L_00AA:
    VMStackPush 0x4155
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00C1
    FlagReset 1038

L_00C1:
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8023, 0
    VMHalt

Script_3:
    ActorsPauseAll
    PlayerGetGPos 0x8021, 0x8022
    WorkSub 0x8022, 1
    ActorCmdExec 11, Movement_04C8
    ActorCmdWait
    VMSleep 6
    ActorCmdExec 11, Movement_04B0
    ActorCmdWait
    InfoMsg 0, 1
    MsgWinCloseAll
    ActorWalkRoute 11, 0x8021, 0x8022, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 1, 11, 5, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_04C0
    ActorCmdWait
    ActorMsg 1024, 2, 11, 5, 0
    MsgWinCloseAll
    ActorCmdExec 11, Movement_021C
    ActorCmdWait
    ActorMsg 1024, 3, 11, 5, 0
    MsgWinCloseAll
    ActorWalkRoute 11, 22, 13, 1, 8, 0
    ActorCmdWait
    VMSleep 8
    ActorCmdExec 11, Movement_04A8
    ActorCmdWait
    VMSleep 8
    ActorWalkRoute 11, 0x8021, 0x8022, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 4, 11, 5, 0
    MsgWinCloseAll
    VMStackPush 0x8000
    VMStackPush 0x8001
    WorkSet 0x8000, 638
    WorkSet 0x8001, 1
    RTCallGlobal 2805
    VMStackPop 0x8001
    VMStackPop 0x8000
    Cmd_02F1 6
    ActorMsg 1024, 5, 11, 5, 0
    MsgWinCloseAll
    VMStackPush 0x8021
    VMStackPushConst 22
    VMStackCmp 1
    VMJumpIf 255, L_01E9
    ActorWalkRoute 11, 23, 24, 1, 8, 0
    VMJump L_01F7

L_01E9:
    ActorWalkRoute 11, 22, 24, 1, 8, 0

L_01F7:
    VMSleep 16
    ActorCmdExec 255, Movement_04B0
    ActorCmdWait
    ActorDelete 11
    FlagSet 1028
    WorkSetConst 0x4150, 2
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_021C:
    Move 33, 1
    Move 75, 1
    MoveEnd

Script_5:
    ActorsPauseAll
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 9688, 0, 0xed000, 0x338000, 32795, 0x318000, 40
    PlayerGetGPos 0x8021, 0x8022
    VMStackPush 0x8021
    VMStackPushConst 50
    VMStackCmp 1
    VMJumpIf 255, L_026D
    ActorCmdExec 255, Movement_0364
    VMJump L_0275

L_026D:
    ActorCmdExec 255, Movement_0374

L_0275:
    ActorCmdWait
    EvCameraWait
    ActorMsg 1024, 9, 13, 5, 0
    MsgWinCloseAll
    ActorCmdExec 12, Movement_037C
    VMSleep 8
    ActorCmdExec 13, Movement_04B0
    ActorCmdWait
    ActorMsgVersioned 1024, 10, 11, 12, 6, 0
    MsgWaitAdvance
    ActorMsgClose
    ActorCmdExec 13, Movement_0398
    ActorCmdWait
    ActorMsg 1024, 12, 13, 5, 0
    MsgWaitAdvance
    MsgWinCloseAll
    EvCameraMoveToDefault 34
    ActorCmdExec 13, Movement_03B0
    VMSleep 2
    ActorCmdExec 12, Movement_03A0
    VMSleep 8
    ActorCmdExec 255, Movement_04B0
    ActorCmdWait
    ActorDelete 12
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    ActorCmdExec 13, Movement_03C0
    ActorCmdWait
    SEPlay 1369
    ActorDelete 13
    SEWait
    ActorCmdExec 14, Movement_03C8
    VMSleep 8
    ActorCmdExec 255, Movement_04A8
    ActorCmdWait
    ActorMsg 1024, 16, 14, 3, 0
    MsgWaitAdvance
    MsgWinCloseAll
    ActorCmdExec 14, Movement_03D4
    VMSleep 16
    ActorCmdExec 255, Movement_04B0
    ActorCmdWait
    SEPlay 1369
    ActorDelete 14
    SEWait
    WorkSetConst 0x4155, 1
    FlagSet 1038
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0364:
    Move 12, 1
    Move 15, 1
    Move 32, 0
    MoveEnd

Movement_0374:
    Move 12, 1
    MoveEnd

Movement_037C:
    Move 51, 1
    Move 19, 1
    Move 17, 3
    Move 19, 1
    Move 32, 0
    Move 48, 1
    MoveEnd

Movement_0398:
    Move 17, 1
    MoveEnd

Movement_03A0:
    Move 17, 2
    Move 18, 1
    Move 17, 1
    MoveEnd

Movement_03B0:
    Move 17, 4
    Move 18, 1
    Move 37, 0
    MoveEnd

Movement_03C0:
    Move 17, 1
    MoveEnd

Movement_03C8:
    Move 15, 1
    Move 13, 1
    MoveEnd

Movement_03D4:
    Move 14, 1
    Move 13, 3
    MoveEnd

Script_1:
    ActorsPauseAll
    VMStackPushFlag 2450
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0436
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 6, 0, 0
    MsgWinCloseAll
    Cmd_0275 0, 39, 0
    SEPlay 1908
    SystemMsg 7, 0
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    MsgWinCloseAll
    FlagSet 2450
    VMJump L_044A

L_0436:
    SEPlay 1351
    ActorSetEyeToEye
    ParentActorMsg 1024, 8, 0, 0
    LastKeyWait
    ActorMsgClose

L_044A:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_4:
    ActorsPauseAll
    SEPlay 1351
    InfoMsg 20, 2
    LastKeyWait
    InfoMsgClose_0039
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0
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

Movement_04A8:
    Move 32, 1
    MoveEnd

Movement_04B0:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_04C0:
    Move 35, 1
    MoveEnd

Movement_04C8:
    Move 75, 1
    MoveEnd
    Move 159, 1
    MoveEnd
    Move 161, 1
    MoveEnd
