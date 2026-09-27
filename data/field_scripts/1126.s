#include "asm/field_script.inc"

// Script plugin 9, from the only plugin whose commands it decodes with

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntry Script_3
    ScriptEntry Script_4
    ScriptEntry Script_5
    ScriptEntry Script_6
    ScriptEntriesEnd

L_001A:
    VMStackPushFlag 364
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_003D
    ObjInitWarpGPos 0, 0, 0, 0
    VMJump L_0047

L_003D:
    ObjInitWarpGPos 2, 0, 0, 0

L_0047:
    VMReturn

Script_3:
    VMCall L_001A
    VMHalt

Script_4:
    VMCall L_0067
    VMHalt

Script_5:
    VMCall L_0067
    VMCall L_001A
    VMHalt

L_0067:
    VMStackPush 0x40fb
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0092
    Plugin9_Cmd1006 0
    VMNop2
    Plugin9_Cmd1006 1
    VMNop2
    Plugin9_Cmd1006 2
    VMNop2
    Plugin9_Cmd1006 3
    VMNop2

L_0092:
    VMReturn

Script_6:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 0, Movement_024C
    ActorWalkRoute 255, 11, 12, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 0, 2, 5, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_025C
    ActorCmdWait
    ActorMsg 1024, 1, 0, 6, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_00FD
    CallTrainerMultiBattle 794, 798, 799, 0
    VMJump L_012A

L_00FD:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0120
    CallTrainerMultiBattle 795, 798, 799, 0
    VMJump L_012A

L_0120:
    CallTrainerMultiBattle 796, 798, 799, 0

L_012A:
    VMCall L_03EC
    ActorCmdExec 2, Movement_047C
    ActorCmdExec 1, Movement_0484
    ActorCmdWait
    ActorMsg 1024, 2, 2, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 1, 3, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_0278
    ActorCmdExec 1, Movement_0264
    VMSleep 6
    ActorCmdExec 255, Movement_0474
    ActorCmdExec 0, Movement_0474
    ActorCmdWait
    ActorDelete 1
    ActorCmdExec 2, Movement_0288
    ActorCmdWait
    SEPlay 1369
    ActorDelete 2
    SEWait
    ActorMsg 1024, 4, 0, 6, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_046C
    ActorCmdExec 0, Movement_046C
    ActorCmdWait
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0484
    ActorCmdWait
    VMSleep 16
    ActorCmdExec 0, Movement_047C
    ActorCmdExec 255, Movement_0484
    ActorCmdWait
    ActorMsg 1024, 7, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_0290
    VMSleep 4
    ActorCmdExec 255, Movement_0474
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    FlagSet 836
    WorkSetConst 0x40ff, 1
    WorkSetConst 0x4100, 1
    WorkSetConst 0x40f1, 3
    FlagSet 830
    FlagSet 832
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_024C:
    Move 12, 1
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_025C:
    Move 36, 2
    MoveEnd

Movement_0264:
    Move 18, 1
    Move 17, 3
    Move 19, 1
    Move 17, 2
    MoveEnd

Movement_0278:
    Move 19, 1
    Move 17, 4
    Move 18, 2
    MoveEnd

Movement_0288:
    Move 17, 1
    MoveEnd

Movement_0290:
    Move 17, 2
    Move 18, 1
    Move 17, 2
    MoveEnd

Script_2:
    ActorsPauseAll
    SEPlay 1351
    VMStackPushFlag 356
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_02C9
    SystemMsg 8, 2
    LastKeyWait
    MsgWinCloseAll
    VMJump L_0394

L_02C9:
    VMStackPush 0x40fb
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_038A
    Plugin9_Cmd1005 0x400a
    DebugPrint 0x400a
    SEPlay 2214
    SEWait
    SystemMsg 9, 2
    YesNoWin 0x8010
    VMStackPush 0x8010
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0382
    MsgWinCloseAll
    WorkSetConst 0x8020, 0
    Plugin9_Cmd1004 0x8020
    VMStackPush 0x8020
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_036C
    SEPlay 2215
    SystemMsg 11, 2
    SEWait
    MsgWaitAdvance
    MsgWinCloseAll
    Plugin9_Cmd1008 0
    VMSleep 8
    Plugin9_Cmd1008 1
    VMSleep 8
    Plugin9_Cmd1008 2
    VMSleep 8
    Plugin9_Cmd1008 3
    SystemMsg 12, 2
    LastKeyWait
    MsgWinCloseAll
    WorkSetConst 0x40fb, 1
    FlagSet 357
    VMJump L_037C

L_036C:
    SEPlay 2216
    SEWait
    SystemMsg 10, 2
    LastKeyWait
    MsgWinCloseAll

L_037C:
    VMJump L_0384

L_0382:
    MsgWinCloseAll

L_0384:
    VMJump L_0394

L_038A:
    SystemMsg 12, 2
    LastKeyWait
    MsgWinCloseAll

L_0394:
    WorkSetConst 0x8020, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    ActorCmdExec 255, Movement_03CC
    ActorCmdWait
    SEPlay 2221
    ActorCmdExec 255, Movement_03D8
    ActorCmdWait
    SEWait
    InfoMsg 13, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_03CC:
    Move 0, 1
    Move 75, 1
    MoveEnd

Movement_03D8:
    Move 71, 1
    Move 36, 2
    Move 17, 2
    Move 72, 1
    MoveEnd

L_03EC:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0426
    PokePartyGetCount 0x8008, 2
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_041E
    PokePartyRecoverAll

L_041E:
    CallTrainerBattleEnd
    VMJump L_0428

L_0426:
    CallTrainerLose

L_0428:
    VMReturn
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

Movement_046C:
    Move 32, 1
    MoveEnd

Movement_0474:
    Move 33, 1
    MoveEnd

Movement_047C:
    Move 34, 1
    MoveEnd

Movement_0484:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
