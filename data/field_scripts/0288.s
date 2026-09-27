#include "asm/field_script.inc"

// Script plugin 3, from the zones that use this file

    ScriptEntry Script_1
    ScriptEntry Script_2
    ScriptEntriesEnd
    WorkSetConst 0x8020, 0
    WorkSetConst 0x8021, 0
    WorkSetConst 0x8022, 0
    WorkSetConst 0x8023, 0
    WorkSetConst 0x8024, 0
    WorkSetConst 0x8025, 0
    WorkSetConst 0x8026, 0

Script_1:
    ActorsPauseAll
    VMStackPush 0x4001
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_0093
    VMSleep 30
    ActorMsg 1024, 0, 0, 1, 0
    MsgWinCloseAll
    Plugin3_Cmd1017
    Plugin3_Cmd1019 0
    Plugin3_Cmd1019 255
    SEPlay 2229
    VMSleep 60
    ActorCmdExec 0, Movement_044C
    ActorCmdWait
    ActorMsg 1024, 1, 0, 1, 0
    MsgWaitAdvance
    MsgWinCloseAll
    WorkSetConst 0x4001, 1
    VMJump L_00A1

L_0093:
    ActorMsg 1024, 7, 0, 1, 0
    MsgWinCloseAll

L_00A1:
    ActorCmdExec 255, Movement_04C4
    ActorCmdWait
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

Script_2:
    ActorsPauseAll
    SEPlay 1351
    ActorSetEyeToEye
    FunfestBGMReturn
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 10317, 0, 0x72000, 0x108000, 0xd00cf, 0x31b000, 60
    PlayerGetDir 0x8010
    WorkCmpConst 0x8010, 2
    VMJumpIf 1, L_00EE
    VMJump L_00FC

L_00EE:
    ActorCmdExec 255, Movement_0414
    VMJump L_013E

L_00FC:
    WorkCmpConst 0x8010, 3
    VMJumpIf 1, L_010F
    VMJump L_011D

L_010F:
    ActorCmdExec 255, Movement_0400
    VMJump L_013E

L_011D:
    WorkCmpConst 0x8010, 0
    VMJumpIf 1, L_0130
    VMJump L_013E

L_0130:
    ActorCmdExec 255, Movement_0428
    VMJump L_013E

L_013E:
    VMSleep 24
    ActorWalkRoute 0, 18, 40, 0, 8, 0
    EvCameraWait
    ActorCmdWait
    EvCameraEnd
    ActorCmdExec 0, Movement_04AC
    ActorCmdWait
    VMSleep 30
    Plugin3_Cmd1021
    VMStackPushFlag 2400
    VMStackPushConst 0
    VMStackCmp 1
    VMJumpIf 255, L_01FF
    ActorMsg 1024, 2, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_04D4
    ActorCmdExec 255, Movement_04CC
    ActorCmdWait
    WorkSetConst 0x8027, 0
    GameGetDifficulty 0x8027
    VMStackPush 0x8027
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_01C4
    CallTrainerBattle 776, 0, 0
    VMJump L_01CC

L_01C4:
    CallTrainerBattle 341, 0, 0

L_01CC:
    WorkSetConst 0x8027, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_01F7
    VMCall L_036B
    CallTrainerBattleEnd
    VMJump L_01F9

L_01F7:
    CallTrainerLose

L_01F9:
    VMJump L_027F

L_01FF:
    ActorMsg 1024, 3, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_04D4
    ActorCmdExec 255, Movement_04CC
    ActorCmdWait
    WorkSetConst 0x8028, 0
    GameGetDifficulty 0x8028
    VMStackPush 0x8028
    VMStackPushConst 2
    VMStackCmp 1
    VMJumpIf 255, L_024A
    CallTrainerBattle 781, 0, 0
    VMJump L_0252

L_024A:
    CallTrainerBattle 536, 0, 0

L_0252:
    WorkSetConst 0x8028, 0
    TrainerBattleIsVictory 0x8010
    VMStackPush 0x8010
    VMStackPushConst 1
    VMStackCmp 1
    VMJumpIf 255, L_027D
    VMCall L_036B
    CallTrainerBattleEnd
    VMJump L_027F

L_027D:
    CallTrainerLose

L_027F:
    VMSleep 8
    ActorMsg 1024, 4, 0, 1, 0
    MsgWinCloseAll
    EvCameraReturn 60
    ActorCmdExec 0, Movement_049C
    VMSleep 8
    ActorCmdExec 251, Movement_049C
    ActorCmdWait
    EvCameraWait
    EvCameraRebind
    EvCameraEnd
    Plugin3_Cmd1018
    SEPlay 2230
    SEPlay 2234
    VMSleep 130
    SEPlay 2231
    VMSleep 105
    SEPlay 2232
    VMSleep 77
    SEPlay 2233
    VMSleep 58
    VMSleep 16
    ActorCmdExec 0, Movement_04D4
    VMSleep 8
    ActorCmdExec 251, Movement_04B4
    ActorCmdWait
    ActorMsgGendered 1024, 5, 6, 0, 1, 0
    MsgWinCloseAll
    ActorCmdExec 0, Movement_048C
    VMSleep 2
    ActorCmdExec 251, Movement_048C
    ActorCmdWait
    ActorCmdExec 0, Movement_047C
    VMSleep 6
    ActorCmdExec 251, Movement_04A4
    ActorCmdWait
    ActorCmdExec 251, Movement_0444
    ActorCmdExec 255, Movement_0444
    VMSleep 2
    ActorCmdExec 0, Movement_0474
    ActorCmdWait
    Plugin3_Cmd1020 0
    Plugin3_Cmd1020 255
    Plugin3_Cmd1020 251
    RTReserveScript 1
    MapChangeWarp 145, 8, 19, 0
    FinishAllEvents
    ActorsUnpauseAll
    VMHalt

L_036B:
    ActorSetGPos 255, 16, 13, 40, 3
    ActorCmdExec 255, Movement_04DC
    ActorCmdWait
    TrainerCardGetSex 0x8026
    WorkCmpConst 0x8026, 0
    VMJumpIf 1, L_0398
    VMJump L_03AC

L_0398:
    ActorNew 15, 40, 3, 251, 231, 0
    VMJump L_03D3

L_03AC:
    WorkCmpConst 0x8026, 1
    VMJumpIf 1, L_03BF
    VMJump L_03D3

L_03BF:
    ActorNew 15, 40, 3, 251, 240, 0
    VMJump L_03D3

L_03D3:
    Plugin3_Cmd1019 251
    EvCameraInit
    EvCameraUnbind
    EvCameraMoveTo 10317, 0, 0x72000, 0x108000, 0xd00cf, 0x31b000, 1
    EvCameraWait
    VMReturn
    .balign 4, 0
    Move 12, 1
    MoveEnd

Movement_0400:
    Move 13, 1
    Move 14, 1
    Move 13, 1
    Move 35, 1
    MoveEnd

Movement_0414:
    Move 13, 1
    Move 14, 3
    Move 13, 1
    Move 35, 1
    MoveEnd

Movement_0428:
    Move 14, 2
    Move 13, 1
    Move 35, 1
    MoveEnd
    Move 15, 1
    Move 12, 21
    MoveEnd

Movement_0444:
    Move 12, 21
    MoveEnd

Movement_044C:
    Move 13, 4
    MoveEnd
    VMStackDiv
    VMNop2
    VMStackSub
    VMHalt
    FieldGetContinueFlag 1
    PokePartyGetSpecies 0, 13
    VMHalt
    Move 15, 1
    Move 34, 1
    MoveEnd

Movement_0474:
    Move 12, 20
    MoveEnd

Movement_047C:
    Move 17, 1
    Move 18, 1
    Move 32, 1
    MoveEnd

Movement_048C:
    Move 71, 1
    Move 11, 1
    Move 72, 1
    MoveEnd

Movement_049C:
    Move 32, 1
    MoveEnd

Movement_04A4:
    Move 33, 1
    MoveEnd

Movement_04AC:
    Move 34, 1
    MoveEnd

Movement_04B4:
    Move 35, 1
    MoveEnd
    Move 13, 1
    MoveEnd

Movement_04C4:
    Move 12, 1
    MoveEnd

Movement_04CC:
    Move 15, 1
    MoveEnd

Movement_04D4:
    Move 14, 1
    MoveEnd

Movement_04DC:
    Move 69, 1
    MoveEnd
