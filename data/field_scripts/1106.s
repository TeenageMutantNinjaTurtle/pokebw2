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
    ScriptEntriesEnd

Script_2:
    VMCall L_0044
    VMHalt

Script_3:
    VMCall L_0073
    VMHalt

Script_8:
    VMCall L_0073
    VMCall L_0044
    VMHalt

L_0044:
    VMStackPushFlag 364
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0067
    ObjInitWarpGPos 0, 0, 0, 0
    VMJump L_0071

L_0067:
    ObjInitWarpGPos 6, 0, 0, 0

L_0071:
    VMReturn

L_0073:
    VMStackPush 0x40f5
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0092
    .byte 0xee
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x1e
    .byte 0x00
    .byte 0x06
    .byte 0x00
    .byte 0x00
    .byte 0x00

L_0092:
    .byte 0xee
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x09
    .byte 0x00
    .byte 0xf6
    .byte 0x40
    .byte 0x08
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x11
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x0c
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xee
    .byte 0x03
    .byte 0x01
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x1e
    .byte 0x00
    .byte 0x06
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xee
    .byte 0x03
    .byte 0x01
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x09
    .byte 0x00
    .byte 0xf7
    .byte 0x40
    .byte 0x08
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x11
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x0c
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xee
    .byte 0x03
    VMHalt
    .byte 0x00
    .byte 0x00
    .byte 0x1e
    .byte 0x00
    .byte 0x06
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xee
    .byte 0x03
    VMHalt
    .byte 0x01
    .byte 0x00
    .byte 0x09
    .byte 0x00
    .byte 0xf8
    .byte 0x40
    .byte 0x08
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0x11
    .byte 0x00
    .byte 0x01
    .byte 0x00
    .byte 0x1f
    .byte 0x00
    .byte 0xff
    .byte 0x0c
    .byte 0x00
    .byte 0x00
    .byte 0x00
    .byte 0xee
    .byte 0x03
    VMSleep 0
    VMJump L_0107
    .byte 0xee
    .byte 0x03
    VMSleep 1

L_0107:
    VMReturn

Script_9:
    ActorsPauseAll
    WordSetPlayerName 0
    WordSetLoadRivalName 1
    ActorCmdExec 0, Movement_02A0
    ActorWalkRoute 255, 11, 12, 1, 8, 0
    ActorCmdWait
    ActorMsg 1024, 0, 2, 5, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_02B0
    ActorCmdWait
    ActorMsg 1024, 1, 0, 6, 0
    MsgWinCloseAll
    VMStackPush 0x4030
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0172
    CallTrainerMultiBattle 794, 798, 799, 0
    VMJump L_019F

L_0172:
    VMStackPush 0x4030
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0195
    CallTrainerMultiBattle 795, 798, 799, 0
    VMJump L_019F

L_0195:
    CallTrainerMultiBattle 796, 798, 799, 0

L_019F:
    VMCall L_060F
    ActorMsg 1024, 2, 2, 5, 0
    MsgWinCloseAll
    ActorMsg 1024, 3, 1, 3, 0
    MsgWinCloseAll
    ActorCmdExec 2, Movement_06C0
    ActorCmdExec 1, Movement_06C8
    ActorCmdWait
    ActorCmdExec 2, Movement_02CC
    ActorCmdExec 1, Movement_02B8
    VMSleep 6
    ActorCmdExec 255, Movement_06B8
    ActorCmdExec 0, Movement_06B8
    ActorCmdWait
    ActorDelete 1
    ActorCmdExec 2, Movement_02DC
    ActorCmdWait
    SEPlay 1369
    ActorDelete 2
    SEWait
    ActorMsg 1024, 4, 0, 6, 0
    MsgWinCloseAll
    ActorCmdExec 255, Movement_06B0
    ActorCmdExec 0, Movement_06B0
    ActorCmdWait
    ActorMsg 1024, 5, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_06C0
    ActorCmdExec 255, Movement_06C8
    ActorCmdWait
    ActorMsg 1024, 6, 0, 0, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_02E4
    VMSleep 4
    ActorCmdExec 255, Movement_06B8
    ActorCmdWait
    SEPlay 1369
    ActorDelete 0
    SEWait
    FlagSet 835
    WorkSetConst 0x40ff, 1
    WorkSetConst 0x4100, 1
    WorkSetConst 0x40f2, 3
    FlagSet 830
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt
    .balign 4, 0

Movement_02A0:
    Move 12, 1
    Move 15, 1
    Move 32, 1
    MoveEnd

Movement_02B0:
    Move 36, 2
    MoveEnd

Movement_02B8:
    Move 18, 1
    Move 17, 3
    Move 19, 1
    Move 17, 2
    MoveEnd

Movement_02CC:
    Move 19, 1
    Move 17, 4
    Move 18, 2
    MoveEnd

Movement_02DC:
    Move 17, 1
    MoveEnd

Movement_02E4:
    Move 17, 2
    Move 18, 1
    Move 17, 2
    MoveEnd

Script_4:
    ActorsPauseAll
    WorkSetConst 0x40f5, 1
    SEPlay 2217
    InfoMsg 7, 2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0350
    MsgWaitAdvance
    VMJump L_0352

L_0350:
    LastKeyWait

L_0352:
    MsgWinCloseAll
    SEWait
    .byte 0xef
    .byte 0x03
    .byte 0x00
    .byte 0x00
    .byte 0xf0
    .byte 0x03
    VMNop
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_03AA
    InfoMsg 8, 2
    LastKeyWait
    MsgWinCloseAll

L_03AA:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_5:
    ActorsPauseAll
    WorkSetConst 0x40f6, 1
    SEPlay 2217
    InfoMsg 7, 2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_040C
    MsgWaitAdvance
    VMJump L_040E

L_040C:
    LastKeyWait

L_040E:
    MsgWinCloseAll
    SEWait
    .byte 0xef
    .byte 0x03
    .byte 0x01
    .byte 0x00
    .byte 0xf0
    .byte 0x03
    VMNop2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0466
    InfoMsg 8, 2
    LastKeyWait
    MsgWinCloseAll

L_0466:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_6:
    ActorsPauseAll
    WorkSetConst 0x40f7, 1
    SEPlay 2217
    InfoMsg 7, 2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_04C8
    MsgWaitAdvance
    VMJump L_04CA

L_04C8:
    LastKeyWait

L_04CA:
    MsgWinCloseAll
    SEWait
    .byte 0xef
    .byte 0x03
    VMHalt
    .byte 0xf0
    .byte 0x03
    VMHalt
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0522
    InfoMsg 8, 2
    LastKeyWait
    MsgWinCloseAll

L_0522:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_7:
    ActorsPauseAll
    WorkSetConst 0x40f8, 1
    SEPlay 2217
    InfoMsg 7, 2
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_0584
    MsgWaitAdvance
    VMJump L_0586

L_0584:
    LastKeyWait

L_0586:
    MsgWinCloseAll
    SEWait
    .byte 0xef
    .byte 0x03
    .byte 0x03
    .byte 0x00
    .byte 0xf0
    .byte 0x03
    .byte 0x03
    .byte 0x00
    VMStackPush 0x40f5
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f6
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f7
    VMStackPushConst 1
    VMStackCmp 1
    VMStackPush 0x40f8
    VMStackPushConst 1
    VMStackCmp 1
    VMStackCmp 7
    VMStackCmp 7
    VMStackCmp 7
    VMJumpIf 255, L_05DE
    InfoMsg 8, 2
    LastKeyWait
    MsgWinCloseAll

L_05DE:
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_1:
    ActorsPauseAll
    ActorCmdExec 255, Movement_0650
    ActorCmdWait
    SEPlay 2221
    ActorCmdExec 255, Movement_065C
    ActorCmdWait
    SEWait
    InfoMsg 9, 2
    LastKeyWait
    MsgWinCloseAll
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_060F:
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_0649
    PokePartyGetCount 0x8008, 2
    VMStackPush 0x8008
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0641
    PokePartyRecoverAll

L_0641:
    CallTrainerBattleEnd
    VMJump L_064B

L_0649:
    CallTrainerLose

L_064B:
    VMReturn
    .balign 4, 0

Movement_0650:
    Move 0, 1
    Move 75, 1
    MoveEnd

Movement_065C:
    Move 71, 1
    Move 36, 2
    Move 17, 2
    Move 72, 1
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

Movement_06B0:
    Move 32, 1
    MoveEnd

Movement_06B8:
    Move 33, 1
    MoveEnd

Movement_06C0:
    Move 34, 1
    MoveEnd

Movement_06C8:
    Move 35, 1
    MoveEnd
    Move 75, 1
    MoveEnd
