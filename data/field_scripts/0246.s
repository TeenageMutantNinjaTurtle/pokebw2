#include "asm/field_script.inc"

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntriesEnd

Script_4:
    FlagSet 494
    VMHalt

Script_5:
    VMStackPush 0x40d9
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_003B
    ActorSetGPos 1, 14, 0, 10, 2

L_003B:
    VMHalt

Script_3:
    ActorsPauseAll
    ActorCmdExec 255, Movement_0190
    VMSleep 32
    ActorCmdExec 0, Movement_01A4
    ActorCmdWait
    ActorMsg 1024, 0, 0, 0, 0
    MsgWinCloseAll
    ActorMsgVersioned 1024, 2, 1, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_025C
    ActorCmdWait
    ActorMsgVersioned 1024, 4, 3, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0204
    ActorCmdWait
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_026C
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    SEPlay 2266
    EvCameraShake 0, 1, 3, 6, 0, 0, 0, 0
    ScreamMsg 7, 2
    MsgWinCloseAll
    FlagSet 2553
    BGMChangeMap
    SEWait
    ActorCmdExec 0, Movement_027C
    ActorCmdWait
    ActorCmdExec 0, Movement_025C
    ActorCmdWait
    ActorMsg 1024, 8, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_01BC
    ActorCmdExec 255, Movement_01B0
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    ActorWalkRoute 255, 9, 14, 0, 8, 0
    ActorCmdWait
    WorkSetConst 0x40d9, 2
    FlagSet 800
    FlagReset 794
    FlagReset 1034
    WorkSetConst 0x40d7, 1
    RTReserveScript 21
    WorkSetConst 0x8020, 0
    GameGetVersion 0x8020
    VMStackPush 0x8020
    VMStackPushConst 23
    VMStackCmp 1
    VMJumpIf 255, L_0179
    MapChangeWarp 120, 418, 162, 1
    VMJump L_0183

L_0179:
    MapChangeWarp 120, 418, 164, 1

L_0183:
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0190:
    Move 12, 3
    Move 15, 1
    Move 12, 2
    Move 34, 1
    MoveEnd

Movement_01A4:
    Move 14, 1
    Move 35, 1
    MoveEnd

Movement_01B0:
    Move 14, 1
    Move 13, 2
    MoveEnd

Movement_01BC:
    Move 17, 2
    Move 19, 1
    Move 17, 3
    MoveEnd

Script_1:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    RTCallGlobal 2280
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    PVPlay 610, 0
    ParentActorMsg 1024, 9, 0, 0
    PVWait
    LastKeyWait
    ActorMsgClose
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_0204:
    Move 10, 1
    Move 11, 1
    Move 30, 1
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
    Move 32, 1
    MoveEnd

Movement_025C:
    Move 33, 1
    MoveEnd
    Move 34, 1
    MoveEnd

Movement_026C:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd

Movement_027C:
    Move 159, 1
    MoveEnd
